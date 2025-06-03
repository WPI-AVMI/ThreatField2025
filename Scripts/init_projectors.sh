#!/bin/bash

sshpass -p 'letmein' ssh -f avmi-lab-01@192.168.1.11 "export DISPLAY=:0; python /home/avmi-lab-01/Documents/Scripts/project.py"
sshpass -p 'letmein' ssh -f avmi-lab-02@192.168.1.12 "export DISPLAY=:0; python /home/avmi-lab-02/Documents/Scripts/project.py"
sshpass -p 'letmein' ssh -f avmi-lab-03@192.168.1.13 "export DISPLAY=:0; python /home/avmi-lab-03/Documents/Scripts/project.py"
sshpass -p 'letmein' ssh -f avmi-lab-04@192.168.1.14 "export DISPLAY=:0; python /home/avmi-lab-04/Documents/Scripts/project.py"
