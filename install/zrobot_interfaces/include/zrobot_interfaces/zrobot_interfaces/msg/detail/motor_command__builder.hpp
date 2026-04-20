// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from zrobot_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "zrobot_interfaces/msg/motor_command.hpp"


#ifndef ZROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__BUILDER_HPP_
#define ZROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "zrobot_interfaces/msg/detail/motor_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace zrobot_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotorCommand_mode
{
public:
  explicit Init_MotorCommand_mode(::zrobot_interfaces::msg::MotorCommand & msg)
  : msg_(msg)
  {}
  ::zrobot_interfaces::msg::MotorCommand mode(::zrobot_interfaces::msg::MotorCommand::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::zrobot_interfaces::msg::MotorCommand msg_;
};

class Init_MotorCommand_motors_running
{
public:
  explicit Init_MotorCommand_motors_running(::zrobot_interfaces::msg::MotorCommand & msg)
  : msg_(msg)
  {}
  Init_MotorCommand_mode motors_running(::zrobot_interfaces::msg::MotorCommand::_motors_running_type arg)
  {
    msg_.motors_running = std::move(arg);
    return Init_MotorCommand_mode(msg_);
  }

private:
  ::zrobot_interfaces::msg::MotorCommand msg_;
};

class Init_MotorCommand_right_speed
{
public:
  explicit Init_MotorCommand_right_speed(::zrobot_interfaces::msg::MotorCommand & msg)
  : msg_(msg)
  {}
  Init_MotorCommand_motors_running right_speed(::zrobot_interfaces::msg::MotorCommand::_right_speed_type arg)
  {
    msg_.right_speed = std::move(arg);
    return Init_MotorCommand_motors_running(msg_);
  }

private:
  ::zrobot_interfaces::msg::MotorCommand msg_;
};

class Init_MotorCommand_left_speed
{
public:
  Init_MotorCommand_left_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorCommand_right_speed left_speed(::zrobot_interfaces::msg::MotorCommand::_left_speed_type arg)
  {
    msg_.left_speed = std::move(arg);
    return Init_MotorCommand_right_speed(msg_);
  }

private:
  ::zrobot_interfaces::msg::MotorCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::zrobot_interfaces::msg::MotorCommand>()
{
  return zrobot_interfaces::msg::builder::Init_MotorCommand_left_speed();
}

}  // namespace zrobot_interfaces

#endif  // ZROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__BUILDER_HPP_
