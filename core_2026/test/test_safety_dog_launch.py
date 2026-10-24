"""No ROS process start: evaluate dog launch with simple launch API stand-ins."""
import importlib.util
from pathlib import Path
import sys
import types
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]


def load(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec); spec.loader.exec_module(module)
    return module


class DogLaunchTests(unittest.TestCase):
    def setUp(self):
        self.config = load('config_fixture', ROOT / 'scripts/safety_config.py')
        modules = {key: types.ModuleType(key) for key in ['launch', 'launch.actions', 'launch.substitutions',
                   'launch_ros', 'launch_ros.actions', 'launch.event_handlers', 'ament_index_python', 'ament_index_python.packages']}
        modules['launch'].LaunchDescription = lambda actions: actions
        modules['launch.actions'].DeclareLaunchArgument = lambda *args, **kw: (args, kw)
        modules['launch.actions'].OpaqueFunction = lambda **kw: kw
        modules['launch.actions'].RegisterEventHandler = lambda handler: {'handler': handler}
        modules['launch.actions'].LogInfo = lambda **kw: kw
        modules['launch.event_handlers'].OnProcessExit = lambda **kw: kw
        class Configuration:
            def __init__(self, name): self.name = name
            def perform(self, context): return context[self.name]
        modules['launch.substitutions'].LaunchConfiguration = Configuration
        modules['launch_ros.actions'].Node = lambda **kwargs: kwargs
        modules['ament_index_python.packages'].get_package_share_directory = lambda _: str(ROOT)
        with patch.dict(sys.modules, modules):
            self.launch = load('dog_launch_fixture', ROOT / 'launch/dog_web.launch.py')

    def test_each_config_value_reaches_global_arguments(self):
        data = self.config.document(self.config.defaults())
        data['config']['control']['max_vx'] = .22
        data = self.config.document(data['config'])
        with patch.object(self.config, 'startup', return_value=data), patch.object(self.launch, '_config_module', return_value=self.config):
            node = self.launch._start({'safety_mode': '', 'enable_takeoff_getdown': 'true'})[0]
        self.assertNotIn('parameters', node)
        args = node['arguments']
        self.assertIn('wait_for_mission:=true', args)
        self.assertIn('confirm_transitions:=false', args)
        self.assertIn('safety_max_vx:=0.22', args)
        self.assertIn('safety_config_revision:=' + data['revision'], args)
        self.assertNotIn('safety_calibration_validated:=false', args)
        for name in self.config.control_parameters(data):
            self.assertTrue(any(a.startswith(name + ':=') for a in args))

    def test_takeoff_receiver_follows_explicit_switch(self):
        data = self.config.document(self.config.defaults())
        for enabled in ('true', 'false'):
            with patch.object(self.config, 'startup', return_value=data), patch.object(self.launch, '_config_module', return_value=self.config):
                actions = self.launch._start({'safety_mode': '', 'enable_takeoff_getdown': enabled})
            self.assertIn('enable_takeoff_getdown:=' + enabled, actions[0]['arguments'])
            receivers = [a for a in actions if a.get('executable') == 'start_takeoff_receiver.sh']
            self.assertEqual(len(receivers), int(enabled == 'true'))
            if receivers:
                self.assertEqual(receivers[0]['arguments'], ['--enable-actions'])
        declarations = self.launch.generate_launch_description()
        self.assertTrue(any(isinstance(a, tuple) and a[0] == ('enable_takeoff_getdown',) and
                            a[1]['default_value'] == 'true' for a in declarations))

    def test_override_changes_identity_and_corrupt_start_fails(self):
        data = self.config.document(self.config.defaults())
        before = data['revision']
        with patch.object(self.config, 'startup', return_value=data), patch.object(self.launch, '_config_module', return_value=self.config):
            with self.assertRaises(self.config.ConfigError):
                self.launch._start({'safety_mode': 'observe', 'enable_takeoff_getdown': 'true'})
            args = self.launch._start({'safety_mode': 'enforce', 'enable_takeoff_getdown': 'true'})[0]['arguments']
        self.assertIn('safety_mode:=enforce', args)
        self.assertIn('safety_config_revision:=' + before, args)
        with patch.object(self.config, 'startup', side_effect=ValueError('bad config')), patch.object(self.launch, '_config_module', return_value=self.config):
            with self.assertRaises(ValueError): self.launch._start({'safety_mode': '', 'enable_takeoff_getdown': 'true'})


if __name__ == '__main__': unittest.main()
