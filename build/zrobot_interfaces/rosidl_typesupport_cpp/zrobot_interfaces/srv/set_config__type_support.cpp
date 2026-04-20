// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from zrobot_interfaces:srv/SetConfig.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "zrobot_interfaces/srv/detail/set_config__functions.h"
#include "zrobot_interfaces/srv/detail/set_config__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace zrobot_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetConfig_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetConfig_Request_type_support_ids_t;

static const _SetConfig_Request_type_support_ids_t _SetConfig_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetConfig_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetConfig_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetConfig_Request_type_support_symbol_names_t _SetConfig_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, zrobot_interfaces, srv, SetConfig_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, zrobot_interfaces, srv, SetConfig_Request)),
  }
};

typedef struct _SetConfig_Request_type_support_data_t
{
  void * data[2];
} _SetConfig_Request_type_support_data_t;

static _SetConfig_Request_type_support_data_t _SetConfig_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetConfig_Request_message_typesupport_map = {
  2,
  "zrobot_interfaces",
  &_SetConfig_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SetConfig_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SetConfig_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetConfig_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetConfig_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &zrobot_interfaces__srv__SetConfig_Request__get_type_hash,
  &zrobot_interfaces__srv__SetConfig_Request__get_type_description,
  &zrobot_interfaces__srv__SetConfig_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace zrobot_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<zrobot_interfaces::srv::SetConfig_Request>()
{
  return &::zrobot_interfaces::srv::rosidl_typesupport_cpp::SetConfig_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, zrobot_interfaces, srv, SetConfig_Request)() {
  return get_message_type_support_handle<zrobot_interfaces::srv::SetConfig_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "zrobot_interfaces/srv/detail/set_config__functions.h"
// already included above
// #include "zrobot_interfaces/srv/detail/set_config__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace zrobot_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetConfig_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetConfig_Response_type_support_ids_t;

static const _SetConfig_Response_type_support_ids_t _SetConfig_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetConfig_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetConfig_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetConfig_Response_type_support_symbol_names_t _SetConfig_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, zrobot_interfaces, srv, SetConfig_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, zrobot_interfaces, srv, SetConfig_Response)),
  }
};

typedef struct _SetConfig_Response_type_support_data_t
{
  void * data[2];
} _SetConfig_Response_type_support_data_t;

static _SetConfig_Response_type_support_data_t _SetConfig_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetConfig_Response_message_typesupport_map = {
  2,
  "zrobot_interfaces",
  &_SetConfig_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SetConfig_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SetConfig_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetConfig_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetConfig_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &zrobot_interfaces__srv__SetConfig_Response__get_type_hash,
  &zrobot_interfaces__srv__SetConfig_Response__get_type_description,
  &zrobot_interfaces__srv__SetConfig_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace zrobot_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<zrobot_interfaces::srv::SetConfig_Response>()
{
  return &::zrobot_interfaces::srv::rosidl_typesupport_cpp::SetConfig_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, zrobot_interfaces, srv, SetConfig_Response)() {
  return get_message_type_support_handle<zrobot_interfaces::srv::SetConfig_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "zrobot_interfaces/srv/detail/set_config__functions.h"
// already included above
// #include "zrobot_interfaces/srv/detail/set_config__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace zrobot_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetConfig_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetConfig_Event_type_support_ids_t;

static const _SetConfig_Event_type_support_ids_t _SetConfig_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetConfig_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetConfig_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetConfig_Event_type_support_symbol_names_t _SetConfig_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, zrobot_interfaces, srv, SetConfig_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, zrobot_interfaces, srv, SetConfig_Event)),
  }
};

typedef struct _SetConfig_Event_type_support_data_t
{
  void * data[2];
} _SetConfig_Event_type_support_data_t;

static _SetConfig_Event_type_support_data_t _SetConfig_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetConfig_Event_message_typesupport_map = {
  2,
  "zrobot_interfaces",
  &_SetConfig_Event_message_typesupport_ids.typesupport_identifier[0],
  &_SetConfig_Event_message_typesupport_symbol_names.symbol_name[0],
  &_SetConfig_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetConfig_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetConfig_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &zrobot_interfaces__srv__SetConfig_Event__get_type_hash,
  &zrobot_interfaces__srv__SetConfig_Event__get_type_description,
  &zrobot_interfaces__srv__SetConfig_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace zrobot_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<zrobot_interfaces::srv::SetConfig_Event>()
{
  return &::zrobot_interfaces::srv::rosidl_typesupport_cpp::SetConfig_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, zrobot_interfaces, srv, SetConfig_Event)() {
  return get_message_type_support_handle<zrobot_interfaces::srv::SetConfig_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "zrobot_interfaces/srv/detail/set_config__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace zrobot_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetConfig_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetConfig_type_support_ids_t;

static const _SetConfig_type_support_ids_t _SetConfig_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetConfig_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetConfig_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetConfig_type_support_symbol_names_t _SetConfig_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, zrobot_interfaces, srv, SetConfig)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, zrobot_interfaces, srv, SetConfig)),
  }
};

typedef struct _SetConfig_type_support_data_t
{
  void * data[2];
} _SetConfig_type_support_data_t;

static _SetConfig_type_support_data_t _SetConfig_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetConfig_service_typesupport_map = {
  2,
  "zrobot_interfaces",
  &_SetConfig_service_typesupport_ids.typesupport_identifier[0],
  &_SetConfig_service_typesupport_symbol_names.symbol_name[0],
  &_SetConfig_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SetConfig_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetConfig_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<zrobot_interfaces::srv::SetConfig_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<zrobot_interfaces::srv::SetConfig_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<zrobot_interfaces::srv::SetConfig_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<zrobot_interfaces::srv::SetConfig>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<zrobot_interfaces::srv::SetConfig>,
  &zrobot_interfaces__srv__SetConfig__get_type_hash,
  &zrobot_interfaces__srv__SetConfig__get_type_description,
  &zrobot_interfaces__srv__SetConfig__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace zrobot_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<zrobot_interfaces::srv::SetConfig>()
{
  return &::zrobot_interfaces::srv::rosidl_typesupport_cpp::SetConfig_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, zrobot_interfaces, srv, SetConfig)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<zrobot_interfaces::srv::SetConfig>();
}

#ifdef __cplusplus
}
#endif
