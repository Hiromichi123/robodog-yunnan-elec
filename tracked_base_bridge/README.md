# 差速履带底盘兼容层

独立机型：大脑直接控制两路 50Hz PWM，无小脑。当前不接 Web、dog_node、任务队列或生产启动链路。

硬件后端二选一：

| backend | 说明 |
|---|---|
| `mock` | 默认，不碰硬件 |
| `usbgpio` | USB 转 PWM 模块（GD32 CDC ACM，USB-GPIO V4 协议），`/dev/ttyACM*` |
| `sysfs` | 板载 `pwmchipN` 硬件 PWM（保留，未实测） |

## 默认只模拟

```bash
~/rosrun.sh 'ros2 launch tracked_base_bridge tracked_base.launch.py'
```

默认 `backend=mock`、`allow_hardware=false`、`mapping_confirmed=false`，初始 DISARMED，不访问硬件。配置中的 0.4m 履带间距、0.5m/s 速度和 1000/1500/2000μs **只是模拟样例，不是标定值**。

所有话题隔离在 `/tracked_base`：

| 话题 | 类型 | 内容 |
|---|---|---|
| cmd_vel | geometry_msgs/Twist | 仅 linear.x (m/s) / angular.z (rad/s) |
| command | std_msgs/String | enable / disable / vel_stop / status |
| cmd_state | std_msgs/String | JSON 生命周期 |
| feedback | std_msgs/String | 文本，含 state= token |
| heartbeat | std_msgs/String | 2Hz JSON 状态及 commanded_pulse_us |

command 接受纯命令文本，或 `{"cmd":"enable","seq":1}`。非零 seq 在最近 256 个键内按 (seq,cmd) 去重，重复帧 REJECTED、不重执行。seq=0 不去重。生命周期字段与狗端形式相同：seq/cmd/code/phase/target/state/elapsed_ms，另加 reason；code 0 RECEIVED、2 DONE、3 FAILED、4 REJECTED。同步操作不虚构 EXECUTING。DONE 仅代表软件/驱动写入完成，不代表履带物理到位。

状态为 DISARMED / ENABLED / FAULT，绝不伪装成机器狗 FSM。getup/getdown/locomotion/passive/nav_on 等不适用命令均拒绝。

## 控制与安全

- `vL=vx-wz*track_width/2`、`vR=vx+wz*track_width/2`。车体与履带超限同比缩放保留曲率；左右可独立反向/中立/死区。
- 映射为开环油门近似，不是闭环速度，不发布虚假 odom、姿态或物理反馈。
- enable 后必须收到新速度；enable 重复执行不刷新看门狗。disable 撤销使能，vel_stop 清目标并回中立（不撤销使能）。
- 默认 0.5s 速度断流即停车并撤销使能，包含 enable 后一直未发速度的情况。非法数值/不支持轴停车撤销使能；写失败锁定 FAULT，需诊断后重启。
- 50Hz 更新目标；PWM 波形由硬件外设输出，不靠 Python 定时翻转 GPIO。固定周期 20,000,000ns，1000–2000μs 即 5%–10% 占空比。
- 输入 QoS RELIABLE / VOLATILE / depth=1；速度须为本机系统时钟的有效 DDS source_timestamp，早于最近 enable/stop 的帧与超时帧均丢弃。发送器必须持续发送，不能靠一条长效速度。不要远程时钟未同步发送 enable/速度。安全看门狗用 monotonic，定时器用 STEADY_TIME，不随 ROS 仿真时间暂停。
- 配置启动时固定，运行中参数修改拒绝。不要 remap 到 `/rl_real/*`，此轮没有狗任务适配。

## 实机接线前置条件（未确认前禁止输出真实 PWM）

1. 确认电调双向控制与停止脉宽，独立验证失信号保护；不能假设 1500μs 中立。当前只支持 reverse < neutral < forward 的双向电调，方向差异用 inverted；其他协议需另做适配。
2. 确认电平、公共地、两路输出及未被其他设备占用。经独立批准后设置几何/速度/映射、`mapping_confirmed=true`、`allow_hardware=true`。缺一不可；不自动 sudo/改权限/改设备树。
3. 启动 DISARMED 仍输出已确认的中立脉冲。正常退出尽力回中立后关闭 PWM 输出；关闭输出 **不等于刹车**。进程 SIGKILL/挂死/掉电/拔 USB 可能无法清理，必须有硬件急停与电调独立保护。

### USB-PWM（`backend=usbgpio`）

