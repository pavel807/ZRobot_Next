// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from zrobot_interfaces:srv/SetConfig.idl
// generated code does not contain a copyright notice
#include "zrobot_interfaces/srv/detail/set_config__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `parameter_name`
#include "rosidl_runtime_c/string_functions.h"

bool
zrobot_interfaces__srv__SetConfig_Request__init(zrobot_interfaces__srv__SetConfig_Request * msg)
{
  if (!msg) {
    return false;
  }
  // parameter_name
  if (!rosidl_runtime_c__String__init(&msg->parameter_name)) {
    zrobot_interfaces__srv__SetConfig_Request__fini(msg);
    return false;
  }
  // value
  return true;
}

void
zrobot_interfaces__srv__SetConfig_Request__fini(zrobot_interfaces__srv__SetConfig_Request * msg)
{
  if (!msg) {
    return;
  }
  // parameter_name
  rosidl_runtime_c__String__fini(&msg->parameter_name);
  // value
}

bool
zrobot_interfaces__srv__SetConfig_Request__are_equal(const zrobot_interfaces__srv__SetConfig_Request * lhs, const zrobot_interfaces__srv__SetConfig_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // parameter_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->parameter_name), &(rhs->parameter_name)))
  {
    return false;
  }
  // value
  if (lhs->value != rhs->value) {
    return false;
  }
  return true;
}

bool
zrobot_interfaces__srv__SetConfig_Request__copy(
  const zrobot_interfaces__srv__SetConfig_Request * input,
  zrobot_interfaces__srv__SetConfig_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // parameter_name
  if (!rosidl_runtime_c__String__copy(
      &(input->parameter_name), &(output->parameter_name)))
  {
    return false;
  }
  // value
  output->value = input->value;
  return true;
}

