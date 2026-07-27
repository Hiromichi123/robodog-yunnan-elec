#!/usr/bin/env python3
"""踝关节轮子电机速度测试 - 发送小速度到 /cmd_vel"""
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import sys

class AnkleTest(Node):
    def __init__(self, vx=0.3, duration=3.0):
        super().__init__('ankle_test')
        self.pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.vx = float(vx)
        self.duration = float(duration)
        self.timer = self.create_timer(0.05, self.send_cmd)
        self.start = self.get_clock().now()
        self.get_logger().info(f'发送 vx={self.vx} m/s, 持续 {self.duration}s...')

    def send_cmd(self):
        elapsed = (self.get_clock().now() - self.start).nanoseconds / 1e9
        if elapsed > self.duration:
            self.get_logger().info('测试完成，停止发送')
            self.destroy_node()
            rclpy.shutdown()
            return
        msg = Twist()
        msg.linear.x = self.vx
        self.pub.publish(msg)

def main():
    rclpy.init()
    vx = sys.argv[1] if len(sys.argv) > 1 else '0.3'
    dur = sys.argv[2] if len(sys.argv) > 2 else '3.0'
    node = AnkleTest(vx, dur)
    rclpy.spin(node)

if __name__ == '__main__':
    main()
