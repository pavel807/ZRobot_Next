// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from zrobot_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice
#ifndef ZROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define ZROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "zrobot_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "zrobot_interfaces/msg/detail/motor_command__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zrobot_interfaces
bool cdr_serialize_zrobot_interfaces__msg__MotorCommand(
  const zrobot_interfaces__msg__MotorCommand * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zrobot_interfaces
bool cdr_deserialize_zrobot_interfaces__msg__MotorCommand(
  eprosima::fastcdr::Cdr &,
  zrobot_interfaces__msg__MotorCommand * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zrobot_interfaces
size_t get_serialized_size_zrobot_interfaces__msg__MotorCommand(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zrobot_interfaces
size_t max_serialized_size_zrobot_interfaces__msg__MotorCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zrobot_interfaces
bool cdr_serialize_key_zrobot_interfaces__msg__MotorCommand(
  const zrobot_interfaces__msg__MotorCommand * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zrobot_interfaces
size_t get_serialized_size_key_zrobot_interfaces__msg__MotorCommand(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zrobot_interfaces
size_t max_serialized_size_key_zrobot_interfaces__msg__MotorCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zrobot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, zrobot_interfaces, msg, MotorCommand)();

#ifdef __cplusplus
}
#endif

#endif  // ZROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
