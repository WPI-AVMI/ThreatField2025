from setuptools import find_packages, setup

package_name = 'py_sensor'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
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
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'talker = py_sensor.FakeTele:main',
            'sense = py_sensor.sensor_node:main',
            'service = py_sensor.service_member_function:main',
            'client = py_sensor.client_member_function:main',
            'listener = py_sensor.numsub:main',
            'sen_service = py_sensor.sensor_service:main',
            'sen_client = py_sensor.sensor_client:main',

        ],
    },
)
