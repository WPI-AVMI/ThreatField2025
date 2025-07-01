import numpy as np
from collections import deque

Xq = deque(maxlen=8)
Yq = deque(maxlen=8)
Zq = deque(maxlen=8)
Tq = deque(maxlen=8)
Cq = deque(maxlen=8)



def Grad_calc(XX,YY,ZZ,TT,CC):
    print(np.random.rand)
    try:

        DRi = np.transpose([np.subtract(XX[:-1],XX[-1]),np.subtract(YY[:-1],YY[-1]),
                np.subtract(ZZ[:-1],ZZ[-1]),np.subtract(TT[:-1],TT[-1])])
        
        W = np.diag(1/(np.linalg.norm(DRi,axis=1)**2))**2
        c_matrix = (np.subtract(CC[:-1],CC[-1]))
        l_mat = np.matmul(np.matmul(np.transpose(DRi),W),DRi)
        r_mat = np.matmul(np.matmul(np.transpose(DRi),W),c_matrix)
        Grad  = np.linalg.solve(l_mat, r_mat)

        print(np.random.rand)



        return Grad
    except np.linalg.LinAlgError:
        return []

def callback_fun( q,w,e,r):


        Xq.append(q)
        Yq.append(w)
        Zq.append(e)
        Tq.append(r)
        Cq.append(q)


        if len(Cq) == 8:
            XX = list(Xq)
            YY = list(Yq)
            ZZ = list(Zq)
            TT = list(Tq)
            CC = list(Cq)
            Grad = Grad_calc(XX,YY,ZZ,TT,CC)
            print(Grad)
            print(np.random.rand)

        


for t in range(8):    
    print(np.random.rand())       
    callback_fun( 1+t,1+t*2,1+t*3,1+t*4)