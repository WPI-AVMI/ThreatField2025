## This script is meant to be run on the ground control station to publish the images to the headless Raspberry PIs via NFS drive

import math
import GCS_Functions_3D as GCS
# THREAT FIELD PARAMETERS

Xr = 0.5 # release coord X
Yr = 0.5 # release coord Z
Zr = 0.5 # release coord Y
Tr = 0 # release Time
U  = 0.1  # Wind Velocity X
V  = 0  # Wind Velocity Y
W  = 0  # Wind Velocity Z

# Diffusion Constants 
Ks = 0.005      # Eddy Diffusion term
As =  10**(-9) # Affects spread over time 

# generates image with physics based algorithm 
# GCS.generate_image_algo(Xr,Yr,Tr,U,V,img_height, img_width,Ks,As)
res = 100
GCS.generate_Data_3D(Xr,Yr,Zr,Tr,U,V,W,Ks,As,res)
