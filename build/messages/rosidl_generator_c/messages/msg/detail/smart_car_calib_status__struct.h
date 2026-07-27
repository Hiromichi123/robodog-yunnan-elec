// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from messages:msg/SmartCarCalibStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_CALIB_STATUS__STRUCT_H_
#define MESSAGES__MSG__DETAIL__SMART_CAR_CALIB_STATUS__STRUCT_H_

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

/// Struct defined in msg/SmartCarCalibStatus in the package messages.
typedef struct messages__msg__SmartCarCalibStatus
{
  builtin_interfaces__msg__Time stamp;
  uint32_t time_boot_ms;
  uint32_t point_id;
  uint32_t sweep_index;
  uint32_t sweep_count;
  uint32_t valid_count;
  uint32_t invalid_count;
  float v_center_avg;
  float yaw_rate_avg;
  float kappa_avg;
  float radius_est;
  int16_t target_rpm;
  uint16_t servo_pwm_us;
  uint8_t state;
  uint8_t sweep_enabled;
  uint8_t yaw_sign_inverted;
} messages__msg__SmartCarCalibStatus;

// Struct for a sequence of messages__msg__SmartCarCalibStatus.
typedef struct messages__msg__SmartCarCalibStatus__Sequence
{
  messages__msg__SmartCarCalibStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__msg__SmartCarCalibStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_CALIB_STATUS__STRUCT_H_
