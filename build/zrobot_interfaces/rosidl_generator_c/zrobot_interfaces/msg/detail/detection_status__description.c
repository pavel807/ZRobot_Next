// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from zrobot_interfaces:msg/DetectionStatus.idl
// generated code does not contain a copyright notice

#include "zrobot_interfaces/msg/detail/detection_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_zrobot_interfaces
const rosidl_type_hash_t *
zrobot_interfaces__msg__DetectionStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x65, 0x26, 0x7e, 0x05, 0x16, 0xfb, 0x87, 0x9d,
      0x96, 0xd3, 0xf1, 0xa8, 0xec, 0x09, 0x54, 0x0e,
      0x2f, 0xc2, 0xa2, 0x0e, 0xdf, 0x06, 0xa3, 0x32,
      0x92, 0xd1, 0x7b, 0x56, 0x94, 0x19, 0x98, 0xa5,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char zrobot_interfaces__msg__DetectionStatus__TYPE_NAME[] = "zrobot_interfaces/msg/DetectionStatus";

// Define type names, field names, and default values
static char zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__target_object[] = "target_object";
static char zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__target_found[] = "target_found";
static char zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__zone[] = "zone";
static char zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__target_count[] = "target_count";
static char zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__confidence[] = "confidence";
static char zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__inference_time_ms[] = "inference_time_ms";
static char zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__fps[] = "fps";
static char zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__frame_width[] = "frame_width";
static char zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__frame_height[] = "frame_height";
static char zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__target_center_x[] = "target_center_x";

static rosidl_runtime_c__type_description__Field zrobot_interfaces__msg__DetectionStatus__FIELDS[] = {
  {
    {zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__target_object, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__target_found, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__zone, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__target_count, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__confidence, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__inference_time_ms, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__fps, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__frame_width, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__frame_height, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__msg__DetectionStatus__FIELD_NAME__target_center_x, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
zrobot_interfaces__msg__DetectionStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zrobot_interfaces__msg__DetectionStatus__TYPE_NAME, 37, 37},
      {zrobot_interfaces__msg__DetectionStatus__FIELDS, 10, 10},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Detection status message\n"
  "# Published by yolo_detector_node\n"
  "\n"
  "string target_object          # Target object class name\n"
  "bool target_found             # True if target is detected\n"
  "string zone                   # \"LEFT\", \"CENTER\", \"RIGHT\", \"NONE\"\n"
  "int32 target_count            # Number of detected targets\n"
  "float32 confidence            # Confidence threshold\n"
  "float32 inference_time_ms     # Inference time in milliseconds\n"
  "int32 fps                     # Current FPS\n"
  "int32 frame_width             # Frame width\n"
  "int32 frame_height            # Frame height\n"
  "float32 target_center_x       # X coordinate of target center";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
zrobot_interfaces__msg__DetectionStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zrobot_interfaces__msg__DetectionStatus__TYPE_NAME, 37, 37},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 614, 614},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zrobot_interfaces__msg__DetectionStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zrobot_interfaces__msg__DetectionStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
