// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from messages:msg/PlatformTarget.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__PLATFORM_TARGET__STRUCT_H_
#define MESSAGES__MSG__DETAIL__PLATFORM_TARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'PLATFORM_CAR'.
enum
{
  messages__msg__PlatformTarget__PLATFORM_CAR = 0
};

/// Constant 'PLATFORM_FLIGHT'.
enum
{
  messages__msg__PlatformTarget__PLATFORM_FLIGHT = 1
};

/// Struct defined in msg/PlatformTarget in the package messages.
typedef struct messages__msg__PlatformTarget
{
  uint8_t platform;
  float x;
  float y;
  float z;
  float yaw;
  float vx_mps;
  float vy_mps;
  float vz_mps;
  float speed_mps;
  float curvature;
  float yaw_rate_dps;
} messages__msg__PlatformTarget;

// Struct for a sequence of messages__msg__PlatformTarget.
typedef struct messages__msg__PlatformTarget__Sequence
{
  messages__msg__PlatformTarget * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__msg__PlatformTarget__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES__MSG__DETAIL__PLATFORM_TARGET__STRUCT_H_
