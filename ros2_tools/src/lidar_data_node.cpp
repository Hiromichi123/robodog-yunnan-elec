/*
 * 功能:
 * 订阅里程计数据（实机或仿真），处理后发布雷达位姿信息
 * 兼容PointLIO里程计消息格式
 * 发布消息类型: ros2_tools::msg::LidarPose
 * 订阅消息类型: nav_msgs::msg::Odometry
 * 配置参数:
 * - use_simulation (bool): 是否使用仿真里程计，默认true
 * - simulation_odom_topic (string): 仿真里程计话题，默认"/absolute_pose"
 * - real_robot_odom_topic (string): 实机里程计话题，默认"/aft_mapped_to_init"
 */
#include <cmath>
#include "ros2_tools/navigation_frame.hpp"
#include <chrono>
#include <sstream>
#include <iomanip>
#include <random>
#include <std_msgs/msg/string.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <rclcpp/rclcpp.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

#include "ros2_tools/msg/lidar_pose.hpp"

class LidarDataNode : public rclcpp::Node {
public:
    LidarDataNode() : Node("lidar_data_node") {
        // Even identical numerical startup origins must identify a new process.
        std::random_device random;
        std::ostringstream session;
        session << std::hex << std::chrono::system_clock::now().time_since_epoch().count()
                << '-' << random() << random();
        session_id_ = session.str();
        // 参数声明
        this->declare_parameter<bool>("use_simulation", false);
        this->declare_parameter<std::string>("simulation_odom_topic", "/absolute_pose");
        this->declare_parameter<std::string>("real_robot_odom_topic", "/aft_mapped_to_init");
        // ── 雷达安装变换（车体系 -> 雷达系）──────────────────────────
        // 实机：雷达朝前下方 45°、位于 base_link 正前 0.286m（实测 286mm）。
        // Point-LIO 输出的位姿是雷达(body)系的，这里换算到车体系，
        // 否则静止时 pitch 会读到 45°，且 yaw 是关于倾斜轴的、不等于车体朝向。
        this->declare_parameter<bool>("apply_mount_transform", true);
        this->declare_parameter<double>("mount_x", 0.286);
        this->declare_parameter<double>("mount_y", 0.0);
        this->declare_parameter<double>("mount_z", 0.0);
        this->declare_parameter<double>("mount_roll", 0.0);
        // 实机是**前向倒装 45°** —— 绕 y 轴 −135°（= 180° + 45°）。
        // 不是"朝前下方45°"（那是 +45°，实测对不上：原始姿态反推为 −139.3°，
        // 与 −135° 逐项吻合）。
        this->declare_parameter<double>("mount_pitch", -3.0 * M_PI / 4.0);
        // **2026-10-05 实测修正：mount_yaw 由 0 改成 π。**
        // 症状：goto 时狗沿车头走、上报位姿却反着跑（位移方向与上报 yaw 差
        // ≈180°），即上报的车头方向是物理车头的背面。也就是当初定的这个
        // 安装变换少了一个绕 base_link z 的 180°。
        // 这个 yaw **静态测不出来**：Point-LIO 的 camera_init 世界系 yaw 由
        // 启动时雷达姿态定，而雷达自己看不见绕 z 的安装角 —— 当年"静止姿态
        // 反推"那步把 yaw 假设成 0，是循环论证，这一项从来没被验过。
        // 注意：改的是**旋转整体**（位置会跟着转到真实的 base 原点），
        // 不是只给发布的 yaw 加 180 —— 那样位置和朝向会各说各话。
        this->declare_parameter<double>("mount_yaw", M_PI);
        this->declare_parameter<bool>("normalize_start_pose", true);
        normalize_start_ = this->get_parameter("normalize_start_pose").as_bool();
        // 获取参数值
        using_gazebo_ = this->get_parameter("use_simulation").as_bool();
        std::string sim_topic = this->get_parameter("simulation_odom_topic").as_string();
        std::string real_topic = this->get_parameter("real_robot_odom_topic").as_string();
        apply_mount_ = this->get_parameter("apply_mount_transform").as_bool();
        mount_x_ = this->get_parameter("mount_x").as_double();
        mount_y_ = this->get_parameter("mount_y").as_double();
        mount_z_ = this->get_parameter("mount_z").as_double();
        mount_roll_  = this->get_parameter("mount_roll").as_double();
        mount_pitch_ = this->get_parameter("mount_pitch").as_double();
        mount_yaw_   = this->get_parameter("mount_yaw").as_double();
        if (apply_mount_) {
            RCLCPP_INFO(this->get_logger(),
                "安装变换已启用: 平移(%.3f, %.3f, %.3f) rpy(%.1f°, %.1f°, %.1f°)",
                mount_x_, mount_y_, mount_z_,
                mount_roll_ * 180.0 / M_PI, mount_pitch_ * 180.0 / M_PI,
                mount_yaw_ * 180.0 / M_PI);
        }
        
        // 设置QoS，某些情况下
        //rclcpp::QoS qos_profile = rclcpp::QoS(rclcpp::KeepLast(10)).best_effort();

        // 雷达数据发布
        lidar_pub = this->create_publisher<ros2_tools::msg::LidarPose>("lidar_data", 10);
        RCLCPP_INFO(this->get_logger(), "创建发布 lidar_data");
        world_pub_ = this->create_publisher<ros2_tools::msg::LidarPose>("lidar_data_world", 10);
        origin_pub_ = this->create_publisher<std_msgs::msg::String>(
            "navigation_origin", rclcpp::QoS(1).reliable().transient_local());
        origin_timer_ = this->create_wall_timer(std::chrono::seconds(1), [this]() {
            if (origin_ready_) publishOrigin();
        });

        const auto topic = using_gazebo_ ? sim_topic : real_topic;
        odom_sub = this->create_subscription<nav_msgs::msg::Odometry>(
            topic, 10, [this](const nav_msgs::msg::Odometry::SharedPtr msg) { odomCallback(msg); });
        RCLCPP_INFO(this->get_logger(), "里程计订阅: %s", topic.c_str());
    }

