// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from zrobot_interfaces:msg/DetectionStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "zrobot_interfaces/msg/detection_status.hpp"


#ifndef ZROBOT_INTERFACES__MSG__DETAIL__DETECTION_STATUS__BUILDER_HPP_
#define ZROBOT_INTERFACES__MSG__DETAIL__DETECTION_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "zrobot_interfaces/msg/detail/detection_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace zrobot_interfaces
{

namespace msg
{

namespace builder
{

class Init_DetectionStatus_target_center_x
{
public:
  explicit Init_DetectionStatus_target_center_x(::zrobot_interfaces::msg::DetectionStatus & msg)
  : msg_(msg)
  {}
  ::zrobot_interfaces::msg::DetectionStatus target_center_x(::zrobot_interfaces::msg::DetectionStatus::_target_center_x_type arg)
  {
    msg_.target_center_x = std::move(arg);
    return std::move(msg_);
  }

private:
  ::zrobot_interfaces::msg::DetectionStatus msg_;
};

class Init_DetectionStatus_frame_height
{
public:
  explicit Init_DetectionStatus_frame_height(::zrobot_interfaces::msg::DetectionStatus & msg)
  : msg_(msg)
  {}
  Init_DetectionStatus_target_center_x frame_height(::zrobot_interfaces::msg::DetectionStatus::_frame_height_type arg)
  {
    msg_.frame_height = std::move(arg);
    return Init_DetectionStatus_target_center_x(msg_);
  }

private:
  ::zrobot_interfaces::msg::DetectionStatus msg_;
};

class Init_DetectionStatus_frame_width
{
public:
  explicit Init_DetectionStatus_frame_width(::zrobot_interfaces::msg::DetectionStatus & msg)
  : msg_(msg)
  {}
  Init_DetectionStatus_frame_height frame_width(::zrobot_interfaces::msg::DetectionStatus::_frame_width_type arg)
  {
    msg_.frame_width = std::move(arg);
    return Init_DetectionStatus_frame_height(msg_);
  }

private:
  ::zrobot_interfaces::msg::DetectionStatus msg_;
};

class Init_DetectionStatus_fps
{
public:
  explicit Init_DetectionStatus_fps(::zrobot_interfaces::msg::DetectionStatus & msg)
  : msg_(msg)
  {}
  Init_DetectionStatus_frame_width fps(::zrobot_interfaces::msg::DetectionStatus::_fps_type arg)
  {
    msg_.fps = std::move(arg);
    return Init_DetectionStatus_frame_width(msg_);
  }

private:
  ::zrobot_interfaces::msg::DetectionStatus msg_;
};

class Init_DetectionStatus_inference_time_ms
{
public:
  explicit Init_DetectionStatus_inference_time_ms(::zrobot_interfaces::msg::DetectionStatus & msg)
  : msg_(msg)
  {}
  Init_DetectionStatus_fps inference_time_ms(::zrobot_interfaces::msg::DetectionStatus::_inference_time_ms_type arg)
  {
    msg_.inference_time_ms = std::move(arg);
    return Init_DetectionStatus_fps(msg_);
  }

private:
  ::zrobot_interfaces::msg::DetectionStatus msg_;
};

class Init_DetectionStatus_confidence
{
public:
  explicit Init_DetectionStatus_confidence(::zrobot_interfaces::msg::DetectionStatus & msg)
  : msg_(msg)
  {}
  Init_DetectionStatus_inference_time_ms confidence(::zrobot_interfaces::msg::DetectionStatus::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_DetectionStatus_inference_time_ms(msg_);
  }

private:
  ::zrobot_interfaces::msg::DetectionStatus msg_;
};

class Init_DetectionStatus_target_count
{
public:
  explicit Init_DetectionStatus_target_count(::zrobot_interfaces::msg::DetectionStatus & msg)
  : msg_(msg)
  {}
  Init_DetectionStatus_confidence target_count(::zrobot_interfaces::msg::DetectionStatus::_target_count_type arg)
  {
    msg_.target_count = std::move(arg);
    return Init_DetectionStatus_confidence(msg_);
  }

private:
  ::zrobot_interfaces::msg::DetectionStatus msg_;
};

class Init_DetectionStatus_zone
{
public:
  explicit Init_DetectionStatus_zone(::zrobot_interfaces::msg::DetectionStatus & msg)
  : msg_(msg)
  {}
  Init_DetectionStatus_target_count zone(::zrobot_interfaces::msg::DetectionStatus::_zone_type arg)
  {
    msg_.zone = std::move(arg);
    return Init_DetectionStatus_target_count(msg_);
  }

private:
  ::zrobot_interfaces::msg::DetectionStatus msg_;
};

class Init_DetectionStatus_target_found
{
public:
  explicit Init_DetectionStatus_target_found(::zrobot_interfaces::msg::DetectionStatus & msg)
  : msg_(msg)
  {}
  Init_DetectionStatus_zone target_found(::zrobot_interfaces::msg::DetectionStatus::_target_found_type arg)
  {
    msg_.target_found = std::move(arg);
    return Init_DetectionStatus_zone(msg_);
  }

private:
  ::zrobot_interfaces::msg::DetectionStatus msg_;
};

class Init_DetectionStatus_target_object
{
public:
  Init_DetectionStatus_target_object()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectionStatus_target_found target_object(::zrobot_interfaces::msg::DetectionStatus::_target_object_type arg)
  {
    msg_.target_object = std::move(arg);
    return Init_DetectionStatus_target_found(msg_);
  }

private:
  ::zrobot_interfaces::msg::DetectionStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::zrobot_interfaces::msg::DetectionStatus>()
{
  return zrobot_interfaces::msg::builder::Init_DetectionStatus_target_object();
}

}  // namespace zrobot_interfaces

#endif  // ZROBOT_INTERFACES__MSG__DETAIL__DETECTION_STATUS__BUILDER_HPP_
