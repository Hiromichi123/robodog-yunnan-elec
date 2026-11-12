"""Standalone ROS 2 adapter. Nothing here starts the dog or a mission."""
import json
import time

import rclpy
from rclpy.node import Node
from rclpy.clock import Clock, ClockType
from rclpy.duration import Duration
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy
from geometry_msgs.msg import Twist
from std_msgs.msg import String

from .core import Config, Controller, Mapping
from .protocol import Commands
from .pwm import (MockPWM, SysfsPWM, UsbGpioPWM, USB_RESOLUTION, USB_PERIOD_COUNTS)


class TrackedBaseNode(Node):
    def __init__(self):
        super().__init__('tracked_base_bridge', namespace='/tracked_base')
        self.controller = None
        self.backend = None
        self.started = time.monotonic()
        self.sequence = 0
        self.velocity_after_ns = time.time_ns()
        defaults = dict(backend='mock', allow_hardware=False, mapping_confirmed=False,
                        left_chip='', right_chip='', left_channel=-1, right_channel=-1,
                        serial_port='', serial_baud=115200, pwm_group=1,
                        left_pwm_channel=1, right_pwm_channel=2,
                        pwm_resolution_counts=USB_RESOLUTION,
                        pwm_period_counts=USB_PERIOD_COUNTS,
                        track_width_m=0.4, max_track_speed_mps=0.5, max_vx_mps=0.5,
                        max_wz_rps=1.0, timeout_s=0.5)
        for side in ('left', 'right'):
            defaults.update({f'{side}_reverse_us': 1000, f'{side}_neutral_us': 1500,
                             f'{side}_forward_us': 2000, f'{side}_inverted': False,
                             f'{side}_deadband': 0.02})
        for name, value in defaults.items():
            self.declare_parameter(name, value)
        p = lambda name: self.get_parameter(name).value
        mappings = [Mapping(**{key: p(f'{side}_{key}') for key in
                               ('reverse_us', 'neutral_us', 'forward_us', 'inverted', 'deadband')})
                    for side in ('left', 'right')]
        config = Config(**{name: p(name) for name in
                           ('track_width_m', 'max_track_speed_mps', 'max_vx_mps', 'max_wz_rps', 'timeout_s')},
                        left=mappings[0], right=mappings[1])
        config.validate()
        backend_name = p('backend')
        if backend_name not in ('mock', 'sysfs', 'usbgpio'):
            raise ValueError('backend must be mock, sysfs or usbgpio')
        self.mapping_confirmed = p('mapping_confirmed')
        try:
            if backend_name == 'mock':
                self.backend = MockPWM(config.neutral)
            elif backend_name == 'sysfs':
                self.backend = SysfsPWM(
                    [p('left_chip'), p('right_chip')],
                    [p('left_channel'), p('right_channel')], config.neutral,
                    allow_hardware=p('allow_hardware'),
                    mapping_confirmed=self.mapping_confirmed)
            else:
                self.backend = UsbGpioPWM(
                    p('serial_port'), p('pwm_group'),
                    [p('left_pwm_channel'), p('right_pwm_channel')], config.neutral,
                    allow_hardware=p('allow_hardware'),
                    mapping_confirmed=self.mapping_confirmed,
                    baud=p('serial_baud'),
                    resolution=p('pwm_resolution_counts'),
                    period_counts=p('pwm_period_counts'))
            self.controller = Controller(config, self.backend)
            if self.controller.state == 'FAULT':
                raise RuntimeError(self.controller.fault)
            self.commands = Commands(self.controller)
            output_qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.RELIABLE,
                                    durability=DurabilityPolicy.VOLATILE)
            input_qos = QoSProfile(depth=1, reliability=ReliabilityPolicy.RELIABLE,
                                   durability=DurabilityPolicy.VOLATILE,
                                   lifespan=Duration(seconds=config.timeout_s))
            self.feedback_pub = self.create_publisher(String, 'feedback', output_qos)
            self.state_pub = self.create_publisher(String, 'cmd_state', output_qos)
            self.heartbeat_pub = self.create_publisher(String, 'heartbeat', output_qos)
            self.create_subscription(Twist, 'cmd_vel', self.velocity_cb, input_qos)
            self.create_subscription(String, 'command', self.command_cb, input_qos)
            steady = Clock(clock_type=ClockType.STEADY_TIME)
            self.create_timer(0.02, self.tick, clock=steady)
            self.create_timer(0.5, self.heartbeat, clock=steady)
            # Runtime parameter changes are rejected: safety config is startup-only.
            self.add_on_set_parameters_callback(self.reject_parameters)
            self.get_logger().info('tracked_base backend=' + self.backend.name + '; initially DISARMED')
        except BaseException:
            self.close()
            raise

    @staticmethod
    def reject_parameters(parameters):
        from rcl_interfaces.msg import SetParametersResult
        return SetParametersResult(successful=False, reason='startup-only configuration; restart disarmed')

    def velocity_cb(self, msg, info):
        # ROS source timestamps use system time. This single-board interface rejects
        # pre-enable/stale/unknown samples rather than replaying queued velocities.
        source = info.get('source_timestamp', 0) if isinstance(info, dict) else info.source_timestamp
        now = time.time_ns()
        if source <= self.velocity_after_ns or source > now or now - source >= int(self.controller.config.timeout_s * 1e9):
            return
        self.controller.velocity(msg.linear.x, msg.angular.z,
                                 (msg.linear.y, msg.linear.z, msg.angular.x, msg.angular.y))

    def command_cb(self, msg, info):
        source = info.get('source_timestamp', 0) if isinstance(info, dict) else info.source_timestamp
        now = time.time_ns()
        # Stop commands are safe to execute even if old; enable is time-bounded.
        from .protocol import parse_command
        try:
            cmd, _ = parse_command(msg.data)
        except ValueError:
            cmd = ''
        if cmd == 'enable' and (source <= 0 or source > now or now - source >= int(self.controller.config.timeout_s * 1e9)):
            self.state_pub.publish(String(data=json.dumps(self.commands.event(
                'enable', 0, 4, 'stale enable rejected', time.monotonic()))))
            return
        before = self.controller.state
        events = self.commands.execute(msg.data)
        if cmd in ('disable', 'vel_stop') or (cmd == 'enable' and before != 'ENABLED'):
            self.velocity_after_ns = time.time_ns()
        for event in events:
            self.state_pub.publish(String(data=json.dumps(event)))
        self.feedback_pub.publish(String(data=f'{cmd} state={self.controller.state} reason={events[-1]["reason"]}'))

    def tick(self):
        before = self.controller.state
        self.controller.tick()
        if before != self.controller.state:
            self.velocity_after_ns = time.time_ns()
            self.feedback_pub.publish(String(data=f'watchdog state={self.controller.state} reason={self.controller.reason} fault={self.controller.fault}'))

    def heartbeat(self):
        self.sequence += 1
        c = self.controller
        data = dict(seq=self.sequence, model='tracked_base', backend=self.backend.name,
                    mapping_confirmed=self.mapping_confirmed, state=c.state,
                    armed=c.state == 'ENABLED', nav=c.state == 'ENABLED', active_seq=0,
                    uptime_ms=int((time.monotonic() - self.started) * 1000),
                    fault=c.fault, reason=c.reason,
                    commanded_pulse_us=list(c.target), physical_feedback=False)
        self.heartbeat_pub.publish(String(data=json.dumps(data)))

    def close(self):
        if self.controller is not None:
            self.controller.close()
        elif self.backend is not None:
            self.backend.close()


def main(args=None):
    rclpy.init(args=args)
    node = None
    try:
        node = TrackedBaseNode()
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if node is not None:
            node.close()
            node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
