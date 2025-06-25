import numpy as np
import math
import time
import threading
import cv2
from flask import Flask, Response
from PIL import Image
import colorsys
import matplotlib.pyplot as plt 
import test as test
import rsync as sync



# === FLASK STREAMING SETUP ===
app = Flask(__name__)
current_frames = [None] * 4  # Store 4 image quadrants
frame_lock = threading.Lock()

@app.route('/video_feed/<int:feed_id>')
def video_feed(feed_id):
    def generate():
        while True:
            with frame_lock:
                if current_frames[feed_id] is not None:
                    ret, jpeg = cv2.imencode('.jpg', current_frames[feed_id])
                    yield (b'--frame\r\n'
                           b'Content-Type: image/jpeg\r\n\r\n' + jpeg.tobytes() + b'\r\n')
            time.sleep(0.01)
    return Response(generate(), mimetype='multipart/x-mixed-replace; boundary=frame')

def start_flask_server():
    app.run(host='0.0.0.0', port=8000, debug=False, threaded=True)



# current system functions 

# Helper function to calculate concentration at specific coordinate 

# IMPLEMENTATION OF ADVECTION DIFFUSION EQUATIONS 
def algo_helper(Xs,Ys,ts,Xr,Yr,Tr,U,V,Ks,As):

    # Non dimentionalized Concentration Calculations 
    Rcs2 = 4*Ks
    rs2 = (Xs - (Xr+U*(ts-Tr)))**2 + (Ys-(Yr+V*(ts-Tr)))**2
    Cs2 = np.exp(-(rs2/Rcs2))
    Cs1 = (As/(np.pi*Rcs2)**(3/2))
    Cs = Cs1*Cs2

    return Cs



def stay_helper(Xs,Ys,ts,Xr,Yr,Tr,U,V,Ks,As):

    # Non dimentionalized Concentration Calculations 
    Rcs2 = 4*Ks
    X = Xs
    rs2 =  (Ys-Yr)**2*U
    Cs2 = np.exp((-rs2/(Rcs2*X)))
    Cs1 = (As/(np.pi*Rcs2*(X)))
    Cs = Cs1*Cs2
    np.savetxt("output.txt",Cs)

    return Cs


# === MAIN FUNCTION WITH MULTI STREAM===
def generate_image_algo(Xr, Yr, Tr, U, V, img_height, img_width, Ks, As):
    global current_frame
    sim_size = max([img_height,img_width])


    # Start MJPEG Flask server once
    threading.Thread(target=start_flask_server, daemon=True).start()

    # Time constants 
    ts = 0                           # initial reading time 
    timestep = 0.002                      # time step 
    timeperiod = 6                    # Ending reading time
    reps = int((timeperiod-ts)/timestep) # iterations 

    xcoord = [0 for i in range(reps)]
    ycoord = [0 for i in range(reps)]
    scalar = None  # for normalization


    ## coordinate translation for simulation crop 
    S1 = img_height/sim_size
    S2 = img_width/sim_size
    Xr = (1-S1)/2+S1*Xr
    Yr = (1-S2)/2+S2*Yr


    
    for t in range(reps):
        scalar = None  # for normalization

        # Define size of matrix for readings
        pixelArray = [[0 for i in range(sim_size)] for j in range(sim_size)]
        Ts = ts + t * timestep


        # max = np.amax(pixelArray[x])
        Ys, Xs = np.meshgrid(
        np.linspace(0, 1, sim_size),
        np.linspace(0, 1, sim_size),
        indexing="ij"
        )

        if Ts <= Tr:
            # Create and send a zero image
            scalar = 0.00025076634654540655
            
            blank = np.zeros((img_width, img_height, 3), dtype=np.uint8)
            normalized = (blank / scalar * 255).astype(np.uint8)
            color_mapped = cv2.applyColorMap(normalized, cv2.COLORMAP_JET)
            with frame_lock:
                current_frame = color_mapped.copy()
            scalar = None  # for normalization




        if Ts > Tr:
            pixelArray = algo_helper(Xs, Ys, Ts, Xr, Yr, Tr, U, V, Ks, As)
            if scalar is None:
                scalar = np.amax(pixelArray)
                print(scalar)

        
            normalized = (pixelArray / scalar * 255).astype(np.uint8)
            color_mapped = cv2.applyColorMap(normalized, cv2.COLORMAP_JET)


            if img_height > img_width:
                crop_margin = int(abs(img_width-img_height)/2 )
                color_mapped = color_mapped[crop_margin:-crop_margin, :]

            elif img_width > img_height:
                crop_margin = int(abs((img_height-img_width)/2))
                color_mapped = color_mapped[: ,crop_margin:-crop_margin]
        

        # new image splitter 
         # Split the image into 4 quadrants
        h, w = color_mapped.shape[:2]
        half_h, half_w = h // 2, w // 2

        quadrant_frames = [
            color_mapped[0:half_h, 0:half_w],       # Top-left
            color_mapped[0:half_h, half_w:w],       # Top-right
            color_mapped[half_h:h, 0:half_w],       # Bottom-left
            color_mapped[half_h:h, half_w:w]        # Bottom-right
        ]       
        # Flip top-left and top-right horizontally
        quadrant_frames[0] = cv2.flip(quadrant_frames[0], 0)  # Top-left
        quadrant_frames[1] = cv2.flip(quadrant_frames[1], 0)  # Top-right
        # Flip top-left and top-right horizontally
        quadrant_frames[0] = cv2.flip(quadrant_frames[0], 1)  # Top-left
        quadrant_frames[1] = cv2.flip(quadrant_frames[1], 1)  # Top-right


        # Update global frames for each quadrant
        with frame_lock:
            for i in range(4):
                current_frames[i] = quadrant_frames[i].copy()
        time.sleep(0.001)



