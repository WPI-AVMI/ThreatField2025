
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess
import os

def generate_launch_description():
    micro_ros_agent = ExecuteProcess(
        cmd=[[
            'MicroXRCEAgent udp4 --port 8888 -v '
        ]],
        shell=True
    )
    clock_translation_node = ExecuteProcess(
        cmd=[[
            'ros2 run ros_gz_bridge parameter_bridge /clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock'
        ]],
        shell=True
    )

    sense_node = Node(
        package='py_sensor',
        executable='sense',
        output='screen',
        shell=True,
    )

    QGroundcontrol_node = ExecuteProcess(
        cmd=[[
            '/home/avmi-lab-user/Downloads/QGroundControl-x86_64.AppImage'
            
        ]],
        output='screen',
        shell=True
    )

    px4_launch = ExecuteProcess(
        cmd=[
            'make', 'px4_sitl', 'gz_x500'
        ],
        cwd=os.path.expanduser('~/PX4-Autopilot'),  # Adjust if your PX4 is in a different path
        output='screen',
        shell=True
    )



    return LaunchDescription([
        micro_ros_agent,
        QGroundcontrol_node,
        clock_translation_node,
        px4_launch,
    ])
