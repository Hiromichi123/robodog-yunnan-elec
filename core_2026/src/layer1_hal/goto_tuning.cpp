#include "layer1_hal/goto_tuning.hpp"

#include <stdexcept>
#include <rcl_interfaces/msg/parameter_type.hpp>

namespace mission {

GotoTuning::GotoTuning(rclcpp::Node& node, std::string path) : path_(std::move(path)) {
    if (!valid_goto_config(store_.snapshot().config)) throw std::logic_error("invalid default goto config");
    try {
        GotoSavedConfig loaded;
        if (load_goto_saved(path_, loaded)) {
            std::vector<std::pair<std::string, double>> patch;
            for (const auto& spec : kGotoParameterSpecs)
                patch.emplace_back(spec.name, loaded.config.*(spec.member));
            const auto error = store_.apply(patch);
            if (!error.empty()) throw std::runtime_error(error);
            saved_ = loaded;
            RCLCPP_INFO(node.get_logger(), "[goto调参] 已加载保存参数：%s", path_.c_str());
        }
    } catch (const std::exception& error) {
        load_error_ = error.what();
        RCLCPP_ERROR(node.get_logger(), "[goto调参] 加载失败，使用内置默认值：%s", error.what());
    }
    using Trigger = std_srvs::srv::Trigger;
    persistence_ = node.create_service<Trigger>("/dog/goto/get_persistence_state",
        [this](Trigger::Request::SharedPtr, Trigger::Response::SharedPtr response) {
            response->success = true;
            response->message = persistence_state();
        });
    // Deferred response: disk I/O never blocks the HAL/mission single-thread executor.
    save_ = node.create_service<Trigger>("/dog/goto/save_parameters",
        [this, logger = node.get_logger()](rclcpp::Service<Trigger>::SharedPtr service,
                std::shared_ptr<rmw_request_id_t> header, Trigger::Request::SharedPtr) {
            if (saving_.exchange(true)) {
                Trigger::Response response;
                response.success = false;
                response.message = "已有保存操作进行中";
                service->send_response(*header, response);
                return;
            }
            if (save_worker_.joinable()) save_worker_.join();
            const auto config = store_.snapshot().config;
            try {
                save_worker_ = std::thread([this, config, service, header, logger]() {
                    Trigger::Response response;
                    try {
                        const auto saved = save_goto_config(path_, config);
                        {
                            std::lock_guard<std::mutex> lock(persistence_mutex_);
                            saved_ = saved;
                            save_error_.clear();
                        }
                        response.success = true;
                        response.message = persistence_state();
                    } catch (const std::exception& error) {
                        std::lock_guard<std::mutex> lock(persistence_mutex_);
                        save_error_ = error.what();
                        response.success = false;
                        response.message = save_error_;
                    }
                    try { service->send_response(*header, response); }
                    catch (const std::exception& error) {
                        RCLCPP_WARN(logger, "[goto调参] 保存响应未送达：%s", error.what());
                    }
                    saving_ = false;
                });
            } catch (const std::exception& error) {
                saving_ = false;
                Trigger::Response response;
                response.success = false;
                response.message = error.what();
                service->send_response(*header, response);
            }
        });
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
                    descriptor.additional_constraints = "热改即时生效，显式保存后重启加载；step是网页建议步长";
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

GotoTuning::~GotoTuning() {
    if (save_worker_.joinable()) save_worker_.join();
}

std::string GotoTuning::persistence_state() const {
    std::lock_guard<std::mutex> lock(persistence_mutex_);
    return nlohmann::json{{"schema_version", 1}, {"saving", saving_.load()},
        {"saved", saved_ ? nlohmann::json{{"parameters", goto_config_json(saved_->config)},
                                         {"saved_at", saved_->saved_at}} : nlohmann::json(nullptr)},
        {"load_error", load_error_}, {"save_error", save_error_}}.dump();
}

}  // namespace mission