    // 兼容版odom回调
    void odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg) {
        msgDispose(msg->pose.pose);
    }

    // 处理并发布LidarPose消息
    void msgDispose(const geometry_msgs::msg::Pose &pose) {
        // 提取位置和姿态
        double x = pose.position.x;
        double y = pose.position.y;
        double z = pose.position.z;
        tf2::Quaternion q(pose.orientation.x, pose.orientation.y,
                        pose.orientation.z, pose.orientation.w);
        if (!std::isfinite(x) || !std::isfinite(y) || !std::isfinite(z) ||
            !std::isfinite(q.x()) || !std::isfinite(q.y()) || !std::isfinite(q.z()) ||
            !std::isfinite(q.w()) || !std::isfinite(q.length2()) || q.length2() < 1e-12) return;
        q.normalize();
        tf2::Matrix3x3 m(q);
        double roll, pitch, yaw;
        m.getRPY(roll, pitch, yaw);

        if (apply_mount_) {
            // Point-LIO 给的是 T_world_lidar（body 系）。要车体系：
            //     T_world_base = T_world_lidar * T_base_lidar^-1
            // 其中 T_base_lidar 就是安装变换。
            tf2::Transform T_world_lidar;
            T_world_lidar.setOrigin(tf2::Vector3(x, y, z));
            T_world_lidar.setRotation(q);

            tf2::Transform T_base_lidar;
            T_base_lidar.setOrigin(tf2::Vector3(mount_x_, mount_y_, mount_z_));
            tf2::Quaternion q_mount;
            q_mount.setRPY(mount_roll_, mount_pitch_, mount_yaw_);
            T_base_lidar.setRotation(q_mount);

            const tf2::Transform T_world_base = T_world_lidar * T_base_lidar.inverse();
            const tf2::Vector3 o = T_world_base.getOrigin();
            tf2::Matrix3x3 mb(T_world_base.getRotation());
            x = o.x(); y = o.y(); z = o.z();
            q = T_world_base.getRotation();
            mb.getRPY(roll, pitch, yaw);
        }

        ros2_tools::msg::LidarPose world;
        world.x=x; world.y=y; world.z=z;
        world.roll=roll; world.pitch=pitch; world.yaw=yaw;
        world_pub_->publish(world);
        if (!origin_ready_) {
            x0_=normalize_start_ ? x : 0; y0_=normalize_start_ ? y : 0;
            z0_=normalize_start_ ? z : 0; yaw0_=normalize_start_ ? yaw : 0;
            origin_ready_=true;
            publishOrigin();
            RCLCPP_INFO(this->get_logger(), "导航原点: (%.3f, %.3f, %.3f), yaw=%.2f deg",
                        x0_, y0_, z0_, yaw0_*180/M_PI);
        }
        const auto nav = world_to_navigation(x, y, z, x0_, y0_, z0_, yaw0_);
        x = nav[0]; y = nav[1]; z = nav[2];
        tf2::Quaternion rotation;
        rotation.setRPY(0,0,-yaw0_);
        tf2::Matrix3x3(rotation*q).getRPY(roll,pitch,yaw);

        // 归一化到 (-π, π]
        // 原为 [0, 2π)：副作用是"负零"会变成 2π —— 机器人水平静止时 pitch
        // 本应读 0，却读成 6.283，调 SLAM 时极易误判。改用 ROS 惯用的标准区间。
        // 消费端 RobotDogHAL 用 std::remainder 算角差，对区间不敏感。
        auto wrap_pi = [](double a) {
            a = std::fmod(a + M_PI, 2.0 * M_PI);
            if (a < 0) a += 2.0 * M_PI;
            return a - M_PI;
        };
        roll  = wrap_pi(roll);
        pitch = wrap_pi(pitch);
        yaw   = wrap_pi(yaw);

        // 填充并发布LidarPose消息
        lidar_pose.x = x;
        lidar_pose.y = y;
        lidar_pose.z = z;
        lidar_pose.roll = roll;
        lidar_pose.pitch = pitch;
        lidar_pose.yaw = yaw;

        lidar_pub->publish(lidar_pose);

        log(x, y, z, roll, pitch, yaw); // 低频打印日志
    }

    // 低频打印当前位姿日志
    void log(double x, double y, double z, double roll, double pitch, double yaw) {
        RCLCPP_INFO_THROTTLE(
            this->get_logger(),
            *this->get_clock(),
            5000, // 5秒打印一次
            "Position=(%.2f, %.2f, %.2f), Orientation=(%.2f, %.2f, %.2f) rad",
            x, y, z, roll, pitch, yaw);
    }

