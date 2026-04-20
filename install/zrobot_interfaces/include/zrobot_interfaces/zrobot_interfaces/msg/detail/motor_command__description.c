// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from zrobot_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice

#include "zrobot_interfaces/msg/detail/motor_command__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_zrobot_interfaces
const rosidl_type_hash_t *
zrobot_interfaces__msg__MotorCommand__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x37, 0xf6, 0x1f, 0xd4, 0xa8, 0xf3, 0x3f, 0xd7,
      0x2e, 0x46, 0xdd, 0x52, 0xa3, 0x51, 0x25, 0xe7,
      0x57, 0x14, 0x31, 0x17, 0xbd, 0x44, 0x07, 0x6d,
      0x45, 0x7f, 0x1f, 0x6f, 0xd5, 0x45, 0xd0, 0x77,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char zrobot_interfaces__msg__MotorCommand__TYPE_NAME[] = "zrobot_interfaces/msg/MotorCommand";

// Define type names, field names, and default values
static char zrobot_interfaces__msg__MotorCommand__FIELD_NAME__left_speed[] = "left_speed";
static char zrobot_interfaces__msg__MotorCommand__FIELD_NAME__right_speed[] = "right_speed";
static char zrobot_interfaces__msg__MotorCommand__FIELD_NAME__motors_running[] = "motors_running";
static char zrobot_interfaces__msg__MotorCommand__FIELD_NAME__mode[] = "mode";

static rosidl_runtime_c__type_description__Field zrobot_interfaces__msg__MotorCommand__FIELDS[] = {
  {
    {zrobot_interfaces__msg__MotorCommand__FIELD_NAME__left_speed, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__msg__MotorCommand__FIELD_NAME__right_speed, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__msg__MotorCommand__FIELD_NAME__motors_running, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__msg__MotorCommand__FIELD_NAME__mode, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
zrobot_interfaces__msg__MotorCommand__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zrobot_interfaces__msg__MotorCommand__TYPE_NAME, 34, 34},
      {zrobot_interfaces__msg__MotorCommand__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Motor command message\n"
  "# Published by object_tracker, consumed by motor_controller\n"
  "\n"
  "int32 left_speed              # Left motor speed (0-255)\n"
  "int32 right_speed             # Right motor speed (0-255)\n"
  "bool motors_running           # True if motors are active\n"
  "string mode                   # \"TRACKING\", \"SEARCHING\", \"STOPPED\"";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
zrobot_interfaces__msg__MotorCommand__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zrobot_interfaces__msg__MotorCommand__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 325, 325},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zrobot_interfaces__msg__MotorCommand__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zrobot_interfaces__msg__MotorCommand__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
