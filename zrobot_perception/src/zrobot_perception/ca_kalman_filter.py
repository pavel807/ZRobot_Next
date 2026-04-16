#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Constant Acceleration Kalman Filter for high-maneuverability tracking.
Optimized for Rock 5B + YOLO NPU (80ms latency compensation).

Features:
- CA (Constant Acceleration) model instead of CV
- Increased Process Noise (Q) for fast acceleration changes
- Mahalanobis distance gating - detector resets filter when prediction diverges
- 80ms latency compensation via extrapolation
"""

import numpy as np
from typing import Optional, Tuple


class ConstantAccelerationKalmanFilter:
    """
    State: [x, y, vx, vy, ax, ay]
    Measurement: [x, y] (from YOLO center)
    """

    def __init__(
        self,
        dt: float = 0.02,
        process_noise_acc: float = 100.0,
        measurement_noise: float = 3.0,
        mahalanobis_threshold: float = 5.0,
        latency_ms: float = 80.0,
    ):
        self.dt = dt
        self.latency = latency_ms / 1000.0
        self.mahalanobis_threshold = mahalanobis_threshold

        self.state_dim = 6
        self.meas_dim = 2

        self._init_matrices(process_noise_acc, measurement_noise)
        self._init_state()

    def _init_matrices(self, q_acc: float, r: float):
        dt = self.dt
        dt2 = dt * dt
        dt3 = dt2 * dt
        dt4 = dt3 * dt
        dt5 = dt4 * dt
        dt6 = dt5 * dt

        self.F = np.eye(self.state_dim)
        self.F[0, 2] = dt
        self.F[0, 4] = dt2 / 2
        self.F[1, 3] = dt
        self.F[1, 5] = dt2 / 2
        self.F[2, 4] = dt
        self.F[3, 5] = dt

        self.H = np.zeros((self.meas_dim, self.state_dim))
        self.H[0, 0] = 1.0
        self.H[1, 1] = 1.0

        q = q_acc
        self.Q = np.zeros((self.state_dim, self.state_dim))
        self.Q[0, 0] = dt6 / 36 * q
        self.Q[0, 2] = dt5 / 12 * q
        self.Q[0, 4] = dt4 / 6 * q
        self.Q[1, 1] = dt6 / 36 * q
        self.Q[1, 3] = dt5 / 12 * q
        self.Q[1, 5] = dt4 / 6 * q
        self.Q[2, 0] = dt5 / 12 * q
        self.Q[2, 2] = dt4 / 4 * q
        self.Q[2, 4] = dt3 / 2 * q
        self.Q[3, 1] = dt5 / 12 * q
        self.Q[3, 3] = dt4 / 4 * q
        self.Q[3, 5] = dt3 / 2 * q
        self.Q[4, 0] = dt4 / 6 * q
        self.Q[4, 2] = dt3 / 2 * q
        self.Q[4, 4] = dt2 * q
        self.Q[5, 1] = dt4 / 6 * q
        self.Q[5, 3] = dt3 / 2 * q
        self.Q[5, 5] = dt2 * q

        self.R = np.eye(self.meas_dim) * (r * r)

    def _init_state(self):
        self.x = np.zeros((self.state_dim, 1))
        self.P = np.eye(self.state_dim) * 500.0
        self.initialized = False
        self.last_timestamp = None

    def predict(self, timestamp: Optional[float] = None) -> Tuple[float, float]:
        if timestamp is not None and self.last_timestamp is not None:
            dt = timestamp - self.last_timestamp
            if dt > 0:
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
        dt5 = dt4 * dt
        dt6 = dt5 * dt

        q = 50.0

        self.F = np.eye(self.state_dim)
        self.F[0, 2] = dt
        self.F[0, 4] = dt2 / 2
        self.F[1, 3] = dt
        self.F[1, 5] = dt2 / 2
        self.F[2, 4] = dt
        self.F[3, 5] = dt

        self.Q = np.zeros((self.state_dim, self.state_dim))
        self.Q[0, 0] = dt6 / 36 * q
        self.Q[0, 2] = dt5 / 12 * q
        self.Q[0, 4] = dt4 / 6 * q
        self.Q[1, 1] = dt6 / 36 * q
        self.Q[1, 3] = dt5 / 12 * q
        self.Q[1, 5] = dt4 / 6 * q
        self.Q[2, 0] = dt5 / 12 * q
        self.Q[2, 2] = dt4 / 4 * q
        self.Q[2, 4] = dt3 / 2 * q
        self.Q[3, 1] = dt5 / 12 * q
        self.Q[3, 3] = dt4 / 4 * q
        self.Q[3, 5] = dt3 / 2 * q
        self.Q[4, 0] = dt4 / 6 * q
        self.Q[4, 2] = dt3 / 2 * q
        self.Q[4, 4] = dt2 * q
        self.Q[5, 1] = dt4 / 6 * q
        self.Q[5, 3] = dt3 / 2 * q
        self.Q[5, 5] = dt2 * q

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
            return measurement[0], measurement[1]

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

        if timestamp is not None:
            self.last_timestamp = timestamp

        return float(self.x[0, 0]), float(self.x[1, 0])

    def _reset_to_measurement(self, measurement: Tuple[float, float]):
        self.x[0, 0] = measurement[0]
        self.x[1, 0] = measurement[1]
        self.P = np.eye(self.state_dim) * 10.0

    def get_extrapolated_position(self) -> Tuple[float, float]:
        if not self.initialized:
            return 0.0, 0.0

        if self.latency > 0:
            dt = self.latency
            F_latency = np.eye(self.state_dim)
            F_latency[0, 2] = dt
            F_latency[0, 4] = dt * dt / 2
            F_latency[1, 3] = dt
            F_latency[1, 5] = dt * dt / 2
            F_latency[2, 4] = dt
            F_latency[3, 5] = dt

            extrapolated = F_latency @ self.x
            return float(extrapolated[0, 0]), float(extrapolated[1, 0])

        return float(self.x[0, 0]), float(self.x[1, 0])

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
    """Manages multiple CA-KF instances for tracking multiple objects."""

    def __init__(
        self,
        dt: float = 0.02,
        process_noise_acc: float = 100.0,
        measurement_noise: float = 3.0,
        mahalanobis_threshold: float = 5.0,
        latency_ms: float = 80.0,
        max_tracks: int = 10,
        track_timeout: float = 0.3,
    ):
        self.max_tracks = max_tracks
        self.track_timeout = track_timeout
        self.filters = {}
        self.timestamps = {}

        self.params = {
            "dt": dt,
            "process_noise_acc": process_noise_acc,
            "measurement_noise": measurement_noise,
            "mahalanobis_threshold": mahalanobis_threshold,
            "latency_ms": latency_ms,
        }

    def predict(self, timestamp: float):
        for track_id in list(self.filters.keys()):
            self.filters[track_id].predict(timestamp)
            self.timestamps[track_id] = timestamp

    def update(self, detections: list, timestamp: float):
        detection_centers = {
            (d["x"], d["y"]): d.get("track_id", i) for i, d in enumerate(detections)
        }

        matched_filters = set()

        for det in detections:
            det_center = (det["x"], det["y"])
            track_id = det.get("track_id", -1)

            if track_id in self.filters:
                self.filters[track_id].predict(timestamp)
                self.filters[track_id].update((det["x"], det["y"]), timestamp)
                matched_filters.add(track_id)
                self.timestamps[track_id] = timestamp
                continue

            min_dist = float("inf")
            best_track = None

            for tid, kf in self.filters.items():
                if tid in matched_filters:
                    continue
                pred_x, pred_y = kf.get_extrapolated_position()
                dist = np.sqrt(
                    (pred_x - det_center[0]) ** 2 + (pred_y - det_center[1]) ** 2
                )
                if dist < min_dist:
                    min_dist = dist
                    best_track = tid

            if best_track is not None and min_dist < 150:
                self.filters[best_track].predict(timestamp)
                self.filters[best_track].update(det_center, timestamp)
                matched_filters.add(best_track)
                self.timestamps[best_track] = timestamp
            elif len(self.filters) < self.max_tracks:
                new_id = max(list(self.filters.keys()) + [-1]) + 1
                kf = ConstantAccelerationKalmanFilter(**self.params)
                kf.update(det_center, timestamp)
                self.filters[new_id] = kf
                self.timestamps[new_id] = timestamp

        current_time = timestamp
        for track_id in list(self.filters.keys()):
            if track_id not in matched_filters:
                if current_time - self.timestamps.get(track_id, 0) > self.track_timeout:
                    del self.filters[track_id]
                    del self.timestamps[track_id]

    def get_track(self, track_id: int):
        if track_id not in self.filters:
            return None
        kf = self.filters[track_id]
        return {
            "x": kf.x[0, 0],
            "y": kf.x[1, 0],
            "vx": kf.x[2, 0],
            "vy": kf.x[3, 0],
            "ax": kf.x[4, 0],
            "ay": kf.x[5, 0],
            "extrapolated_x": kf.get_extrapolated_position()[0],
            "extrapolated_y": kf.get_extrapolated_position()[1],
        }

    def get_all_tracks(self):
        return {tid: self.get_track(tid) for tid in self.filters.keys()}
