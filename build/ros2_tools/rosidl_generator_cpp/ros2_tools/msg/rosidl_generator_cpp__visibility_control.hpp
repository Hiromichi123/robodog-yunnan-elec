// generated from rosidl_generator_cpp/resource/rosidl_generator_cpp__visibility_control.hpp.in
// generated code does not contain a copyright notice

#ifndef ROS2_TOOLS__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
#define ROS2_TOOLS__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_GENERATOR_CPP_EXPORT_ros2_tools __attribute__ ((dllexport))
    #define ROSIDL_GENERATOR_CPP_IMPORT_ros2_tools __attribute__ ((dllimport))
  #else
    #define ROSIDL_GENERATOR_CPP_EXPORT_ros2_tools __declspec(dllexport)
    #define ROSIDL_GENERATOR_CPP_IMPORT_ros2_tools __declspec(dllimport)
  #endif
  #ifdef ROSIDL_GENERATOR_CPP_BUILDING_DLL_ros2_tools
    #define ROSIDL_GENERATOR_CPP_PUBLIC_ros2_tools ROSIDL_GENERATOR_CPP_EXPORT_ros2_tools
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_ros2_tools ROSIDL_GENERATOR_CPP_IMPORT_ros2_tools
  #endif
#else
  #define ROSIDL_GENERATOR_CPP_EXPORT_ros2_tools __attribute__ ((visibility("default")))
  #define ROSIDL_GENERATOR_CPP_IMPORT_ros2_tools
  #if __GNUC__ >= 4
    #define ROSIDL_GENERATOR_CPP_PUBLIC_ros2_tools __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_ros2_tools
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // ROS2_TOOLS__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
