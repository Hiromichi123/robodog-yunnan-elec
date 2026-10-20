#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstring>
#include <deque>
#include <limits>
#include <memory>
#include <iterator>
#include <stdexcept>
#include <string>

#include <nlohmann/json.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <std_msgs/msg/string.hpp>
#include <tf2/LinearMath/Transform.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>

#include "ros2_tools/local_safety_evidence.hpp"
#include "ros2_tools/local_safety_filter.hpp"
#include "ros2_tools/bounded_pose_buffer.hpp"
#include "ros2_tools/msg/local_safety_map.hpp"
#include "ros2_tools/navigation_frame.hpp"

namespace {
using Steady = std::chrono::steady_clock;
double steady_s() { return std::chrono::duration<double>(Steady::now().time_since_epoch()).count(); }
double stamp_s(const builtin_interfaces::msg::Time& s) {
    return static_cast<double>(s.sec)+1e-9*s.nanosec;
}
bool finite(const tf2::Vector3& p) {
    return std::isfinite(p.x()) && std::isfinite(p.y()) && std::isfinite(p.z());
}
bool transform(const geometry_msgs::msg::Pose& p, tf2::Transform& out) {
    tf2::Vector3 v(p.position.x,p.position.y,p.position.z);
    tf2::Quaternion q(p.orientation.x,p.orientation.y,p.orientation.z,p.orientation.w);
    if (!finite(v) || std::abs(v.x())>100000 || std::abs(v.y())>100000 || std::abs(v.z())>100000 ||
        !std::isfinite(q.length2()) || q.length2()<1e-12) return false;
    q.normalize(); out=tf2::Transform(q,v); return true;
}
using Pose = local_safety::TimedPose;
}

