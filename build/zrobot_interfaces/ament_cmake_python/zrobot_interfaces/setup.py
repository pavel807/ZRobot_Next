from setuptools import find_packages
from setuptools import setup

setup(
    name='zrobot_interfaces',
    version='1.0.0',
    packages=find_packages(
        include=('zrobot_interfaces', 'zrobot_interfaces.*')),
)
