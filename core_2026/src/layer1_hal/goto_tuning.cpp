#include "layer1_hal/goto_tuning.hpp"

#include <stdexcept>
#include <rcl_interfaces/msg/parameter_type.hpp>

namespace mission {

GotoTuning::GotoTuning(rclcpp::Node& node) {
    if (!valid_goto_config(store_.snapshot().config)) throw std::logic_error("invalid default goto config");
    get_ = node.create_service<rcl_interfaces::srv::GetParameters>(
        "/dog/goto/get_parameters",
        [this](const rcl_interfaces::srv::GetParameters::Request::SharedPtr request,
               rcl_interfaces::srv::GetParameters::Response::SharedPtr response) {
            const auto config = store_.snapshot().config;
            for (const auto& name : request->names) {
                rcl_interfaces::msg::ParameterValue value;
                if (const auto* spec = goto_parameter_spec(name)) {
                    value.type = rcl_interfaces::msg::ParameterType::PARAMETER_DOUBLE;
                    value.double_value = config.*(spec->member);
                }
                response->values.push_back(value);  // 未知名称返回NOT_SET，保持请求顺序
            }
        });
    describe_ = node.create_service<rcl_interfaces::srv::DescribeParameters>(
        "/dog/goto/describe_parameters",
        [](const rcl_interfaces::srv::DescribeParameters::Request::SharedPtr request,
           rcl_interfaces::srv::DescribeParameters::Response::SharedPtr response) {
            for (const auto& name : request->names) {
                rcl_interfaces::msg::ParameterDescriptor descriptor;
                descriptor.name = name;
                if (const auto* spec = goto_parameter_spec(name)) {
                    descriptor.type = rcl_interfaces::msg::ParameterType::PARAMETER_DOUBLE;
                    descriptor.description = spec->description;
                    descriptor.additional_constraints = "仅当前进程有效；运行中立即影响goto/goto_pose；step是网页建议步长";
                    rcl_interfaces::msg::FloatingPointRange range;
                    range.from_value = spec->min;
                    range.to_value = spec->max;
                    range.step = spec->step;
                    descriptor.floating_point_range.push_back(range);
                }
                response->descriptors.push_back(descriptor);
            }
        });
    set_ = node.create_service<rcl_interfaces::srv::SetParametersAtomically>(
        "/dog/goto/set_parameters_atomically",
        [this, logger = node.get_logger()](
            const rcl_interfaces::srv::SetParametersAtomically::Request::SharedPtr request,
            rcl_interfaces::srv::SetParametersAtomically::Response::SharedPtr response) {
            std::vector<std::pair<std::string, double>> patch;
            for (const auto& param : request->parameters) {
                if (param.value.type != rcl_interfaces::msg::ParameterType::PARAMETER_DOUBLE) {
                    response->result.successful = false;
                    response->result.reason = "参数必须为DOUBLE：" + param.name;
                    return;
                }
                patch.emplace_back(param.name, param.value.double_value);
            }
            const auto before = store_.snapshot().revision;
            response->result.reason = store_.apply(patch);
            response->result.successful = response->result.reason.empty();
            const auto after = store_.snapshot();
            if (response->result.successful && after.revision != before) {
                const auto& c = after.config;
                RCLCPP_INFO(logger, "[goto调参] rev=%llu kp_vx=%.3f kp_yaw=%.3f kd=%.3f "
                            "max_vx=%.3f max_wz=%.3f D_limit=%.3f tol_xy=%.3f tol_yaw=%.3f",
                            static_cast<unsigned long long>(after.revision),
                            c.kp_vx, c.kp_yaw, c.kd_yaw, c.max_vx, c.max_yaw_rate,
                            c.derivative_limit, c.tol_xy, c.tol_yaw);
            }
        });
}

}  // namespace mission
