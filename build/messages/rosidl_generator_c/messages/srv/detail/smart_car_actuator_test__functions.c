// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from messages:srv/SmartCarActuatorTest.idl
// generated code does not contain a copyright notice
#include "messages/srv/detail/smart_car_actuator_test__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
messages__srv__SmartCarActuatorTest_Request__init(messages__srv__SmartCarActuatorTest_Request * msg)
{
  if (!msg) {
    return false;
  }
  // test_mask
  // servo_angle_deg
  // servo_pwm_us
  // motor1_rpm
  // motor2_rpm
  // duration_ms
  return true;
}

void
messages__srv__SmartCarActuatorTest_Request__fini(messages__srv__SmartCarActuatorTest_Request * msg)
{
  if (!msg) {
    return;
  }
  // test_mask
  // servo_angle_deg
  // servo_pwm_us
  // motor1_rpm
  // motor2_rpm
  // duration_ms
}

bool
messages__srv__SmartCarActuatorTest_Request__are_equal(const messages__srv__SmartCarActuatorTest_Request * lhs, const messages__srv__SmartCarActuatorTest_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // test_mask
  if (lhs->test_mask != rhs->test_mask) {
    return false;
  }
  // servo_angle_deg
  if (lhs->servo_angle_deg != rhs->servo_angle_deg) {
    return false;
  }
  // servo_pwm_us
  if (lhs->servo_pwm_us != rhs->servo_pwm_us) {
    return false;
  }
  // motor1_rpm
  if (lhs->motor1_rpm != rhs->motor1_rpm) {
    return false;
  }
  // motor2_rpm
  if (lhs->motor2_rpm != rhs->motor2_rpm) {
    return false;
  }
  // duration_ms
  if (lhs->duration_ms != rhs->duration_ms) {
    return false;
  }
  return true;
}

bool
messages__srv__SmartCarActuatorTest_Request__copy(
  const messages__srv__SmartCarActuatorTest_Request * input,
  messages__srv__SmartCarActuatorTest_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // test_mask
  output->test_mask = input->test_mask;
  // servo_angle_deg
  output->servo_angle_deg = input->servo_angle_deg;
  // servo_pwm_us
  output->servo_pwm_us = input->servo_pwm_us;
  // motor1_rpm
  output->motor1_rpm = input->motor1_rpm;
  // motor2_rpm
  output->motor2_rpm = input->motor2_rpm;
  // duration_ms
  output->duration_ms = input->duration_ms;
  return true;
}

