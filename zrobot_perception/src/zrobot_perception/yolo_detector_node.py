#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Advanced YOLO Detector Node — optimized for Rock 5B NPU.
Includes CA-Kalman filter for latency compensation and improved following.
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, LaserScan
from vision_msgs.msg import (
    Detection2DArray,
    Detection2D,
    ObjectHypothesisWithPose,
    ObjectHypothesis,
)
from geometry_msgs.msg import Twist
from std_msgs.msg import String, Float32
from cv_bridge import CvBridge
import cv2
import numpy as np
import multiprocessing as mp
import time
import os
import json
import threading
import signal
import sys
import math
from collections import deque
from zrobot_perception.ca_kalman_filter import MultiTargetCAKF

# COCO classes
COCO_CLASSES = {
    0: "person",
    1: "bicycle",
    2: "car",
    3: "motorcycle",
    4: "airplane",
    5: "bus",
    6: "train",
    7: "truck",
    8: "boat",
    9: "traffic light",
    10: "fire hydrant",
    11: "stop sign",
    12: "parking meter",
    13: "bench",
    14: "bird",
    15: "cat",
    16: "dog",
    17: "horse",
    18: "sheep",
    19: "cow",
    20: "elephant",
    21: "bear",
    22: "zebra",
    23: "giraffe",
    24: "backpack",
    25: "umbrella",
    26: "handbag",
    27: "tie",
    28: "suitcase",
    29: "frisbee",
    30: "skis",
    31: "snowboard",
    32: "sports ball",
    33: "kite",
    34: "baseball bat",
    35: "baseball glove",
    36: "skateboard",
    37: "surfboard",
    38: "tennis racket",
    39: "bottle",
    40: "wine glass",
    41: "cup",
    42: "fork",
    43: "knife",
    44: "spoon",
    45: "bowl",
    46: "banana",
    47: "apple",
    48: "sandwich",
    49: "orange",
    50: "broccoli",
    51: "carrot",
    52: "hot dog",
    53: "pizza",
    54: "donut",
    55: "cake",
    56: "chair",
    57: "couch",
    58: "potted plant",
    59: "bed",
    60: "dining table",
    61: "toilet",
    62: "tv",
    63: "laptop",
    64: "mouse",
    65: "remote",
    66: "keyboard",
    67: "cell phone",
    68: "microwave",
    69: "oven",
    70: "toaster",
    71: "sink",
    72: "refrigerator",
    73: "book",
    74: "clock",
    75: "vase",
    76: "scissors",
    77: "teddy bear",
    78: "hair drier",
    79: "toothbrush",
}

IMG_SIZE = 640
QUEUE_TIMEOUT = 0.05


def numpy_nms(boxes, scores, iou_threshold=0.45):
    """Fast NMS using numpy."""
    if len(boxes) == 0:
        return np.array([], dtype=np.int32)

    x1 = boxes[:, 0]
    y1 = boxes[:, 1]
    x2 = boxes[:, 0] + boxes[:, 2]
    y2 = boxes[:, 1] + boxes[:, 3]

    areas = (x2 - x1) * (y2 - y1)
    order = scores.argsort()[::-1]

    keep = []
    while len(order) > 0:
        i = order[0]
        keep.append(i)

        if len(order) == 1:
            break

        xx1 = np.maximum(x1[i], x1[order[1:]])
        yy1 = np.maximum(y1[i], y1[order[1:]])
        xx2 = np.minimum(x2[i], x2[order[1:]])
        yy2 = np.minimum(y2[i], y2[order[1:]])

        w = np.maximum(0.0, xx2 - xx1)
        h = np.maximum(0.0, yy2 - yy1)
        inter = w * h

        iou = inter / (areas[i] + areas[order[1:]] - inter + 1e-10)

        mask = iou <= iou_threshold
        order = order[1:][mask]

    return np.array(keep, dtype=np.int32)


