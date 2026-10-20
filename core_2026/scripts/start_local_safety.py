#!/usr/bin/env python3
"""Owned LiDAR-only safety perception for Point-LIO; no camera, depth or motion bridge."""
import argparse
import importlib.util
import os
from pathlib import Path
import signal
import subprocess
import sys
import time


def configuration():
    here = Path(__file__).resolve()
    path = here.parent / 'safety_config.py'
    if not path.is_file():
        path = here.parents[2] / 'share/core_2026/safety_config.py'
    spec = importlib.util.spec_from_file_location('safety_startup_config', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def prepare_snapshot(module):
    existing = os.environ.get('ROBODOG_SAFETY_SNAPSHOT')
    if existing:
        module.load(existing, missing_ok=False, allow_legacy=False)
        return Path(existing).resolve()
    path, _ = module.freeze(Path.home() / '.config/robodog/startup-snapshots')
    return path.resolve()


def parameter_args(parameters):
    args = ['--ros-args']
    for name, value in parameters.items():
        value = str(value).lower() if isinstance(value, bool) else str(value)
        args.extend(['-p', name + ':=' + value])
    return args


class OwnedProcesses:
    def __init__(self, spawn=subprocess.Popen):
        self.children = []
        self.spawn = spawn

    def start(self, args):
        # No setsid: children remain members of the existing navigation process group.
        child = self.spawn(args, stdin=subprocess.DEVNULL)
        self.children.append(child)
        return child

    def check(self):
        for child in self.children:
            code = child.poll()
            if code is not None:
                raise RuntimeError(f'安全感知子进程已退出 ({code}): {child.args[0]}')

    def close(self):
        for child in self.children:
            if child.poll() is None:
                child.send_signal(signal.SIGINT)
        deadline = time.monotonic() + 1.0
        for child in self.children:
            try:
                child.wait(timeout=max(.01, deadline - time.monotonic()))
            except subprocess.TimeoutExpired:
                child.terminate()
        for child in self.children:
            try:
                child.wait(timeout=.3)
            except subprocess.TimeoutExpired:
                child.kill()
                child.wait(timeout=.3)


def run(module, data):
    if data['config']['mode'] == 'disabled':
        return 0
    import rclpy
    from ament_index_python.packages import get_package_prefix

    stop = False
    def interrupted(signum, frame):
        nonlocal stop
        stop = True
    # rclpy must not replace our handler: cleanup owns only the children we spawn.
    from rclpy.signals import SignalHandlerOptions
    rclpy.init(signal_handler_options=SignalHandlerOptions.NO)
    signal.signal(signal.SIGINT, interrupted)
    signal.signal(signal.SIGTERM, interrupted)
    node = rclpy.create_node('local_safety_dependencies')
    owned = OwnedProcesses()
    try:
        # Discover an existing publisher before starting our one owned perception process.
        deadline = time.monotonic() + 3.0
        while not stop and time.monotonic() < deadline:
            rclpy.spin_once(node, timeout_sec=.1)
        if stop:
            return 0
        if node.count_publishers('/local_safety/map'):
            raise RuntimeError('已有外部安全地图发布者，拒绝启动第二份；请在原入口管理')
        executable = str(Path(get_package_prefix('ros2_tools')) / 'lib/ros2_tools/local_obstacle_node')
        owned.start([executable, *parameter_args(module.perception_parameters(data))])
        print('雷达单源安全感知已启动；无人工标定门禁，仍以实时数据和足迹检查决定运动放行。', flush=True)
        while not stop and rclpy.ok():
            rclpy.spin_once(node, timeout_sec=.1)
            owned.check()
            if node.count_publishers('/local_safety/map') > 1:
                raise RuntimeError('检测到重复安全地图发布者，停止本入口感知；不终止外部进程')
        return 0
    finally:
        owned.close()
        node.destroy_node()
        rclpy.shutdown()


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    actions = parser.add_mutually_exclusive_group()
    actions.add_argument('--prepare', action='store_true', help='Freeze/verify startup configuration, print path only')
    actions.add_argument('--mode', action='store_true', help='Print frozen mode without starting ROS')
    args = parser.parse_args(argv)
    module = configuration()
    if args.prepare:
        print(prepare_snapshot(module))
        return 0
    # Direct helper invocation must not accidentally consume a mutable live configuration.
    if not os.environ.get('ROBODOG_SAFETY_SNAPSHOT'):
        raise RuntimeError('缺少 ROBODOG_SAFETY_SNAPSHOT；请从 Point-LIO 启动入口运行')
    data = module.startup()
    if args.mode:
        print(data['config']['mode'])
        return 0
    return run(module, data)


if __name__ == '__main__':
    try:
        sys.exit(main())
    except (OSError, ValueError, RuntimeError, ImportError) as exc:
        print('安全感知启动失败: ' + str(exc), file=sys.stderr, flush=True)
        sys.exit(1)
