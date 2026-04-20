// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from zrobot_interfaces:srv/SetConfig.idl
// generated code does not contain a copyright notice

#include "zrobot_interfaces/srv/detail/set_config__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_zrobot_interfaces
const rosidl_type_hash_t *
zrobot_interfaces__srv__SetConfig__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb9, 0x26, 0x68, 0x48, 0xcf, 0x35, 0x90, 0x41,
      0xf2, 0x56, 0x18, 0x37, 0xed, 0x13, 0x24, 0x63,
      0xb7, 0x06, 0x0f, 0x2c, 0x84, 0xa6, 0xd9, 0x6b,
      0x37, 0x3c, 0x9c, 0x33, 0x38, 0x21, 0xc4, 0x80,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_zrobot_interfaces
const rosidl_type_hash_t *
zrobot_interfaces__srv__SetConfig_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xab, 0xc8, 0xf6, 0x2e, 0xcf, 0xc5, 0x17, 0x65,
      0x4b, 0x8e, 0x03, 0x89, 0x32, 0xcc, 0xac, 0xc4,
      0x7d, 0xd9, 0xcf, 0xec, 0xf9, 0x79, 0x21, 0xb6,
      0x86, 0xa6, 0xb7, 0xef, 0x80, 0x7e, 0x43, 0x73,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_zrobot_interfaces
const rosidl_type_hash_t *
zrobot_interfaces__srv__SetConfig_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc1, 0x70, 0xb5, 0x15, 0x60, 0xee, 0x1a, 0x54,
      0x74, 0x89, 0x09, 0xd5, 0x70, 0xed, 0xce, 0x14,
      0xea, 0x29, 0x30, 0x47, 0x6a, 0x01, 0xb2, 0x83,
      0x92, 0xd6, 0x68, 0x91, 0x44, 0xaf, 0xbb, 0xce,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_zrobot_interfaces
const rosidl_type_hash_t *
zrobot_interfaces__srv__SetConfig_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x96, 0x11, 0x11, 0xb3, 0xd8, 0x4e, 0x55, 0xf2,
      0x23, 0x35, 0xfe, 0x90, 0xdf, 0xa0, 0xbc, 0xde,
      0x3c, 0x94, 0x13, 0xa0, 0x6f, 0xe0, 0x03, 0x12,
      0xc6, 0x44, 0xa9, 0xb8, 0xc4, 0x88, 0x4f, 0x32,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char zrobot_interfaces__srv__SetConfig__TYPE_NAME[] = "zrobot_interfaces/srv/SetConfig";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char zrobot_interfaces__srv__SetConfig_Event__TYPE_NAME[] = "zrobot_interfaces/srv/SetConfig_Event";
static char zrobot_interfaces__srv__SetConfig_Request__TYPE_NAME[] = "zrobot_interfaces/srv/SetConfig_Request";
static char zrobot_interfaces__srv__SetConfig_Response__TYPE_NAME[] = "zrobot_interfaces/srv/SetConfig_Response";

