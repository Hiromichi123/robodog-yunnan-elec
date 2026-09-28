"""起「链路」：雷达 + SLAM + 小脑桥，**不起 dog_node**。

为什么桥放进来、dog_node 不放：
    桥只是转发（WebSocket ↔ /rl_real/*），没有任何运动风险；但漏起它会很坑 ——
    /rl_real/* 整套话题根本不存在，dog_node 发出去的命令没有订阅者，只能白等
    5s 超时（2026-09-28 实测踩过）。所以把它和链路绑在一起，少一个会忘的步骤。
    dog_node 不一样：一过预检就让狗站起来，必须是**一次明确的手动动作**，
    所以仍单独起。保留 `slam_only` 这个名字就是因为这个区分还在。

起了什么:
    1. livox_ros_driver2   雷达驱动。**必须 xfer_format=1**（CustomMsg）——
                           Point-LIO 在 lidar_type=1 时订阅的是 CustomMsg，
                           而官方 msg_MID360_launch.py 硬编码 xfer_format=0 发
                           PointCloud2，两边对不上会一个点都收不到。
                           那份 launch 不接受参数（是硬编码变量，没有
                           DeclareLaunchArgument），所以这里直接起节点。
    2. static TF ×2        base_link → livox_frame / body，即雷达安装变换
                           （朝前下方 45°、杆臂正前 0.3m）
    3. Point-LIO           激光惯性里程计，延迟 5s 等雷达就绪
    4. lidar_data_node     里程计 → /lidar_data，并把位姿从雷达系换算到车体系
    5. dog_ws_bridge       小脑 WebSocket(:8088) ↔ /rl_real/* 的桥。
                           **dog_node 必须等它起来**，否则 /rl_real/command 等
                           话题不存在，命令发出去没有订阅者。

没起什么:
    dog_node —— 确认 /lidar_data 有数据、且日志出现「已连上小脑 WebSocket」后，
    再单独起：
        ros2 run core_2026 dog_node --ros-args -p forward_duration_s:=0.0
    （forward_duration_s:=0.0 表示只起立→进RL→趴下，不产生位移）

用法:
    ros2 launch core_2026 slam_only.launch.py
    ros2 launch core_2026 slam_only.launch.py rviz:=true
    ros2 launch core_2026 slam_only.launch.py real_robot_odom_topic:=/Odometry
    ros2 launch core_2026 slam_only.launch.py url:=ws://192.168.8.236:8088/ws
"""

import os

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    # 雷达安装变换：**前向倒装 45°**、杆臂正前 0.3m。
    # 四元数 (0, -0.923880, 0, 0.382683) = 绕 y 轴 −135°（= 180° + 45°），
    # 即雷达的 +x 指向 base_link 的**后上方** 45°。
    # 依据：静止时原始 Point-LIO 姿态反推为绕 y ≈ −139.3°，与 −135° 逐项吻合；
    # "绕y+45°再绕z/x 180°"两种组合都会退化成万向锁，与实测不符。
    mount_xyz_rpy = ["0.3", "0", "0", "0", "-0.923880", "0", "0.382683"]

    default_livox_config = os.path.expanduser(
        os.environ.get('MID360_CONFIG', '~/ros2_ws/config/MID360_config.json'))

    decls = [
        DeclareLaunchArgument(
            'livox_config', default_value=default_livox_config,
            description='MID360 网络配置（host_ip / 雷达 IP）'),
        DeclareLaunchArgument(
            'real_robot_odom_topic', default_value='/aft_mapped_to_init',
            description='Point-LIO 的里程计话题。注意 dock 里有文档默认写 /Odometry，'
                        '但 Point-LIO 实际发的是 /aft_mapped_to_init'),
        DeclareLaunchArgument(
            'slam_delay_s', default_value='5.0',
            description='Point-LIO 延迟启动秒数，等雷达驱动就绪'),
        DeclareLaunchArgument(
            'rviz', default_value='false', description='是否开 rviz'),
        # ── 传给小脑桥（dog_ws_bridge）的参数 ──
        DeclareLaunchArgument(
            'url', default_value='ws://192.168.8.236:8088/ws',
            description='小脑 WebSocket 地址'),
        DeclareLaunchArgument(
            'status_poll_hz', default_value='2.0',
            description='桥轮询 FSM 状态的频率；dog_node 的前置判断靠它刷新'),
    ]

    # ── 1. 雷达驱动（xfer_format=1）──────────────────────────────────
    livox_driver = Node(
        package='livox_ros_driver2',
        executable='livox_ros_driver2_node',
        name='livox_lidar_publisher',
        output='screen',
        parameters=[{
            'xfer_format': 1,            # 1 = CustomMsg（Point-LIO 要的格式）
            'multi_topic': 0,
            'data_src': 0,
            'publish_freq': 10.0,
            'output_data_type': 0,
            'frame_id': 'livox_frame',
            'user_config_path': LaunchConfiguration('livox_config'),
            'cmdline_input_bd_code': 'livox0000000001',
        }],
    )

    # ── 2. 安装变换（静态 TF）────────────────────────────────────────
    tf_livox = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='base_to_livox_tf',
        arguments=mount_xyz_rpy + ['base_link', 'livox_frame'],
    )
    # Point-LIO 的 odom.child_frame_id 就是 "body"，与 livox_frame 同体同朝向。
    # 这里也挂到 base_link 下，免得 TF 树里出现悬空帧。
    tf_body = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='base_to_body_tf',
        arguments=mount_xyz_rpy + ['base_link', 'body'],
    )

    # ── 3. Point-LIO（延迟等雷达）───────────────────────────────────
    slam = TimerAction(
        period=LaunchConfiguration('slam_delay_s'),
        actions=[
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource([
                    PathJoinSubstitution([
                        FindPackageShare('point_lio'), 'launch', 'point_lio.launch.py'
                    ])
                ]),
                launch_arguments={
                    'rviz': LaunchConfiguration('rviz'),
                }.items(),
            )
        ],
    )

    # ── 4. 里程计 → /lidar_data（含安装变换换算到车体系）─────────────
    lidar_data_node = Node(
        package='ros2_tools',
        executable='lidar_data_node',
        output='screen',
        parameters=[{
            'use_simulation': False,
            'simulation_odom_topic': '/absolute_pose',
            'real_robot_odom_topic': LaunchConfiguration('real_robot_odom_topic'),
            # 安装变换参数（默认就是实机装法，见 lidar_data_node.cpp 注释）
            'apply_mount_transform': True,
            'mount_x': 0.3, 'mount_y': 0.0, 'mount_z': 0.0,
            # 前向倒装 45° = 绕 y 轴 −135°（−2.356194 rad）
            'mount_roll': 0.0, 'mount_pitch': -2.356194, 'mount_yaw': 0.0,
        }],
    )

    # ── 5. 小脑桥 ────────────────────────────────────────────────────
    # 直接 include 桥自己的 launch，桥的参数只在那一处维护，避免两边漂移。
    # 它立刻起（不延迟）：dog_node 是人工在之后单独起的，顺序天然满足。
    bridge = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('dog_ws_bridge'), 'launch', 'dog_bridge.launch.py'
            ])
        ]),
        launch_arguments={
            'url': LaunchConfiguration('url'),
            'status_poll_hz': LaunchConfiguration('status_poll_hz'),
        }.items(),
    )

    return LaunchDescription(decls + [
        livox_driver,
        tf_livox,
        tf_body,
        slam,
        lidar_data_node,
        bridge,
    ])
