#include "layer1_hal/local_safety.hpp"
#include <chrono>
#include <iostream>
#include <thread>
#include <limits>
#include <nlohmann/json.hpp>

namespace {
int failures = 0;
void check(bool yes, const char* label) {
    std::cout << (yes ? "PASS " : "FAIL ") << label << '\n';
    if (!yes) ++failures;
}
void spin(rclcpp::executors::SingleThreadedExecutor& ex, int milliseconds = 180) {
    const auto until = std::chrono::steady_clock::now() + std::chrono::milliseconds(milliseconds);
    while (std::chrono::steady_clock::now() < until) {
        ex.spin_some();
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}
}

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::NodeOptions options;
    options.parameter_overrides({rclcpp::Parameter("safety_mode", "enforce"),
                                rclcpp::Parameter("safety_calibration_validated", false),
                                rclcpp::Parameter("safety_startup_unknown_free", false)});
    auto node = std::make_shared<rclcpp::Node>("local_safety_selftest", options);
    LocalSafety safety(*node);
    rclcpp::executors::SingleThreadedExecutor ex;
    ex.add_node(node);
    const local_nav::Pose pose{0, 0, 0};
    check(!safety.check(pose, true, 0.1, 0), "enforce blocks missing map");
    check(safety.check(pose, false, 0, 0), "zero always passes missing data");
    auto origin_pub = node->create_publisher<std_msgs::msg::String>(
        "/navigation_origin", rclcpp::QoS(1).reliable().transient_local());
    auto map_pub = node->create_publisher<ros2_tools::msg::LocalSafetyMap>(
        "/local_safety/map", rclcpp::QoS(1).best_effort());
    spin(ex);
    std_msgs::msg::String origin;
    origin.data = R"({"frame":"startup_navigation","session_id":"test-epoch","x":0,"y":0,"z":0,"yaw":0})";
    origin_pub->publish(origin);
    ros2_tools::msg::LocalSafetyMap map;
    map.header.frame_id = "startup_navigation";
    map.session_id = "test-epoch";
    map.config_revision = "lidar-only-explicit-v2";
    map.sequence = 1;
    map.valid = true;
    map.grid.header.frame_id = map.header.frame_id;
    map.grid.info.resolution = 0.1;
    map.grid.info.width = 80;
    map.grid.info.height = 80;
    map.grid.info.origin.position.x = -4;
    map.grid.info.origin.position.y = -4;
    map.grid.info.origin.orientation.w = 1;
    map.grid.data.assign(6400, 0);
    auto publish = [&] {
        map.header.stamp = node->now();
        map.grid.header.stamp = map.header.stamp;
        map_pub->publish(map);
        spin(ex, 60);
    };
    publish();
    check(safety.snapshot().valid, "fresh matching session accepted without calibration gate");
    check(safety.check(pose, true, 0.1, 0), "free swept footprint passes");
    for (const std::string revision : {"", "wrong-config", "legacy-explicit-v1"}) {
        map.config_revision = revision;
        map.sequence++;
        publish();
        check(!safety.snapshot().valid, revision.empty() ? "missing revision rejected" : "mismatched revision rejected");
        check(!safety.check(pose, true, 0.1, 0), "invalid revision blocks enforced motion");
        check(safety.check(pose, false, 0, 0), "invalid revision still permits stopping");
    }
    map.config_revision = "lidar-only-explicit-v2";
    map.sequence++;
    publish();
    check(safety.snapshot().valid, "matching revision restores valid map");
    check(!node->set_parameter(rclcpp::Parameter("safety_config_revision", "changed")).successful,
          "configuration revision is startup read-only");
    check(!safety.check(pose, false, 0.1, 0), "stale navigation blocks");
    check(!safety.check(pose, true, -0.1, 0), "reverse rejected");
    check(!safety.check(pose, true, 0.5, 0), "out-of-range speed rejected");
    check(!safety.check(pose, true, std::numeric_limits<double>::quiet_NaN(), 0), "NaN rejected");
    map.sequence++;
    map.grid.data.assign(6400, -1);
    publish();
    check(!safety.check(pose, true, 0.1, 0), "unknown does not mean free");
    map.sequence++;
    map.grid.data.assign(6400, 0);
    map.observation_age_s = 1;
    publish();
    check(!safety.snapshot().valid, "new heartbeat cannot refresh old observation");
    map.sequence++;
    map.observation_age_s = 0;
    publish();
    check(safety.snapshot().valid, "fresh observations restore transient validity");
    origin.data = R"({"frame":"startup_navigation","session_id":"test-epoch"})";
    origin_pub->publish(origin);
    spin(ex, 30);
    map.sequence++;
    publish();
    check(!safety.snapshot().valid, "fresh map cannot override invalid origin coordinates");
    origin.data = R"({"frame":"startup_navigation","session_id":"test-epoch","x":0,"y":0,"z":0,"yaw":0})";
    origin_pub->publish(origin);
    spin(ex, 30);
    map.sequence++;
    publish();
    check(safety.snapshot().valid, "valid unchanged origin restores transient metadata fault");
    spin(ex, 550);
    check(!safety.check(pose, true, 0.1, 0), "receive timeout blocks");
    // Duplicate/regressed sequence is a latched fault, not a new valid frame.
    publish();
    check(!safety.snapshot().valid, "replayed map rejected");
    map.sequence++;
    publish();
    check(!safety.snapshot().valid, "sequence fault stays latched");