messages__srv__SmartCarActuatorTest_Request *
messages__srv__SmartCarActuatorTest_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__srv__SmartCarActuatorTest_Request * msg = (messages__srv__SmartCarActuatorTest_Request *)allocator.allocate(sizeof(messages__srv__SmartCarActuatorTest_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(messages__srv__SmartCarActuatorTest_Request));
  bool success = messages__srv__SmartCarActuatorTest_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
messages__srv__SmartCarActuatorTest_Request__destroy(messages__srv__SmartCarActuatorTest_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    messages__srv__SmartCarActuatorTest_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
messages__srv__SmartCarActuatorTest_Request__Sequence__init(messages__srv__SmartCarActuatorTest_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__srv__SmartCarActuatorTest_Request * data = NULL;

  if (size) {
    data = (messages__srv__SmartCarActuatorTest_Request *)allocator.zero_allocate(size, sizeof(messages__srv__SmartCarActuatorTest_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = messages__srv__SmartCarActuatorTest_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        messages__srv__SmartCarActuatorTest_Request__fini(&data[i - 1]);
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
messages__srv__SmartCarActuatorTest_Request__Sequence__fini(messages__srv__SmartCarActuatorTest_Request__Sequence * array)
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
      messages__srv__SmartCarActuatorTest_Request__fini(&array->data[i]);
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

messages__srv__SmartCarActuatorTest_Request__Sequence *
messages__srv__SmartCarActuatorTest_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__srv__SmartCarActuatorTest_Request__Sequence * array = (messages__srv__SmartCarActuatorTest_Request__Sequence *)allocator.allocate(sizeof(messages__srv__SmartCarActuatorTest_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = messages__srv__SmartCarActuatorTest_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
messages__srv__SmartCarActuatorTest_Request__Sequence__destroy(messages__srv__SmartCarActuatorTest_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    messages__srv__SmartCarActuatorTest_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
messages__srv__SmartCarActuatorTest_Request__Sequence__are_equal(const messages__srv__SmartCarActuatorTest_Request__Sequence * lhs, const messages__srv__SmartCarActuatorTest_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!messages__srv__SmartCarActuatorTest_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
messages__srv__SmartCarActuatorTest_Request__Sequence__copy(
  const messages__srv__SmartCarActuatorTest_Request__Sequence * input,
  messages__srv__SmartCarActuatorTest_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(messages__srv__SmartCarActuatorTest_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    messages__srv__SmartCarActuatorTest_Request * data =
      (messages__srv__SmartCarActuatorTest_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!messages__srv__SmartCarActuatorTest_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          messages__srv__SmartCarActuatorTest_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!messages__srv__SmartCarActuatorTest_Request__copy(
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
messages__srv__SmartCarActuatorTest_Response__init(messages__srv__SmartCarActuatorTest_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    messages__srv__SmartCarActuatorTest_Response__fini(msg);
    return false;
  }
  return true;
}

void
messages__srv__SmartCarActuatorTest_Response__fini(messages__srv__SmartCarActuatorTest_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
messages__srv__SmartCarActuatorTest_Response__are_equal(const messages__srv__SmartCarActuatorTest_Response * lhs, const messages__srv__SmartCarActuatorTest_Response * rhs)
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
messages__srv__SmartCarActuatorTest_Response__copy(
  const messages__srv__SmartCarActuatorTest_Response * input,
  messages__srv__SmartCarActuatorTest_Response * output)
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

messages__srv__SmartCarActuatorTest_Response *
messages__srv__SmartCarActuatorTest_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__srv__SmartCarActuatorTest_Response * msg = (messages__srv__SmartCarActuatorTest_Response *)allocator.allocate(sizeof(messages__srv__SmartCarActuatorTest_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(messages__srv__SmartCarActuatorTest_Response));
  bool success = messages__srv__SmartCarActuatorTest_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
messages__srv__SmartCarActuatorTest_Response__destroy(messages__srv__SmartCarActuatorTest_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    messages__srv__SmartCarActuatorTest_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
messages__srv__SmartCarActuatorTest_Response__Sequence__init(messages__srv__SmartCarActuatorTest_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__srv__SmartCarActuatorTest_Response * data = NULL;

  if (size) {
    data = (messages__srv__SmartCarActuatorTest_Response *)allocator.zero_allocate(size, sizeof(messages__srv__SmartCarActuatorTest_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = messages__srv__SmartCarActuatorTest_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        messages__srv__SmartCarActuatorTest_Response__fini(&data[i - 1]);
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
messages__srv__SmartCarActuatorTest_Response__Sequence__fini(messages__srv__SmartCarActuatorTest_Response__Sequence * array)
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
      messages__srv__SmartCarActuatorTest_Response__fini(&array->data[i]);
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

messages__srv__SmartCarActuatorTest_Response__Sequence *
messages__srv__SmartCarActuatorTest_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__srv__SmartCarActuatorTest_Response__Sequence * array = (messages__srv__SmartCarActuatorTest_Response__Sequence *)allocator.allocate(sizeof(messages__srv__SmartCarActuatorTest_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = messages__srv__SmartCarActuatorTest_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
messages__srv__SmartCarActuatorTest_Response__Sequence__destroy(messages__srv__SmartCarActuatorTest_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    messages__srv__SmartCarActuatorTest_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
messages__srv__SmartCarActuatorTest_Response__Sequence__are_equal(const messages__srv__SmartCarActuatorTest_Response__Sequence * lhs, const messages__srv__SmartCarActuatorTest_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!messages__srv__SmartCarActuatorTest_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
messages__srv__SmartCarActuatorTest_Response__Sequence__copy(
  const messages__srv__SmartCarActuatorTest_Response__Sequence * input,
  messages__srv__SmartCarActuatorTest_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(messages__srv__SmartCarActuatorTest_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    messages__srv__SmartCarActuatorTest_Response * data =
      (messages__srv__SmartCarActuatorTest_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!messages__srv__SmartCarActuatorTest_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          messages__srv__SmartCarActuatorTest_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!messages__srv__SmartCarActuatorTest_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
