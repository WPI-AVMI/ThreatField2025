from setuptools import find_packages, setup

package_name = 'py_sensor'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='avmi-lab-user',
    maintainer_email='delias.intr@gmail.com',
    description='TODO: Package description',
    license='Apache-2.0',
    entry_points={
        'console_scripts': [
            'sense = py_sensor.sensor_node:main',

        ],
    },
)
