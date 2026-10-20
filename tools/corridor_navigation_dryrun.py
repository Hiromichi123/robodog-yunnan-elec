#!/usr/bin/env python3
"""Isolated executor integration test. Never launch a bridge or publish /rl_real/*.

Run after building, inside the ROS environment:
  ROS_DOMAIN_ID=187 ROS_LOCALHOST_ONLY=1 python3 tools/corridor_navigation_dryrun.py --isolated-demo

The explicit opt-in, fixed non-production domain, localhost discovery, remapped
interfaces, and empty-domain preflight are all required. This tests synthetic
maps/kinematics, not physical stopping distance or sensor coverage.
"""
import argparse
import json
import math
import os
import signal
import subprocess
import tempfile
import time
from pathlib import Path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--isolated-demo', action='store_true', required=True)
    parser.add_argument('--scenarios', nargs='+', help='Run selected known isolated scenarios')
    args = parser.parse_args()
    if not args.isolated_demo or os.environ.get('ROS_DOMAIN_ID') != '187':
        raise SystemExit('Refusing: set ROS_DOMAIN_ID=187 and pass --isolated-demo')
    if os.environ.get('ROS_LOCALHOST_ONLY') != '1':
        raise SystemExit('Refusing: ROS_LOCALHOST_ONLY=1 is required')
    os.environ['ROS_AUTOMATIC_DISCOVERY_RANGE'] = 'LOCALHOST'
    os.environ['RMW_IMPLEMENTATION'] = 'rmw_cyclonedds_cpp'
    os.environ['CYCLONEDDS_URI'] = '<CycloneDDS><Domain><General><Interfaces><NetworkInterface name="lo"/></Interfaces><AllowMulticast>false</AllowMulticast></General><Discovery><Peers><Peer Address="127.0.0.1"/></Peers></Discovery></Domain></CycloneDDS>'

    import rclpy
    from rclpy.node import Node
    from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy
    from geometry_msgs.msg import Twist
    from std_msgs.msg import String
    from ros2_tools.msg import LidarPose, LocalSafetyMap
    from ament_index_python.packages import get_package_prefix
    from rcl_interfaces.msg import Parameter,ParameterValue,ParameterType
    from rcl_interfaces.srv import SetParametersAtomically

    class Harness(Node):
        def __init__(self, scenario):
            super().__init__('corridor_dryrun_harness')
            self.scenario = scenario
            self.soft = scenario.startswith(("buffer_","arrival_","goal_"))
            self.x = self.y = self.yaw = 0.0
            self.vx = self.wz = 0.0
            self.command_at = 0.0
            self.sequence = self.cmd_sequence = 0
            self.statuses = []
            self.last_tick = time.monotonic()
            self.violation = ''
            self.fault_at = None
            self.motion_seen = False
            self.max_forward = 0.0
            self.reverse_seen = False
            self.reverse_start = None
            self.stop_checks=0
            self.origin_pub = self.create_publisher(String, '/corridor_test/origin', QoSProfile(
                depth=1, reliability=ReliabilityPolicy.RELIABLE,
                durability=DurabilityPolicy.TRANSIENT_LOCAL))
            self.pose_pub = self.create_publisher(LidarPose, '/corridor_test/pose', 10)
            self.map_pub = self.create_publisher(LocalSafetyMap, '/corridor_test/map', 1)
            self.feedback_pub = self.create_publisher(String, '/corridor_test/feedback', 10)
            self.cmd_state_pub = self.create_publisher(String, '/corridor_test/cmd_state', 10)
            self.mission_pub = self.create_publisher(String, '/corridor_test/mission', 10)
            self.mission_cmd_pub = self.create_publisher(String, '/corridor_test/mission_cmd', 10)
            self.create_subscription(Twist, '/corridor_test/cmd_vel', self.velocity, 10)
            self.create_subscription(String, '/corridor_test/command', self.command, 10)
            self.create_subscription(String, '/corridor_test/mission_status', self.status, 10)
            self.create_timer(0.05, self.tick)
            self.create_timer(0.1, self.publish_map)
            self.create_timer(0.2, self.publish_feedback)
            self.create_timer(0.5, self.publish_origin)

        def session_id(self):
            changed = self.scenario == 'origin_reset' and self.fault_at is not None
            return 'synthetic-'+self.scenario+('-reset' if changed else '')

        def publish_origin(self):
            self.origin_pub.publish(String(data=json.dumps(dict(
                frame='startup_navigation', session_id=self.session_id(),
                x=0.0, y=0.0, z=0.0, yaw=0.0))))

        def publish_feedback(self):
            self.feedback_pub.publish(String(data='status state=RLFSMStateRLLocomotion gamepad_override=false'))

        def command(self, msg):
            self.cmd_sequence += 1
            # This test never needs getup or getdown. Unexpected commands fail it.
            if msg.data != 'vel_stop':
                self.violation = 'Unexpected FSM command: '+msg.data
            self.vx = self.wz = 0.0
            if self.scenario.startswith('arrival_') and self.motion_seen:
                self.stop_checks+=1
                if self.scenario=='arrival_drift' and self.stop_checks==1 or self.scenario=='arrival_unstable':
                    self.x-=.12  # external pose disturbance during the acknowledged stop
                if self.scenario in ('arrival_dropout','arrival_body','arrival_unconfirmed','arrival_pose_dropout'):
                    self.fault_at=time.monotonic()
                if self.scenario in ('arrival_dropout','arrival_body'):self.publish_map()
                if self.scenario=='arrival_unconfirmed':return
            self.cmd_state_pub.publish(String(data=json.dumps(dict(
                seq=self.cmd_sequence, cmd=msg.data, code=2, phase='DONE',
                target='RLFSMStateRLLocomotion', state='RLFSMStateRLLocomotion', elapsed_ms=0))))
            self.publish_feedback()

        def velocity(self, msg):
            recovery_case=self.scenario in ('detour','reverse_escape','recovery_dropout')
            if abs(msg.linear.y) > 1e-9 or (msg.linear.x < -1e-9 and not recovery_case):
                self.violation = 'Unexpected lateral/reverse command'
            speed_limit=.45 if self.soft else .30 if self.scenario in ('unknown_explore','explore_blocked','detour','reverse_escape','recovery_dropout') else .15
            if abs(msg.linear.x) > speed_limit+1e-5 or abs(msg.angular.z) > 0.35001:
                self.violation = 'Command exceeds configured limits'
            if msg.linear.x < -1e-9:
                self.reverse_seen=True
                if abs(msg.linear.x)>.08001 or abs(msg.angular.z)>1e-9:
                    self.violation='Recovery reverse exceeds straight low-speed limit'
                if self.reverse_start is None:self.reverse_start=(self.x,self.y,time.monotonic())
                if math.hypot(self.x-self.reverse_start[0],self.y-self.reverse_start[1])>.301 or time.monotonic()-self.reverse_start[2]>4.2:
                    self.violation='Recovery reverse exceeds distance/time budget'
            elif msg.linear.x>1e-9 or abs(msg.angular.z)>1e-9:
                self.reverse_start=None
            self.vx, self.wz = msg.linear.x, msg.angular.z
            self.max_forward=max(self.max_forward,self.vx)
            self.command_at = time.monotonic()
            if abs(self.vx)+abs(self.wz) > 1e-9:
                self.motion_seen = True
                if self.fault_at is not None and self.command_at-self.fault_at > 0.7:
                    self.violation = 'Nonzero command after safety fault watchdog budget'
            if self.scenario in ('blocked_move','explore_blocked','buffer_fast','buffer_hard') and (abs(self.vx)+abs(self.wz)) > 1e-9:
                self.violation = 'Nonzero command in unknown/blocked scene'

        def status(self, msg):
            self.statuses.append(json.loads(msg.data))

        def tick(self):
            now = time.monotonic()
            dt = min(now-self.last_tick, 0.1)
            self.last_tick = now
            if now-self.command_at > 0.3:
                self.vx = self.wz = 0.0
            self.x += self.vx*math.cos(self.yaw)*dt
            self.y += self.vx*math.sin(self.yaw)*dt
            self.yaw = math.remainder(self.yaw+self.wz*dt, 2*math.pi)
            if self.scenario in ('map_dropout', 'origin_reset') and self.fault_at is None and self.x > 0.1:
                self.fault_at = now
                if self.scenario == 'origin_reset':
                    self.publish_origin()
            if self.scenario=='recovery_dropout' and self.fault_at is None and self.x < -.05:
                self.fault_at=now
            # Independent rectangular body-vs-corridor assertion (no planner reuse).
            for xx in ((-.45,.55) if self.soft else (-.55,.65)):
                for yy in ((-.37,.37) if self.soft else (-.47,.47)):
                    world_y = self.y + xx*math.sin(self.yaw) + yy*math.cos(self.yaw)
                    if self.scenario == 'unknown':
                        world_x = self.x + xx*math.cos(self.yaw) - yy*math.sin(self.yaw)
                        if math.hypot(world_x,world_y) > 1.26:
                            self.violation = 'Startup motion escaped fixed initial known-free allowance'
                    wall_limit=.4 if self.soft and not self.scenario.startswith('goal_') else 2.0 if self.scenario in ('detour','reverse_escape','recovery_dropout') else 1.0
                    world_x=self.x+xx*math.cos(self.yaw)-yy*math.sin(self.yaw)
                    if (self.scenario=='buffer_goto' or self.scenario.startswith('arrival_')) and world_x>1.2:wall_limit=1.0
                    if abs(world_y) >= wall_limit:
                        self.violation = 'Swept inflated body crossed synthetic corridor wall'
            # Independent polygon SAT against the actual synthetic front obstacle.
            if self.scenario in ('detour','reverse_escape','recovery_dropout'):
                left,right=(1.0,1.3) if self.scenario=='detour' else (.7,.9)
                co,si=math.cos(self.yaw),math.sin(self.yaw)
                body=[(self.x+a*co-b*si,self.y+a*si+b*co) for a in (-.55,.65) for b in (-.47,.47)]
                wall=[(a,b) for a in (left,right) for b in (-.8,.8)]
                overlaps=True
                for ax,ay in [(1,0),(0,1),(co,si),(-si,co)]:
                    bp=[a*ax+b*ay for a,b in body];wp=[a*ax+b*ay for a,b in wall]
                    if max(bp)<min(wp) or max(wp)<min(bp):overlaps=False;break
                if overlaps:self.violation='Recovery body intersects synthetic front obstacle'
            pose = LidarPose()
            pose.x, pose.y, pose.yaw = self.x, self.y, self.yaw
            if not (self.scenario=='arrival_pose_dropout' and self.fault_at is not None):self.pose_pub.publish(pose)

        def publish_map(self):
            if self.scenario in ('map_dropout','recovery_dropout') and self.fault_at is not None:
                return
            self.sequence += 1
            msg = LocalSafetyMap()
            msg.header.stamp = self.get_clock().now().to_msg()
            msg.header.frame_id = 'startup_navigation'
            msg.session_id = self.session_id()
            msg.config_revision = 'lidar-only-explicit-v2'
            msg.sequence = self.sequence
            msg.valid = not (self.scenario=='arrival_dropout' and self.fault_at is not None)
            msg.reason = 'synthetic test only'
            msg.observation_age_s = 0.0
            msg.grid.header = msg.header
            msg.grid.info.resolution = 0.1
            msg.grid.info.width = msg.grid.info.height = 80
            msg.grid.info.origin.position.x = msg.grid.info.origin.position.y = -4.0
            msg.grid.info.origin.orientation.w = 1.0
            cells = []
            for iy in range(80):
                for ix in range(80):
                    x, y = -4+(ix+0.5)*0.1, -4+(iy+0.5)*0.1
                    wall_limit=.4 if self.soft and not self.scenario.startswith('goal_') else 2.0 if self.scenario in ('detour','reverse_escape','recovery_dropout') else 1.0
                    if (self.scenario=='buffer_goto' or self.scenario.startswith('arrival_')) and x>1.2:wall_limit=1.0
                    val = 100 if abs(y) >= wall_limit else 0
                    if self.scenario in ('detour','reverse_escape','recovery_dropout'):
                        left,right=(1.0,1.3) if self.scenario=='detour' else (.7,.9)
                        if left<=x<=right and abs(y)<=.8:val=100
                    if self.scenario=='buffer_hard' and .5<=x<=.7:val=100
                    if self.scenario.startswith('goal_'):
                        left=2.6 if self.scenario=='goal_buffer' else 2.4
                        if left<=x<=2.9 and abs(y)<.8:val=100
                    if self.scenario=='arrival_body' and self.fault_at is not None and abs(x-self.x)<.1 and abs(y-self.y)<.1:val=100
                    if self.scenario == 'unknown':
                        val = -1
                    if self.scenario in ('unknown_explore','explore_blocked') and abs(y)<1.0:
                        val = -1
                    if self.scenario in ('blocked_move','explore_blocked') and 0.65 <= x <= 1.0:
                        val = 100
                    cells.append(val)
            msg.grid.data = cells
            self.map_pub.publish(msg)

    def spin_until(node, predicate, timeout):
        deadline = time.monotonic()+timeout
        while time.monotonic() < deadline:
            rclpy.spin_once(node, timeout_sec=0.02)
            if node.violation:
                raise AssertionError(node.violation)
            if predicate():
                return
        raise AssertionError('Timeout; latest statuses: '+json.dumps(node.statuses[-3:]))

    rclpy.init()
    binary = Path(get_package_prefix('core_2026'))/'lib/core_2026/dog_node'
    try:
        scenarios=('detour', 'reverse_escape', 'recovery_dropout', 'adjusted', 'unknown', 'unknown_explore', 'explore_blocked', 'blocked_move', 'confirm_each', 'map_dropout', 'origin_reset', 'buffer_move', 'buffer_goto', 'buffer_fast', 'buffer_hard', 'arrival_drift', 'arrival_unstable', 'arrival_dropout', 'arrival_body', 'arrival_unconfirmed', 'goal_buffer', 'goal_inside', 'arrival_pose_dropout')
        assert not args.scenarios or set(args.scenarios)<=set(scenarios),'unknown scenario'
        for scenario in (args.scenarios or scenarios):
            node = Harness(scenario)
            log = tempfile.TemporaryFile(mode='w+t', encoding='utf8')
            process = None
            test_home = tempfile.TemporaryDirectory(prefix='corridor-dryrun-home-')
            try:
                # Empty-domain preflight. A running real bridge here is an error, not permission to continue.
                deadline = time.monotonic()+1.0
                while time.monotonic() < deadline:
                    rclpy.spin_once(node, timeout_sec=0.05)
                others = [n for n in node.get_node_names() if n != node.get_name()]
                if others:
                    raise AssertionError('Isolated domain not empty: '+repr(others))
                params = dict(wait_for_mission='true', confirm_transitions='false',
                    safety_mode='enforce', safety_soft_buffer_enabled='false',
                    safety_map_topic='/corridor_test/map', lidar_pose_topic='/corridor_test/pose',
                    cmd_vel_topic='/corridor_test/cmd_vel', fsm_command_topic='/corridor_test/command',
                    dog_state_topic='/corridor_test/feedback', cmd_state_topic='/corridor_test/cmd_state',
                    heartbeat_topic='/corridor_test/heartbeat', posture_topic='/corridor_test/posture',
                    check_stand_result_topic='/corridor_test/check_result',
                    mission_topic='/corridor_test/mission', mission_cmd_topic='/corridor_test/mission_cmd',
                    mission_status_topic='/corridor_test/mission_status')
                if node.soft:
                    params['safety_soft_buffer_enabled']='true'
                    params['safety_max_vx']=.45
                if scenario.startswith('goal_'):params['safety_max_longitudinal_loss']=.8
                command = [str(binary), '--ros-args', '-r', '/navigation_origin:=/corridor_test/origin',
                           '-r', '/dog/safety/status:=/corridor_test/safety_status']
                if scenario in ('unknown_explore','explore_blocked','detour','reverse_escape','recovery_dropout'):
                    params['safety_unknown_as_free']='true'
                    params['safety_unknown_exploration_range_m']=5.0
                    params['safety_max_vx']=.3
                for key, value in params.items():
                    command += ['-p', f'{key}:={value}']
                child_env = os.environ.copy()
                # Production saved tuning must neither affect nor be modified by this test.
                child_env['HOME'] = test_home.name
                process = subprocess.Popen(command, stdout=log, stderr=subprocess.STDOUT,
                                           start_new_session=True, env=child_env)
                spin_until(node, lambda: any(s.get('phase') == 'idle' for s in node.statuses), 12)
                # Match the requested production stopping tolerance without touching real services.
                tuning=node.create_client(SetParametersAtomically,'/dog/goto/set_parameters_atomically')
                assert tuning.wait_for_service(timeout_sec=5)
                request=SetParametersAtomically.Request();request.parameters=[Parameter(name='tol_xy',value=ParameterValue(type=ParameterType.PARAMETER_DOUBLE,double_value=.30))]
                future=tuning.call_async(request);spin_until(node,future.done,4)
                assert future.result().result.successful;node.destroy_client(tuning)
                # Let maps/origin/pose discovery settle before task execution.
                settle = time.monotonic()+1
                spin_until(node, lambda: time.monotonic() >= settle, 2)
                first = dict(type='goto', x=2.0, y=1.3, goto_timeout_s=100)
                if scenario in ('map_dropout', 'origin_reset', 'unknown_explore'):
                    first = dict(type='goto', x=2.0, y=0.0, goto_timeout_s=30)
                if scenario in ('detour','reverse_escape','recovery_dropout'):
                    first=dict(type='goto',x=3.0,y=0.0,goto_timeout_s=100)
                if scenario in ('blocked_move','explore_blocked'):
                    first = dict(type='move', vx=0.1, vy=0.0, wz=0.0, duration_s=1.0)
                if scenario in ('buffer_move','buffer_fast','buffer_hard'):
                    first=dict(type='move',vx=.4 if scenario=='buffer_fast' else .3,vy=0.,wz=0.,duration_s=2.)
                if scenario=='buffer_goto' or scenario.startswith(('arrival_','goal_')):
                    first=dict(type='goto',x=2.5 if scenario=='goal_inside' else 2.0,y=0.,goto_timeout_s=18 if scenario=='arrival_unstable' else 40)
                if scenario == 'confirm_each':
                    first = dict(type='goto', x=0.0, y=0.0, goto_timeout_s=15)
                plan = dict(version=1, name=scenario, confirm='each' if scenario=='confirm_each' else 'none',
                            steps=[first, dict(type='wait', duration_s=0.5)])
                if scenario == 'confirm_each':
                    plan['steps'].append(dict(type='goto', x=0.0, y=0.0, goto_timeout_s=15))
                node.mission_pub.publish(String(data=json.dumps(plan)))
                if scenario == 'confirm_each':
                    spin_until(node, lambda: any(s.get('phase')=='waiting_confirm' and s.get('index')==1
                                                 for s in node.statuses), 8)
                    node.mission_cmd_pub.publish(String(data='confirm'))
                    spin_until(node, lambda: any(s.get('phase')=='waiting_confirm' and s.get('index')==3
                                                 for s in node.statuses), 15)
                    assert not any(s.get('phase')=='done' for s in node.statuses)
                    node.mission_cmd_pub.publish(String(data='confirm'))
                spin_until(node, lambda: any(s.get('name')==scenario and s.get('phase') in ('done','failed')
                                             for s in node.statuses), 110)
                terminal = next(s for s in reversed(node.statuses) if s.get('phase') in ('done','failed'))
                if scenario == 'adjusted':
                    assert terminal['phase']=='done', terminal
                    result = terminal['navigation_results'][0]
                    assert result['outcome']=='adjusted_arrival', result
                    assert result['original']==dict(x=2.0,y=1.3), result
                    forward = (2.0,1.3)
                    loss = ((2-result['effective']['x'])*forward[0]+(1.3-result['effective']['y'])*forward[1])/math.hypot(*forward)
                    assert -0.01 <= loss <= 0.201, loss
                    assert any(s.get('index')==2 and s.get('phase')=='running' for s in node.statuses)
                elif scenario in ('confirm_each','unknown_explore','detour','reverse_escape','buffer_move','buffer_goto','arrival_drift','goal_buffer','goal_inside'):
                    assert terminal['phase']=='done', terminal
                else:
                    assert terminal['phase']=='failed', terminal
                    assert not any(s.get('index')==2 and s.get('phase')=='running' for s in node.statuses)
                if scenario=='unknown':
                    captures=list((Path(test_home.name)/'logs/navigation_failures').glob('recovery-failure-*.json'))
                    assert captures,'failed recovery must preserve its original map'
                    capture=json.loads(captures[-1].read_text())
                    assert capture['state']=='recovery_stall_rounds_exhausted',capture['state']
                    assert 'last_search=' in capture['detail'] and 'rear_certified=' in capture['detail']
                    assert -1 in capture['observed_grid']['cells'] and 0 in capture['control_grid']['cells']
                if scenario=='buffer_move':
                    assert node.motion_seen and node.x>.4,'HAL must permit .30m/s inside soft buffer'
                if scenario=='buffer_goto':
                    assert node.max_forward>=.299,'recovery route must actually reach the new .30m/s cap'
                    assert node.motion_seen and node.x>1.5 and math.hypot(2.-node.x,node.y)<=.30001,'local route must satisfy the requested 0.30m stopping tolerance'
                    assert terminal['navigation_results'][0]['outcome']=='arrived',terminal
                if scenario.startswith('arrival_'):
                    captures=list((Path(test_home.name)/'logs/navigation_failures').glob('arrival-failure-*.json'))
                    assert captures,'post-stop rechecks must preserve precise map and evidence'
                    evidence=[json.loads(p.read_text()) for p in captures]
                    if scenario=='arrival_drift':
                        assert any(e['state']=='arrival_position_drift' for e in evidence),evidence
                        assert any(s.get('navigation_state')=='arrival_reapproach' for s in node.statuses)
                        assert math.hypot(2.-node.x,node.y)<=.30001,'retry must still satisfy original tolerance'
                    if scenario=='arrival_unstable':
                        assert node.stop_checks>=4 and '在规定时间内未到达目标' in terminal['msg'],terminal
                        assert '超过3次' not in terminal['msg'],terminal
                    expected={'arrival_body':'arrival_body_blocked','arrival_unconfirmed':'arrival_stop_unconfirmed','arrival_dropout':'arrival_map_unavailable','arrival_pose_dropout':'arrival_pose_not_updated'}.get(scenario)
                    if expected:assert any(e['state']==expected for e in evidence),(expected,[e['state'] for e in evidence])
                if scenario.startswith('goal_'):
                    result=terminal['navigation_results'][0];target=result['effective'];wall=2.6 if scenario=='goal_buffer' else 2.4
                    assert result['outcome']=='adjusted_arrival',result
                    assert target['x']<result['original']['x'] and target['x']+.65<wall+1e-6,result
                    assert abs(target['y'])+.47<1.0,result
                if scenario=='reverse_escape':assert node.reverse_seen,'tight scenario must execute certified retreat'
                if scenario in ('map_dropout', 'origin_reset','recovery_dropout'):
                    assert node.motion_seen and node.fault_at is not None, 'fault must interrupt actual motion'
                    assert abs(node.vx)+abs(node.wz) < 1e-9, 'fault must leave zero commanded velocity'
                print('PASS',scenario,'final pose',round(node.x,3),round(node.y,3),'peak_v',round(node.max_forward,3))
            except Exception:
                log.seek(0)
                print(log.read())
                raise
            finally:
                if process is not None:
                    process.send_signal(signal.SIGINT)
                    try:
                        process.wait(timeout=6)
                    except subprocess.TimeoutExpired:
                        process.kill()
                        process.wait(timeout=3)
                log.close()
                test_home.cleanup()
                node.destroy_node()
                time.sleep(1)
    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()
