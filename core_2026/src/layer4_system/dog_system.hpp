#pragma once

#include <memory>
#include <thread>
#include <rclcpp/rclcpp.hpp>

#include "layer1_hal/robot_dog_hal.hpp"
#include "layer2_control/flight_controller.hpp"
#include "layer3_mission/dog_mission_executor.hpp"
#include "layer3_mission/dog_plan_executor.hpp"
#include "layer3_mission/mission_channel.hpp"

/**
 * @brief 机器狗系统编排层
 *
 * 参考 DroneSystem，适配四足机器人:
 * - pre_flight: 站起 (getup FSM)，本版会**等到命令真的完成**才返回
 * - 使用 FlightController (地面 PID 参数)
 * - MissionExecutor (不变！通过接口适配)
 *
 * ── 两种运行方式（由 HAL 的 `wait_for_mission` 参数选）──────────────────
 *   false（默认）：**旧行为一字不改**。预检 → 固定流程（起立/进RL/前进N秒/趴下），
 *                 每一步由终端回车闸门把关。
 *   true（网页驱动）：只等 LiDAR 定位到货，然后循环「等 /dog/mission 上的任务 →
 *                 解析校验 → 逐步执行 → 回报」。预检（自检/起立）变成任务里的
 *                 **步骤**，由操作员在网页上显式拼进去 —— 网页上看到的就是狗真正
 *                 会做的全部动作，没有"看不见的自动步骤"。
 *
 * 网页模式下终端闸门没有意义（launch 拉起时 stdin 不是终端，wait_for_enter 会按
 * 安全策略直接中止），要配 `-p confirm_transitions:=false`；"确认"改由任务 JSON 的
 * confirm 字段驱动，走网页的「继续/放弃」按钮 —— 是**换了道闸门，不是拆了闸门**。
 */
class DogSystem {
public:
    DogSystem();
    ~DogSystem();

    void run();

private:
    /** @return true = 预检通过（狗已确认站立）；false = 失败，调用方不应执行任务 */
    [[nodiscard]] bool pre_flight_checks();

    /** 等 /lidar_data 上的定位到货。两种模式都要（预检与闭环都依赖它）。 */
    [[nodiscard]] bool wait_for_lidar();

    /** 网页驱动模式的主循环：等任务 → 解析校验 → 执行 → 回报。 */
    void run_mission_loop();

    std::shared_ptr<RobotDogHAL>        hal_;
    std::unique_ptr<FlightController>   fc_;
    std::unique_ptr<MissionExecutor>    mission_;   // 旧路径：固定流程
    std::shared_ptr<mission::DogMissionChannel> channel_;     // 网页三条话题
    std::unique_ptr<mission::DogPlanExecutor>   plan_exec_;   // 新路径：按 JSON 跑
    std::shared_ptr<std::thread>        spin_thread_;
};
