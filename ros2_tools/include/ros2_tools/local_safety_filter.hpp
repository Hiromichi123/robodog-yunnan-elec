#pragma once
#include <cmath>

namespace local_safety {
inline bool sensor_return_in_range(double x, double y, double z, double minimum, double maximum) {
    if (!std::isfinite(x) || !std::isfinite(y) || !std::isfinite(z)) return false;
    const double range = std::hypot(x, y, z);
    return range >= minimum && range <= maximum;
}
inline bool inside_self_box(double x, double y, double z, double half_length, double half_width,
                            double min_z, double max_z) {
    return std::isfinite(x) && std::isfinite(y) && std::isfinite(z) &&
        std::abs(x) <= half_length && std::abs(y) <= half_width && z >= min_z && z <= max_z;
}
}
