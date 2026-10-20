# Web 避障页配置（2026-10-17）

## 范围和生效方式

独立「避障」页用于配置 **dog_node 任务速度通道** 的近场保护。手动遥控和其他节点直接发布 `/rl_real/cmd_vel` 不经过该保护，不可把页面状态理解为全车防撞保证。

主开关开启为 enforce，关闭为 disabled；高级 observe 仅诊断、不拦截速度。修改表单不立即生效，点击「保存」后写入大脑 `~/.config/robodog/local_safety.json`，**下次明确启动相关链路时加载**。保存、读取、切换页签均不会启动/重启进程或发送运动指令。

页面区分草稿、已保存和实际运行配置。保存不需要 ROS 在线；运行状态需要 ROS，超过 3 秒未更新即未知。切换配置后若已有 SLAM/狗节点使用旧快照，启动另一半会被拒绝，必须通过原有生命周期入口手动停止相关链路并重新启动。不要用改文件或重复点启动绕过这一检查。

## 雷达单源与真实有效性门禁

避障仅使用 `/cloud_registered_body`；不依赖深度相机，不设人工标定验收门禁。旧 `calibration_validated` 参数仅兼容解析，不决定放行，也不会被冒充设置为 true。雷达、位姿、时间戳、坐标/TF、会话、配置版本、足迹及扫掠制停检查继续有效；unknown 不等于 free。

自车排除盒在 base_link 中为 x±0.55m、y±0.35m、z[-0.30,+0.15]m（含边界）；传感器距离严格小于0.30m的点丢弃。丢弃点不产生清空射线，也不把自车盒标为自由空间。过滤与运动足迹/安全余量独立。

Point-LIO 辅助进程只启动受管的安全感知节点，不再补相机TF或深度转换器。其他相机/视觉建图功能保持独立。雷达盲区、腿部遮挡和证据不足仍可能导致拒绝起步；取消固定标定门禁不是全场景防撞保证。

## 配置和接口

- 权威字段描述/默认值/校验：`core_2026/scripts/safety_config.py`，安装到 `share/core_2026/safety_config.py`。
- GET `/api/avoidance/config`：读取保存配置、默认值、字段描述和只读感知策略。
- POST 同一接口：`{"expected_revision":"...","config":{"mode":"...","control":{},"perception":{}}}`，需要同源 Origin 和 JSON。
- revision 是 schema+雷达单源/过滤策略+规范化配置的 SHA256。过时写入返回 409；坏配置拒绝启动，不静默回退 disabled。
- Web 生命周期快照：`~/logs/safety-snapshots/safety-<revision>.json`。CLI Point-LIO 快照：`~/.config/robodog/startup-snapshots/`。
- 两组件传入相同冻结快照。`LocalSafetyMap.config_revision` 由控制端验证，不能仅在网页比较。
- `/dog/safety/status`、`/local_safety/status`：每秒 String JSON 实际运行诊断，协议版本 2；不传完整栅格。
- 直接 `ros2 run` 的旧显式 CLI 默认标识为 `lidar-only-explicit-v2`，不是 Web 已保存配置，页面不将其当成已应用。
- 脚本权威副本在 `tools/pointlio/`，家目录同名脚本是部署副本。

## 验证和上线注意

Python 配置/HTTP/生命周期测试使用临时文件和 mock 进程；C++ 安全测试与干跑必须在隔离 ROS domain、仅 lo DDS、测试话题环境运行，绝不连接真实运动桥。

修改了自定义消息，必须同时重编 `ros2_tools` 和 `core_2026`，安装配置模块与 helper 后再更新 Web Python 服务。生产部署及 Web 服务重启需要明确授权；不能只替换网页后声称后端已接通。保留既有 Git 修改和 goto 保存参数，先逐文件备份和校验基线。

保存schema为2；合法v1配置仅在内存迁移，GET/启动不改原文件。旧策略启动快照不可复用。只有显式保存写入v2。
