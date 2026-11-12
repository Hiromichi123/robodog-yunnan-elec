from setuptools import setup
from glob import glob
name = 'tracked_base_bridge'
setup(name=name, version='0.1.0', packages=[name],
      data_files=[('share/ament_index/resource_index/packages', ['resource/' + name]),
                  ('share/' + name, ['package.xml', 'README.md']),
                  ('share/' + name + '/launch', glob('launch/*.py')),
                  ('share/' + name + '/config', glob('config/*.yaml'))],
      install_requires=['setuptools'], zip_safe=True,
      maintainer='Hiromichi123', maintainer_email='2271612727@qq.com',
      description='Standalone tracked chassis PWM adapter', license='Apache-2.0',
      tests_require=['pytest'],
      entry_points={'console_scripts': ['tracked_base_bridge = tracked_base_bridge.node:main']})
