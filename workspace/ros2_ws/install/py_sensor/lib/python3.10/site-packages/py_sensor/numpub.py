import rclpy
from rclpy.node import Node

from interface.msg import FakeData                            # CHANGE


class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(FakeData, 'topic', 10)  # CHANGE
        timer_period = 0.5
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = FakeData()                                                # CHANGE
        msg.x = 0.2                                           # CHANGE
        msg.y = 0.2                                           # CHANGE
        msg.z = 0.2                                           # CHANGE
        msg.t = self.i*0.01                                   # CHANGE


        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: x: %f y: %f z: %f t: %f' % (msg.x, msg.y,msg.z, msg.t))
        self.i += 1


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()