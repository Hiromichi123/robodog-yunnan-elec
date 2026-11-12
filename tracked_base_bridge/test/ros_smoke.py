"""Installed-node DDS acceptance test. Mock only, private local ROS domain."""
import json
import os
from pathlib import Path
import signal
import subprocess
import sys
import tempfile
import time


def main():
    # Set before importing rclpy; never join the production domain by default.
    domain = int(os.environ.get('TRACKED_TEST_DOMAIN', '173'))
    if not 1 <= domain <= 232:
        raise ValueError('TRACKED_TEST_DOMAIN must be in 1..232')
    os.environ['ROS_DOMAIN_ID'] = str(domain)
    os.environ['ROS_AUTOMATIC_DISCOVERY_RANGE'] = 'LOCALHOST'
    os.environ['ROS_LOCALHOST_ONLY'] = '1'
    import rclpy
    from geometry_msgs.msg import Twist
    from std_msgs.msg import String
    from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy
    from rcl_interfaces.srv import SetParameters
    from rcl_interfaces.msg import Parameter, ParameterValue, ParameterType
    from tracked_base_bridge.core import Config

    rclpy.init()
    probe = rclpy.create_node('tracked_base_acceptance')
    process = None
    log = tempfile.TemporaryFile(mode='w+')
    hearts, events = [], []
    qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.RELIABLE,
                     durability=DurabilityPolicy.VOLATILE)
    probe.create_subscription(String, '/tracked_base/heartbeat',
                              lambda m: hearts.append(json.loads(m.data)), qos)
    probe.create_subscription(String, '/tracked_base/cmd_state',
                              lambda m: events.append(json.loads(m.data)), qos)
    commands = probe.create_publisher(String, '/tracked_base/command', qos)
    velocity = probe.create_publisher(Twist, '/tracked_base/cmd_vel', qos)
    seq = 0
    checks = []

    def spin(seconds):
        end = time.monotonic() + seconds
        while time.monotonic() < end:
            rclpy.spin_once(probe, timeout_sec=0.02)

    def wait(predicate, timeout=5, send=None):
        end = time.monotonic() + timeout
        while time.monotonic() < end:
            if process is not None and process.poll() is not None:
                raise AssertionError('mock launch exited unexpectedly')
            if send:
                send()
            rclpy.spin_once(probe, timeout_sec=0.03)
            if predicate():
                return
        raise AssertionError('timed out waiting for DDS acceptance condition')

    def command(cmd, code=2, sequence=None):
        nonlocal seq
        if sequence is None:
            seq += 1
            sequence = seq
        start = len(events)
        commands.publish(String(data=json.dumps(dict(cmd=cmd, seq=sequence))))
        wait(lambda: any(e['seq'] == sequence and e['cmd'] == cmd and
                         e['code'] == code for e in events[start:]))
        return sequence, events[start:]

    def heartbeat(state, pulses=None, send=None):
        start = len(hearts)
        wait(lambda: any(h['state'] == state and
                         (pulses is None or h['commanded_pulse_us'] == list(pulses))
                         for h in hearts[start:]), send=send)
        h = hearts[-1]
        assert h['backend'] == 'mock' and h['physical_feedback'] is False
        assert h['mapping_confirmed'] is False

    def drive(vx, wz, **extra):
        msg = Twist()
        msg.linear.x, msg.angular.z = float(vx), float(wz)
        msg.linear.y = extra.get('linear_y', 0.0)
        return lambda: velocity.publish(msg)

    def passed(name):
        checks.append(name)
        print('PASS:', name, flush=True)

    try:
        spin(1.5)
        assert not any(ns == '/tracked_base' for _, ns in probe.get_node_names_and_namespaces()), 'test domain occupied'
        assert not hearts and commands.get_subscription_count() == 0 and velocity.get_subscription_count() == 0, 'test topics occupied'
        # The default installed YAML is exercised; no user-supplied config or sysfs path.
        from ament_index_python.packages import get_package_share_directory
        import yaml
        config_path = Path(get_package_share_directory('tracked_base_bridge')) / 'config/tracked_base.yaml'
        params = yaml.safe_load(config_path.read_text())['/tracked_base/tracked_base_bridge']['ros__parameters']
        assert params['backend'] == 'mock' and params['allow_hardware'] is False and params['mapping_confirmed'] is False
        config = Config()
        assert all(params[k] == getattr(config, k) for k in ('track_width_m', 'max_track_speed_mps', 'max_vx_mps', 'max_wz_rps', 'timeout_s'))
        process = subprocess.Popen(['ros2', 'launch', 'tracked_base_bridge', 'tracked_base.launch.py'],
                                   stdout=log, stderr=subprocess.STDOUT, start_new_session=True)
        wait(lambda: commands.get_subscription_count() == 1 and velocity.get_subscription_count() == 1)
        heartbeat('DISARMED', config.neutral)
        heartbeat('DISARMED', config.neutral, drive(.5, 0))
        passed('startup disarmed; velocity cannot enable')
        _, result = command('enable')
        assert [e['code'] for e in result if e['cmd'] == 'enable'] == [0, 2]
        # Maintain velocities while observing 2Hz heartbeat, not a single long-lived sample.
        for vx, wz in ((.5, 0), (-.5, 0), (0, 1), (0, -1), (.5, 1), (5, 3)):
            command('enable')
            heartbeat('ENABLED', config.mix(vx, wz), drive(vx, wz))
        passed('enable lifecycle; forward/reverse/turn/curvature-preserving limits')
        command('vel_stop')
        # Status event is immediate; heartbeat may arrive after the watchdog disarms.
        assert events[-1]['state'] == 'ENABLED'
        heartbeat('DISARMED', config.neutral)
        passed('vel_stop neutral then idle watchdog disarms')
        command('enable')
        command('disable')
        heartbeat('DISARMED', config.neutral, drive(.5, 0))
        passed('disable blocks subsequent velocities')
        command('enable')
        heartbeat('DISARMED', config.neutral)
        passed('enable without velocity times out')
        command('enable')
        heartbeat('ENABLED', config.mix(.5, 0), drive(.5, 0))
        heartbeat('DISARMED', config.neutral)
        passed('velocity stream loss disarms')
        command('enable')
        start = time.monotonic()
        while time.monotonic() - start < .3:
            command('enable')
            spin(.04)
        heartbeat('DISARMED', config.neutral)
        passed('repeated enable without velocity still times out')
        command('disable')
        duplicate, _ = command('enable')
        command('disable')
        command('enable', code=4, sequence=duplicate)
        heartbeat('DISARMED', config.neutral)
        for cmd in ('getup', 'getdown', 'locomotion', 'nav_on', 'passive'):
            command(cmd, code=4)
        passed('sequence deduplication; dog commands rejected')
        for send in (drive(.1, 0, linear_y=1.0), drive(float('nan'), 0)):
            command('enable')
            heartbeat('DISARMED', config.neutral, send)
        passed('invalid axis/non-finite velocity disarms')
        client = probe.create_client(SetParameters, '/tracked_base/tracked_base_bridge/set_parameters')
        assert client.wait_for_service(timeout_sec=3)
        request = SetParameters.Request(parameters=[Parameter(name='allow_hardware', value=ParameterValue(type=ParameterType.PARAMETER_BOOL, bool_value=True))])
        future = client.call_async(request)
        wait(future.done)
        assert future.result().results and not future.result().results[0].successful
        passed('runtime hardware parameter changes rejected')
        print(json.dumps({'domain': domain, 'checks': len(checks), 'result': 'PASS'}), flush=True)
    finally:
        if process is not None:
            if process.poll() is None:
                # Let launch forward one SIGINT; signalling the entire group
                # would interrupt the child twice, including during cleanup.
                process.send_signal(signal.SIGINT)
                try:
                    process.wait(timeout=10)
                except subprocess.TimeoutExpired:
                    os.killpg(process.pid, signal.SIGTERM)
                    try:
                        process.wait(timeout=5)
                    except subprocess.TimeoutExpired:
                        os.killpg(process.pid, signal.SIGKILL)
                        process.wait(timeout=5)
            log.seek(0)
            print(log.read(), flush=True)
        probe.destroy_node()
        rclpy.shutdown()
        log.close()


if __name__ == '__main__':
    main()
