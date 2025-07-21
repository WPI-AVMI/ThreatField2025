import numpy as np
import time
from mayavi import mlab

# IMPLEMENTATION OF ADVECTION DIFFUSION EQUATIONS 
def algo_helper_3D(Xs, Ys, Zs, ts, Xr, Yr, Zr, Tr, U, V, W, Ks, As):
    Rcs2 = 4 * Ks
    rs2 = (Xs - (Xr + U * (ts - Tr))) ** 2 + \
          (Ys - (Yr + V * (ts - Tr))) ** 2 + \
          (Zs - (Zr + W * (ts - Tr))) ** 2
    Cs2 = np.exp(-(rs2 / Rcs2))
    Cs1 = (As / (np.pi * Rcs2) ** 1.5)
    Cs = Cs1 * Cs2
    return Cs

# === MAIN FUNCTION WITH SINGLE STREAM===
def generate_Data_3D(Xr, Yr, Zr, Tr, U, V, W, Ks, As,res):
    # Time constants 
    ts = 0                    # initial reading time 
    timestep = 0.01           # 1 second interval
    timeperiod = 6            # Ending reading time
    reps = int((timeperiod - ts) / timestep)

    # Define grid (fixed)
    Ys, Xs, Zs = np.meshgrid(
        np.linspace(0, 1, res),
        np.linspace(0, 1, res),
        np.linspace(0, 1, res),
        indexing="ij"
    )

    # Initialize Mayavi figure once
    figure = mlab.figure('Advection-Diffusion 3D', bgcolor=(0, 0, 0))
    Ts = ts
    pixelArray = algo_helper_3D(Xs, Ys, Zs, Ts, Xr, Yr, Zr, Tr, U, V, W, Ks, As)
    pts = mlab.points3d(Xs, Ys, Zs, pixelArray, scale_mode='none', scale_factor=0.07)
    mlab.axes()

    # Animation loop
    for t in range(reps):
        Ts = ts + t * timestep
        pixelArray = algo_helper_3D(Xs, Ys, Zs, Ts, Xr, Yr, Zr, Tr, U, V, W, Ks, As)

        
        # Update scalar data instead of recreating plot
        pts.mlab_source.scalars = pixelArray

        mlab.process_ui_events()
        mlab.draw()
        print(f"Updated time: {Ts:.2f} s")
        time.sleep(0.1)  # Pause 1 second per frame

    mlab.show()  # Show final result (optional)

# Example usage
