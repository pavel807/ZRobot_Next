#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
BoT-SORT inspired tracker for Rock 5B NPU.
Lightweight version: Kalman + IoU matching + Age-based track management
Optimized for high-speed tracking with 80ms latency compensation.
"""

import numpy as np
from typing import Optional, Tuple, List, Dict
import time


class BoTSORTKalmanFilter:
    """Enhanced Kalman Filter for BoT-SORT - uses motion model with velocity and acceleration."""

    def __init__(
        self,
        bbox: Optional[List[float]] = None,
        dt: float = 0.02,
        q_std_position: float = 1.0,
        q_std_velocity: float = 0.01,
        r_std: float = 3.0,
    ):
        self.dt = dt
        self.q_std_position = q_std_position
        self.q_std_velocity = q_std_velocity
        self.r_std = r_std

        self.state_dim = 8
        self.meas_dim = 4

        self._init_matrices()

        if bbox is not None:
            x, y, w, h = bbox
            self.x = np.array([x + w / 2, y + h / 2, w, h, 0, 0, 0, 0]).reshape(8, 1)
            self.P = np.eye(self.state_dim) * 1000.0
            self.initialized = True
            self.confidence = 1.0
        else:
            self._init_state()

        self.last_timestamp = time.time()

    def _init_matrices(self):
        self.F = np.eye(self.state_dim)
        self.F[0, 4] = self.dt
        self.F[1, 5] = self.dt
        self.F[2, 6] = self.dt
        self.F[3, 7] = self.dt

        self.H = np.zeros((self.meas_dim, self.state_dim))
        self.H[0, 0] = 1.0
        self.H[1, 1] = 1.0
        self.H[2, 2] = 1.0
        self.H[3, 3] = 1.0

        q_pos = self.q_std_position**2
        q_vel = self.q_std_velocity**2
        d = self.dt

        self.Q = np.zeros((self.state_dim, self.state_dim))
        self.Q[0, 0] = q_pos
        self.Q[1, 1] = q_pos
        self.Q[2, 2] = q_pos
        self.Q[3, 3] = q_pos
        self.Q[0, 4] = q_pos * d
        self.Q[1, 5] = q_pos * d
        self.Q[2, 6] = q_pos * d
        self.Q[3, 7] = q_pos * d
        self.Q[4, 0] = q_pos * d
        self.Q[5, 1] = q_pos * d
        self.Q[6, 2] = q_pos * d
        self.Q[7, 3] = q_pos * d
        self.Q[4, 4] = q_vel + q_pos * d * d
        self.Q[5, 5] = q_vel + q_pos * d * d
        self.Q[6, 6] = q_vel + q_pos * d * d
        self.Q[7, 7] = q_vel + q_pos * d * d

        self.R = np.eye(self.meas_dim) * (self.r_std**2)

    def _init_state(self):
        self.x = np.zeros((self.state_dim, 1))
        self.P = np.eye(self.state_dim) * 1000.0
        self.initialized = False
        self.confidence = 1.0

    def predict(self) -> Tuple[float, float, float, float]:
        self.x = self.F @ self.x
        self.P = self.F @ self.P @ self.F.T + self.Q

        cx = float(self.x[0, 0])
        cy = float(self.x[1, 0])
        w = float(self.x[2, 0])
        h = float(self.x[3, 0])

        return cx, cy, w, h

    def update(self, bbox: List[float], confidence: float = 1.0):
        if not self.initialized:
            x, y, w, h = bbox
            self.x = np.array([x + w / 2, y + h / 2, w, h, 0, 0, 0, 0]).reshape(8, 1)
            self.P = np.eye(self.state_dim) * 1000.0
            self.initialized = True
            self.confidence = confidence
            return

        z = np.array(bbox).reshape(4, 1)

        predicted = self.H @ self.x
        innovation = z - predicted

        S = self.H @ self.P @ self.H.T + self.R
        K = self.P @ self.H.T @ np.linalg.inv(S + 1e-10 * np.eye(4))

        self.x = self.x + K @ innovation
        self.P = (np.eye(self.state_dim) - K @ self.H) @ self.P

        self.confidence = confidence
        self.last_timestamp = time.time()

    def get_state(self) -> Tuple[float, float, float, float]:
        cx = float(self.x[0, 0])
        cy = float(self.x[1, 0])
        w = float(self.x[2, 0])
        h = float(self.x[3, 0])
        return cx, cy, w, h

    def get_extrapolated(
        self, latency_ms: float = 80
    ) -> Tuple[float, float, float, float]:
        dt = latency_ms / 1000.0
        F_latency = np.eye(self.state_dim)
        F_latency[0, 4] = dt
        F_latency[1, 5] = dt
        F_latency[2, 6] = dt
        F_latency[3, 7] = dt

        x_extrapolated = F_latency @ self.x

        cx = float(x_extrapolated[0, 0])
        cy = float(x_extrapolated[1, 0])
        w = float(x_extrapolated[2, 0])
        h = float(x_extrapolated[3, 0])
        return cx, cy, w, h


class Track:
    """Single track instance for BoT-SORT"""

    def __init__(self, track_id: int, bbox: List[float], confidence: float = 1.0):
        self.track_id = track_id
        self.kf = BoTSORTKalmanFilter(bbox=bbox)
        self.confidence = confidence
        self.age = 0
        self.hits = 1
        self.time_since_update = 0
        self.last_bbox = bbox

    def predict(self):
        return self.kf.predict()

    def update(self, bbox: List[float], confidence: float = 1.0):
        self.kf.update(bbox, confidence)
        self.hits += 1
        self.time_since_update = 0
        self.last_bbox = bbox

    def get_extrapolated(
        self, latency_ms: float = 80
    ) -> Tuple[float, float, float, float]:
        return self.kf.get_extrapolated(latency_ms)


def compute_iou(
    bbox1: Tuple[float, float, float, float], bbox2: Tuple[float, float, float, float]
) -> float:
    """Compute IoU between two bounding boxes (cx, cy, w, h format)."""
    x1, y1, w1, h1 = bbox1
    x2, y2, w2, h2 = bbox2

    x1_min, y1_min = x1 - w1 / 2, y1 - h1 / 2
    x1_max, y1_max = x1 + w1 / 2, y1 + h1 / 2
    x2_min, y2_min = x2 - w2 / 2, y2 - h2 / 2
    x2_max, y2_max = x2 + w2 / 2, y2 + h2 / 2

    inter_x_min = max(x1_min, x2_min)
    inter_y_min = max(y1_min, y2_min)
    inter_x_max = min(x1_max, x2_max)
    inter_y_max = min(y1_max, y2_max)

    if inter_x_max < inter_x_min or inter_y_max < inter_y_min:
        return 0.0

    inter_area = (inter_x_max - inter_x_min) * (inter_y_max - inter_y_min)
    area1 = w1 * h1
    area2 = w2 * h2
    union_area = area1 + area2 - inter_area

    return inter_area / (union_area + 1e-10)


def compute_distance(
    bbox1: Tuple[float, float, float, float], bbox2: Tuple[float, float, float, float]
) -> float:
    """Compute center distance between bboxes."""
    cx1, cy1 = bbox1[0], bbox1[1]
    cx2, cy2 = bbox2[0], bbox2[1]
    return np.sqrt((cx1 - cx2) ** 2 + (cy1 - cy2) ** 2)


class BoTSORTTracker:
    """
    BoT-SORT inspired tracker with:
    - Kalman filter for motion prediction
    - IoU matching
    - Age-based track management
    - 80ms latency compensation
    """

    def __init__(
        self,
        max_age: int = 30,
        min_hits: int = 3,
        iou_threshold: float = 0.3,
        max_distance: float = 100.0,
        latency_ms: float = 80.0,
    ):
        self.max_age = max_age
        self.min_hits = min_hits
        self.iou_threshold = iou_threshold
        self.max_distance = max_distance
        self.latency_ms = latency_ms
        self.tracks: Dict[int, Track] = {}
        self.next_track_id = 0
        self.frame_count = 0

    def update(self, detections: List[Dict]) -> Dict[int, Dict]:
        """
        Update tracker with new detections.
        detections: [{'bbox': [cx, cy, w, h], 'confidence': 0.95, 'class_id': 0}, ...]
        Returns: {track_id: {'bbox': [...], 'confidence': ..., 'class_id': ...}}
        """
        self.frame_count += 1

        if not detections:
            self._age_tracks()
            return {}

        det_bboxes = []
        for det in detections:
            cx, cy, w, h = det["bbox"]
            det_bboxes.append((cx, cy, w, h))

        matched_tracks = set()
        matched_dets = set()
        iou_matrix = np.zeros((len(self.tracks), len(detections)))

        for tid, track in self.tracks.items():
            pred_bbox = track.get_extrapolated(self.latency_ms)
            for did, det_bbox in enumerate(det_bboxes):
                iou = compute_iou(pred_bbox, det_bbox)
                iou_matrix[tid if tid < len(self.tracks) else 0, did] = iou

        track_ids = list(self.tracks.keys())
        for did, det in enumerate(detections):
            best_iou = self.iou_threshold
            best_tid = None

            for tid in track_ids:
                if tid in matched_tracks:
                    continue
                track = self.tracks[tid]
                pred_bbox = track.get_extrapolated(self.latency_ms)
                iou = compute_iou(pred_bbox, tuple(det["bbox"]))
                dist = compute_distance(pred_bbox, tuple(det["bbox"]))

                if iou > best_iou and dist < self.max_distance:
                    best_iou = iou
                    best_tid = tid

            if best_tid is not None:
                self.tracks[best_tid].update(det["bbox"], det.get("confidence", 1.0))
                matched_tracks.add(best_tid)
                matched_dets.add(did)

        for did, det in enumerate(detections):
            if did in matched_dets:
                continue
            new_id = self.next_track_id
            self.next_track_id += 1
            self.tracks[new_id] = Track(new_id, det["bbox"], det.get("confidence", 1.0))

        self._age_tracks()

        result = {}
        for tid, track in self.tracks.items():
            if track.hits >= self.min_hits:
                cx, cy, w, h = track.get_extrapolated(self.latency_ms)
                result[tid] = {
                    "bbox": [cx, cy, w, h],
                    "confidence": track.confidence,
                    "class_id": track.last_bbox.get("class_id", 0),
                    "age": track.age,
                }

        return result

    def _age_tracks(self):
        for tid in list(self.tracks.keys()):
            self.tracks[tid].time_since_update += 1
            self.tracks[tid].age += 1
            if self.tracks[tid].time_since_update > self.max_age:
                del self.tracks[tid]

    def reset(self):
        self.tracks = {}
        self.next_track_id = 0
        self.frame_count = 0
