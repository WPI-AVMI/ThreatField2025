from example_interfaces.srv import AddTwoInts

import rclpy
from rclpy.node import Node
import numpy as np
import time

class MinimalService(Node):


    def __init__(self):
        super().__init__('minimal_service')
        self.srv = self.create_service(AddTwoInts, 'add_two_ints', self.add_two_ints_callback)


    def add_two_ints_callback(self, request, response):

        Xs = request.a
        Ys = request.b
        Zs = request.c
        Ts = request.d

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



        self.get_logger().info('Incoming request\na: %d b: %d' % (request.a, request.b))

        return response


def main():
    rclpy.init()

    minimal_service = MinimalService()

    rclpy.spin(minimal_service)

    rclpy.shutdown()


if __name__ == '__main__':
    main()