# === MAIN FUNCTION WITH SINGLE STREAM===
def generate_image_algo_single(Xr, Yr, Tr, U, V, img_height, img_width, Ks, As):
    global current_frame
    sim_size = max([img_height,img_width])


    # Start MJPEG Flask server once
    threading.Thread(target=start_flask_server, daemon=True).start()

    # Time constants 
    ts = 0                           # initial reading time 
    timestep = 0.002                      # time step 
    timeperiod = 6                    # Ending reading time
    reps = int((timeperiod-ts)/timestep) # iterations 

    xcoord = [0 for i in range(reps)]
    ycoord = [0 for i in range(reps)]
    scalar = None  # for normalization


    ## coordinate translation for simulation crop 
    S1 = img_height/sim_size
    S2 = img_width/sim_size
    Xr = (1-S1)/2+S1*Xr
    Yr = (1-S2)/2+S2*Yr

    # iteration over time 
    for t in range(reps):
        scalar = None  # for normalization

        # Define size of matrix for readings
        pixelArray = [[0 for i in range(sim_size)] for j in range(sim_size)]
        Ts = ts + t * timestep


        # max = np.amax(pixelArray[x])
        Ys, Xs = np.meshgrid(
        np.linspace(0, 1, sim_size),
        np.linspace(0, 1, sim_size),
        indexing="ij"
        )

        if Ts <= Tr:
            # Create and send a zero image
            scalar = 0.00025076634654540655
            
            blank = np.zeros((img_width, img_height, 3), dtype=np.uint8)
            normalized = (blank / scalar * 255).astype(np.uint8)
            color_mapped = cv2.applyColorMap(normalized, cv2.COLORMAP_JET)
            with frame_lock:
                current_frame = color_mapped.copy()
            scalar = None  # for normalization




        if Ts > Tr:
            pixelArray = algo_helper(Xs, Ys, Ts, Xr, Yr, Tr, U, V, Ks, As)
            if scalar is None:
                scalar = np.amax(pixelArray)
                print(scalar)

        
            normalized = (pixelArray / scalar * 255).astype(np.uint8)
            color_mapped = cv2.applyColorMap(normalized, cv2.COLORMAP_JET)


            if img_height > img_width:
                crop_margin = int(abs(img_width-img_height)/2 )
                color_mapped = color_mapped[crop_margin:-crop_margin, :]

            elif img_width > img_height:
                crop_margin = int(abs((img_height-img_width)/2))
                color_mapped = color_mapped[: ,crop_margin:-crop_margin]
                

            # Update global frame for MJPEG stream
            with frame_lock:
                current_frame = color_mapped.copy()


