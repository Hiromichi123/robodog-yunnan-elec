cmake_minimum_required(VERSION 3.8)
project(ros2_tools)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)

# ── 可选依赖 ──────────────────────────────────────────────────────
# OpenCV / cv_bridge / realsense2 只被 ground_camera_node 和 d435_node 使用。
# 本机（NanoPi M5，JXG 机器狗）不需要这两个节点，且 RoboStack aarch64 上没有
# realsense2 包。改为 QUIET：缺失时跳过对应目标，而不是让整个包 configure 失败。
# 依赖齐全的机器上行为与上游完全一致。
find_package(OpenCV QUIET)
find_package(cv_bridge QUIET)
find_package(realsense2 QUIET)

rosidl_generate_interfaces(${PROJECT_NAME} "msg/LidarPose.msg")
ament_export_dependencies(rosidl_default_runtime)

# ── 必需目标 ──────────────────────────────────────────────────────
add_executable(lidar_data_node src/lidar_data_node.cpp)
add_executable(lidar_to_px4_bridge src/lidar_to_px4_bridge.cpp)

# ── 可选目标（缺依赖就跳过）────────────────────────────────────────
if(OpenCV_FOUND AND cv_bridge_FOUND)
  add_executable(ground_camera_node src/ground_camera_node.cpp)
  ament_target_dependencies(ground_camera_node rclcpp sensor_msgs OpenCV cv_bridge)
else()
  message(STATUS "ros2_tools: 缺 OpenCV/cv_bridge，跳过 ground_camera_node")
endif()

if(OpenCV_FOUND AND cv_bridge_FOUND AND realsense2_FOUND)
  add_executable(d435_node src/d435_node.cpp)
  target_include_directories(d435_node PRIVATE ${realsense2_INCLUDE_DIRS})
  target_link_libraries(d435_node ${realsense2_LIBRARY})
  ament_target_dependencies(d435_node rclcpp sensor_msgs OpenCV cv_bridge realsense2)
else()
  message(STATUS "ros2_tools: 缺 realsense2，跳过 d435_node")
endif()

target_include_directories(lidar_data_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(lidar_data_node ${cpp_typesupport_target})

ament_target_dependencies(lidar_data_node rclcpp geometry_msgs tf2 tf2_geometry_msgs nav_msgs)
ament_target_dependencies(lidar_to_px4_bridge rclcpp geometry_msgs nav_msgs)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS lidar_data_node DESTINATION lib/${PROJECT_NAME})
install(TARGETS lidar_to_px4_bridge DESTINATION lib/${PROJECT_NAME})
# 注：上游此处重复 install 了一次 lidar_to_px4_bridge，已去掉（无功能影响）
if(TARGET ground_camera_node)
  install(TARGETS ground_camera_node DESTINATION lib/${PROJECT_NAME})
endif()
if(TARGET d435_node)
  install(TARGETS d435_node DESTINATION lib/${PROJECT_NAME})
endif()
install(DIRECTORY msg DESTINATION share/${PROJECT_NAME})

ament_package()
