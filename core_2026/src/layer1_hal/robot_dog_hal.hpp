#pragma once

#include <mutex>
#include <memory>
#include <string>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <geometry_msgs/msg/twist_stamped.hpp>
#include <std_msgs/msg/string.hpp>
#include <ros2_tools/msg/lidar_pose.hpp>

#include "layer1_hal/i_state_provider.hpp"
#include "layer1_hal/i_command_publisher.hpp"
#include "layer1_hal/i_vision_provider.hpp"
#include "layer1_hal/i_dvs_avoid_provider.hpp"

/**
 * @brief 机器狗硬件抽象层
 *
 * 关键映射（话题名由参数给出，默认对齐底层桥的契约）:
 *   publish_velocity(Velocity) → Twist on /rl_real/cmd_vel
 *   publish_position(Target)   → 内部 P 控制器转速度
 *   get_state()                → DroneState from /lidar_data
 *   FSM 控制                    → /rl_real/command
 *   命令生命周期                 → /rl_real/cmd_state（桥转发）
 *
 * ── 命令生命周期（本版新增的核心）──────────────────────────────────
 * 原来发完命令就 sleep 固定秒数、假定狗做到了。本版改为：
 *     request_fsm_transition("getup")   → 发命令，并记下"正在等 getup"
 *     wait_for_command_done(6.0)        → 等桥转发的 cmd_state 到达终态
 *
 * cmd_state 的字段（JSON 字符串）:
 *     {"seq":1,"cmd":"getup","code":2,"phase":"DONE",
 *      "target":"RLFSMStateGetUp","state":"RLFSMStateGetUp","elapsed_ms":3120}
 * 终态码: 2=DONE 3=FAILED 4=REJECTED，其余（0 RECEIVED / 1 EXECUTING）为非终态。
 *
 * 注意：seq 由桥分配，上层不知道；但任务流程是严格串行的（一次只等一条命令），
 * 所以这里按**命令名**匹配即可。
 */
