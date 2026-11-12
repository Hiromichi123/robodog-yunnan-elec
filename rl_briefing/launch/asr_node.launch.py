"""单独起离线语音转写节点（平时跟着 rl_briefing/briefing_player.launch.py
或 core_2026/dog_web.launch.py 一起起；调试时用这个）。

    ros2 launch rl_briefing asr_node.launch.py
    ros2 launch rl_briefing asr_node.launch.py device:=plughw:CARD=A311,DEV=0
    ros2 launch rl_briefing asr_node.launch.py auto_start:=false

话题：
  /rl_asr/control  start | stop | status
  /rl_asr/text     一句话最终转写
  /rl_asr/partial  实时中间结果
  /rl_asr/status   listening | stopped | error: <原因>（0.5s 心跳）

依赖：ros 环境里要装 vosk（pip install vosk），模型目录见 model_path。
"""
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            'model_path',
            default_value='/home/jinjiao/asr_models/vosk-model-small-cn-0.22',
            description='Vosk 模型目录（不含包的资源，默认 ~/asr_models）'),
        DeclareLaunchArgument(
            'device', default_value='plughw:CARD=A311,DEV=0',
            description='ALSA 采集设备；A311 是机器人喇叭那块 USB 声卡，自带麦克风'),
        DeclareLaunchArgument('sample_rate', default_value='16000'),
        DeclareLaunchArgument('auto_start', default_value='true',
                              choices=['true', 'false']),
        DeclareLaunchArgument('min_text_chars', default_value='2',
                              description='最终结果短于该字数不发（过滤环境噪声单字）'),
        Node(
            package='rl_briefing',
            executable='asr_node.py',
            name='asr_node',
            output='screen',
            parameters=[{
                'model_path': LaunchConfiguration('model_path'),
                'device': LaunchConfiguration('device'),
                'sample_rate': LaunchConfiguration('sample_rate'),
                'auto_start': LaunchConfiguration('auto_start'),
                'min_text_chars': LaunchConfiguration('min_text_chars'),
            }],
        ),
    ])
