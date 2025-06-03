import numpy as np
import math
import time
import threading
import cv2
from flask import Flask, Response

# === FLASK STREAMING SETUP ===
app = Flask(__name__)
current_frame = None
frame_lock = threading.Lock()

@app.route('/video_feed')
def video_feed():
    def generate():
        while True:
            with frame_lock:
                if current_frame is not None:
                    ret, jpeg = cv2.imencode('.jpg', current_frame)
                    yield (b'--frame\r\n'
                           b'Content-Type: image/jpeg\r\n\r\n' + jpeg.tobytes() + b'\r\n')
            time.sleep(0.01)
    return Response(generate(), mimetype='multipart/x-mixed-replace; boundary=frame')

def start_flask_server():
    app.run(host='0.0.0.0', port=8000, debug=False, threaded=True)

# === HELPER FUNCTION ===
def algo_helper(Xs, Ys, ts, Xr, Yr, Tr, U, V, Ks, As):
    Rcs2 = 4 * Ks * (ts - Tr)
    rs2 = (Xs - (Xr + U * (ts - Tr)))**2 + (Ys - (Yr + V * (ts - Tr)))**2
    Cs2 = np.exp(-rs2 / Rcs2)
    Cs1 = As / (np.pi * Rcs2)**(1.5)
    return Cs1 * Cs2

# === MAIN FUNCTION ===
def generate_image_algo(Xr, Yr, Tr, U, V, img_height, img_width, Ks, As):
    global current_frame

    # Start MJPEG Flask server once
    threading.Thread(target=start_flask_server, daemon=True).start()

    ts = 0.1
    timestep = 0.0001
    timeperiod = 6
    reps = int((timeperiod - ts) / timestep)

    scalar = None  # for normalization

    for t in range(reps):
        start_time = time.time()
        Ts = ts + t * timestep

        # Create meshgrid of dimensionless coordinates
        Ys, Xs = np.meshgrid(
            np.linspace(0, 1, img_height),
            np.linspace(0, 1, img_width),
            indexing="ij"
        )

        # Compute concentration field
        pixelArray = algo_helper(Xs, Ys, Ts, Xr, Yr, Tr, U, V, Ks, As)

        # Normalize and convert to heatmap
        if scalar is None:
            scalar = np.max(pixelArray)

        normalized = (pixelArray / scalar * 255).astype(np.uint8)
        color_mapped = cv2.applyColorMap(normalized, cv2.COLORMAP_JET)

        # Update global frame for MJPEG stream
        with frame_lock:
            current_frame = color_mapped.copy()

        print(f"[t={t}] Frame streamed in {time.time() - start_time:.2f}s")
        time.sleep(timestep)
