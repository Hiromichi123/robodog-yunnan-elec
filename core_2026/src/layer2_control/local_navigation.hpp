#pragma once

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <limits>
#include <string>
#include <vector>

namespace local_nav {

struct Pose { double x{0.0}, y{0.0}, yaw{0.0}; };

struct Grid {
    double resolution{0.1}, origin_x{0.0}, origin_y{0.0};
    int width{0}, height{0};
    std::vector<std::int8_t> cells;
    bool valid{false};
};

// Initial engineering values, NOT measured stopping/footprint calibration.
struct Config {
    double footprint_front{0.5}, footprint_rear{0.4}, half_width{0.32}, margin{0.15};
    double reaction_s{0.35}, decel{0.3}, angular_decel{0.5};
    double max_vx{0.15}, max_wz{0.35};
    double max_lateral_shift{1.5}, max_longitudinal_loss{0.2};
    double rollout_s{1.0};
    // Legacy geometry callers opt in explicitly; production LocalSafety enables this.
    bool soft_buffer_enabled{false};
    double hard_margin{0.05};
    double buffer_max_vx{0.30}, buffer_max_wz{0.45};
    bool seed_current_footprint_unknown{false};
};

struct Command {
    bool safe{false};
    double vx{0.0}, wz{0.0};
    std::string reason;
};

struct GoalResult { bool found{false}; Pose goal; };

inline bool valid_pose(const Pose& p) {
    return std::isfinite(p.x) && std::isfinite(p.y) && std::isfinite(p.yaw);
}

inline bool valid_config(const Config& c) {
    for (double v : {c.footprint_front, c.footprint_rear, c.half_width, c.margin,
                     c.reaction_s, c.decel, c.angular_decel, c.max_vx, c.max_wz,
                     c.max_lateral_shift, c.max_longitudinal_loss, c.rollout_s,
                     c.hard_margin, c.buffer_max_vx, c.buffer_max_wz})
        if (!std::isfinite(v) || v < 0.0) return false;
    return c.footprint_front > 0.0 && c.footprint_front <= 3.0 &&
           c.footprint_rear > 0.0 && c.footprint_rear <= 3.0 &&
           c.half_width > 0.0 && c.half_width <= 2.0 && c.margin <= 1.0 &&
           c.reaction_s > 0.0 && c.reaction_s <= 3.0 &&
           c.decel >= 0.01 && c.decel <= 5.0 &&
           c.angular_decel >= 0.01 && c.angular_decel <= 10.0 &&
           c.max_vx > 0.0 && c.max_vx <= 0.5 && c.max_wz > 0.0 && c.max_wz <= 1.0 &&
           c.max_lateral_shift <= 3.0 && c.max_longitudinal_loss <= 1.0 &&
           c.rollout_s >= 0.1 && c.rollout_s <= 3.0 && c.hard_margin <= .20 &&
           c.buffer_max_vx > 0 && c.buffer_max_vx <= .5 && c.buffer_max_wz > 0 && c.buffer_max_wz <= 1.;
}

inline bool valid_grid(const Grid& g) {
    return g.valid && std::isfinite(g.resolution) && g.resolution >= 0.02 &&
           g.resolution <= 0.5 && std::isfinite(g.origin_x) && std::isfinite(g.origin_y) &&
           std::abs(g.origin_x) < 1e6 && std::abs(g.origin_y) < 1e6 &&
           g.width > 0 && g.height > 0 && g.width <= 1000 && g.height <= 1000 &&
           g.cells.size() == static_cast<std::size_t>(g.width) * g.height;
}

// The configured margin becomes a preferred total clearance, not another
// expansion added on top of hard_margin. Never shrink a smaller user margin.
inline double hard_margin(const Config& c) {
    return c.soft_buffer_enabled ? std::min(c.margin,c.hard_margin) : c.margin;
}

namespace detail {

inline double wrap(double a) { return std::remainder(a, 6.2831853071795864769); }

// SAT for an oriented footprint rectangle and an axis-aligned grid cell.
inline bool intersects(double x, double y, double cell_half, const Pose& p,
                       double front, double rear, double side) {
    const double c = std::cos(p.yaw), s = std::sin(p.yaw);
    const double half = (front + rear) * 0.5;
    const double center = (front - rear) * 0.5;
    const double dx = x - (p.x + c * center), dy = y - (p.y + s * center);
    const double ac = std::abs(c), as = std::abs(s), e = 1e-10;
    return std::abs(dx) <= half * ac + side * as + cell_half + e &&
           std::abs(dy) <= half * as + side * ac + cell_half + e &&
           std::abs(c * dx + s * dy) <= half + cell_half * (ac + as) + e &&
           std::abs(-s * dx + c * dy) <= side + cell_half * (ac + as) + e;
}

inline bool contained_in_seed(double x, double y, double h, const Pose& seed,
                              const Config& c) {
    const double co = std::cos(seed.yaw), si = std::sin(seed.yaw);
    for (double dx : {-h, h}) for (double dy : {-h, h}) {
        const double px = x + dx - seed.x, py = y + dy - seed.y;
        const double a = co * px + si * py, b = -si * px + co * py;
        if (a < -c.footprint_rear || a > c.footprint_front || std::abs(b) > c.half_width)
            return false;
    }
    return true;
}

inline bool footprint(const Grid& g, const Pose& p, const Config& cfg,
                      double extra, const Pose* seed, bool occupied_only) {
    const double front = cfg.footprint_front + hard_margin(cfg) + extra;
    const double rear = cfg.footprint_rear + hard_margin(cfg) + extra;
    const double side = cfg.half_width + hard_margin(cfg) + extra;
    const double c = std::cos(p.yaw), s = std::sin(p.yaw);
    const double center = (front - rear) * 0.5;
    const double cx = p.x + c * center, cy = p.y + s * center;
    const double ex = (front + rear) * 0.5 * std::abs(c) + side * std::abs(s);
    const double ey = (front + rear) * 0.5 * std::abs(s) + side * std::abs(c);
    const double left = g.origin_x, bottom = g.origin_y;
    const double right = left + g.width * g.resolution, top = bottom + g.height * g.resolution;
    if (!occupied_only && (cx - ex <= left || cx + ex >= right ||
                           cy - ey <= bottom || cy + ey >= top)) return false;
    // Clip doubles before integer conversion; arbitrarily distant goals cannot overflow int.
    if (cx + ex < left || cx - ex > right || cy + ey < bottom || cy - ey > top)
        return false;
    const auto ix = [&](double v) { return static_cast<int>(std::clamp(
        std::floor((v - left) / g.resolution), 0.0, static_cast<double>(g.width - 1))); };
    const auto iy = [&](double v) { return static_cast<int>(std::clamp(
        std::floor((v - bottom) / g.resolution), 0.0, static_cast<double>(g.height - 1))); };
    const int x0 = ix(cx - ex - 1e-10), x1 = ix(cx + ex + 1e-10);
    const int y0 = iy(cy - ey - 1e-10), y1 = iy(cy + ey + 1e-10);
    for (int y = y0; y <= y1; ++y) for (int x = x0; x <= x1; ++x) {
        const double px = left + (x + 0.5) * g.resolution;
        const double py = bottom + (y + 0.5) * g.resolution;
        if (!intersects(px, py, g.resolution * 0.5, p, front, rear, side)) continue;
        const auto value = g.cells[static_cast<std::size_t>(y) * g.width + x];
        if (occupied_only) {
            if (value > 0) return true;
        } else if (value != 0) {
            if (value == -1 && seed && contained_in_seed(px, py, g.resolution * 0.5, *seed, cfg))
                continue;
            return false;
        }
    }
    return !occupied_only;
}

inline Pose integrate(Pose p, double vx, double wz, double dt) {
    const double a = p.yaw, b = a + wz * dt;
    if (std::abs(wz) < 1e-9) {
        p.x += vx * dt * std::cos(a); p.y += vx * dt * std::sin(a);
    } else {
        p.x += vx / wz * (std::sin(b) - std::sin(a));
        p.y += vx / wz * (std::cos(a) - std::cos(b));
    }
    p.yaw = wrap(b);
    return p;
}

inline double radius(const Config& c) {
    return std::hypot(std::max(c.footprint_front, c.footprint_rear) + hard_margin(c),
                      c.half_width + hard_margin(c));
}

inline double clearance(const Grid& g, const Pose& p, const Config& c) {
    double free_margin = 0.0;
    for (double extra = 0.025; extra <= 0.45001; extra += 0.025) {
        if (!footprint(g, p, c, extra, nullptr, false)) break;
        free_margin = extra;
    }
    return free_margin;
}

// Circumscribed disk is deliberately stricter than an aligned rectangle. It certifies
// every intermediate heading of a local straight route, including its end rotations.
inline bool disk_safe(const Grid& g, double px, double py, double r) {
    if (px - r <= g.origin_x || py - r <= g.origin_y ||
        px + r >= g.origin_x + g.width * g.resolution ||
        py + r >= g.origin_y + g.height * g.resolution) return false;
    const int x0 = static_cast<int>(std::floor((px - r - g.origin_x) / g.resolution));
    const int x1 = static_cast<int>(std::floor((px + r - g.origin_x) / g.resolution));
    const int y0 = static_cast<int>(std::floor((py - r - g.origin_y) / g.resolution));
    const int y1 = static_cast<int>(std::floor((py + r - g.origin_y) / g.resolution));
    for (int y = y0; y <= y1; ++y) for (int x = x0; x <= x1; ++x) {
        const double cx = g.origin_x + (x + 0.5) * g.resolution;
        const double cy = g.origin_y + (y + 0.5) * g.resolution;
        const double dx = std::max(0.0, std::abs(px - cx) - g.resolution * 0.5);
        const double dy = std::max(0.0, std::abs(py - cy) - g.resolution * 0.5);
        if (dx * dx + dy * dy <= r * r + 1e-12 &&
            g.cells[static_cast<std::size_t>(y) * g.width + x] != 0) return false;
    }
    return true;
}

inline bool direct_route(const Grid& g, const Pose& from, const Pose& to, const Config& c) {
    const double d = std::hypot(to.x - from.x, to.y - from.y);
    const double step = g.resolution * 0.25;
    if (!std::isfinite(d) || d > 100.0) return false;
    const int count = std::max(1, static_cast<int>(std::ceil(d / step)));
    // Half-step padding covers the unsampled interval along the line.
    const double r = radius(c) + d / (2.0 * count);
    for (int i = 0; i <= count; ++i) {
        const double f = static_cast<double>(i) / count;
        if (!disk_safe(g, from.x + f * (to.x - from.x),
                       from.y + f * (to.y - from.y), r)) return false;
    }
    return true;
}

}  // namespace detail

inline bool footprint_safe(const Grid& g, const Pose& p, const Config& c) {
    return valid_grid(g) && valid_pose(p) && valid_config(c) &&
           detail::footprint(g, p, c, 0.0, nullptr, false);
}

inline bool goal_occupied(const Grid& g, const Pose& p, const Config& c) {
    return valid_grid(g) && valid_pose(p) && valid_config(c) &&
           detail::footprint(g, p, c, 0.0, nullptr, true);
}

// A known obstacle may enter the preferred buffer at crawl speed. Unknown
// handling remains in the hard footprint/map gates, never certifies reverse.
inline bool preferred_clear(const Grid& g,const Pose& p,const Config& c,double pad=0.) {
    return !detail::footprint(g,p,c,std::max(0.,c.margin-hard_margin(c))+pad,nullptr,true);
}
inline bool buffer_speed_safe(const Grid& g,const Pose& p,double vx,double wz,
                              const Config& c,double pad) {
    return !c.soft_buffer_enabled ||
           (std::abs(vx)<=c.buffer_max_vx+1e-6 && std::abs(wz)<=c.buffer_max_wz+1e-6) ||
           preferred_clear(g,p,c,pad);
}

inline bool swept_safe(const Grid& g, const Pose& p, double vx, double wz, const Config& c) {
    if (!valid_grid(g) || !valid_pose(p) || !valid_config(c) ||
        !std::isfinite(vx) || !std::isfinite(wz) || vx < 0.0 ||
        vx > c.max_vx + 1e-6 || std::abs(wz) > c.max_wz + 1e-6) return false;
    const Pose* seed = c.seed_current_footprint_unknown ? &p : nullptr;
    const double speed_bound = vx + detail::radius(c) * std::abs(wz);
    const double dt = std::min(0.05, g.resolution * 0.2 / std::max(0.01, speed_bound));
    // Each sample covers the next whole step, not just its center. This prevents
    // a thin cell/corner from falling between swept-footprint samples.
    const double pad = speed_bound * dt;
    if (!detail::footprint(g, p, c, pad, seed, false) ||
        !buffer_speed_safe(g,p,vx,wz,c,pad)) return false;
    Pose q = p;
    const double hold_s = c.rollout_s + c.reaction_s;
    const double brake_s = std::max(vx / c.decel, std::abs(wz) / c.angular_decel);
    const double end = hold_s + brake_s;
    for (double t = 0.0; t < end; ) {
        const double h = std::min(dt, end - t);
        const double braking = std::max(0.0, t - hold_s);
        const double v = std::max(0.0, vx - c.decel * braking);
        const double w = std::copysign(std::max(0.0, std::abs(wz) - c.angular_decel * braking), wz);
        q = detail::integrate(q, v, w, h);
        if (!detail::footprint(g, q, c, pad, seed, false) ||
            !buffer_speed_safe(g,q,vx,wz,c,pad)) return false;
        t += h;
    }
    return true;
}

// All intermediate footprints are checked; the padding bounds travel between samples.
inline bool primitive_clear(const Grid& g,const Pose& p,double v,double w,double duration,const Config& c) {
    if(!valid_grid(g)||!valid_pose(p)||!valid_config(c)||!std::isfinite(duration)||duration<=0) return false;
    const double bound=std::abs(v)+detail::radius(c)*std::abs(w);
    const int steps=std::max(1,static_cast<int>(std::ceil(bound*duration/(g.resolution*.2))));
    if(steps>1000) return false;
    const double pad=bound*duration/steps;
    for(int i=0;i<=steps;++i) {
        const Pose q=detail::integrate(p,v,w,duration*i/steps);
        if(!detail::footprint(g,q,c,pad,nullptr,false)) return false;
    }
    return true;
}

// Destination placement uses the whole preferred buffer, while transit may
// consume it under the ordinary hard-footprint and braking gates.
inline Config goal_clearance_config(const Config& c) {
    Config goal=c;goal.soft_buffer_enabled=false;return goal;
}
inline bool goal_needs_adjustment(const Grid& g,const Pose& p,const Config& c) {
    return goal_occupied(g,p,goal_clearance_config(c));
}
inline bool goal_in_free_space(const Grid& g,const Pose& p,const Config& c) {
    return footprint_safe(g,p,goal_clearance_config(c));
}
inline bool oriented_direct_route(const Grid& g,const Pose& from,const Pose& to,const Config& c) {
    const double distance=std::hypot(to.x-from.x,to.y-from.y);
    if(!std::isfinite(distance)||distance>100.)return false;
    const double heading=distance>1e-9?std::atan2(to.y-from.y,to.x-from.x):from.yaw;
    const double turn=std::min(.30,c.max_wz),speed=std::min(.20,c.max_vx);
    const double first=detail::wrap(heading-from.yaw),last=detail::wrap(to.yaw-heading);
    if(std::abs(first)>1e-9&&!primitive_clear(g,from,0,std::copysign(turn,first),std::abs(first)/turn,c))return false;
    Pose aligned=from;aligned.yaw=heading;
    if(distance>1e-9&&!primitive_clear(g,aligned,speed,0,distance/speed,c))return false;
    Pose end=to;end.yaw=heading;
    return std::abs(last)<=1e-9||primitive_clear(g,end,0,std::copysign(turn,last),std::abs(last)/turn,c);
}

inline Command select_command(const Grid& g, const Pose& p, const Pose& target,
                              double nominal_vx, double nominal_wz, const Config& c) {
    Command best;
    best.reason = "no safe forward/turn trajectory";
    if (!valid_grid(g) || !valid_pose(p) || !valid_pose(target) || !valid_config(c) ||
        !std::isfinite(nominal_vx) || !std::isfinite(nominal_wz) || nominal_vx < 0.0) {
        best.reason = "invalid local navigation input";
        return best;
    }
    const double v0 = std::min(nominal_vx, c.max_vx);
    const double w0 = std::clamp(nominal_wz, -c.max_wz, c.max_wz);
    if (v0 <= 1e-9) {
        // Align/final-yaw modes may slow or stop, but never translate or reverse yaw.
        for (double scale : {1.0, 0.5, 0.25}) {
            if (swept_safe(g, p, 0.0, w0 * scale, c))
                return {true, 0.0, w0 * scale, "safe rotation"};
        }
        return best;
    }
    const double distance = std::hypot(target.x - p.x, target.y - p.y);
    if (!std::isfinite(distance)) return best;
    double best_score = -std::numeric_limits<double>::infinity();
    const double bearing = std::atan2(target.y - p.y, target.x - p.x);
    // Absolute crawl candidates matter when only a short certified corridor is
    // available: a fraction of a high requested speed may still be too fast.
    for (double v : {v0, v0 * 0.66, v0 * 0.33, std::min(v0,c.buffer_max_vx), std::min(v0, 0.05), std::min(v0, 0.03)}) {
        for (double w : {w0, 0.0, -c.max_wz, -c.max_wz * 0.5, c.max_wz * 0.5, c.max_wz}) {
            if (!swept_safe(g, p, v, w, c)) continue;
            const Pose q = detail::integrate(p, v, w, c.rollout_s);
            const double progress = distance - std::hypot(target.x - q.x, target.y - q.y);
            if (progress <= 1e-5) continue;
            const double error = std::abs(detail::wrap(bearing - q.yaw));
            // Clearance acts before the collision boundary. Merely rejecting collisions
            // drives toward an unseen wall goal until too little turning room remains.
            const double clearance = detail::clearance(g, q, c);
            const double score = progress * 4.0 + clearance * 1.2 - error * 0.10 -
                                 std::abs(w - w0) * 0.03;
            if (score > best_score) {
                best_score = score;
                best = {true, v, w, v < v0 ? "safe reduced speed" : "safe local trajectory"};
            }
        }
    }
    // Do not return arbitrary endless spins when every forward candidate is blocked.
    // The executor can choose a new lookahead/goal or stop with an explicit reason.
    return best;
}

inline GoalResult find_adjusted_goal(const Grid& g, const Pose& robot,
                                    const Pose& original, const Pose& start, const Config& c) {
    GoalResult result;
    if (!valid_grid(g) || !valid_pose(robot) || !valid_pose(original) || !valid_pose(start) ||
        !valid_config(c) || !goal_needs_adjustment(g, original, c)) return result;
    const double dx = original.x - start.x, dy = original.y - start.y;
    const double length = std::hypot(dx, dy);
    if (!std::isfinite(length) || length < g.resolution || length > 100.0) return result;
    const double ux = dx / length, uy = dy / length;
    const double quantum = g.resolution * 0.5;
    const int lateral_count = static_cast<int>(std::ceil(c.max_lateral_shift / quantum));
    const int loss_count = static_cast<int>(std::ceil(c.max_longitudinal_loss / quantum));
    // In soft-buffer mode first retreat along the incoming segment into a
    // completely free destination envelope, before trying a large lateral jump.
    if(c.soft_buffer_enabled)for(int loss_i=0;loss_i<=loss_count;++loss_i) {
        const double loss=std::min(c.max_longitudinal_loss,loss_i*quantum);
        if(loss>=length-g.resolution)continue;
        const Pose q{original.x-ux*loss,original.y-uy*loss,original.yaw};
        if(goal_in_free_space(g,q,c) &&
           (detail::direct_route(g,robot,q,c)||oriented_direct_route(g,robot,q,c)))return {true,q};
    }
    // Lexicographic ordering: longitudinal preservation, lateral correction, route length.
    // A certified direct route is stricter than flood-fill connectivity and rules out
    // free islands and diagonal corner cutting without introducing a global planner.
    for (int loss_i = 0; loss_i <= loss_count; ++loss_i) {
        const double loss = std::min(c.max_longitudinal_loss, loss_i * quantum);
        if (loss >= length - g.resolution) continue;
        for (int shift_i = 0; shift_i <= lateral_count; ++shift_i) {
            const double shift = std::min(c.max_lateral_shift, shift_i * quantum);
            double best_distance = std::numeric_limits<double>::infinity();
            for (double sign : {-1.0, 1.0}) {
                Pose q{original.x - ux * loss - uy * shift * sign,
                       original.y - uy * loss + ux * shift * sign, original.yaw};
                if (!goal_in_free_space(g,q,c)) continue;
                if (!detail::direct_route(g,robot,q,c) &&
                    !(c.soft_buffer_enabled&&oriented_direct_route(g,robot,q,c))) continue;
                const double distance = std::hypot(q.x - robot.x, q.y - robot.y);
                if (distance < best_distance) {
                    best_distance = distance;
                    result = {true, q};
                }
            }
            if (result.found) return result;
        }
    }
    return result;
}

}  // namespace local_nav
