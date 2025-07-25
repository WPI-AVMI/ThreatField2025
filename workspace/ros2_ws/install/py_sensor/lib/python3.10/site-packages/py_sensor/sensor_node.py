import rclpy
from rclpy.node import Node
from interface.msg import Sensor
from interface.msg  import State
import numpy as np
from collections import deque
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from px4_msgs.msg import OffboardControlMode, TrajectorySetpoint, VehicleCommand, VehicleLocalPosition, VehicleStatus


Xq = deque(maxlen=8)
Yq = deque(maxlen=8)
Zq = deque(maxlen=8)
Tq = deque(maxlen=8)
Cq = deque(maxlen=8)

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.TRANSIENT_LOCAL,
            history=HistoryPolicy.KEEP_LAST,
            depth=1
        )


        self.publisher_Sensor = self.create_publisher(Sensor, '/Sensor', 10)
        self.publisher_Num = self.create_publisher(State, '/State', 10)

        self.vehicle_local_position_subscriber = self.create_subscription(
            VehicleLocalPosition, '/fmu/out/vehicle_local_position', self.vehicle_local_position_callback, qos_profile)
        

        self.sensor = Sensor()
        self.state = State()
        self.vehicle_local_position = VehicleLocalPosition()

            
    
    def Concentration_calc(self,Xs,Ys,Zs,Ts):

        Xr = 0.5 # release coord X
        Yr = 0.5 # release coord Z
        Zr = 0.5 # release coord Y
        Tr = 0 # release Time
        U  = 1  # Wind Velocity X
        V  = 0  # Wind Velocity Y
        W  = 0  # Wind Velocity Z
        Ks = 0.0025      # Eddy Diffusion term
        As =  10**(-9) # Affects spread over time 





        Rcs2 = 4 * Ks
        rs2 = (Xs - (Xr + U * (Ts - Tr))) ** 2 + \
            (Ys - (Yr + V * (Ts - Tr))) ** 2 + \
            (Zs - (Zr + W * (Ts - Tr))) ** 2
        Cs2 = np.exp(-(rs2 / Rcs2))
        Cs1 = (As / (np.pi * Rcs2) ** 1.5)
        C = Cs1 * Cs2
        return C


    def normalizer(self,X,Y,Z,T,T_init):

        L0 = 200
        Z0 = 200
        V0 = 0.6
        
        Xs = X/L0
        Ys = Y/L0
        Zs = Z*(-1)/Z0
        Ts = ((T-T_init)/(10**6))*V0/L0

        return [Xs,Ys,Zs,Ts]
    
    def Grad_calc(self,XX,YY,ZZ,TT,CC):
        try:
            DRi = np.transpose([np.subtract(XX[:-1],XX[-1]),np.subtract(YY[:-1],YY[-1]),
                    np.subtract(ZZ[:-1],ZZ[-1]),np.subtract(TT[:-1],TT[-1])])
            
            W = np.diag(1/(np.linalg.norm(DRi,axis=1)**2))**2
            c_matrix = (np.subtract(CC[:-1],CC[-1]))
            l_mat = np.matmul(np.matmul(np.transpose(DRi),W),DRi)
            r_mat = np.matmul(np.matmul(np.transpose(DRi),W),c_matrix)
            Grad  = np.linalg.solve(l_mat, r_mat)
            return Grad
        
        except np.linalg.LinAlgError:
            Grad = []
            return Grad

    def vehicle_local_position_callback(self, msg):
    
        
        if not hasattr(self, 'T_init'):
            self.T_init = msg.timestamp 


        Norm = self.normalizer(msg.x,msg.y,msg.z,msg.timestamp,self.T_init)
        X, Y, Z, T = Norm



        Xq.append(X)
        Yq.append(Y)
        Zq.append(Z)
        Tq.append(T)
        C = self.Concentration_calc(X,Y,Z,T)


        self.state.x = X
        self.state.y = Y
        self.state.z = Z
        self.state.t = T
        self.state.c = C
        
        self.publisher_Num.publish(self.state)
        Cq.append(C)


        if len(Cq) == 8:
           XX = list(Xq)
           YY = list(Yq)
           ZZ = list(Zq)
           TT = list(Tq)
           CC = list(Cq)
           Grad = self.Grad_calc(XX,YY,ZZ,TT,CC)
           

           if len(Grad)==0:
               self.get_logger().info('Error publishing Linear Solve Matrix Singularity'  )
           else: 
                self.sensor.dx = float(Grad[0])
                self.sensor.dy = float(Grad[1])
                self.sensor.dz = float(Grad[2])
                self.sensor.dt = float(Grad[3])
                self.publisher_Sensor.publish(self.sensor)
                self.get_logger().info('Pub: dc/dx: %E dc/dy: %E dc/dz: %E dc/dt: %E'  % (Grad[0], Grad[1],Grad[2], Grad[3]))


        


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