    for (const bool change_session : {false, true}) {
        auto opts = options;
        const std::string topic = change_session ? "/origin_session_test" : "/origin_value_test";
        opts.arguments({"--ros-args", "-r", "/navigation_origin:=" + topic});
        auto n = std::make_shared<rclcpp::Node>(change_session ? "session_test" : "value_test", opts);
        LocalSafety guard(*n);
        ex.add_node(n);
        auto publisher = n->create_publisher<std_msgs::msg::String>(
            topic, rclcpp::QoS(1).reliable().transient_local());
        origin.data = R"({"frame":"startup_navigation","session_id":"test-epoch","x":0,"y":0,"z":0,"yaw":0})";
        publisher->publish(origin);
        spin(ex, 60);
        map.sequence++;
        publish();
        check(guard.snapshot().valid, "fresh guard accepts initial origin and map");
        origin.data = change_session
            ? R"({"frame":"startup_navigation","session_id":"new-epoch","x":0,"y":0,"z":0,"yaw":0})"
            : R"({"frame":"startup_navigation","session_id":"test-epoch","x":1,"y":0,"z":0,"yaw":0})";
        publisher->publish(origin);
        spin(ex, 60);
        map.sequence++;
        publish();
        check(!guard.snapshot().valid, change_session ? "origin session change latches stop"
                                                      : "same-session coordinate change latches stop");
        origin.data = R"({"frame":"startup_navigation","session_id":"test-epoch","x":0,"y":0,"z":0,"yaw":0})";
        publisher->publish(origin);
        spin(ex, 60);
        map.sequence++;
        publish();
        check(!guard.snapshot().valid, "origin rollback cannot clear latched epoch fault");
        ex.remove_node(n);
    }

    // Explicit exploration must reach the final velocity gate, not just planning.
    {
        auto opts=options;
        opts.parameter_overrides({rclcpp::Parameter("safety_mode", "enforce"),
                                  rclcpp::Parameter("safety_startup_unknown_free", false),
                                  rclcpp::Parameter("safety_unknown_as_free", true),
                                  rclcpp::Parameter("safety_unknown_exploration_range_m", 5.0),
                                  rclcpp::Parameter("safety_max_vx", .3)});
        opts.arguments({"--ros-args","-r","/navigation_origin:=/explore_origin_test"});
        auto n=std::make_shared<rclcpp::Node>("unknown_exploration_test",opts);
        LocalSafety guard(*n);ex.add_node(n);
        auto pub=n->create_publisher<std_msgs::msg::String>("/explore_origin_test",rclcpp::QoS(1).reliable().transient_local());
        origin.data=R"({"frame":"startup_navigation","session_id":"test-epoch","x":0,"y":0,"z":0,"yaw":0})";
        pub->publish(origin);spin(ex,60);
        map.valid=true;map.grid.data.assign(6400,-1);map.sequence++;publish();
        check(guard.snapshot().exploration_unknown_cells>0,"exploration snapshot reports converted unknown cells");
        check(guard.check({1.5,0,0},true,.3,0),"exploration final gate allows 0.30m/s beyond original startup disk");
        check(!guard.check({1.5,0,0},false,.3,0),"exploration still blocks stale robot pose");
        map.grid.data[40*80+55]=100;map.sequence++;publish();
        check(!guard.check({1.5,0,0},true,.3,0),"exploration final gate blocks real occupied footprint");
        map.valid=false;map.sequence++;publish();
        check(!guard.check({1.5,0,0},true,.3,0),"exploration cannot bypass invalid perception");
        map.valid=true;map.grid.data.assign(6400,0);map.sequence++;publish();
        ex.remove_node(n);
    }

