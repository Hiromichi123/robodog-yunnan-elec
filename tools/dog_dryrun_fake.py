#!/usr/bin/env python3
"""假小脑：给 dog_node 造一个"听话的机器人"，用来**不接狗**跑完整任务流程。

它做什么：
  订阅 /dryrun/command（dog_node 发来的 FSM 命令），过 latency_s 秒后：
    · 发 /dryrun/cmd_state  {"seq":n,"cmd":"getup","code":2,"phase":"DONE",
                             "target":"RLFSMStateGetUp","state":"RLFSMStateGetUp"}
    · 发 /dryrun/feedback   "status state=RLFSMStateGetUp gamepad_override=false"
  另外 2Hz 重发一次 feedback（dog_node 的 current_fsm_state_ 靠它维持新鲜）。

  它会照着真小脑的 FSM 规则拒绝非法切换（比如趴着就 getdown），这样
  dog_node 的"前置判断"那一关也能被真实验证到。

配 dog_node 一起跑（**所有 /rl_real/* 都要 remap 走，别碰真狗那一路**）。
本脚本在仓库 tools/ 下；板上完整路径
~/ros2_ws/src/robodog-yunnan-elec/tools/dog_dryrun_fake.py

    # 0) 假小脑
    ~/rosrun.sh 'python3 ~/ros2_ws/src/robodog-yunnan-elec/tools/dog_dryrun_fake.py'

    # 1) 假位姿：把 /dryrun/cmd_vel 积分成 /fake/odom
    ~/rosrun.sh 'ros2 run dog_nav_demo fake_pose --ros-args \
        -p cmd_vel_topic:=/dryrun/cmd_vel -p odom_topic:=/fake/odom'

    # 2) 位姿桥：把 /fake/odom 变成 /lidar_data_dryrun
    #    ⚠️ apply_mount_transform 默认 true，会把假位姿按 45° 安装角转一道，必须关掉
    #    ⚠️ real_robot_odom_topic 要指到不存在的话题，否则会和正在跑的 Point-LIO 抢
    ~/rosrun.sh 'ros2 run ros2_tools lidar_data_node --ros-args \
        -r __node:=lidar_data_dryrun -r lidar_data:=/lidar_data_dryrun \
        -p real_robot_odom_topic:=/dryrun_none \
        -p simulation_odom_topic:=/fake/odom -p apply_mount_transform:=false'

    # 3) dog_node：全话题走 /dryrun/*
    ~/rosrun.sh 'ros2 run core_2026 dog_node --ros-args \
        -p wait_for_mission:=true -p confirm_transitions:=false \
        -p lidar_pose_topic:=/lidar_data_dryrun \
        -p cmd_vel_topic:=/dryrun/cmd_vel -p fsm_command_topic:=/dryrun/command \
        -p cmd_state_topic:=/dryrun/cmd_state -p dog_state_topic:=/dryrun/feedback'

    # 4) 看进度（网页上也能看：连 rosbridge 后开「任务编排」页签）
    ~/rosrun.sh 'ros2 topic echo /dog/mission_status'

这样能验：任务解析/拒绝、四道状态把关、逐步确认的暂停与继续、急停的响应速度、
move/goto 的自循环与到位判据 —— 全程不发一条真命令。
"""

import json
import time

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

# 命令 → 执行成功后的 FSM 状态。与真小脑 fsm_JXGw.hpp 的分支一致。
CMD_TO_STATE = {
    'getup':      'RLFSMStateGetUp',
    'stand':      'RLFSMStateGetUp',
    'locomotion': 'RLFSMStateRLLocomotion',
    'rl':         'RLFSMStateRLLocomotion',
    'getdown':    'RLFSMStatePassive',   # GetDown 是过渡态，动画跑完就是 Passive
    'down':       'RLFSMStatePassive',
    'vel_stop':   None,                  # 只归零速度，不动状态
    'hold':       None,
    'zero':       None,
    'check_stand': None,                 # 查询型：不改状态
}