- 模块：USB-GPIO V4（GD32 CDC ACM），协议见《USBGPIO通信协议_V4》。12 路 PWM 分 3 组，同组 4 路共周期；**左右必须接同组两个不同通道**。
- 引脚：G17–G28 = P1_1–P3_4。`pwm_group`（1–3）+ `left_pwm_channel`/`right_pwm_channel`（1–4），默认 `group=1, left=1, right=2`，即 G17/G18。
- 参数：`serial_port`（建议用 `/dev/serial/by-id/...`，避免与 mavros 的 `/dev/ttyACM0` 抢占）、`serial_baud`（CDC 实际忽略，默认 115200）、`pwm_resolution_counts=120`（1μs）、`pwm_period_counts=20000`（50Hz）。非 50Hz 配置直接拒绝。
- 初始化：先发 `0x41` 校验固件含 `softWare_V4`（大小写不敏感；误连 FCU 等 CDC 设备会拒绝），再把两个引脚配成 PWM（`0x01` 类型 6）→ 周期（`0x21`）→ 中立占空比（`0x22`）→ 开组（`0x23`）。不做 `0x42` 保存，避免掉电后自动输出。
- 运行：每帧 `0x22` 一次写四路占空比，左右**同一帧**更新，比 sysfs 的两路非原子写入更安全。退出写中立后 `0x23` 关组。
- 每个串口路径有 flock 端口锁，只防本包多实例；不能阻止其他程序打开同一设备。模块无命令回执，DONE 只代表串口写入完成。

### 板载 sysfs（`backend=sysfs`，保留）

- 当前探测 pwmchip0/1/2 各 1 通道，但**不是接线分配**；已导出通道一律拒绝接管。
- 初始化两路禁用→周期/极性/中立→启用，两路写入**非原子**；退出回中立后 disable/unexport。

## 测试（全程无真实 PWM）

```bash
# 系统 Python 没有 pytest；使用已有 ROS 环境，不另装依赖。
~/rosrun.sh "bash -c 'cd /home/jinjiao/ros2_ws/src/robodog-yunnan-elec/tracked_base_bridge && PYTEST_DISABLE_PLUGIN_AUTOLOAD=1 python -m pytest test -q'"
# ROS 环境构建/测试，仅本包：
~/rosrun.sh "bash -c 'cd /home/jinjiao/ros2_ws && colcon build --merge-install --packages-select tracked_base_bridge'"
~/rosrun.sh "bash -c 'cd /home/jinjiao/ros2_ws && PYTEST_DISABLE_PLUGIN_AUTOLOAD=1 colcon test --merge-install --packages-select tracked_base_bridge --python-testing pytest && colcon test-result --test-result-base build/tracked_base_bridge --verbose'"
# 安装后 DDS/launch 验收；默认独立域 173，需先确认未使用。
~/rosrun.sh 'python ~/ros2_ws/src/robodog-yunnan-elec/tracked_base_bridge/test/ros_smoke.py'
```

板端 `rosrun.sh` 使用 `exec`，含 `cd` 的命令必须包在 `bash -c` 中。现有 pytest 9 与自动加载的 launch_testing 插件不兼容，因此仅本次命令禁用插件自动加载；colcon 显式选择 pytest，避免新版 setuptools 忽略 tests_require 后回退到 unittest。无需更换全局环境。

2026-10-30 板端验收：56 项单测全部通过（colcon 同样 56/0/0），独立域 173 的 10 组 DDS mock 检查通过，launch 正常退出。

2026-11-01 板端验收：新增 USB-PWM 后端后 76 项单测通过（colcon 76/0/0），mock smoke 10/10；用 `test/usbgpio_neutral_check.py --yes` 对实际模块发帧成功（固件 `softWare_V4`，group1 P1_1/P1_2，中立 1500μs 保持 3s 后 `0x23` 关组），**当时未接线、未用示波器测量**；电调/接线/标定仍未验收。

`test/test_node.py` 在 ROS 环境下验证时间戳边界；本机无 rclpy 时跳过。`ros_smoke.py` 显式本机发现，拒绝已有履带节点/订阅者的域，检查安装的 YAML 仍为 mock，再启动安装的 launch。可用 `TRACKED_TEST_DOMAIN` 选择其他未占用域。脚本退出时回收自身 launch 进程组；不可用它做实机验收。

`test/test_pwm.py` 用临时目录伪 sysfs（Linux），不会触碰 `/sys/class/pwm`。`test/test_usbgpio.py` 用假串口传输（FakeTransport）校验 USB-PWM 帧字节、固件校验、端口锁和关闭顺序，不打开 `/dev/ttyACM*`。`test/ros_smoke.py` 仅启动 mock，使用独立 ROS_DOMAIN_ID，验证 ROS 协议/运动计算/超时。禁止将其改成 sysfs 运行。
