# rl_briefing —— 作业交底语音播报

狗在作业前把"安全交底"念出来：网页上点几个场景 → 语音顺序播报。
**大脑侧的 ROS 2 包**（2026-09-29 从小脑备份 `rl_sar-w2_recovered_v3` 的 `rl_briefing`
移植过来；原来那版跑在小脑、输出到一块 USB 声卡，那块卡现在不在了）。

## 话题（**网页早就按这个协议写好了**，见 `web/js/ros-bridge.js`）

| 话题 | 方向 | 类型 | 内容 |
|---|---|---|---|
| `/rl_briefing/play` | web → 本节点 | `std_msgs/String` | `"<场景>"` / `"<a,b,c>"`（顺序连播）/ `"stop"` / `"list"` |
| `/rl_briefing/status` | 本节点 → web | `std_msgs/String` | 纯文本，网页直接 toast |

状态文案：`playing: forklift (2/3)`、`done: forklift,elevator`、`stopped`、
`not found: xxx`、`wav load failed: xxx`、`audio open failed: <device>`、
`audio list: elevator forklift …`

## 场景与音频

- 场景定义（id / 中文名 / 关键词 / 逐句稿子）在 `config/safety_briefings.yaml`：
  `elevator` 货运电梯、`forklift` 叉车、`lifting` 起重机吊装、`warehouse` 库区常规、`height` 高处。
- **音频文件不在包里**（可替换资源，不跟代码一起版本化），默认放 `~/briefing_audio/<id>.wav`，
  48kHz 单声道 PCM16。路径用 `audio_dir` 参数改。
- 生成/替换音频：`scripts/make_wavs.py`（见下）。
  原来的 NPU 方案（voice-assistant + Matcha + RKNN 声码器）保留在同目录
  `scripts/briefing_tts.py` 里作出处 —— 那套部署在小脑上，随重装系统丢了。

## 起

跟着链路一起起（`slam_only.launch.py` 里有它），或单独起：

```bash
~/rosrun.sh 'ros2 launch rl_briefing briefing_player.launch.py'
~/rosrun.sh 'ros2 launch rl_briefing briefing_player.launch.py device:=dmix:CARD=realtekrt5616co,DEV=0'
```

命令行试一下：

```bash
~/rosrun.sh 'ros2 topic pub --once /rl_briefing/play std_msgs/msg/String "{data: forklift}"'
~/rosrun.sh 'ros2 topic echo /rl_briefing/status'      # 另开一个看状态
```

## 音频设备

默认 `device=plughw:CARD=A311,DEV=0` —— **机器人喇叭那块 USB 免驱声卡**
（Yundea A31-1，就是原版在小脑上用的那块，插到大脑上后是 card 2）。用**卡名**而不是
卡号：插拔别的 USB 设备会让卡号变。

`aplay -L` 能列出所有可选：

| 设备 | 说明 |
|---|---|
| `plughw:CARD=A311,DEV=0` | **默认**，外接 USB 声卡（喇叭） |
| `plughw:CARD=realtekrt5616co,DEV=0` | 板载 codec —— 声音从**板子的耳机口**出来，不插耳机就是哑的 |
| `dmix:CARD=A311,DEV=0` | 允许和其它程序的声音混着播 |
| `default` | 系统默认（当前指向板载 codec，**不是喇叭**） |

音量：`alsamixer -c 2`（USB 卡是 card 2，只有一个 `PCM` 控件；出厂/默认可能只有 30%）。
命令行快速调：`amixer -c 2 sset PCM 80%`。

## 生成音频（TTS）

```bash
# 在能联网的机器上跑（音质好），再把 wav 传到板子
python3 scripts/make_wavs.py --backend edge --out ~/briefing_audio     # 全部 5 个场景
python3 scripts/make_wavs.py --backend edge --out out --scene forklift # 只一个

# 或者板上离线跑（要 sudo apt install espeak-ng；音质机械）
python3 scripts/make_wavs.py --backend espeak --out ~/briefing_audio
```

`--voice`（edge 默认 `zh-CN-YunjianNeural` 男声播报）、`--rate`（默认 -8%，比日常慢一点）、
`--speed`（espeak 语速）。脚本逐句合成、按原 NPU 脚本的 0.11s/0.14s 补静音垫 ——
稿子本来就是按口语短句切好的（数字已转中文），逐句送 TTS 比整段送清楚。

## 移植时改了什么

1. **`device` 默认改成 `default`**（原版写死小脑的 USB 声卡 `plughw:3,0`）。
2. **`audio_dir` 默认改成 `/home/jinjiao/briefing_audio`**（原版是建包那台机器的路径）。
3. **补上逗号连播**：原版把 `"forklift,elevator"` 当**一个文件**去找，直接 `not found`；
   而网页多选就是按点选顺序拼成这种串发的。现在会拆开、顺序播，并在状态里报 `(2/3)`。
4. 节点名 `audio_player_node` → `briefing_player`。
5. 多了一段 `scripts/make_wavs.py`（可移植 TTS）与这份 README。

## 和小脑那条路的关系

小脑的 `rl_sar` 里也有一套 briefing（`web_bridge` 的 `{"type":"briefing"}` /
`briefing_status` 帧，同一批代码的另一半）。**但现在小脑没有声卡**，而网页走的是
ROS 话题（经大脑的 rosbridge），所以实际发声的是这个包。小脑那边的 WS 帧目前只在
`dog_ws_bridge` 里打日志 —— 如果以后喇叭改挂到小脑，把那个桥按 `/rl_briefing/play`
转一帧过去即可，协议是通的。
