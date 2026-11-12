#!/bin/bash
# Independent MID360 driver; never started or stopped by the SLAM switch.
set -eu
export HOME="${HOME:-/home/jinjiao}"
if [ "${1:-}" != --inner ]; then
 exec 8>"$HOME/.jxg-lidar.lock"
 flock -n 8 || { echo 'MID360 driver is already running.' >&2; exit 1; }
 exec "$HOME/rosrun.sh" 'bash "$HOME/lidar_driver_run.sh" --inner'
fi
python "$HOME/pointlio_local/check_lidar_input.py"
if pgrep -f '[/]livox_ros_driver2_node' >/dev/null; then
 echo 'Another MID360 driver exists; refusing to bind the same UDP ports.' >&2
 exit 1
fi
exec "$HOME/ros2_ws/install/lib/livox_ros_driver2/livox_ros_driver2_node" --ros-args  -p xfer_format:=1 -p multi_topic:=0 -p data_src:=0 -p publish_freq:=10.0  -p output_data_type:=0 -p frame_id:=livox_frame  -p user_config_path:="$HOME/ros2_ws/config/MID360_config.json"  -p cmdline_input_bd_code:=livox0000000001