    // Rear motion has its own explicit gate and never inherits unknown-as-free.
    {
        auto opts=options;
        opts.parameter_overrides({rclcpp::Parameter("safety_mode", "enforce"),
                                  rclcpp::Parameter("safety_unknown_as_free", true),
                                  rclcpp::Parameter("safety_max_vx", .3)});
        opts.arguments({"--ros-args","-r","/navigation_origin:=/reverse_origin_test"});
        auto n=std::make_shared<rclcpp::Node>("reverse_recovery_test",opts);
        LocalSafety guard(*n);ex.add_node(n);
        auto pub=n->create_publisher<std_msgs::msg::String>("/reverse_origin_test",rclcpp::QoS(1).reliable().transient_local());
        origin.data=R"({"frame":"startup_navigation","session_id":"test-epoch","x":0,"y":0,"z":0,"yaw":0})";
        pub->publish(origin);spin(ex,60);
        map.valid=true;map.grid.data.assign(6400,0);map.sequence++;publish();
        check(!guard.check(pose,true,-.08,0),"ordinary outlet cannot request recovery reverse");
        check(guard.check_recovery_reverse(pose,true,-.08,0),"dedicated reverse gate accepts real free rear");
        check(!guard.check_recovery_reverse(pose,false,-.08,0),"reverse gate rejects stale pose");
        check(!guard.check_recovery_reverse(pose,true,-.09,0),"reverse gate enforces 0.08m/s cap");
        check(!guard.check_recovery_reverse(pose,true,-.08,.1),"reverse gate permits straight retreat only");
        check(!guard.check_recovery_reverse({-.31,0,0},true,-.08,0),"reverse gate independently limits retreat distance");
        guard.check(pose,true,0,0);
        map.grid.data.assign(6400,-1);map.sequence++;publish();
        check(!guard.check_recovery_reverse(pose,true,-.08,0),"explored unknown rear is insufficient reverse evidence");
        map.grid.data.assign(6400,0);map.grid.data[40*80+33]=100;map.sequence++;publish();
        check(guard.check_recovery_reverse(pose,true,-.08,0),"rear preferred buffer can be consumed with certified stopping clearance");
        guard.check(pose,true,0,0);
        map.grid.data.assign(6400,0);map.grid.data[40*80+34]=100;map.sequence++;publish();
        check(!guard.check_recovery_reverse(pose,true,-.08,0),"rear obstacle inside hard stopping sweep stops recovery reverse");
        map.valid=false;map.sequence++;publish();
        check(!guard.check_recovery_reverse(pose,true,-.08,0),"invalid map stops recovery reverse");
        map.valid=true;map.grid.data.assign(6400,0);map.sequence++;publish();
        ex.remove_node(n);
    }

