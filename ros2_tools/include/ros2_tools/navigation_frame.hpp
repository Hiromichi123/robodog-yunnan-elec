#pragma once
#include <array>
#include <cmath>

inline std::array<double, 3> world_to_navigation(
    double x, double y, double z, double x0, double y0, double z0, double yaw0) {
    const double c = std::cos(yaw0), s = std::sin(yaw0);
    return {c*(x-x0)+s*(y-y0), -s*(x-x0)+c*(y-y0), z-z0};
}
