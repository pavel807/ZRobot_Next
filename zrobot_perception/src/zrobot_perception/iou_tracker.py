#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
IoU-based Multi-Object Tracker
Inspired by old ZRobot C++ implementation
Features:
    - IoU matching with Hungarian algorithm (greedy)
    - Track history for smoothing
    - Confidence decay
    - Max consecutive misses handling
"""

import numpy as np
from typing import List, Tuple, Dict, Optional
from collections import deque


class SingleObjectTracker:
    def __init__(
        self,
        track_id: int,
        label: int,
        class_name: str,
        bbox: Tuple[int, int, int, int],  # x, y, w, h
        confidence: float,
    ):
        self.id = track_id
        self.label = label
        self.class_name = class_name
        self.age = 0
        self.consecutive_misses = 0
        self.is_confirmed = False

        # History
        self.history = deque(maxlen=30)
        self.confidence_history = deque(maxlen=30)

        # Kalman state: [x, y, vx, vy, w, h]
        self.x = np.array([0.0, 0.0, 0.0, 0.0, 0.0, 0.0])
        self.P = np.eye(6) * 1.0

        # Initialize with first detection
        x, y, w, h = bbox
        cx, cy = x + w / 2, y + h / 2
        self.x[0] = cx
        self.x[1] = cy
        self.x[4] = w
        self.x[5] = h

        self.history.append(bbox)
        self.confidence_history.append(confidence)

        self.last_bbox = bbox
        self.last_confidence = confidence

    def predict(self, dt: float = 0.033) -> Tuple[int, int, int, int]:
        # Constant velocity model
        # F = [[1, 0, dt, 0, 0, 0],
        #      [0, 1, 0, dt, 0, 0],
        #      [0, 0, 1, 0, 0, 0],
        #      [0, 0, 0, 1, 0, 0],
        #      [0, 0, 0, 0, 1, 0],
        #      [0, 0, 0, 0, 0, 1]]

        F = np.eye(6)
        F[0, 2] = dt
        F[1, 3] = dt

        # Process noise
        q = 0.1
        Q = np.eye(6) * q

        self.x = F @ self.x
        self.P = F @ self.P @ F.T + Q

        # Predict bbox
        cx, cy = self.x[0], self.x[1]
        w, h = self.x[4], self.x[5]

        x = int(cx - w / 2)
        y = int(cy - h / 2)

        return (x, y, int(w), int(h))

    def update(self, bbox: Tuple[int, int, int, int], confidence: float):
        x, y, w, h = bbox
        cx, cy = x + w / 2, y + h / 2

        # Measurement: [cx, cy, w, h]
        z = np.array([cx, cy, w, h])

        # Measurement matrix H = [[1,0,0,0,0,0], [0,1,0,0,0,0], [0,0,0,0,1,0], [0,0,0,0,0,1]]
        H = np.array(
            [
                [1, 0, 0, 0, 0, 0],
                [0, 1, 0, 0, 0, 0],
                [0, 0, 0, 0, 1, 0],
                [0, 0, 0, 0, 0, 1],
            ]
        )

        # Measurement noise
        R = np.diag([0.5, 0.5, 0.5, 0.5])

        # Kalman gain
        S = H @ self.P @ H.T + R
        K = self.P @ H.T @ np.linalg.inv(S)

        # Innovation
        z_pred = H @ self.x
        innovation = z - z_pred

        # Update
        self.x = self.x + K @ innovation
        self.P = (np.eye(6) - K @ H) @ self.P

        # Update history
        self.history.append(bbox)
        self.confidence_history.append(confidence)

        self.last_bbox = bbox
        self.last_confidence = confidence

        self.age += 1
        self.consecutive_misses = 0

        if self.age >= 3:
            self.is_confirmed = True

    def mark_missed(self, confidence_decay: float = 0.9):
        self.consecutive_misses += 1
        if len(self.confidence_history) > 0:
            decayed = self.confidence_history[-1] * confidence_decay
            self.confidence_history.append(decayed)

    def get_average_confidence(self) -> float:
        if not self.confidence_history:
            return 0.0
        return sum(self.confidence_history) / len(self.confidence_history)

    def get_velocity(self) -> Tuple[float, float]:
        if len(self.history) < 2:
            return 0.0, 0.0
        curr = self.history[-1]
        prev = self.history[-2]

        curr_cx = curr[0] + curr[2] / 2
        curr_cy = curr[1] + curr[3] / 2
        prev_cx = prev[0] + prev[2] / 2
        prev_cy = prev[1] + prev[3] / 2

        return curr_cx - prev_cx, curr_cy - prev_cy


def compute_iou(
    bbox1: Tuple[int, int, int, int], bbox2: Tuple[int, int, int, int]
) -> float:
    x1, y1, w1, h1 = bbox1
    x2, y2, w2, h2 = bbox2

    x1_min, y1_min = x1, y1
    x1_max, y1_max = x1 + w1, y1 + h1

    x2_min, y2_min = x2, y2
    x2_max, y2_max = x2 + w2, y2 + h2

    inter_x_min = max(x1_min, x2_min)
    inter_y_min = max(y1_min, y2_min)
    inter_x_max = min(x1_max, x2_max)
    inter_y_max = min(y1_max, y2_max)

    inter_w = max(0, inter_x_max - inter_x_min)
    inter_h = max(0, inter_y_max - inter_y_min)
    intersection = inter_w * inter_h

    area1 = w1 * h1
    area2 = w2 * h2
    union = area1 + area2 - intersection

    return intersection / union if union > 0 else 0.0


class IoUTracker:
    def __init__(
        self,
        iou_threshold: float = 0.3,
        max_consecutive_misses: int = 15,
        confidence_decay: float = 0.9,
    ):
        self.iou_threshold = iou_threshold
        self.max_consecutive_misses = max_consecutive_misses
        self.confidence_decay = confidence_decay
        self.tracks: List[SingleObjectTracker] = []
        self.next_track_id = 0

    def update(
        self,
        detections: List[Tuple[int, int, int, int]],  # List of (x, y, w, h)
        labels: List[int],
        class_names: List[str],
        confidences: List[float],
    ) -> List[SingleObjectTracker]:
        # Mark existing tracks as missed
        for track in self.tracks:
            track.mark_missed(self.confidence_decay)

        n_tracks = len(self.tracks)
        n_detections = len(detections)

        if n_tracks == 0 and n_detections == 0:
            return []

        # Build cost matrix (IoU based)
        cost_matrix = np.zeros((n_tracks, n_detections))

        for i, track in enumerate(self.tracks):
            pred_bbox = track.predict()
            for j, det in enumerate(detections):
                if track.label != labels[j]:
                    cost_matrix[i, j] = 0
                else:
                    cost_matrix[i, j] = compute_iou(pred_bbox, det)

        # Greedy Hungarian matching
        matched_tracks = [False] * n_tracks
        matched_detections = [False] * n_detections
        matches = []

        # Sort by highest IoU
        sorted_costs = []
        for i in range(n_tracks):
            for j in range(n_detections):
                if cost_matrix[i, j] > self.iou_threshold:
                    sorted_costs.append((cost_matrix[i, j], i, j))

        sorted_costs.sort(key=lambda x: x[0], reverse=True)

        for iou, ti, di in sorted_costs:
            if not matched_tracks[ti] and not matched_detections[di]:
                matches.append((ti, di))
                matched_tracks[ti] = True
                matched_detections[di] = True

        # Update matched tracks
        for ti, di in matches:
            self.tracks[ti].update(detections[di], confidences[di])

        # Create new tracks for unmatched detections
        for j in range(n_detections):
            if not matched_detections[j]:
                new_track = SingleObjectTracker(
                    self.next_track_id,
                    labels[j],
                    class_names[j],
                    detections[j],
                    confidences[j],
                )
                self.tracks.append(new_track)
                self.next_track_id += 1

        # Remove lost tracks
        self.tracks = [
            t
            for t in self.tracks
            if t.consecutive_misses <= self.max_consecutive_misses
        ]

        return self.tracks

    def get_active_count(self) -> int:
        return len(self.tracks)

    def clear(self):
        self.tracks = []
        self.next_track_id = 0
