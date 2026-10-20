#!/bin/bash
# Default navigation. Reconstruction is an explicit opt-in.
set -eu
export RECONSTRUCTION=0 SLAM_MAPPING=0
for option in "$@"; do
 case "$option" in
  --navigation) export RECONSTRUCTION=0 ;;
  --reconstruction) export RECONSTRUCTION=1 ;;
  --slam-mapping) export SLAM_MAPPING=1 ;;
  *) echo 'Usage: pointlio_run.sh [--navigation|--reconstruction] [--slam-mapping]' >&2; exit 2 ;;
 esac
done
exec 9>"$HOME/.fastlivo.lock"
flock -n 9 || { echo 'A SLAM stack is already running.' >&2; exit 1; }
# Freeze once before any sensor is started; Web already supplies its owned snapshot.
ROBODOG_SAFETY_SNAPSHOT=$(python3 "$HOME/ros2_ws/install/lib/core_2026/start_local_safety.py" --prepare)
export ROBODOG_SAFETY_SNAPSHOT
export MAMBA_ROOT_PREFIX="${MAMBA_ROOT_PREFIX:-$HOME/micromamba}"
exec "$HOME/.local/bin/micromamba" run -n ros bash -c \
 'source "$HOME/ros2_ws/install/setup.bash" && source "$HOME/fastlivo_ws/install/setup.bash" && exec bash "$HOME/pointlio_inner.sh"'
