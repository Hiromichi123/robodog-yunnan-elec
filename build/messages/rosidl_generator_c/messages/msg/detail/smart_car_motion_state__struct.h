// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from messages:msg/SmartCarMotionState.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_MOTION_STATE__STRUCT_H_
#define MESSAGES__MSG__DETAIL__SMART_CAR_MOTION_STATE__STRUCT_H_

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

/// Struct defined in msg/SmartCarMotionState in the package messages.
typedef struct messages__msg__SmartCarMotionState
{
  builtin_interfaces__msg__Time stamp;
  uint32_t time_boot_ms;
  float speed_mps;
  float target_speed_mps;
  float yaw_rate_dps;
  float yaw_deg;
  float curvature_meas;
  float curvature_cmd;
  float steering_angle_deg;
  uint16_t steering_pwm_us;
  uint8_t steering_clamped;
} messages__msg__SmartCarMotionState;

// Struct for a sequence of messages__msg__SmartCarMotionState.
typedef struct messages__msg__SmartCarMotionState__Sequence
{
  messages__msg__SmartCarMotionState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__msg__SmartCarMotionState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_MOTION_STATE__STRUCT_H_
