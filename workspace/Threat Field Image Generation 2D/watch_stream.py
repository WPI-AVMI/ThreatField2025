import subprocess
import time
import os
import signal

# === Configuration ===
STREAM_URL = "http://192.168.1.10:8000/video_feed"  # CHANGE this to your host IP
CHECK_INTERVAL = 2  # in seconds

def is_stream_up():
    try:
        result = subprocess.run(
            ["curl", "--silent", "--head", "--max-time", "2", STREAM_URL],
            stdout=subprocess.PIPE
        )
        return b"200 OK" in result.stdout
    except Exception:
        return False

def is_browser_running():
    result = subprocess.run(
        ["pgrep", "-f", "chromium-browser"],
        stdout=subprocess.PIPE
    )
    return result.returncode == 0

def launch_browser():
    print("Stream is up. Launching Chromium...")
    subprocess.Popen([
        "chromium-browser",
        "--new-window",
        "--kiosk",
        "--noerrdialogs",
        "--disable-infobars",
        "--disable-gpu",
        "--disable-software-rasterizer",
        "--autoplay-policy=no-user-gesture-required",
        STREAM_URL
    ], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

def close_browser():
    print("tream is down. Closing Chromium...")
    subprocess.call(["pkill", "-f", "chromium-browser"])

def main():
    stream_up = False

    while True:
        current_status = is_stream_up()

        if current_status and not stream_up:
            # Stream just came online
            launch_browser()
            stream_up = True

        elif not current_status and stream_up:
            # Stream just went offline
            close_browser()
            stream_up = False

        elif current_status and not is_browser_running():
            # Browser was closed manually or crashed, relaunch
            launch_browser()

        time.sleep(CHECK_INTERVAL)

if __name__ == "__main__":
    main()
