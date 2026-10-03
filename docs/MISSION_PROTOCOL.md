# 任务编排协议：网页 → 狗

> 2026-09-29 加。网页「任务编排」页签拼装任务 → 生成 JSON → 下发给 `dog_node` 逐步执行。
> 这份文档是**两边共同遵守的契约**：改一边必须同步改另一边。
>
> 代码位置：
> - 网页：`~/web/js/mission-view.js`（UI + 生成 JSON）
> - 狗端：`~/ros2_ws/src/robodog-yunnan-elec/core_2026/src/layer3_mission/`
>   - `mission_plan.{hpp,cpp}` —— 解析 + 校验（纯逻辑，不含 ROS）
>   - `mission_channel.{hpp,cpp}` —— 三个话题的收发 + 2Hz 心跳
>   - `dog_plan_executor.{hpp,cpp}` —— 一步步执行
> - 干跑工具与样例：本仓库 `tools/` —— `dog_dryrun_fake.py`（假小脑）、
>   `mission_pubstr.py`（CLI 发文本）、`mission_samples/`（样例任务 JSON）

---

## 1. 话题

| 话题 | 方向 | 类型 | 说明 |
|---|---|---|---|
| `/dog/mission` | web → 狗 | `std_msgs/String` | 一整份任务 JSON，**发下去即开始执行** |
| `/dog/mission_status` | 狗 → web | `std_msgs/String` | 进度 JSON，**变化时 + 2Hz 心跳** |
| `/dog/mission_cmd` | web → 狗 | `std_msgs/String` | `confirm` / `reject` / `abort` |

走浏览器已经在连的 rosbridge（`ws://192.168.8.137:9090`）。
**状态以狗端发的为准**：刷新页面/断线重连后网页靠 2Hz 心跳自动对齐，不需要自己记。
超过 1.5s 没收到状态 → 网页显示「狗端未上线」（说明 dog_node 没起）。

---

## 2. 任务 JSON

```json
{
  "version": 1,
  "name": "巡检A",
  "confirm": "each",
  "map": "map_20260929_113215.pcd",
  "steps": [
    {"type": "check_stand", "timeout_s": 5},
    {"type": "getup", "settle_s": 10},
    {"type": "locomotion"},
    {"type": "move", "vx": 0.1, "vy": 0.0, "wz": 0.0, "duration_s": 3.0},
    {"type": "goto", "x": 1.5, "y": 0.5, "yaw": 0.0, "goto_timeout_s": 60},
    {"type": "wait", "duration_s": 5.0},
    {"type": "getdown", "settle_s": 1}
  ]
}
```

- `version`：只认 `1`（不写按 1 处理）。
- `name`：显示用，不写给个兜底名。
- `confirm`：`"each"`（默认，危险步骤前暂停等网页确认）/ `"none"`（一口气跑完）。
  **不写就是 `each`** —— 缺省必须落在最安全那一档。
- `steps`：至少一步，最多 200 步。
- `map`（可选，网页加的）：这份任务的航点是在**哪张点云图上取的**，纯自描述。
  狗端**不看也不需要** —— 解析器只认已知键，多出来的键**安静忽略**
  （自测里专门有一条钉住这个性质；别改成"遇到未知键就报错"，
  否则网页一加 UI 字段狗就拒任务，现场看着像"发出去了、狗不动"）。

### 步骤类型

| type | 参数 | 默认 | 上限 / 说明 |
|---|---|---|---|
| `check_stand` | `timeout_s` | 5 | ≤60；站立自检（只读电机零位 + IMU，不动） |
| `getup` | `settle_s` | 10 | ≤120；起立。前置：狗必须趴着 |
| `locomotion` | — | — | 进 RL 运动模式。前置：狗必须已起立 |
| `move` | `vx` `vy` `wz` `duration_s` | 0.1 / 0 / 0 / 3.0 | vx,vy ≤0.5、wz ≤1.0、duration>0 且 ≤300 |
| `goto` | `x` `y` `yaw` `goto_timeout_s` | 1.0 / 0 / 0 / 60 | 坐标 ≤±50 m，超时 ≤300。**世界系**（见 §7） |
| `wait` | `duration_s` | 5 | ≥0 且 ≤300 |
| `getdown` | `settle_s` | 1 | ≤120；平滑趴下（2s 插值） |

