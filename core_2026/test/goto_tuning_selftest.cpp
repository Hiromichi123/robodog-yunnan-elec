#include "layer1_hal/goto_tuning.hpp"

#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <future>
#include <stdexcept>
#include <string>
#include <rcl_interfaces/msg/parameter_type.hpp>

using namespace std::chrono_literals;

template<class Service>
auto call(rclcpp::Node::SharedPtr node, rclcpp::executors::SingleThreadedExecutor& exec,
          const char* name, typename Service::Request::SharedPtr request) {
    auto client = node->create_client<Service>(name);
    if (!client->wait_for_service(3s)) throw std::runtime_error(std::string("service unavailable: ") + name);
    auto future = client->async_send_request(request);
    if (exec.spin_until_future_complete(future, 3s) != rclcpp::FutureReturnCode::SUCCESS)
        throw std::runtime_error("service call timed out");
    return future.get();
}

int main(int argc, char** argv) {
    // 专用测试域+localhost是硬门禁，避免误把测试写请求发到真狗。
    const char* domain = std::getenv("ROS_DOMAIN_ID");
    const char* local = std::getenv("ROS_LOCALHOST_ONLY");
    if (!domain || std::string(domain) != "197" || !local || std::string(local) != "1") {
        std::fprintf(stderr, "Requires ROS_DOMAIN_ID=197 ROS_LOCALHOST_ONLY=1\n");
        return 2;
    }
    rclcpp::init(argc, argv);
    int total = 0, failed = 0;
    auto check = [&](bool ok, const char* label) {
        ++total; if (!ok) ++failed;
        std::printf("%s %s\n", ok ? "PASS" : "FAIL", label);
    };
    try {
        auto node = std::make_shared<rclcpp::Node>("goto_config_test_only");
        mission::GotoTuning tuning(*node);  // 没有HAL/控制器/运动话题
        rclcpp::executors::SingleThreadedExecutor exec;
        exec.add_node(node);
        if (argc > 1 && std::string(argv[1]) == "--serve") {
            exec.spin();  // 供隔离rosbridge协议测试；此测试进程退出即丢弃配置
        } else {
            using Get = rcl_interfaces::srv::GetParameters;
            using Describe = rcl_interfaces::srv::DescribeParameters;
            using Set = rcl_interfaces::srv::SetParametersAtomically;
            auto desc = std::make_shared<Describe::Request>();
            auto get = std::make_shared<Get::Request>();
            for (const auto& spec : mission::kGotoParameterSpecs) {
                desc->names.push_back(spec.name); get->names.push_back(spec.name);
            }
            auto descriptions = call<Describe>(node, exec, "/dog/goto/describe_parameters", desc);
            check(descriptions->descriptors.size() == 8, "describe returns all 8 fields");
            for (std::size_t i = 0; i < descriptions->descriptors.size(); ++i) {
                const auto& d = descriptions->descriptors[i];
                const auto& spec = mission::kGotoParameterSpecs[i];
                check(d.name == spec.name && d.type == 3 && d.floating_point_range.size() == 1 &&
                      d.floating_point_range[0].from_value == spec.min &&
                      d.floating_point_range[0].to_value == spec.max, "wire descriptor matches canonical range");
            }
            auto values = call<Get>(node, exec, "/dog/goto/get_parameters", get);
            check(values->values.size() == 8 && values->values[0].type == 3 &&
                  values->values[0].double_value == 0.7, "get returns current doubles in requested order");
            auto set = std::make_shared<Set::Request>();
            rcl_interfaces::msg::Parameter p;
            p.name = "max_vx"; p.value.type = 3; p.value.double_value = 0.2;
            set->parameters.push_back(p);
            check(call<Set>(node, exec, "/dog/goto/set_parameters_atomically", set)->result.successful,
                  "valid live update succeeds");
            check(tuning.snapshot().config.max_vx == 0.2, "service and controller snapshot share state");
            p.name = "tol_xy"; p.value.double_value = 0.6; set->parameters.push_back(p);
            check(call<Set>(node, exec, "/dog/goto/set_parameters_atomically", set)->result.successful &&
                  tuning.snapshot().tolerance_revision == 1, "tolerance revision updated atomically");
            const auto rev = tuning.snapshot().revision;
            set->parameters[0].value.double_value = 0.3;
            set->parameters[1].value.type = 2; set->parameters[1].value.integer_value = 1;
            auto result = call<Set>(node, exec, "/dog/goto/set_parameters_atomically", set)->result;
            check(!result.successful && !result.reason.empty() && tuning.snapshot().revision == rev &&
                  tuning.snapshot().config.max_vx == 0.2, "wrong type rejects entire batch");
            set->parameters[1].value.type = 3; set->parameters[1].value.double_value = 99;
            check(!call<Set>(node, exec, "/dog/goto/set_parameters_atomically", set)->result.successful &&
                  tuning.snapshot().revision == rev, "out-of-range batch leaves all unchanged");
            set->parameters[1] = set->parameters[0];
            check(!call<Set>(node, exec, "/dog/goto/set_parameters_atomically", set)->result.successful,
                  "duplicate wire parameters rejected");
            set->parameters[1].name = "bad_key";
            check(!call<Set>(node, exec, "/dog/goto/set_parameters_atomically", set)->result.successful,
                  "unknown wire parameters rejected");
            get->names = {"bad_key", "max_vx"};
            values = call<Get>(node, exec, "/dog/goto/get_parameters", get);
            check(values->values[0].type == 0 && values->values[1].double_value == 0.2,
                  "unknown get returns NOT_SET without reordering");
            check(node->get_publishers_info_by_topic("/rl_real/cmd_vel").empty(), "test publishes no robot velocity");
        }
    } catch (const std::exception& e) {
        std::fprintf(stderr, "FAIL %s\n", e.what()); ++failed;
    }
    rclcpp::shutdown();
    std::printf("%d checks, %d failed\n", total, failed);
    return failed ? 1 : 0;
}
