// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from messages:msg/Vision.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__VISION__STRUCT_H_
#define MESSAGES__MSG__DETAIL__VISION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'label'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Vision in the package messages.
typedef struct messages__msg__Vision
{
  bool is_detected;
  int32_t center_x;
  int32_t center_y;
  int32_t center_x1_error;
  rosidl_runtime_c__String label;
} messages__msg__Vision;

// Struct for a sequence of messages__msg__Vision.
typedef struct messages__msg__Vision__Sequence
{
  messages__msg__Vision * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__msg__Vision__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES__MSG__DETAIL__VISION__STRUCT_H_