**没有 `passive`。** 2026-09-29 用户定：passive 的卸力（kp=0、靠重力砸下去）不可靠，
已从整条链路移除 —— 回趴下一律用 `getdown`。任务里也就不需要"急停步骤"，
急停是任务级动作（`abort` 指令）。

### 校验（狗端，执行前一步都不动就能拒）

数值必须有限且在范围内；`steps` 非空；type 必须认识；缺字段用默认值。
不过就回 `rejected` + 中文原因，**一步都不会动**。

刻意**不**校验"移动步骤前面必须有 getup/locomotion"：狗上一轮任务结束时可能还站着，
那时"只移动"完全合法；反过来计划里写了 getup 但狗已经站着，getup 那步自己会失败。
所以这件事在执行期按**狗当时的真实 FSM 状态**判，网页上只做提示（黄色小字）。

---

## 3. 状态 JSON

```json
{"phase":"running","name":"巡检A","type":"move","msg":"","prompt":"",
 "index":4,"total":7,"elapsed_s":1.2}
```

| phase | 含义 | 网页表现 |
|---|---|---|
| `idle` | 起来了，等任务 | 「空闲」 |
| `running` | 正在跑第 index/total 步 | 高亮那一步 + 计时 |
| `waiting_confirm` | 停在危险步骤前等确认，`prompt` 里是给人看的那句话 | 弹「继续 / 放弃」 |
| `done` | 全部步骤跑完 | 绿字 |
| `failed` | 某步失败，已停速 + getdown 回趴下，`msg` 是原因 | 红字 |
| `aborted` | 操作员按了急停 | 黄字 |
| `rejected` | 任务被拒（解析/校验没过），`msg` 是原因 | 红字 |

---

## 4. 确认闸门（危险步骤前暂停）

危险步骤 = **会改变姿态或位置的那些**：`getup` / `locomotion` / `move` / `goto` / `getdown`。
`check_stand`（只读）和 `wait` 不问 —— 尺度与原来的终端回车闸门一致。

- `confirm:"each"` 时，到达危险步骤前狗**停下不动**，状态转 `waiting_confirm`，
  网页显示狗给的 `prompt`（就是原来终端里那句话，改成"点继续"）。
- 网页点「继续」→ 发 `confirm` → 执行这一步。
- 网页点「放弃」→ 发 `reject`：
  - 一般危险步骤：**中止整个任务**（停速 + getdown 回趴下）；
  - **`getdown` 这一步例外**：只跳过它、任务算完成、狗保持站立（照原来"趴下前按 q
    不替操作员做主"的语义），但日志和界面会提示**需人工看护**。
- **不设超时中止**：操作员去接个电话，比"等不到人回答就自动动"安全得多。
  每 30s 在狗端日志提醒一次还在等。

---

## 5. 失败 / 中止

一条规则：**回趴下一律 `getdown`，已经趴着就什么都不发**（`RobotDogHAL::safe_go_down()`）。
它按当前 FSM 状态决定：

| 当前状态 | 动作 |
|---|---|
| `RLLocomotion` | 发 `getdown` 平滑趴下，等确认 |
| `GetDown` / `Passive` | 已经趴着/正在趴 → 不发命令，算成功 |
| `GetUp`（起立动画中） | getdown 会被 FSM 拒 → 等 1s 重试，最多 3 次 |
| 读不到 / 别的 | 不发命令，报错要求人工确认（状态不可信时发什么都是赌） |

