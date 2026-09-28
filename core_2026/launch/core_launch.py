import os
import launch
from launch import LaunchDescription
from launch.actions import TimerAction, IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch.substitutions import PathJoinSubstitution, LaunchConfiguration
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    real_robot_odom_topic = LaunchConfiguration('real_robot_odom_topic')

    mavros = Node(
        package='mavros',
        executable='mavros_node',
        parameters=[{
            'fcu_url': 'serial:///dev/ttyACM0:57600',
            'tgt_system': 1,
            'tgt_component': 1,
            'fcu_protocol': 'v2.0'
        }]
    )

    livox_ros_driver = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            os.path.join(get_package_share_directory('livox_ros_driver2'), 'launch_ROS2', 'msg_MID360_launch.py')
        ])
    )

    tf = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        name="base_to_livox_tf",
            # 雷达安装变换：**前向倒装 45°**、杆臂正前 0.3m。
    # 四元数 (0, -0.923880, 0, 0.382683) = 绕 y 轴 −135°（= 180° + 45°）。
    # 注意：这只影响 TF 树；位姿的实质修正见 ros2_tools/lidar_data_node.cpp。
        arguments=["0.3", "0", "0", "0", "-0.923880", "0", "0.382683", "base_link", "livox_frame"]
    )

    # Point-LIO 的 odom.child_frame_id 是 "body"，实机上与 livox_frame 同体同朝向，
    # 这里把它也挂到 base_link 下，避免 TF 树里出现悬空帧。
    tf_body = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        name="base_to_body_tf",
        arguments=["0.3", "0", "0", "0", "-0.923880", "0", "0.382683", "base_link", "body"]
    )

    slam = TimerAction(
        period=5.0,  # 延迟 10s 启动 PointLIO
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
    
    ros2_tools_nodes = [
        Node(package='ros2_tools', 
             executable='lidar_data_node',
             parameters=[{
                'use_simulation': False, # 仿真开关
                'simulation_odom_topic': '/absolute_pose', # gazebo的里程计话题
                'real_robot_odom_topic': real_robot_odom_topic # PointLIO/FastLIO的里程计话题
             }]),
        Node(
            package='ros2_tools',
            executable='lidar_to_px4_bridge',
            parameters=[{
                'real_robot_odom_topic': real_robot_odom_topic,
                'vision_pose_topic': '/mavros/vision_pose/pose'
            }]
        )
    ]

    core = Node(
        package='core_2026',
        executable='quad_node',
    )

    return launch.LaunchDescription([
        DeclareLaunchArgument(
            'real_robot_odom_topic',
            default_value='/Odometry',
            description='Odometry topic from PointLIO/FastLIO, for lidar_data_node and lidar_to_px4_bridge.'
        ),
        mavros,             # ros2 run mavros mavros_node --ros-args -p fcu_url:=serial:///dev/ttyACM0:57600 -p tgt_system:=1 -p tgt_component:=1 -p fcu_protocol:=v2.0
        livox_ros_driver,   # ros2 launch livox_ros_driver2 msg_MID360_launch.py
        tf,                 # 安装变换: 0.3 0 0  0 -0.923880 0 0.382683  base_link livox_frame
        tf_body,            # 同上，挂在 body 上（Point-LIO odom 的 child_frame_id）
        slam,               # ros2 launch point_lio point_lio.launch.py rviz:=False
        *ros2_tools_nodes,  # ros2 run ros2_tools lidar_data_node --ros-args -p use_simulation:=False -p simulation_odom_topic:=/absolute_pose -p real_robot_odom_topic:=/aft_mapped_to_init
                            # ros2 run ros2_tools lidar_to_px4_bridge
        core                # ros2 run core_2026 quad_node
    ])
