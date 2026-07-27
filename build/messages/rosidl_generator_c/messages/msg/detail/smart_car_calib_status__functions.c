// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from messages:msg/SmartCarCalibStatus.idl
// generated code does not contain a copyright notice
#include "messages/msg/detail/smart_car_calib_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
messages__msg__SmartCarCalibStatus__init(messages__msg__SmartCarCalibStatus * msg)
{
  if (!msg) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    messages__msg__SmartCarCalibStatus__fini(msg);
    return false;
  }
  // time_boot_ms
  // point_id
  // sweep_index
  // sweep_count
  // valid_count
  // invalid_count
  // v_center_avg
  // yaw_rate_avg
  // kappa_avg
  // radius_est
  // target_rpm
  // servo_pwm_us
  // state
  // sweep_enabled
  // yaw_sign_inverted
  return true;
}

void
messages__msg__SmartCarCalibStatus__fini(messages__msg__SmartCarCalibStatus * msg)
{
  if (!msg) {
    return;
  }
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
  // time_boot_ms
  // point_id
  // sweep_index
  // sweep_count
  // valid_count
  // invalid_count
  // v_center_avg
  // yaw_rate_avg
  // kappa_avg
  // radius_est
  // target_rpm
  // servo_pwm_us
  // state
  // sweep_enabled
  // yaw_sign_inverted
}

bool
messages__msg__SmartCarCalibStatus__are_equal(const messages__msg__SmartCarCalibStatus * lhs, const messages__msg__SmartCarCalibStatus * rhs)
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
  // point_id
  if (lhs->point_id != rhs->point_id) {
    return false;
  }
  // sweep_index
  if (lhs->sweep_index != rhs->sweep_index) {
    return false;
  }
  // sweep_count
  if (lhs->sweep_count != rhs->sweep_count) {
    return false;
  }
  // valid_count
  if (lhs->valid_count != rhs->valid_count) {
    return false;
  }
  // invalid_count
  if (lhs->invalid_count != rhs->invalid_count) {
    return false;
  }
  // v_center_avg
  if (lhs->v_center_avg != rhs->v_center_avg) {
    return false;
  }
  // yaw_rate_avg
  if (lhs->yaw_rate_avg != rhs->yaw_rate_avg) {
    return false;
  }
  // kappa_avg
  if (lhs->kappa_avg != rhs->kappa_avg) {
    return false;
  }
  // radius_est
  if (lhs->radius_est != rhs->radius_est) {
    return false;
  }
  // target_rpm
  if (lhs->target_rpm != rhs->target_rpm) {
    return false;
  }
  // servo_pwm_us
  if (lhs->servo_pwm_us != rhs->servo_pwm_us) {
    return false;
  }
  // state
  if (lhs->state != rhs->state) {
    return false;
  }
  // sweep_enabled
  if (lhs->sweep_enabled != rhs->sweep_enabled) {
    return false;
  }
  // yaw_sign_inverted
  if (lhs->yaw_sign_inverted != rhs->yaw_sign_inverted) {
    return false;
  }
  return true;
}

bool
messages__msg__SmartCarCalibStatus__copy(
  const messages__msg__SmartCarCalibStatus * input,
  messages__msg__SmartCarCalibStatus * output)
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
  // point_id
  output->point_id = input->point_id;
  // sweep_index
  output->sweep_index = input->sweep_index;
  // sweep_count
  output->sweep_count = input->sweep_count;
  // valid_count
  output->valid_count = input->valid_count;
  // invalid_count
  output->invalid_count = input->invalid_count;
  // v_center_avg
  output->v_center_avg = input->v_center_avg;
  // yaw_rate_avg
  output->yaw_rate_avg = input->yaw_rate_avg;
  // kappa_avg
  output->kappa_avg = input->kappa_avg;
  // radius_est
  output->radius_est = input->radius_est;
  // target_rpm
  output->target_rpm = input->target_rpm;
  // servo_pwm_us
  output->servo_pwm_us = input->servo_pwm_us;
  // state
  output->state = input->state;
  // sweep_enabled
  output->sweep_enabled = input->sweep_enabled;
  // yaw_sign_inverted
  output->yaw_sign_inverted = input->yaw_sign_inverted;
  return true;
}

messages__msg__SmartCarCalibStatus *
messages__msg__SmartCarCalibStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__SmartCarCalibStatus * msg = (messages__msg__SmartCarCalibStatus *)allocator.allocate(sizeof(messages__msg__SmartCarCalibStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(messages__msg__SmartCarCalibStatus));
  bool success = messages__msg__SmartCarCalibStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
messages__msg__SmartCarCalibStatus__destroy(messages__msg__SmartCarCalibStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    messages__msg__SmartCarCalibStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
messages__msg__SmartCarCalibStatus__Sequence__init(messages__msg__SmartCarCalibStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__SmartCarCalibStatus * data = NULL;

  if (size) {
    data = (messages__msg__SmartCarCalibStatus *)allocator.zero_allocate(size, sizeof(messages__msg__SmartCarCalibStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = messages__msg__SmartCarCalibStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        messages__msg__SmartCarCalibStatus__fini(&data[i - 1]);
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
messages__msg__SmartCarCalibStatus__Sequence__fini(messages__msg__SmartCarCalibStatus__Sequence * array)
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
      messages__msg__SmartCarCalibStatus__fini(&array->data[i]);
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

messages__msg__SmartCarCalibStatus__Sequence *
messages__msg__SmartCarCalibStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__SmartCarCalibStatus__Sequence * array = (messages__msg__SmartCarCalibStatus__Sequence *)allocator.allocate(sizeof(messages__msg__SmartCarCalibStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = messages__msg__SmartCarCalibStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
messages__msg__SmartCarCalibStatus__Sequence__destroy(messages__msg__SmartCarCalibStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    messages__msg__SmartCarCalibStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
messages__msg__SmartCarCalibStatus__Sequence__are_equal(const messages__msg__SmartCarCalibStatus__Sequence * lhs, const messages__msg__SmartCarCalibStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!messages__msg__SmartCarCalibStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
messages__msg__SmartCarCalibStatus__Sequence__copy(
  const messages__msg__SmartCarCalibStatus__Sequence * input,
  messages__msg__SmartCarCalibStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(messages__msg__SmartCarCalibStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    messages__msg__SmartCarCalibStatus * data =
      (messages__msg__SmartCarCalibStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!messages__msg__SmartCarCalibStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          messages__msg__SmartCarCalibStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!messages__msg__SmartCarCalibStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
