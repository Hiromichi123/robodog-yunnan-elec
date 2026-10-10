#!/usr/bin/env python3
"""持续发「零点位姿」的假 /lidar_data —— 无雷达时的台架联调用。

**用途**：把整条链路（web / 桥 / dog_node）拉起来，但位姿来自假节点而不是
雷达。这样 dog_node 的前置检查（要 /lidar_data 上有数据）能过、网页能下发
任务，而**不依赖雷达和 Point-LIO**。典型场景：雷达没接、SLAM 起不来、
或只想单独验控制链的收发。

**它发的是恒定 (0,0,0)，所以只验"通不通"，不验"走得对不对"**：
狗的位姿永远停在原点，goto 这类闭环任务的距离永远不变 —— 必然收敛不了，
最后按超时失败。每 5 秒重复警告一次，就是怕有人忘了是假的还在那等它走到。
真要用假位姿驱动狗走，得让位姿动起来（那是另一件事，别在本节点上加）。

**切换**（slam_only.launch.py 的 `lidar_source` 参数，见 ~/start_slam.sh）：
    ~/start_slam.sh fake     # 本节点发 /lidar_data
    ~/start_slam.sh          # 默认 real：Point-LIO → lidar_data_node

**两个来源互斥**：真节点与本节点同时发 /lidar_data，控制环会拿到两份互相
矛盾的位姿（狗在两个位置之间来回跳，表现是无规律乱走，极难倒查 —— 和当年
"两份 Point-LIO 让地图出现平移第二层"是同一类坑）。launch 里用条件保证
只起一个；但手动 `ros2 run` 绕过了那层保护，所以本节点自己也查发布者数量。
"""

import rclpy
from rclpy.node import Node

from ros2_tools.msg import LidarPose


class FakeLidarData(Node):
    def __init__(self):
        super().__init__('fake_lidar_data')

        # 话题名做成参数：联调时想把它挂到别处（比如 /verify/lidar_data）
        # 不用改代码，也就不用担心误发到真的 /lidar_data 上。
        self.declare_parameter('topic', 'lidar_data')
        self.declare_parameter('rate_hz', 10.0)
        # 注意 rclpy 是 gp('x').value —— **没有** as_string()/as_double()，
        # 那两个是 rclcpp 的写法（这里踩过：AttributeError: no attribute 'as_string'）。
        gp = self.get_parameter
        topic = gp('topic').value
        rate_hz = max(0.1, gp('rate_hz').value)

        self.pub_ = self.create_publisher(LidarPose, topic, 10)

        # 六个字段全是 float64，默认就是 0.0 —— 建一次、每拍重发同一条。
        self.pose_ = LidarPose()

        self.create_timer(1.0 / rate_hz, self.on_timer)
        # 1Hz 查一次发布者数量：>1 说明真节点也在发，必须立刻喊出来。
        self.create_timer(1.0, self.check_publishers)

        self.get_logger().warn(
            f'假位姿已启动：{topic} @ {rate_hz:.1f}Hz，恒定 (0,0,0)。'
            '狗会一直以为自己停在原点没动过 —— 闭环任务必然收敛不了，'
            '本节点只用来验链路通不通。')

    def on_timer(self):
        self.pub_.publish(self.pose_)

    def check_publishers(self):
        n = self.count_publishers(self.pub_.topic_name)
        if n > 1:
            self.get_logger().error(
                f'{self.pub_.topic_name} 上有 {n} 个发布者 —— 真节点/假节点同时在发，'
                '控制环会拿到两份互相矛盾的位姿（狗会无规律乱走）。停掉其中一个。',
                throttle_duration_sec=2.0)


def main():
    rclpy.init()
    node = FakeLidarData()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
