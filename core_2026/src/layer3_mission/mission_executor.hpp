#pragma once

#include <rclcpp/rclcpp.hpp>

#include "layer2_control/flight_controller.hpp"
#include "layer1_hal/i_state_provider.hpp"
#include "layer1_hal/i_vision_provider.hpp"
#include "layer1_hal/i_dvs_avoid_provider.hpp"
#include "layer1_hal/i_command_publisher.hpp"
#include "layer0_common/target.hpp"
#include "layer0_common/velocity.hpp"

/**
 * @brief 任务执行层
 *
 * - 通过接口获取状态和视觉数据，不依赖任何具体硬件类。
 */
class MissionExecutor {
public:
    MissionExecutor(FlightController&  fc,     // 飞行控制器
                    IStateProvider&    state,  // 状态接口
                    IVisionProvider&   vision, // 视觉提供接口
                    IDvsAvoidProvider& dvs,    // DVS规避接口
                    ICommandPublisher& cmd,    // 指令发布接口（悬停直发setpoint）
                    rclcpp::Logger     logger, // DroneHAL日志记录器
                    float              default_altitude = 1.2f);

    void run(); // 开始执行任务

protected:
    // ===== 状态机组 =====
    enum class State {
        TAKEOFF,
        HOVER,
        LAND,
        DONE,
        // 任务失败。派生类负责在置这个状态之前把狗置于安全姿态
        // （狗执行器是 getdown 回趴下），run() 见到它就退出。
        FAULT
    };

    // ===== 状态方法组（虚函数，子类可覆写） =====
    virtual void on_takeoff();
    virtual void on_hover();
    virtual void on_land();

    // ===== 成员组 =====
    FlightController& fc_;
    IStateProvider&   state_;
    IVisionProvider&  vision_;
    IDvsAvoidProvider& dvs_;
    ICommandPublisher& cmd_;
    rclcpp::Logger    logger_;

    float default_altitude_;
    State current_state_{State::TAKEOFF};

    rclcpp::Clock steady_clock_{RCL_STEADY_TIME};
    rclcpp::Time  hover_start_time_{0, 0, RCL_STEADY_TIME};
    float         hover_anchor_x_{0.0f};
    float         hover_anchor_y_{0.0f};
    float         hover_anchor_yaw_{0.0f};

    Target hover_target_;
    Target takeoff_target_;

    static constexpr float  kHoverAltitude      = 1.20f;
    static constexpr float  kHoverDurationSec   = 25.0f;
    static constexpr float  kLandVz           = -0.20f;
    static constexpr float  kLandDuration     = 5.0f;

private:
};
