#!/usr/bin/env python3
"""Read-only perception diagnostics test, synthetic isolated domain only.

ROS_DOMAIN_ID=189 ROS_LOCALHOST_ONLY=1 python3 tools/local_safety_status_selftest.py --isolated-demo
No sensor/bridge/motion node is started. Synthetic LiDAR/pose/origin/TF only; no camera or motion bridge.
"""
import argparse
import json
import os
import signal
import subprocess
import tempfile
import time
from pathlib import Path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--isolated-demo', action='store_true', required=True)
    args = parser.parse_args()
    if not args.isolated_demo or os.environ.get('ROS_DOMAIN_ID') != '189' or os.environ.get('ROS_LOCALHOST_ONLY') != '1':
        raise SystemExit('Refusing: domain 189, localhost and --isolated-demo are required')
    os.environ['ROS_AUTOMATIC_DISCOVERY_RANGE'] = 'LOCALHOST'
    os.environ['RMW_IMPLEMENTATION'] = 'rmw_cyclonedds_cpp'
    os.environ['CYCLONEDDS_URI'] = ('<CycloneDDS><Domain><General><Interfaces>'
        '<NetworkInterface name="lo"/></Interfaces><AllowMulticast>false</AllowMulticast>'
        '</General><Discovery><Peers><Peer Address="localhost"/></Peers></Discovery></Domain></CycloneDDS>')
    import rclpy
    from rcl_interfaces.msg import Parameter, ParameterType, ParameterValue
    from rcl_interfaces.srv import DescribeParameters, SetParametersAtomically
    import struct
    from nav_msgs.msg import Odometry
    from sensor_msgs.msg import PointCloud2, PointField
    from geometry_msgs.msg import TransformStamped
    from tf2_msgs.msg import TFMessage
    from rclpy.qos import QoSProfile, DurabilityPolicy
    from std_msgs.msg import String
    from ros2_tools.msg import LocalSafetyMap
    from ament_index_python.packages import get_package_prefix

    rclpy.init()
    node = rclpy.create_node('safety_status_selftest')
    statuses, maps = [], []
    node.create_subscription(String, '/safety_status_test/status', lambda m: statuses.append(json.loads(m.data)), 1)
    node.create_subscription(LocalSafetyMap, '/safety_status_test/map', maps.append, 1)
    process = None
    log = tempfile.TemporaryFile(mode='w+t', encoding='utf8')

    def spin_until(predicate, timeout=8):
        deadline = time.monotonic() + timeout
        while time.monotonic() < deadline:
            rclpy.spin_once(node, timeout_sec=0.02)
            if predicate():
                return
        raise AssertionError('Timed out waiting for isolated perception node')

    def request(service_type, suffix, body):
        client = node.create_client(service_type, '/local_obstacle_node/' + suffix)
        assert client.wait_for_service(timeout_sec=5), suffix
        future = client.call_async(body)
        spin_until(future.done)
        result = future.result()
        node.destroy_client(client)
        return result

    try:
        until = time.monotonic() + 1
        spin_until(lambda: time.monotonic() >= until)
        assert node.get_node_names() == [node.get_name()], 'Isolated domain is not empty'
        binary = Path(get_package_prefix('ros2_tools')) / 'lib/ros2_tools/local_obstacle_node'
        revision = 'a' * 64
        command = [str(binary), '--ros-args', '-p', 'config_revision:=' + revision,
                   '-p', 'max_range_m:=2.0', '-p', 'ground_z:=-0.25']
        for source, target in {
            '/local_safety/status': '/safety_status_test/status',
            '/local_safety/map': '/safety_status_test/map',
            '/navigation_origin': '/safety_status_test/origin',
            '/aft_mapped_to_init': '/safety_status_test/odom',
            '/cloud_registered_body': '/safety_status_test/lidar',
            '/camera/camera/depth/color/points': '/safety_status_test/depth',
            '/tf': '/safety_status_test/tf', '/tf_static': '/safety_status_test/tf_static',
        }.items():
            command += ['-r', source + ':=' + target]
        process = subprocess.Popen(command, stdout=log, stderr=subprocess.STDOUT, start_new_session=True)
        spin_until(lambda: len(statuses) >= 2 and bool(maps))
        status = statuses[-1]
        assert status['protocol_version'] == 2 and status['revision'] == revision
        assert maps[-1].config_revision == revision
        assert status['config']['perception']['max_range_m'] == 2.0
        assert status['max_return_range_m'] == 10.0
        assert status['config']['perception']['ground_z'] == -0.25
        assert not status['calibration_validated'] and not status['valid'] and not maps[-1].valid
        assert status['reason'] == 'navigation_origin_missing_or_stale'
        assert status['sensor_source'] == 'lidar' and status['calibration_required'] is False
        assert status['self_filter'] == dict(half_length=.55, half_width=.35, min_z=-.3, max_z=.15, min_range_m=.6)
        print('PASS fresh diagnostics report actual config, map revision and missing-input state without calibration gate')
        names = ['config_revision', 'calibration_validated', 'resolution', 'width', 'ground_z',
                 'obstacle_min_height', 'obstacle_max_height', 'free_ttl_s', 'floor_ttl_s',
                 'max_observation_age_s', 'max_pose_gap_s', 'max_range_m', 'max_clear_rays_per_cloud',
                 'self_half_length', 'self_half_width', 'self_min_z', 'self_max_z',
                 'odom_topic', 'lidar_topic', 'min_range_m', 'max_return_range_m']
        response = request(DescribeParameters, 'describe_parameters', DescribeParameters.Request(names=names))
        assert len(response.descriptors) == len(names)
        assert all(d.name == name and d.read_only for name, d in zip(names, response.descriptors))
        print('PASS all perception algorithm/input parameters are startup read-only')
        response = request(SetParametersAtomically, 'set_parameters_atomically',
            SetParametersAtomically.Request(parameters=[Parameter(name='max_range_m',
                value=ParameterValue(type=ParameterType.PARAMETER_DOUBLE, double_value=1.0))]))
        assert not response.result.successful
        before = len(statuses)
        spin_until(lambda: len(statuses) > before)
        assert statuses[-1]['config']['perception']['max_range_m'] == 2.0
        print('PASS rejected hot edit leaves actual running configuration unchanged')
        qos = QoSProfile(depth=1, durability=DurabilityPolicy.TRANSIENT_LOCAL)
        origin_pub = node.create_publisher(String, '/safety_status_test/origin', qos)
        tf_pub = node.create_publisher(TFMessage, '/safety_status_test/tf_static', qos)
        odom_pub = node.create_publisher(Odometry, '/safety_status_test/odom', 10)
        cloud_pub = node.create_publisher(PointCloud2, '/safety_status_test/lidar', 10)
        state = dict(points=[(1., .05, -.2)] * 30, frame='body', lidar=True, odom=True, x=0.)
        origin = String(data=json.dumps(dict(frame='startup_navigation', session_id='synthetic', x=0., y=0., z=0., yaw=0.)))
        tf = TransformStamped()
        tf.header.frame_id='base_link'; tf.child_frame_id='body'; tf.transform.rotation.w=1.
        def feed():
            stamp=node.get_clock().now().to_msg()
            origin_pub.publish(origin)
            tf.header.stamp=stamp; tf_pub.publish(TFMessage(transforms=[tf]))
            if state['odom']:
                odom=Odometry(); odom.header.stamp=stamp; odom.header.frame_id='camera_init'
                odom.child_frame_id='body'; odom.pose.pose.orientation.w=1.; odom.pose.pose.position.x=state['x']
                odom_pub.publish(odom)
            if state['lidar']:
                cloud=PointCloud2(); cloud.header.stamp=stamp; cloud.header.frame_id=state['frame']
                cloud.height=1; cloud.width=len(state['points']); cloud.point_step=12; cloud.row_step=12*cloud.width
                cloud.fields=[PointField(name=n, offset=i*4, datatype=PointField.FLOAT32, count=1) for i,n in enumerate(('x','y','z'))]
                cloud.data=b''.join(struct.pack('<fff',*point) for point in state['points'])
                cloud_pub.publish(cloud)
        timer=node.create_timer(.05,feed)
        def settle(valid, reason='', timeout=5):
            start=len(maps)
            spin_until(lambda: len(maps)>start+3 and maps[-1].valid==valid and reason in maps[-1].reason, timeout)
        settle(True)
        assert not any('/camera/' in name for name,_ in node.get_topic_names_and_types())
        assert -1 in maps[-1].grid.data, 'valid map must not imply all space free'
        print('PASS LiDAR-only valid without calibration/camera; unknown cells retained')
        state['points']=[(8.,.05,.4)]*30
        settle(True)
        assert 100 not in maps[-1].grid.data, 'far endpoint must not be a near-field hit'
        print('PASS far valid returns accepted without clipped endpoint obstacle')
        state['points']=[(10.01,0.,0.)]*30
        settle(False,'insufficient_valid_returns')
        state['points']=[(1.,.05,-.2)]*30
        settle(True)
        print('PASS returns beyond 10m rejected and transient fault recovers')

        for points,label in [([(0.,0.,.599)]*30,'near'), ([(.54,.34,-.29)]*30,'self box'),
                             ([(float('nan'),0.,0.)]*30,'NaN'),([], 'empty')]:
            state['points']=points; settle(False)
            assert 'insufficient_valid_returns' in maps[-1].reason or 'malformed_or_empty_cloud' in maps[-1].reason
            state['points']=[(1.,.05,-.2)]*30; settle(True)
            print('PASS rejected',label,'returns; valid LiDAR restores transient fault')
        state['points']=[(0.,0.,.6)]*30; settle(True)
        print('PASS 0.60m returns outside self box accepted')
        state['frame']='wrong_frame'; settle(False,'unexpected_cloud_frame')
        state['frame']='body'; settle(True)
        print('PASS invalid frame blocks, correct frame recovers')
        state['lidar']=False; settle(False,'stale'); state['lidar']=True; settle(True)
        print('PASS LiDAR dropout blocks despite ongoing odometry')
        state['odom']=False; settle(False,'odometry_missing_or_stale')
        state['odom']=True; settle(True)
        print('PASS stale odometry blocks despite ongoing LiDAR')
        state['x']=5.; settle(False,'odometry_reset_or_jump')
        state['x']=0.; settle(False,'odometry_reset_or_jump')
        print('PASS pose jump remains latched')
        node.destroy_timer(timer)

    except Exception:
        log.seek(0)
        print(log.read())
        raise
    finally:
        if process is not None and process.poll() is None:
            os.killpg(process.pid, signal.SIGINT)
            try:
                process.wait(timeout=8)
            except subprocess.TimeoutExpired:
                os.killpg(process.pid, signal.SIGKILL)
                process.wait()
        log.close()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