class LocalObstacleNode : public rclcpp::Node {
public:
    LocalObstacleNode() : Node("local_obstacle_node"), tf_(get_clock()), listener_(tf_) {
        rcl_interfaces::msg::ParameterDescriptor fixed;
        fixed.read_only=true;
        config_revision_=declare_parameter<std::string>("config_revision","lidar-only-explicit-v2",fixed);
        if (config_revision_.empty() || config_revision_.size()>128)
            throw std::invalid_argument("invalid config_revision");
        // Deprecated compatibility parameter, not a readiness gate.
        declare_parameter<bool>("calibration_validated",false,fixed);
        local_safety::EvidenceGrid::Config c;
        c.resolution=declare_parameter<double>("resolution",0.10,fixed);
        c.width=declare_parameter<int>("width",120,fixed);
        c.ground_z=declare_parameter<double>("ground_z",-0.35,fixed);
        c.obstacle_min_height=declare_parameter<double>("obstacle_min_height",0.06,fixed);
        c.obstacle_max_height=declare_parameter<double>("obstacle_max_height",0.72,fixed);
        c.free_ttl=declare_parameter<double>("free_ttl_s",0.8,fixed);
        c.floor_ttl=declare_parameter<double>("floor_ttl_s",1.5,fixed);
        grid_=std::make_unique<local_safety::EvidenceGrid>(c);
        max_age_=declare_parameter<double>("max_observation_age_s",0.40,fixed);
        max_gap_=declare_parameter<double>("max_pose_gap_s",0.20,fixed);
        max_range_=declare_parameter<double>("max_range_m",5.0,fixed);
        max_return_range_=declare_parameter<double>("max_return_range_m",10.0,fixed);
        min_range_=declare_parameter<double>("min_range_m",0.60,fixed);
        max_clear_rays_=declare_parameter<int>("max_clear_rays_per_cloud",12000,fixed);
        // The box is a self-return exclusion, NOT a declared safe/free footprint.
        self_half_length_=declare_parameter<double>("self_half_length",0.55,fixed);
        self_half_width_=declare_parameter<double>("self_half_width",0.35,fixed);
        self_min_z_=declare_parameter<double>("self_min_z",-0.30,fixed);
        self_max_z_=declare_parameter<double>("self_max_z",0.15,fixed);
        if (!std::isfinite(max_age_) || max_age_<=0 || max_age_>1 ||
            !std::isfinite(max_gap_) || max_gap_<=0 || max_gap_>0.3 ||
            !std::isfinite(max_range_) || max_range_<0.5 || max_range_>5.0 || max_range_>c.width*c.resolution*.5-c.resolution ||
            !std::isfinite(min_range_) || min_range_<0 || min_range_>=max_range_ ||
            !std::isfinite(max_return_range_) || max_return_range_<max_range_ || max_return_range_>10.0 ||
            max_clear_rays_<100 || max_clear_rays_>50000 ||
            !std::isfinite(self_half_length_) || self_half_length_<=0 || self_half_length_>0.8 ||
            !std::isfinite(self_half_width_) || self_half_width_<=0 || self_half_width_>0.5 ||
            !std::isfinite(self_min_z_) || !std::isfinite(self_max_z_) ||
            self_min_z_>=self_max_z_ || self_min_z_< -1.0 || self_max_z_>1.0)
            throw std::invalid_argument("invalid local safety sensor limits");
        pub_=create_publisher<ros2_tools::msg::LocalSafetyMap>("/local_safety/map",rclcpp::QoS(1).reliable());
        status_pub_=create_publisher<std_msgs::msg::String>("/local_safety/status",rclcpp::QoS(1).reliable());
        origin_sub_=create_subscription<std_msgs::msg::String>("/navigation_origin",
            rclcpp::QoS(1).reliable().transient_local(),[this](std_msgs::msg::String::ConstSharedPtr m){ origin(*m); });
        odom_sub_=create_subscription<nav_msgs::msg::Odometry>(
            declare_parameter<std::string>("odom_topic","/aft_mapped_to_init",fixed),rclcpp::SensorDataQoS(),
            [this](nav_msgs::msg::Odometry::ConstSharedPtr m){ odom(*m); });
        cloud_sub_=create_subscription<sensor_msgs::msg::PointCloud2>(
            declare_parameter<std::string>("lidar_topic","/cloud_registered_body",fixed),rclcpp::SensorDataQoS(),
            [this](sensor_msgs::msg::PointCloud2::ConstSharedPtr m){
                if (pending_.size()>=3) pending_.pop_front();
                pending_.push_back({m,steady_s()});
            });
        timer_=create_wall_timer(std::chrono::milliseconds(100),[this](){tick();});
        RCLCPP_WARN(get_logger(),"局部感知 source=lidar；无人工标定门禁，仍检查观测、位姿、时间及坐标有效性");
    }
private:
    void reset_map() {
        grid_->clear(); poses_.clear();
        pending_.clear();
        sensor_=Sensor{};
        odom_rx_=0; odom_stamp_=0; world_frame_.clear(); fault_.clear();
    }
    void origin(const std_msgs::msg::String& m) {
        try {
            const auto j=nlohmann::json::parse(m.data);
            const auto session=j.at("session_id").get<std::string>();
            const auto frame=j.at("frame").get<std::string>();
            const std::array<double,4> value{{j.at("x").get<double>(),j.at("y").get<double>(),
                                            j.at("z").get<double>(),j.at("yaw").get<double>()}};
            if (session.empty() || session.size()>128 || frame!="startup_navigation" ||
                !std::all_of(value.begin(),value.end(),[](double v){return std::isfinite(v) && std::abs(v)<100000;}))
                throw std::invalid_argument("invalid origin");
            if (!origin_ready_ || session!=session_) {
                reset_map(); session_=session; origin_=value; origin_ready_=true;
            } else if (value!=origin_) {
                fault_="navigation_origin_changed_without_new_session"; grid_->clear();
            }
            origin_rx_=steady_s();
        } catch (const std::exception&) {
            fault_="invalid_navigation_origin"; grid_->clear();
        }
    }
    void odom(const nav_msgs::msg::Odometry& m) {
        if (!origin_ready_ || !fault_.empty()) return;
        const double s=stamp_s(m.header.stamp), t=now().seconds();
        tf2::Transform pose;
        if (m.child_frame_id!="body" || m.header.frame_id.empty() ||
            !transform(m.pose.pose,pose) || s<=0 || t-s< -0.05 || t-s>max_age_) {
            odom_rx_=0; return;
        }
        if (!poses_.empty()) {
            const auto& last=poses_.back();
            const double dt=s-last.stamp;
            if (dt==0) return;  // duplicates cannot refresh the watchdog
            if (dt<0 || dt>1.0 || m.header.frame_id!=world_frame_ ||
                (pose.getOrigin()-last.value.getOrigin()).length()>0.15+1.0*dt ||
                pose.getRotation().angleShortestPath(last.value.getRotation())>0.15+2.0*dt) {
                fault_="odometry_reset_or_jump_restart_navigation_required"; grid_->clear(); return;
            }
        }
        world_frame_=m.header.frame_id; poses_.push_back({s,pose});
        while (poses_.size()>80) poses_.pop_front();
        odom_rx_=steady_s(); odom_stamp_=s;
    }
    bool pose_at(double s, tf2::Transform& out) const {
        return local_safety::interpolate_pose(poses_,s,max_gap_,out);
    }
    tf2::Transform navigation_from_world() const {
        tf2::Quaternion q; q.setRPY(0,0,-origin_[3]);
        const auto p=world_to_navigation(0,0,0,origin_[0],origin_[1],origin_[2],origin_[3]);
        return tf2::Transform(q,tf2::Vector3(p[0],p[1],p[2]));
    }
    bool cloud(const sensor_msgs::msg::PointCloud2& m,double rx) {
        const double s=stamp_s(m.header.stamp), current=now().seconds();
        const double acquired_steady=steady_s()-std::max(0.0,current-s);
        if (!origin_ready_ || !fault_.empty()) return false;
        if (sensor_.stamp>0 && s<sensor_.stamp-0.01) {
            fault_="sensor_time_reversed_restart_navigation_required"; grid_->clear(); return false;
        }
        if (current-s< -0.05 || current-s>max_age_ || s<=0) {
            sensor_.error="cloud_clock_domain_or_age_invalid"; return false;
        }
        if (s<=sensor_.stamp) return false;  // duplicates never refresh evidence
        const std::string expected="body";
        if (m.header.frame_id!=expected) { sensor_.error="unexpected_cloud_frame"; return false; }
        tf2::Transform world_body;
        if (!pose_at(s,world_body)) { sensor_.error="no_bounded_pose_interpolation"; return false; }
        tf2::Transform body_sensor,base_body;
        try {
            body_sensor.setIdentity();
            tf2::fromMsg(tf_.lookupTransform("base_link","body",tf2::TimePointZero).transform,base_body);
        } catch (const tf2::TransformException&) {
            sensor_.error="missing_verified_static_tf"; return false;
        }
        if (!finite(body_sensor.getOrigin()) || !finite(base_body.getOrigin()) ||
            body_sensor.getOrigin().length()>2.0 || base_body.getOrigin().length()>2.0 ||
            !std::isfinite(body_sensor.getRotation().length2()) ||
            !std::isfinite(base_body.getRotation().length2()) ||
            std::abs(body_sensor.getRotation().length2()-1.0)>1e-3 ||
            std::abs(base_body.getRotation().length2()-1.0)>1e-3) {
            sensor_.error="invalid_static_tf"; return false;
        }
        const auto nav_body=navigation_from_world()*world_body;
        const auto nav_sensor=nav_body*body_sensor;
        const auto base_sensor=base_body*body_sensor;
        const auto nav_base=nav_body*base_body.inverse();
        grid_->recenter(nav_base.getOrigin().x(),nav_base.getOrigin().y());
        // A malformed cloud must not be parsed through unchecked field offsets.
        int offsets[3]={-1,-1,-1};
        for (const auto& f:m.fields) for (int k=0;k<3;++k)
            if (f.name==std::array<const char*,3>{{"x","y","z"}}[k] &&
                f.datatype==sensor_msgs::msg::PointField::FLOAT32 && f.count==1 &&
                f.offset+sizeof(float)<=m.point_step) offsets[k]=static_cast<int>(f.offset);
        if (m.is_bigendian || m.point_step<12 || m.width==0 || m.height==0 ||
            m.width>1000000 || m.height>1000000 ||
            static_cast<std::uint64_t>(m.width)*m.height>2000000 ||
            static_cast<std::uint64_t>(m.row_step)<static_cast<std::uint64_t>(m.width)*m.point_step ||
            static_cast<std::uint64_t>(m.row_step)*m.height>m.data.size() ||
            offsets[0]<0 || offsets[1]<0 || offsets[2]<0) {
            sensor_.error="malformed_or_empty_cloud"; return false;
        }
        grid_->begin_frame();
        const auto o=nav_sensor.getOrigin();
        const std::array<double,3> ray_origin{{o.x(),o.y(),o.z()}};
        const std::size_t count=static_cast<std::size_t>(m.width)*m.height;
        const std::size_t stride=std::max<std::size_t>(1,(count+max_clear_rays_-1)/max_clear_rays_);
        std::size_t accepted=0;
        for (std::uint32_t y=0;y<m.height;++y) for (std::uint32_t x=0;x<m.width;++x) {
            const auto* p=m.data.data()+static_cast<std::size_t>(y)*m.row_step+static_cast<std::size_t>(x)*m.point_step;
            float xyz[3]; for (int k=0;k<3;++k) std::memcpy(&xyz[k],p+offsets[k],sizeof(float));
            tf2::Vector3 sensor(xyz[0],xyz[1],xyz[2]);
            if (!local_safety::sensor_return_in_range(sensor.x(),sensor.y(),sensor.z(),min_range_,max_return_range_)) continue;
            const auto bp=base_sensor*sensor;
            if (local_safety::inside_self_box(bp.x(),bp.y(),bp.z(),self_half_length_,self_half_width_,
                                              self_min_z_,self_max_z_)) continue;
            const auto np=nav_sensor*sensor;
            grid_->ray(ray_origin,{{np.x(),np.y(),np.z()}},
                       (static_cast<std::size_t>(y)*m.width+x)%stride==0,max_range_);
            ++accepted;
        }
        if (accepted<20) { sensor_.error="insufficient_valid_returns"; return false; }
        // Evidence ages are acquisition ages mapped onto steady time. Processing
        // a queued old cloud must not make old space fresh again.
        grid_->end_frame(acquired_steady);
        sensor_={s,rx,""}; return true;
    }
    void tick() {
        const double t=steady_s(), ros=now().seconds();
        if (last_ros_>0 && ros<last_ros_-0.01) { fault_="ros_clock_reversed"; grid_->clear(); }
        last_ros_=ros;
        while (!pending_.empty()) {
            const auto& next=pending_.front();
            const double stamp=stamp_s(next.msg->header.stamp);
            if (!poses_.empty() && stamp>poses_.back().stamp && t-next.received<0.15) break;
            cloud(*next.msg,next.received); pending_.pop_front();
        }
        ros2_tools::msg::LocalSafetyMap out;
        out.session_id=session_; out.sequence=++sequence_; out.config_revision=config_revision_;
        const double oldest=std::min(sensor_.stamp,odom_stamp_);
        const double publish_ros=now().seconds(), publish_steady=steady_s();
        const double age=oldest>0 ? std::max(0.0,publish_ros-oldest) : 1e6;
        out.header.frame_id="startup_navigation";
        out.header.stamp=rclcpp::Time(static_cast<std::int64_t>(std::max(0.0,oldest)*1e9));
        out.observation_age_s=static_cast<float>(age);
        if (!origin_ready_ || publish_steady-origin_rx_>2.5) out.reason="navigation_origin_missing_or_stale";
        else if (!fault_.empty()) out.reason=fault_;
        else if (odom_rx_<=0 || publish_steady-odom_rx_>max_age_) out.reason="odometry_missing_or_stale";
        else if (age>max_age_) out.reason="sensor_acquisition_stale_or_missing";
        else if (!sensor_.error.empty()) out.reason="invalid_sensor_frame";
        else if (publish_steady-sensor_.received>max_age_)
            out.reason="lidar_reception_stale";
        else out.valid=true;
        if (!out.valid && !sensor_.error.empty()) out.reason+=";"+sensor_.error;
        out.grid.header=out.header;
        out.grid.info.resolution=grid_->config().resolution;
        out.grid.info.width=grid_->config().width; out.grid.info.height=grid_->config().width;
        out.grid.info.origin.position.x=grid_->origin_x(); out.grid.info.origin.position.y=grid_->origin_y();
        out.grid.info.origin.orientation.w=1.0;
        out.grid.data=grid_->snapshot(steady_s());
        pub_->publish(out);
        if (publish_steady-last_status_>=1.0) {
            const auto& c=grid_->config();
            const nlohmann::json perception={
                {"ground_z",c.ground_z}, {"obstacle_min_height",c.obstacle_min_height},
                {"obstacle_max_height",c.obstacle_max_height}, {"free_ttl_s",c.free_ttl},
                {"floor_ttl_s",c.floor_ttl}, {"max_observation_age_s",max_age_},
                {"max_pose_gap_s",max_gap_}, {"max_range_m",max_range_}
            };
            std_msgs::msg::String status;
            status.data=nlohmann::json({
                {"protocol_version",2}, {"sensor_source","lidar"}, {"calibration_required",false}, {"revision",config_revision_},
                {"config",{{"perception",perception}}}, {"calibration_validated",false},
                {"max_return_range_m",max_return_range_},
                {"self_filter",{{"half_length",self_half_length_},{"half_width",self_half_width_},
                                {"min_z",self_min_z_},{"max_z",self_max_z_},{"min_range_m",min_range_}}},
                {"valid",out.valid}, {"reason",out.reason}, {"session_id",session_},
                {"sequence",out.sequence}, {"observation_age_s",age}
            }).dump();
            status_pub_->publish(status);
            last_status_=publish_steady;
        }
    }
    struct Sensor { double stamp{0},received{0}; std::string error; };
    struct Pending { sensor_msgs::msg::PointCloud2::ConstSharedPtr msg; double received; };
    bool origin_ready_{false};
    std::string session_,fault_,world_frame_,config_revision_;
    std::array<double,4> origin_{};
    double origin_rx_{0},odom_rx_{0},odom_stamp_{0},last_ros_{0},last_status_{0};
    double max_age_,max_gap_,max_range_,max_return_range_,min_range_,self_half_length_,self_half_width_,self_min_z_,self_max_z_;
    int max_clear_rays_;
    std::uint64_t sequence_{0};
    Sensor sensor_;
    std::deque<Pending> pending_;
    std::deque<Pose> poses_;
    std::unique_ptr<local_safety::EvidenceGrid> grid_;
    tf2_ros::Buffer tf_;
    tf2_ros::TransformListener listener_;
    rclcpp::Publisher<ros2_tools::msg::LocalSafetyMap>::SharedPtr pub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr status_pub_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr origin_sub_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr cloud_sub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc,char** argv) {
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<LocalObstacleNode>());
    rclcpp::shutdown();
    return 0;
}
