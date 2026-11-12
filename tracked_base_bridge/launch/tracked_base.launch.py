from pathlib import Path
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    config = str(Path(get_package_share_directory('tracked_base_bridge')) / 'config/tracked_base.yaml')
    return LaunchDescription([
        DeclareLaunchArgument('config', default_value=config),
        Node(package='tracked_base_bridge', executable='tracked_base_bridge',
             namespace='tracked_base', name='tracked_base_bridge', output='screen',
             parameters=[LaunchConfiguration('config')]),
    ])
