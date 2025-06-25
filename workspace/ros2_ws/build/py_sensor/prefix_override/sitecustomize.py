import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/avmi-lab-user/ThreatField2025/workspace/ros2_ws/install/py_sensor'
