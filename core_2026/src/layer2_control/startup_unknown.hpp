#pragma once
#include "layer2_control/local_navigation.hpp"
namespace local_nav {
// Explicit exploration policy: only unknown cells wholly inside the current
// near-field disk become traversable in a private control snapshot.
inline std::size_t apply_unknown_exploration(Grid& g,double range) {
    if (!valid_grid(g) || !std::isfinite(range) || range<.5 || range>5.) return 0;
    std::size_t changed=0;
    for(int y=0;y<g.height;++y) for(int x=0;x<g.width;++x) {
        auto& value=g.cells[static_cast<std::size_t>(y)*g.width+x];
        if(value!=-1) continue;
        const double dx=(std::abs(x+.5-g.width*.5)+.5)*g.resolution;
        const double dy=(std::abs(y+.5-g.height*.5)+.5)*g.resolution;
        if(std::hypot(dx,dy)<=range) { value=0;++changed; }
    }
    return changed;
}

// Fixed world-space startup allowance. Only whole cells inside the initial
// rotation envelope are eligible; occupied values are never changed.
inline std::size_t apply_startup_unknown(Grid& g,const Pose& seed,const Config& cfg) {
    if (!valid_grid(g) || !valid_pose(seed) || !valid_config(cfg)) return 0;
    // A rectangle clears the current heading only. A disk around the
    // circumscribed padded footprint also covers initial in-place turning.
    // Authorised startup unknown travel at the configured forward cap. Cover
    // rollout, reaction and braking distance as well as cell sampling padding.
    const double travel=cfg.max_vx*(cfg.rollout_s+cfg.reaction_s)+
                        cfg.max_vx*cfg.max_vx/(2*cfg.decel);
    const double radius=std::hypot(std::max(cfg.footprint_front,cfg.footprint_rear)+cfg.margin,
                                  cfg.half_width+cfg.margin)+travel+2*g.resolution;
    std::size_t changed=0;
    for (int y=0;y<g.height;++y) for (int x=0;x<g.width;++x) {
        auto& cell=g.cells[static_cast<std::size_t>(y)*g.width+x];
        if (cell!=-1) continue;
        const double px=g.origin_x+(x+.5)*g.resolution;
        const double py=g.origin_y+(y+.5)*g.resolution;
        bool inside=true;
        for (double dx : {-g.resolution*.5,g.resolution*.5})
            for (double dy : {-g.resolution*.5,g.resolution*.5})
                inside=inside && std::hypot(px+dx-seed.x,py+dy-seed.y)<=radius;
        if (inside) { cell=0;++changed; }
    }
    return changed;
}
}
