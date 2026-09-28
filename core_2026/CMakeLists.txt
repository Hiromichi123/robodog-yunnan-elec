cmake_minimum_required(VERSION 3.8)
project(core_2026)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ── 依赖 ──────────────────────────────────────────────────────
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(ros2_tools REQUIRED)
find_package(messages REQUIRED)
# mavros_msgs 只被 quad_node / car_mission_node / test_max_curvature（无人机、小车）
# 使用；dog_node 不链接它。本机（NanoPi M5，JXG 机器狗）没有 mavros_msgs，
# 故改为 QUIET，缺失时只构建 dog_node。依赖齐全的机器上行为与上游一致。
find_package(mavros_msgs QUIET)

# ── RPATH（必须写在 add_executable 之前！）──────────────────────
# CMAKE_INSTALL_RPATH 只在 **创建目标时** 被读去初始化目标的 INSTALL_RPATH 属性，
# 写在 add_executable 之后就完全无效 —— 上游那句就踩了这个坑（它在文件末尾），
# 所以 /usr/local/lib 从来没进过 RUNPATH。
#
# 为什么必须显式写：RoboStack/conda 不设 LD_LIBRARY_PATH，库全靠 RUNPATH 找。
# 而 dog_node 用老式 ament_target_dependencies 链接，传递依赖（tracetools/rclcpp）
# 没有对应的链接目录，-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=ON 收集不到，
# 结果就是运行时 `librclcpp.so: cannot open shared object file`（已实测）。
#
# 两条都要：conda 的 lib（rclcpp 等）+ 工作区 install/lib（messages / ros2_tools）。
if(DEFINED ENV{CONDA_PREFIX})
  set(CMAKE_INSTALL_RPATH "$ENV{CONDA_PREFIX}/lib" "${CMAKE_INSTALL_PREFIX}/lib")
else()
  set(CMAKE_INSTALL_RPATH /usr/local/lib)
endif()

# ── 源文件 ────────────────────────────────────────────────────
set(SOURCES
  src/layer1_hal/drone_hal.cpp
  src/layer2_control/pid_controller.cpp
  src/layer2_control/flight_controller.cpp
  src/layer3_mission/mission_executor.cpp
  src/layer4_system/drone_system.cpp
  src/main.cpp
)

set(CAR_MISSION_SOURCES
  src/layer3_mission/car_mission_executor.cpp
)

set(TEST_MAX_CURVATURE_SOURCES
  src/layer3_mission/test_max_curvature.cpp
)

# ── 机器狗源文件 ──────────────────────────────────────────
set(DOG_SOURCES
  src/layer1_hal/robot_dog_hal.cpp
  src/layer2_control/pid_controller.cpp
  src/layer2_control/flight_controller.cpp
  src/layer3_mission/mission_executor.cpp
  src/layer3_mission/dog_mission_executor.cpp
  src/layer4_system/dog_system.cpp
  src/main_dog.cpp
)

# ── 机器狗目标（本机唯一需要构建的）────────────────────────────
add_executable(dog_node ${DOG_SOURCES})

target_include_directories(dog_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
  $<INSTALL_INTERFACE:include>
)

ament_target_dependencies(dog_node
  rclcpp
  geometry_msgs
  nav_msgs
  std_msgs
  ros2_tools
  messages
)

# ── 无人机 / 小车目标（需要 mavros_msgs，缺则整块跳过）──────────
if(mavros_msgs_FOUND)
  add_executable(quad_node ${SOURCES})
  add_executable(car_mission_node ${CAR_MISSION_SOURCES})
  add_executable(test_max_curvature ${TEST_MAX_CURVATURE_SOURCES})

  target_include_directories(quad_node PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>
  )

  target_include_directories(car_mission_node PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>
  )

  target_include_directories(test_max_curvature PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>
  )

  ament_target_dependencies(quad_node
    rclcpp geometry_msgs nav_msgs std_msgs mavros_msgs ros2_tools messages)

  ament_target_dependencies(car_mission_node
    rclcpp geometry_msgs nav_msgs std_msgs mavros_msgs ros2_tools messages)

  ament_target_dependencies(test_max_curvature
    rclcpp geometry_msgs nav_msgs std_msgs mavros_msgs ros2_tools messages)
else()
  message(STATUS "core_2026: 缺 mavros_msgs，只构建 dog_node（跳过 quad_node / car_mission_node / test_max_curvature）")
endif()

# ── 安装 ──────────────────────────────────────────────────────
# 注：RPATH 在文件开头设置（必须早于 add_executable），见上方注释。
install(TARGETS dog_node DESTINATION lib/${PROJECT_NAME})
if(mavros_msgs_FOUND)
  install(TARGETS quad_node car_mission_node test_max_curvature DESTINATION lib/${PROJECT_NAME})
endif()
install(DIRECTORY launch/ DESTINATION share/${PROJECT_NAME}/)

ament_package()
