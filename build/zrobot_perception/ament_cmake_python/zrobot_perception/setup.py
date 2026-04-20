from setuptools import find_packages
from setuptools import setup

setup(
    name='zrobot_perception',
    version='1.0.0',
    packages=find_packages(
        include=('zrobot_perception', 'zrobot_perception.*')),
)