def npu_process(
    core_id,
    input_queue,
    output_queue,
    model_path,
    obj_thresh,
    nms_thresh,
    shutdown_event,
):
    """NPU worker with optimized postprocessing."""
    from rknnlite.api import RKNNLite

    signal.signal(signal.SIGINT, signal.SIG_IGN)
    os.sched_setaffinity(0, {4 + core_id})

    try:
        rknn = RKNNLite()
        ret = rknn.load_rknn(model_path)
        if ret != 0:
            print(f"[NPU {core_id}] ❌ Failed to load model", flush=True)
            return

        core_masks = [RKNNLite.NPU_CORE_0, RKNNLite.NPU_CORE_1, RKNNLite.NPU_CORE_2]
        ret = rknn.init_runtime(core_mask=core_masks[core_id])
        if ret != 0:
            print(f"[NPU {core_id}] ❌ Failed to init runtime", flush=True)
            return

        print(f"🚀 NPU Core {core_id} started", flush=True)

        while not shutdown_event.is_set():
            try:
                task = input_queue.get(timeout=QUEUE_TIMEOUT)
            except Exception:
                continue

            if task is None:
                break

            frame_id, rgb_array = task

            start_time = time.perf_counter()
            outputs = rknn.inference(inputs=[rgb_array])
            inference_time_ms = (time.perf_counter() - start_time) * 1000.0

            out = outputs[0][0] if outputs[0].shape[0] == 1 else outputs[0]

            if out.shape[0] == 4:
                boxes_raw = out[:4, :].T
                raw_scores = out[4:, :].T
            else:
                boxes_raw = out[:4, :].T
                raw_scores = out[4:, :].T

            confidences = np.max(raw_scores, axis=1)
            class_ids = np.argmax(raw_scores, axis=1)

            mask = confidences > obj_thresh
            if not np.any(mask):
                try:
                    output_queue.put_nowait((frame_id, [], inference_time_ms))
                except:
                    pass
                continue

            conf = confidences[mask]
            c_ids = class_ids[mask]
            b_raw = boxes_raw[mask]

            boxes = np.empty_like(b_raw)
            boxes[:, 0] = b_raw[:, 0] - b_raw[:, 2] / 2
            boxes[:, 1] = b_raw[:, 1] - b_raw[:, 3] / 2
            boxes[:, 2] = b_raw[:, 2]
            boxes[:, 3] = b_raw[:, 3]

            indices = numpy_nms(boxes, conf, nms_thresh)

            if len(indices) > 0:
                detections = [
                    (
                        float(boxes[i][0]),
                        float(boxes[i][1]),
                        float(boxes[i][2]),
                        float(boxes[i][3]),
                        float(conf[i]),
                        int(c_ids[i]),
                    )
                    for i in indices
                ]
            else:
                detections = []

            try:
                output_queue.put_nowait((frame_id, detections, inference_time_ms))
            except:
                pass

    except Exception as e:
        print(f"[NPU {core_id}] ❌ Error: {e}", flush=True)
    finally:
        try:
            rknn.release()
        except:
            pass
        print(f"[NPU {core_id}] 🛑 Stopped", flush=True)


