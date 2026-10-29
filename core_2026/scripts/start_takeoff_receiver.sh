#!/usr/bin/env bash
set -e
ROOT=$(cd "$(dirname "$0")" && pwd)
export MAMBA_ROOT_PREFIX="$HOME/micromamba"
exec "$HOME/.local/bin/micromamba" run -n ros bash --noprofile --norc -c '
source "$HOME/ros2_ws/install/setup.bash"
export RMW_IMPLEMENTATION=rmw_fastrtps_cpp ROS_LOCALHOST_ONLY=0
exec python3 "$1/takeoff_thrust_receiver.py" "${@:2}"
' bash "$ROOT" "$@"
