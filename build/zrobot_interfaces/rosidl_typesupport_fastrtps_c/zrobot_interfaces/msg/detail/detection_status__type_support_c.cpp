// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from zrobot_interfaces:msg/DetectionStatus.idl
// generated code does not contain a copyright notice
#include "zrobot_interfaces/msg/detail/detection_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "zrobot_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "zrobot_interfaces/msg/detail/detection_status__struct.h"
#include "zrobot_interfaces/msg/detail/detection_status__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // target_object, zone
#include "rosidl_runtime_c/string_functions.h"  // target_object, zone

// forward declare type support functions


using _DetectionStatus__ros_msg_type = zrobot_interfaces__msg__DetectionStatus;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zrobot_interfaces
bool cdr_serialize_zrobot_interfaces__msg__DetectionStatus(
  const zrobot_interfaces__msg__DetectionStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: target_object
  {
    const rosidl_runtime_c__String * str = &ros_message->target_object;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: target_found
  {
    cdr << (ros_message->target_found ? true : false);
  }

  // Field name: zone
  {
    const rosidl_runtime_c__String * str = &ros_message->zone;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: target_count
  {
    cdr << ros_message->target_count;
  }

  // Field name: confidence
  {
    cdr << ros_message->confidence;
  }

  // Field name: inference_time_ms
  {
    cdr << ros_message->inference_time_ms;
  }

  // Field name: fps
  {
    cdr << ros_message->fps;
  }

  // Field name: frame_width
  {
    cdr << ros_message->frame_width;
  }

  // Field name: frame_height
  {
    cdr << ros_message->frame_height;
  }

  // Field name: target_center_x
  {
    cdr << ros_message->target_center_x;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zrobot_interfaces
bool cdr_deserialize_zrobot_interfaces__msg__DetectionStatus(
  eprosima::fastcdr::Cdr & cdr,
  zrobot_interfaces__msg__DetectionStatus * ros_message)
{
  // Field name: target_object
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->target_object.data) {
      rosidl_runtime_c__String__init(&ros_message->target_object);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->target_object,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'target_object'\n");
      return false;
    }
  }

  // Field name: target_found
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->target_found = tmp ? true : false;
  }

  // Field name: zone
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->zone.data) {
      rosidl_runtime_c__String__init(&ros_message->zone);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->zone,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'zone'\n");
      return false;
    }
  }

  // Field name: target_count
  {
    cdr >> ros_message->target_count;
  }

  // Field name: confidence
  {
    cdr >> ros_message->confidence;
  }

  // Field name: inference_time_ms
  {
    cdr >> ros_message->inference_time_ms;
  }

  // Field name: fps
  {
    cdr >> ros_message->fps;
  }

  // Field name: frame_width
  {
    cdr >> ros_message->frame_width;
  }

  // Field name: frame_height
  {
    cdr >> ros_message->frame_height;
  }

  // Field name: target_center_x
  {
    cdr >> ros_message->target_center_x;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zrobot_interfaces
size_t get_serialized_size_zrobot_interfaces__msg__DetectionStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DetectionStatus__ros_msg_type * ros_message = static_cast<const _DetectionStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: target_object
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->target_object.size + 1);

  // Field name: target_found
  {
    size_t item_size = sizeof(ros_message->target_found);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: zone
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->zone.size + 1);

  // Field name: target_count
  {
    size_t item_size = sizeof(ros_message->target_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: confidence
  {
    size_t item_size = sizeof(ros_message->confidence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: inference_time_ms
  {
    size_t item_size = sizeof(ros_message->inference_time_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: fps
  {
    size_t item_size = sizeof(ros_message->fps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: frame_width
  {
    size_t item_size = sizeof(ros_message->frame_width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: frame_height
  {
    size_t item_size = sizeof(ros_message->frame_height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: target_center_x
  {
    size_t item_size = sizeof(ros_message->target_center_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zrobot_interfaces
size_t max_serialized_size_zrobot_interfaces__msg__DetectionStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: target_object
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: target_found
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: zone
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: target_count
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: confidence
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: inference_time_ms
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: fps
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: frame_width
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: frame_height
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: target_center_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = zrobot_interfaces__msg__DetectionStatus;
    is_plain =
      (
      offsetof(DataType, target_center_x) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zrobot_interfaces
bool cdr_serialize_key_zrobot_interfaces__msg__DetectionStatus(
  const zrobot_interfaces__msg__DetectionStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: target_object
  {
    const rosidl_runtime_c__String * str = &ros_message->target_object;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: target_found
  {
    cdr << (ros_message->target_found ? true : false);
  }

  // Field name: zone
  {
    const rosidl_runtime_c__String * str = &ros_message->zone;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: target_count
  {
    cdr << ros_message->target_count;
  }

  // Field name: confidence
  {
    cdr << ros_message->confidence;
  }

  // Field name: inference_time_ms
  {
    cdr << ros_message->inference_time_ms;
  }

  // Field name: fps
  {
    cdr << ros_message->fps;
  }

  // Field name: frame_width
  {
    cdr << ros_message->frame_width;
  }

  // Field name: frame_height
  {
    cdr << ros_message->frame_height;
  }

  // Field name: target_center_x
  {
    cdr << ros_message->target_center_x;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zrobot_interfaces
size_t get_serialized_size_key_zrobot_interfaces__msg__DetectionStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DetectionStatus__ros_msg_type * ros_message = static_cast<const _DetectionStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: target_object
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->target_object.size + 1);

  // Field name: target_found
  {
    size_t item_size = sizeof(ros_message->target_found);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: zone
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->zone.size + 1);

  // Field name: target_count
  {
    size_t item_size = sizeof(ros_message->target_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: confidence
  {
    size_t item_size = sizeof(ros_message->confidence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: inference_time_ms
  {
    size_t item_size = sizeof(ros_message->inference_time_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: fps
  {
    size_t item_size = sizeof(ros_message->fps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: frame_width
  {
    size_t item_size = sizeof(ros_message->frame_width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: frame_height
  {
    size_t item_size = sizeof(ros_message->frame_height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: target_center_x
  {
    size_t item_size = sizeof(ros_message->target_center_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zrobot_interfaces
size_t max_serialized_size_key_zrobot_interfaces__msg__DetectionStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: target_object
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: target_found
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: zone
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: target_count
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: confidence
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: inference_time_ms
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: fps
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: frame_width
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: frame_height
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: target_center_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = zrobot_interfaces__msg__DetectionStatus;
    is_plain =
      (
      offsetof(DataType, target_center_x) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _DetectionStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const zrobot_interfaces__msg__DetectionStatus * ros_message = static_cast<const zrobot_interfaces__msg__DetectionStatus *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_zrobot_interfaces__msg__DetectionStatus(ros_message, cdr);
}

static bool _DetectionStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  zrobot_interfaces__msg__DetectionStatus * ros_message = static_cast<zrobot_interfaces__msg__DetectionStatus *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_zrobot_interfaces__msg__DetectionStatus(cdr, ros_message);
}

static uint32_t _DetectionStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_zrobot_interfaces__msg__DetectionStatus(
      untyped_ros_message, 0));
}

static size_t _DetectionStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_zrobot_interfaces__msg__DetectionStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_DetectionStatus = {
  "zrobot_interfaces::msg",
  "DetectionStatus",
  _DetectionStatus__cdr_serialize,
  _DetectionStatus__cdr_deserialize,
  _DetectionStatus__get_serialized_size,
  _DetectionStatus__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _DetectionStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_DetectionStatus,
  get_message_typesupport_handle_function,
  &zrobot_interfaces__msg__DetectionStatus__get_type_hash,
  &zrobot_interfaces__msg__DetectionStatus__get_type_description,
  &zrobot_interfaces__msg__DetectionStatus__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, zrobot_interfaces, msg, DetectionStatus)() {
  return &_DetectionStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
