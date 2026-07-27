// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_tools:msg/LidarPose.idl
// generated code does not contain a copyright notice

#ifndef ROS2_TOOLS__MSG__DETAIL__LIDAR_POSE__STRUCT_H_
#define ROS2_TOOLS__MSG__DETAIL__LIDAR_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/LidarPose in the package ros2_tools.
typedef struct ros2_tools__msg__LidarPose
{
  double x;
  double y;
  double z;
  double roll;
  double pitch;
  double yaw;
} ros2_tools__msg__LidarPose;

// Struct for a sequence of ros2_tools__msg__LidarPose.
typedef struct ros2_tools__msg__LidarPose__Sequence
{
  ros2_tools__msg__LidarPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_tools__msg__LidarPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_TOOLS__MSG__DETAIL__LIDAR_POSE__STRUCT_H_