class RobotDogHAL
    : public rclcpp::Node
    , public IStateProvider
    , public ICommandPublisher
    , public IVisionProvider
    , public IDvsAvoidProvider
{
public:
    explicit RobotDogHAL();

    // IStateProvider
    [[nodiscard]] DroneState get_state() const override;
    [[nodiscard]] bool       has_state() const override;

    // ICommandPublisher
    void publish_position(Target& target) override;
    void publish_velocity(Velocity& velocity) override;

    // IVisionProvider (空实现)
    [[nodiscard]] messages::msg::Vision get_vision() const override;
    [[nodiscard]] bool                   has_vision() const override;

    // IDvsAvoidProvider (空实现)
    [[nodiscard]] geometry_msgs::msg::Twist get_dvs_avoid_cmd() const override;
    [[nodiscard]] bool has_recent_dvs_avoid(double max_age_sec) const override;
    [[nodiscard]] int64_t get_last_dvs_detect_time_ns() const override;

    // === 机器狗特有接口 ===
    /** 发一条 FSM 命令，并把"正在等它"记下来（清掉上一次的终态）。 */
    void request_fsm_transition(const std::string& fsm_state);

    /**
     * 等上一条命令到达终态。
     * @return true = DONE(2)；false = FAILED/REJECTED/超时
     */
    [[nodiscard]] bool wait_for_command_done(double timeout_sec);

    /**
     * 等上一条命令的终态状态码（wait_for_command_done 的底层）。
     * @return 2=DONE / 3=FAILED / 4=REJECTED；-1 = 超时没收到终态
     * @param verbose 超时时是否打 WARN —— 重试轮里传 false 免得刷屏
     */
    [[nodiscard]] int wait_for_command_code(double timeout_sec, bool verbose = true);

    void set_navigation_mode(bool enable);
    [[nodiscard]] std::string get_current_fsm_state() const;
    [[nodiscard]] bool wait_for_fsm_state(const std::string& target, double timeout_sec);

    // === 状态切换把关（本版新增）===
    /**
     * 站立前检查：照小脑 ~/ws_demo.py 的做法，把 check_stand 当**普通命令**
     * 走 cmd_state 生命周期（RECEIVED → EXECUTING → DONE/FAILED）。
     *   DONE(2)        = 可以站立
     *   FAILED(3)/超时 = 不可站立
     * 细节（motors_ready / imu_ready / reason）来自 /rl_real/check_stand_result，
     * 只用于打日志；判定一律以 cmd_state 的状态码为准。
     */
    [[nodiscard]] bool run_check_stand(double timeout_sec);

    /**
     * 一次带把关的状态切换，四道依次过：
     *   1. 前置判断：等当前 FSM 状态变成 require_state（空串=跳过）
     *   2. 发命令，等 cmd_state 终态（只认 DONE(2)）
     *   3. 状态码确认：等 FSM 状态真的变成 expect_state（空串=跳过）
     *   4. 稳定延迟：从发命令起算补足 settle_s
     * 等终态的超时按命令名取（见 timeout_for_cmd）。
     * @return true 仅当四道全过
     */
    bool transition_to(const std::string& cmd,
                       const std::string& expect_state,
                       const std::string& require_state,
                       double settle_s);

    /**
     * 人工闸门：等操作员按回车才继续（照 ~/dog_step_test.py 的 gate()）。
     *   回车     = 继续
     *   q / quit = 放弃
     *   EOF / Ctrl-C = 放弃
     *
     * 只在 stdin 是终端时可用。非终端（launch 拉起 / stdin 重定向）一律按
     * **安全策略中止** —— 不让「没有终端」悄悄退化成「无人确认就动」。
     * 要非交互运行必须显式传 -p confirm_transitions:=false。
     *
     * @return true = 继续，false = 放弃（调用方负责安全处置）
     */
    [[nodiscard]] bool wait_for_enter(const std::string& prompt);

    // ---- 任务参数（给 mission 层用，做成参数便于现场调）----
    [[nodiscard]] double get_stand_timeout_s() const      { return stand_timeout_s_; }
    [[nodiscard]] double get_locomotion_timeout_s() const { return locomotion_timeout_s_; }
    [[nodiscard]] double get_passive_timeout_s() const    { return passive_timeout_s_; }
    /** 前进时长；<= 0 表示跳过前进（用于"只起立进RL再趴下"的验证） */
    [[nodiscard]] double get_forward_duration_s() const   { return forward_duration_s_; }
    [[nodiscard]] double get_forward_vx() const           { return forward_vx_; }

    // ---- 状态切换把关参数 ----
    [[nodiscard]] double get_check_stand_timeout_s() const { return check_stand_timeout_s_; }
    /** 起立后的稳定等待（从发 getup 起算），默认 10s —— 双重保险的第二道 */
    [[nodiscard]] double get_stand_settle_s() const        { return stand_settle_s_; }
    /** 其他状态切换的默认稳定延迟，默认 1s */
    [[nodiscard]] double get_transition_settle_s() const   { return transition_settle_s_; }

private:
    void lidar_cb(const ros2_tools::msg::LidarPose::SharedPtr msg);
    void dog_state_cb(const std_msgs::msg::String::SharedPtr msg);
    void cmd_state_cb(const std_msgs::msg::String::SharedPtr msg);
    void check_stand_result_cb(const std_msgs::msg::String::SharedPtr msg);

    /** 按命令名取等终态的超时；未知命令给 stand_timeout_s_ 兜底。 */
    [[nodiscard]] double timeout_for_cmd(const std::string& cmd) const;

    // 发布器
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr  cmd_vel_pub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr       fsm_command_pub_;

    // 订阅器
    rclcpp::Subscription<ros2_tools::msg::LidarPose>::SharedPtr lidar_sub_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr      dog_state_sub_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr      cmd_state_sub_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr      check_stand_result_sub_;

    // 状态
    mutable std::mutex state_mutex_;
    DroneState         state_{};
    bool               has_state_{false};
    std::string        current_fsm_state_{"Unknown"};

    // 命令生命周期（回调和等待分别在 spin 线程与主线程，必须加锁）
    mutable std::mutex cmd_mutex_;
    std::string        pending_cmd_;          // 正在等的命令名；空 = 没在等
    int                pending_code_{-1};     // 终态码；-1 = 还没收到
    std::string        pending_phase_;        // 文字形式，写日志用
    std::string        pending_state_;        // 终态时狗实际的 FSM 状态

    // 任务参数
    double stand_timeout_s_{8.0};
    double locomotion_timeout_s_{8.0};
    double passive_timeout_s_{8.0};
    double forward_duration_s_{3.5};
    double forward_vx_{0.1};

    // check_stand 细节（来自 check_stand_result 帧），只用于日志
    mutable std::mutex check_stand_mutex_;
    std::string        check_stand_detail_;

    // 人工闸门：每次切换前是否等回车（照 ~/dog_step_test.py）
    bool   confirm_transitions_{true};

    // 状态切换把关参数
    double check_stand_timeout_s_{5.0};
    double stand_settle_s_{10.0};
    double transition_settle_s_{1.0};
    double precondition_timeout_s_{5.0};
    double fsm_confirm_timeout_s_{2.0};

    // 空 vision / dvs 返回
    messages::msg::Vision empty_vision_{};
    geometry_msgs::msg::Twist empty_dvs_cmd_{};
};
