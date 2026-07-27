// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from messages:msg/SmartCarStatus.idl
// generated code does not contain a copyright notice
#include "messages/msg/detail/smart_car_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
messages__msg__SmartCarStatus__init(messages__msg__SmartCarStatus * msg)
{
  if (!msg) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    messages__msg__SmartCarStatus__fini(msg);
    return false;
  }
  // time_boot_ms
  // mode
  // state
  // fault_flags
  // warn_flags
  // cmd_age_ms
  // control_loop_hz
  // imu_online
  // can_online
  // host_online
  // servo_online
  // motor_online_mask
  return true;
}

void
messages__msg__SmartCarStatus__fini(messages__msg__SmartCarStatus * msg)
{
  if (!msg) {
    return;
  }
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
  // time_boot_ms
  // mode
  // state
  // fault_flags
  // warn_flags
  // cmd_age_ms
  // control_loop_hz
  // imu_online
  // can_online
  // host_online
  // servo_online
  // motor_online_mask
}

bool
messages__msg__SmartCarStatus__are_equal(const messages__msg__SmartCarStatus * lhs, const messages__msg__SmartCarStatus * rhs)
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
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  // state
  if (lhs->state != rhs->state) {
    return false;
  }
  // fault_flags
  if (lhs->fault_flags != rhs->fault_flags) {
    return false;
  }
  // warn_flags
  if (lhs->warn_flags != rhs->warn_flags) {
    return false;
  }
  // cmd_age_ms
  if (lhs->cmd_age_ms != rhs->cmd_age_ms) {
    return false;
  }
  // control_loop_hz
  if (lhs->control_loop_hz != rhs->control_loop_hz) {
    return false;
  }
  // imu_online
  if (lhs->imu_online != rhs->imu_online) {
    return false;
  }
  // can_online
  if (lhs->can_online != rhs->can_online) {
    return false;
  }
  // host_online
  if (lhs->host_online != rhs->host_online) {
    return false;
  }
  // servo_online
  if (lhs->servo_online != rhs->servo_online) {
    return false;
  }
  // motor_online_mask
  if (lhs->motor_online_mask != rhs->motor_online_mask) {
    return false;
  }
  return true;
}

bool
messages__msg__SmartCarStatus__copy(
  const messages__msg__SmartCarStatus * input,
  messages__msg__SmartCarStatus * output)
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
  // mode
  output->mode = input->mode;
  // state
  output->state = input->state;
  // fault_flags
  output->fault_flags = input->fault_flags;
  // warn_flags
  output->warn_flags = input->warn_flags;
  // cmd_age_ms
  output->cmd_age_ms = input->cmd_age_ms;
  // control_loop_hz
  output->control_loop_hz = input->control_loop_hz;
  // imu_online
  output->imu_online = input->imu_online;
  // can_online
  output->can_online = input->can_online;
  // host_online
  output->host_online = input->host_online;
  // servo_online
  output->servo_online = input->servo_online;
  // motor_online_mask
  output->motor_online_mask = input->motor_online_mask;
  return true;
}

messages__msg__SmartCarStatus *
messages__msg__SmartCarStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__SmartCarStatus * msg = (messages__msg__SmartCarStatus *)allocator.allocate(sizeof(messages__msg__SmartCarStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(messages__msg__SmartCarStatus));
  bool success = messages__msg__SmartCarStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
messages__msg__SmartCarStatus__destroy(messages__msg__SmartCarStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    messages__msg__SmartCarStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
messages__msg__SmartCarStatus__Sequence__init(messages__msg__SmartCarStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__SmartCarStatus * data = NULL;

  if (size) {
    data = (messages__msg__SmartCarStatus *)allocator.zero_allocate(size, sizeof(messages__msg__SmartCarStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = messages__msg__SmartCarStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        messages__msg__SmartCarStatus__fini(&data[i - 1]);
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
messages__msg__SmartCarStatus__Sequence__fini(messages__msg__SmartCarStatus__Sequence * array)
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
      messages__msg__SmartCarStatus__fini(&array->data[i]);
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

messages__msg__SmartCarStatus__Sequence *
messages__msg__SmartCarStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__SmartCarStatus__Sequence * array = (messages__msg__SmartCarStatus__Sequence *)allocator.allocate(sizeof(messages__msg__SmartCarStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = messages__msg__SmartCarStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
messages__msg__SmartCarStatus__Sequence__destroy(messages__msg__SmartCarStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    messages__msg__SmartCarStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
messages__msg__SmartCarStatus__Sequence__are_equal(const messages__msg__SmartCarStatus__Sequence * lhs, const messages__msg__SmartCarStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!messages__msg__SmartCarStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
messages__msg__SmartCarStatus__Sequence__copy(
  const messages__msg__SmartCarStatus__Sequence * input,
  messages__msg__SmartCarStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(messages__msg__SmartCarStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    messages__msg__SmartCarStatus * data =
      (messages__msg__SmartCarStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!messages__msg__SmartCarStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          messages__msg__SmartCarStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!messages__msg__SmartCarStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
