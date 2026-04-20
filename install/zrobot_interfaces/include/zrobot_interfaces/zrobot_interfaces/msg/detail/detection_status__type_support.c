// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from zrobot_interfaces:msg/DetectionStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "zrobot_interfaces/msg/detail/detection_status__rosidl_typesupport_introspection_c.h"
#include "zrobot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "zrobot_interfaces/msg/detail/detection_status__functions.h"
#include "zrobot_interfaces/msg/detail/detection_status__struct.h"


// Include directives for member types
// Member `target_object`
// Member `zone`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void zrobot_interfaces__msg__DetectionStatus__rosidl_typesupport_introspection_c__DetectionStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  zrobot_interfaces__msg__DetectionStatus__init(message_memory);
}

void zrobot_interfaces__msg__DetectionStatus__rosidl_typesupport_introspection_c__DetectionStatus_fini_function(void * message_memory)
{
  zrobot_interfaces__msg__DetectionStatus__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember zrobot_interfaces__msg__DetectionStatus__rosidl_typesupport_introspection_c__DetectionStatus_message_member_array[10] = {
  {
    "target_object",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zrobot_interfaces__msg__DetectionStatus, target_object),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_found",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zrobot_interfaces__msg__DetectionStatus, target_found),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "zone",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zrobot_interfaces__msg__DetectionStatus, zone),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zrobot_interfaces__msg__DetectionStatus, target_count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zrobot_interfaces__msg__DetectionStatus, confidence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "inference_time_ms",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zrobot_interfaces__msg__DetectionStatus, inference_time_ms),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "fps",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zrobot_interfaces__msg__DetectionStatus, fps),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "frame_width",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zrobot_interfaces__msg__DetectionStatus, frame_width),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "frame_height",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zrobot_interfaces__msg__DetectionStatus, frame_height),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_center_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zrobot_interfaces__msg__DetectionStatus, target_center_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers zrobot_interfaces__msg__DetectionStatus__rosidl_typesupport_introspection_c__DetectionStatus_message_members = {
  "zrobot_interfaces__msg",  // message namespace
  "DetectionStatus",  // message name
  10,  // number of fields
  sizeof(zrobot_interfaces__msg__DetectionStatus),
  false,  // has_any_key_member_
  zrobot_interfaces__msg__DetectionStatus__rosidl_typesupport_introspection_c__DetectionStatus_message_member_array,  // message members
  zrobot_interfaces__msg__DetectionStatus__rosidl_typesupport_introspection_c__DetectionStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  zrobot_interfaces__msg__DetectionStatus__rosidl_typesupport_introspection_c__DetectionStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t zrobot_interfaces__msg__DetectionStatus__rosidl_typesupport_introspection_c__DetectionStatus_message_type_support_handle = {
  0,
  &zrobot_interfaces__msg__DetectionStatus__rosidl_typesupport_introspection_c__DetectionStatus_message_members,
  get_message_typesupport_handle_function,
  &zrobot_interfaces__msg__DetectionStatus__get_type_hash,
  &zrobot_interfaces__msg__DetectionStatus__get_type_description,
  &zrobot_interfaces__msg__DetectionStatus__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zrobot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zrobot_interfaces, msg, DetectionStatus)() {
  if (!zrobot_interfaces__msg__DetectionStatus__rosidl_typesupport_introspection_c__DetectionStatus_message_type_support_handle.typesupport_identifier) {
    zrobot_interfaces__msg__DetectionStatus__rosidl_typesupport_introspection_c__DetectionStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &zrobot_interfaces__msg__DetectionStatus__rosidl_typesupport_introspection_c__DetectionStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
