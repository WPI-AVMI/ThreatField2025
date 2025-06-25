import subprocess
import os






def send_file():
    """
    Sends a file from the local machine to a remote machine using rsync over SSH.
    
    Args:
        source_file (str): The path to the picture file on the local machine.
        destination_user (str): The username for the destination machine.
        destination_ip (str): The IP address of the destination machine.
        destination_path (str): The destination path on the remote machine.

    """

    img_num = 0
    password = "letmein"
    for i in range(4):
        img_num +=1
        source_file = "/home/avmi-lab-user/Documents/projector-" + str(img_num) + ".png"
        destination_user = "avmi-lab-0" + str(img_num) 
        destination_ip = "192.168.1.1"  + str(img_num) 
        destination_path = "/home/avmi-lab-0" + str(img_num) + "/Pictures/pppp.png"

        try:
            # Construct the rsync command
            rsync_command = [
                "sshpass",
                "-p", password,
                "rsync",
                "-avz",
                "-q",
                "-a",

                source_file,
                f"{destination_user}@{destination_ip}:{destination_path}"
            ]
            
            # Execute the rsync command
            result = subprocess.run(rsync_command, check=True, text=True, capture_output=True)
        except subprocess.CalledProcessError as e:
            print(f"Error sending file: {e}")
            print(e.stderr)
