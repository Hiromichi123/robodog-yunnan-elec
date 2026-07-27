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

    // Layer 3: 机器狗任务执行器 (TAKEOFF=getup, LAND=passive)
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
    pre_flight_checks();
    mission_->run();
}

void DogSystem::pre_flight_checks() {
    RCLCPP_INFO(hal_->get_logger(), "[PreFlight] 等待 LiDAR 定位...");
    while (rclcpp::ok() && !hal_->has_state()) {
        RCLCPP_WARN_THROTTLE(hal_->get_logger(), *hal_->get_clock(), 5000,
            "[PreFlight] 未收到 lidar_data 定位数据");
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    RCLCPP_INFO(hal_->get_logger(), "[PreFlight] 请求机器狗站立...");
    hal_->request_fsm_transition("getup");

    // 等待站立完成（给时间让 FSM 执行 GetUp 动画）
    std::this_thread::sleep_for(std::chrono::seconds(3));

    RCLCPP_INFO(hal_->get_logger(), "[PreFlight] 就绪！机器狗已站立");
}