def npu_process_sequential(
    model_path, obj_thresh, nms_thresh, shutdown_event, input_queue, output_queue
):
    """Single NPU worker for sequential mode - processes all frames."""
    from rknnlite.api import RKNNLite

    signal.signal(signal.SIGINT, signal.SIG_IGN)

    try:
        rknn = RKNNLite()
        ret = rknn.load_rknn(model_path)
        if ret != 0:
            print(f"[NPU Sequential] ❌ Failed to load model", flush=True)
            return

        ret = rknn.init_runtime()
        if ret != 0:
            print(f"[NPU Sequential] ❌ Failed to init runtime", flush=True)
            return

        print(f"🚀 NPU Sequential started (all cores)", flush=True)

        while not shutdown_event.is_set():
            try:
                task = input_queue.get(timeout=QUEUE_TIMEOUT)
            except Exception:
                continue

            if task is None:
                break

            frame_id, rgb_array = task

            start_time = time.perf_counter()
            outputs = rknn.inference(inputs=[rgb_array])
            inference_time_ms = (time.perf_counter() - start_time) * 1000.0

            out = outputs[0][0] if outputs[0].shape[0] == 1 else outputs[0]

            if out.shape[0] == 4:
                boxes_raw = out[:4, :].T
                raw_scores = out[4:, :].T
            else:
                boxes_raw = out[:4, :].T
                raw_scores = out[4:, :].T

            confidences = np.max(raw_scores, axis=1)
            class_ids = np.argmax(raw_scores, axis=1)

            mask = confidences > obj_thresh
            if not np.any(mask):
                try:
                    output_queue.put_nowait((frame_id, [], inference_time_ms))
                except:
                    pass
                continue

            conf = confidences[mask]
            c_ids = class_ids[mask]
            b_raw = boxes_raw[mask]

            boxes = np.empty_like(b_raw)
            boxes[:, 0] = b_raw[:, 0] - b_raw[:, 2] / 2
            boxes[:, 1] = b_raw[:, 1] - b_raw[:, 3] / 2
            boxes[:, 2] = b_raw[:, 2]
            boxes[:, 3] = b_raw[:, 3]

            indices = numpy_nms(boxes, conf, nms_thresh)

            if len(indices) > 0:
                detections = [
                    (
                        float(boxes[i][0]),
                        float(boxes[i][1]),
                        float(boxes[i][2]),
                        float(boxes[i][3]),
                        float(conf[i]),
                        int(c_ids[i]),
                    )
                    for i in indices
                ]
            else:
                detections = []

            try:
                output_queue.put_nowait((frame_id, detections, inference_time_ms))
            except:
                pass

    except Exception as e:
        print(f"[NPU Sequential] ❌ Error: {e}", flush=True)
    finally:
        try:
            rknn.release()
        except:
            pass
        print(f"[NPU Sequential] 🛑 Stopped", flush=True)


