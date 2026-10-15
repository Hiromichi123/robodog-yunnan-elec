#pragma once

#include <array>
#include <cmath>
#include <cstdint>
#include <mutex>
#include <string>
#include <utility>
#include <vector>

namespace mission {

struct GotoConfig {
    double kp_vx{0.70};
    double kp_yaw{0.45};
    double kd_yaw{0.12};
    double max_vx{0.40};
    double max_yaw_rate{0.35};
    double derivative_limit{0.15};
    double tol_xy{0.40};
    double tol_yaw{0.50};
};

struct GotoParameterSpec {
    const char* name;
    const char* description;
    double GotoConfig::* member;
    double min;
    double max;
    double step;
};

inline constexpr std::array<GotoParameterSpec, 8> kGotoParameterSpecs{{
    {"kp_vx", "线速度P (1/s)", &GotoConfig::kp_vx, 0.10, 2.00, 0.01},
    {"kp_yaw", "角速度P (1/s)", &GotoConfig::kp_yaw, 0.10, 2.00, 0.01},
    {"kd_yaw", "角速度D", &GotoConfig::kd_yaw, 0.00, 0.50, 0.01},
    {"max_vx", "最大前进速度 (m/s)", &GotoConfig::max_vx, 0.00, 0.50, 0.01},
    {"max_yaw_rate", "最大角速度 (rad/s)", &GotoConfig::max_yaw_rate, 0.00, 1.00, 0.01},
    {"derivative_limit", "D项限幅 (rad/s)", &GotoConfig::derivative_limit, 0.00, 0.35, 0.01},
    {"tol_xy", "位置到点死区 (m)", &GotoConfig::tol_xy, 0.05, 1.00, 0.01},
    {"tol_yaw", "终点航向容差 (rad，仅goto_pose)", &GotoConfig::tol_yaw, 0.02, 1.57, 0.01},
}};

inline const GotoParameterSpec* goto_parameter_spec(const std::string& name) {
    for (const auto& spec : kGotoParameterSpecs) if (name == spec.name) return &spec;
    return nullptr;
}

inline bool valid_goto_config(const GotoConfig& config) {
    for (const auto& spec : kGotoParameterSpecs) {
        const double value = config.*(spec.member);
        if (!std::isfinite(value) || value < spec.min || value > spec.max) return false;
    }
    return true;
}

struct GotoConfigSnapshot {
    GotoConfig config{};
    std::uint64_t revision{0};
    std::uint64_t tolerance_revision{0};
};

// 服务与控制线程共享这一份权威配置；部分更新也必须在同一临界区合并。
class GotoConfigStore {
public:
    GotoConfigSnapshot snapshot() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return current_;
    }

    std::string apply(const std::vector<std::pair<std::string, double>>& patch) {
        std::lock_guard<std::mutex> lock(mutex_);
        GotoConfig next = current_.config;
        std::vector<std::string> seen;
        for (const auto& item : patch) {
            const auto* spec = goto_parameter_spec(item.first);
            if (!spec) return "未知参数：" + item.first;
            for (const auto& name : seen) if (name == item.first) return "重复参数：" + item.first;
            seen.push_back(item.first);
            if (!std::isfinite(item.second) || item.second < spec->min || item.second > spec->max)
                return "参数越界或非有限数：" + item.first;
            next.*(spec->member) = item.second;
        }
        bool changed = false;
        for (const auto& spec : kGotoParameterSpecs)
            changed |= next.*(spec.member) != current_.config.*(spec.member);
        if (changed) {
            if (next.tol_xy != current_.config.tol_xy || next.tol_yaw != current_.config.tol_yaw)
                ++current_.tolerance_revision;
            current_.config = next;
            ++current_.revision;
        }
        return {};
    }

private:
    mutable std::mutex mutex_;
    GotoConfigSnapshot current_{};
};

}  // namespace mission
