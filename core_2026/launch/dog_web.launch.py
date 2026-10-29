"""网页驱动模式起 dog_node：等 /dog/mission 上的任务，按 JSON 一步步执行。

    ros2 launch core_2026 dog_web.launch.py

**为什么 dog_node 不在 slam_only.launch.py 里**：那套是"链路"（雷达/SLAM/桥/网页入口），
而起 dog_node 会让狗在预检通过后站起来 —— 这必须是**一次明确的手动动作**，不能跟着链路
一起被拉起来。这个 launch 就是那个手动动作，只是把参数固定成网页模式。

两个参数的含义（**别随手改**）：
  wait_for_mission:=true        起来后不跑固定流程，等网页下发任务；预检（自检/起立）
                                变成任务里的步骤，操作员在网页上看得见、可编排。
  confirm_transitions:=false    关掉**终端**回车闸门 —— 不是拆掉闸门，是**换成网页闸门**：
                                任务 JSON 的 confirm 字段（默认 "each"）会让狗在每个危险
                                步骤前停下，等网页点「继续/放弃」。不关的话，launch 拉起时
                                stdin 不是终端，wait_for_enter 会按安全策略直接中止。

想回到"固定流程 + 终端回车确认"，直接 ros2 run（不带这些参数）即可，行为一字未变：
    ~/rosrun.sh 'ros2 run core_2026 dog_node --ros-args -p forward_duration_s:=0.0'

⚠️ 这里用 `arguments=[...]` 传 `-p`，**不要改成 `parameters=[{...}]`**：
launch_ros 的 `parameters=` 会生成一份**按节点名索引**的参数文件（这里是 `dog_node`），
而实际声明这些参数的是同进程里的 `robot_dog_hal_node` / `dog_mission_node` —— 名字对不上，
参数会**静默不生效**（最危险的是 confirm_transitions 没传进去，闸门还开着）。
命令行 `-p` 是本板验证过的路子（手动 `ros2 run ... -p forward_duration_s:=0.0` 一直这么用）。
"""

import importlib.util
from pathlib import Path
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction, RegisterEventHandler, LogInfo
from launch.event_handlers import OnProcessExit
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def _config_module():
    path = Path(get_package_share_directory('core_2026')) / 'safety_config.py'
    spec = importlib.util.spec_from_file_location('dog_safety_config', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def _start(context):
    module = _config_module()
    data = module.startup()
    override = LaunchConfiguration('safety_mode').perform(context)
    if override:
        data['config']['mode'] = override
        data = module.document(data['config'])
    params = module.control_parameters(data)
    # Runtime validity checks apply without an artificial calibration requirement.
    takeoff = LaunchConfiguration('enable_takeoff_getdown').perform(context).lower() == 'true'
    args = ['--ros-args', '-p', 'wait_for_mission:=true', '-p', 'confirm_transitions:=false',
            '-p', 'enable_takeoff_getdown:=' + str(takeoff).lower()]
    for name, value in params.items():
        rendered = str(value).lower() if isinstance(value, bool) else str(value)
        args.extend(['-p', name + ':=' + rendered])
    dog_node = Node(
        package='core_2026',
        executable='dog_node',
        name='dog_node',
        output='screen',
        emulate_tty=True,
        additional_env={"RMW_IMPLEMENTATION": "rmw_cyclonedds_cpp"},
        arguments=args,
    )
    bridge = Node(package='core_2026', executable='drone_preset_bridge.py',
                  name='drone_preset_bridge', output='screen',
                  additional_env={"RMW_IMPLEMENTATION":"rmw_cyclonedds_cpp"})
    # 交底随任务程序启动，与 SLAM/定位是否就绪无关。
    briefing = Node(package='rl_briefing', executable='briefing_player',
                    name='briefing_player', output='screen',
                    additional_env={"RMW_IMPLEMENTATION": "rmw_cyclonedds_cpp"},
                    parameters=[{'audio_dir': LaunchConfiguration('audio_dir'),
                                 'device': LaunchConfiguration('audio_device')}])
    actions = [dog_node, bridge, briefing]
    if takeoff:
        receiver = Node(package='core_2026', executable='start_takeoff_receiver.sh',
                        name='takeoff_thrust_process', output='screen',
                        arguments=['--enable-actions'])
        # Never tear down active dog control merely because telemetry failed.
        actions.extend([RegisterEventHandler(OnProcessExit(
            target_action=receiver, on_exit=[LogInfo(msg=
                'ERROR: 推力监听已退出，自动趴下联动不可用；请检查日志，不会自动重启/重放事件。')])), receiver])
    return actions


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument('audio_dir', default_value='/home/jinjiao/briefing_audio',
                              description='交底 WAV 目录'),
        DeclareLaunchArgument('audio_device', default_value='plughw:CARD=A311,DEV=0',
                              description='交底 ALSA 播放设备'),
        DeclareLaunchArgument('enable_takeoff_getdown', default_value='true',
                              choices=['true', 'false'],
                              description='起飞推力>=0.43时联动趴下；随dog启动监听'),
        DeclareLaunchArgument('safety_mode', default_value='',
                              choices=['', 'disabled', 'observe', 'enforce'],
                              description='留空加载已保存配置；disabled/observe 无碰撞保护'),
        OpaqueFunction(function=_start),
    ])
