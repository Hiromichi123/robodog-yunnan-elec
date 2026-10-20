"""Browser ROS transport only; no sensors, robot HAL or mission executor."""
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, SetEnvironmentVariable
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    return LaunchDescription([
        SetEnvironmentVariable('RMW_IMPLEMENTATION', 'rmw_cyclonedds_cpp'),
        DeclareLaunchArgument('port', default_value='9090'),
        DeclareLaunchArgument('address', default_value='0.0.0.0'),
        IncludeLaunchDescription(
            AnyLaunchDescriptionSource(PathJoinSubstitution([
                FindPackageShare('rosbridge_server'), 'launch', 'rosbridge_websocket_launch.xml'])),
            launch_arguments={'port': LaunchConfiguration('port'),
                              'address': LaunchConfiguration('address')}.items()),
    ])
