# robodog-yunnan-elec —— JXG 轮足狗的大脑端控制仓库

跑在**算法大脑**（NanoPi M5，`nanopi-m5` / 192.168.8.137）上的 ROS2 源码，
是工作区 `~/ros2_ws/src/` 里的主体：编译用 `~/ros2_ws/build.sh`，跑命令用 `~/rosrun.sh`。

> 本 README 2026-10-03 按当前实况重写。旧版是移植前的原项目文档（xkai 狗 + Nav2 +
> ego-planner + ROS2 Humble 时代），留在 git 历史里；其中描述的流程在本板**不再使用**
> （对应遗留 launch 见 §8）。

## 1. 板上环境

- 板：NanoPi M5，Armbian 26.8.1 / Debian 13 aarch64；用户 `jinjiao`
- ROS：RoboStack 提供的**原生 ROS 2 Jazzy**（micromamba 环境 `ros`，**不是 docker**）
- 工作区：`~/ros2_ws`（`--merge-install`）；环境/网络细节见 `~/ros2_ws/README.md`
- 跑命令的唯一正确姿势：`~/rosrun.sh '<命令>'`（封装 micromamba run + source setup.bash）
- 小脑：192.168.8.236（`rl_real_JXG` v4，运控 + 电机）。大脑与小脑
  **ROS2 原生 DDS 直连**，`/rl_real/*` 是两边的主接口；小脑上旧的 WebSocket
  `:8088` 仍保留（浏览器 console 页直连它）

## 2. 本仓库有什么

| 目录 | 内容 |
|---|---|
| `core_2026/` | 狗端控制核心。`dog_node` = HAL（robot_dog_hal）+ 控制 + 任务执行（layer3_mission）+ 编排（layer4_system）；`mission_plan_selftest` 是任务 JSON 契约自测 |
| `ros2_tools/` | `lidar_data_node`（里程计 → `/lidar_data`，含雷达安装变换）、`lidar_to_px4_bridge`、地面相机 / D435 节点 |
| `rl_briefing/` | 作业交底语音播报（ALSA）。wav 放 `~/briefing_audio/`（可替换资源，**不随仓库**），见其 README |
| `messages/` | 原项目的自定义消息（SmartCar* / Vision* / PlatformTarget），当前狗链路不用 |
| `docs/` | 协议文档：`MISSION_PROTOCOL.md`（网页 ↔ 狗 任务编排契约） |
| `tools/` | 干跑与调试：`dog_dryrun_fake.py`（假小脑）、`mission_pubstr.py`（CLI 发文本）、`mission_samples/`（样例任务 JSON） |

不在本仓库、但同工作区一起跑的：`dog_ros2_bridge`（小脑桥适配层）、`dog_ws_bridge`
（旧 WebSocket 桥，已弃用）、`lidar_recorder`（建图录制）、`dog_nav_demo`（闭环示例）、
第三方 `Point-LIO` / `livox_ros_driver2`。

## 3. 链路拓扑

```
Livox MID360 ──livox_ros_driver2──▶ Point-LIO ──/aft_mapped_to_init──▶ lidar_data_node
                                                  └─/cloud_registered_body    │ /lidar_data (ros2_tools/LidarPose)
                                                                              ▼
 小脑 192.168.8.236 ◀──/rl_real/*（cmd_vel·command·feedback·cmd_state·heartbeat，DDS 直连）──▶ dog_node
       ▲                                                                              │
       └ 浏览器 console 页(WebSocket :8088)                    rosbridge :9090 ◀── 网页「任务编排」(~/web)
```

- `dog_ros2_bridge`（**不在本仓库**）只补小脑侧没有的三件事：2Hz `status` 轮询
  （dog_node 预检要的 feedback `state=` 文本）、`heartbeat_alive` 派生、`cmd_vel` 断流补零。
  `slam_only.launch.py` 的 `bridge:=ros2`（默认）| `ws`（回退旧桥）| `none`（调试）切换；
  **两个桥不能同起**（心跳会叠加）。
