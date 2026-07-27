# RoboDog Yunnan-Elec 机器狗全自动控制系统

## 项目概述

基于 `core_2026` 架构实现 XKAI 四足机器狗的全自动控制，集成 LiDAR SLAM 定位、Nav2 导航避障、ego-planner 轨迹规划，支持手柄遥控和 ROS2 自主控制双模式。

## 硬件架构

```
LiDAR (MID360) → PointLIO → Odometry → lidar_data_node → LidarPose
                                                              ↓
[Xbox/PS4手柄] → rl_real_xkai ← /cmd_vel ← nav2 / ego-planner ← 目标点
                   ↓  ↑            ↓  ↑
              /dog/fsm_command   /dog/state (FSM反馈)
                   ↓  ↑
              dog_node (core_2026)
```

## 目录结构

```
~/ros2/
├── rl_sar-w/                          # 机器狗底层控制
│   ├── cmake_build/bin/rl_real_xkai   # 机器狗主程序
│   └── policy/XKAIw/                  # 策略配置与RL模型
│       ├── base.yaml                  # 基础配置 (16 DOF)
│       └── himloco/                   # himloco RL 模型
├── robodog-yunnan-elec/               # core_2026 控制核心
│   └── core_2026/
│       ├── src/layer1_hal/robot_dog_hal.*  # 机器狗 HAL
│       ├── src/layer3_mission/dog_mission_executor.*  # 任务执行器
│       ├── src/layer4_system/dog_system.*  # 系统编排
│       └── launch/dog_mission.launch.py    # 启动文件
├── Point-LIO/                         # LiDAR SLAM
├── nav2/                              # Nav2 导航避障
└── ego-planner-swarm/                 # ego-planner 轨迹规划
```

---

## 一、编译

### 1.1 机器狗底层

```bash
cd ~/ros2/rl_sar-w/cmake_build

# 配置（需 ROS2 humble 环境）
cmake /home/zhenzhen/ros2/rl_sar-w/src/rl_sar -DUSE_CMAKE=ON

# 编译
make -j$(nproc) rl_real_xkai
```

### 1.2 core_2026 控制核心

```bash
cd ~/ros2/robodog-yunnan-elec
colcon build --symlink-install
```

---

## 二、启动机器狗

### 2.1 纯手柄遥控

```bash
cd ~/ros2/rl_sar-w/cmake_build
source ~/ros2/robodog-yunnan-elec/install/setup.bash
./bin/rl_real_xkai wheel
```

| 手柄操作 | 功能 |
|----------|------|
| **A 键** (PS4: ✕) | 站立 (Passive → GetUp) |
| **LB + 上键** | 进入 RL 运动模式 (GetUp → RLLocomotion) |
| **B 键** (PS4: ○) | 趴下 |
| **P 键** (键盘) / **LB + X** | 回到 Passive |
| 左摇杆 ↑↓ | 前进/后退 |
| 左摇杆 ←→ | 左右平移 |
| 右摇杆 ←→ | 转向 |
| **LB + RB** | 紧急退出 |

### 2.2 ROS2 自动控制

```bash
# 终端1: 启动机器狗底层
cd ~/ros2/rl_sar-w/cmake_build
source ~/ros2/robodog-yunnan-elec/install/setup.bash
./bin/rl_real_xkai wheel

# 终端2: 一键启动全系统
source ~/ros2/robodog-yunnan-elec/install/setup.bash
ros2 launch core_2026 dog_mission.launch.py
```

`dog_mission.launch.py` 启动的节点：

| 节点 | 功能 |
|------|------|
| `livox_ros_driver2` | MID360 激光雷达驱动 |
| `tf2_ros static_transform` | base_link → livox_frame 变换 |
| `point_lio` | 激光 SLAM 定位（延迟5秒启动） |
| `lidar_data_node` | Odometry → LidarPose 转换 |
| `dog_node` | core_2026 机器狗 HAL + 任务编排 |

### 2.3 任务流程

```text
TAKEOFF → "getup" (A键) → sleep(4s) 等待站起
       → "locomotion" (LB+上键) → sleep(1s) 进入运动模式
       → HOVER
HOVER  → vx=0.3m/s × 3.5s (前进约1米)
       → LAND
LAND   → "passive" (P键) → sleep(2s) 趴下
       → DONE
```

---

## 三、Nav2 自主导航避障

### 3.1 架构

```
PointLIO Odometry → odom_republisher → /odom (nav2输入)
LiDAR PointCloud → /livox/lidar → nav2 costmap (障碍物检测)
nav2 planner → /cmd_vel → rl_real_xkai → 机器狗运动
```

Nav2 输出的 `/cmd_vel` 直接通过 `ros2_cmd_active_` 机制注入 `control.x/y/yaw`，无需 `navigation_mode`。

**手柄与自动控制自动切换**：收到 `/cmd_vel` 后自动切换为 ROS2 控制，手柄摇杆有输入后自动切回手柄。500ms 无 `/cmd_vel` 消息则自动恢复手柄。

