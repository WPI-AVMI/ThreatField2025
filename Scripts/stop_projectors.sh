#!/bin/bash

sshpass -p 'letmein' ssh -f avmi-lab-01@192.168.1.11 "pkill sxiv"
sshpass -p 'letmein' ssh -f avmi-lab-02@192.168.1.12 "pkill sxiv"
sshpass -p 'letmein' ssh -f avmi-lab-03@192.168.1.13 "pkill sxiv"
sshpass -p 'letmein' ssh -f avmi-lab-04@192.168.1.14 "pkill sxiv"
