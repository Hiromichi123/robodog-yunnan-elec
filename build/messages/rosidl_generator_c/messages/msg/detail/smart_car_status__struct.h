// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from messages:msg/SmartCarStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_STATUS__STRUCT_H_
#define MESSAGES__MSG__DETAIL__SMART_CAR_STATUS__STRUCT_H_

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
  messages__msg__SmartCarStatus__SMART_CAR_MODE_IDLE = 0
};

/// Constant 'SMART_CAR_MODE_MANUAL'.
enum
{
  messages__msg__SmartCarStatus__SMART_CAR_MODE_MANUAL = 1
};

/// Constant 'SMART_CAR_MODE_AUTO'.
enum
{
  messages__msg__SmartCarStatus__SMART_CAR_MODE_AUTO = 2
};

/// Constant 'SMART_CAR_MODE_CALIB'.
enum
{
  messages__msg__SmartCarStatus__SMART_CAR_MODE_CALIB = 3
};

/// Constant 'SMART_CAR_STATE_IDLE'.
enum
{
  messages__msg__SmartCarStatus__SMART_CAR_STATE_IDLE = 0
};

/// Constant 'SMART_CAR_STATE_ARMED'.
enum
{
  messages__msg__SmartCarStatus__SMART_CAR_STATE_ARMED = 1
};

/// Constant 'SMART_CAR_STATE_RUNNING'.
enum
{
  messages__msg__SmartCarStatus__SMART_CAR_STATE_RUNNING = 2
};

/// Constant 'SMART_CAR_STATE_FAULT'.
enum
{
  messages__msg__SmartCarStatus__SMART_CAR_STATE_FAULT = 3
};

/// Constant 'SMART_CAR_STATE_CALIB'.
enum
{
  messages__msg__SmartCarStatus__SMART_CAR_STATE_CALIB = 4
};

/// Constant 'SMART_CAR_FAULT_CMD_TIMEOUT'.
enum
{
  messages__msg__SmartCarStatus__SMART_CAR_FAULT_CMD_TIMEOUT = 1ul
};

/// Constant 'SMART_CAR_FAULT_MOTOR1_OFFLINE'.
enum
{
  messages__msg__SmartCarStatus__SMART_CAR_FAULT_MOTOR1_OFFLINE = 2ul
};

/// Constant 'SMART_CAR_FAULT_MOTOR2_OFFLINE'.
enum
{
  messages__msg__SmartCarStatus__SMART_CAR_FAULT_MOTOR2_OFFLINE = 4ul
};

/// Constant 'SMART_CAR_FAULT_IMU_NOT_READY'.
enum
{
  messages__msg__SmartCarStatus__SMART_CAR_FAULT_IMU_NOT_READY = 8ul
};

/// Constant 'SMART_CAR_FAULT_CAN_ERROR'.
enum
{
  messages__msg__SmartCarStatus__SMART_CAR_FAULT_CAN_ERROR = 16ul
};

/// Constant 'SMART_CAR_FAULT_SERVO_CLAMPED'.
enum
{
  messages__msg__SmartCarStatus__SMART_CAR_FAULT_SERVO_CLAMPED = 32ul
};

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/SmartCarStatus in the package messages.
typedef struct messages__msg__SmartCarStatus
{
  builtin_interfaces__msg__Time stamp;
  uint32_t time_boot_ms;
  uint8_t mode;
  uint8_t state;
  uint32_t fault_flags;
  uint32_t warn_flags;
  uint16_t cmd_age_ms;
  uint16_t control_loop_hz;
  uint8_t imu_online;
  uint8_t can_online;
  uint8_t host_online;
  uint8_t servo_online;
  uint8_t motor_online_mask;
} messages__msg__SmartCarStatus;

// Struct for a sequence of messages__msg__SmartCarStatus.
typedef struct messages__msg__SmartCarStatus__Sequence
{
  messages__msg__SmartCarStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__msg__SmartCarStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_STATUS__STRUCT_H_
