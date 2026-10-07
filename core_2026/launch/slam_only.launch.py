"""起「链路」：雷达 + SLAM + 小脑桥 + web 地面站入口，**不起 dog_node**。

为什么桥放进来、dog_node 不放：
    桥只做通信适配，没有任何运动风险；但漏起它会很坑 —— dog_node 的命令与
    预检依赖它（旧桥时代 /rl_real/* 话题根本不存在；新协议下则缺 feedback 的
    state= 文本），只能白等 5s 超时（2026-09-28 实测踩过）。所以把它和链路
    绑在一起，少一个会忘的步骤。
    dog_node 不一样：一过预检就让狗站起来，必须是**一次明确的手动动作**，
    所以仍单独起。保留 `slam_only` 这个名字就是因为这个区分还在。
    同理并入的还有 6/7 两项（rosbridge + 建图录制）—— 也都是零运动风险，
    漏起的表现都是「网页上点了没反应」这种很难一眼看出原因的毛病。

起了什么:
    1. livox_ros_driver2   雷达驱动。**必须 xfer_format=1**（CustomMsg）——
                           Point-LIO 在 lidar_type=1 时订阅的是 CustomMsg，
                           而官方 msg_MID360_launch.py 硬编码 xfer_format=0 发
                           PointCloud2，两边对不上会一个点都收不到。
                           那份 launch 不接受参数（是硬编码变量，没有
                           DeclareLaunchArgument），所以这里直接起节点。
    2. static TF ×4        base_link → livox_frame / body / camera_link
                           → camera_camera_rgb（彩色光学系），
                           即雷达与**彩色相机**的安装变换。
                           雷达：前向倒装 45°、杆臂正前 0.286m（实测 286mm）。
                           相机：机器人正前方、相对**车体** x+40mm z+95mm
                           （所以相对 base_link 是 0.286+0.040=0.326、z=0.095）。
    3. Point-LIO           激光惯性里程计，延迟 5s 等雷达就绪。
                           **它必须发 `scan_bodyframe_pub_en`（mid360.yaml 里已开）**
                           —— 第 7 项的建图点云取自 /cloud_registered_body；
                           那个话题不开，建图开关按下去就没数据。
    4. lidar_data_node     里程计 → /lidar_data，并把位姿从雷达系换算到车体系
    5. dog_ros2_bridge     ROS2 原生协议适配层（bridge:=ros2，默认）。
                           小脑 v4 已把 /rl_real/* 整套协议原生搬上 ROS2
                           （含 cmd_state 生命周期与 2Hz heartbeat），DDS 直连；
                           本层只补三件事：2Hz status 轮询（dog_node 预检要的
                           feedback state= 文本）、heartbeat_alive 派生、
                           cmd_vel 断流补零。**dog_node 必须等它起来。**
                           bridge:=ws 回退旧 WebSocket 桥（已弃用）；
                           bridge:=none 不起（调试）；两个桥不能同起。
    6. rosbridge_websocket 浏览器进 ROS 的入口（:9090）。网页 ~/web 靠它连上来
                           （由 ~/webserver.sh 起静态服务，浏览器开
                            http://192.168.8.137:8080/，ROS 地址填
                            ws://192.168.8.137:9090）。
    6b. stereo_points      双目点云（仅 map_source:=camera）。
                           订左右红外 + 彩色，SGBM 算视差 → 深度 → 彩色点云，
                           发 /camera/camera/depth/color/points。
    7. lidar_recorder      点云 → 网页的唯一点云出口 + 建图落盘。
                           **几何源由 map_source 决定**，两条路线各一份 Node：
                           camera(默认) 订 /camera/camera/depth/color/points
                             （帧 camera_camera_left，先搬到 body 再乘位姿；
                              点云自带颜色，关掉上色那一遍）
                           lidar(旧) 订 /cloud_registered_body（body 系、IMU 去畸变、
                             只经过 point_filter_num 抽稀），用彩色相机投影补色。
                             **不要改成订 /cloud_registered**：那份是
                             feats_down_world，被 filter_size_surf=0.5 的体素
                             降采样过，一面 10m 的墙只剩约 20 个点（差 ~20 倍）。
                           两条路线都再用 /aft_mapped_to_init 乘一次位姿到世界系。
                           **2026-10-07 换成相机路线的原因**：旧路线要求相机-雷达
                           外参准确，而外参只能靠标定/假设 —— 折腾一轮标定后结论是
                           数据分辨不出更好的外参。相机路线几何与颜色**同源**，
                           整个外参问题不存在；代价是几何精度掉到厘米级
                           （3.5m 处 ±0.2m），且被动双目在无纹理面上没有深度
                           （白墙/亮地面/天花板）。
                           网页上「开始建图」打开时把每帧（变换后的）转发给浏览器，
                           同时按体素去重（相机 0.02m / 雷达 0.01m）累积，
                           关闭时写成单张 pcd
                           （~/lidar_maps/map_<时间戳>.pcd + 同名 .json 边车，
                           pcd 带 rgb 字段）。

没起什么:
    dog_node —— 确认 /lidar_data 有数据、且日志出现「已连上小脑 WebSocket」后，
    再单独起：
        ros2 run core_2026 dog_node --ros-args -p forward_duration_s:=0.0
    （forward_duration_s:=0.0 表示只起立→进RL→趴下，不产生位移）

用法:
    ros2 launch core_2026 slam_only.launch.py
    ros2 launch core_2026 slam_only.launch.py rviz:=true
    ros2 launch core_2026 slam_only.launch.py real_robot_odom_topic:=/Odometry
    ros2 launch core_2026 slam_only.launch.py bridge:=ws    # 回退旧 WebSocket 桥(已弃用)
    ros2 launch core_2026 slam_only.launch.py bridge:=none  # 不起桥(调试)
    ros2 launch core_2026 slam_only.launch.py rosbridge_port:=9091 maps_dir:=/tmp/m
"""

