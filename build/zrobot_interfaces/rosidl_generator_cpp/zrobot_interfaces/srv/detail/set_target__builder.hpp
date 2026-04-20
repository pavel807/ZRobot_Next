// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from zrobot_interfaces:srv/SetTarget.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "zrobot_interfaces/srv/set_target.hpp"


#ifndef ZROBOT_INTERFACES__SRV__DETAIL__SET_TARGET__BUILDER_HPP_
#define ZROBOT_INTERFACES__SRV__DETAIL__SET_TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "zrobot_interfaces/srv/detail/set_target__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace zrobot_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetTarget_Request_target_object
{
public:
  Init_SetTarget_Request_target_object()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::zrobot_interfaces::srv::SetTarget_Request target_object(::zrobot_interfaces::srv::SetTarget_Request::_target_object_type arg)
  {
    msg_.target_object = std::move(arg);
    return std::move(msg_);
  }

private:
  ::zrobot_interfaces::srv::SetTarget_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::zrobot_interfaces::srv::SetTarget_Request>()
{
  return zrobot_interfaces::srv::builder::Init_SetTarget_Request_target_object();
}

}  // namespace zrobot_interfaces


namespace zrobot_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetTarget_Response_message
{
public:
  explicit Init_SetTarget_Response_message(::zrobot_interfaces::srv::SetTarget_Response & msg)
  : msg_(msg)
  {}
  ::zrobot_interfaces::srv::SetTarget_Response message(::zrobot_interfaces::srv::SetTarget_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::zrobot_interfaces::srv::SetTarget_Response msg_;
};

class Init_SetTarget_Response_success
{
public:
  Init_SetTarget_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetTarget_Response_message success(::zrobot_interfaces::srv::SetTarget_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetTarget_Response_message(msg_);
  }

private:
  ::zrobot_interfaces::srv::SetTarget_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::zrobot_interfaces::srv::SetTarget_Response>()
{
  return zrobot_interfaces::srv::builder::Init_SetTarget_Response_success();
}

}  // namespace zrobot_interfaces


namespace zrobot_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetTarget_Event_response
{
public:
  explicit Init_SetTarget_Event_response(::zrobot_interfaces::srv::SetTarget_Event & msg)
  : msg_(msg)
  {}
  ::zrobot_interfaces::srv::SetTarget_Event response(::zrobot_interfaces::srv::SetTarget_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::zrobot_interfaces::srv::SetTarget_Event msg_;
};

class Init_SetTarget_Event_request
{
public:
  explicit Init_SetTarget_Event_request(::zrobot_interfaces::srv::SetTarget_Event & msg)
  : msg_(msg)
  {}
  Init_SetTarget_Event_response request(::zrobot_interfaces::srv::SetTarget_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetTarget_Event_response(msg_);
  }

private:
  ::zrobot_interfaces::srv::SetTarget_Event msg_;
};

class Init_SetTarget_Event_info
{
public:
  Init_SetTarget_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetTarget_Event_request info(::zrobot_interfaces::srv::SetTarget_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetTarget_Event_request(msg_);
  }

private:
  ::zrobot_interfaces::srv::SetTarget_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::zrobot_interfaces::srv::SetTarget_Event>()
{
  return zrobot_interfaces::srv::builder::Init_SetTarget_Event_info();
}

}  // namespace zrobot_interfaces

#endif  // ZROBOT_INTERFACES__SRV__DETAIL__SET_TARGET__BUILDER_HPP_
