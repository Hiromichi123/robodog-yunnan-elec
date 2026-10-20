#include "layer3_mission/goto_control.hpp"

#include <cstdio>
#include <limits>

int main() {
    using namespace mission;
    int total = 0, failed = 0;
    const auto check = [&](bool ok, const char* label) {
        ++total;
        if (!ok) ++failed;
        std::printf("%s %s\n", ok ? "PASS" : "FAIL", label);
    };
    const auto near = [](double a, double b) { return std::abs(a - b) < 1e-9; };
    const auto fresh = [](const MissionStep& p, double x, double y, double yaw) {
        GotoController controller;
        return controller.update(p, x, y, yaw, 1, 0.0);
    };
    constexpr double pi = 3.14159265358979323846;
    const double nan = std::numeric_limits<double>::quiet_NaN();
    MissionStep point;
    point.type = StepType::Goto;
    point.x = 0.4;
    point.yaw = nan;
    auto c = fresh(point, 0, 0, pi);
    check(c.valid && c.arrived && c.vx == 0 && c.wz == 0, "ordinary boundary ignores unused target yaw");
    point.x = 0;
    check(fresh(point, 0, 0, pi).arrived, "coincident ordinary point finishes without turning");
    point.x = 0.400001;
    c = fresh(point, 0, 0, 0);
    check(!c.arrived && c.vx > 0 && c.wz == 0, "outside position boundary moves");
    for (auto type : {StepType::Goto, StepType::GotoPose}) {
        point.type = type;
        point.yaw = 0;
        for (double distance : {0.41, 2.0}) {
            point.x = distance;
            for (double sign : {-1.0, 1.0}) {
                for (double angle : {44.9 * pi / 180.0, pi / 4.0}) {
                    c = fresh(point, 0, 0, -sign * angle);
                    check(c.valid && c.mode == GotoMode::Drive && c.vx > 0 &&
                          near(c.vx, std::min(0.40, 0.70 * distance) * std::cos(angle)),
                          "both waypoint types: <=45deg moves with cosine slowdown");
                }
                c = fresh(point, 0, 0, -sign * (pi / 4.0 + 1e-6));
                check(c.mode == GotoMode::Align && c.vx == 0 && c.wz * sign > 0,
                      "just outside either 45deg boundary turns only");
            }
        }
    }
    point.x = 2;
    c = fresh(point, 0, 0, 0);
    check(c.vx == 0.40 && c.wz == 0 && c.d_term == 0, "aligned first frame has no D kick");
    point.x = 0.4; point.yaw = 0.5;
    check(fresh(point, 0, 0, 0).arrived, "pose point position/yaw boundaries inclusive");
    point.yaw = 0.500001;
    c = fresh(point, 0, 0, 0);
    check(!c.arrived && c.mode == GotoMode::FinalYaw && c.vx == 0 && c.wz > 0,
          "pose point at position calibrates yaw even within 45deg");
    point.yaw = pi;
    check(fresh(point, 0, 0, 0).wz == 0.35, "yaw speed limited to 0.35rad/s");
    point.yaw = -pi + 0.1;
    c = fresh(point, 0, 0, pi - 0.1);
    check(c.arrived && near(c.yaw_error, 0.2), "target yaw wraps across pi");

    point.type = StepType::Goto; point.x = 2; point.yaw = nan;
    GotoController ctl;
    ctl.update(point, 0, 0, -0.4, 1, 0.0);
    c = ctl.update(point, 0, 0, -0.3, 2, 0.1);
    check(c.derivative_valid && near(c.estimated_yaw_rate, 0.5) && near(c.d_term, -0.06),
          "new 10Hz pose updates filtered measurement derivative");
    const auto held = ctl.update(point, 0, 0, -0.3, 2, 0.1);
    check(near(held.wz, c.wz) && near(held.estimated_yaw_rate, c.estimated_yaw_rate),
          "20Hz repeated pose holds D without advancing filter");
    c = ctl.update(point, 0, 0, -0.2, 3, 0.2);
    check(near(c.estimated_yaw_rate, 0.75), "next sample uses actual pose interval");
    ctl.reset();
    c = ctl.update(point, 0, 0, -0.2, 4, 0.3);
    check(!c.derivative_valid && c.d_term == 0, "explicit reset clears derivative history");
    for (double sign : {-1.0, 1.0}) {
        GotoController toward, away;
        toward.update(point, 0, 0, -sign * 0.4, 1, 0.0);
        away.update(point, 0, 0, -sign * 0.2, 1, 0.0);
        const auto t = toward.update(point, 0, 0, -sign * 0.3, 2, 0.1);
        const auto a = away.update(point, 0, 0, -sign * 0.3, 2, 0.1);
        check(t.wz * sign < t.p_term * sign && a.wz * sign > a.p_term * sign,
              "signed symmetry: approaching damps, departing increases correction");
    }
    ctl.reset();
    ctl.update(point, 0, 0, -0.11, 1, 0.0);
    c = ctl.update(point, 0, 0, -0.01, 2, 0.1);
    check(c.bearing_error > 0 && c.wz < 0 && c.vx > 0, "D can brake opposite small error while moving");
    ctl.reset();
    ctl.update(point, 0, 0, pi - 0.01, 1, 0.0);
    c = ctl.update(point, 0, 0, -pi + 0.01, 2, 0.1);
    check(near(c.estimated_yaw_rate, 0.1), "measurement derivative wraps across pi");
    ctl.reset();
    ctl.update(point, 0, 0, -2.0, 1, 0.0);
    c = ctl.update(point, 0, 0, -0.1, 2, 0.1);
    check(near(c.d_term, -0.15) && std::abs(c.wz) <= 0.35, "derivative and final output independently bounded");
    c = ctl.update(point, 2, 0, 0.1, 3, 0.2);
    check(c.arrived && c.wz == 0 && c.vx == 0, "arrival bypasses nonzero derivative immediately");

    for (double dt : {-0.1, 0.0, 0.01, 0.31, 2.0}) {
        ctl.reset();
        ctl.update(point, 0, 0, -0.3, 1, 1.0);
        ctl.update(point, 0, 0, -0.2, 2, 1.1);
        c = ctl.update(point, 0, 0, -0.1, 3, 1.1 + dt);
        check(c.valid && !c.derivative_valid && c.d_term == 0 && near(c.wz, c.p_term),
              "bad dt rebaselines and falls back to P-only");
        c = ctl.update(point, 0, 0, 0, 4, 1.2 + dt);
        check(c.derivative_valid && std::isfinite(c.wz), "valid sample after bad dt restores bounded D");
    }
    ctl.reset();
    ctl.update(point, 0, 0, -0.3, 10, 0.0);
    c = ctl.update(point, 0, 0, -0.2, 9, 0.1);
    check(c.valid && !c.derivative_valid, "sample id reversal discards D history");
    for (int i = 1; i <= 100; ++i) c = ctl.update(point, 0, 0, -2, 10 + i, i * 0.1);
    c = ctl.update(point, 0, 0, 2, 111, 10.1);
    check(c.wz < 0, "saturated control reverses without integral windup or output lag");
    ctl.reset();
    c = ctl.update(point, 0, 0, 0, 1, 0);
    check(c.wz == 0, "next waypoint starts with no residual command");

    ctl.update(point, 0, 0, -0.4, 2, 0.1);
    c = ctl.update(point, nan, 0, 0, 3, 0.2);
    check(!c.valid && c.vx == 0 && c.wz == 0, "NaN pose stops immediately");
    c = ctl.update(point, 0, 0, -0.3, 4, 0.3);
    check(c.valid && !c.derivative_valid, "invalid pose resets history");
    check(!fresh(point, 0, 0, nan).valid, "NaN navigation yaw rejected");
    check(!ctl.update(point, 0, 0, 0, 0, 0).valid, "uninitialized sample rejected");
    check(!ctl.update(point, 0, 0, 0, 1, nan).valid, "invalid sample time rejected");
    point.type = StepType::GotoPose;
    check(!fresh(point, 0, 0, 0).valid, "pose waypoint requires finite target yaw");
    point.type = StepType::Goto; point.x = std::numeric_limits<double>::infinity();
    check(!fresh(point, 0, 0, 0).valid, "invalid target position rejected");

    point.type = StepType::GotoPose; point.x = 1; point.yaw = 1;
    ctl.reset();
    ctl.update(point, 0, 0, -0.2, 1, 0.0);
    c = ctl.update(point, 0.7, 0, -0.1, 2, 0.1);
    check(c.mode == GotoMode::FinalYaw && near(c.d_term, -0.06),
          "final-yaw mode retains measurement D, no setpoint derivative kick");
    GotoConfig cfg;
    point.type = StepType::Goto; point.x = 2;
    ctl.reset();
    ctl.update(point, 0, 0, -0.4, 1, 0);
    const auto old = ctl.update(point, 0, 0, -0.3, 2, 0.1);
    cfg.max_vx = 0.1; cfg.max_yaw_rate = 0.03;
    c = ctl.update(point, 0, 0, -0.3, 2, 0.1, cfg);
    check(c.vx <= 0.1 && std::abs(c.wz) <= 0.03 && near(c.estimated_yaw_rate, old.estimated_yaw_rate),
          "hot limits apply on repeated sample without resetting derivative");
    cfg.max_vx = 0; cfg.max_yaw_rate = 0;
    c = ctl.update(point, 0, 0, -0.3, 2, 0.1, cfg);
    check(c.valid && c.vx == 0 && c.wz == 0, "zero limits stop respective outputs immediately");
    cfg = GotoConfig{}; cfg.kd_yaw = 0;
    c = ctl.update(point, 0, 0, -0.3, 2, 0.1, cfg);
    check(c.d_term == 0 && near(c.wz, c.p_term), "hot kd=0 removes D without clearing measured history");
    cfg.kp_yaw = 0.2; cfg.kp_vx = 0.1;
    c = ctl.update(point, 0, 0, -0.3, 2, 0.1, cfg);
    check(near(c.p_term, 0.06) && near(c.vx, 0.2 * std::cos(0.3)), "hot P gains affect current step");
    cfg = GotoConfig{}; cfg.derivative_limit = 0.01;
    c = ctl.update(point, 0, 0, -0.3, 2, 0.1, cfg);
    check(near(c.d_term, -0.01), "hot D clamp applies immediately");
    point.x = 0.6;
    cfg.tol_xy = 0.7;
    c = ctl.update(point, 0, 0, -0.3, 2, 0.1, cfg);
    check(c.arrived && c.vx == 0 && c.wz == 0, "expanded position tolerance immediately zeros command");
    point.type = StepType::GotoPose; point.yaw = 0.4;
    cfg.tol_yaw = 0.8;
    check(ctl.update(point, 0, 0, -0.3, 2, 0.1, cfg).arrived, "hot final yaw tolerance used by pose point");
    cfg.tol_yaw = 0.2;
    check(!ctl.update(point, 0, 0, -0.3, 2, 0.1, cfg).arrived, "smaller final yaw tolerance keeps unfinished point active");
    cfg.max_vx = nan;
    c = ctl.update(point, 0, 0, -0.3, 2, 0.1, cfg);
    check(!c.valid && c.vx == 0 && c.wz == 0, "invalid config fails closed");
    std::printf("%d checks, %d failed\n", total, failed);
    return failed ? 1 : 0;
}
