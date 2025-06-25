import numpy as np
from scipy import stats
from mayavi import mlab



def algo_helper_3D(Xs,Ys,Zs,ts,Xr,Yr,Zr,Tr,U,V,W,Ks,As):
    Rcs2 = 4*Ks
    # Non dimentionalized Concentration Calculations 
    rs2 = (Xs - (Xr+U*(ts-Tr)))**2 + (Ys-(Yr+V*(ts-Tr)))**2 + (Zs-(Zr+W*(ts-Tr)))**2
    Cs2 = np.exp(-(rs2/Rcs2))
    Cs1 = (As/(np.pi*Rcs2)**1.5)
    Cs = Cs1*Cs2

    return Cs



Ys, Xs,Zs = np.meshgrid(
    np.linspace(0, 1, 10),
    np.linspace(0, 1, 10),
    np.linspace(0, 1, 10),
indexing="ij"
)


Xr = 0.5 # release coord X
Yr = 0.5 # release coord Z
Zr = 0.5 # release coord Y
Tr = 0 # release Time
U  = 0  # Wind Velocity X
V  = 0  # Wind Velocity Y
W  = 0  # Wind Velocity Z
Ts =1

Ks = 0.005      # Eddy Diffusion term
As =  10**(-9) # Affects spread over time 



pixelArray = algo_helper_3D(Xs,Ys,Zs,Ts,Xr,Yr,Zr,Tr,U,V,W,Ks,As)

# Plot scatter with mayavi
figure = mlab.figure('DensityPlot')
pts = mlab.points3d(Xs, Ys, Zs, pixelArray, scale_mode='none', scale_factor=0.07)
mlab.axes()
mlab.show()
