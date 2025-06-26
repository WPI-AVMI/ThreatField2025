from interface.srv import Concentration
import rclpy
from rclpy.node import Node
import numpy as np
import time

class MinimalService(Node):


    def __init__(self):
        super().__init__('minimal_service')
        self.srv = self.create_service(Concentration, 'Concentration', self.Concentration_callback)


    def Concentration_callback(self, request, response):

        Xs = request.x
        Ys = request.y
        Zs = request.z
        Ts = request.t

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
        response.c = Cs1 * Cs2

        self.get_logger().info('Incoming request\nx: %f y: %f z: %f t: %f' % (request.x, request.y,request.z, request.t))

        return response


def main():
    rclpy.init()

    minimal_service = MinimalService()

    rclpy.spin(minimal_service)

    rclpy.shutdown()


if __name__ == '__main__':
    main()