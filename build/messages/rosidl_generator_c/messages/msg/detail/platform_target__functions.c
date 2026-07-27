// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from messages:msg/PlatformTarget.idl
// generated code does not contain a copyright notice
#include "messages/msg/detail/platform_target__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
messages__msg__PlatformTarget__init(messages__msg__PlatformTarget * msg)
{
  if (!msg) {
    return false;
  }
  // platform
  // x
  // y
  // z
  // yaw
  // vx_mps
  // vy_mps
  // vz_mps
  // speed_mps
  // curvature
  // yaw_rate_dps
  return true;
}

void
messages__msg__PlatformTarget__fini(messages__msg__PlatformTarget * msg)
{
  if (!msg) {
    return;
  }
  // platform
  // x
  // y
  // z
  // yaw
  // vx_mps
  // vy_mps
  // vz_mps
  // speed_mps
  // curvature
  // yaw_rate_dps
}

bool
messages__msg__PlatformTarget__are_equal(const messages__msg__PlatformTarget * lhs, const messages__msg__PlatformTarget * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // platform
  if (lhs->platform != rhs->platform) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // vx_mps
  if (lhs->vx_mps != rhs->vx_mps) {
    return false;
  }
  // vy_mps
  if (lhs->vy_mps != rhs->vy_mps) {
    return false;
  }
  // vz_mps
  if (lhs->vz_mps != rhs->vz_mps) {
    return false;
  }
  // speed_mps
  if (lhs->speed_mps != rhs->speed_mps) {
    return false;
  }
  // curvature
  if (lhs->curvature != rhs->curvature) {
    return false;
  }
  // yaw_rate_dps
  if (lhs->yaw_rate_dps != rhs->yaw_rate_dps) {
    return false;
  }
  return true;
}

bool
messages__msg__PlatformTarget__copy(
  const messages__msg__PlatformTarget * input,
  messages__msg__PlatformTarget * output)
{
  if (!input || !output) {
    return false;
  }
  // platform
  output->platform = input->platform;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // yaw
  output->yaw = input->yaw;
  // vx_mps
  output->vx_mps = input->vx_mps;
  // vy_mps
  output->vy_mps = input->vy_mps;
  // vz_mps
  output->vz_mps = input->vz_mps;
  // speed_mps
  output->speed_mps = input->speed_mps;
  // curvature
  output->curvature = input->curvature;
  // yaw_rate_dps
  output->yaw_rate_dps = input->yaw_rate_dps;
  return true;
}

messages__msg__PlatformTarget *
messages__msg__PlatformTarget__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__PlatformTarget * msg = (messages__msg__PlatformTarget *)allocator.allocate(sizeof(messages__msg__PlatformTarget), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(messages__msg__PlatformTarget));
  bool success = messages__msg__PlatformTarget__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
messages__msg__PlatformTarget__destroy(messages__msg__PlatformTarget * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    messages__msg__PlatformTarget__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
messages__msg__PlatformTarget__Sequence__init(messages__msg__PlatformTarget__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__PlatformTarget * data = NULL;

  if (size) {
    data = (messages__msg__PlatformTarget *)allocator.zero_allocate(size, sizeof(messages__msg__PlatformTarget), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = messages__msg__PlatformTarget__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        messages__msg__PlatformTarget__fini(&data[i - 1]);
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
messages__msg__PlatformTarget__Sequence__fini(messages__msg__PlatformTarget__Sequence * array)
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
      messages__msg__PlatformTarget__fini(&array->data[i]);
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

messages__msg__PlatformTarget__Sequence *
messages__msg__PlatformTarget__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__PlatformTarget__Sequence * array = (messages__msg__PlatformTarget__Sequence *)allocator.allocate(sizeof(messages__msg__PlatformTarget__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = messages__msg__PlatformTarget__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
messages__msg__PlatformTarget__Sequence__destroy(messages__msg__PlatformTarget__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    messages__msg__PlatformTarget__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
messages__msg__PlatformTarget__Sequence__are_equal(const messages__msg__PlatformTarget__Sequence * lhs, const messages__msg__PlatformTarget__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!messages__msg__PlatformTarget__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
messages__msg__PlatformTarget__Sequence__copy(
  const messages__msg__PlatformTarget__Sequence * input,
  messages__msg__PlatformTarget__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(messages__msg__PlatformTarget);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    messages__msg__PlatformTarget * data =
      (messages__msg__PlatformTarget *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!messages__msg__PlatformTarget__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          messages__msg__PlatformTarget__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!messages__msg__PlatformTarget__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
