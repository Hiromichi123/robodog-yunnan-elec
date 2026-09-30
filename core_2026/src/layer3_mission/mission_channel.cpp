#include "layer3_mission/mission_channel.hpp"

#include <algorithm>
#include <cctype>

#include <nlohmann/json.hpp>

namespace mission {

namespace {
/** 指令串收一下：去空白 + 转小写。网页那边可能带换行。 */
std::string normalize(const std::string& s) {
    std::string out;
    out.reserve(s.size());
    for (char c : s) {
        if (std::isspace(static_cast<unsigned char>(c))) continue;
        out += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }
    return out;
}
}  // namespace

DogMissionChannel::DogMissionChannel() : Node("dog_mission_node") {
    const std::string doc_topic    = this->declare_parameter<std::string>(
        "mission_topic", "/dog/mission");
    const std::string cmd_topic    = this->declare_parameter<std::string>(
        "mission_cmd_topic", "/dog/mission_cmd");
    const std::string status_topic = this->declare_parameter<std::string>(
        "mission_status_topic", "/dog/mission_status");

    status_pub_ = this->create_publisher<std_msgs::msg::String>(status_topic, 10);
    doc_sub_    = this->create_subscription<std_msgs::msg::String>(
        doc_topic, 10,
        [this](std_msgs::msg::String::SharedPtr m) { this->on_doc(m); });
    cmd_sub_    = this->create_subscription<std_msgs::msg::String>(
        cmd_topic, 10,
        [this](std_msgs::msg::String::SharedPtr m) { this->on_cmd(m); });

    heartbeat_ = this->create_wall_timer(std::chrono::milliseconds(500),
                                         [this]() { this->publish_status_now(); });

    RCLCPP_INFO(this->get_logger(),
                "[任务通道] 就绪 | 任务=%s 指令=%s 状态=%s（2Hz 心跳）",
                doc_topic.c_str(), cmd_topic.c_str(), status_topic.c_str());
}

void DogMissionChannel::set_abort_hook(std::function<void()> hook) {
    std::lock_guard<std::mutex> lock(mutex_);
    abort_hook_ = std::move(hook);
}

void DogMissionChannel::set_doc_accepting(bool on) {
    std::lock_guard<std::mutex> lock(mutex_);
    doc_accepting_ = on;
}

void DogMissionChannel::on_doc(const std_msgs::msg::String::SharedPtr msg) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!doc_accepting_) {
        RCLCPP_WARN(this->get_logger(),
                    "[任务通道] 正在执行任务，这份新任务被丢弃（%zu 字节）—— 请等它跑完再下发",
                    msg->data.size());
        return;
    }
    pending_doc_ = msg->data;
    has_doc_     = true;
    RCLCPP_INFO(this->get_logger(), "[任务通道] 收到任务（%zu 字节），等主线程取走",
                msg->data.size());
}

void DogMissionChannel::on_cmd(const std_msgs::msg::String::SharedPtr msg) {
    const std::string cmd = normalize(msg->data);
    if (cmd.empty()) return;

    std::function<void()> hook;
    {
        std::lock_guard<std::mutex> lock(mutex_);
        pending_cmd_ = cmd;
        has_cmd_     = true;
        if (cmd == "abort") hook = abort_hook_;
    }

    RCLCPP_INFO(this->get_logger(), "[任务通道] 收到指令：%s", cmd.c_str());

    // 急停**在 spin 线程里就动手**：主线程可能正阻塞着等某条命令的终态，
    // 等它轮询到为止（最长 8s）黄花菜都凉了。钩子里只做两件不阻塞的事：
    // 置中止位 + 伪造终态打断等待。
    if (cmd == "abort" && hook) hook();
}

bool DogMissionChannel::take_doc(std::string& out) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!has_doc_) return false;
    out = pending_doc_;
    pending_doc_.clear();
    has_doc_ = false;
    return true;
}

bool DogMissionChannel::take_cmd(std::string& out) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!has_cmd_) return false;
    out = pending_cmd_;
    pending_cmd_.clear();
    has_cmd_ = false;
    return true;
}

void DogMissionChannel::set_status(const Status& s) {
    std::lock_guard<std::mutex> lock(mutex_);
    status_ = s;
}

void DogMissionChannel::publish_status_now() {
    Status s;
    {
        std::lock_guard<std::mutex> lock(mutex_);
        s = status_;
    }

    // elapsed 在这里算，而不是让主线程每 50ms 刷一次 —— 主线程忙着跑步骤，
    // 心跳是 spin 线程发的，时间由发的人算最省事。
    double elapsed = 0.0;
    if (s.step_started_at.time_since_epoch().count() != 0) {
        elapsed = std::chrono::duration<double>(
                      std::chrono::steady_clock::now() - s.step_started_at).count();
        if (elapsed < 0.0) elapsed = 0.0;
    }

    nlohmann::json j{
        {"phase", s.phase},
        {"name", s.name},
        {"type", s.type},
        {"msg", s.msg},
        {"prompt", s.prompt},
        {"index", s.index},
        {"total", s.total},
        {"elapsed_s", elapsed},
    };

    auto msg = std_msgs::msg::String();
    msg.data = j.dump();
    status_pub_->publish(msg);
}

}  // namespace mission
