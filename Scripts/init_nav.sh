#!/bin/bash

sshpass -p 'letmein' ssh -f root@192.168.1.16 "cd /home/avmi-cam-sys/;./init_nav.sh"