# 合法切换的前置状态（空 = 无条件）。照真小脑：趴着才能起立，站着才能进 RL/趴下。
PRECOND = {
    'getup':      ('RLFSMStatePassive',),
    'stand':      ('RLFSMStatePassive',),
    'locomotion': ('RLFSMStateGetUp',),
    'rl':         ('RLFSMStateGetUp',),
    'getdown':    ('RLFSMStateRLLocomotion',),
    'down':       ('RLFSMStateRLLocomotion',),
}


class FakeCerebellum(Node):
    def __init__(self):
        super().__init__('dog_dryrun_fake')
        self.declare_parameter('command_topic',    '/dryrun/command')
        self.declare_parameter('cmd_state_topic',  '/dryrun/cmd_state')
        self.declare_parameter('feedback_topic',   '/dryrun/feedback')
        self.declare_parameter('check_result_topic', '/dryrun/check_stand_result')
        self.declare_parameter('latency_s', 0.5)          # 模拟小脑的处理耗时
        self.declare_parameter('feedback_hz', 2.0)        # 与真桥一致：2Hz 刷状态
        self.declare_parameter('reject_illegal', True)    # 非法切换照真机拒绝

        gp = self.get_parameter
        self.latency = gp('latency_s').value
        self.state = 'RLFSMStatePassive'
        self.seq = 0
        self.pending = []      # [(due_time, cmd)]

        self.cmd_state_pub = self.create_publisher(String, gp('cmd_state_topic').value, 10)
        self.feedback_pub  = self.create_publisher(String, gp('feedback_topic').value, 10)
        self.check_pub     = self.create_publisher(String, gp('check_result_topic').value, 10)
        self.create_subscription(String, gp('command_topic').value, self.on_command, 10)

        period = 1.0 / max(0.1, gp('feedback_hz').value)
        self.create_timer(period, self.publish_feedback)
        self.create_timer(0.05, self.tick)
        self.get_logger().info(
            f'假小脑就绪：命令={gp("command_topic").value} 初始状态={self.state}')
        self.publish_feedback()

    # ── 收命令 ────────────────────────────────────────────────────────
    def on_command(self, msg: String):
        cmd = (msg.data or '').strip().lower()
        self.seq += 1
        seq = self.seq
        self.get_logger().info(f'← {cmd} (seq={seq})')

        if cmd == 'check_stand':
            self.check_pub.publish(String(data=json.dumps(
                {'ready': True, 'motors_ready': True, 'imu_ready': True, 'reason': ''})))
            target = None
            code = 2
        elif cmd in CMD_TO_STATE:
            target = CMD_TO_STATE[cmd]
            need = PRECOND.get(cmd)
            if self.get_parameter('reject_illegal').value and need and self.state not in need:
                # 照真机：前置不满足 → REJECTED，状态不变
                self.pending.append((time.monotonic() + self.latency * 0.4,
                                     (seq, cmd, 4, 'REJECTED', target, self.state)))
                self.get_logger().warn(f'→ REJECTED {cmd}（当前 {self.state}，需要 {need}）')
                return
            code = 2
        else:
            # 未知命令照样回 REJECTED，别让上层干等
            self.pending.append((time.monotonic() + 0.1,
                                 (seq, cmd, 4, 'REJECTED', None, self.state)))
            self.get_logger().warn(f'→ REJECTED 未知命令 {cmd}')
            return

        self.pending.append((time.monotonic() + self.latency,
                             (seq, cmd, code, 'DONE', target, target or self.state)))

    def tick(self):
        now = time.monotonic()
        while self.pending and self.pending[0][0] <= now:
            _, (seq, cmd, code, phase, target, final_state) = self.pending.pop(0)
            if code == 2 and target:
                self.state = target
            self.cmd_state_pub.publish(String(data=json.dumps({
                'seq': seq, 'cmd': cmd, 'code': code, 'phase': phase,
                'target': target, 'state': self.state, 'elapsed_ms': int(self.latency * 1000),
            })))
            self.get_logger().info(f'→ {cmd} code={code} {phase}（现在 {self.state}）')
            self.publish_feedback()

    def publish_feedback(self):
        self.feedback_pub.publish(String(
            data=f'status state={self.state} gamepad_override=false'))


def main():
    rclpy.init()
    node = FakeCerebellum()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == '__main__':
    main()
