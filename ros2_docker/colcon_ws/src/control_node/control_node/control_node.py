import rclpy
from rclpy.node import Node
import std_msgs.msg
from visualization_msgs.msg import Marker
import visualization_msgs
import geometry_msgs
from types import NoneType
import rclpy
from rclpy.node import Node
import std_msgs.msg
from visualization_msgs.msg import Marker

from geometry_msgs.msg import TransformStamped, Point, PoseStamped
import tf2_ros

class ControlNode(Node):
    wireless_charging_range = 30
    
    
    def __init__(self):
        super().__init__('control_node')
        self.pose_pub = self.create_publisher(PoseStamped, 'goal_pose', 10)
        self.battery_sub = self.create_subscription(std_msgs.msg.Bool, 'iot_charging_request', self.charging_request_callback, 10)
        
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)
    
    def get_frame_position(self, frame_id):
        try:
            transform = self.tf_buffer.lookup_transform('map', frame_id, rclpy.time.Time())
            position = transform.transform.translation
            return position
        except (tf2_ros.LookupException, tf2_ros.ConnectivityException, tf2_ros.ExtrapolationException) as e:
            self.get_logger().error(f'Failed to get transform for {frame_id}: {str(e)}')

    def charging_request_callback(self, msg):
        pose = PoseStamped()
        pose.header.frame_id = "map"
        pose.header.stamp = self.get_clock().now().to_msg()
        
        pos = self.get_frame_position("arduino-nano")
        
        pose.pose.position.x = pos.x
        pose.pose.position.y = pos.y
        pose.pose.position.z = pos.z
        
        self.pose_pub.publish(pose)
        
        
        
        

def main(args=None):
    rclpy.init(args=args)
    node = ControlNode()
    while rclpy.ok():
        rclpy.spin_once(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()