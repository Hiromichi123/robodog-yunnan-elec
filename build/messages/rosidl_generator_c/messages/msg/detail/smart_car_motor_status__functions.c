// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from messages:msg/SmartCarMotorStatus.idl
// generated code does not contain a copyright notice
#include "messages/msg/detail/smart_car_motor_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
messages__msg__SmartCarMotorStatus__init(messages__msg__SmartCarMotorStatus * msg)
{
  if (!msg) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    messages__msg__SmartCarMotorStatus__fini(msg);
    return false;
  }
  // time_boot_ms
  // target_rpm_1
  // target_rpm_2
  // actual_rpm_1
  // actual_rpm_2
  // current_cmd_1
  // current_cmd_2
  // feedback_current_1
  // feedback_current_2
  // angle_1
  // angle_2
  // online_mask
  // can_tx_busy_count
  // can_error_count
  return true;
}

void
messages__msg__SmartCarMotorStatus__fini(messages__msg__SmartCarMotorStatus * msg)
{
  if (!msg) {
    return;
  }
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
  // time_boot_ms
  // target_rpm_1
  // target_rpm_2
  // actual_rpm_1
  // actual_rpm_2
  // current_cmd_1
  // current_cmd_2
  // feedback_current_1
  // feedback_current_2
  // angle_1
  // angle_2
  // online_mask
  // can_tx_busy_count
  // can_error_count
}

bool
messages__msg__SmartCarMotorStatus__are_equal(const messages__msg__SmartCarMotorStatus * lhs, const messages__msg__SmartCarMotorStatus * rhs)
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
  // target_rpm_1
  if (lhs->target_rpm_1 != rhs->target_rpm_1) {
    return false;
  }
  // target_rpm_2
  if (lhs->target_rpm_2 != rhs->target_rpm_2) {
    return false;
  }
  // actual_rpm_1
  if (lhs->actual_rpm_1 != rhs->actual_rpm_1) {
    return false;
  }
  // actual_rpm_2
  if (lhs->actual_rpm_2 != rhs->actual_rpm_2) {
    return false;
  }
  // current_cmd_1
  if (lhs->current_cmd_1 != rhs->current_cmd_1) {
    return false;
  }
  // current_cmd_2
  if (lhs->current_cmd_2 != rhs->current_cmd_2) {
    return false;
  }
  // feedback_current_1
  if (lhs->feedback_current_1 != rhs->feedback_current_1) {
    return false;
  }
  // feedback_current_2
  if (lhs->feedback_current_2 != rhs->feedback_current_2) {
    return false;
  }
  // angle_1
  if (lhs->angle_1 != rhs->angle_1) {
    return false;
  }
  // angle_2
  if (lhs->angle_2 != rhs->angle_2) {
    return false;
  }
  // online_mask
  if (lhs->online_mask != rhs->online_mask) {
    return false;
  }
  // can_tx_busy_count
  if (lhs->can_tx_busy_count != rhs->can_tx_busy_count) {
    return false;
  }
  // can_error_count
  if (lhs->can_error_count != rhs->can_error_count) {
    return false;
  }
  return true;
}

bool
messages__msg__SmartCarMotorStatus__copy(
  const messages__msg__SmartCarMotorStatus * input,
  messages__msg__SmartCarMotorStatus * output)
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
  // target_rpm_1
  output->target_rpm_1 = input->target_rpm_1;
  // target_rpm_2
  output->target_rpm_2 = input->target_rpm_2;
  // actual_rpm_1
  output->actual_rpm_1 = input->actual_rpm_1;
  // actual_rpm_2
  output->actual_rpm_2 = input->actual_rpm_2;
  // current_cmd_1
  output->current_cmd_1 = input->current_cmd_1;
  // current_cmd_2
  output->current_cmd_2 = input->current_cmd_2;
  // feedback_current_1
  output->feedback_current_1 = input->feedback_current_1;
  // feedback_current_2
  output->feedback_current_2 = input->feedback_current_2;
  // angle_1
  output->angle_1 = input->angle_1;
  // angle_2
  output->angle_2 = input->angle_2;
  // online_mask
  output->online_mask = input->online_mask;
  // can_tx_busy_count
  output->can_tx_busy_count = input->can_tx_busy_count;
  // can_error_count
  output->can_error_count = input->can_error_count;
  return true;
}

messages__msg__SmartCarMotorStatus *
messages__msg__SmartCarMotorStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__SmartCarMotorStatus * msg = (messages__msg__SmartCarMotorStatus *)allocator.allocate(sizeof(messages__msg__SmartCarMotorStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(messages__msg__SmartCarMotorStatus));
  bool success = messages__msg__SmartCarMotorStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
messages__msg__SmartCarMotorStatus__destroy(messages__msg__SmartCarMotorStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    messages__msg__SmartCarMotorStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
messages__msg__SmartCarMotorStatus__Sequence__init(messages__msg__SmartCarMotorStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__SmartCarMotorStatus * data = NULL;

  if (size) {
    data = (messages__msg__SmartCarMotorStatus *)allocator.zero_allocate(size, sizeof(messages__msg__SmartCarMotorStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = messages__msg__SmartCarMotorStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        messages__msg__SmartCarMotorStatus__fini(&data[i - 1]);
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
messages__msg__SmartCarMotorStatus__Sequence__fini(messages__msg__SmartCarMotorStatus__Sequence * array)
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
      messages__msg__SmartCarMotorStatus__fini(&array->data[i]);
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

messages__msg__SmartCarMotorStatus__Sequence *
messages__msg__SmartCarMotorStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__SmartCarMotorStatus__Sequence * array = (messages__msg__SmartCarMotorStatus__Sequence *)allocator.allocate(sizeof(messages__msg__SmartCarMotorStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = messages__msg__SmartCarMotorStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
messages__msg__SmartCarMotorStatus__Sequence__destroy(messages__msg__SmartCarMotorStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    messages__msg__SmartCarMotorStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
messages__msg__SmartCarMotorStatus__Sequence__are_equal(const messages__msg__SmartCarMotorStatus__Sequence * lhs, const messages__msg__SmartCarMotorStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!messages__msg__SmartCarMotorStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
messages__msg__SmartCarMotorStatus__Sequence__copy(
  const messages__msg__SmartCarMotorStatus__Sequence * input,
  messages__msg__SmartCarMotorStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(messages__msg__SmartCarMotorStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    messages__msg__SmartCarMotorStatus * data =
      (messages__msg__SmartCarMotorStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!messages__msg__SmartCarMotorStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          messages__msg__SmartCarMotorStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!messages__msg__SmartCarMotorStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
