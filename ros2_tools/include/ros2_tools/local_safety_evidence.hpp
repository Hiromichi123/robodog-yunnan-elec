#pragma once

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <limits>
#include <stdexcept>
#include <vector>

namespace local_safety {

// A conservative 2.5-D evidence store, independent of ROS. A free XY cell needs
// recent floor support AND ray evidence in every robot-height band. A ceiling
// return alone must never clear a low obstacle. Unknown is deliberately common.
class EvidenceGrid {
public:
    static constexpr int kBands = 6;
    struct Config {
        double resolution{0.10};
        int width{80};
        double ground_z{-0.35};       // startup-navigation z; must be measured
        double floor_tolerance{0.035};
        double obstacle_min_height{0.06};
        double obstacle_max_height{0.72};
        double free_ttl{0.8};
        double floor_ttl{1.5};
        int clear_frames{3};
    };
    explicit EvidenceGrid(const Config& c) : c_(c) {
        if (!std::isfinite(c.resolution) || c.resolution < 0.05 || c.resolution > 0.25 ||
            c.width < 20 || c.width > 160 || !std::isfinite(c.ground_z) ||
            !std::isfinite(c.floor_tolerance) || !std::isfinite(c.obstacle_min_height) ||
            !std::isfinite(c.obstacle_max_height) || !std::isfinite(c.free_ttl) ||
            !std::isfinite(c.floor_ttl) ||
            !(c.floor_tolerance > 0 && c.floor_tolerance < c.obstacle_min_height) ||
            !(c.obstacle_min_height > 0 && c.obstacle_max_height > c.obstacle_min_height) ||
            !(c.free_ttl > 0 && c.floor_ttl > 0) || c.clear_frames < 2)
            throw std::invalid_argument("invalid local safety evidence configuration");
        cells_.resize(c.width * c.width);
        pending_.resize(cells_.size());
    }
    void clear() {
        std::fill(cells_.begin(), cells_.end(), Cell{});
        std::fill(pending_.begin(), pending_.end(), Pending{});
    }
    void recenter(double x, double y) {
        if (!std::isfinite(x) || !std::isfinite(y) || std::abs(x)>1e6 || std::abs(y)>1e6)
            throw std::invalid_argument("invalid safety grid center");
        const int nx = static_cast<int>(std::floor(x / c_.resolution)) - c_.width / 2;
        const int ny = static_cast<int>(std::floor(y / c_.resolution)) - c_.width / 2;
        if (nx == x0_ && ny == y0_) return;
        std::vector<Cell> shifted(cells_.size());
        for (int y1 = 0; y1 < c_.width; ++y1) {
            for (int x1 = 0; x1 < c_.width; ++x1) {
                const int ox = x1 + nx - x0_, oy = y1 + ny - y0_;
                if (ox >= 0 && oy >= 0 && ox < c_.width && oy < c_.width)
                    shifted[y1*c_.width+x1] = cells_[oy*c_.width+ox];
            }
        }
        x0_ = nx; y0_ = ny;
        cells_.swap(shifted);
        std::fill(pending_.begin(), pending_.end(), Pending{});
    }
    void begin_frame() { std::fill(pending_.begin(), pending_.end(), Pending{}); }

