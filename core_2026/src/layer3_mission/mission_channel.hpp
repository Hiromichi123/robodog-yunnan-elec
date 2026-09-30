#pragma once

#include <chrono>
#include <functional>
#include <mutex>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

namespace mission {

/**
 * @brief 网页 ↔ 狗 的三条话题（**只搬字符串，不解析任务语义**）。
 *
 *   /dog/mission        (web → 狗, String)  一整份任务 JSON
 *   /dog/mission_cmd    (web → 狗, String)  confirm / reject / abort
 *   /dog/mission_status (狗 → web, String)  进度 JSON，**变化时 + 2Hz 心跳**
 *
 * 为什么单独一个节点、而不是挂在 RobotDogHAL 上：HAL 是"硬件抽象"，任务语义
 * （是否在等确认、第几步）不该塞进去；而且 HAL 已经 600 多行。
 *
 * ⚠️ 2Hz 心跳必须由**定时器**发，不能由主线程的执行循环发：主线程在跑一步时
 * 会阻塞好几秒（等命令终态、等稳定延迟），那期间操作员最需要看到"还在跑"。
 *
 * 状态**以节点发的为准**：刷新页面/断线重连后，网页靠这 2Hz 自动对齐，
 * 不用自己记（和雷达建图开关那套是同一个设计）。
 */
class DogMissionChannel : public rclcpp::Node {
public:
    /** 一帧状态。字段就是网页上要显示的东西。 */
    struct Status {
        std::string phase{"idle"};   // idle/running/waiting_confirm/done/aborted/failed/rejected
        std::string name;            // 任务名
        std::string type;            // 当前步骤类型（空 = 没在跑）
        std::string msg;             // 人话：报错原因 / 结果
        std::string prompt;          // waiting_confirm 时给操作员看的那句话
        int    index{-1};            // 当前步骤（从 1 起；-1 = 无）
        int    total{0};
        // 当前步骤的起始时刻：elapsed_s 由发布那一刻算，省得主线程一边跑一边刷时间
        std::chrono::steady_clock::time_point step_started_at{};
    };

    DogMissionChannel();

    // ── 主线程用 ────────────────────────────────────────────────────
    /** 取走最新一帧任务文档（JSON 文本）。取走后清空，重复调用返回 false。 */
    [[nodiscard]] bool take_doc(std::string& out);
    /** 取走最新一条指令（confirm/reject/abort）。取走后清空。 */
    [[nodiscard]] bool take_cmd(std::string& out);
    /** 写状态（主线程）。下一拍定时器会带出去。 */
    void set_status(const Status& s);
    /** 立刻发一帧 —— 状态变化时用，别让操作员等最多 0.5s。 */
    void publish_status_now();
    /**
     * 是否接受新的任务文档。执行期间置 false：
     * 否则任务跑到一半又收到一份，会在上一份结束后**自动开始**（意外动作）。
     * 期间收到的会被丢掉并打一条 WARN —— 宁可让操作员重发，也不要攒着。
     */
    void set_doc_accepting(bool on);

    /**
     * 急停钩子：收到 abort 时**在 spin 线程里**直接调用，不等主线程。
     * 主线程可能正阻塞在某条命令的等待上（最长 8s），等它就是几秒的延迟，
     * 而那几秒里狗还在动。
     */
    void set_abort_hook(std::function<void()> hook);

private:
    void on_doc(const std_msgs::msg::String::SharedPtr msg);
    void on_cmd(const std_msgs::msg::String::SharedPtr msg);

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr      status_pub_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr   doc_sub_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr   cmd_sub_;
    rclcpp::TimerBase::SharedPtr                             heartbeat_;

    mutable std::mutex    mutex_;
    std::string           pending_doc_;
    bool                  has_doc_{false};
    std::string           pending_cmd_;
    bool                  has_cmd_{false};
    bool                  doc_accepting_{true};
    Status                status_;
    std::function<void()> abort_hook_;
};

}  // namespace mission
