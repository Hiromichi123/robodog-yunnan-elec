// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from messages:msg/SmartCarMotionState.idl
// generated code does not contain a copyright notice
#include "messages/msg/detail/smart_car_motion_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
messages__msg__SmartCarMotionState__init(messages__msg__SmartCarMotionState * msg)
{
  if (!msg) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    messages__msg__SmartCarMotionState__fini(msg);
    return false;
  }
  // time_boot_ms
  // speed_mps
  // target_speed_mps
  // yaw_rate_dps
  // yaw_deg
  // curvature_meas
  // curvature_cmd
  // steering_angle_deg
  // steering_pwm_us
  // steering_clamped
  return true;
}

void
messages__msg__SmartCarMotionState__fini(messages__msg__SmartCarMotionState * msg)
{
  if (!msg) {
    return;
  }
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
  // time_boot_ms
  // speed_mps
  // target_speed_mps
  // yaw_rate_dps
  // yaw_deg
  // curvature_meas
  // curvature_cmd
  // steering_angle_deg
  // steering_pwm_us
  // steering_clamped
}

bool
messages__msg__SmartCarMotionState__are_equal(const messages__msg__SmartCarMotionState * lhs, const messages__msg__SmartCarMotionState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  // time_boot_ms
  if (lhs->time_boot_ms != rhs->time_boot_ms) {
    return false;
  }
  // speed_mps
  if (lhs->speed_mps != rhs->speed_mps) {
    return false;
  }
  // target_speed_mps
  if (lhs->target_speed_mps != rhs->target_speed_mps) {
    return false;
  }
  // yaw_rate_dps
  if (lhs->yaw_rate_dps != rhs->yaw_rate_dps) {
    return false;
  }
  // yaw_deg
  if (lhs->yaw_deg != rhs->yaw_deg) {
    return false;
  }
  // curvature_meas
  if (lhs->curvature_meas != rhs->curvature_meas) {
    return false;
  }
  // curvature_cmd
  if (lhs->curvature_cmd != rhs->curvature_cmd) {
    return false;
  }
  // steering_angle_deg
  if (lhs->steering_angle_deg != rhs->steering_angle_deg) {
    return false;
  }
  // steering_pwm_us
  if (lhs->steering_pwm_us != rhs->steering_pwm_us) {
    return false;
  }
  // steering_clamped
  if (lhs->steering_clamped != rhs->steering_clamped) {
    return false;
  }
  return true;
}

bool
messages__msg__SmartCarMotionState__copy(
  const messages__msg__SmartCarMotionState * input,
  messages__msg__SmartCarMotionState * output)
{
  if (!input || !output) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  // time_boot_ms
  output->time_boot_ms = input->time_boot_ms;
  // speed_mps
  output->speed_mps = input->speed_mps;
  // target_speed_mps
  output->target_speed_mps = input->target_speed_mps;
  // yaw_rate_dps
  output->yaw_rate_dps = input->yaw_rate_dps;
  // yaw_deg
  output->yaw_deg = input->yaw_deg;
  // curvature_meas
  output->curvature_meas = input->curvature_meas;
  // curvature_cmd
  output->curvature_cmd = input->curvature_cmd;
  // steering_angle_deg
  output->steering_angle_deg = input->steering_angle_deg;
  // steering_pwm_us
  output->steering_pwm_us = input->steering_pwm_us;
  // steering_clamped
  output->steering_clamped = input->steering_clamped;
  return true;
}

messages__msg__SmartCarMotionState *
messages__msg__SmartCarMotionState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__SmartCarMotionState * msg = (messages__msg__SmartCarMotionState *)allocator.allocate(sizeof(messages__msg__SmartCarMotionState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(messages__msg__SmartCarMotionState));
  bool success = messages__msg__SmartCarMotionState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
messages__msg__SmartCarMotionState__destroy(messages__msg__SmartCarMotionState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    messages__msg__SmartCarMotionState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
messages__msg__SmartCarMotionState__Sequence__init(messages__msg__SmartCarMotionState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__SmartCarMotionState * data = NULL;

  if (size) {
    data = (messages__msg__SmartCarMotionState *)allocator.zero_allocate(size, sizeof(messages__msg__SmartCarMotionState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = messages__msg__SmartCarMotionState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        messages__msg__SmartCarMotionState__fini(&data[i - 1]);
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
messages__msg__SmartCarMotionState__Sequence__fini(messages__msg__SmartCarMotionState__Sequence * array)
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
      messages__msg__SmartCarMotionState__fini(&array->data[i]);
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

messages__msg__SmartCarMotionState__Sequence *
messages__msg__SmartCarMotionState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__SmartCarMotionState__Sequence * array = (messages__msg__SmartCarMotionState__Sequence *)allocator.allocate(sizeof(messages__msg__SmartCarMotionState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = messages__msg__SmartCarMotionState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
messages__msg__SmartCarMotionState__Sequence__destroy(messages__msg__SmartCarMotionState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    messages__msg__SmartCarMotionState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
messages__msg__SmartCarMotionState__Sequence__are_equal(const messages__msg__SmartCarMotionState__Sequence * lhs, const messages__msg__SmartCarMotionState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!messages__msg__SmartCarMotionState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
messages__msg__SmartCarMotionState__Sequence__copy(
  const messages__msg__SmartCarMotionState__Sequence * input,
  messages__msg__SmartCarMotionState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(messages__msg__SmartCarMotionState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    messages__msg__SmartCarMotionState * data =
      (messages__msg__SmartCarMotionState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!messages__msg__SmartCarMotionState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          messages__msg__SmartCarMotionState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!messages__msg__SmartCarMotionState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