class YoloDetectorNode(Node):
    def __init__(self):
        super().__init__("yolo_detector")
        self.get_logger().info("🔧 Initializing Optimized YOLO Detector with CA-KF...")

        # Parameters
        self.declare_parameter("model_path", "models/yolo26s-rk3588.rknn")
        self.declare_parameter("camera_id", 1)
        self.declare_parameter("obj_thresh", 0.25)
        self.declare_parameter("nms_thresh", 0.45)
        self.declare_parameter("target_object", "person")
        self.declare_parameter("enable_auto_follow", True)
        self.declare_parameter("max_linear_speed", 0.3)
        self.declare_parameter("turn_speed", 0.8)
        self.declare_parameter("parallel_inference", True)
        self.declare_parameter("enable_nv12", False)
        self.declare_parameter("center_zone_width", 0.12)
        self.declare_parameter("turn_response", 0.6)
        self.declare_parameter("smoothing_factor", 0.1)
        self.declare_parameter("min_turn_threshold", 0.03)
        self.declare_parameter("latency_compensation_ms", 80)

        self.model_path = self.get_parameter("model_path").value
        self.camera_id = self.get_parameter("camera_id").value
        self.obj_thresh = self.get_parameter("obj_thresh").value
        self.nms_thresh = self.get_parameter("nms_thresh").value
        self.target_object = self.get_parameter("target_object").value
        self.enable_auto_follow = self.get_parameter("enable_auto_follow").value
        self.max_linear_speed = self.get_parameter("max_linear_speed").value
        self.turn_speed = self.get_parameter("turn_speed").value
        self.parallel_inference = self.get_parameter("parallel_inference").value
        self.enable_nv12 = self.get_parameter("enable_nv12").value
        self.center_zone_width = self.get_parameter("center_zone_width").value
        self.turn_response = self.get_parameter("turn_response").value
        self.smoothing_factor = self.get_parameter("smoothing_factor").value
        self.min_turn_threshold = self.get_parameter("min_turn_threshold").value
        self.latency_compensation_ms = self.get_parameter("latency_compensation_ms").value

        # PID state
        self.filtered_angular_z = 0.0
        self.last_angular_update_time = time.time()
        self.integral_error = 0.0
        self.last_error = 0.0

        # CA-KF tracker
        self.tracker = MultiTargetCAKF(
            dt=0.02,
            process_noise_acc=150.0,
            measurement_noise=4.0,
            mahalanobis_threshold=5.0,
            latency_ms=self.latency_compensation_ms,
            max_tracks=20,
            track_timeout=0.5,
            iou_threshold=0.3
        )

        # LiDAR
        self.current_scan_ranges = None
        self.current_scan_angle_min = None
        self.current_scan_angle_max = None
        self.current_scan_angle_increment = None

        self.base_conf_threshold = self.obj_thresh
        self.current_fps = 0.0
        self.frame_count = 0
        self.fps_start_time = time.time()

        self.min_area_ratio = 0.001
        self.max_area_ratio = 0.5

        self.get_logger().info(
            f"📦 COCO: {len(COCO_CLASSES)} | Parallel: {self.parallel_inference}"
        )

        # Publishers
        self.detections_pub = self.create_publisher(Detection2DArray, "detections", 10)
        self.image_pub = self.create_publisher(Image, "processed_image", 10)
        self.status_pub = self.create_publisher(String, "detection_status", 10)
        self.cmd_vel_pub = self.create_publisher(Twist, "cmd_vel", 10)
        self.tracked_objects_pub = self.create_publisher(String, "tracked_objects", 10)

        # Subscribers
        self.target_sub = self.create_subscription(
            String, "set_target", self.target_callback, 10
        )
        self.conf_sub = self.create_subscription(
            Float32, "set_confidence", self.confidence_callback, 10
        )
        self.scan_sub = self.create_subscription(
            LaserScan, "scan", self.scan_callback, 10
        )

        self.cv_bridge = CvBridge()

        # Camera capture
        self.cap = cv2.VideoCapture(self.camera_id)
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
        self.cap.set(cv2.CAP_PROP_FPS, 30)
        self.cap.set(cv2.CAP_PROP_BUFFERSIZE, 1)
        self.cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*"MJPG"))

        if not self.cap.isOpened():
            self.get_logger().error(f"❌ Failed to open camera {self.camera_id}")
            raise RuntimeError(f"Failed to open camera {self.camera_id}")

        self.get_logger().info(
            f"📷 Camera: 640x480 @ 30 FPS | NV12: {self.enable_nv12}"
        )

        self.scale_x = 640 / 640.0
        self.scale_y = 480 / 640.0

        self.shutdown_event = mp.Event()

        # NPU workers
        if self.parallel_inference:
            self.prep_queue = mp.Queue(maxsize=8)
            self.result_queue = mp.Queue(maxsize=8)
            self.npu_processes = []
            num_cores = 3
            for i in range(num_cores):
                p = mp.Process(
                    target=npu_process,
                    args=(
                        i,
                        self.prep_queue,
                        self.result_queue,
                        self.model_path,
                        self.obj_thresh,
                        self.nms_thresh,
                        self.shutdown_event,
                    ),
                )
                p.start()
                self.npu_processes.append(p)
            self.get_logger().info(f"🧠 Parallel mode: {num_cores} NPU cores")
        else:
            self.prep_queue = mp.Queue(maxsize=4)
            self.result_queue = mp.Queue(maxsize=4)
            p = mp.Process(
                target=npu_process_sequential,
                args=(
                    self.model_path,
                    self.obj_thresh,
                    self.nms_thresh,
                    self.shutdown_event,
                    self.prep_queue,
                    self.result_queue,
                ),
            )
            p.start()
            self.npu_processes = [p]
            self.get_logger().info("🧠 Sequential mode: single NPU worker")

        self.frame_buffer = deque(maxlen=10)
        self.frame_id_counter = 0

        self.current_detections = []
        self.current_frame_id = 0
        self.current_inference_time = 0.0
        self.results_lock = threading.Lock()

        self.collector_running = True
        self.collector_thread = threading.Thread(
            target=self._collect_results, daemon=True
        )
        self.collector_thread.start()

        self.fps_counter = {"count": 0, "start": time.time(), "fps": 0.0}

        self.timer = self.create_timer(0.02, self.run_detection)

        self.get_logger().info("✅ Optimized YOLO Detector with CA-KF STARTED")

    def _collect_results(self):
        while self.collector_running and rclpy.ok():
            try:
                result = self.result_queue.get(timeout=QUEUE_TIMEOUT)
                frame_id, detections, inference_time_ms = result
                with self.results_lock:
                    self.current_detections = detections
                    self.current_frame_id = frame_id
                    self.current_inference_time = inference_time_ms
            except Exception:
                continue

    def target_callback(self, msg: String):
        self.target_object = msg.data
        self.get_logger().info(f"🎯 Target: {msg.data}")

    def confidence_callback(self, msg: Float32):
        self.obj_thresh = msg.data
        self.get_logger().info(f"📊 Confidence: {msg.data:.2f}")

    def scan_callback(self, msg: LaserScan):
        self.current_scan_ranges = msg.ranges
        self.current_scan_angle_min = msg.angle_min
        self.current_scan_angle_max = msg.angle_max
        self.current_scan_angle_increment = msg.angle_increment

    def _get_distance_from_lidar(self, center_x: int, frame_width: int) -> float:
        if self.current_scan_ranges is None:
            return None
        if (
            self.current_scan_angle_increment is None
            or self.current_scan_angle_min is None
        ):
            return None
        normalized_x = center_x / frame_width
        angle_rad = self.current_scan_angle_min + normalized_x * (
            self.current_scan_angle_max - self.current_scan_angle_min
        )
        angle_idx = int(
            (angle_rad - self.current_scan_angle_min)
            / self.current_scan_angle_increment
        )
        if 0 <= angle_idx < len(self.current_scan_ranges):
            r = self.current_scan_ranges[angle_idx]
            if not math.isinf(r) and not math.isnan(r) and r > 0.1:
                return float(r)
        return None

    def _scale_detections(self, detections):
        scaled = []
        for x1, y1, w, h, score, cls_id in detections:
            x1_s = x1 * self.scale_x
            y1_s = y1 * self.scale_y
            w_s = w * self.scale_x
            h_s = h * self.scale_y
            x1_s = max(0.0, min(x1_s, 640.0))
            y1_s = max(0.0, min(y1_s, 480.0))
            w_s = max(0.0, min(w_s, 640.0 - x1_s))
            h_s = max(0.0, min(h_s, 480.0 - y1_s))
            scaled.append((x1_s, y1_s, w_s, h_s, score, cls_id))
        return scaled

    def _filter_by_area(self, detections, frame_width, frame_height):
        frame_area = frame_width * frame_height
        filtered = []
        for x1, y1, w, h, score, cls_id in detections:
            area_ratio = (w * h) / frame_area
            if self.min_area_ratio <= area_ratio <= self.max_area_ratio:
                filtered.append((x1, y1, w, h, score, cls_id))
        return filtered

    def _apply_adaptive_threshold(self):
        target_fps = 25.0
        if self.current_fps < target_fps * 0.8:
            self.obj_thresh = min(0.8, self.obj_thresh + 0.02)
        elif self.current_fps > target_fps * 1.2:
            self.obj_thresh = max(0.1, self.obj_thresh - 0.01)

    def _update_fps(self):
        self.frame_count += 1
        elapsed = time.time() - self.fps_start_time
        if elapsed >= 0.5:
            self.current_fps = self.frame_count / elapsed
            self.frame_count = 0
            self.fps_start_time = time.time()
            self._apply_adaptive_threshold()

    def run_detection(self):
        ret, frame = self.cap.read()
        if not ret:
            return

        if frame.shape[0] != IMG_SIZE or frame.shape[1] != IMG_SIZE:
            resized = cv2.resize(frame, (IMG_SIZE, IMG_SIZE))
        else:
            resized = frame
        rgb = cv2.cvtColor(resized, cv2.COLOR_BGR2RGB)

        fid = self.frame_id_counter
        self.frame_id_counter += 1
        self.frame_buffer.append((fid, frame))

        npu_input = np.expand_dims(rgb, axis=0)

        try:
            if not self.prep_queue.full():
                self.prep_queue.put((fid, npu_input), timeout=QUEUE_TIMEOUT)
        except:
            pass

        with self.results_lock:
            det_fid = self.current_frame_id
            detections = list(self.current_detections)

        detections = self._scale_detections(detections)
        frame_w, frame_h = 640, 480
        detections = self._filter_by_area(detections, frame_w, frame_h)

        # Convert to tracker format
        det_list = []
        for x1, y1, w, h, score, cls_id in detections:
            cx = x1 + w / 2
            cy = y1 + h / 2
            det_list.append({
                'center': (cx, cy),
                'bbox': (x1, y1, w, h),
                'class_id': cls_id,
                'confidence': score
            })

        timestamp = time.time()
        tracked = self.tracker.update(det_list, timestamp)

        # Find target
        target_track_id = None
        target_data = None
        for tid, data in tracked.items():
            if COCO_CLASSES.get(data['class_id'], '') == self.target_object:
                if target_data is None or data['confidence'] > target_data['confidence']:
                    target_track_id = tid
                    target_data = data

        self._update_fps()

        # Display frame
        display_frame = frame
        for buffered_fid, buffered_frame in reversed(self.frame_buffer):
            if buffered_fid == det_fid:
                display_frame = buffered_frame
                break
        else:
            if len(self.frame_buffer) > 0:
                display_frame = self.frame_buffer[-1][1]

        if display_frame is None:
            display_frame = frame

        # Draw tracked objects
        for tid, data in tracked.items():
            bbox = data.get('bbox')
            if bbox is None:
                cx, cy = data['center']
                w = h = 50
                x1, y1 = int(cx - w/2), int(cy - h/2)
                bbox = (x1, y1, w, h)
            else:
                x1, y1, w, h = [int(v) for v in bbox]

            class_name = COCO_CLASSES.get(data['class_id'], str(data['class_id']))
            color = (0, 0, 255) if class_name == self.target_object else (0, 255, 0)

            cv2.rectangle(display_frame, (x1, y1), (x1 + w, y1 + h), color, 2)
            label = f"ID:{tid} {class_name} {data['confidence']:.0%}"
            cv2.putText(display_frame, label, (x1, y1-10),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 2)

            if tid == target_track_id:
                ext_cx, ext_cy = data['extrapolated_center']
                cv2.circle(display_frame, (int(ext_cx), int(ext_cy)), 6, (0, 255, 255), -1)
                cv2.putText(display_frame, "pred", (int(ext_cx)+5, int(ext_cy)-5),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.4, (0, 255, 255), 1)

        self.fps_counter["count"] += 1
        elapsed = time.time() - self.fps_counter["start"]
        if elapsed > 1.0:
            self.fps_counter["fps"] = self.fps_counter["count"] / elapsed
            self.fps_counter["count"] = 0
            self.fps_counter["start"] = time.time()

        self.publish_results(display_frame, detections, tracked, target_track_id, target_data)

    def publish_results(self, frame, detections, tracked, target_track_id, target_data):
        if self.image_pub.get_subscription_count() > 0:
            img_msg = self.cv_bridge.cv2_to_imgmsg(frame, encoding="bgr8")
            img_msg.header.stamp = self.get_clock().now().to_msg()
            img_msg.header.frame_id = "camera"
            self.image_pub.publish(img_msg)

        if self.detections_pub.get_subscription_count() > 0:
            det_array = Detection2DArray()
            det_array.header.stamp = self.get_clock().now().to_msg()
            det_array.header.frame_id = "camera"
            for x1, y1, w, h, score, cls_id in detections:
                det = Detection2D()
                det.header = det_array.header
                det.bbox.center.position.x = float(x1 + w / 2)
                det.bbox.center.position.y = float(y1 + h / 2)
                det.bbox.size_x = float(w)
                det.bbox.size_y = float(h)
                hypothesis = ObjectHypothesis()
                hypothesis.class_id = COCO_CLASSES.get(cls_id, str(cls_id))
                hypothesis.score = score
                hyp_with_pose = ObjectHypothesisWithPose()
                hyp_with_pose.hypothesis = hypothesis
                det.results.append(hyp_with_pose)
                det_array.detections.append(det)
            self.detections_pub.publish(det_array)

        if self.status_pub.get_subscription_count() > 0:
            inference_time = self.current_inference_time
            target_found = target_data is not None
            target_zone = "NONE"
            if target_data:
                ext_cx = target_data['extrapolated_center'][0]
                norm = ext_cx / 640.0
                if norm < 0.35:
                    target_zone = "LEFT"
                elif norm > 0.65:
                    target_zone = "RIGHT"
                else:
                    target_zone = "CENTER"
            detected_classes = list(set(COCO_CLASSES.get(d['class_id'], '') for d in tracked.values()))
            status = String()
            status.data = json.dumps({
                "target": self.target_object,
                "found": target_found,
                "zone": target_zone,
                "count": len(tracked),
                "classes": ", ".join(detected_classes),
                "fps": self.fps_counter["fps"],
                "inference_time": inference_time,
                "tracked": len(tracked),
                "adaptive_conf": round(self.obj_thresh, 2),
            })
            self.status_pub.publish(status)

        if self.tracked_objects_pub.get_subscription_count() > 0:
            tracked_msg = String()
            tracked_data = []
            for tid, data in tracked.items():
                vx, vy = data['velocity']
                tracked_data.append({
                    "id": tid,
                    "class": COCO_CLASSES.get(data['class_id'], str(data['class_id'])),
                    "conf": round(data['confidence'], 2),
                    "vx": round(vx, 2),
                    "vy": round(vy, 2),
                })
            tracked_msg.data = json.dumps(tracked_data)
            self.tracked_objects_pub.publish(tracked_msg)

        if self.enable_auto_follow:
            self.publish_cmd_vel(target_data, frame.shape[1])

    def publish_cmd_vel(self, target_data, frame_width):
        twist = Twist()
        if target_data is not None:
            ext_cx = target_data['extrapolated_center'][0]
            error = (ext_cx / frame_width) - 0.5
            half_zone = self.center_zone_width / 2.0

            if abs(error) < half_zone:
                target_angular = 0.0
                target_linear = self.max_linear_speed
                self.integral_error = 0.0
            else:
                dt = time.time() - self.last_angular_update_time
                if dt > 0.0 and dt < 1.0:
                    self.integral_error += error * dt
                    derivative = (error - self.last_error) / dt if dt > 0 else 0.0
                else:
                    derivative = 0.0
                Kp = self.turn_response * self.turn_speed
                Ki = 0.01
                Kd = 0.05
                target_angular = Kp * error + Ki * self.integral_error + Kd * derivative
                target_angular = max(-self.turn_speed, min(self.turn_speed, target_angular))
                target_linear = self.max_linear_speed * 0.5

                alpha = self.smoothing_factor
                self.filtered_angular_z = alpha * target_angular + (1 - alpha) * self.filtered_angular_z

                self.last_error = error
                self.last_angular_update_time = time.time()

            twist.angular.z = self.filtered_angular_z
            twist.linear.x = target_linear
        else:
            twist.angular.z = self.turn_speed * 0.3
            twist.linear.x = 0.0
            self.filtered_angular_z = twist.angular.z
            self.integral_error = 0.0

        self.cmd_vel_pub.publish(twist)

    def _shutdown_npu_workers(self):
        self.get_logger().info("🛑 Stopping NPU workers...")
        self.shutdown_event.set()
        for _ in self.npu_processes:
            try:
                self.prep_queue.put_nowait(None)
            except:
                pass
        for p in self.npu_processes:
            if p.is_alive():
                p.join(timeout=2.0)
                if p.is_alive():
                    p.terminate()
                    p.join(timeout=1.0)

    def destroy_node(self):
        self.get_logger().info("🛑 Shutting down YOLO Detector...")
        self.collector_running = False
        self._shutdown_npu_workers()
        if hasattr(self, "cap") and self.cap.isOpened():
            self.cap.release()
        try:
            self.prep_queue.close()
            self.prep_queue.join_thread()
            self.result_queue.close()
            self.result_queue.join_thread()
        except:
            pass
        super().destroy_node()


def main(args=None):
    mp.set_start_method("spawn", force=True)
    rclpy.init(args=args)
    node = YoloDetectorNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        try:
            node.destroy_node()
            rclpy.shutdown()
        except Exception:
            pass


if __name__ == "__main__":
    main()
