"""单独起语音播报节点（正常情况下它跟着 core_2026/dog_web.launch.py 一起起）。

    ros2 launch rl_briefing briefing_player.launch.py
    ros2 launch rl_briefing briefing_player.launch.py device:=dmix:CARD=realtekrt5616co,DEV=0

参数（都是从原版移植后按大脑的情况改过默认值的）：
  audio_dir     wav 放哪。默认 ~/briefing_audio（不在包里 —— 音频是可替换的资源，
                不该跟代码一起版本化）
  device        ALSA 设备。默认 default = 板上 codec（RT5616）。原版写死的是小脑上的
                USB 声卡 plughw:3,0，那块卡现在不在了。
                设备名可以用 `aplay -L` 看：
                  plughw:CARD=realtekrt5616co,DEV=0   直连硬件（带软件转换，最稳）
                  dmix:CARD=realtekrt5616co,DEV=0     允许和其它声音混着播
                  default                             系统默认
  sample_rate   输出采样率，默认 48000（wav 是多少都行，节点内部会做线性重采样）
  channels      输出声道数，默认 2

  enable_asr    同时起离线语音转写节点 asr_node（默认 false）。ASR 只听不控，
                转写结果发 /rl_asr/text + /rl_asr/partial，状态发 /rl_asr/status。
                常驻 ASR 由 jxg-asr.service 负责；只有没装服务时才需要传 true。
  asr_model     Vosk 模型目录，默认 ~/asr_models/vosk-model-small-cn-0.22
  asr_device    ALSA 采集设备，默认与播放同一块 A311（它自带麦克风）
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    args = [
        DeclareLaunchArgument('audio_dir', default_value='/home/jinjiao/briefing_audio',
                              description='交底 wav 所在目录'),
        DeclareLaunchArgument('device', default_value='plughw:CARD=A311,DEV=0',
                              description='ALSA 播放设备。默认=机器人喇叭那块 USB 声卡'
                                          '（Yundea A31-1）；用卡名而不是卡号，插拔别的 USB 不会走样'),
        DeclareLaunchArgument('sample_rate', default_value='48000'),
        DeclareLaunchArgument('channels', default_value='2'),
        DeclareLaunchArgument('enable_asr', default_value='false',
                              choices=['true', 'false'],
                              description='同时起离线语音转写节点；常驻由 jxg-asr.service 负责'),
        DeclareLaunchArgument('asr_model',
                              default_value='/home/jinjiao/asr_models/vosk-model-small-cn-0.22'),
        DeclareLaunchArgument('asr_device', default_value='plughw:CARD=A311,DEV=0',
                              description='麦克风采集设备（A311 自带麦克风）'),
    ]

    player = Node(
        package='rl_briefing',
        executable='briefing_player',
        name='briefing_player',
        output='screen',
        parameters=[{
            'audio_dir': LaunchConfiguration('audio_dir'),
            'device': LaunchConfiguration('device'),
            'sample_rate': LaunchConfiguration('sample_rate'),
            'channels': LaunchConfiguration('channels'),
        }],
    )

    asr = Node(
        package='rl_briefing',
        executable='asr_node.py',
        name='asr_node',
        output='screen',
        condition=IfCondition(LaunchConfiguration('enable_asr')),
        parameters=[{
            'model_path': LaunchConfiguration('asr_model'),
            'device': LaunchConfiguration('asr_device'),
            'auto_start': True,
        }],
    )

    return LaunchDescription(args + [player, asr])
