import sys
import rclpy
from rclpy.node import Node
from interface.srv import Concentration


class MinimalClientAsync(Node):

    def __init__(self):
        super().__init__('minimal_client_async')
        self.cli = self.create_client(Concentration, 'Concentration')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = Concentration.Request()

    def send_request(self, x, y,z,t):
        self.req.x = float(sys.argv[1])
        self.req.y = float(sys.argv[2])
        self.req.z = float(sys.argv[3])
        self.req.t = float(sys.argv[4])
        return self.cli.call_async(self.req)


def main():
    rclpy.init()

    minimal_client = MinimalClientAsync()
    future = minimal_client.send_request(float(sys.argv[1]), float(sys.argv[2]),float(sys.argv[3]),float(sys.argv[4]))
    rclpy.spin_until_future_complete(minimal_client, future)
    response = future.result()
    minimal_client.get_logger().info(
        'Result of conentration: for %f + %f + %f + %f= %e' %
        (minimal_client.req.x, minimal_client.req.y, minimal_client.req.z,  minimal_client.req.t, response.c))

    minimal_client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()