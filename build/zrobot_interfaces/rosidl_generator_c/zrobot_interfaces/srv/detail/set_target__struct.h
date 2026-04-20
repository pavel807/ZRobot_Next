// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from zrobot_interfaces:srv/SetTarget.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "zrobot_interfaces/srv/set_target.h"


#ifndef ZROBOT_INTERFACES__SRV__DETAIL__SET_TARGET__STRUCT_H_
#define ZROBOT_INTERFACES__SRV__DETAIL__SET_TARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target_object'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetTarget in the package zrobot_interfaces.
typedef struct zrobot_interfaces__srv__SetTarget_Request
{
  /// Object class to track (e.g., "person", "car")
  rosidl_runtime_c__String target_object;
} zrobot_interfaces__srv__SetTarget_Request;

// Struct for a sequence of zrobot_interfaces__srv__SetTarget_Request.
typedef struct zrobot_interfaces__srv__SetTarget_Request__Sequence
{
  zrobot_interfaces__srv__SetTarget_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zrobot_interfaces__srv__SetTarget_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetTarget in the package zrobot_interfaces.
typedef struct zrobot_interfaces__srv__SetTarget_Response
{
  /// True if target was set successfully
  bool success;
  /// Status message
  rosidl_runtime_c__String message;
} zrobot_interfaces__srv__SetTarget_Response;

// Struct for a sequence of zrobot_interfaces__srv__SetTarget_Response.
typedef struct zrobot_interfaces__srv__SetTarget_Response__Sequence
{
  zrobot_interfaces__srv__SetTarget_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zrobot_interfaces__srv__SetTarget_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  zrobot_interfaces__srv__SetTarget_Event__request__MAX_SIZE = 1
};
// response
enum
{
  zrobot_interfaces__srv__SetTarget_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SetTarget in the package zrobot_interfaces.
typedef struct zrobot_interfaces__srv__SetTarget_Event
{
  service_msgs__msg__ServiceEventInfo info;
  zrobot_interfaces__srv__SetTarget_Request__Sequence request;
  zrobot_interfaces__srv__SetTarget_Response__Sequence response;
} zrobot_interfaces__srv__SetTarget_Event;

// Struct for a sequence of zrobot_interfaces__srv__SetTarget_Event.
typedef struct zrobot_interfaces__srv__SetTarget_Event__Sequence
{
  zrobot_interfaces__srv__SetTarget_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zrobot_interfaces__srv__SetTarget_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ZROBOT_INTERFACES__SRV__DETAIL__SET_TARGET__STRUCT_H_
