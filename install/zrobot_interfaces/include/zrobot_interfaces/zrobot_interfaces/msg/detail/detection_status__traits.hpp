// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from zrobot_interfaces:msg/DetectionStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "zrobot_interfaces/msg/detection_status.hpp"


#ifndef ZROBOT_INTERFACES__MSG__DETAIL__DETECTION_STATUS__TRAITS_HPP_
#define ZROBOT_INTERFACES__MSG__DETAIL__DETECTION_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "zrobot_interfaces/msg/detail/detection_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace zrobot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DetectionStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_object
  {
    out << "target_object: ";
    rosidl_generator_traits::value_to_yaml(msg.target_object, out);
    out << ", ";
  }

  // member: target_found
  {
    out << "target_found: ";
    rosidl_generator_traits::value_to_yaml(msg.target_found, out);
    out << ", ";
  }

  // member: zone
  {
    out << "zone: ";
    rosidl_generator_traits::value_to_yaml(msg.zone, out);
    out << ", ";
  }

  // member: target_count
  {
    out << "target_count: ";
    rosidl_generator_traits::value_to_yaml(msg.target_count, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: inference_time_ms
  {
    out << "inference_time_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.inference_time_ms, out);
    out << ", ";
  }

  // member: fps
  {
    out << "fps: ";
    rosidl_generator_traits::value_to_yaml(msg.fps, out);
    out << ", ";
  }

  // member: frame_width
  {
    out << "frame_width: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_width, out);
    out << ", ";
  }

  // member: frame_height
  {
    out << "frame_height: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_height, out);
    out << ", ";
  }

  // member: target_center_x
  {
    out << "target_center_x: ";
    rosidl_generator_traits::value_to_yaml(msg.target_center_x, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectionStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target_object
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_object: ";
    rosidl_generator_traits::value_to_yaml(msg.target_object, out);
    out << "\n";
  }

  // member: target_found
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_found: ";
    rosidl_generator_traits::value_to_yaml(msg.target_found, out);
    out << "\n";
  }

  // member: zone
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zone: ";
    rosidl_generator_traits::value_to_yaml(msg.zone, out);
    out << "\n";
  }

  // member: target_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_count: ";
    rosidl_generator_traits::value_to_yaml(msg.target_count, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: inference_time_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "inference_time_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.inference_time_ms, out);
    out << "\n";
  }

  // member: fps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fps: ";
    rosidl_generator_traits::value_to_yaml(msg.fps, out);
    out << "\n";
  }

  // member: frame_width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frame_width: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_width, out);
    out << "\n";
  }

  // member: frame_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frame_height: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_height, out);
    out << "\n";
  }

  // member: target_center_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_center_x: ";
    rosidl_generator_traits::value_to_yaml(msg.target_center_x, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectionStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace zrobot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use zrobot_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const zrobot_interfaces::msg::DetectionStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  zrobot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use zrobot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const zrobot_interfaces::msg::DetectionStatus & msg)
{
  return zrobot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<zrobot_interfaces::msg::DetectionStatus>()
{
  return "zrobot_interfaces::msg::DetectionStatus";
}

template<>
inline const char * name<zrobot_interfaces::msg::DetectionStatus>()
{
  return "zrobot_interfaces/msg/DetectionStatus";
}

template<>
struct has_fixed_size<zrobot_interfaces::msg::DetectionStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<zrobot_interfaces::msg::DetectionStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<zrobot_interfaces::msg::DetectionStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ZROBOT_INTERFACES__MSG__DETAIL__DETECTION_STATUS__TRAITS_HPP_
