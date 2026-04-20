// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from zrobot_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "zrobot_interfaces/msg/motor_command.h"


#ifndef ZROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__STRUCT_H_
#define ZROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'mode'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MotorCommand in the package zrobot_interfaces.
/**
  * Motor command message
  * Published by object_tracker, consumed by motor_controller
 */
typedef struct zrobot_interfaces__msg__MotorCommand
{
  /// Left motor speed (0-255)
  int32_t left_speed;
  /// Right motor speed (0-255)
  int32_t right_speed;
  /// True if motors are active
  bool motors_running;
  /// "TRACKING", "SEARCHING", "STOPPED"
  rosidl_runtime_c__String mode;
} zrobot_interfaces__msg__MotorCommand;

// Struct for a sequence of zrobot_interfaces__msg__MotorCommand.
typedef struct zrobot_interfaces__msg__MotorCommand__Sequence
{
  zrobot_interfaces__msg__MotorCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zrobot_interfaces__msg__MotorCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ZROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__STRUCT_H_
