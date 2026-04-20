// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from zrobot_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice
#include "zrobot_interfaces/msg/detail/motor_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `mode`
#include "rosidl_runtime_c/string_functions.h"

bool
zrobot_interfaces__msg__MotorCommand__init(zrobot_interfaces__msg__MotorCommand * msg)
{
  if (!msg) {
    return false;
  }
  // left_speed
  // right_speed
  // motors_running
  // mode
  if (!rosidl_runtime_c__String__init(&msg->mode)) {
    zrobot_interfaces__msg__MotorCommand__fini(msg);
    return false;
  }
  return true;
}

void
zrobot_interfaces__msg__MotorCommand__fini(zrobot_interfaces__msg__MotorCommand * msg)
{
  if (!msg) {
    return;
  }
  // left_speed
  // right_speed
  // motors_running
  // mode
  rosidl_runtime_c__String__fini(&msg->mode);
}

bool
zrobot_interfaces__msg__MotorCommand__are_equal(const zrobot_interfaces__msg__MotorCommand * lhs, const zrobot_interfaces__msg__MotorCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // left_speed
  if (lhs->left_speed != rhs->left_speed) {
    return false;
  }
  // right_speed
  if (lhs->right_speed != rhs->right_speed) {
    return false;
  }
  // motors_running
  if (lhs->motors_running != rhs->motors_running) {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->mode), &(rhs->mode)))
  {
    return false;
  }
  return true;
}

bool
zrobot_interfaces__msg__MotorCommand__copy(
  const zrobot_interfaces__msg__MotorCommand * input,
  zrobot_interfaces__msg__MotorCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // left_speed
  output->left_speed = input->left_speed;
  // right_speed
  output->right_speed = input->right_speed;
  // motors_running
  output->motors_running = input->motors_running;
  // mode
  if (!rosidl_runtime_c__String__copy(
      &(input->mode), &(output->mode)))
  {
    return false;
  }
  return true;
}

zrobot_interfaces__msg__MotorCommand *
zrobot_interfaces__msg__MotorCommand__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zrobot_interfaces__msg__MotorCommand * msg = (zrobot_interfaces__msg__MotorCommand *)allocator.allocate(sizeof(zrobot_interfaces__msg__MotorCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(zrobot_interfaces__msg__MotorCommand));
  bool success = zrobot_interfaces__msg__MotorCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
zrobot_interfaces__msg__MotorCommand__destroy(zrobot_interfaces__msg__MotorCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    zrobot_interfaces__msg__MotorCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
zrobot_interfaces__msg__MotorCommand__Sequence__init(zrobot_interfaces__msg__MotorCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zrobot_interfaces__msg__MotorCommand * data = NULL;

  if (size) {
    data = (zrobot_interfaces__msg__MotorCommand *)allocator.zero_allocate(size, sizeof(zrobot_interfaces__msg__MotorCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = zrobot_interfaces__msg__MotorCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        zrobot_interfaces__msg__MotorCommand__fini(&data[i - 1]);
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
zrobot_interfaces__msg__MotorCommand__Sequence__fini(zrobot_interfaces__msg__MotorCommand__Sequence * array)
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
      zrobot_interfaces__msg__MotorCommand__fini(&array->data[i]);
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

zrobot_interfaces__msg__MotorCommand__Sequence *
zrobot_interfaces__msg__MotorCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zrobot_interfaces__msg__MotorCommand__Sequence * array = (zrobot_interfaces__msg__MotorCommand__Sequence *)allocator.allocate(sizeof(zrobot_interfaces__msg__MotorCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = zrobot_interfaces__msg__MotorCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
zrobot_interfaces__msg__MotorCommand__Sequence__destroy(zrobot_interfaces__msg__MotorCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    zrobot_interfaces__msg__MotorCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
zrobot_interfaces__msg__MotorCommand__Sequence__are_equal(const zrobot_interfaces__msg__MotorCommand__Sequence * lhs, const zrobot_interfaces__msg__MotorCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!zrobot_interfaces__msg__MotorCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
zrobot_interfaces__msg__MotorCommand__Sequence__copy(
  const zrobot_interfaces__msg__MotorCommand__Sequence * input,
  zrobot_interfaces__msg__MotorCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(zrobot_interfaces__msg__MotorCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    zrobot_interfaces__msg__MotorCommand * data =
      (zrobot_interfaces__msg__MotorCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!zrobot_interfaces__msg__MotorCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          zrobot_interfaces__msg__MotorCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!zrobot_interfaces__msg__MotorCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
