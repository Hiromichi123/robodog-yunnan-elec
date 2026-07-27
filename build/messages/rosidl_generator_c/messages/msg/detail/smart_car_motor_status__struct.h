// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from messages:msg/SmartCarMotorStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_MOTOR_STATUS__STRUCT_H_
#define MESSAGES__MSG__DETAIL__SMART_CAR_MOTOR_STATUS__STRUCT_H_

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

/// Struct defined in msg/SmartCarMotorStatus in the package messages.
typedef struct messages__msg__SmartCarMotorStatus
{
  builtin_interfaces__msg__Time stamp;
  uint32_t time_boot_ms;
  int16_t target_rpm_1;
  int16_t target_rpm_2;
  int16_t actual_rpm_1;
  int16_t actual_rpm_2;
  int16_t current_cmd_1;
  int16_t current_cmd_2;
  int16_t feedback_current_1;
  int16_t feedback_current_2;
  uint16_t angle_1;
  uint16_t angle_2;
  uint8_t online_mask;
  uint32_t can_tx_busy_count;
  uint32_t can_error_count;
} messages__msg__SmartCarMotorStatus;

// Struct for a sequence of messages__msg__SmartCarMotorStatus.
typedef struct messages__msg__SmartCarMotorStatus__Sequence
{
  messages__msg__SmartCarMotorStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__msg__SmartCarMotorStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_MOTOR_STATUS__STRUCT_H_
