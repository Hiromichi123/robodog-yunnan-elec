#pragma once

#include <rclcpp/rclcpp.hpp>
#include <rcl_interfaces/srv/get_parameters.hpp>
#include <rcl_interfaces/srv/describe_parameters.hpp>
#include <rcl_interfaces/srv/set_parameters_atomically.hpp>
#include <std_srvs/srv/trigger.hpp>
#include <atomic>
#include <optional>
#include <thread>

#include "layer1_hal/goto_persistence.hpp"

namespace mission {

// 独立于运动接口；测试必须注入临时文件路径，不能访问生产配置。
class GotoTuning {
public:
    explicit GotoTuning(rclcpp::Node& node, std::string path = goto_default_config_path());
    ~GotoTuning();
    GotoConfigSnapshot snapshot() const { return store_.snapshot(); }

private:
    std::string persistence_state() const;
    GotoConfigStore store_;
    std::string path_;
    mutable std::mutex persistence_mutex_;
    std::optional<GotoSavedConfig> saved_;
    std::string load_error_;
    std::string save_error_;
    std::atomic<bool> saving_{false};
    std::thread save_worker_;
    rclcpp::Service<rcl_interfaces::srv::GetParameters>::SharedPtr get_;
    rclcpp::Service<rcl_interfaces::srv::DescribeParameters>::SharedPtr describe_;
    rclcpp::Service<rcl_interfaces::srv::SetParametersAtomically>::SharedPtr set_;
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr save_;
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr persistence_;
};

}  // namespace mission
