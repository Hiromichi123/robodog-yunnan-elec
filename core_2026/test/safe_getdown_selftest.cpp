#include "layer1_hal/robot_dog_hal.hpp"
#include <nlohmann/json.hpp>
#include <atomic>
#include <cstdlib>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;
using Clock = std::chrono::steady_clock;

int main(int argc, char** argv) {
    // 双重硬门禁：测试必须与真狗 DDS 隔离，不能仅依赖调用者记得改域。
    const auto domain = std::getenv("ROS_DOMAIN_ID");
    const auto local = std::getenv("ROS_LOCALHOST_ONLY");
    if (!domain || std::string(domain) != "163" || !local || std::string(local) != "1") {
        std::cerr << "Requires ROS_DOMAIN_ID=163 ROS_LOCALHOST_ONLY=1\n";
        return 2;
    }
    rclcpp::init(argc, argv);
    int failures = 0;
    auto run = [&](const std::string& name, std::string initial, bool settled,
                   const std::string& mode, bool expected, int expected_commands) {
        auto hal = std::make_shared<RobotDogHAL>();
        auto fake = std::make_shared<rclcpp::Node>("fake_cerebellum");
        auto posture = fake->create_publisher<std_msgs::msg::String>("/rl_real/posture", 10);
        auto heartbeat = fake->create_publisher<std_msgs::msg::String>("/rl_real/heartbeat", 10);
        auto result = fake->create_publisher<std_msgs::msg::String>("/rl_real/cmd_state", 10);
        std::atomic<int> commands{0};
        std::atomic<bool> started{false};
        int active_ticks = 0;
        auto sub = fake->create_subscription<std_msgs::msg::String>("/rl_real/command", 10,
            [&](std_msgs::msg::String::SharedPtr m) {
                if (m->data == "getdown") ++commands;
                else { std::cerr << "Unexpected command: " << m->data << '\n'; ++commands; }
            });
        auto timer = fake->create_wall_timer(20ms, [&] {
            const bool active = started.load();
            const double dt = active ? (++active_ticks * .02) : 0.0;
            std::string state = initial;
            bool done = settled;
            if (mode == "becomes_ready" && active && dt > .15) done = true;
            if (mode == "already_down" && active && dt > .15) { state = "RLFSMStatePassive"; done = true; }
            if (commands > 0 && mode != "reject" && mode != "no_done" && mode != "no_settled") {
                state = "RLFSMStatePassive"; done = true;
            }
            if (commands > 0 && mode == "no_settled") { state = "RLFSMStateGetDown"; done = false; }
            if (mode == "stale" && active) return;
            nlohmann::json j{{"fsm",state},{"settled",done},{"gamepad_override",mode == "gamepad"}};
            if (mode == "missing") j.erase("settled");
            if (mode == "invalid") j["settled"] = "true";
            std_msgs::msg::String msg;
            if (mode == "mismatch") {
                // 先前 Passive 的 settled 不能与后来的 GetUp 心跳拼接。
                if (!active) { j["fsm"] = "RLFSMStatePassive"; msg.data = j.dump(); posture->publish(msg); }
                msg.data = R"({"state":"RLFSMStateGetUp","gamepad_override":false})";
                heartbeat->publish(msg);
            } else { msg.data = j.dump(); posture->publish(msg); }
            if (commands > 0 && mode != "no_done") {
                msg.data = nlohmann::json{{"cmd","getdown"},{"code",mode == "reject" ? 4 : 2},
                    {"phase",mode == "reject" ? "REJECTED" : "DONE"},{"state",state}}.dump();
                result->publish(msg);
            }
        });
        rclcpp::executors::SingleThreadedExecutor exec;
        exec.add_node(hal); exec.add_node(fake);
        std::thread spin([&] { exec.spin(); });
        // 等待发现与真实订阅回调预热。
        std::this_thread::sleep_for(500ms);
        started = true;
        if (mode == "mismatch") std::this_thread::sleep_for(100ms);
        if (mode == "stale") std::this_thread::sleep_for(1100ms);
        if (mode == "cancel") { hal->inhibit_takeoff_motion(true); hal->cancel_takeoff_action(); }
        const bool actual = hal->safe_go_down(0.0);
        exec.cancel(); spin.join();
        const bool ok = actual == expected && commands == expected_commands;
        std::cout << (ok ? "PASS " : "FAIL ") << name << " result=" << actual
                  << " commands=" << commands << '\n';
        if (!ok) ++failures;
    };
    run("standing GetUp", "RLFSMStateGetUp", true, "normal", true, 1);
    run("GetUp settles later", "RLFSMStateGetUp", false, "becomes_ready", true, 1);
    run("GetUp still rising", "RLFSMStateGetUp", false, "normal", false, 0);
    run("stale posture", "RLFSMStateGetUp", true, "stale", false, 0);
    run("missing settled", "RLFSMStateGetUp", true, "missing", false, 0);
    run("string settled invalid", "RLFSMStateGetUp", true, "invalid", false, 0);
    run("FSM mismatch", "RLFSMStateGetUp", true, "mismatch", false, 0);
    run("gamepad override", "RLFSMStateGetUp", true, "gamepad", false, 0);
    run("cancelled takeoff", "RLFSMStateGetUp", true, "cancel", false, 0);
    run("RL locomotion", "RLFSMStateRLLocomotion", true, "normal", true, 1);
    run("already getting down", "RLFSMStateGetDown", false, "already_down", true, 0);
    run("already lying settled", "RLFSMStatePassive", true, "normal", true, 0);
    run("Passive not settled", "RLFSMStatePassive", false, "normal", false, 0);
    run("cerebellum rejects", "RLFSMStateGetUp", true, "reject", false, 1);
    run("missing DONE", "RLFSMStateGetUp", true, "no_done", false, 1);
    run("DONE without settled", "RLFSMStateGetUp", true, "no_settled", false, 1);
    run("unsupported state", "RLFSMStateSafeHold", true, "normal", false, 0);
    rclcpp::shutdown();
    std::cout << "safe_getdown: 17 cases, failures=" << failures << '\n';
    return failures ? 1 : 0;
}
