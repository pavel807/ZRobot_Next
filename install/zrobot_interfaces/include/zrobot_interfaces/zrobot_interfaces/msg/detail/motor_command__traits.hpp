// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from zrobot_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "zrobot_interfaces/msg/motor_command.hpp"


#ifndef ZROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__TRAITS_HPP_
#define ZROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "zrobot_interfaces/msg/detail/motor_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace zrobot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: left_speed
  {
    out << "left_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.left_speed, out);
    out << ", ";
  }

  // member: right_speed
  {
    out << "right_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.right_speed, out);
    out << ", ";
  }

  // member: motors_running
  {
    out << "motors_running: ";
    rosidl_generator_traits::value_to_yaml(msg.motors_running, out);
    out << ", ";
  }

  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: left_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.left_speed, out);
    out << "\n";
  }

  // member: right_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.right_speed, out);
    out << "\n";
  }

  // member: motors_running
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motors_running: ";
    rosidl_generator_traits::value_to_yaml(msg.motors_running, out);
    out << "\n";
  }

  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorCommand & msg, bool use_flow_style = false)
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
  const zrobot_interfaces::msg::MotorCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  zrobot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use zrobot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const zrobot_interfaces::msg::MotorCommand & msg)
{
  return zrobot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<zrobot_interfaces::msg::MotorCommand>()
{
  return "zrobot_interfaces::msg::MotorCommand";
}

template<>
inline const char * name<zrobot_interfaces::msg::MotorCommand>()
{
  return "zrobot_interfaces/msg/MotorCommand";
}

template<>
struct has_fixed_size<zrobot_interfaces::msg::MotorCommand>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<zrobot_interfaces::msg::MotorCommand>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<zrobot_interfaces::msg::MotorCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ZROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__TRAITS_HPP_
