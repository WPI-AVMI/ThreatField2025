#!/usr/bin/python3
import os 
import datetime
import time 
import scp
from scp import SCPClient
import paramiko as param

def get_client(host, user, password, port):
    """
    Initialize an SSHClient instance to a remote agent using SSH key-based authentication.

    Parameters
    ----------
    host : str
        The IP address of the agent's remote SSH server.
    user: str
        The agent's username.
    password: str
        The agent's password.
    port : int
        The port number to connect to on the agent.

    Returns
    -------
    SSHClient
        An SSHClient instance connected to the specified agent.

    See Also
    --------
    upload : Upload a file or directory from the local machine to a remote agent via SSH using SCP.
    download : Download a file or directory from a remote agent via SSH using SCP to the local machine.
    """

    ssh = param.SSHClient()
    ssh.load_system_host_keys()
    ssh.set_missing_host_key_policy(param.AutoAddPolicy())
    if port == -1:
        ssh.connect(
            hostname=host, 
            username=user,
            password=password
        )
    else:
        ssh.connect(
            hostname=host, 
            username=user,
            password=password,
            port=port
        )
    return ssh




def upload(host,user,password, local_path, remote_path):
    """
    Upload a file or directory from the local machine to a remote agent via SSH using SCP.

    Parameters
    ----------
    agent : UGVPrimary or UAVPrimary
        An agent's corresponding object on the local machine running the experiment.
    local_path : str
        The path to a file or directory on the local machine.
    remote_path : str
        The path to a file or directory on the agent's remote SSH server.

    See Also
    --------
    get_client : Initialize an SSHClient instance to a remote agent using SSH key-based authentication.
    download : Download a file or directory from a remote agent via SSH using SCP to the local machine.
    """

    ssh = get_client(
        host=host,
        user=user,
        password=password,
        port=-1
    )
    scp = SCPClient(ssh.get_transport())
    scp.put(local_path, recursive=True, remote_path=remote_path)
    scp.close()
    ssh.close()

def run():
    upload('192.168.1.11','avmi-lab-01','letmein','/home/avmi-lab-user/Documents/Threat Field Image Generation/splitimages/projector-pics/projector-1.png','/home/avmi-lab-01/Pictures/pppp.png')
    upload('192.168.1.12','avmi-lab-02','letmein','/home/avmi-lab-user/Documents/Threat Field Image Generation/splitimages/projector-pics/projector-2.png','/home/avmi-lab-02/Pictures/pppp.png')
    upload('192.168.1.13','avmi-lab-03','letmein','/home/avmi-lab-user/Documents/Threat Field Image Generation/splitimages/projector-pics/projector-3.png','/home/avmi-lab-03/Pictures/pppp.png')
    upload('192.168.1.14','avmi-lab-04','letmein','/home/avmi-lab-user/Documents/Threat Field Image Generation/splitimages/projector-pics/projector-4.png','/home/avmi-lab-04/Pictures/pppp.png')

