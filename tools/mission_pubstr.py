#!/usr/bin/env python3
"""往一个 std_msgs/String 话题发一条文本（内容取自文件）。干跑测试用。

    python3 mission_pubstr.py <topic> <file>

板上（本脚本在仓库 tools/ 下）：
    ~/rosrun.sh 'python3 ~/ros2_ws/src/robodog-yunnan-elec/tools/mission_pubstr.py /dog/mission /tmp/m.json'
"""
import sys
import time

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

rclpy.init()
node = Node('dryrun_pubstr')
pub = node.create_publisher(String, sys.argv[1], 10)
text = open(sys.argv[2], encoding='utf-8').read()

# ⚠️ 板上节点多（rosbridge、Point-LIO、rosapi…），DDS 发现慢。
# 这个脚本是**短命节点**：create_publisher 之后立刻发，订阅方还没发现它，
# 帧会被静默丢掉 —— 实测反复踩到（有时任务话题丢、有时指令话题丢，看着像代码 bug）。
# 所以：先等 2s 让它被发现，再慢慢发 6 帧（1Hz），整个发布端活 8 秒。
# （生产链路没这问题：rosbridge 的发布端是常驻的。）
time.sleep(2.0)
for _ in range(6):
    pub.publish(String(data=text))
    time.sleep(1.0)
print(f'已发布 {sys.argv[1]}（{len(text)} 字节）')
node.destroy_node()
rclpy.try_shutdown()
