// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from zrobot_interfaces:srv/SetTarget.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "zrobot_interfaces/srv/detail/set_target__functions.h"
#include "zrobot_interfaces/srv/detail/set_target__struct.hpp"
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

typedef struct _SetTarget_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetTarget_Request_type_support_ids_t;

static const _SetTarget_Request_type_support_ids_t _SetTarget_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetTarget_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetTarget_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetTarget_Request_type_support_symbol_names_t _SetTarget_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, zrobot_interfaces, srv, SetTarget_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, zrobot_interfaces, srv, SetTarget_Request)),
  }
};

typedef struct _SetTarget_Request_type_support_data_t
{
  void * data[2];
} _SetTarget_Request_type_support_data_t;

static _SetTarget_Request_type_support_data_t _SetTarget_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetTarget_Request_message_typesupport_map = {
  2,
  "zrobot_interfaces",
  &_SetTarget_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SetTarget_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SetTarget_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetTarget_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetTarget_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &zrobot_interfaces__srv__SetTarget_Request__get_type_hash,
  &zrobot_interfaces__srv__SetTarget_Request__get_type_description,
  &zrobot_interfaces__srv__SetTarget_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace zrobot_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<zrobot_interfaces::srv::SetTarget_Request>()
{
  return &::zrobot_interfaces::srv::rosidl_typesupport_cpp::SetTarget_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, zrobot_interfaces, srv, SetTarget_Request)() {
  return get_message_type_support_handle<zrobot_interfaces::srv::SetTarget_Request>();
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
// #include "zrobot_interfaces/srv/detail/set_target__functions.h"
// already included above
// #include "zrobot_interfaces/srv/detail/set_target__struct.hpp"
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

typedef struct _SetTarget_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetTarget_Response_type_support_ids_t;

static const _SetTarget_Response_type_support_ids_t _SetTarget_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetTarget_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetTarget_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetTarget_Response_type_support_symbol_names_t _SetTarget_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, zrobot_interfaces, srv, SetTarget_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, zrobot_interfaces, srv, SetTarget_Response)),
  }
};

typedef struct _SetTarget_Response_type_support_data_t
{
  void * data[2];
} _SetTarget_Response_type_support_data_t;

static _SetTarget_Response_type_support_data_t _SetTarget_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetTarget_Response_message_typesupport_map = {
  2,
  "zrobot_interfaces",
  &_SetTarget_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SetTarget_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SetTarget_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetTarget_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetTarget_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &zrobot_interfaces__srv__SetTarget_Response__get_type_hash,
  &zrobot_interfaces__srv__SetTarget_Response__get_type_description,
  &zrobot_interfaces__srv__SetTarget_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace zrobot_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<zrobot_interfaces::srv::SetTarget_Response>()
{
  return &::zrobot_interfaces::srv::rosidl_typesupport_cpp::SetTarget_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, zrobot_interfaces, srv, SetTarget_Response)() {
  return get_message_type_support_handle<zrobot_interfaces::srv::SetTarget_Response>();
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
// #include "zrobot_interfaces/srv/detail/set_target__functions.h"
// already included above
// #include "zrobot_interfaces/srv/detail/set_target__struct.hpp"
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

typedef struct _SetTarget_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetTarget_Event_type_support_ids_t;

static const _SetTarget_Event_type_support_ids_t _SetTarget_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetTarget_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetTarget_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetTarget_Event_type_support_symbol_names_t _SetTarget_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, zrobot_interfaces, srv, SetTarget_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, zrobot_interfaces, srv, SetTarget_Event)),
  }
};

typedef struct _SetTarget_Event_type_support_data_t
{
  void * data[2];
} _SetTarget_Event_type_support_data_t;

static _SetTarget_Event_type_support_data_t _SetTarget_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetTarget_Event_message_typesupport_map = {
  2,
  "zrobot_interfaces",
  &_SetTarget_Event_message_typesupport_ids.typesupport_identifier[0],
  &_SetTarget_Event_message_typesupport_symbol_names.symbol_name[0],
  &_SetTarget_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetTarget_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetTarget_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &zrobot_interfaces__srv__SetTarget_Event__get_type_hash,
  &zrobot_interfaces__srv__SetTarget_Event__get_type_description,
  &zrobot_interfaces__srv__SetTarget_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace zrobot_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<zrobot_interfaces::srv::SetTarget_Event>()
{
  return &::zrobot_interfaces::srv::rosidl_typesupport_cpp::SetTarget_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, zrobot_interfaces, srv, SetTarget_Event)() {
  return get_message_type_support_handle<zrobot_interfaces::srv::SetTarget_Event>();
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
// #include "zrobot_interfaces/srv/detail/set_target__struct.hpp"
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

typedef struct _SetTarget_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetTarget_type_support_ids_t;

static const _SetTarget_type_support_ids_t _SetTarget_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetTarget_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetTarget_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetTarget_type_support_symbol_names_t _SetTarget_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, zrobot_interfaces, srv, SetTarget)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, zrobot_interfaces, srv, SetTarget)),
  }
};

typedef struct _SetTarget_type_support_data_t
{
  void * data[2];
} _SetTarget_type_support_data_t;

static _SetTarget_type_support_data_t _SetTarget_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetTarget_service_typesupport_map = {
  2,
  "zrobot_interfaces",
  &_SetTarget_service_typesupport_ids.typesupport_identifier[0],
  &_SetTarget_service_typesupport_symbol_names.symbol_name[0],
  &_SetTarget_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SetTarget_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetTarget_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<zrobot_interfaces::srv::SetTarget_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<zrobot_interfaces::srv::SetTarget_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<zrobot_interfaces::srv::SetTarget_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<zrobot_interfaces::srv::SetTarget>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<zrobot_interfaces::srv::SetTarget>,
  &zrobot_interfaces__srv__SetTarget__get_type_hash,
  &zrobot_interfaces__srv__SetTarget__get_type_description,
  &zrobot_interfaces__srv__SetTarget__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace zrobot_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<zrobot_interfaces::srv::SetTarget>()
{
  return &::zrobot_interfaces::srv::rosidl_typesupport_cpp::SetTarget_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, zrobot_interfaces, srv, SetTarget)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<zrobot_interfaces::srv::SetTarget>();
}

#ifdef __cplusplus
}
#endif