// Define type names, field names, and default values
static char zrobot_interfaces__srv__SetConfig__FIELD_NAME__request_message[] = "request_message";
static char zrobot_interfaces__srv__SetConfig__FIELD_NAME__response_message[] = "response_message";
static char zrobot_interfaces__srv__SetConfig__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field zrobot_interfaces__srv__SetConfig__FIELDS[] = {
  {
    {zrobot_interfaces__srv__SetConfig__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {zrobot_interfaces__srv__SetConfig_Request__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__srv__SetConfig__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {zrobot_interfaces__srv__SetConfig_Response__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__srv__SetConfig__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {zrobot_interfaces__srv__SetConfig_Event__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription zrobot_interfaces__srv__SetConfig__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__srv__SetConfig_Event__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__srv__SetConfig_Request__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__srv__SetConfig_Response__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
zrobot_interfaces__srv__SetConfig__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zrobot_interfaces__srv__SetConfig__TYPE_NAME, 31, 31},
      {zrobot_interfaces__srv__SetConfig__FIELDS, 3, 3},
    },
    {zrobot_interfaces__srv__SetConfig__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = zrobot_interfaces__srv__SetConfig_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = zrobot_interfaces__srv__SetConfig_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = zrobot_interfaces__srv__SetConfig_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char zrobot_interfaces__srv__SetConfig_Request__FIELD_NAME__parameter_name[] = "parameter_name";
static char zrobot_interfaces__srv__SetConfig_Request__FIELD_NAME__value[] = "value";

static rosidl_runtime_c__type_description__Field zrobot_interfaces__srv__SetConfig_Request__FIELDS[] = {
  {
    {zrobot_interfaces__srv__SetConfig_Request__FIELD_NAME__parameter_name, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__srv__SetConfig_Request__FIELD_NAME__value, 5, 5},
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
zrobot_interfaces__srv__SetConfig_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zrobot_interfaces__srv__SetConfig_Request__TYPE_NAME, 39, 39},
      {zrobot_interfaces__srv__SetConfig_Request__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char zrobot_interfaces__srv__SetConfig_Response__FIELD_NAME__success[] = "success";
static char zrobot_interfaces__srv__SetConfig_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field zrobot_interfaces__srv__SetConfig_Response__FIELDS[] = {
  {
    {zrobot_interfaces__srv__SetConfig_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__srv__SetConfig_Response__FIELD_NAME__message, 7, 7},
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
zrobot_interfaces__srv__SetConfig_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zrobot_interfaces__srv__SetConfig_Response__TYPE_NAME, 40, 40},
      {zrobot_interfaces__srv__SetConfig_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char zrobot_interfaces__srv__SetConfig_Event__FIELD_NAME__info[] = "info";
static char zrobot_interfaces__srv__SetConfig_Event__FIELD_NAME__request[] = "request";
static char zrobot_interfaces__srv__SetConfig_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field zrobot_interfaces__srv__SetConfig_Event__FIELDS[] = {
  {
    {zrobot_interfaces__srv__SetConfig_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__srv__SetConfig_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {zrobot_interfaces__srv__SetConfig_Request__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__srv__SetConfig_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {zrobot_interfaces__srv__SetConfig_Response__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription zrobot_interfaces__srv__SetConfig_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__srv__SetConfig_Request__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {zrobot_interfaces__srv__SetConfig_Response__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
zrobot_interfaces__srv__SetConfig_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {zrobot_interfaces__srv__SetConfig_Event__TYPE_NAME, 37, 37},
      {zrobot_interfaces__srv__SetConfig_Event__FIELDS, 3, 3},
    },
    {zrobot_interfaces__srv__SetConfig_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = zrobot_interfaces__srv__SetConfig_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = zrobot_interfaces__srv__SetConfig_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Set configuration parameters service\n"
  "string parameter_name         # Parameter to change (e.g., \"confidence\", \"max_speed\")\n"
  "float32 value                 # New value\n"
  "---\n"
  "bool success                  # True if parameter was set successfully\n"
  "string message                # Status message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
zrobot_interfaces__srv__SetConfig__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zrobot_interfaces__srv__SetConfig__TYPE_NAME, 31, 31},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 289, 289},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
zrobot_interfaces__srv__SetConfig_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zrobot_interfaces__srv__SetConfig_Request__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
zrobot_interfaces__srv__SetConfig_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zrobot_interfaces__srv__SetConfig_Response__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
zrobot_interfaces__srv__SetConfig_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {zrobot_interfaces__srv__SetConfig_Event__TYPE_NAME, 37, 37},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zrobot_interfaces__srv__SetConfig__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zrobot_interfaces__srv__SetConfig__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *zrobot_interfaces__srv__SetConfig_Event__get_individual_type_description_source(NULL);
    sources[4] = *zrobot_interfaces__srv__SetConfig_Request__get_individual_type_description_source(NULL);
    sources[5] = *zrobot_interfaces__srv__SetConfig_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zrobot_interfaces__srv__SetConfig_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zrobot_interfaces__srv__SetConfig_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zrobot_interfaces__srv__SetConfig_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zrobot_interfaces__srv__SetConfig_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
zrobot_interfaces__srv__SetConfig_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *zrobot_interfaces__srv__SetConfig_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *zrobot_interfaces__srv__SetConfig_Request__get_individual_type_description_source(NULL);
    sources[4] = *zrobot_interfaces__srv__SetConfig_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
