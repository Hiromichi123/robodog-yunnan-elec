// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from messages:msg/SmartCarControlSetpoint.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_CONTROL_SETPOINT__STRUCT_H_
#define MESSAGES__MSG__DETAIL__SMART_CAR_CONTROL_SETPOINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'SMART_CAR_MODE_IDLE'.
enum
{
  messages__msg__SmartCarControlSetpoint__SMART_CAR_MODE_IDLE = 0
};

/// Constant 'SMART_CAR_MODE_MANUAL'.
enum
{
  messages__msg__SmartCarControlSetpoint__SMART_CAR_MODE_MANUAL = 1
};

/// Constant 'SMART_CAR_MODE_AUTO'.
enum
{
  messages__msg__SmartCarControlSetpoint__SMART_CAR_MODE_AUTO = 2
};

/// Constant 'SMART_CAR_MODE_CALIB'.
enum
{
  messages__msg__SmartCarControlSetpoint__SMART_CAR_MODE_CALIB = 3
};

/// Constant 'SMART_CAR_CONTROL_FLAG_ENABLE'.
enum
{
  messages__msg__SmartCarControlSetpoint__SMART_CAR_CONTROL_FLAG_ENABLE = 1
};

/// Constant 'SMART_CAR_CONTROL_FLAG_BRAKE'.
enum
{
  messages__msg__SmartCarControlSetpoint__SMART_CAR_CONTROL_FLAG_BRAKE = 2
};

/// Constant 'SMART_CAR_CONTROL_FLAG_REVERSE'.
enum
{
  messages__msg__SmartCarControlSetpoint__SMART_CAR_CONTROL_FLAG_REVERSE = 4
};

/// Constant 'SMART_CAR_CONTROL_FLAG_HOLD'.
enum
{
  messages__msg__SmartCarControlSetpoint__SMART_CAR_CONTROL_FLAG_HOLD = 8
};

/// Struct defined in msg/SmartCarControlSetpoint in the package messages.
typedef struct messages__msg__SmartCarControlSetpoint
{
  uint8_t mode;
  uint16_t flags;
  float target_speed_mps;
  float target_curvature;
  float target_yaw_rate_dps;
  float target_accel_mps2;
} messages__msg__SmartCarControlSetpoint;

// Struct for a sequence of messages__msg__SmartCarControlSetpoint.
typedef struct messages__msg__SmartCarControlSetpoint__Sequence
{
  messages__msg__SmartCarControlSetpoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__msg__SmartCarControlSetpoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_CONTROL_SETPOINT__STRUCT_H_
