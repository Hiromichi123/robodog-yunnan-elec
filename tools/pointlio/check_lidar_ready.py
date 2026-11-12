"""Bounded raw-data preflight; does not start or stop the driver."""
import time
import rclpy
from rclpy.qos import qos_profile_sensor_data
from livox_ros_driver2.msg import CustomMsg
from sensor_msgs.msg import Imu


def main():
    rclpy.init()
    node = rclpy.create_node('slam_lidar_preflight')
    counts = {'lidar': 0, 'imu': 0}
    def received(key):
        def callback(msg):
            if key != 'lidar' or msg.point_num > 0:
                counts[key] += 1
        return callback
    subscriptions = [
        node.create_subscription(CustomMsg, '/livox/lidar', received('lidar'), qos_profile_sensor_data),
        node.create_subscription(Imu, '/livox/imu', received('imu'), qos_profile_sensor_data),
    ]
    deadline = time.monotonic() + 15
    try:
        while min(counts.values()) < 2 and time.monotonic() < deadline:
            rclpy.spin_once(node, timeout_sec=0.2)
        if min(counts.values()) < 2:
            print('SLAM 启动失败：未收到持续雷达点云/IMU数据 ' + str(counts) +
                  '。驱动独立运行，请检查 systemctl status jxg-lidar 和 journalctl -u jxg-lidar；本开关不会启动驱动。', flush=True)
            return 2
        print('独立雷达驱动数据已就绪：' + str(counts), flush=True)
        return 0
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    raise SystemExit(main())
