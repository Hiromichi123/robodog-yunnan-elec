"""Deterministic DDS timestamp boundaries; no hardware or ROS graph required."""
import json
from types import SimpleNamespace
from unittest.mock import patch

import pytest

pytest.importorskip('rclpy')
from geometry_msgs.msg import Twist
from std_msgs.msg import String
from tracked_base_bridge.core import Config, Controller
from tracked_base_bridge.pwm import MockPWM
from tracked_base_bridge.protocol import Commands
from tracked_base_bridge.node import TrackedBaseNode


@pytest.fixture(params=[dict, SimpleNamespace])
def metadata(request):
    return request.param


class Publisher:
    def __init__(self):
        self.messages = []

    def publish(self, msg):
        self.messages.append(msg)


def fixture():
    controller = Controller(Config(), MockPWM((1500, 1500)))
    return SimpleNamespace(controller=controller, commands=Commands(controller),
                           velocity_after_ns=1_000_000_000,
                           state_pub=Publisher(), feedback_pub=Publisher())


@pytest.mark.parametrize('stamp', [0, 999_999_999, 1_000_000_000, 1_500_000_001])
def test_velocity_rejects_unknown_pre_enable_future(stamp, metadata):
    node = fixture()
    node.controller.command('enable')
    msg = Twist()
    msg.linear.x = .5
    with patch('tracked_base_bridge.node.time.time_ns', return_value=1_500_000_000):
        TrackedBaseNode.velocity_cb(node, msg, metadata(source_timestamp=stamp))
    assert node.controller.last_velocity is None
    assert node.controller.target == (1500, 1500)


def test_velocity_stale_boundary_and_fresh(metadata):
    node = fixture()
    node.controller.command('enable')
    msg = Twist()
    msg.linear.x = .5
    with patch('tracked_base_bridge.node.time.time_ns', return_value=1_600_000_000):
        TrackedBaseNode.velocity_cb(node, msg, metadata(source_timestamp=1_100_000_000))
        assert node.controller.last_velocity is None
        TrackedBaseNode.velocity_cb(node, msg, metadata(source_timestamp=1_100_000_001))
    assert node.controller.target == (2000, 2000)


@pytest.mark.parametrize('stamp', [0, 1_000_000_000, 1_500_000_001])
def test_stale_enable_rejected(stamp, metadata):
    node = fixture()
    with patch('tracked_base_bridge.node.time.time_ns', return_value=1_500_000_000):
        TrackedBaseNode.command_cb(node, String(data='enable'), metadata(source_timestamp=stamp))
    assert node.controller.state == 'DISARMED'
    assert json.loads(node.state_pub.messages[-1].data)['code'] == 4


def test_old_disable_is_safe_and_resets_velocity_barrier(metadata):
    node = fixture()
    node.controller.command('enable')
    node.controller.velocity(.5, 0)
    with patch('tracked_base_bridge.node.time.time_ns', return_value=1_500_000_000):
        TrackedBaseNode.command_cb(node, String(data='disable'), metadata(source_timestamp=0))
    assert node.controller.state == 'DISARMED'
    assert node.controller.target == (1500, 1500)
    assert node.velocity_after_ns == 1_500_000_000
