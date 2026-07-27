// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from messages:msg/SmartCarImuStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_IMU_STATUS__STRUCT_H_
#define MESSAGES__MSG__DETAIL__SMART_CAR_IMU_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/SmartCarImuStatus in the package messages.
typedef struct messages__msg__SmartCarImuStatus
{
  builtin_interfaces__msg__Time stamp;
  uint32_t time_boot_ms;
  uint32_t sample_count;
  uint32_t overrun_count;
  uint32_t error_count;
  int32_t gyro_x_mdps;
  int32_t gyro_y_mdps;
  int32_t gyro_z_mdps;
  float yaw_rate_raw_dps;
  float yaw_rate_dps;
  float gyro_bias_z_dps;
  int16_t accel_x_mg;
  int16_t accel_y_mg;
  int16_t accel_z_mg;
  int16_t temperature_c_x100;
  uint8_t calibrated;
} messages__msg__SmartCarImuStatus;

// Struct for a sequence of messages__msg__SmartCarImuStatus.
typedef struct messages__msg__SmartCarImuStatus__Sequence
{
  messages__msg__SmartCarImuStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__msg__SmartCarImuStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_IMU_STATUS__STRUCT_H_
