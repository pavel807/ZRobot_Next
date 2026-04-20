// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from zrobot_interfaces:srv/SetConfig.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "zrobot_interfaces/srv/set_config.h"


#ifndef ZROBOT_INTERFACES__SRV__DETAIL__SET_CONFIG__STRUCT_H_
#define ZROBOT_INTERFACES__SRV__DETAIL__SET_CONFIG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'parameter_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetConfig in the package zrobot_interfaces.
typedef struct zrobot_interfaces__srv__SetConfig_Request
{
  /// Parameter to change (e.g., "confidence", "max_speed")
  rosidl_runtime_c__String parameter_name;
  /// New value
  float value;
} zrobot_interfaces__srv__SetConfig_Request;

// Struct for a sequence of zrobot_interfaces__srv__SetConfig_Request.
typedef struct zrobot_interfaces__srv__SetConfig_Request__Sequence
{
  zrobot_interfaces__srv__SetConfig_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zrobot_interfaces__srv__SetConfig_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetConfig in the package zrobot_interfaces.
typedef struct zrobot_interfaces__srv__SetConfig_Response
{
  /// True if parameter was set successfully
  bool success;
  /// Status message
  rosidl_runtime_c__String message;
} zrobot_interfaces__srv__SetConfig_Response;

// Struct for a sequence of zrobot_interfaces__srv__SetConfig_Response.
typedef struct zrobot_interfaces__srv__SetConfig_Response__Sequence
{
  zrobot_interfaces__srv__SetConfig_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zrobot_interfaces__srv__SetConfig_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  zrobot_interfaces__srv__SetConfig_Event__request__MAX_SIZE = 1
};
// response
enum
{
  zrobot_interfaces__srv__SetConfig_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SetConfig in the package zrobot_interfaces.
typedef struct zrobot_interfaces__srv__SetConfig_Event
{
  service_msgs__msg__ServiceEventInfo info;
  zrobot_interfaces__srv__SetConfig_Request__Sequence request;
  zrobot_interfaces__srv__SetConfig_Response__Sequence response;
} zrobot_interfaces__srv__SetConfig_Event;

// Struct for a sequence of zrobot_interfaces__srv__SetConfig_Event.
typedef struct zrobot_interfaces__srv__SetConfig_Event__Sequence
{
  zrobot_interfaces__srv__SetConfig_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zrobot_interfaces__srv__SetConfig_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ZROBOT_INTERFACES__SRV__DETAIL__SET_CONFIG__STRUCT_H_