import math
import os

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, TimerAction
from launch.conditions import LaunchConfigurationEquals
from launch.launch_description_sources import (
    AnyLaunchDescriptionSource,
    PythonLaunchDescriptionSource,
)
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def quat_from_rpy(roll, pitch, yaw):
    """RPY(弧度) → 四元数。static_transform_publisher 只吃四元数。"""
    cr, sr = math.cos(roll / 2), math.sin(roll / 2)
    cp, sp = math.cos(pitch / 2), math.sin(pitch / 2)
    cy, sy = math.cos(yaw / 2), math.sin(yaw / 2)
    return (sr * cp * cy - cr * sp * sy,
            cr * sp * cy + sr * cp * sy,
            cr * cp * sy - sr * sp * cy,
            cr * cp * cy + sr * sp * sy)


def generate_launch_description():
    # 雷达安装变换：**前向倒装 45°**、杆臂正前 0.286m（实测 286mm）。
    # 四元数 (0.923880, 0, 0.382683, 0) = rpy(roll=0, pitch=−135°, yaw=π)，
    # 即：绕 y 轴 −135°（前向倒装 45°）**再绕 base_link z 加 180°**。
    #
    # ⚠️ 2026-10-06 补上的那个 π（原来是 (0,-0.923880,0,0.382683) = 只有 Ry(−135°)）：
    # 当年这个 mount 是从「静止时原始 Point-LIO 姿态反推」定的，而 camera_init 的
    # 世界系 yaw 是启动时任意的 —— 那步把 yaw 假设成 0 是循环论证，**yaw 根本测不出来**
    # （雷达自己看不见绕 z 的安装角）。2026-10-05 goto 跑反现场定下真正差的是 180° yaw，
    # 当时只改了位姿那一路（lidar_data_node 的 mount_yaw=3.141593），TF 这一路留了待办。
    # 现在对齐。**两路的 rpy 必须一致**：lidar_data_node 那套是 rpy(0,−135°,180°)。
    #
    # 为什么必须补：不补的话相机光轴在雷达 body 系里落到「方位 180°、俯仰 −45°」，
    # 正好是雷达被遮挡的那个空洞（实测 body 系方位 100°~240° 全空、260°~80° 才有
    # −5°~+55° 的覆盖）—— 网页/录制的彩色上色会几乎一个点都命中不了，只有贴地点勉强有色。
    # 补上之后光轴落到「方位 0°、俯仰 +45°」，正落在覆盖区里。
    mount_xyz_rpy = ["0.286", "0", "0", "0.923880", "0", "0.382683", "0"]

    # 彩色相机：装在机器人正前方、竖直；相对**车体**偏移 x+40mm、z+95mm。
    # 注意是相对车体（base_link）量的，不是相对雷达 —— 杆臂 0.286 才是雷达的位置，
    # 所以相机在 base_link 下是 (0.286+0.040, 0, 0.095) = (0.326, 0, 0.095)。
    # **旋转还没标定**：先留单位四元数。定它的办法是让相机点云和雷达地图对着看
    # （地面平面、墙面法向是否重合），不要凭猜。标定完改后 4 个数（qx qy qz qw），
    # 格式与上面 mount_xyz_rpy 一致：x y z qx qy qz qw。
    # lidar_recorder 是查 TF 拿变换的，所以改这一处两边都生效。
    cam_xyz_quat = ["0.326", "0", "0.095", "0", "0", "0", "1"]

    # 相机自己的 frame（相机不发 TF，得我们来接）：相机点云/图像里写的
    # frame_id 是 camera_camera_left（左目）等，取的是**光学系**约定
    # x 右 / y 下 / z 前。相对车体系就是标准的"光学→车体"旋转：
    # roll=-90°、yaw=-90°（下面用 quat_from_rpy 现算，免得手抄四元数）。
    # **这段是标定旋钮**：如果相机装得跟这个假设不一样（比如竖装多转了 90°），
    # 相机点云在图上会整体歪一个固定角度 —— 改 cam_opt_rpy 重跑即可。
    cam_opt_rpy = [-1.570796, 0.0, -1.570796]

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
        # ── /lidar_data 来源（real=真链路 / fake=假节点发 0）──
        # 互斥：两个来源同时发 /lidar_data，控制环会拿到两份互相矛盾的位姿
        # （狗无规律乱走，极难倒查）—— 和"两份 Point-LIO"是同一类坑。
        DeclareLaunchArgument(
            'lidar_source', default_value='real',
            description='/lidar_data 来源: real=Point-LIO→lidar_data_node(默认,实机) | '
                        'fake=持续发 0 的假节点(无雷达台架联调)。两者互斥，'
                        '见 ~/start_slam.sh'),
        # ── 建图几何源（map_source:=camera 默认 / lidar 回退）──
        # （2026-10-07 换向：原来是"雷达出几何 + 相机只上色"，那条路要求相机-雷达
        #   外参准确，而外参只能靠标定/假设 —— 折腾一轮标定后结论是数据分辨不出来。
        #   改成"相机自己的双目点云出几何，雷达只提供位姿"之后，几何和颜色同源，
        #   **整个外参问题就不存在了**。代价是几何精度掉到厘米级、无纹理面没有深度。）
        DeclareLaunchArgument(
            'map_source', default_value='camera',
            description='建图几何来源: camera=相机的双目彩色点云(stereo_points，默认，'
                        '雷达只给位姿) | lidar=雷达点云+相机上色(旧路线，保留以便对比/回退)'),
        # 相机路线里雷达**仍然要跑**（Point-LIO 提供世界系位姿），所以这个开关
        # 不动 lidar_source —— 两条路线都依赖 Point-LIO 的 /aft_mapped_to_init。
        DeclareLaunchArgument(
            'stereo_max_range_m', default_value='3.5',
            description='双目点云的最远距离(m)。基线和视差决定了深度误差 ≈ z²σ/30.7，'
                        '放到 8m 处误差 ±1m、点云就是一团锥形发散的雾，所以默认只到 3.5m'),
        # ── 小脑通信桥（bridge:=ros2 默认 / ws 回退 / none 不起）──
        DeclareLaunchArgument(
            'bridge', default_value='ros2',
            description='小脑通信桥: ros2=ROS2 原生协议适配层(默认) | '
                        'ws=旧 WebSocket 桥(已弃用) | none=不起'),
        # 以下 url 仅 bridge:=ws 时传给旧桥；dog_ros2_bridge 与小脑 DDS 直连，没有 url
        DeclareLaunchArgument(
            'url', default_value='ws://192.168.8.236:8088/ws',
            description='小脑 WebSocket 地址（仅 bridge:=ws 用）'),
        DeclareLaunchArgument(
            'status_poll_hz', default_value='2.0',
            description='桥轮询 FSM 状态的频率；dog_node 的前置判断靠它刷新'
                        '（两种桥都吃这个参数）'),
        # ── 传给 web 侧（rosbridge + 建图录制）的参数 ──
        DeclareLaunchArgument(
            'rosbridge_port', default_value='9090',
            description='浏览器连的 rosbridge 端口。address 留空 = 监听所有网口'),
        DeclareLaunchArgument(
            'maps_dir', default_value='~/lidar_maps',
            description='建图 pcd 的落盘目录（同名 .json 边车一起写在那里）'),
        DeclareLaunchArgument(
            'voxel_size', default_value='0.01',
            description='建图体素去重边长(m)。静止重复扫描的同一面墙只留一个点；'
                        '0.01 比 MID360 原生点间距还细，基本无损。'
                        '（雷达路线 map_source:=lidar 用这个）'),
        DeclareLaunchArgument(
            'cam_voxel_size', default_value='0.02',
            description='相机路线(map_source:=camera)的体素边长(m)。比雷达那档粗一倍 —— '
                        '双目点云本身就有约 1~2cm 的深度噪声，用 0.01 等于把噪声也当结构存，'
                        '地图会迅速堆到 max_points 上限'),
        # ── 上色用的彩色图（可选）──
        # **是图像，不是点云**：几何由雷达给，相机只负责颜色。
        DeclareLaunchArgument(
            'color_topic',
            default_value='/camera/camera/color/image_rect_raw/compressed',
            description='上色用的彩色图（CompressedImage）。留空=不上色，'
                        '点云照常建图，只是 rgb 全为 NaN。用 image_rect_raw 那一路'
                        '（raw 未校正，rect 才校正过），要跟下面的内参配对'),
        DeclareLaunchArgument(
            'color_info_topic',
            default_value='/camera/camera/color/camera_info',
            description='彩色内参；投影取色要用。换相机/换分辨率必须跟着换'),

        # ── 作业交底语音播报（rl_briefing）──
        DeclareLaunchArgument(
            'audio_dir', default_value='~/briefing_audio',
            description='交底 wav 目录。音频不在包里（可替换资源），'
                        '生成/替换见 robodog-yunnan-elec/rl_briefing/scripts/make_wavs.py'),
        DeclareLaunchArgument(
            'audio_device', default_value='plughw:CARD=A311,DEV=0',
            description='ALSA 播放设备。默认=机器人喇叭那块 USB 免驱声卡（Yundea A31-1）；'
                        '用卡名不用卡号，插拔别的 USB 不会走样。列可选设备: aplay -L'),
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
    # 彩色相机。lidar_recorder 就是查这条 TF 把相机点云搬到 body 系的
    # （相机点云本身一般在相机光学系里，frame_id 见 camera_frame 参数）。
    tf_camera = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='base_to_camera_tf',
        arguments=cam_xyz_quat + ['base_link', 'camera_link'],
    )

    # 相机光学系（挂在 camera_link 下；平移先按 0 —— 左目传感器就在相机基准处，
    # 厘米级的偏移对地图影响很小，真要抠再量）
    cam_opt_quat = quat_from_rpy(*cam_opt_rpy)
    tf_cam_left = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='camera_to_left_tf',
        arguments=['0', '0', '0'] + [f'{v}' for v in cam_opt_quat]
                  + ['camera_link', 'camera_camera_left'],
    )
    # 彩色相机的光学系。**上色取的就是这一路**（color_topic 的图像 frame_id 是
    # camera_camera_rgb）。彩色与左目在同一块模组上、相距约一厘米，所以平移仍按 0
    # —— 一厘米的偏移在 3 米外是 0.2°，投影取色看不出来。
    tf_cam_rgb = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='camera_to_rgb_tf',
        arguments=['0', '0', '0'] + [f'{v}' for v in cam_opt_quat]
                  + ['camera_link', 'camera_camera_rgb'],
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
        condition=LaunchConfigurationEquals('lidar_source', 'real'),
        parameters=[{
            'use_simulation': False,
            'simulation_odom_topic': '/absolute_pose',
            'real_robot_odom_topic': LaunchConfiguration('real_robot_odom_topic'),
            # 安装变换参数（默认就是实机装法，见 lidar_data_node.cpp 注释）
            'apply_mount_transform': True,
            'mount_x': 0.286, 'mount_y': 0.0, 'mount_z': 0.0,
            # 前向倒装 45° = 绕 y 轴 −135°（−2.356194 rad）
            # mount_yaw = π（2026-10-05 实测修正）：安装变换少了绕 base_link z 的
            # 180°，上报车头方向原本是物理车头的背面（goto 时表现为走反）。
            # 静态测不出来（见 lidar_data_node.cpp 注释）；改的是旋转整体。
            'mount_roll': 0.0, 'mount_pitch': -2.356194, 'mount_yaw': 3.141593,
        }],
    )

    # ── 4b. 假 /lidar_data（lidar_source:=fake）──────────────────────
    # 无雷达/无 SLAM 的台架联调：持续发 (0,0,0)，让 dog_node 的前置检查能过、
    # 网页能下发任务。**只验链路通不通** —— 位姿恒定，闭环任务必然收敛不了。
    # 与上面的 lidar_data_node 互斥（见 lidar_source 的说明）。
    fake_lidar_data = Node(
        package='core_2026',
        executable='fake_lidar_data',
        name='fake_lidar_data',
        output='screen',
        condition=LaunchConfigurationEquals('lidar_source', 'fake'),
        parameters=[{
            'topic': 'lidar_data',
            'rate_hz': 10.0,
        }],
    )

    # ── 5. 小脑通信桥（bridge:=ros2|ws|none，默认 ros2）───────────────
    # 直接 include 桥自己的 launch，桥的参数只在那一处维护，避免两边漂移。
    # 两个桥**互斥**：原生通道与旧桥转发的 heartbeat/cmd_state 同起会双份
    # （实测叠加到 4.7Hz），所以用 launch 条件只起一个。
    # 立刻起（不延迟）：dog_node 是人工在之后单独起的，顺序天然满足。
    bridge = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('dog_ros2_bridge'), 'launch', 'dog_ros2_bridge.launch.py'
            ])
        ]),
        launch_arguments={
            'status_poll_hz': LaunchConfiguration('status_poll_hz'),
        }.items(),
        condition=LaunchConfigurationEquals('bridge', 'ros2'),
    )
    # 旧 WebSocket 桥（已弃用，回退用）
    bridge_ws = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('dog_ws_bridge'), 'launch', 'dog_bridge.launch.py'
            ])
        ]),
        launch_arguments={
            'url': LaunchConfiguration('url'),
            'status_poll_hz': LaunchConfiguration('status_poll_hz'),
        }.items(),
        condition=LaunchConfigurationEquals('bridge', 'ws'),
    )

    # ── 6. rosbridge:浏览器进 ROS 的入口 ─────────────────────────────
    # 用官方 launch（端口/地址这些参数只在那处维护），它同时会把 rosapi 也起上
    # ——网页「话题调试」页签列话题靠的就是 rosapi。
    # **必须用 AnyLaunchDescriptionSource**：那份是 .xml，用
    # PythonLaunchDescriptionSource 会抛 "invalid syntax (…xml, line 1)"，
    # 而 launch 的异常会**把整条链路一起中断**（实测：只剩 3 个节点起来）。
    # address 传空 = 监听所有网口 —— 笔记本上的浏览器要连 192.168.8.137:9090，
    # 不能只听 127.0.0.1。
    rosbridge = IncludeLaunchDescription(
        AnyLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('rosbridge_server'), 'launch',
                'rosbridge_websocket_launch.xml'
            ])
        ]),
        launch_arguments={
            'port': LaunchConfiguration('rosbridge_port'),
            'address': '',
        }.items(),
    )

    # ── 6b. 双目点云（map_source:=camera）──────────────────────────
    # stereo_points 订左右红外 + 彩色，SGBM 算视差 → 深度 → 彩色点云，
    # 发 /camera/camera/depth/color/points（帧 camera_camera_left）。
    # 只在相机路线起 —— SGBM 在这块板上跑 5Hz 已占不少 CPU，雷达路线用不着。
    stereo = Node(
        package='stereo_points',
        executable='stereo_points_node',
        name='stereo_points',
        output='screen',
        parameters=[{
            'max_range_m': LaunchConfiguration('stereo_max_range_m'),
        }],
        condition=LaunchConfigurationEquals('map_source', 'camera'),
    )

    # ── 7. 建图录制:点云 → 网页的唯一点云出口 + pcd 落盘 ──────────────
    # 立刻起（不必等雷达）：它收不到点云时只是不发数据，状态里会标 degraded，
    # 网页那边看到的是「未收到点云」而不是「点了没反应」。
    #
    # **两条路线各一份 Node，用 map_source 互斥**（和上面 lidar_data_node 的
    # real/fake 同一个套路）：参数差异不止话题名，还有 cloud_frame（相机点云在
    # 左目光学系，得先搬到 body 再乘位姿）和上色（相机点云自带颜色，要关掉补色那一遍）。
    # 拆成两份比在参数里写条件表达式清楚得多。
    recorder_camera = Node(
        package='lidar_recorder',
        executable='lidar_recorder_node',
        name='lidar_recorder',
        output='screen',
        parameters=[{
            'out_dir': LaunchConfiguration('maps_dir'),
            'voxel_size': LaunchConfiguration('cam_voxel_size'),
            'cloud_topic': '/camera/camera/depth/color/points',
            # 相机点云在**左目光学系**；节点会走 base_link 中转搬到 body 再乘位姿
            'cloud_frame': 'camera_camera_left',
            # 留空 = 不上色：点云自带 rgb，前端的"给已有点补色"那一路整段跳过
            'color_topic': '',
        }],
        condition=LaunchConfigurationEquals('map_source', 'camera'),
    )
    recorder_lidar = Node(
        package='lidar_recorder',
        executable='lidar_recorder_node',
        name='lidar_recorder',
        output='screen',
        parameters=[{
            'out_dir': LaunchConfiguration('maps_dir'),
            'voxel_size': LaunchConfiguration('voxel_size'),
            'cloud_topic': '/cloud_registered_body',
            'cloud_frame': 'body',
            'color_topic': LaunchConfiguration('color_topic'),
            'color_info_topic': LaunchConfiguration('color_info_topic'),
        }],
        condition=LaunchConfigurationEquals('map_source', 'lidar'),
    )

    # ── 8. 作业交底语音播报:网页点场景 → /rl_briefing/play → 播 wav ────────
    # 零运动风险（只往声卡写音频），所以放链路里跟着一起起 —— 网页点交底就该有反应。
    # 音频不在包里（可替换资源），默认 ~/briefing_audio；生成/替换见
    # src/robodog-yunnan-elec/rl_briefing/scripts/make_wavs.py
    briefing = Node(
        package='rl_briefing',
        executable='briefing_player',
        name='briefing_player',
        output='screen',
        parameters=[{
            'audio_dir': LaunchConfiguration('audio_dir'),
            'device': LaunchConfiguration('audio_device'),
        }],
    )

    return LaunchDescription(decls + [
        livox_driver,
        tf_livox,
        tf_body,
        tf_camera,
        tf_cam_left,
        tf_cam_rgb,
        slam,
        lidar_data_node,
        fake_lidar_data,
        bridge,
        bridge_ws,
        rosbridge,
        stereo,
        recorder_camera,
        recorder_lidar,
        briefing,
    ])
