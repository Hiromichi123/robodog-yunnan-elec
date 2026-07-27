// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from messages:msg/SmartCarControlSetpoint.idl
// generated code does not contain a copyright notice
#include "messages/msg/detail/smart_car_control_setpoint__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
messages__msg__SmartCarControlSetpoint__init(messages__msg__SmartCarControlSetpoint * msg)
{
  if (!msg) {
    return false;
  }
  // mode
  // flags
  // target_speed_mps
  // target_curvature
  // target_yaw_rate_dps
  // target_accel_mps2
  return true;
}

void
messages__msg__SmartCarControlSetpoint__fini(messages__msg__SmartCarControlSetpoint * msg)
{
  if (!msg) {
    return;
  }
  // mode
  // flags
  // target_speed_mps
  // target_curvature
  // target_yaw_rate_dps
  // target_accel_mps2
}

bool
messages__msg__SmartCarControlSetpoint__are_equal(const messages__msg__SmartCarControlSetpoint * lhs, const messages__msg__SmartCarControlSetpoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  // flags
  if (lhs->flags != rhs->flags) {
    return false;
  }
  // target_speed_mps
  if (lhs->target_speed_mps != rhs->target_speed_mps) {
    return false;
  }
  // target_curvature
  if (lhs->target_curvature != rhs->target_curvature) {
    return false;
  }
  // target_yaw_rate_dps
  if (lhs->target_yaw_rate_dps != rhs->target_yaw_rate_dps) {
    return false;
  }
  // target_accel_mps2
  if (lhs->target_accel_mps2 != rhs->target_accel_mps2) {
    return false;
  }
  return true;
}

bool
messages__msg__SmartCarControlSetpoint__copy(
  const messages__msg__SmartCarControlSetpoint * input,
  messages__msg__SmartCarControlSetpoint * output)
{
  if (!input || !output) {
    return false;
  }
  // mode
  output->mode = input->mode;
  // flags
  output->flags = input->flags;
  // target_speed_mps
  output->target_speed_mps = input->target_speed_mps;
  // target_curvature
  output->target_curvature = input->target_curvature;
  // target_yaw_rate_dps
  output->target_yaw_rate_dps = input->target_yaw_rate_dps;
  // target_accel_mps2
  output->target_accel_mps2 = input->target_accel_mps2;
  return true;
}

messages__msg__SmartCarControlSetpoint *
messages__msg__SmartCarControlSetpoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__SmartCarControlSetpoint * msg = (messages__msg__SmartCarControlSetpoint *)allocator.allocate(sizeof(messages__msg__SmartCarControlSetpoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(messages__msg__SmartCarControlSetpoint));
  bool success = messages__msg__SmartCarControlSetpoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
messages__msg__SmartCarControlSetpoint__destroy(messages__msg__SmartCarControlSetpoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    messages__msg__SmartCarControlSetpoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
messages__msg__SmartCarControlSetpoint__Sequence__init(messages__msg__SmartCarControlSetpoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__SmartCarControlSetpoint * data = NULL;

  if (size) {
    data = (messages__msg__SmartCarControlSetpoint *)allocator.zero_allocate(size, sizeof(messages__msg__SmartCarControlSetpoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = messages__msg__SmartCarControlSetpoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        messages__msg__SmartCarControlSetpoint__fini(&data[i - 1]);
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
messages__msg__SmartCarControlSetpoint__Sequence__fini(messages__msg__SmartCarControlSetpoint__Sequence * array)
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
      messages__msg__SmartCarControlSetpoint__fini(&array->data[i]);
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

messages__msg__SmartCarControlSetpoint__Sequence *
messages__msg__SmartCarControlSetpoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__SmartCarControlSetpoint__Sequence * array = (messages__msg__SmartCarControlSetpoint__Sequence *)allocator.allocate(sizeof(messages__msg__SmartCarControlSetpoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = messages__msg__SmartCarControlSetpoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
messages__msg__SmartCarControlSetpoint__Sequence__destroy(messages__msg__SmartCarControlSetpoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    messages__msg__SmartCarControlSetpoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
messages__msg__SmartCarControlSetpoint__Sequence__are_equal(const messages__msg__SmartCarControlSetpoint__Sequence * lhs, const messages__msg__SmartCarControlSetpoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!messages__msg__SmartCarControlSetpoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
messages__msg__SmartCarControlSetpoint__Sequence__copy(
  const messages__msg__SmartCarControlSetpoint__Sequence * input,
  messages__msg__SmartCarControlSetpoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(messages__msg__SmartCarControlSetpoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    messages__msg__SmartCarControlSetpoint * data =
      (messages__msg__SmartCarControlSetpoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!messages__msg__SmartCarControlSetpoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          messages__msg__SmartCarControlSetpoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!messages__msg__SmartCarControlSetpoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
