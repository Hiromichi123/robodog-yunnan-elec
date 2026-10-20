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
                   'launch_ros', 'launch_ros.actions', 'ament_index_python', 'ament_index_python.packages']}
        modules['launch'].LaunchDescription = lambda actions: actions
        modules['launch.actions'].DeclareLaunchArgument = lambda *args, **kw: (args, kw)
        modules['launch.actions'].OpaqueFunction = lambda **kw: kw
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
            node = self.launch._start({'safety_mode': ''})[0]
        self.assertNotIn('parameters', node)
        args = node['arguments']
        self.assertIn('wait_for_mission:=true', args)
        self.assertIn('confirm_transitions:=false', args)
        self.assertIn('safety_max_vx:=0.22', args)
        self.assertIn('safety_config_revision:=' + data['revision'], args)
        self.assertNotIn('safety_calibration_validated:=false', args)
        for name in self.config.control_parameters(data):
            self.assertTrue(any(a.startswith(name + ':=') for a in args))

    def test_override_changes_identity_and_corrupt_start_fails(self):
        data = self.config.document(self.config.defaults())
        before = data['revision']
        with patch.object(self.config, 'startup', return_value=data), patch.object(self.launch, '_config_module', return_value=self.config):
            args = self.launch._start({'safety_mode': 'observe'})[0]['arguments']
        self.assertIn('safety_mode:=observe', args)
        self.assertNotIn('safety_config_revision:=' + before, args)
        with patch.object(self.config, 'startup', side_effect=ValueError('bad config')), patch.object(self.launch, '_config_module', return_value=self.config):
            with self.assertRaises(ValueError): self.launch._start({'safety_mode': ''})


if __name__ == '__main__': unittest.main()