    // One fixed allowance, shared by planning snapshots and final HAL checks.
    {
        auto opts=options;
        opts.parameter_overrides({rclcpp::Parameter("safety_mode", "enforce"),
                                  rclcpp::Parameter("safety_startup_unknown_free", true)});
        opts.arguments({"--ros-args","-r","/navigation_origin:=/startup_origin_test"});
        auto n=std::make_shared<rclcpp::Node>("startup_unknown_test",opts);
        LocalSafety guard(*n);ex.add_node(n);
        auto pub=n->create_publisher<std_msgs::msg::String>("/startup_origin_test",rclcpp::QoS(1).reliable().transient_local());
        origin.data=R"({"frame":"startup_navigation","session_id":"test-epoch","x":0,"y":0,"z":0,"yaw":0})";
        pub->publish(origin);spin(ex,60);
        map.grid.data.assign(6400,-1);map.sequence++;publish();
        guard.prepare_startup(pose,false);
        check(guard.snapshot().startup_unknown_cells==0,"stale pose cannot initialize startup allowance");
        guard.prepare_startup(pose,true);
        const auto seeded=guard.snapshot();
        check(seeded.valid && seeded.startup_unknown_cells>0,"fresh valid map seeds startup unknown cells");
        const auto at=[](const local_nav::Grid& g,double x,double y) {
            return g.cells[static_cast<std::size_t>(std::floor((y-g.origin_y)/g.resolution))*g.width+
                           static_cast<std::size_t>(std::floor((x-g.origin_x)/g.resolution))];
        };
        check(at(*seeded.grid,0,0)==0,"initial body unknown becomes free");
        check(at(*seeded.grid,2,0)==-1,"outside startup allowance remains unknown");
        check(guard.check(pose,true,0,.35),"fixed startup disk covers initial rotation sweep");
        guard.prepare_startup({.2,0,0},true);
        check(at(*guard.snapshot().grid,1.7,0)==-1,"startup allowance does not move with robot");
        map.grid.data[40*80+40]=100;map.sequence++;publish();
        check(at(*guard.snapshot().grid,.05,.05)==100,"occupied inside startup area stays occupied");
        check(!guard.check(pose,true,.03,0),"occupied startup area still blocks motion");
        map.grid.data.assign(6400,-1);map.sequence++;publish();
        check(guard.check(pose,true,.03,0),"low speed startup sweep can use fixed allowance");
        check(!guard.check({2.0,0,0},true,.15,0),"sweep beyond fixed allowance remains blocked");
        map.valid=false;map.sequence++;publish();
        check(!guard.snapshot().valid && guard.snapshot().startup_unknown_cells==0,"invalid map cannot use allowance");
        map.valid=true;map.sequence++;publish();
        guard.prepare_startup({1.5,0,0},true);
        check(guard.snapshot().startup_unknown_cells==0,"leaving startup region permanently retires allowance");
        guard.prepare_startup(pose,true);
        check(guard.snapshot().startup_unknown_cells==0,"returning cannot reseed startup allowance");
        ex.remove_node(n);
    }

    for (const std::string mode : {"disabled", "observe", "enforce"}) {
        rclcpp::NodeOptions opts;
        opts.parameter_overrides({rclcpp::Parameter("safety_mode", mode),
                                  rclcpp::Parameter("safety_max_vx", 0.12),
                                  rclcpp::Parameter("safety_config_revision", std::string(64, 'a'))});
        const std::string status_topic = "/safety_status_test/" + mode;
        opts.arguments({"--ros-args", "-r", "/dog/safety/status:=" + status_topic});
        auto n = std::make_shared<rclcpp::Node>("safety_" + mode, opts);
        LocalSafety s(*n);
        check(s.check(pose, true, 0.1, 0) == (mode != "enforce"),
              (mode + " missing-map semantics").c_str());
        check(s.check(pose, false, 0, 0), (mode + " zero pass").c_str());
        nlohmann::json status;
        auto sub = n->create_subscription<std_msgs::msg::String>(status_topic, rclcpp::QoS(1),
            [&](std_msgs::msg::String::ConstSharedPtr msg) { status = nlohmann::json::parse(msg->data); });
        ex.add_node(n);
        spin(ex, 1150);
        check(status.is_object() && status.value("mode", "") == mode &&
              status.value("revision", "") == std::string(64, 'a') &&
              status.value("protocol_version", 0) == 2 &&
              status.value("sensor_source", "") == "lidar" &&
              status.contains("calibration_required") && !status["calibration_required"].get<bool>(),
              (mode + " reports actual startup mode/revision").c_str());
        check(status.contains("config") && status["config"]["control"]["max_vx"] == 0.12,
              (mode + " reports actual configured values").c_str());
        check(status.contains("protection_ready") && !status["protection_ready"].get<bool>() &&
              !status["map_valid"].get<bool>() && !status["calibration_validated"].get<bool>(),
              (mode + " never reports missing-map protection ready").c_str());
        ex.remove_node(n);
    }
    rclcpp::shutdown();
    std::cout << "failures=" << failures << '\n';
    return failures ? 1 : 0;
}