### 3.2 启动 Nav2

```bash
# 确保机器狗底层 + LiDAR + SLAM 已运行（见2.2节）

# 启动 Nav2
ros2 launch /home/zhenzhen/ros2/nav2/drone_nav2.launch.py

# RViz 可视化（可选）
ros2 launch /home/zhenzhen/ros2/nav2/drone_rviz.launch.py

# 发布导航目标点
python3 /home/zhenzhen/ros2/nav2/goal_publisher.py <x> <y> <z> [yaw]
# 示例：前进2米，右转1米
python3 /home/zhenzhen/ros2/nav2/goal_publisher.py 2.0 1.0 0.0 0.0
```

### 3.3 关键参数 (nav2_drone_params.yaml)

| 参数 | 值 | 说明 |
|------|-----|------|
| 最大线速度 | 1.0 m/s | 可调整 |
| 障碍物检测范围 | 8.0m | LiDAR 最大距离 |
| 局部代价地图分辨率 | 0.1m | |
| 全局代价地图分辨率 | 0.2m | |
| 机器人半径 | 0.5m | 膨胀半径 |

---

## 四、ego-planner 轨迹规划

ego-planner 生成无碰撞的平滑轨迹，输出 position/velocity 指令。

### 4.1 启动 ego-planner

```bash
# 确保机器狗底层 + LiDAR + SLAM 已运行

source ~/ros2/ego-planner-swarm/install/setup.bash
ros2 launch ego_planner run_in_sim.launch.py
```

### 4.2 与机器狗集成

ego-planner 输出轨迹点 → 需要转换为 `/cmd_vel` 发送给机器狗。有两种方式：

**方式 A：速度 PID 跟随**（推荐）
```bash
# ego-planner 轨迹 → dog_node 的 FlightController::fly_by_path()
# 通过 ICommandPublisher::publish_velocity() 转换为 /cmd_vel
```

**方式 B：直接话题桥接**
```bash
# ego-planner 输出 /planning/pos_cmd (PoseStamped)
# → 自定义桥接节点 → /cmd_vel (Twist)
```

---

## 五、开发指南

### 5.1 自定义任务

编辑 `~/ros2/robodog-yunnan-elec/core_2026/src/layer3_mission/dog_mission_executor.cpp`：

```cpp
void DogMissionExecutor::on_hover() {
    // 示例：走正方形
    Velocity fwd(0.3f, 0.0f, 0.0f, 0.0f);
    Velocity turn(0.0f, 0.0f, 0.0f, 0.5f);

    for (int i = 0; i < 4; i++) {
        fc_.fly_by_vel_duration(fwd, 3.0f);   // 前进1m
        fc_.fly_by_vel_duration(turn, 1.5f);  // 转90°
    }
    current_state_ = State::LAND;
}
```

### 5.2 自定义 FSM 指令

`/dog/fsm_command` 支持的值：

| 指令 | FSM 动作 |
|------|----------|
| `getup` / `stand` | 站立 (Gamepad::A) |
| `passive` / `sit` | 趴下 (Keyboard::P) |
| `locomotion` / `walk` | 进入RL运动 (Gamepad::RB_DPadUp) |

### 5.3 ROS2 Topic 接口

| Topic | 类型 | 方向 | 说明 |
|-------|------|------|------|
| `/cmd_vel` | `geometry_msgs/Twist` | → 机器狗 | 速度指令 (vx, vy, vyaw) |
| `/dog/fsm_command` | `std_msgs/String` | → 机器狗 | FSM 状态切换 |
| `/dog/state` | `std_msgs/String` | ← 机器狗 | FSM 状态反馈 |
| `lidar_data` | `ros2_tools/LidarPose` | ← SLAM | 定位数据 |

---

## 六、故障排除

### 机器狗不动
1. 检查 CAN 串口 `/dev/ttycan1~4` 是否都有反馈
2. 确认电机已使能（`[MOTOR]` 输出中 `kp > 0`）
3. 轮子电机 `kp=0` 是正常设计（速度模式），确认 `real_tau` 是否有值

### Nav2 目标点无法到达
1. 检查 TF 变换树：`ros2 run tf2_tools view_frames`
2. 确认 LiDAR 点云发布在 `/livox/lidar`
3. 检查 `/odom` 话题是否有数据

### 手柄不响应
1. 确认 `ros2_cmd_active_=0`（诊断输出每秒显示）
2. 检查 `/cmd_vel` 是否有其他发布者：`ros2 topic info /cmd_vel`
3. 确认手柄已连接：启动日志应显示 `[Xbox] 手柄已连接成功`

### 编译问题
- `rclcpp/rclcpp.hpp not found`: 确保 ROS2 humble 环境已 source
- `messages not found`: 先 `colcon build --packages-select messages ros2_tools`
- `USE_ROS2 not defined`: 检查 CMakeLists.txt 中 `USE_ROS2 USE_ROS` 定义
