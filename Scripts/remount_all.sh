#!/bin/bash

sshpass -p 'letmein' ssh -t avmi-lab-01@192.168.1.11 "sudo umount -a"
sshpass -p 'letmein' ssh -t avmi-lab-01@192.168.1.11 "sudo mount -a"

sshpass -p 'letmein' ssh -t avmi-lab-02@192.168.1.12 "sudo umount -a"
sshpass -p 'letmein' ssh -t avmi-lab-02@192.168.1.12 "sudo mount -a"

sshpass -p 'letmein' ssh -t avmi-lab-03@192.168.1.13 "sudo umount -a"
sshpass -p 'letmein' ssh -t avmi-lab-03@192.168.1.13 "sudo mount -a"

sshpass -p 'letmein' ssh -t avmi-lab-04@192.168.1.14 "sudo umount -a"
sshpass -p 'letmein' ssh -t avmi-lab-04@192.168.1.14 "sudo mount -a"