private:
    void publishOrigin() {
        std::ostringstream out;
        out << std::setprecision(17)
            << "{\"frame\":\"" << (normalize_start_ ? "startup_navigation" : "slam_world")
            << "\",\"session_id\":\"" << session_id_ << "\",\"x\":" << x0_ << ",\"y\":" << y0_
            << ",\"z\":" << z0_ << ",\"yaw\":" << yaw0_ << "}";
        std_msgs::msg::String msg; msg.data=out.str(); origin_pub_->publish(msg);
    }
    std::string session_id_;
    bool normalize_start_=true, origin_ready_=false;
    double x0_=0, y0_=0, z0_=0, yaw0_=0;
    rclcpp::Publisher<ros2_tools::msg::LidarPose>::SharedPtr world_pub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr origin_pub_;
    rclcpp::TimerBase::SharedPtr origin_timer_;
    bool using_gazebo_; // 仿真开关
    bool   apply_mount_ = true;   // 是否把位姿从雷达系换算到车体系
    double mount_x_ = 0.286, mount_y_ = 0.0, mount_z_ = 0.0;
    double mount_roll_ = 0.0, mount_pitch_ = -3.0 * M_PI / 4.0, mount_yaw_ = M_PI;
    
    rclcpp::Publisher<ros2_tools::msg::LidarPose>::SharedPtr lidar_pub;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr local_position_sub;

    ros2_tools::msg::LidarPose lidar_pose;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<LidarDataNode>();
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Lidar_data_node started");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}