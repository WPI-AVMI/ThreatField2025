
import numpy as np



Xs = 0.2
Ys = 0.2
Zs = 0.2
Ts = 0.2

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


Rcs2 = 4 * Ks
rs2 = (Xs - (Xr + U * (Ts - Tr))) ** 2 + \
    (Ys - (Yr + V * (Ts - Tr))) ** 2 + \
    (Zs - (Zr + W * (Ts - Tr))) ** 2
Cs2 = np.exp(-(rs2 / Rcs2))
Cs1 = (As / (np.pi * Rcs2) ** 1.5)
response = Cs1 * Cs2
print('ss %e '%(response) )
print(response)