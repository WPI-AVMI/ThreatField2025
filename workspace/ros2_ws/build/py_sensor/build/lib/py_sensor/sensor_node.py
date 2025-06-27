import rclpy
from rclpy.node import Node
from interface.msg import Sensor
from interface.msg import FakeData
import numpy as np
from collections import deque

Xq = deque(maxlen=8)
Yq = deque(maxlen=8)
Zq = deque(maxlen=8)
Tq = deque(maxlen=8)
Cq = deque(maxlen=8)

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(Sensor, 'Sensor', 10)
        self.subscription = self.create_subscription(FakeData,'topic' ,self.callback_fun,10)
        self.sensor = Sensor()
            
    
    def Concentration_calc(self,X,Y,Z,T):

        Xs = X
        Ys = Y
        Zs = Z
        Ts = T

        Xr = 0.5 # release coord X
        Yr = 0.5 # release coord Z
        Zr = 0.5 # release coord Y
        Tr = 0 # release Time
        U  = 0.1  # Wind Velocity X
        V  = 0  # Wind Velocity Y
        W  = 0  # Wind Velocity Z
        Ks = 0.005      # Eddy Diffusion term
        As =  10**(-9) # Affects spread over time 


        Rcs2 = 4 * Ks
        rs2 = (Xs - (Xr + U * (Ts - Tr))) ** 2 + \
            (Ys - (Yr + V * (Ts - Tr))) ** 2 + \
            (Zs - (Zr + W * (Ts - Tr))) ** 2
        Cs2 = np.exp(-(rs2 / Rcs2))
        Cs1 = (As / (np.pi * Rcs2) ** 1.5)
        C = Cs1 * Cs2
        return C


    def translation(self,X,Y,Z,T):
        return [X,Y,Z,T]
    
    def Grad_calc(self,XX,YY,ZZ,TT,CC):
            Dx = XX[4]
            Dy = YY[4]
            Dz = ZZ[4]
            Dt = TT[4]
            return [Dx,Dy,Dz,Dt]

    def callback_fun(self, msg):


        Norm = self.translation(msg.x,msg.y,msg.z,msg.t)
        X = Norm[0]
        Y = Norm[1]
        Z = Norm[2]
        T = Norm[3]


        Xq.append(X)
        Yq.append(Y)
        Zq.append(Z)
        Tq.append(T)
        Cq.append(self.Concentration_calc(X,Y,Z,T))


        if len(Cq) == 8:
           XX = list(Xq)
           YY = list(Yq)
           ZZ = list(Zq)
           TT = list(Tq)
           CC = list(Cq)
           Grad = self.Grad_calc(XX,YY,ZZ,TT,CC)
           self.sensor.dx = Grad[0]
           self.sensor.dy = Grad[1]
           self.sensor.dz = Grad[2]
           self.sensor.dt = Grad[3]
           self.publisher_.publish(self.sensor)
           self.get_logger().info('Publishing: dc/x: %f dc/dy: %f dc/dz: %f dc/dt: %f'  % (Grad[0], Grad[1],Grad[2], Grad[3]))


        


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()