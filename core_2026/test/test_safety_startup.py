"""No ROS runtime, sensors, subprocesses or production files are used by these tests."""
import ast
import copy
import importlib.util
import os
from pathlib import Path
import signal
import sys
import tempfile
import types
import unittest
from unittest.mock import Mock, patch

ROOT = Path(__file__).resolve().parents[1]

def load(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module

helper = load('safety_startup_test', ROOT / 'scripts/start_local_safety.py')
config = load('safety_config_test', ROOT / 'scripts/safety_config.py')


class StartupTest(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.home = Path(self.temp.name)
        self.env = patch.dict(os.environ, {}, clear=False)
        self.env.start(); self.addCleanup(self.env.stop)
        os.environ.pop('ROBODOG_SAFETY_SNAPSHOT', None)
        patcher = patch.object(Path, 'home', return_value=self.home)
        patcher.start(); self.addCleanup(patcher.stop)

    def enabled(self):
        values = config.defaults(); values['mode'] = 'enforce'
        return config.document(values)

    def test_freeze_then_saved_changes_do_not_mutate_snapshot(self):
        path = helper.prepare_snapshot(config)
        os.environ['ROBODOG_SAFETY_SNAPSHOT'] = str(path)
        first = config.startup()
        config.save(self.enabled()['config'], first['revision'])
        self.assertEqual(config.startup()['config']['mode'], 'disabled')
        self.assertEqual(helper.prepare_snapshot(config), path)

    def test_bad_supplied_snapshot_does_not_fallback(self):
        os.environ['ROBODOG_SAFETY_SNAPSHOT'] = str(self.home / 'missing.json')
        with self.assertRaises(config.ConfigError): helper.prepare_snapshot(config)

    def test_direct_helper_requires_snapshot(self):
        with self.assertRaisesRegex(RuntimeError, 'SNAPSHOT'): helper.main(['--mode'])

    def test_disabled_never_imports_ros_or_starts_process(self):
        with patch.object(helper.subprocess, 'Popen') as spawn:
            self.assertEqual(helper.run(config, config.document(config.defaults())), 0)
            spawn.assert_not_called()

    def test_parameters_all_forwarded_without_shell(self):
        params = config.perception_parameters(self.enabled())
        args = helper.parameter_args(params)
        self.assertNotIn('calibration_validated:=false', args)
        self.assertIn('min_range_m:=0.6', args)
        self.assertIn('config_revision:=' + self.enabled()['revision'], args)
        for name in self.enabled()['config']['perception']: self.assertTrue(any(x.startswith(name + ':=') for x in args))

    def test_explicit_unknown_exploration_forwarded_to_control(self):
        data=self.enabled()
        params=config.control_parameters(data)
        self.assertIs(params['safety_unknown_as_free'], True)
        self.assertEqual(params['safety_unknown_exploration_range_m'],data['config']['perception']['max_range_m'])
        self.assertEqual(params['safety_max_vx'],data['config']['control']['max_vx'])

    def test_no_camera_dependencies(self):
        source = (ROOT / 'scripts/start_local_safety.py').read_text()
        for forbidden in ('depth_points_node', 'lookup_transform', 'camera_driver', 'tf2_msgs'):
            self.assertNotIn(forbidden, source)

    def test_owned_children_no_new_group_and_cleanup(self):
        child = Mock(); child.poll.return_value = None
        spawn = Mock(return_value=child)
        owned = helper.OwnedProcesses(spawn)
        owned.start(['/owned/exe', 'argument with spaces'])
        self.assertNotIn('start_new_session', spawn.call_args.kwargs)
        self.assertNotIn('shell', spawn.call_args.kwargs)
        owned.check(); owned.close()
        child.send_signal.assert_called_once_with(signal.SIGINT)

    def test_dead_owned_child_fails_supervisor(self):
        child = Mock(args=['/owned/exe']); child.poll.return_value = 3
        owned = helper.OwnedProcesses(Mock(return_value=child)); owned.start(['/owned/exe'])
        with self.assertRaisesRegex(RuntimeError, '退出'): owned.check()

    def mock_run(self, depth=False, external_safety=False, parents=None):
        node = Mock()
        def count(topic):
            return int((topic == '/camera/camera/depth/color/points' and depth) or
                       (topic == '/local_safety/map' and external_safety))
        node.count_publishers.side_effect = count
        def subscribe(kind, topic, callback, qos):
            if topic == '/tf_static' and parents:
                callback(types.SimpleNamespace(transforms=[types.SimpleNamespace(
                    child_frame_id=child, header=types.SimpleNamespace(frame_id=parent)) for child,parent in parents.items()]))
            return object()
        node.create_subscription.side_effect = subscribe
        ros = types.ModuleType('rclpy'); ros.init=Mock(); ros.shutdown=Mock()
        ros.create_node=Mock(return_value=node); ros.spin_once=Mock(); ros.ok=Mock(side_effect=[True, False])
        qos = types.ModuleType('rclpy.qos'); qos.QoSProfile=Mock()
        qos.DurabilityPolicy=types.SimpleNamespace(TRANSIENT_LOCAL=1)
        qos.ReliabilityPolicy=types.SimpleNamespace(RELIABLE=1)
        signals = types.ModuleType('rclpy.signals'); signals.SignalHandlerOptions=types.SimpleNamespace(NO=0)
        packages = types.ModuleType('ament_index_python.packages'); packages.get_package_prefix=lambda package: '/prefix/' + package
        msg = types.ModuleType('tf2_msgs.msg'); msg.TFMessage=object
        modules={'rclpy':ros, 'rclpy.qos':qos, 'rclpy.signals':signals,
                 'ament_index_python':types.ModuleType('ament_index_python'), 'ament_index_python.packages':packages,
                 'tf2_msgs':types.ModuleType('tf2_msgs'), 'tf2_msgs.msg':msg}
        children=[]
        def spawn(args, **kwargs):
            child=Mock(args=args); child.poll.return_value=None; children.append(child); return child
        ticks=iter(range(100))
        with patch.dict(sys.modules, modules), patch.object(helper, 'OwnedProcesses', lambda: real_owned(spawn)), \
             patch.object(helper.signal, 'signal'), patch.object(helper.time, 'monotonic', side_effect=lambda: next(ticks)):
            result=helper.run(config,self.enabled())
        return result, children, node

    def test_run_starts_only_owned_safety_dependencies(self):
        result, children, _ = self.mock_run()
        self.assertEqual(result,0)
        self.assertEqual(len(children),1)
        args=[c.args for c in children]
        self.assertFalse(any('depth_points_node' in x[0] for x in args))
        self.assertTrue(any('local_obstacle_node' in x[0] for x in args))
        self.assertFalse(any('camera_driver' in x[0] or 'dog_node' in x[0] for x in args))
        for child in children: child.send_signal.assert_called_once_with(signal.SIGINT)

    def test_run_reuses_external_depth_and_tf(self):
        _, children, _ = self.mock_run(depth=True,parents={'camera_link':'base_link','camera_camera_left':'camera_camera_imu'})
        self.assertEqual(len(children),1)
        self.assertIn('local_obstacle_node',children[0].args[0])

    def test_duplicate_map_publisher_rejected(self):
        with self.assertRaisesRegex(RuntimeError, '外部安全地图'): self.mock_run(external_safety=True)

    def test_launch_override_changes_revision_and_never_calibrates(self):
        source=(ROOT/'launch/slam_only.launch.py').read_text(encoding='utf-8')
        tree=ast.parse(source)
        function=next(n for n in tree.body if isinstance(n,ast.FunctionDef) and n.name=='_safety_node')
        args={'local_safety':'true','safety_ground_z':'-.4','real_robot_odom_topic':'/test/odom'}
        class Configuration:
            def __init__(self,name): self.name=name
            def perform(self,context): return args[self.name]
        namespace={'LaunchConfiguration':Configuration,'Node':lambda **kwargs:kwargs}
        exec(compile(ast.Module(body=[function],type_ignores=[]),str(ROOT/'launch/slam_only.launch.py'),'exec'),namespace)
        data=self.enabled(); original=copy.deepcopy(data)
        nodes=namespace['_safety_node'](None,config,data)
        params=nodes[0]['parameters'][0]
        self.assertEqual(data,original)
        self.assertEqual(params['ground_z'],-.4)
        self.assertNotEqual(params['config_revision'],data['revision'])
        self.assertNotIn('calibration_validated', params)
        self.assertEqual(params['odom_topic'],'/test/odom')
        args['local_safety']='false'
        self.assertEqual(namespace['_safety_node'](None,config,data),[])


real_owned=helper.OwnedProcesses
if __name__ == '__main__': unittest.main()
