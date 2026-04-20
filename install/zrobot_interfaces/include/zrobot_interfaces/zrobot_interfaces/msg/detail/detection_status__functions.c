// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from zrobot_interfaces:msg/DetectionStatus.idl
// generated code does not contain a copyright notice
#include "zrobot_interfaces/msg/detail/detection_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `target_object`
// Member `zone`
#include "rosidl_runtime_c/string_functions.h"

bool
zrobot_interfaces__msg__DetectionStatus__init(zrobot_interfaces__msg__DetectionStatus * msg)
{
  if (!msg) {
    return false;
  }
  // target_object
  if (!rosidl_runtime_c__String__init(&msg->target_object)) {
    zrobot_interfaces__msg__DetectionStatus__fini(msg);
    return false;
  }
  // target_found
  // zone
  if (!rosidl_runtime_c__String__init(&msg->zone)) {
    zrobot_interfaces__msg__DetectionStatus__fini(msg);
    return false;
  }
  // target_count
  // confidence
  // inference_time_ms
  // fps
  // frame_width
  // frame_height
  // target_center_x
  return true;
}

void
zrobot_interfaces__msg__DetectionStatus__fini(zrobot_interfaces__msg__DetectionStatus * msg)
{
  if (!msg) {
    return;
  }
  // target_object
  rosidl_runtime_c__String__fini(&msg->target_object);
  // target_found
  // zone
  rosidl_runtime_c__String__fini(&msg->zone);
  // target_count
  // confidence
  // inference_time_ms
  // fps
  // frame_width
  // frame_height
  // target_center_x
}

bool
zrobot_interfaces__msg__DetectionStatus__are_equal(const zrobot_interfaces__msg__DetectionStatus * lhs, const zrobot_interfaces__msg__DetectionStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target_object
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->target_object), &(rhs->target_object)))
  {
    return false;
  }
  // target_found
  if (lhs->target_found != rhs->target_found) {
    return false;
  }
  // zone
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->zone), &(rhs->zone)))
  {
    return false;
  }
  // target_count
  if (lhs->target_count != rhs->target_count) {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // inference_time_ms
  if (lhs->inference_time_ms != rhs->inference_time_ms) {
    return false;
  }
  // fps
  if (lhs->fps != rhs->fps) {
    return false;
  }
  // frame_width
  if (lhs->frame_width != rhs->frame_width) {
    return false;
  }
  // frame_height
  if (lhs->frame_height != rhs->frame_height) {
    return false;
  }
  // target_center_x
  if (lhs->target_center_x != rhs->target_center_x) {
    return false;
  }
  return true;
}

bool
zrobot_interfaces__msg__DetectionStatus__copy(
  const zrobot_interfaces__msg__DetectionStatus * input,
  zrobot_interfaces__msg__DetectionStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // target_object
  if (!rosidl_runtime_c__String__copy(
      &(input->target_object), &(output->target_object)))
  {
    return false;
  }
  // target_found
  output->target_found = input->target_found;
  // zone
  if (!rosidl_runtime_c__String__copy(
      &(input->zone), &(output->zone)))
  {
    return false;
  }
  // target_count
  output->target_count = input->target_count;
  // confidence
  output->confidence = input->confidence;
  // inference_time_ms
  output->inference_time_ms = input->inference_time_ms;
  // fps
  output->fps = input->fps;
  // frame_width
  output->frame_width = input->frame_width;
  // frame_height
  output->frame_height = input->frame_height;
  // target_center_x
  output->target_center_x = input->target_center_x;
  return true;
}

zrobot_interfaces__msg__DetectionStatus *
zrobot_interfaces__msg__DetectionStatus__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zrobot_interfaces__msg__DetectionStatus * msg = (zrobot_interfaces__msg__DetectionStatus *)allocator.allocate(sizeof(zrobot_interfaces__msg__DetectionStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(zrobot_interfaces__msg__DetectionStatus));
  bool success = zrobot_interfaces__msg__DetectionStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
zrobot_interfaces__msg__DetectionStatus__destroy(zrobot_interfaces__msg__DetectionStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    zrobot_interfaces__msg__DetectionStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
zrobot_interfaces__msg__DetectionStatus__Sequence__init(zrobot_interfaces__msg__DetectionStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zrobot_interfaces__msg__DetectionStatus * data = NULL;

  if (size) {
    data = (zrobot_interfaces__msg__DetectionStatus *)allocator.zero_allocate(size, sizeof(zrobot_interfaces__msg__DetectionStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = zrobot_interfaces__msg__DetectionStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        zrobot_interfaces__msg__DetectionStatus__fini(&data[i - 1]);
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
zrobot_interfaces__msg__DetectionStatus__Sequence__fini(zrobot_interfaces__msg__DetectionStatus__Sequence * array)
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
      zrobot_interfaces__msg__DetectionStatus__fini(&array->data[i]);
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

zrobot_interfaces__msg__DetectionStatus__Sequence *
zrobot_interfaces__msg__DetectionStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zrobot_interfaces__msg__DetectionStatus__Sequence * array = (zrobot_interfaces__msg__DetectionStatus__Sequence *)allocator.allocate(sizeof(zrobot_interfaces__msg__DetectionStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = zrobot_interfaces__msg__DetectionStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
zrobot_interfaces__msg__DetectionStatus__Sequence__destroy(zrobot_interfaces__msg__DetectionStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    zrobot_interfaces__msg__DetectionStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
zrobot_interfaces__msg__DetectionStatus__Sequence__are_equal(const zrobot_interfaces__msg__DetectionStatus__Sequence * lhs, const zrobot_interfaces__msg__DetectionStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!zrobot_interfaces__msg__DetectionStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
zrobot_interfaces__msg__DetectionStatus__Sequence__copy(
  const zrobot_interfaces__msg__DetectionStatus__Sequence * input,
  zrobot_interfaces__msg__DetectionStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(zrobot_interfaces__msg__DetectionStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    zrobot_interfaces__msg__DetectionStatus * data =
      (zrobot_interfaces__msg__DetectionStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!zrobot_interfaces__msg__DetectionStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          zrobot_interfaces__msg__DetectionStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!zrobot_interfaces__msg__DetectionStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
