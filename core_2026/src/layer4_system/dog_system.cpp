#include "layer4_system/dog_system.hpp"
#include <chrono>

using namespace fly_to_target_args;

DogSystem::DogSystem() {
    // Layer 1: 机器狗 HAL
    hal_ = std::make_shared<RobotDogHAL>();

    // Layer 2: 飞行控制器 (地面 PID)
    PidConfig dog_pid;
    dog_pid.xy  = PidGains{0.3f, 0.05f, 0.1f, 0.3f, 0.0f};
    dog_pid.z   = PidGains{0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    dog_pid.yaw = PidGains{0.5f, 0.1f, 0.1f, 0.3f, 0.3f};

    fc_ = std::make_unique<FlightController>(
        *hal_,              // IStateProvider&
        *hal_,              // ICommandPublisher&
        hal_->get_logger(),
        hal_->get_clock(),
        20,
        dog_pid);

    // Layer 3: 机器狗任务执行器
    mission_ = std::make_unique<DogMissionExecutor>(
        *fc_, *hal_, *hal_, *hal_, *hal_, hal_->get_logger(), *hal_, 0.0f);

    // Spin 线程
    spin_thread_ = std::make_shared<std::thread>([this]() {
        while (rclcpp::ok()) {
            rclcpp::spin_some(hal_);
            std::this_thread::sleep_for(std::chrono::milliseconds(2));
        }
    });

    rclcpp::on_shutdown([this]() {
        if (spin_thread_ && spin_thread_->joinable()) spin_thread_->join();
    });

    RCLCPP_INFO(hal_->get_logger(), "[DogSystem] 初始化完成");
}

DogSystem::~DogSystem() {
    if (spin_thread_ && spin_thread_->joinable()) spin_thread_->join();
}

void DogSystem::run() {
    if (!pre_flight_checks()) {
        RCLCPP_ERROR(hal_->get_logger(),
                     "[DogSystem] 预检未通过，不执行任务（狗已按安全流程处置）");
        return;
    }
    mission_->run();
}

bool DogSystem::pre_flight_checks() {
    RCLCPP_INFO(hal_->get_logger(), "[PreFlight] 等待 LiDAR 定位...");
    while (rclcpp::ok() && !hal_->has_state()) {
        RCLCPP_WARN_THROTTLE(hal_->get_logger(), *hal_->get_clock(), 5000,
            "[PreFlight] 未收到 lidar_data 定位数据");
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    if (!rclcpp::ok()) return false;

    // ── 第 1 步：站立前检查（照小脑 ~/ws_demo.py 的做法）────────────
    // check_stand 只检测、不动电机（电机零位 + IMU）。不过就卸力中止，
    // 与 ws_demo.py「前一步失败即停」一致。
    RCLCPP_INFO(hal_->get_logger(), "[PreFlight] 请求站立前检查 check_stand...");
    if (!hal_->run_check_stand(hal_->get_check_stand_timeout_s())) {
        RCLCPP_ERROR(hal_->get_logger(),
                     "[PreFlight] check_stand 未通过 —— 不可站立，发 passive 卸力后中止");
        // 尽力卸力：这里不检查结果，狗该趴下就趴下了
        (void)hal_->transition_to("passive", "RLFSMStatePassive", "",
                                  hal_->get_transition_settle_s());
        return false;
    }

    // ── 人工闸门：起立前确认现场安全（照 ~/dog_step_test.py）──────
    if (!hal_->wait_for_enter(
            "链路 OK，check_stand 通过。确认狗周围安全后按回车发起立")) {
        RCLCPP_WARN(hal_->get_logger(),
                    "[PreFlight] 操作员放弃（或无法交互）—— 不起立，直接中止");
        return false;
    }

    // ── 第 2 步：起立 ──────────────────────────────────────────────
    // 前置：狗必须是趴着的（RLFSMStatePassive）。
    // 确认：命令终态 DONE + FSM 状态码真的变成 RLFSMStateGetUp。
    // 延迟：stand_settle_s（默认 10s，从发命令起算）—— 双重保险的第二道，
    //       给狗留够真的站稳的时间，之后才允许进 RL 模式。
    RCLCPP_INFO(hal_->get_logger(), "[PreFlight] 请求机器狗站立...");
    if (!hal_->transition_to("getup", "RLFSMStateGetUp", "RLFSMStatePassive",
                             hal_->get_stand_settle_s())) {
        RCLCPP_ERROR(hal_->get_logger(),
                     "[PreFlight] 起立未确认完成 —— 发 passive 卸力后中止");
        // 尽力卸力：这里不检查结果，狗该趴下就趴下了
        (void)hal_->transition_to("passive", "RLFSMStatePassive", "",
                                  hal_->get_transition_settle_s());
        return false;
    }

    RCLCPP_INFO(hal_->get_logger(),
                "[PreFlight] 就绪！机器狗已站立且已稳定 %.0fs",
                hal_->get_stand_settle_s());
    return true;
}