zrobot_interfaces__srv__SetConfig_Request *
zrobot_interfaces__srv__SetConfig_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zrobot_interfaces__srv__SetConfig_Request * msg = (zrobot_interfaces__srv__SetConfig_Request *)allocator.allocate(sizeof(zrobot_interfaces__srv__SetConfig_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(zrobot_interfaces__srv__SetConfig_Request));
  bool success = zrobot_interfaces__srv__SetConfig_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
zrobot_interfaces__srv__SetConfig_Request__destroy(zrobot_interfaces__srv__SetConfig_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    zrobot_interfaces__srv__SetConfig_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
zrobot_interfaces__srv__SetConfig_Request__Sequence__init(zrobot_interfaces__srv__SetConfig_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zrobot_interfaces__srv__SetConfig_Request * data = NULL;

  if (size) {
    data = (zrobot_interfaces__srv__SetConfig_Request *)allocator.zero_allocate(size, sizeof(zrobot_interfaces__srv__SetConfig_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = zrobot_interfaces__srv__SetConfig_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        zrobot_interfaces__srv__SetConfig_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
zrobot_interfaces__srv__SetConfig_Request__Sequence__fini(zrobot_interfaces__srv__SetConfig_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      zrobot_interfaces__srv__SetConfig_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

zrobot_interfaces__srv__SetConfig_Request__Sequence *
zrobot_interfaces__srv__SetConfig_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zrobot_interfaces__srv__SetConfig_Request__Sequence * array = (zrobot_interfaces__srv__SetConfig_Request__Sequence *)allocator.allocate(sizeof(zrobot_interfaces__srv__SetConfig_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = zrobot_interfaces__srv__SetConfig_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
zrobot_interfaces__srv__SetConfig_Request__Sequence__destroy(zrobot_interfaces__srv__SetConfig_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    zrobot_interfaces__srv__SetConfig_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
zrobot_interfaces__srv__SetConfig_Request__Sequence__are_equal(const zrobot_interfaces__srv__SetConfig_Request__Sequence * lhs, const zrobot_interfaces__srv__SetConfig_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!zrobot_interfaces__srv__SetConfig_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
zrobot_interfaces__srv__SetConfig_Request__Sequence__copy(
  const zrobot_interfaces__srv__SetConfig_Request__Sequence * input,
  zrobot_interfaces__srv__SetConfig_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(zrobot_interfaces__srv__SetConfig_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    zrobot_interfaces__srv__SetConfig_Request * data =
      (zrobot_interfaces__srv__SetConfig_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!zrobot_interfaces__srv__SetConfig_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          zrobot_interfaces__srv__SetConfig_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!zrobot_interfaces__srv__SetConfig_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
zrobot_interfaces__srv__SetConfig_Response__init(zrobot_interfaces__srv__SetConfig_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    zrobot_interfaces__srv__SetConfig_Response__fini(msg);
    return false;
  }
  return true;
}

void
zrobot_interfaces__srv__SetConfig_Response__fini(zrobot_interfaces__srv__SetConfig_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
zrobot_interfaces__srv__SetConfig_Response__are_equal(const zrobot_interfaces__srv__SetConfig_Response * lhs, const zrobot_interfaces__srv__SetConfig_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
zrobot_interfaces__srv__SetConfig_Response__copy(
  const zrobot_interfaces__srv__SetConfig_Response * input,
  zrobot_interfaces__srv__SetConfig_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

zrobot_interfaces__srv__SetConfig_Response *
zrobot_interfaces__srv__SetConfig_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zrobot_interfaces__srv__SetConfig_Response * msg = (zrobot_interfaces__srv__SetConfig_Response *)allocator.allocate(sizeof(zrobot_interfaces__srv__SetConfig_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(zrobot_interfaces__srv__SetConfig_Response));
  bool success = zrobot_interfaces__srv__SetConfig_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
zrobot_interfaces__srv__SetConfig_Response__destroy(zrobot_interfaces__srv__SetConfig_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    zrobot_interfaces__srv__SetConfig_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
zrobot_interfaces__srv__SetConfig_Response__Sequence__init(zrobot_interfaces__srv__SetConfig_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zrobot_interfaces__srv__SetConfig_Response * data = NULL;

  if (size) {
    data = (zrobot_interfaces__srv__SetConfig_Response *)allocator.zero_allocate(size, sizeof(zrobot_interfaces__srv__SetConfig_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = zrobot_interfaces__srv__SetConfig_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        zrobot_interfaces__srv__SetConfig_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
zrobot_interfaces__srv__SetConfig_Response__Sequence__fini(zrobot_interfaces__srv__SetConfig_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      zrobot_interfaces__srv__SetConfig_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

zrobot_interfaces__srv__SetConfig_Response__Sequence *
zrobot_interfaces__srv__SetConfig_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zrobot_interfaces__srv__SetConfig_Response__Sequence * array = (zrobot_interfaces__srv__SetConfig_Response__Sequence *)allocator.allocate(sizeof(zrobot_interfaces__srv__SetConfig_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = zrobot_interfaces__srv__SetConfig_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
zrobot_interfaces__srv__SetConfig_Response__Sequence__destroy(zrobot_interfaces__srv__SetConfig_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    zrobot_interfaces__srv__SetConfig_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
zrobot_interfaces__srv__SetConfig_Response__Sequence__are_equal(const zrobot_interfaces__srv__SetConfig_Response__Sequence * lhs, const zrobot_interfaces__srv__SetConfig_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!zrobot_interfaces__srv__SetConfig_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
zrobot_interfaces__srv__SetConfig_Response__Sequence__copy(
  const zrobot_interfaces__srv__SetConfig_Response__Sequence * input,
  zrobot_interfaces__srv__SetConfig_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(zrobot_interfaces__srv__SetConfig_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    zrobot_interfaces__srv__SetConfig_Response * data =
      (zrobot_interfaces__srv__SetConfig_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!zrobot_interfaces__srv__SetConfig_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          zrobot_interfaces__srv__SetConfig_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!zrobot_interfaces__srv__SetConfig_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "zrobot_interfaces/srv/detail/set_config__functions.h"

bool
zrobot_interfaces__srv__SetConfig_Event__init(zrobot_interfaces__srv__SetConfig_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    zrobot_interfaces__srv__SetConfig_Event__fini(msg);
    return false;
  }
  // request
  if (!zrobot_interfaces__srv__SetConfig_Request__Sequence__init(&msg->request, 0)) {
    zrobot_interfaces__srv__SetConfig_Event__fini(msg);
    return false;
  }
  // response
  if (!zrobot_interfaces__srv__SetConfig_Response__Sequence__init(&msg->response, 0)) {
    zrobot_interfaces__srv__SetConfig_Event__fini(msg);
    return false;
  }
  return true;
}

void
zrobot_interfaces__srv__SetConfig_Event__fini(zrobot_interfaces__srv__SetConfig_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  zrobot_interfaces__srv__SetConfig_Request__Sequence__fini(&msg->request);
  // response
  zrobot_interfaces__srv__SetConfig_Response__Sequence__fini(&msg->response);
}

bool
zrobot_interfaces__srv__SetConfig_Event__are_equal(const zrobot_interfaces__srv__SetConfig_Event * lhs, const zrobot_interfaces__srv__SetConfig_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!zrobot_interfaces__srv__SetConfig_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!zrobot_interfaces__srv__SetConfig_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
zrobot_interfaces__srv__SetConfig_Event__copy(
  const zrobot_interfaces__srv__SetConfig_Event * input,
  zrobot_interfaces__srv__SetConfig_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!zrobot_interfaces__srv__SetConfig_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!zrobot_interfaces__srv__SetConfig_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

zrobot_interfaces__srv__SetConfig_Event *
zrobot_interfaces__srv__SetConfig_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zrobot_interfaces__srv__SetConfig_Event * msg = (zrobot_interfaces__srv__SetConfig_Event *)allocator.allocate(sizeof(zrobot_interfaces__srv__SetConfig_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(zrobot_interfaces__srv__SetConfig_Event));
  bool success = zrobot_interfaces__srv__SetConfig_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
zrobot_interfaces__srv__SetConfig_Event__destroy(zrobot_interfaces__srv__SetConfig_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    zrobot_interfaces__srv__SetConfig_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
zrobot_interfaces__srv__SetConfig_Event__Sequence__init(zrobot_interfaces__srv__SetConfig_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zrobot_interfaces__srv__SetConfig_Event * data = NULL;

  if (size) {
    data = (zrobot_interfaces__srv__SetConfig_Event *)allocator.zero_allocate(size, sizeof(zrobot_interfaces__srv__SetConfig_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = zrobot_interfaces__srv__SetConfig_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        zrobot_interfaces__srv__SetConfig_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
zrobot_interfaces__srv__SetConfig_Event__Sequence__fini(zrobot_interfaces__srv__SetConfig_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      zrobot_interfaces__srv__SetConfig_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

zrobot_interfaces__srv__SetConfig_Event__Sequence *
zrobot_interfaces__srv__SetConfig_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zrobot_interfaces__srv__SetConfig_Event__Sequence * array = (zrobot_interfaces__srv__SetConfig_Event__Sequence *)allocator.allocate(sizeof(zrobot_interfaces__srv__SetConfig_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = zrobot_interfaces__srv__SetConfig_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
zrobot_interfaces__srv__SetConfig_Event__Sequence__destroy(zrobot_interfaces__srv__SetConfig_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    zrobot_interfaces__srv__SetConfig_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
zrobot_interfaces__srv__SetConfig_Event__Sequence__are_equal(const zrobot_interfaces__srv__SetConfig_Event__Sequence * lhs, const zrobot_interfaces__srv__SetConfig_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!zrobot_interfaces__srv__SetConfig_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
zrobot_interfaces__srv__SetConfig_Event__Sequence__copy(
  const zrobot_interfaces__srv__SetConfig_Event__Sequence * input,
  zrobot_interfaces__srv__SetConfig_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(zrobot_interfaces__srv__SetConfig_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    zrobot_interfaces__srv__SetConfig_Event * data =
      (zrobot_interfaces__srv__SetConfig_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!zrobot_interfaces__srv__SetConfig_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          zrobot_interfaces__srv__SetConfig_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!zrobot_interfaces__srv__SetConfig_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
