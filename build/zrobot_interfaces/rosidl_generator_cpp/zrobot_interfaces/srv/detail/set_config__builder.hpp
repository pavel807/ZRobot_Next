// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from zrobot_interfaces:srv/SetConfig.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "zrobot_interfaces/srv/set_config.hpp"


#ifndef ZROBOT_INTERFACES__SRV__DETAIL__SET_CONFIG__BUILDER_HPP_
#define ZROBOT_INTERFACES__SRV__DETAIL__SET_CONFIG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "zrobot_interfaces/srv/detail/set_config__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace zrobot_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetConfig_Request_value
{
public:
  explicit Init_SetConfig_Request_value(::zrobot_interfaces::srv::SetConfig_Request & msg)
  : msg_(msg)
  {}
  ::zrobot_interfaces::srv::SetConfig_Request value(::zrobot_interfaces::srv::SetConfig_Request::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::zrobot_interfaces::srv::SetConfig_Request msg_;
};

class Init_SetConfig_Request_parameter_name
{
public:
  Init_SetConfig_Request_parameter_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetConfig_Request_value parameter_name(::zrobot_interfaces::srv::SetConfig_Request::_parameter_name_type arg)
  {
    msg_.parameter_name = std::move(arg);
    return Init_SetConfig_Request_value(msg_);
  }

private:
  ::zrobot_interfaces::srv::SetConfig_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::zrobot_interfaces::srv::SetConfig_Request>()
{
  return zrobot_interfaces::srv::builder::Init_SetConfig_Request_parameter_name();
}

}  // namespace zrobot_interfaces


namespace zrobot_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetConfig_Response_message
{
public:
  explicit Init_SetConfig_Response_message(::zrobot_interfaces::srv::SetConfig_Response & msg)
  : msg_(msg)
  {}
  ::zrobot_interfaces::srv::SetConfig_Response message(::zrobot_interfaces::srv::SetConfig_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::zrobot_interfaces::srv::SetConfig_Response msg_;
};

class Init_SetConfig_Response_success
{
public:
  Init_SetConfig_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetConfig_Response_message success(::zrobot_interfaces::srv::SetConfig_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetConfig_Response_message(msg_);
  }

private:
  ::zrobot_interfaces::srv::SetConfig_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::zrobot_interfaces::srv::SetConfig_Response>()
{
  return zrobot_interfaces::srv::builder::Init_SetConfig_Response_success();
}

}  // namespace zrobot_interfaces


namespace zrobot_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetConfig_Event_response
{
public:
  explicit Init_SetConfig_Event_response(::zrobot_interfaces::srv::SetConfig_Event & msg)
  : msg_(msg)
  {}
  ::zrobot_interfaces::srv::SetConfig_Event response(::zrobot_interfaces::srv::SetConfig_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::zrobot_interfaces::srv::SetConfig_Event msg_;
};

class Init_SetConfig_Event_request
{
public:
  explicit Init_SetConfig_Event_request(::zrobot_interfaces::srv::SetConfig_Event & msg)
  : msg_(msg)
  {}
  Init_SetConfig_Event_response request(::zrobot_interfaces::srv::SetConfig_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetConfig_Event_response(msg_);
  }

private:
  ::zrobot_interfaces::srv::SetConfig_Event msg_;
};

class Init_SetConfig_Event_info
{
public:
  Init_SetConfig_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetConfig_Event_request info(::zrobot_interfaces::srv::SetConfig_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetConfig_Event_request(msg_);
  }

private:
  ::zrobot_interfaces::srv::SetConfig_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::zrobot_interfaces::srv::SetConfig_Event>()
{
  return zrobot_interfaces::srv::builder::Init_SetConfig_Event_info();
}

}  // namespace zrobot_interfaces

#endif  // ZROBOT_INTERFACES__SRV__DETAIL__SET_CONFIG__BUILDER_HPP_