    // Finite, range-checked returns only. Invalid/no-return beams are NOT rays.
    // Endpoint exclusion (one whole cell) avoids clearing a thin obstacle at
    // its own return. Hits win over free evidence from every ray in this frame.
    void ray(const std::array<double,3>& origin, const std::array<double,3>& point,
             bool trace_free = true, double evidence_range = 10.0) {
        for (double v : origin) if (!std::isfinite(v)) return;
        for (double v : point) if (!std::isfinite(v)) return;
        const double dx=point[0]-origin[0], dy=point[1]-origin[1], dz=point[2]-origin[2];
        const double len=std::sqrt(dx*dx+dy*dy+dz*dz);
        if (!(len > c_.resolution) || len > 10.0 + 1e-9 ||
            !std::isfinite(evidence_range) || evidence_range <= 0.0 || evidence_range > 10.0) return;
        const int end = index(point[0], point[1]);
        const double h = point[2]-c_.ground_z;
        if (end >= 0 && len <= evidence_range) {
            if (std::abs(h) <= c_.floor_tolerance) pending_[end].floor = true;
            const int b=band(point[2]);
            if (b >= 0) pending_[end].hit |= (1u<<b);
        }
        if (!trace_free) return;  // retain every hit even when limiting clearing CPU work
        const int steps=static_cast<int>(std::ceil(len/(c_.resolution*0.4)));
        const double clear_until=std::min(len-c_.resolution,evidence_range);
        for (int i=1; i<steps; ++i) {
            const double a=static_cast<double>(i)/steps;
            if (a*len > clear_until) break;
            const int at=index(origin[0]+a*dx, origin[1]+a*dy);
            const int b=band(origin[2]+a*dz);
            if (at >= 0 && at != end && b >= 0) pending_[at].free |= (1u<<b);
        }
    }
    void end_frame(double observed_at) {
        if (!std::isfinite(observed_at)) return;
        for (std::size_t i=0; i<cells_.size(); ++i) {
            auto& c=cells_[i]; const auto& p=pending_[i];
            if (p.floor) c.floor=std::max(c.floor,observed_at);
            for (int b=0; b<kBands; ++b) {
                if (p.hit & (1u<<b)) {
                    if (observed_at >= c.hit[b]) {
                        c.hit[b]=observed_at; c.occupied[b]=true; c.clear_count[b]=0;
                    }
                } else if ((p.free & (1u<<b)) && observed_at > c.seen[b] &&
                           observed_at > c.hit[b]) {
                    if (observed_at-c.seen[b] > c_.free_ttl) c.clear_count[b]=0;
                    c.seen[b]=observed_at;
                    c.clear_count[b]=std::min(c_.clear_frames,c.clear_count[b]+1);
                    if (c.clear_count[b] >= c_.clear_frames) c.occupied[b]=false;
                }
            }
        }
    }
    std::vector<std::int8_t> snapshot(double now) const {
        std::vector<std::int8_t> out(cells_.size(),-1);
        for (std::size_t i=0; i<cells_.size(); ++i) {
            const auto& c=cells_[i];
            if (std::any_of(c.occupied.begin(),c.occupied.end(),[](bool x){return x;})) {
                out[i]=100; continue;  // expiry alone must never remove an obstacle
            }
            bool free=now>=c.floor && now-c.floor<=c_.floor_ttl;
            for (int b=0; b<kBands; ++b)
                free=free && c.clear_count[b]>=c_.clear_frames && now>=c.seen[b] &&
                     now-c.seen[b]<=c_.free_ttl;
            if (free) out[i]=0;
        }
        return out;
    }
    int index(double x,double y) const {
        if (!std::isfinite(x) || !std::isfinite(y)) return -1;
        const double gx=std::floor(x/c_.resolution)-x0_;
        const double gy=std::floor(y/c_.resolution)-y0_;
        if (gx<0 || gy<0 || gx>=c_.width || gy>=c_.width) return -1;
        return static_cast<int>(gy)*c_.width+static_cast<int>(gx);
    }
    double origin_x() const { return x0_*c_.resolution; }
    double origin_y() const { return y0_*c_.resolution; }
    const Config& config() const { return c_; }
private:
    int band(double z) const {
        const double h=z-c_.ground_z;
        if (h<c_.obstacle_min_height || h>c_.obstacle_max_height) return -1;
        return std::min(kBands-1,static_cast<int>((h-c_.obstacle_min_height)*kBands/
                         (c_.obstacle_max_height-c_.obstacle_min_height)));
    }
    struct Cell {
        std::array<double,kBands> seen{{-1e100,-1e100,-1e100,-1e100,-1e100,-1e100}};
        std::array<double,kBands> hit{{-1e100,-1e100,-1e100,-1e100,-1e100,-1e100}};
        std::array<int,kBands> clear_count{};
        std::array<bool,kBands> occupied{};
        double floor{-1e100};
    };
    struct Pending { unsigned free{0},hit{0}; bool floor{false}; };
    Config c_;
    int x0_{0},y0_{0};
    std::vector<Cell> cells_;
    std::vector<Pending> pending_;
};

}  // namespace local_safety
