// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from messages:msg/VisionMsg.idl
// generated code does not contain a copyright notice
#include "messages/msg/detail/vision_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
messages__msg__VisionMsg__init(messages__msg__VisionMsg * msg)
{
  if (!msg) {
    return false;
  }
  // is_line_detected
  // lateral_error
  // angle_error
  // is_square_detected
  // center_x1_error
  // center_y1_error
  // is_circle_detected
  // center_x2_error
  // center_y2_error
  return true;
}

void
messages__msg__VisionMsg__fini(messages__msg__VisionMsg * msg)
{
  if (!msg) {
    return;
  }
  // is_line_detected
  // lateral_error
  // angle_error
  // is_square_detected
  // center_x1_error
  // center_y1_error
  // is_circle_detected
  // center_x2_error
  // center_y2_error
}

bool
messages__msg__VisionMsg__are_equal(const messages__msg__VisionMsg * lhs, const messages__msg__VisionMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // is_line_detected
  if (lhs->is_line_detected != rhs->is_line_detected) {
    return false;
  }
  // lateral_error
  if (lhs->lateral_error != rhs->lateral_error) {
    return false;
  }
  // angle_error
  if (lhs->angle_error != rhs->angle_error) {
    return false;
  }
  // is_square_detected
  if (lhs->is_square_detected != rhs->is_square_detected) {
    return false;
  }
  // center_x1_error
  if (lhs->center_x1_error != rhs->center_x1_error) {
    return false;
  }
  // center_y1_error
  if (lhs->center_y1_error != rhs->center_y1_error) {
    return false;
  }
  // is_circle_detected
  if (lhs->is_circle_detected != rhs->is_circle_detected) {
    return false;
  }
  // center_x2_error
  if (lhs->center_x2_error != rhs->center_x2_error) {
    return false;
  }
  // center_y2_error
  if (lhs->center_y2_error != rhs->center_y2_error) {
    return false;
  }
  return true;
}

bool
messages__msg__VisionMsg__copy(
  const messages__msg__VisionMsg * input,
  messages__msg__VisionMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // is_line_detected
  output->is_line_detected = input->is_line_detected;
  // lateral_error
  output->lateral_error = input->lateral_error;
  // angle_error
  output->angle_error = input->angle_error;
  // is_square_detected
  output->is_square_detected = input->is_square_detected;
  // center_x1_error
  output->center_x1_error = input->center_x1_error;
  // center_y1_error
  output->center_y1_error = input->center_y1_error;
  // is_circle_detected
  output->is_circle_detected = input->is_circle_detected;
  // center_x2_error
  output->center_x2_error = input->center_x2_error;
  // center_y2_error
  output->center_y2_error = input->center_y2_error;
  return true;
}

messages__msg__VisionMsg *
messages__msg__VisionMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__VisionMsg * msg = (messages__msg__VisionMsg *)allocator.allocate(sizeof(messages__msg__VisionMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(messages__msg__VisionMsg));
  bool success = messages__msg__VisionMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
messages__msg__VisionMsg__destroy(messages__msg__VisionMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    messages__msg__VisionMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
messages__msg__VisionMsg__Sequence__init(messages__msg__VisionMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__VisionMsg * data = NULL;

  if (size) {
    data = (messages__msg__VisionMsg *)allocator.zero_allocate(size, sizeof(messages__msg__VisionMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = messages__msg__VisionMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        messages__msg__VisionMsg__fini(&data[i - 1]);
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
messages__msg__VisionMsg__Sequence__fini(messages__msg__VisionMsg__Sequence * array)
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
      messages__msg__VisionMsg__fini(&array->data[i]);
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

messages__msg__VisionMsg__Sequence *
messages__msg__VisionMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__VisionMsg__Sequence * array = (messages__msg__VisionMsg__Sequence *)allocator.allocate(sizeof(messages__msg__VisionMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = messages__msg__VisionMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
messages__msg__VisionMsg__Sequence__destroy(messages__msg__VisionMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    messages__msg__VisionMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
messages__msg__VisionMsg__Sequence__are_equal(const messages__msg__VisionMsg__Sequence * lhs, const messages__msg__VisionMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!messages__msg__VisionMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
messages__msg__VisionMsg__Sequence__copy(
  const messages__msg__VisionMsg__Sequence * input,
  messages__msg__VisionMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(messages__msg__VisionMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    messages__msg__VisionMsg * data =
      (messages__msg__VisionMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!messages__msg__VisionMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          messages__msg__VisionMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!messages__msg__VisionMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
