import os
from launch import LaunchDescription
from launch.actions import TimerAction, IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch.substitutions import PathJoinSubstitution, LaunchConfiguration
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    real_robot_odom_topic = LaunchConfiguration('real_robot_odom_topic')

    # ── LiDAR 驱动 (Livox MID360) ────────────────────────
    livox_ros_driver = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            os.path.join(get_package_share_directory('livox_ros_driver2'),
                         'launch_ROS2', 'msg_MID360_launch.py')
        ])
    )

    # ── 静态 TF (base_link → livox_frame) ────────────────
    tf = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        name="base_to_livox_tf",
        arguments=["0", "0", "0", "0", "0", "0", "1", "base_link", "livox_frame"]
    )

    # ── PointLIO SLAM (延迟5s等LiDAR就绪) ────────────────
    slam = TimerAction(
        period=5.0,
        actions=[
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource([
                    PathJoinSubstitution([
                        FindPackageShare("point_lio"),
                        "launch",
                        "point_lio.launch.py"
                    ])
                ]),
                launch_arguments={"rviz": "False"}.items(),
            )
        ]
    )

    # ── 里程计桥接 (PointLIO odom → LidarPose) ───────────
    lidar_data_node = Node(
        package='ros2_tools',
        executable='lidar_data_node',
        parameters=[{
            'use_simulation': False,
            'simulation_odom_topic': '/absolute_pose',
            'real_robot_odom_topic': real_robot_odom_topic
        }]
    )

    # ── 机器狗控制核心 ───────────────────────────────────
    dog_node = Node(
        package='core_2026',
        executable='dog_node',
        output='screen',
    )

    return LaunchDescription([
        DeclareLaunchArgument(
            'real_robot_odom_topic',
            default_value='/Odometry',
            description='Odometry topic from PointLIO/FastLIO.'
        ),
        livox_ros_driver,   # LiDAR 驱动
        tf,                 # TF 静态变换
        slam,               # PointLIO SLAM (延迟5s)
        lidar_data_node,    # 里程计 → LidarPose
        dog_node,           # 机器狗控制
    ])
