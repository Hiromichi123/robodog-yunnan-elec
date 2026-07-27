// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from messages:msg/Vision.idl
// generated code does not contain a copyright notice
#include "messages/msg/detail/vision__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `label`
#include "rosidl_runtime_c/string_functions.h"

bool
messages__msg__Vision__init(messages__msg__Vision * msg)
{
  if (!msg) {
    return false;
  }
  // is_detected
  // center_x
  // center_y
  // center_x1_error
  // label
  if (!rosidl_runtime_c__String__init(&msg->label)) {
    messages__msg__Vision__fini(msg);
    return false;
  }
  return true;
}

void
messages__msg__Vision__fini(messages__msg__Vision * msg)
{
  if (!msg) {
    return;
  }
  // is_detected
  // center_x
  // center_y
  // center_x1_error
  // label
  rosidl_runtime_c__String__fini(&msg->label);
}

bool
messages__msg__Vision__are_equal(const messages__msg__Vision * lhs, const messages__msg__Vision * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // is_detected
  if (lhs->is_detected != rhs->is_detected) {
    return false;
  }
  // center_x
  if (lhs->center_x != rhs->center_x) {
    return false;
  }
  // center_y
  if (lhs->center_y != rhs->center_y) {
    return false;
  }
  // center_x1_error
  if (lhs->center_x1_error != rhs->center_x1_error) {
    return false;
  }
  // label
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->label), &(rhs->label)))
  {
    return false;
  }
  return true;
}

bool
messages__msg__Vision__copy(
  const messages__msg__Vision * input,
  messages__msg__Vision * output)
{
  if (!input || !output) {
    return false;
  }
  // is_detected
  output->is_detected = input->is_detected;
  // center_x
  output->center_x = input->center_x;
  // center_y
  output->center_y = input->center_y;
  // center_x1_error
  output->center_x1_error = input->center_x1_error;
  // label
  if (!rosidl_runtime_c__String__copy(
      &(input->label), &(output->label)))
  {
    return false;
  }
  return true;
}

messages__msg__Vision *
messages__msg__Vision__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__Vision * msg = (messages__msg__Vision *)allocator.allocate(sizeof(messages__msg__Vision), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(messages__msg__Vision));
  bool success = messages__msg__Vision__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
messages__msg__Vision__destroy(messages__msg__Vision * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    messages__msg__Vision__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
messages__msg__Vision__Sequence__init(messages__msg__Vision__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__Vision * data = NULL;

  if (size) {
    data = (messages__msg__Vision *)allocator.zero_allocate(size, sizeof(messages__msg__Vision), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = messages__msg__Vision__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        messages__msg__Vision__fini(&data[i - 1]);
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
messages__msg__Vision__Sequence__fini(messages__msg__Vision__Sequence * array)
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
      messages__msg__Vision__fini(&array->data[i]);
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

messages__msg__Vision__Sequence *
messages__msg__Vision__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__Vision__Sequence * array = (messages__msg__Vision__Sequence *)allocator.allocate(sizeof(messages__msg__Vision__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = messages__msg__Vision__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
messages__msg__Vision__Sequence__destroy(messages__msg__Vision__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    messages__msg__Vision__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
messages__msg__Vision__Sequence__are_equal(const messages__msg__Vision__Sequence * lhs, const messages__msg__Vision__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!messages__msg__Vision__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
messages__msg__Vision__Sequence__copy(
  const messages__msg__Vision__Sequence * input,
  messages__msg__Vision__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(messages__msg__Vision);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    messages__msg__Vision * data =
      (messages__msg__Vision *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!messages__msg__Vision__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          messages__msg__Vision__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!messages__msg__Vision__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
