#!/bin/bash
set -eu
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
export LD_LIBRARY_PATH="$HOME/micromamba/envs/ros/lib:$HOME/fastlivo_ws/install/fast_livo/lib:${LD_LIBRARY_PATH:-}"
export OMP_NUM_THREADS=2 OPENBLAS_NUM_THREADS=1
safety_helper="$HOME/ros2_ws/install/lib/core_2026/start_local_safety.py"
safety_mode=$(python "$safety_helper" --mode)
safety_pid=''
# Reject disconnected sensors before spawning any mapper or recorder.
python "$HOME/pointlio_local/check_lidar_input.py"
children=(); collector_pid=''; geometry_pid=''; recorders=()
cleanup() {
 trap - EXIT INT TERM
 # Give the disk writer/exporter time to finish before stopping the remaining stack.
 for recorder in "${recorders[@]}"; do
  kill -INT "$recorder" 2>/dev/null || true
 done
 for recorder in "${recorders[@]}"; do
  for ((i=0;i<1800;i++)); do
   kill -0 "$recorder" 2>/dev/null || break
   sleep .1
  done
  kill -TERM "$recorder" 2>/dev/null || true
 done
 for pid in "${children[@]}"; do kill -INT "$pid" 2>/dev/null || true; done
 sleep 2
 for pid in "${children[@]}"; do kill -TERM "$pid" 2>/dev/null || true; done
 sleep 1
 for pid in "${children[@]}"; do kill -KILL "$pid" 2>/dev/null || true; done
 wait || true
}
trap cleanup EXIT
trap 'exit 130' INT
trap 'exit 143' TERM
if pgrep -f '[/](livox_ros_driver2_node|pointlio_mapping|fastlivo_mapping)' >/dev/null; then
 echo 'Another SLAM stack is running.' >&2;exit 1
fi
"$HOME/ros2_ws/install/lib/livox_ros_driver2/livox_ros_driver2_node" --ros-args \
 -p xfer_format:=1 -p multi_topic:=0 -p data_src:=0 -p publish_freq:=10.0 \
 -p output_data_type:=0 -p frame_id:=livox_frame \
 -p user_config_path:="$HOME/ros2_ws/config/MID360_config.json" \
 -p cmdline_input_bd_code:=livox0000000001 >/tmp/livox.log 2>&1 &
children+=("$!");sleep 5;kill -0 "${children[0]}"
if grep -qE 'bind failed|Failed to init livox|Init lds lidar fail' /tmp/livox.log; then
 echo '启动失败：Livox驱动初始化失败；请检查雷达地址、端口或网线。详情：/tmp/livox.log' >&2
 exit 2
fi
# ROS transport is independently managed by ros_web.launch.py.
# The navigation pose interface remains available in both modes.
if ! pgrep -f '[/]ros2_tools/lidar_data_node' >/dev/null; then
 "$HOME/ros2_ws/install/lib/ros2_tools/lidar_data_node" --ros-args \
 -p use_simulation:=false -p real_robot_odom_topic:=/aft_mapped_to_init \
 -p normalize_start_pose:=true -p apply_mount_transform:=true -p mount_x:=0.286 -p mount_y:=0.0 -p mount_z:=0.0 \
 -p mount_roll:=0.0 -p mount_pitch:=-2.356194 -p mount_yaw:=3.141593 >/tmp/lidar_data.log 2>&1 &
 children+=("$!")
fi
ensure_tf() {
 local child="$1";shift
 if ! pgrep -f "[s]tatic_transform_publisher.*--child-frame-id $child( |$)" >/dev/null; then
  "$CONDA_PREFIX/lib/tf2_ros/static_transform_publisher" "$@" --child-frame-id "$child" >/dev/null 2>&1 &
  children+=("$!")
 fi
}
ensure_tf body --x 0.286 --y 0 --z 0 --qx 0.923880 --qy 0 --qz 0.382683 --qw 0 --frame-id base_link
if [ "${SLAM_MAPPING:-0}" = 1 ]; then
 nice -n 10 python "$HOME/pointlio_local/geometry_save.py" &
 geometry_pid=$!;children+=("$geometry_pid");recorders+=("$geometry_pid")
 echo 'SLAM 建图已开启：保存5cm几何点云，停止时导出PCD。'
else
 echo 'SLAM 建图未开启：仅导航，不保存几何点云。'
fi
if [ "${RECONSTRUCTION:-0}" = 1 ]; then
 "$HOME/ros2_ws/install/lib/stereo_points/image_relay_node" --ros-args \
  -p out_topic:=/camera/image_stamped/compressed >/tmp/relay.log 2>&1 &
 children+=("$!")
 ensure_tf camera_link --x 0.326 --y 0 --z 0.095 --qx 0 --qy 0 --qz 0 --qw 1 --frame-id base_link
 ensure_tf camera_camera_rgb --x 0 --y 0 --z 0 --qx -0.5 --qy 0.5 --qz -0.5 --qw 0.5 --frame-id camera_link
 nice -n 10 python "$HOME/pointlio_local/stream_local.py" --export --web-preview &
 collector_pid=$!;children+=("$collector_pid");recorders+=("$collector_pid")
 echo 'MODE: SLAM导航 + 独立纯RGB地图；几何保存由SLAM建图开关控制'
else
 echo 'MODE: SLAM导航；彩色重建与Mesh关闭'
fi
if [ "$safety_mode" != disabled ]; then
 mkdir -p "$HOME/logs"
 python "$safety_helper" >"$HOME/logs/local_safety.log" 2>&1 &
 safety_pid=$!;children+=("$safety_pid")
fi
nice -n 10 "$HOME/ros2_ws/install/lib/point_lio/pointlio_mapping" --ros-args \
 --params-file "$HOME/pointlio_mesh/mid360_mesh.yaml" --log-level warn &
mapper_pid=$!;children+=("$mapper_pid")
# If reconstruction exits unexpectedly, stop rather than pretending to keep saving.
geometry_warned=0
while kill -0 "$mapper_pid" 2>/dev/null; do
 if [ -n "$safety_pid" ] && ! kill -0 "$safety_pid" 2>/dev/null; then
  echo '安全感知进程已退出：保护未就绪，停止本入口拥有的链路；见 ~/logs/local_safety.log。' >&2;exit 1
 fi
 if [ -n "$geometry_pid" ] && ! kill -0 "$geometry_pid" 2>/dev/null && [ "$geometry_warned" = 0 ]; then
  echo '几何保存进程已退出，请检查保存日志；SLAM导航继续运行。' >&2
  geometry_warned=1
 fi
 if [ -n "$collector_pid" ] && ! kill -0 "$collector_pid" 2>/dev/null; then
  echo 'Reconstruction exited; stopping owned stack.' >&2;exit 1
 fi
 sleep 1
done
wait "$mapper_pid"
