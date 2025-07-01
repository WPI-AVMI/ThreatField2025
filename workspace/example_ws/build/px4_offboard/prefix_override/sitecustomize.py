import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/avmi-lab-user/ThreatField2025/workspace/example_ws/install/px4_offboard'
