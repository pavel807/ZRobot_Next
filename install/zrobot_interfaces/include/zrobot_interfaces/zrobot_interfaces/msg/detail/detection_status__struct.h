// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from zrobot_interfaces:msg/DetectionStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "zrobot_interfaces/msg/detection_status.h"


#ifndef ZROBOT_INTERFACES__MSG__DETAIL__DETECTION_STATUS__STRUCT_H_
#define ZROBOT_INTERFACES__MSG__DETAIL__DETECTION_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'target_object'
// Member 'zone'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/DetectionStatus in the package zrobot_interfaces.
/**
  * Detection status message
  * Published by yolo_detector_node
 */
typedef struct zrobot_interfaces__msg__DetectionStatus
{
  /// Target object class name
  rosidl_runtime_c__String target_object;
  /// True if target is detected
  bool target_found;
  /// "LEFT", "CENTER", "RIGHT", "NONE"
  rosidl_runtime_c__String zone;
  /// Number of detected targets
  int32_t target_count;
  /// Confidence threshold
  float confidence;
  /// Inference time in milliseconds
  float inference_time_ms;
  /// Current FPS
  int32_t fps;
  /// Frame width
  int32_t frame_width;
  /// Frame height
  int32_t frame_height;
  /// X coordinate of target center
  float target_center_x;
} zrobot_interfaces__msg__DetectionStatus;

// Struct for a sequence of zrobot_interfaces__msg__DetectionStatus.
typedef struct zrobot_interfaces__msg__DetectionStatus__Sequence
{
  zrobot_interfaces__msg__DetectionStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zrobot_interfaces__msg__DetectionStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ZROBOT_INTERFACES__MSG__DETAIL__DETECTION_STATUS__STRUCT_H_