- 任务失败（goto 超时、进 RL 失败、自检没过、位姿丢失、手柄抢占）→ 停速 → 回趴下 → `failed`。
- 网页「停止（急停）」→ `abort` → 停速 → 回趴下 → `aborted`。
  **急停在 spin 线程里就动手**（置中止位 + 伪造命令终态打断等待），
  所以按下去到狗停下来是几十毫秒量级，不是"等当前那步跑完"。
- `vel_stop`（只归零速度、保持站立）用在**动作收尾**，不是失败处置。

---

## 6. 网页怎么用（两个页签）

**「任务状态」（执行页）** —— 只干"执行 + 看情况"：
- 顶部是狗端在线状态（`/dog/mission_status` 超 1.5s 没来就显示"狗端未上线"）。
- 「已加载：X（N 步 · 确认=each）」—— 要执行的任务从「任务管理」那边**加载**过来。
- 两个大按钮：**下发执行** / **停止（急停）**；狗端停在危险步骤前等确认时，
  出现大的「继续 / 放弃」和狗端给的那句提示（按钮和状态栏都特意放大，站着远看也清楚）。
- 大状态栏：相位 + 第 n/N 步 + 用时。

**「任务管理」** —— 只管"存、选、改、看"：
- **任务列表**：**点一行选中**（高亮），每行有「修改」「删除」；底部「+ 新增任务」「加载到执行页」。
  新增会自动带一套模板（自检→起立→进RL→移动→趴下），重名自动变 `巡检A2`。
- **JSON 预览**：选中任务的那份文本 —— **下发时发出去的就是它**，另有复制/导出/导入。
- **子页面**（点「新增」或某条的「修改」才进来）：任务名、确认方式、步骤编排
  （点类型加到末尾、参数就地改、↑↓ 排序、复制、删除、套用模板、清空）+ 保存 / 取消。
- 子页面里还有**点云地图**区（2026-09-29 加）：选一张板上的地图（走 webserver 的
  `/api/maps`）→ 在点云上**单击** = 往任务末尾加一个「到点」航点，坐标取的就是
  你点中的**那个点**（不是射线插值点），航点画成青色小球。左键拖动旋转、滚轮缩放；
  没点中会提示"这一下没点到点云上"。
  ⚠️ **地图得是这次开机建的**：重上电 / 换场地后 Point-LIO 的世界原点会变，
  拿旧图取的航点会整体偏一个量（图上看着对，狗走过去是偏的）。
  另外这份图里的点云是"录制那一刻"的场景，后来挪动的东西不在地图上。

三个名字别混：**选中**（任务管理里选中的，决定 JSON 预览和编辑对象）、
**加载**（送去执行页的那个，决定"下发执行"发什么）、**运行中**（狗端正在跑的，来自 2Hz 状态）。

**第一次验证流程**：任务管理 →「+ 新增任务」→ 删掉「移动」那一步 →「保存」→
「加载到执行页」（会自动跳到任务状态页）→「下发执行」→ 按提示点「继续」。
这样狗只站起、再趴下，不走一步路，先把"闸门—确认—完成"这条链走顺，再加移动和到点。

## 7. 起法与干跑

### 起（两种模式）

```bash
# 网页驱动（新）：起来后等 /dog/mission，预检变成任务里的步骤
~/rosrun.sh 'ros2 launch core_2026 dog_web.launch.py'

# 固定流程（旧，一字未改）：预检 → 起立 → 前进N秒 → 趴下，终端回车闸门
~/rosrun.sh 'ros2 run core_2026 dog_node --ros-args -p forward_duration_s:=0.0'
```

`dog_web.launch.py` 里 `confirm_transitions:=false` 是**把终端闸门换成网页闸门**，
不是拆掉闸门（网页的 confirm 字段接管了）。不走这个 launch 的话，非 tty 环境
（launch/systemd/重定向）会按安全策略在第一个闸门处直接中止。

### 干跑（不接狗，全流程可验）

