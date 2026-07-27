// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from messages:srv/SmartCarCommand.idl
// generated code does not contain a copyright notice
#include "messages/srv/detail/smart_car_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
messages__srv__SmartCarCommand_Request__init(messages__srv__SmartCarCommand_Request * msg)
{
  if (!msg) {
    return false;
  }
  // command
  // param1
  // param2
  // param3
  // param4
  return true;
}

void
messages__srv__SmartCarCommand_Request__fini(messages__srv__SmartCarCommand_Request * msg)
{
  if (!msg) {
    return;
  }
  // command
  // param1
  // param2
  // param3
  // param4
}

bool
messages__srv__SmartCarCommand_Request__are_equal(const messages__srv__SmartCarCommand_Request * lhs, const messages__srv__SmartCarCommand_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // command
  if (lhs->command != rhs->command) {
    return false;
  }
  // param1
  if (lhs->param1 != rhs->param1) {
    return false;
  }
  // param2
  if (lhs->param2 != rhs->param2) {
    return false;
  }
  // param3
  if (lhs->param3 != rhs->param3) {
    return false;
  }
  // param4
  if (lhs->param4 != rhs->param4) {
    return false;
  }
  return true;
}

bool
messages__srv__SmartCarCommand_Request__copy(
  const messages__srv__SmartCarCommand_Request * input,
  messages__srv__SmartCarCommand_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // command
  output->command = input->command;
  // param1
  output->param1 = input->param1;
  // param2
  output->param2 = input->param2;
  // param3
  output->param3 = input->param3;
  // param4
  output->param4 = input->param4;
  return true;
}

messages__srv__SmartCarCommand_Request *
messages__srv__SmartCarCommand_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__srv__SmartCarCommand_Request * msg = (messages__srv__SmartCarCommand_Request *)allocator.allocate(sizeof(messages__srv__SmartCarCommand_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(messages__srv__SmartCarCommand_Request));
  bool success = messages__srv__SmartCarCommand_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
messages__srv__SmartCarCommand_Request__destroy(messages__srv__SmartCarCommand_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    messages__srv__SmartCarCommand_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
messages__srv__SmartCarCommand_Request__Sequence__init(messages__srv__SmartCarCommand_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__srv__SmartCarCommand_Request * data = NULL;

  if (size) {
    data = (messages__srv__SmartCarCommand_Request *)allocator.zero_allocate(size, sizeof(messages__srv__SmartCarCommand_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = messages__srv__SmartCarCommand_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        messages__srv__SmartCarCommand_Request__fini(&data[i - 1]);
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
messages__srv__SmartCarCommand_Request__Sequence__fini(messages__srv__SmartCarCommand_Request__Sequence * array)
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
      messages__srv__SmartCarCommand_Request__fini(&array->data[i]);
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

messages__srv__SmartCarCommand_Request__Sequence *
messages__srv__SmartCarCommand_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__srv__SmartCarCommand_Request__Sequence * array = (messages__srv__SmartCarCommand_Request__Sequence *)allocator.allocate(sizeof(messages__srv__SmartCarCommand_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = messages__srv__SmartCarCommand_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
messages__srv__SmartCarCommand_Request__Sequence__destroy(messages__srv__SmartCarCommand_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    messages__srv__SmartCarCommand_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
messages__srv__SmartCarCommand_Request__Sequence__are_equal(const messages__srv__SmartCarCommand_Request__Sequence * lhs, const messages__srv__SmartCarCommand_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!messages__srv__SmartCarCommand_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
messages__srv__SmartCarCommand_Request__Sequence__copy(
  const messages__srv__SmartCarCommand_Request__Sequence * input,
  messages__srv__SmartCarCommand_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(messages__srv__SmartCarCommand_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    messages__srv__SmartCarCommand_Request * data =
      (messages__srv__SmartCarCommand_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!messages__srv__SmartCarCommand_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          messages__srv__SmartCarCommand_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!messages__srv__SmartCarCommand_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
messages__srv__SmartCarCommand_Response__init(messages__srv__SmartCarCommand_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    messages__srv__SmartCarCommand_Response__fini(msg);
    return false;
  }
  return true;
}

void
messages__srv__SmartCarCommand_Response__fini(messages__srv__SmartCarCommand_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
messages__srv__SmartCarCommand_Response__are_equal(const messages__srv__SmartCarCommand_Response * lhs, const messages__srv__SmartCarCommand_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
messages__srv__SmartCarCommand_Response__copy(
  const messages__srv__SmartCarCommand_Response * input,
  messages__srv__SmartCarCommand_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

messages__srv__SmartCarCommand_Response *
messages__srv__SmartCarCommand_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__srv__SmartCarCommand_Response * msg = (messages__srv__SmartCarCommand_Response *)allocator.allocate(sizeof(messages__srv__SmartCarCommand_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(messages__srv__SmartCarCommand_Response));
  bool success = messages__srv__SmartCarCommand_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
messages__srv__SmartCarCommand_Response__destroy(messages__srv__SmartCarCommand_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    messages__srv__SmartCarCommand_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
messages__srv__SmartCarCommand_Response__Sequence__init(messages__srv__SmartCarCommand_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__srv__SmartCarCommand_Response * data = NULL;

  if (size) {
    data = (messages__srv__SmartCarCommand_Response *)allocator.zero_allocate(size, sizeof(messages__srv__SmartCarCommand_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = messages__srv__SmartCarCommand_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        messages__srv__SmartCarCommand_Response__fini(&data[i - 1]);
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
messages__srv__SmartCarCommand_Response__Sequence__fini(messages__srv__SmartCarCommand_Response__Sequence * array)
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
      messages__srv__SmartCarCommand_Response__fini(&array->data[i]);
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

messages__srv__SmartCarCommand_Response__Sequence *
messages__srv__SmartCarCommand_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__srv__SmartCarCommand_Response__Sequence * array = (messages__srv__SmartCarCommand_Response__Sequence *)allocator.allocate(sizeof(messages__srv__SmartCarCommand_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = messages__srv__SmartCarCommand_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
messages__srv__SmartCarCommand_Response__Sequence__destroy(messages__srv__SmartCarCommand_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    messages__srv__SmartCarCommand_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
messages__srv__SmartCarCommand_Response__Sequence__are_equal(const messages__srv__SmartCarCommand_Response__Sequence * lhs, const messages__srv__SmartCarCommand_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!messages__srv__SmartCarCommand_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
messages__srv__SmartCarCommand_Response__Sequence__copy(
  const messages__srv__SmartCarCommand_Response__Sequence * input,
  messages__srv__SmartCarCommand_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(messages__srv__SmartCarCommand_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    messages__srv__SmartCarCommand_Response * data =
      (messages__srv__SmartCarCommand_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!messages__srv__SmartCarCommand_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          messages__srv__SmartCarCommand_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!messages__srv__SmartCarCommand_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
