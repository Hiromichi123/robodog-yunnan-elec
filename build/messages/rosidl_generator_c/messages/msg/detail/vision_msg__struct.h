// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from messages:msg/VisionMsg.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__VISION_MSG__STRUCT_H_
#define MESSAGES__MSG__DETAIL__VISION_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/VisionMsg in the package messages.
typedef struct messages__msg__VisionMsg
{
  bool is_line_detected;
  int32_t lateral_error;
  float angle_error;
  bool is_square_detected;
  int32_t center_x1_error;
  int32_t center_y1_error;
  bool is_circle_detected;
  int32_t center_x2_error;
  int32_t center_y2_error;
} messages__msg__VisionMsg;

// Struct for a sequence of messages__msg__VisionMsg.
typedef struct messages__msg__VisionMsg__Sequence
{
  messages__msg__VisionMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__msg__VisionMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES__MSG__DETAIL__VISION_MSG__STRUCT_H_
