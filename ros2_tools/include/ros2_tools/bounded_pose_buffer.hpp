#pragma once

#include <cmath>
#include <deque>
#include <iterator>
#include <algorithm>
#include <tf2/LinearMath/Transform.h>

namespace local_safety {
struct TimedPose { double stamp; tf2::Transform value; };

// Exact samples or interpolation between close samples only. Unlike the map
// recorder's display interpolation, safety never extrapolates an endpoint or
// bridges an arbitrarily long sensor outage.
inline bool interpolate_pose(const std::deque<TimedPose>& poses,double stamp,
                             double max_gap,tf2::Transform& out) {
    if (poses.empty() || !std::isfinite(stamp) || !std::isfinite(max_gap) || max_gap<=0) return false;
    auto hi=std::lower_bound(poses.begin(),poses.end(),stamp,
                           [](const TimedPose& p,double s){return p.stamp<s;});
    if (hi!=poses.end() && std::abs(hi->stamp-stamp)<1e-6) {out=hi->value;return true;}
    if (hi==poses.begin() || hi==poses.end()) return false;
    const auto lo=std::prev(hi);
    const double gap=hi->stamp-lo->stamp;
    if (gap<=0 || gap>max_gap) return false;
    const double a=(stamp-lo->stamp)/gap;
    out.setOrigin(lo->value.getOrigin().lerp(hi->value.getOrigin(),a));
    out.setRotation(lo->value.getRotation().slerp(hi->value.getRotation(),a));
    return true;
}
}  // namespace local_safety