- 雷达安装变换（杆臂 0.286m、前向倒装 45°）配在三个地方，改要同步：
  `core_launch.py` 与 `slam_only.launch.py` 的静态 TF、`ros2_tools/lidar_data_node.cpp`
  的参数（`apply_mount_transform`）。

## 4. 起法

链路（雷达 + SLAM + 桥 + rosbridge + 建图录制 + 播报，**不含 dog_node**）：

```bash
~/start_slam.sh                # 即 ros2 launch core_2026 slam_only.launch.py
~/start_slam.sh rviz:=true     # 带 rviz 看地图
```

`dog_node` **必须是一次明确的手动动作**（一过预检就会让狗站起来），两种模式：

```bash
# 网页驱动（任务编排）：起来后等 /dog/mission，预检变成任务里的步骤
~/rosrun.sh 'ros2 launch core_2026 dog_web.launch.py'

# 固定流程（原样保留）：预检 → 起立 → 前进N秒 → 趴下，终端回车闸门
~/rosrun.sh 'ros2 run core_2026 dog_node --ros-args -p forward_duration_s:=0.0'
```

行为要点（2026-09 实机验证）：

- dog_node 的每个状态切换过**四道关**：前置状态 → 小脑终态码 → 状态码确认 → 分级延迟
  （getup 10s、其余 1s）。非法切换被拦下并上报，不会盲发。
- `passive` 已全链路移除：趴下一律 `getdown`（2s 平滑）。小脑的 ROS 接口
  2026-10-01 起直接 `REJECTED` passive（手柄 P 键与内置 Web 调试台还保留）。
- `dog_web.launch.py` 里 `confirm_transitions:=false` 是**把终端闸门换成网页闸门**，
  不是拆掉闸门 —— 非 tty 环境（launch/systemd/重定向）不走它会按安全策略直接中止。

## 5. 任务编排（网页 → 狗）

协议、字段、错误码：`docs/MISSION_PROTOCOL.md`（**两边共同遵守的契约，改一边必须同步另一边**）。
网页端代码在 `~/web`；命令生命周期状态码 + 2Hz 心跳（console 页用）见 web 仓库
`docs/CMD_STATE_PROTOCOL.md`。

## 6. 干跑（不接狗，全流程可验）

`tools/dog_dryrun_fake.py` 头部有四步配方：假小脑 + `fake_pose` + `lidar_data_node` +
dog_node（所有 `/rl_real/*` remap 到 `/dryrun/*`，绝不碰真狗那一路）。
样例任务 JSON 在 `tools/mission_samples/`。

## 7. 编译与自测

```bash
~/ros2_ws/build.sh --packages-select core_2026    # launch 文件改了也要重编（ros2 launch 读 install 副本）
~/ros2_ws/build/core_2026/mission_plan_selftest   # 任务 JSON 契约自测（59 项，不需要 ROS/硬件）
```

## 8. 遗留文件（原项目，本板不用）

`core_2026/launch/core_launch.py`（mavros 无人机）、`car_mission.launch.py`（巡线车），
以及被开关关掉的条件编译目标 `quad_node` / `car_mission_node` / `test_max_curvature` ——
都是移植前的原项目，保留仅供对照。`messages/` 里大部分消息同源；狗链路实际只用
`ros2_tools/LidarPose`。

## 相关文档

- `~/ros2_ws/README.md` —— 工作区环境、编译参数与网络（雷达口）细节
- `docs/MISSION_PROTOCOL.md` —— 任务编排契约（本仓库）
- `~/web/README.md` + `~/web/docs/CMD_STATE_PROTOCOL.md` —— 网页端与命令生命周期协议
- `~/ros2_ws/src/dog_ros2_bridge/README.md` —— 小脑桥适配层（工作区包，不在本仓库）
- `rl_briefing/README.md` —— 语音播报包
