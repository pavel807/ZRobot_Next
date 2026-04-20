// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from zrobot_interfaces:msg/DetectionStatus.idl
// generated code does not contain a copyright notice

#ifndef ZROBOT_INTERFACES__MSG__DETAIL__DETECTION_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define ZROBOT_INTERFACES__MSG__DETAIL__DETECTION_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "zrobot_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "zrobot_interfaces/msg/detail/detection_status__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace zrobot_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zrobot_interfaces
cdr_serialize(
  const zrobot_interfaces::msg::DetectionStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zrobot_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  zrobot_interfaces::msg::DetectionStatus & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zrobot_interfaces
get_serialized_size(
  const zrobot_interfaces::msg::DetectionStatus & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zrobot_interfaces
max_serialized_size_DetectionStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zrobot_interfaces
cdr_serialize_key(
  const zrobot_interfaces::msg::DetectionStatus & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zrobot_interfaces
get_serialized_size_key(
  const zrobot_interfaces::msg::DetectionStatus & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zrobot_interfaces
max_serialized_size_key_DetectionStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace zrobot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zrobot_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, zrobot_interfaces, msg, DetectionStatus)();

#ifdef __cplusplus
}
#endif

#endif  // ZROBOT_INTERFACES__MSG__DETAIL__DETECTION_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
