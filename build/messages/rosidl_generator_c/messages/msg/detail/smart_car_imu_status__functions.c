// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from messages:msg/SmartCarImuStatus.idl
// generated code does not contain a copyright notice
#include "messages/msg/detail/smart_car_imu_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
messages__msg__SmartCarImuStatus__init(messages__msg__SmartCarImuStatus * msg)
{
  if (!msg) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    messages__msg__SmartCarImuStatus__fini(msg);
    return false;
  }
  // time_boot_ms
  // sample_count
  // overrun_count
  // error_count
  // gyro_x_mdps
  // gyro_y_mdps
  // gyro_z_mdps
  // yaw_rate_raw_dps
  // yaw_rate_dps
  // gyro_bias_z_dps
  // accel_x_mg
  // accel_y_mg
  // accel_z_mg
  // temperature_c_x100
  // calibrated
  return true;
}

void
messages__msg__SmartCarImuStatus__fini(messages__msg__SmartCarImuStatus * msg)
{
  if (!msg) {
    return;
  }
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
  // time_boot_ms
  // sample_count
  // overrun_count
  // error_count
  // gyro_x_mdps
  // gyro_y_mdps
  // gyro_z_mdps
  // yaw_rate_raw_dps
  // yaw_rate_dps
  // gyro_bias_z_dps
  // accel_x_mg
  // accel_y_mg
  // accel_z_mg
  // temperature_c_x100
  // calibrated
}

bool
messages__msg__SmartCarImuStatus__are_equal(const messages__msg__SmartCarImuStatus * lhs, const messages__msg__SmartCarImuStatus * rhs)
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
  // sample_count
  if (lhs->sample_count != rhs->sample_count) {
    return false;
  }
  // overrun_count
  if (lhs->overrun_count != rhs->overrun_count) {
    return false;
  }
  // error_count
  if (lhs->error_count != rhs->error_count) {
    return false;
  }
  // gyro_x_mdps
  if (lhs->gyro_x_mdps != rhs->gyro_x_mdps) {
    return false;
  }
  // gyro_y_mdps
  if (lhs->gyro_y_mdps != rhs->gyro_y_mdps) {
    return false;
  }
  // gyro_z_mdps
  if (lhs->gyro_z_mdps != rhs->gyro_z_mdps) {
    return false;
  }
  // yaw_rate_raw_dps
  if (lhs->yaw_rate_raw_dps != rhs->yaw_rate_raw_dps) {
    return false;
  }
  // yaw_rate_dps
  if (lhs->yaw_rate_dps != rhs->yaw_rate_dps) {
    return false;
  }
  // gyro_bias_z_dps
  if (lhs->gyro_bias_z_dps != rhs->gyro_bias_z_dps) {
    return false;
  }
  // accel_x_mg
  if (lhs->accel_x_mg != rhs->accel_x_mg) {
    return false;
  }
  // accel_y_mg
  if (lhs->accel_y_mg != rhs->accel_y_mg) {
    return false;
  }
  // accel_z_mg
  if (lhs->accel_z_mg != rhs->accel_z_mg) {
    return false;
  }
  // temperature_c_x100
  if (lhs->temperature_c_x100 != rhs->temperature_c_x100) {
    return false;
  }
  // calibrated
  if (lhs->calibrated != rhs->calibrated) {
    return false;
  }
  return true;
}

bool
messages__msg__SmartCarImuStatus__copy(
  const messages__msg__SmartCarImuStatus * input,
  messages__msg__SmartCarImuStatus * output)
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
  // sample_count
  output->sample_count = input->sample_count;
  // overrun_count
  output->overrun_count = input->overrun_count;
  // error_count
  output->error_count = input->error_count;
  // gyro_x_mdps
  output->gyro_x_mdps = input->gyro_x_mdps;
  // gyro_y_mdps
  output->gyro_y_mdps = input->gyro_y_mdps;
  // gyro_z_mdps
  output->gyro_z_mdps = input->gyro_z_mdps;
  // yaw_rate_raw_dps
  output->yaw_rate_raw_dps = input->yaw_rate_raw_dps;
  // yaw_rate_dps
  output->yaw_rate_dps = input->yaw_rate_dps;
  // gyro_bias_z_dps
  output->gyro_bias_z_dps = input->gyro_bias_z_dps;
  // accel_x_mg
  output->accel_x_mg = input->accel_x_mg;
  // accel_y_mg
  output->accel_y_mg = input->accel_y_mg;
  // accel_z_mg
  output->accel_z_mg = input->accel_z_mg;
  // temperature_c_x100
  output->temperature_c_x100 = input->temperature_c_x100;
  // calibrated
  output->calibrated = input->calibrated;
  return true;
}

messages__msg__SmartCarImuStatus *
messages__msg__SmartCarImuStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__SmartCarImuStatus * msg = (messages__msg__SmartCarImuStatus *)allocator.allocate(sizeof(messages__msg__SmartCarImuStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(messages__msg__SmartCarImuStatus));
  bool success = messages__msg__SmartCarImuStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
messages__msg__SmartCarImuStatus__destroy(messages__msg__SmartCarImuStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    messages__msg__SmartCarImuStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
messages__msg__SmartCarImuStatus__Sequence__init(messages__msg__SmartCarImuStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__SmartCarImuStatus * data = NULL;

  if (size) {
    data = (messages__msg__SmartCarImuStatus *)allocator.zero_allocate(size, sizeof(messages__msg__SmartCarImuStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = messages__msg__SmartCarImuStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        messages__msg__SmartCarImuStatus__fini(&data[i - 1]);
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
messages__msg__SmartCarImuStatus__Sequence__fini(messages__msg__SmartCarImuStatus__Sequence * array)
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
      messages__msg__SmartCarImuStatus__fini(&array->data[i]);
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

messages__msg__SmartCarImuStatus__Sequence *
messages__msg__SmartCarImuStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__SmartCarImuStatus__Sequence * array = (messages__msg__SmartCarImuStatus__Sequence *)allocator.allocate(sizeof(messages__msg__SmartCarImuStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = messages__msg__SmartCarImuStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
messages__msg__SmartCarImuStatus__Sequence__destroy(messages__msg__SmartCarImuStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    messages__msg__SmartCarImuStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
messages__msg__SmartCarImuStatus__Sequence__are_equal(const messages__msg__SmartCarImuStatus__Sequence * lhs, const messages__msg__SmartCarImuStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!messages__msg__SmartCarImuStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
messages__msg__SmartCarImuStatus__Sequence__copy(
  const messages__msg__SmartCarImuStatus__Sequence * input,
  messages__msg__SmartCarImuStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(messages__msg__SmartCarImuStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    messages__msg__SmartCarImuStatus * data =
      (messages__msg__SmartCarImuStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!messages__msg__SmartCarImuStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          messages__msg__SmartCarImuStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!messages__msg__SmartCarImuStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
