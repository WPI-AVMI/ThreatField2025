import numpy as np
from collections import deque

Xq = deque(maxlen=8)
Yq = deque(maxlen=8)
Zq = deque(maxlen=8)
Tq = deque(maxlen=8)
Cq = deque(maxlen=8)


def callback_fun( q,w,e,r):


        Xq.append(q)
        Yq.append(w)
        Zq.append(e)
        Tq.append(r)
        Cq.append(q)
        if len(Cq) == 8:
           CC = list(Cq)
           print(CC)

           Cf = CC[-1]
           print(Cf)
           C = np.subtract(CC[:-1],Cf)**2
           print(C)     

        

for t in range(10):           
    callback_fun( 1+t,1,1,1+t)
