#!/usr/bin/env python3
"""
ZRobot Web Interface Node - Optimized with Rust Web Server
ROS2 node that communicates with PyO3 Rust server for HTTP/WebSocket
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import String, Bool, Float32
from vision_msgs.msg import Detection2DArray
from geometry_msgs.msg import Twist
import cv2
import numpy as np
import json
import threading
import time
import psutil
import os
from collections import deque
from cv_bridge import CvBridge
import argparse


class WebInterfaceNode(Node):
    def __init__(self):
        super().__init__("web_interface")

        self.declare_parameter("host", "0.0.0.0")
        self.declare_parameter("port", 8080)
        self.declare_parameter("state_update_rate", 30.0)

        self.host = self.get_parameter("host").get_parameter_value().string_value
        self.port = self.get_parameter("port").get_parameter_value().integer_value
        self.state_update_rate = (
            self.get_parameter("state_update_rate").get_parameter_value().double_value
        )

        self.start_time = time.time()
        self._last_cpu_time = time.time()
        self._cpu_cache = 0.0
        self._cpu_cache_time = 0

        self.image_sub = self.create_subscription(
            Image, "processed_image", self.image_callback, 10
        )
        self.status_sub = self.create_subscription(
            String, "detection_status", self.status_callback, 10
        )
        self.detections_sub = self.create_subscription(
            Detection2DArray, "detections", self.detections_callback, 10
        )
        self.tracked_sub = self.create_subscription(
            String, "tracked_objects", self.tracked_callback, 10
        )
        self.obstacle_sub = self.create_subscription(
            Bool, "obstacle_detected", self.obstacle_callback, 10
        )
        self.motor_status_sub = self.create_subscription(
            String, "motor_status", self.motor_status_callback, 10
        )
        self.obstacle_status_sub = self.create_subscription(
            String, "obstacle_status", self.obstacle_status_callback, 10
        )
        self.lidar_sub = self.create_subscription(
            String, "lidar_status", self.lidar_callback, 10
        )
        self.lidar_scan_sub = self.create_subscription(
            String, "lidar_scan", self.lidar_scan_callback, 10
        )

        self.target_pub = self.create_publisher(String, "set_target", 10)
        self.confidence_pub = self.create_publisher(Float32, "set_confidence", 10)
        self.motor_enable_pub = self.create_publisher(Bool, "motor_enable", 10)
        self.cmd_vel_pub = self.create_publisher(Twist, "cmd_vel", 10)
        self.obstacle_enable_pub = self.create_publisher(Bool, "obstacle_enable", 10)
        self.config_pub = self.create_publisher(String, "set_config", 10)

        self.bridge = CvBridge()
        self.frame_lock = threading.Lock()
        self.current_frame = None

        self.log_buffer = deque(maxlen=100)
        self.alerts = deque(maxlen=20)

        self._init_system_state()
        self._init_settings()

        self._rust_server = None
        self._init_rust_server()

        self.get_logger().info("Web Interface Node initialized with Rust server")

    def _init_rust_server(self):
        try:
            import zrobot_web

            self._rust_server = zrobot_web.WebServer.new()
            self.get_logger().info("PyO3 Rust server loaded")
        except ImportError:
            self.get_logger().warn("Rust server not available, using Python fallback")
            self._rust_server = None

    def _init_system_state(self):
        self.system_state = {
            "video": {
                "fps": 0,
                "resolution": "640x480",
                "codec": "mjpeg",
                "frame_count": 0,
                "bytes_sent": 0,
            },
            "detection": {
                "target": "-",
                "found": False,
                "zone": "NONE",
                "confidence": 0.0,
                "detections_count": 0,
                "tracked_count": 0,
                "inference_time_ms": 0,
                "fps": 0,
                "classes_detected": [],
                "objects": [],
            },
            "motor": {
                "enabled": True,
                "speed": 0,
                "max_speed": 245,
                "current_command": {"linear": 0.0, "angular": 0.0},
                "status": "stopped",
            },
            "obstacle_avoidance": {
                "enabled": True,
                "obstacle_detected": False,
                "min_distance_m": 999.0,
                "status": "clear",
                "min_safe_distance": 0.3,
                "slow_down_distance": 0.5,
            },
            "lidar": {"connected": False, "fps": 0, "points": 0, "scan_data": None},
            "camera": {
                "id": 1,
                "name": "USB Camera",
                "resolution": "640x480",
                "fps": 30,
                "connected": True,
            },
            "system": {
                "uptime_seconds": 0,
                "cpu_usage": 0.0,
                "memory_usage_mb": 0,
                "memory_percent": 0.0,
                "temperature": 0.0,
            },
            "settings": self.settings.copy() if hasattr(self, "settings") else {},
            "logs": [],
            "alerts": [],
        }

    def _init_settings(self):
        self.settings = {
            "target_object": "person",
            "conf_threshold": 0.45,
            "camera_id": 1,
            "enable_tracking": True,
            "obstacle_avoidance_enabled": True,
            "min_safe_distance": 0.3,
            "slow_down_distance": 0.5,
            "max_speed": 200,
        }
        self.system_state["settings"] = self.settings.copy()

    def image_callback(self, msg):
        with self.frame_lock:
            try:
                self.current_frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")
                self.system_state["video"]["frame_count"] += 1
            except Exception as e:
                self._add_log("ERROR", f"Image error: {e}")

    def status_callback(self, msg):
        try:
            data = json.loads(msg.data)
            self.system_state["detection"].update(
                {
                    "target": data.get("target", "-"),
                    "found": data.get("found", False),
                    "zone": data.get("zone", "NONE"),
                    "inference_time_ms": data.get("inference_time", 0),
                    "fps": data.get("fps", 0),
                    "detections_count": data.get("count", 0),
                    "tracked_count": data.get("tracked", 0),
                }
            )
        except Exception as e:
            self._add_log("WARN", f"Status parse: {e}")

    def detections_callback(self, msg):
        self.system_state["detection"]["detections_count"] = len(msg.detections)
        objects_list = []
        if msg.detections:
            scores = []
            for det in msg.detections:
                if det.results:
                    hyp = det.results[0].hypothesis
                    scores.append(hyp.score)
                    bbox = det.bbox
                    objects_list.append(
                        {
                            "class": hyp.class_id,
                            "confidence": round(hyp.score, 3),
                            "x": round(bbox.center.position.x - bbox.size_x / 2, 1),
                            "y": round(bbox.center.position.y - bbox.size_y / 2, 1),
                            "w": round(bbox.size_x, 1),
                            "h": round(bbox.size_y, 1),
                            "cx": round(bbox.center.position.x, 1),
                            "cy": round(bbox.center.position.y, 1),
                        }
                    )
            if scores:
                self.system_state["detection"]["confidence"] = max(scores)
        self.system_state["detection"]["objects"] = objects_list

    def tracked_callback(self, msg):
        try:
            data = json.loads(msg.data)
            self.system_state["detection"]["tracked_count"] = data.get("tracked", 0)
        except:
            pass

    def obstacle_callback(self, msg):
        self.system_state["obstacle_avoidance"]["obstacle_detected"] = msg.data

    def obstacle_status_callback(self, msg):
        try:
            data = json.loads(msg.data)
            self.system_state["obstacle_avoidance"].update(
                {
                    "obstacle_detected": data.get("obstacle", False),
                    "min_distance_m": data.get("distance", 999.0),
                    "status": "blocked" if data.get("obstacle") else "clear",
                }
            )
        except:
            pass

    def motor_status_callback(self, msg):
        try:
            data = json.loads(msg.data)
            left = int(data.get("left_speed", 0))
            right = int(data.get("right_speed", 0))
            speed = max(abs(left), abs(right))
            self.system_state["motor"].update(
                {
                    "enabled": bool(data.get("enabled", True)),
                    "left_speed": left,
                    "right_speed": right,
                    "speed": speed,
                    "status": "running" if speed > 0 else "stopped",
                }
            )
        except Exception as e:
            self._add_log("WARN", f"Motor status: {e}")

    def lidar_callback(self, msg):
        try:
            data = json.loads(msg.data)
            self.system_state["lidar"].update(
                {
                    "connected": data.get("connected", False),
                    "fps": data.get("fps", 0),
                    "points": data.get("points", 0),
                }
            )
        except:
            pass

    def lidar_scan_callback(self, msg):
        try:
            data = json.loads(msg.data)
            self.system_state["lidar"]["scan_data"] = data
        except:
            pass

    def _add_log(self, level, message):
        entry = {
            "level": level,
            "message": message,
            "timestamp": int(time.time() * 1000),
        }
        self.log_buffer.append(entry)
        if len(self.log_buffer) > 100:
            self.log_buffer.popleft()

    def update_system_stats(self):
        uptime = time.time() - self.start_time

        now = time.time()
        if now - self._last_cpu_time > 1.0:
            self._cpu_cache = psutil.cpu_percent(interval=0.1)
            self._last_cpu_time = now

        mem = psutil.virtual_memory()
        temp = 0.0
        try:
            temp = (
                psutil.sensors_temperatures()
                .get("cpu_thermal", [{}])[0]
                .get("current", 0.0)
            )
        except:
            pass

        self.system_state["system"].update(
            {
                "uptime_seconds": int(uptime),
                "cpu_usage": round(self._cpu_cache, 1),
                "memory_usage_mb": int(mem.used / 1024 / 1024),
                "memory_percent": round(mem.percent, 1),
                "temperature": round(temp, 1),
            }
        )

        self.system_state["logs"] = list(self.log_buffer)[-20:]
        self.system_state["alerts"] = list(self.alerts)[-10:]

    def _broadcast_loop(self):
        interval = 1.0 / self.state_update_rate
        while True:
            try:
                self.update_system_stats()
                json_data = json.dumps(self.system_state)

                if self._rust_server:
                    self._rust_server.update_state(json_data)
                else:
                    pass

                if self.current_frame is not None:
                    with self.frame_lock:
                        if self.current_frame is not None:
                            _, buffer = cv2.imencode(
                                ".jpg",
                                self.current_frame,
                                [cv2.IMWRITE_JPEG_QUALITY, 70],
                            )
                            if self._rust_server:
                                self._rust_server.update_frame(buffer.tobytes())
            except Exception as e:
                pass

            time.sleep(interval)

    def run(self):
        broadcast_thread = threading.Thread(target=self._broadcast_loop, daemon=True)
        broadcast_thread.start()

        if self._rust_server:
            self.get_logger().info(f"Starting Rust server on {self.host}:{self.port}")
            self._rust_server.run(self.host, self.port)
        else:
            self.get_logger().info("Starting in Python mode (no Rust server)")
            self._run_python_server()

    def _run_python_server(self):
        from aiohttp import web
        import asyncio

        app = web.Application()
        app.router.add_get("/", self.handle_index)
        app.router.add_get("/api/state", self.handle_state)
        app.router.add_get("/api/status", self.handle_status)
        app.router.add_post("/api/settings", self.handle_settings)
        app.router.add_post("/api/target", self.handle_target)
        app.router.add_post("/api/confidence", self.handle_confidence)
        app.router.add_post("/api/motor", self.handle_motor)
        app.router.add_post("/api/obstacle", self.handle_obstacle)
        app.router.add_get("/ws", self.handle_websocket)

        web.run_app(app, host=self.host, port=self.port, handle_signals=False)

    async def handle_index(self, request):
        with open("web_interface/src/static/index.html", "r") as f:
            return web.Response(text=f.read(), content_type="text/html")

    async def handle_state(self, request):
        self.update_system_stats()
        return web.json_response(self.system_state)

    async def handle_status(self, request):
        return web.json_response(self.system_state["detection"])

    async def handle_settings(self, request):
        data = await request.json()
        for key, value in data.items():
            if key in self.settings:
                self.settings[key] = value
                self.system_state["settings"][key] = value

                if key == "target_object":
                    msg = String()
                    msg.data = str(value)
                    self.target_pub.publish(msg)

        config_msg = String()
        config_msg.data = json.dumps(self.settings)
        self.config_pub.publish(config_msg)

        return web.json_response({"success": True, "settings": self.settings})

    async def handle_target(self, request):
        data = await request.json()
        target = data.get("target", "person")
        msg = String()
        msg.data = target
        self.target_pub.publish(msg)
        self.settings["target_object"] = target
        return web.json_response({"success": True, "target": target})

    async def handle_confidence(self, request):
        data = await request.json()
        confidence = float(data.get("confidence", 0.45))
        msg = Float32()
        msg.data = confidence
        self.confidence_pub.publish(msg)
        self.settings["conf_threshold"] = confidence
        return web.json_response({"success": True, "confidence": confidence})

    async def handle_motor(self, request):
        data = await request.json()
        if data.get("stop") or data.get("emergency"):
            twist = Twist()
            twist.linear.x = 0.0
            twist.angular.z = 0.0
            self.cmd_vel_pub.publish(twist)
            return web.json_response({"success": True, "action": "stop"})

        linear = float(data.get("linear", 0))
        angular = float(data.get("angular", 0))
        twist = Twist()
        twist.linear.x = linear
        twist.angular.z = angular
        self.cmd_vel_pub.publish(twist)
        return web.json_response(
            {"success": True, "linear": linear, "angular": angular}
        )

    async def handle_obstacle(self, request):
        data = await request.json()
        if "enabled" in data:
            self.settings["obstacle_avoidance_enabled"] = data["enabled"]
            msg = Bool()
            msg.data = data["enabled"]
            self.obstacle_enable_pub.publish(msg)
        return web.json_response({"success": True})

    async def handle_websocket(self, request):
        from aiohttp import web

        ws = web.WebSocketResponse()
        await ws.prepare(request)
        await ws.send_str(
            json.dumps(
                {
                    "type": "welcome",
                    "message": "Connected to ZRobot",
                    "settings": self.settings,
                }
            )
        )

        async for msg in ws:
            if msg.type == web.WSMsgType.TEXT:
                data = json.loads(msg.data)
                action = data.get("action")
                payload = data.get("payload", {})

                if action == "motor_control":
                    linear = float(payload.get("linear", 0))
                    angular = float(payload.get("angular", 0))
                    twist = Twist()
                    twist.linear.x = linear
                    twist.angular.z = angular
                    self.cmd_vel_pub.publish(twist)
                    await ws.send_str(
                        json.dumps(
                            {"type": "ack", "action": "motor_control", "success": True}
                        )
                    )

        return ws


def main():
    parser = argparse.ArgumentParser(description="ZRobot Web Interface")
    parser.add_argument("--host", default="0.0.0.0", help="Host")
    parser.add_argument("--port", type=int, default=8080, help="Port")
    parser.add_argument("--rate", type=float, default=30.0, help="Update rate (Hz)")
    args, unknown = parser.parse_known_args()

    rclpy.init(args=unknown)
    node = WebInterfaceNode()
    node.host = args.host
    node.port = args.port
    node.state_update_rate = args.rate

    server_thread = threading.Thread(target=node.run, daemon=True)
    server_thread.start()

    executor = rclpy.executors.SingleThreadedExecutor()
    executor.add_node(node)

    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        try:
            node.destroy_node()
            rclpy.shutdown()
        except:
            pass


if __name__ == "__main__":
    main()
