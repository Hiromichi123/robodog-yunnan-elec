cmake_minimum_required(VERSION 3.15)
project(rl_briefing)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# ── RPATH（必须写在 add_executable 之前！）───────────────────────────
# 移植踩到过：RoboStack/conda 不设 LD_LIBRARY_PATH，库全靠 RUNPATH 找；
# 而老式 ament_target_dependencies 链接时，传递依赖（rclcpp/tracetools）没有
# 对应链接目录，-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=ON 收集不到 →
# 运行时 `librclcpp.so: cannot open shared object file`（实测）。
# CMAKE_INSTALL_RPATH 只在创建目标时被读去初始化 INSTALL_RPATH，写晚了没用。
# 与 core_2026/CMakeLists.txt 里那段一致。
if(DEFINED ENV{CONDA_PREFIX})
  set(CMAKE_INSTALL_RPATH "$ENV{CONDA_PREFIX}/lib" "${CMAKE_INSTALL_PREFIX}/lib")
else()
  set(CMAKE_INSTALL_RPATH /usr/local/lib)
endif()

# ALSA（系统库）
find_library(ALSA_LIB asound REQUIRED)
find_path(ALSA_INCLUDE alsa/asoundlib.h REQUIRED)

# 静态库：直接链进可执行文件，避免 --merge-install 下自定义 .so 的 RPATH 问题
add_library(alsa_player STATIC src/alsa_player.cpp)
target_include_directories(alsa_player PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  ${ALSA_INCLUDE})
target_link_libraries(alsa_player PUBLIC ${ALSA_LIB})

add_executable(briefing_player src/briefing_player.cpp)
ament_target_dependencies(briefing_player rclcpp std_msgs)
target_link_libraries(briefing_player alsa_player)

install(TARGETS briefing_player
  DESTINATION lib/${PROJECT_NAME})
install(DIRECTORY launch config
  DESTINATION share/${PROJECT_NAME})

# make_wavs.py 要在板子上能直接跑（生成/替换音频），所以装到 lib 下
install(PROGRAMS scripts/make_wavs.py
  DESTINATION lib/${PROJECT_NAME})

ament_package()
