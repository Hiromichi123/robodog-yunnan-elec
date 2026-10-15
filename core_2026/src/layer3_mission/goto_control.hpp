#pragma once

#include <algorithm>
#include <cmath>
#include <cstdint>

#include "layer3_mission/mission_plan.hpp"
#include "layer0_common/goto_config.hpp"

namespace mission {

// 可调项统一在GotoConfig；以下门限保持固定。I=0，不积累积分。
inline constexpr double kGotoAlignThresh  = 0.78539816339744830962;  // 45°，含边界允许前进
inline constexpr double kGotoRateFilterTau   = 0.10;  // s，只滤导数，不滤命令
inline constexpr double kGotoMinSampleDt     = 0.02;
inline constexpr double kGotoMaxSampleDt     = 0.30;

enum class GotoMode { Invalid, Arrived, Drive, Align, FinalYaw };

inline const char* goto_mode_name(GotoMode mode) {
    switch (mode) {
        case GotoMode::Invalid:  return "invalid";
        case GotoMode::Arrived:  return "arrived";
        case GotoMode::Drive:    return "drive";
        case GotoMode::Align:    return "align";
        case GotoMode::FinalYaw: return "final_yaw";
    }
    return "invalid";
}

struct GotoControl {
    bool valid{false};
    bool arrived{false};
    bool derivative_valid{false};
    GotoMode mode{GotoMode::Invalid};
    double distance{0.0};
    double bearing_error{0.0};
    double yaw_error{0.0};
    double estimated_yaw_rate{0.0};
    double p_term{0.0};
    double d_term{0.0};
    double vx{0.0};
    double wz{0.0};
};

// 无ROS/HAL副作用。每个航点独立实例，时间是同一快照的单调接收时刻，
// 不是源传感器采样时刻；新鲜度/急停等安全门槛仍由执行器负责。
class GotoController {
public:
    void reset() { *this = GotoController{}; }

    GotoControl update(const MissionStep& target, double x, double y, double yaw,
                       std::uint64_t sample_id, double sample_time_s,
                       const GotoConfig& config = GotoConfig{}) {
        GotoControl out;
        const bool require_yaw = target.type == StepType::GotoPose;
        if (!valid_goto_config(config) ||
            (target.type != StepType::Goto && !require_yaw) || sample_id == 0 ||
            !std::isfinite(x) || !std::isfinite(y) || !std::isfinite(yaw) ||
            !std::isfinite(target.x) || !std::isfinite(target.y) ||
            !std::isfinite(sample_time_s) || (require_yaw && !std::isfinite(target.yaw))) {
            reset();
            return out;
        }
        const double dx = target.x - x;
        const double dy = target.y - y;
        out.distance = std::hypot(dx, dy);
        out.bearing_error = wrap(std::atan2(dy, dx) - yaw);
        if (require_yaw) out.yaw_error = wrap(target.yaw - yaw);
        if (!std::isfinite(out.distance) || !std::isfinite(out.bearing_error) ||
            !std::isfinite(out.yaw_error)) {
            reset();
            return GotoControl{};
        }
        update_rate(yaw, sample_id, sample_time_s);
        out.valid = true;
        out.derivative_valid = derivative_valid_;
        out.estimated_yaw_rate = yaw_rate_;
        out.arrived = out.distance <= config.tol_xy &&
                      (!require_yaw || std::abs(out.yaw_error) <= config.tol_yaw);
        if (out.arrived) {
            out.mode = GotoMode::Arrived;
            return out;  // 到位零速不经过滤波，不保留制动命令。
        }

        double error = out.bearing_error;
        if (out.distance <= config.tol_xy) {
            out.mode = GotoMode::FinalYaw;
            error = out.yaw_error;
        } else if (std::abs(out.bearing_error) > kGotoAlignThresh) {
            out.mode = GotoMode::Align;
        } else {
            out.mode = GotoMode::Drive;
            // 先限基础速度，再按偏角减速；45°时仍前进，不用会卡在阈值内的滞回。
            out.vx = std::min(config.max_vx, config.kp_vx * out.distance) *
                     std::cos(out.bearing_error);
        }
        out.p_term = config.kp_yaw * error;
        out.d_term = std::clamp(-config.kd_yaw * yaw_rate_,
                                -config.derivative_limit, config.derivative_limit);
        // 测量微分避免目标/阶段切换的D冲击；允许D反向制动，不强制与误差同号。
        out.wz = std::clamp(out.p_term + out.d_term, -config.max_yaw_rate, config.max_yaw_rate);
        return out;
    }

private:
    static double wrap(double angle) {
        return std::remainder(angle, 6.283185307179586476925286766559);
    }

    void update_rate(double yaw, std::uint64_t id, double time_s) {
        if (initialized_ && id == last_id_) return;  // 20Hz控制复用10Hz位姿时保持D
        const double dt = time_s - last_time_s_;
        if (initialized_ && id > last_id_ && dt >= kGotoMinSampleDt && dt <= kGotoMaxSampleDt) {
            const double rate = wrap(yaw - last_yaw_) / dt;
            if (std::isfinite(rate)) {
                const double alpha = dt / (kGotoRateFilterTau + dt);
                yaw_rate_ += alpha * (rate - yaw_rate_);
                derivative_valid_ = true;
            } else {
                yaw_rate_ = 0.0;
                derivative_valid_ = false;
            }
        } else {
            yaw_rate_ = 0.0;
            derivative_valid_ = false;
        }
        initialized_ = true;
        last_id_ = id;
        last_time_s_ = time_s;
        last_yaw_ = yaw;
    }

    bool initialized_{false};
    bool derivative_valid_{false};
    std::uint64_t last_id_{0};
    double last_time_s_{0.0};
    double last_yaw_{0.0};
    double yaw_rate_{0.0};
};

}  // namespace mission
