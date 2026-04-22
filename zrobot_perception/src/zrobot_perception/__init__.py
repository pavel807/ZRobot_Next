#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Tracker wrapper with automatic Rust fallback to Python.
If rust_tracker module is not available, automatically falls back to Python implementation.
"""

import sys
import os

_USE_RUST = False
_tracker_module = None


def _try_import_rust():
    """Try to import rust_tracker, return True if available."""
    global _USE_RUST, _tracker_module

    try:
        import rust_tracker

        _tracker_module = rust_tracker
        _USE_RUST = True
        print("[tracker] Using Rust implementation", file=sys.stderr)
        return True
    except ImportError:
        _USE_RUST = False
        return False


def _build_rust_tracker():
    """Build rust_tracker if needed and possible."""
    rust_src = os.path.join(os.path.dirname(__file__), "..", "rust_tracker")

    if not os.path.exists(rust_src):
        return False

    try:
        import subprocess

        result = subprocess.run(
            ["maturin", "build", "--release"],
            cwd=rust_src,
            capture_output=True,
            text=True,
        )
        if result.returncode == 0:
            wheel_dir = os.path.join(rust_src, "target", "wheels")
            for f in os.listdir(wheel_dir):
                if f.endswith(".whl"):
                    sys.path.insert(0, os.path.join(wheel_dir, f))
                    return _try_import_rust()
        else:
            print(f"[tracker] Rust build failed: {result.stderr}", file=sys.stderr)
    except Exception as e:
        print(f"[tracker] Could not build Rust: {e}", file=sys.stderr)

    return False


def get_tracker_class():
    """
    Get the appropriate tracker class.
    Tries Rust first, falls back to Python if Rust unavailable.
    """
    if _USE_RUST:
        return _tracker_module.MultiTargetCAKF

    from zrobot_perception.ca_kalman_filter import MultiTargetCAKF as PyMultiTargetCAKF

    return PyMultiTargetCAKF


def get_iou_tracker_class():
    """Get the appropriate IoU tracker class."""
    if _USE_RUST:
        return _tracker_module.IoUTracker

    from zrobot_perception.iou_tracker import IoUTracker as PyIoUTracker

    return PyIoUTracker


def is_using_rust():
    """Return True if using Rust implementation."""
    return _USE_RUST


_initialized = _try_import_rust() or _build_rust_tracker()

if not _initialized:
    print("[tracker] Using Python implementation (fallback)", file=sys.stderr)

from .ca_kalman_filter import ConstantAccelerationKalmanFilter, MultiTargetCAKF
from .iou_tracker import SingleObjectTracker, IoUTracker, compute_iou

__all__ = [
    "get_tracker_class",
    "get_iou_tracker_class",
    "is_using_rust",
    "ConstantAccelerationKalmanFilter",
    "MultiTargetCAKF",
    "SingleObjectTracker",
    "IoUTracker",
    "compute_iou",
]
