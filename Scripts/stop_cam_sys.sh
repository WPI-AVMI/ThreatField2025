#!/bin/bash

sshpass -p 'letmein' ssh -f root@192.168.1.16 "pkill cam_sys"
