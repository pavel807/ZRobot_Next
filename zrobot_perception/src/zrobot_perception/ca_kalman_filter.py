#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Constant Acceleration Kalman Filter for high-maneuverability tracking.
Optimized for Rock 5B + YOLO NPU (80ms latency compensation).
"""

import numpy as np
from typing import Optional, Tuple, Dict


class ConstantAccelerationKalmanFilter:
    """State: [x, y, vx, vy, ax, ay], Measurement: [x, y]"""

    def __init__(
        self,
        dt: float = 0.02,
        process_noise_acc: float = 100.0,
        measurement_noise: float = 3.0,
        mahalanobis_threshold: float = 5.0,
        latency_ms: float = 80.0,
        adaptive_enabled: bool = True,
        adaptation_threshold: float = 2.0,
        adaptation_factor: float = 1.5,
    ):
        self.dt = dt
        self.latency = latency_ms / 1000.0
        self.mahalanobis_threshold = mahalanobis_threshold
        self.adaptive_enabled = adaptive_enabled
        self.adaptation_threshold = adaptation_threshold
        self.adaptation_factor = adaptation_factor
        self.base_q = process_noise_acc
        self.current_q = process_noise_acc
        self.last_innovation_norm = 0.0
        self.state_dim = 6
        self.meas_dim = 2
        self._init_matrices(process_noise_acc, measurement_noise)
        self._init_state()

    def _init_matrices(self, q_acc: float, r: float):
        dt = self.dt
        dt2 = dt * dt
        dt3 = dt2 * dt
        dt4 = dt3 * dt

        self.F = np.eye(self.state_dim)
        self.F[0, 2] = dt
        self.F[0, 4] = 0.5 * dt2
        self.F[1, 3] = dt
        self.F[1, 5] = 0.5 * dt2
        self.F[2, 4] = dt
        self.F[3, 5] = dt

        self.H = np.zeros((self.meas_dim, self.state_dim))
        self.H[0, 0] = 1.0
        self.H[1, 1] = 1.0

        q = q_acc
        self.Q = np.zeros((self.state_dim, self.state_dim))
        self.Q[0, 0] = dt4 / 4 * q
        self.Q[0, 2] = dt3 / 2 * q
        self.Q[0, 4] = dt2 / 2 * q
        self.Q[1, 1] = dt4 / 4 * q
        self.Q[1, 3] = dt3 / 2 * q
        self.Q[1, 5] = dt2 / 2 * q
        self.Q[2, 0] = dt3 / 2 * q
        self.Q[2, 2] = dt2 * q
        self.Q[2, 4] = dt * q
        self.Q[3, 1] = dt3 / 2 * q
        self.Q[3, 3] = dt2 * q
        self.Q[3, 5] = dt * q
        self.Q[4, 0] = dt2 / 2 * q
        self.Q[4, 2] = dt * q
        self.Q[4, 4] = q
        self.Q[5, 1] = dt2 / 2 * q
        self.Q[5, 3] = dt * q
        self.Q[5, 5] = q

        self.R = np.eye(self.meas_dim) * (r * r)

    def _init_state(self):
        self.x = np.zeros((self.state_dim, 1))
        self.P = np.eye(self.state_dim) * 500.0
        self.initialized = False
        self.last_timestamp = None

    def predict(self, timestamp: Optional[float] = None) -> Tuple[float, float]:
        if timestamp is not None and self.last_timestamp is not None:
            dt = timestamp - self.last_timestamp
            if dt > 0.001:
                self._recompute_matrices(dt)

        self.x = self.F @ self.x
        self.P = self.F @ self.P @ self.F.T + self.Q

        if timestamp is not None:
            self.last_timestamp = timestamp

        return float(self.x[0, 0]), float(self.x[1, 0])

    def _recompute_matrices(self, dt: float):
        dt2 = dt * dt
        dt3 = dt2 * dt
        dt4 = dt3 * dt

        self.F = np.eye(self.state_dim)
        self.F[0, 2] = dt
        self.F[0, 4] = 0.5 * dt2
        self.F[1, 3] = dt
        self.F[1, 5] = 0.5 * dt2
        self.F[2, 4] = dt
        self.F[3, 5] = dt

        q = self.current_q
        self.Q = np.zeros((self.state_dim, self.state_dim))
        self.Q[0, 0] = dt4 / 4 * q
        self.Q[0, 2] = dt3 / 2 * q
        self.Q[0, 4] = dt2 / 2 * q
        self.Q[1, 1] = dt4 / 4 * q
        self.Q[1, 3] = dt3 / 2 * q
        self.Q[1, 5] = dt2 / 2 * q
        self.Q[2, 0] = dt3 / 2 * q
        self.Q[2, 2] = dt2 * q
        self.Q[2, 4] = dt * q
        self.Q[3, 1] = dt3 / 2 * q
        self.Q[3, 3] = dt2 * q
        self.Q[3, 5] = dt * q
        self.Q[4, 0] = dt2 / 2 * q
        self.Q[4, 2] = dt * q
        self.Q[4, 4] = q
        self.Q[5, 1] = dt2 / 2 * q
        self.Q[5, 3] = dt * q
        self.Q[5, 5] = q

    def update(
        self, measurement: Tuple[float, float], timestamp: Optional[float] = None
    ) -> Tuple[float, float]:
        z = np.array([[measurement[0]], [measurement[1]]])

        if not self.initialized:
            self.x[0, 0] = measurement[0]
            self.x[1, 0] = measurement[1]
            self.initialized = True
            if timestamp is not None:
                self.last_timestamp = timestamp
            return measurement

        if timestamp is not None and self.last_timestamp is not None:
            dt = timestamp - self.last_timestamp
            if dt > 0.001:
                self._recompute_matrices(dt)
                self.x = self.F @ self.x
                self.P = self.F @ self.P @ self.F.T + self.Q

        predicted_meas = self.H @ self.x
        innovation = z - predicted_meas

        S = self.H @ self.P @ self.H.T + self.R
        S_inv = np.linalg.inv(S + 1e-10 * np.eye(self.meas_dim))

        mahalanobis_sq = float(innovation.T @ S_inv @ innovation)

        if mahalanobis_sq > self.mahalanobis_threshold**2:
            self._reset_to_measurement(measurement)
            if timestamp is not None:
                self.last_timestamp = timestamp
            return float(self.x[0, 0]), float(self.x[1, 0])

        K = self.P @ self.H.T @ S_inv

        self.x = self.x + K @ innovation
        self.P = (np.eye(self.state_dim) - K @ self.H) @ self.P

        if self.adaptive_enabled:
            self.last_innovation_norm = float(np.sqrt(mahalanobis_sq))
            self._adapt_process_noise()

        if timestamp is not None:
            self.last_timestamp = timestamp

        return float(self.x[0, 0]), float(self.x[1, 0])

    def _adapt_process_noise(self):
        if self.last_innovation_norm > self.adaptation_threshold:
            self.current_q = min(
                self.current_q * self.adaptation_factor, self.base_q * 10.0
            )
        else:
            self.current_q = max(self.current_q / self.adaptation_factor, self.base_q)

        dt = self.dt
        dt2 = dt * dt
        dt3 = dt2 * dt
        dt4 = dt3 * dt
        q = self.current_q
        self.Q[0, 0] = dt4 / 4 * q
        self.Q[0, 2] = dt3 / 2 * q
        self.Q[0, 4] = dt2 / 2 * q
        self.Q[1, 1] = dt4 / 4 * q
        self.Q[1, 3] = dt3 / 2 * q
        self.Q[1, 5] = dt2 / 2 * q
        self.Q[2, 0] = dt3 / 2 * q
        self.Q[2, 2] = dt2 * q
        self.Q[2, 4] = dt * q
        self.Q[3, 1] = dt3 / 2 * q
        self.Q[3, 3] = dt2 * q
        self.Q[3, 5] = dt * q
        self.Q[4, 0] = dt2 / 2 * q
        self.Q[4, 2] = dt * q
        self.Q[4, 4] = q
        self.Q[5, 1] = dt2 / 2 * q
        self.Q[5, 3] = dt * q
        self.Q[5, 5] = q

    def _reset_to_measurement(self, measurement: Tuple[float, float]):
        self.x[0, 0] = measurement[0]
        self.x[1, 0] = measurement[1]
        self.P = np.eye(self.state_dim) * 10.0

    def get_extrapolated_position(
        self, latency_sec: Optional[float] = None
    ) -> Tuple[float, float]:
        if not self.initialized:
            return 0.0, 0.0

        dt = latency_sec if latency_sec is not None else self.latency
        if dt <= 0:
            return float(self.x[0, 0]), float(self.x[1, 0])

        F_ext = np.eye(self.state_dim)
        F_ext[0, 2] = dt
        F_ext[0, 4] = 0.5 * dt * dt
        F_ext[1, 3] = dt
        F_ext[1, 5] = 0.5 * dt * dt
        F_ext[2, 4] = dt
        F_ext[3, 5] = dt

        extrapolated = F_ext @ self.x
        return float(extrapolated[0, 0]), float(extrapolated[1, 0])

    def get_velocity(self) -> Tuple[float, float]:
        if not self.initialized:
            return 0.0, 0.0
        return float(self.x[2, 0]), float(self.x[3, 0])

    def get_acceleration(self) -> Tuple[float, float]:
        if not self.initialized:
            return 0.0, 0.0
        return float(self.x[4, 0]), float(self.x[5, 0])

    def reset(self):
        self._init_state()


class MultiTargetCAKF:
    """Manages multiple CA-KF instances with IoU + Mahalanobis matching."""

    def __init__(
        self,
        dt: float = 0.02,
        process_noise_acc: float = 100.0,
        measurement_noise: float = 3.0,
        mahalanobis_threshold: float = 5.0,
        latency_ms: float = 80.0,
        max_tracks: int = 20,
        track_timeout: float = 0.3,
        iou_threshold: float = 0.3,
    ):
        self.max_tracks = max_tracks
        self.track_timeout = track_timeout
        self.iou_threshold = iou_threshold
        self.filters = {}
        self.timestamps = {}
        self.class_ids = {}
        self.confidences = {}

        self.params = {
            "dt": dt,
            "process_noise_acc": process_noise_acc,
            "measurement_noise": measurement_noise,
            "mahalanobis_threshold": mahalanobis_threshold,
            "latency_ms": latency_ms,
        }
        self.next_id = 0

    def predict(self, timestamp: float):
        for track_id in list(self.filters.keys()):
            self.filters[track_id].predict(timestamp)

    def update(self, detections: list, timestamp: float) -> Dict[int, Dict]:
        self.predict(timestamp)

        det_centers = []
        det_bboxes = []
        det_data = []
        for det in detections:
            cx, cy = det["center"]
            det_centers.append((cx, cy))
            det_bboxes.append(det["bbox"])
            det_data.append(det)

        n_tracks = len(self.filters)
        n_dets = len(detections)
        matched_track_ids = set()
        matched_det_ids = set()

        if n_tracks > 0 and n_dets > 0:
            cost_matrix = np.full((n_tracks, n_dets), np.inf)
            track_ids = list(self.filters.keys())
            for i, tid in enumerate(track_ids):
                kf = self.filters[tid]
                pred_cx, pred_cy = kf.get_extrapolated_position()
                for j, det_center in enumerate(det_centers):
                    z = np.array([[det_center[0]], [det_center[1]]])
                    innov = z - np.array([[pred_cx], [pred_cy]])
                    S = kf.H @ kf.P @ kf.H.T + kf.R
                    S_inv = np.linalg.inv(S + 1e-10 * np.eye(2))
                    mahal_sq = float(innov.T @ S_inv @ innov)
                    cost_matrix[i, j] = mahal_sq

            while True:
                min_cost = np.min(cost_matrix)
                if min_cost > self.params["mahalanobis_threshold"] ** 2:
                    break
                i, j = np.unravel_index(np.argmin(cost_matrix), cost_matrix.shape)
                tid = track_ids[i]
                if tid in matched_track_ids or j in matched_det_ids:
                    cost_matrix[i, j] = np.inf
                    continue
                matched_track_ids.add(tid)
                matched_det_ids.add(j)
                det = det_data[j]
                kf = self.filters[tid]
                kf.update(det["center"], timestamp)
                self.timestamps[tid] = timestamp
                self.class_ids[tid] = det["class_id"]
                self.confidences[tid] = det["confidence"]
                cost_matrix[i, :] = np.inf
                cost_matrix[:, j] = np.inf

        for j, det in enumerate(det_data):
            if j not in matched_det_ids:
                if len(self.filters) < self.max_tracks:
                    new_id = self.next_id
                    self.next_id += 1
                    kf = ConstantAccelerationKalmanFilter(**self.params)
                    kf.update(det["center"], timestamp)
                    self.filters[new_id] = kf
                    self.timestamps[new_id] = timestamp
                    self.class_ids[new_id] = det["class_id"]
                    self.confidences[new_id] = det["confidence"]

        current_time = timestamp
        for tid in list(self.filters.keys()):
            if current_time - self.timestamps.get(tid, 0) > self.track_timeout:
                del self.filters[tid]
                del self.timestamps[tid]
                if tid in self.class_ids:
                    del self.class_ids[tid]
                if tid in self.confidences:
                    del self.confidences[tid]

        result = {}
        for tid, kf in self.filters.items():
            if not kf.initialized:
                continue
            ext_cx, ext_cy = kf.get_extrapolated_position()
            cx, cy = kf.x[0, 0], kf.x[1, 0]
            result[tid] = {
                "center": (cx, cy),
                "extrapolated_center": (ext_cx, ext_cy),
                "velocity": kf.get_velocity(),
                "class_id": self.class_ids.get(tid, 0),
                "confidence": self.confidences.get(tid, 0.0),
            }
        return result
