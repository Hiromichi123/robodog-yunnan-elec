#include <cstdlib>
#include <iostream>
#include "ros2_tools/bounded_pose_buffer.hpp"

int main() {
    int n=0;
    const auto check=[&](bool ok,const char* what){++n;if(!ok){std::cerr<<what<<'\n';std::exit(1);}};
    std::deque<local_safety::TimedPose> poses;
    tf2::Transform result;
    check(!local_safety::interpolate_pose(poses,1,0.2,result),"empty buffer");
    tf2::Quaternion a,b;a.setRPY(0,0,3.0);b.setRPY(0,0,-3.0);
    poses.push_back({1,tf2::Transform(a,tf2::Vector3(0,0,0))});
    poses.push_back({1.1,tf2::Transform(b,tf2::Vector3(0.2,0.4,0.6))});
    check(local_safety::interpolate_pose(poses,1.05,0.2,result),"bounded interpolation");
    check((result.getOrigin()-tf2::Vector3(0.1,0.2,0.3)).length()<1e-8,"linear position");
    tf2::Quaternion midpoint;midpoint.setRPY(0,0,3.141592653589793);
    check(result.getRotation().angleShortestPath(midpoint)<1e-6,"shortest quaternion arc across pi");
    check(local_safety::interpolate_pose(poses,1.1,0.2,result),"exact sample");
    check(!local_safety::interpolate_pose(poses,0.99,0.2,result),"no past extrapolation");
    check(!local_safety::interpolate_pose(poses,1.11,0.2,result),"no future extrapolation");
    check(!local_safety::interpolate_pose(poses,1.05,0.05,result),"large gap rejected");
    check(!local_safety::interpolate_pose(poses,1.05,-1,result),"invalid limit rejected");
    std::cout<<"bounded_pose_buffer_selftest: "<<n<<" passed\n";
}
