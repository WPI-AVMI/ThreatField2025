#!/bin/bash
sshpass -p 'letmein' ssh -t avmi-lab-01@192.168.1.11 "sudo shutdown now"
sshpass -p 'letmein' ssh -t avmi-lab-02@192.168.1.12 "sudo shutdown now"
sshpass -p 'letmein' ssh -t avmi-lab-03@192.168.1.13 "sudo shutdown now"
sshpass -p 'letmein' ssh -t avmi-lab-04@192.168.1.14 "sudo shutdown now"