见 `tools/dog_dryrun_fake.py`（本仓库；板上在 `~/ros2_ws/src/robodog-yunnan-elec/tools/`）头部的四步配方：假小脑 + `fake_pose` + `lidar_data_node`
+ dog_node（**所有 `/rl_real/*` 都 remap 到 `/dryrun/*`**，绝不碰真狗那一路）。
两个必须注意的点：
- `lidar_data_node` 的 `apply_mount_transform` **默认 true**，会把假位姿按 45° 安装角
  转一道 → 干跑要 `-p apply_mount_transform:=false`。
- `real_robot_odom_topic` 默认 `/aft_mapped_to_init`，板上 Point-LIO 正往里发 →
  必须指到不存在的话题，否则假位姿会和真 SLAM 抢同一个 `lidar_data`。
  （`use_simulation` 这个参数在这个节点里**不起作用**，别指望它。）

### 自测（不需要 ROS、不需要硬件）

```bash
~/ros2_ws/build.sh --packages-select core_2026
~/ros2_ws/build/core_2026/mission_plan_selftest                       # 59 项契约自测
~/ros2_ws/build/core_2026/mission_plan_selftest --parse-file x.json   # 验一份任务文件
```

### 不开浏览器也能下发（CLI）

```bash
# 工具在仓库 tools/ 下，板上完整路径 ~/ros2_ws/src/robodog-yunnan-elec/tools/mission_pubstr.py
~/rosrun.sh 'python3 ~/ros2_ws/src/robodog-yunnan-elec/tools/mission_pubstr.py /dog/mission /tmp/m.json'      # 下发任务
echo confirm > /tmp/c.json
~/rosrun.sh 'python3 ~/ros2_ws/src/robodog-yunnan-elec/tools/mission_pubstr.py /dog/mission_cmd /tmp/c.json'  # confirm/reject/abort
~/rosrun.sh 'ros2 topic echo /dog/mission_status'                       # 看进度
```

⚠️ 这类**短命发布端**在板上会被 DDS 发现期吃掉前几帧（实测反复踩到，看着像代码 bug）。
`mission_pubstr.py` 已经处理了（等 2s 再发 6 帧）。自己脚本里现建现发的话要吃同样的亏。
生产链路没这个问题：rosbridge 的发布端是常驻的。

样例任务 JSON 在 `tools/mission_samples/`：`web_default_template`（最小流程）、
`web_all_types`（全步骤）、`web_with_map`（带地图点选航点）。

### 改了代码之后

- 改 `core_2026`：`~/ros2_ws/build.sh --packages-select core_2026`
  （**launch 文件也一样要重编** —— `ros2 launch` 读的是 install 里的副本）
- 改 `~/web`：不用编译，但**改了 `js/main.js` 必须同步 bump `index.html` 和
  `mobile.html` 里的 `?v=`**，否则浏览器拿旧缓存、新页签点了没反应。

---

## 8. 实机注意事项

1. **`goto` 的坐标是世界系**（Point-LIO 建图坐标系），x/y/yaw 的正负号与朝向
   **还没在实机标定过**。第一次用先发一个小距离（0.2~0.3 m）看它往哪个方向走，
   别直接发几米的目标。狗端 goto 的日志里 1Hz 打着"现在位姿 → 目标 → 距离/航向误差"，
   对着看就能判出方向对不对。
2. **手柄一动就抢走控制权**（小脑行为），此后所有指令被忽略。闭环步骤会检测到并失败，
   提示"先放开手柄"。
3. **`passive` 已从上层移除，且 2026-10-01 起小脑的 ROS 接口也直接拒绝它**
   （`passive`/`stop`/`safe_stop` → 立即 `REJECTED`）。趴下一律用 `getdown`（2s 平滑趴下）；
   只有手柄 P 键与内置 Web 调试台（WebSocket）还保留 passive。
4. **`check_stand` 通过 ≠ getup 一定能成**：小脑的 Passive→GetUp 门控读的是
   `motors_ready_for_stand`，它只在开机/`zero_motor` 时重算。起立被静默拒绝时，
   先发一次 `zero_motor <id>` 或重启控制器。
