from types import NoneType
import rclpy
from rclpy.node import Node
import std_msgs.msg
from visualization_msgs.msg import Marker
import math

from geometry_msgs.msg import TransformStamped, Point
import tf2_ros

class MarkerNode(Node):
    charging = False
    
    def __init__(self):
        super().__init__('marker_publisher_and_subscriber')
        
        # Publishers
        self.marker_pub = self.create_publisher(Marker, 'iot_marker', 10)
        self.charging_request_pub = self.create_publisher(std_msgs.msg.Bool, 'iot_charging_request', 10)
        self.iot_charging_in_range_pub = self.create_publisher(std_msgs.msg.Bool, 'iot_charging_in_range', 10)
        self.iot_charging_not_in_range_pub = self.create_publisher(std_msgs.msg.Bool, 'iot_charging_not_in_range', 10)
        
        # Subscribers
        self.battery_sub = self.create_subscription(std_msgs.msg.Int16, 'iot_battery', self.battery_callback, 10)
        
        #Timers
        self.timer = self.create_timer(1.0, self.check_if_charging)
        
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)
    
    def get_frame_position(self, frame_id):
        try:
            transform = self.tf_buffer.lookup_transform('map', frame_id, rclpy.time.Time())
            position = transform.transform.translation
            return position
        except (tf2_ros.LookupException, tf2_ros.ConnectivityException, tf2_ros.ExtrapolationException) as e:
            self.get_logger().error(f'Failed to get transform for {frame_id}: {str(e)}')

    def check_if_charging(self):
        charging_robot_position = self.get_frame_position("base_footprint")
        iot_device_position = self.get_frame_position("arduino-nano")
        
    
        try:
            distance_from_charging_range = math.sqrt(
                                    math.pow((iot_device_position.x - charging_robot_position.x), 2)
                                    + math.pow((iot_device_position.y - charging_robot_position.y), 2)
                                    + math.pow((iot_device_position.z - charging_robot_position.z), 2))
        
            if distance_from_charging_range <= 5.0:
                self.charging = True 
                self.iot_charging_in_range_pub.publish(std_msgs.msg.Bool())
            else:
                self.charging = False
                self.iot_charging_not_in_range_pub.publish(std_msgs.msg.Bool())
        except AttributeError as e:
            self.get_logger().error(str(e))
            

    def battery_callback(self, msg):
        # Publishes the Marker to rviz
        marker = Marker()
        marker.header.frame_id = "map"
        marker.ns = "basic_shapes"
        marker.id = 0
        marker.type = marker.SPHERE
        marker.action = marker.ADD
        
        pos = self.get_frame_position("arduino-nano")
        
        if pos is None:
            pos = Point()
            pos.x = 0.0
            pos.y = 0.0
            pos.z = 0.0
        
        marker.pose.position.x = pos.x
        marker.pose.position.y = pos.y
        marker.pose.position.z = pos.z
        
        marker.pose.orientation.x = 0.0
        marker.pose.orientation.y = 0.0
        marker.pose.orientation.z = 0.0
        marker.pose.orientation.w = 1.0
        marker.scale.x = 1.0
        marker.scale.y = 1.0
        marker.scale.z = 1.0

        battery_level = msg.data
        if battery_level < 80:
            marker.color.r = 1.0
            marker.color.g = 0.0
            marker.color.b = 0.0
            self.charging_request_pub.publish(std_msgs.msg.Bool())
        elif battery_level < 95:
            marker.color.r = 1.0
            marker.color.g = 1.0
            marker.color.b = 0.0
        else:
            marker.color.r = 0.0
            marker.color.g = 1.0
            marker.color.b = 0.0
        marker.color.a = 1.0

        marker.header.stamp = self.get_clock().now().to_msg()
        self.marker_pub.publish(marker)
    

def main(args=None):
    rclpy.init(args=args)
    node = MarkerNode()
    while rclpy.ok():
        rclpy.spin_once(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()