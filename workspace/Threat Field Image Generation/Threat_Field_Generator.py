## This script is meant to be run on the ground control station to publish the images to the headless Raspberry PIs via NFS drive

import math
import GCS_Functions as GCS


# THREAT FIELD PARAMETERS
img_height = 1080
img_width = 1920
mu_x = 250
mu_y = 250
sigma_x = 100
sigma_y = 200
saturation = 1
value = 1.0
theta = math.pi/12
scale_factor = 0.8
invert = True




# Generate Gaussian threat field

# GCS.generate_image_with_rot(800, 1280, 400, 400, 200, 400, saturation, value, theta, scale_factor, invert)   # Good distribution
# # Split image and return 4 PNGs
# Images = GCS.split_image('test_dist.png')



# Physics constants for source initial conditions 
Xr=0.3 # release coord X
Yr=0 # release coord Y
Tr = 0 # release Time
U = 0  # Wind Velocity X
V = 4  # Wind Velocity Y
# Diffusion Constants 
Ks = 0.3      # Affects size of field
As =  10**(-9) # Affects spread over time 

# generates image with physics based algorithm 
GCS.generate_image_algo(Xr,Yr,Tr,U,V,img_height, img_width,Ks,As)

