import os
os.environ['ROS_DOMAIN_ID']='187'
os.environ['ROS_LOCALHOST_ONLY']='1'
import math,time,subprocess,signal,json
import rclpy
from nav_msgs.msg import Odometry
from ros2_tools.msg import LidarPose
from std_msgs.msg import String

def quat(r,p,y):
    cr,sr=math.cos(r/2),math.sin(r/2);cp,sp=math.cos(p/2),math.sin(p/2);cy,sy=math.cos(y/2),math.sin(y/2)
    return (sr*cp*cy-cr*sp*sy,cr*sp*cy+sr*cp*sy,cr*cp*sy-sr*sp*cy,cr*cp*cy+sr*sp*sy)
def mul(a,b):
    x,y,z,w=a;X,Y,Z,W=b
    return (w*X+x*W+y*Z-z*Y,w*Y-x*Z+y*W+z*X,w*Z+x*Y-y*X+z*W,w*W-x*X-y*Y-z*Z)
def close(a,b):
    assert abs(a-b)<1e-5,(a,b)
def spin(n,t):
    end=time.monotonic()+t
    while time.monotonic()<end:rclpy.spin_once(n,timeout_sec=.02)
def case(yaw,mount=False):
    proc=subprocess.Popen([os.path.expanduser('~/ros2_ws/install/lib/ros2_tools/lidar_data_node'),'--ros-args','-p','real_robot_odom_topic:=/test/odom','-p','apply_mount_transform:='+str(mount).lower()],stdout=subprocess.DEVNULL)
    n=rclpy.create_node('navigation_origin_test');pub=n.create_publisher(Odometry,'/test/odom',10)
    poses=[];origins=[]
    sub=n.create_subscription(LidarPose,'/lidar_data',poses.append,10)
    so=n.create_subscription(String,'/navigation_origin',lambda m:origins.append(json.loads(m.data)),10)
    def send(x,y,z,angle):
        m=Odometry();q=quat(.03,-.04,angle)
        if mount:
            v=mul(mul(q,(.286,0,0,0)),(-q[0],-q[1],-q[2],q[3]));x+=v[0];y+=v[1];z+=v[2]
            q=mul(q,quat(0,-3*math.pi/4,math.pi))
        m.pose.pose.position.x=x;m.pose.pose.position.y=y;m.pose.pose.position.z=z
        m.pose.pose.orientation.x=q[0];m.pose.pose.orientation.y=q[1];m.pose.pose.orientation.z=q[2];m.pose.pose.orientation.w=q[3]
        for _ in range(8):pub.publish(m);spin(n,.03)
    try:
        spin(n,1);invalid=Odometry();invalid.pose.pose.orientation.w=0.0;pub.publish(invalid);spin(n,.1);assert not poses
        send(3.,4.,2.,yaw);assert poses
        close(poses[-1].x,0);close(poses[-1].y,0);close(poses[-1].yaw,0)
        send(3+math.cos(yaw),4+math.sin(yaw),2.,yaw)
        close(poses[-1].x,1);close(poses[-1].y,0);close(poses[-1].yaw,0)
        close(math.remainder(math.atan2(-poses[-1].y,2-poses[-1].x)-poses[-1].yaw,2*math.pi),0)
        send(3-math.sin(yaw),4+math.cos(yaw),2.,yaw+.2)
        close(poses[-1].x,0);close(poses[-1].y,1);close(poses[-1].yaw,.2)
        spin(n,1.1);assert origins;close(origins[-1]['x'],3);close(origins[-1]['y'],4)
        print('PASS yaw=',yaw,'mount=',mount)
    finally:
        n.destroy_node();proc.send_signal(signal.SIGINT);proc.wait(timeout=10)
rclpy.init()
try:
    for y in [0.,math.pi,-math.pi+.001,1.2]:case(y)
    case(math.pi,True)
finally:rclpy.shutdown()
