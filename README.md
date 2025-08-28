# Overview

This repository contains files for the threat field simulator research conducted by WPI's
Aerospace Engineering Department under the supervision of Dr Gatsonis and Dr Demetriou. The purpose of the experiment is to setup an environment replicating a dynamic gas plume field through which a autonomous vehicle traverses through as to test vehicle navigation algorithms as well as plume dynamics prediction algorithms. The repository contains all files relating to the experiment including images, videos and reference documents used for its development.

The experiment itself runs as a simulation in gazebo implementing vehicle dynamics and controls of a fixed wing aircraft through PX4 and computation of navigation goals and predictive algorithms through ROS2 nodes. The experiment can be run using the following command 

ros2 launch sense_launch.py 
from the /workspace/ros2_ws/src/py_sensor/launch directory. This will launch an instance of PX4, microDDS, QgrouncdControl and the ROS2 nodes needed. More details about this setup are provided in the manual named Threat Field Experiment manual.

![Cover Image](https://github.com/WPI-AVMI/ThreatField2025/blob/main/cover_image.png)
