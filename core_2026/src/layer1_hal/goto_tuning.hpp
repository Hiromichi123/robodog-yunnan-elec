#pragma once

#include <rclcpp/rclcpp.hpp>
#include <rcl_interfaces/srv/get_parameters.hpp>
#include <rcl_interfaces/srv/describe_parameters.hpp>
#include <rcl_interfaces/srv/set_parameters_atomically.hpp>

#include "layer0_common/goto_config.hpp"

namespace mission {

// 独立于运动接口，可在仅有普通rclcpp::Node的隔离测试中实例化。
class GotoTuning {
public:
    explicit GotoTuning(rclcpp::Node& node);
    GotoConfigSnapshot snapshot() const { return store_.snapshot(); }

private:
    GotoConfigStore store_;
    rclcpp::Service<rcl_interfaces::srv::GetParameters>::SharedPtr get_;
    rclcpp::Service<rcl_interfaces::srv::DescribeParameters>::SharedPtr describe_;
    rclcpp::Service<rcl_interfaces::srv::SetParametersAtomically>::SharedPtr set_;
};

}  // namespace mission
