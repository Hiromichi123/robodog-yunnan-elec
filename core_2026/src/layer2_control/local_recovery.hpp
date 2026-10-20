#pragma once
#include "layer2_control/local_navigation.hpp"
#include <queue>
#include <chrono>
#include <unordered_map>

namespace local_nav {
struct RoutePoint { Pose pose; bool rotate{false}; };
struct LocalRoute { bool found{false}; std::vector<RoutePoint> points; int expanded{0}; std::string reason{"invalid_input"}; };

// Reverse never uses the explored/unknown-as-free map. Only cells already touched
// by the stationary padded footprint are exempt from unknown; newly entered rear
// cells must have real, fresh free evidence. Positive evidence is never erased.
inline bool certified_reverse(const Grid& raw,const Grid& explored,const Pose& p,double speed,const Config& c) {
    if(!footprint_safe(explored,p,c)||!valid_grid(raw)||speed<=0||speed>std::min(.08,c.max_vx)+1e-6) return false;
    Grid known=raw;
    const double pad=speed*.05;
    for(int y=0;y<known.height;++y)for(int x=0;x<known.width;++x) {
        auto& value=known.cells[static_cast<std::size_t>(y)*known.width+x];
        if(value!=-1) continue;
        if(detail::intersects(known.origin_x+(x+.5)*known.resolution,
                              known.origin_y+(y+.5)*known.resolution,known.resolution*.5,
                              p,c.footprint_front+hard_margin(c)+pad,c.footprint_rear+hard_margin(c)+pad,
                              c.half_width+hard_margin(c)+pad)) value=0;
    }
    Config reverse=c;std::swap(reverse.footprint_front,reverse.footprint_rear);
    const Pose rear{p.x,p.y,detail::wrap(p.yaw+3.14159265358979323846)};
    return swept_safe(known,rear,speed,0,reverse);
}

inline bool direct_lookahead_clear(const Grid& g,const Pose& p,const Pose& goal,const Config& c) {
    // Trigger detouring at the preferred boundary, before hard clearance is spent.
    Config preferred=c;preferred.soft_buffer_enabled=false;
    const double distance=std::hypot(goal.x-p.x,goal.y-p.y);
    if(distance<.4) return true;
    const double angle=detail::wrap(std::atan2(goal.y-p.y,goal.x-p.x)-p.yaw);
    const double turn=std::max(.05,std::min(.30,c.max_wz));
    if(std::abs(angle)>.02 && !primitive_clear(g,p,0,std::copysign(turn,angle),std::abs(angle)/turn,preferred))return false;
    Pose aligned=p;aligned.yaw=detail::wrap(p.yaw+angle);
    const double length=std::min(2.0,distance);
    return primitive_clear(g,aligned,.2,0,length/.2,preferred);
}

// Bounded hybrid A*: continuous unicycle arcs, adaptive position cells and 64 heading bins, full oriented
// footprint checks. It can spend distance on a detour before approaching the goal.
inline LocalRoute search_local_route(const Grid& g,const Pose& p,const Pose& goal,const Config& c) {
    LocalRoute result;
    if(!valid_grid(g)||!valid_pose(p)||!valid_pose(goal)||!valid_config(c))return result;
    if(!footprint_safe(g,p,c)){result.reason="initial_footprint_blocked";return result;}
    result.reason="no_path";
    constexpr double pi=3.14159265358979323846,angle=pi/8,fine_angle=pi/32,step=.30,quantum=.10;
    struct Node { Pose p; double cost; int parent; bool rotate; };
    struct Queue { double score; int index; bool operator<(const Queue& b)const{return score>b.score;} };
    std::vector<Node> nodes;nodes.reserve(7000);
    std::priority_queue<Queue> open;
    std::unordered_map<int,double> costs;
    const double original_distance=std::hypot(goal.x-p.x,goal.y-p.y);
    const double remaining=original_distance<=3.0?.20:original_distance-1.30;
    const auto heuristic=[&](const Pose& q){return std::max(0.,std::hypot(goal.x-q.x,goal.y-q.y)-remaining);};
    // Fine search is an escape hatch for a start at which every coarse move
    // fails. Ordinary open-space and post-retreat planning keeps its old size.
    bool fine_mode=true;
    for(int action=0;action<5;++action) {
        const bool rotate=action>=3;const double v=rotate?0.:std::min(.20,c.max_vx);
        const double duration=rotate?angle/std::min(.30,c.max_wz):step/v;
        const double w=action==0?0:(action==1||action==3?angle:-angle)/duration;
        if(std::abs(w)<=c.max_wz+1e-9&&primitive_clear(g,p,v,w,duration,c)){fine_mode=false;break;}
    }
    const auto key=[&](const Pose& q) {
        const bool near=fine_mode && std::hypot(q.x-p.x,q.y-p.y)<=.8;
        const double cell=near?quantum:2*quantum;
        const int stride=near?1:2;
        int x=static_cast<int>(std::lround((q.x-p.x)/cell))*stride+64;
        int y=static_cast<int>(std::lround((q.y-p.y)/cell))*stride+64;
        int h=static_cast<int>(std::lround(detail::wrap(q.yaw-p.yaw)/fine_angle));h=(h%64+64)%64;
        return (y*129+x)*64+h;
    };
    nodes.push_back({p,0,-1,false});open.push({heuristic(p),0});costs[key(p)]=0;
    const auto deadline=std::chrono::steady_clock::now()+std::chrono::milliseconds(120);
    while(!open.empty()&&result.expanded<2200) {
        if((result.expanded%16)==0 && std::chrono::steady_clock::now()>deadline){result.reason="search_time_budget";break;}
        const int index=open.top().index;open.pop();const auto node=nodes[index];
        if(node.cost>costs[key(node.p)]+1e-9)continue;
        ++result.expanded;
        if(index>0&&std::hypot(goal.x-node.p.x,goal.y-node.p.y)<=remaining&&
           swept_safe(g,node.p,std::min(.15,c.max_vx),0,c)) {
            result.found=true;result.reason="found";
            for(int i=index;nodes[i].parent>=0;i=nodes[i].parent)result.points.push_back({nodes[i].p,nodes[i].rotate});
            std::reverse(result.points.begin(),result.points.end());return result;
        }
        // Close to a side/front cell, coarse 22.5deg/30cm moves can all
        // collide although a small steering correction followed by travel fits.
        const bool tight=fine_mode && std::hypot(node.p.x-p.x,node.p.y-p.y)<=.8 &&
                         !detail::footprint(g,node.p,c,.10,nullptr,false);
        for(int action=0;action<(tight?10:5);++action) {
            const int kind=action%5;
            const bool fine=action>=5,rotate=kind>=3;
            const double delta=fine?fine_angle:angle;
            const double length=fine?.10:step;
            const double v=rotate?0.:std::min(.20,c.max_vx);
            const double duration=rotate?delta/std::min(.30,c.max_wz):length/v;
            const double w=kind==0?0:(kind==1||kind==3?delta:-delta)/duration;
            const Pose q=detail::integrate(node.p,v,w,duration);
            if(std::hypot(q.x-p.x,q.y-p.y)>3.8||std::abs(w)>c.max_wz+1e-9)continue;
            const int bucket=key(q);
            const double next_cost=node.cost+(rotate?.14*delta/angle:length)+
                (preferred_clear(g,q,c,.06)?0.:(c.soft_buffer_enabled?.20:.08));
            const auto found=costs.find(bucket);
            if(found!=costs.end()&&found->second<=next_cost+1e-9)continue;
            if(!primitive_clear(g,node.p,v,w,duration,c))continue;
            costs[bucket]=next_cost;nodes.push_back({q,next_cost,index,rotate});
            open.push({next_cost+1.8*heuristic(q),static_cast<int>(nodes.size()-1)});
        }
    }
    if(result.expanded>=2200)result.reason="search_node_budget";
    return result;
}

struct RecoveryDecision {
    bool active{false},failed{false},reverse{false};
    Command command;std::string state;std::string detail;
};

class LocalRecovery {
public:
    RecoveryDecision update(const Grid& grid,const Grid& raw,const Pose& p,const Pose& goal,
                            const Config& cfg,const Command& normal,double now) {
        RecoveryDecision out;
        if(!valid_grid(grid)||!valid_grid(raw)||!valid_pose(p)||!valid_pose(goal)||!valid_config(cfg)||!std::isfinite(now)) {
            out.failed=true;out.state="recovery_invalid_input";return out;
        }
        const double dt=have_time_?std::max(0.,now-last_time_):0.;last_time_=now;have_time_=true;
        if(active_) spent_+=dt;
        if(spent_>90.)return fail("recovery_time_budget_exhausted");
        if(reversing_) {
            if(std::hypot(p.x-reverse_start_.x,p.y-reverse_start_.y)>=.25||now-reverse_at_>=3.5) {
                reversing_=false;path_.clear();next_plan_=now;
                return stop("recovery_reverse_complete");
            }
            if(!certified_reverse(raw,grid,p,std::min(.08,cfg.max_vx),cfg))return fail("recovery_rear_not_observed_free");
            out.active=true;out.reverse=true;out.command={true,-std::min(.08,cfg.max_vx),0,"certified short reverse"};
            out.state="recovering_reverse";out.detail=diagnostics();return out;
        }
        if(!active_) {
            if(normal.safe&&now<next_probe_)return out;
            next_probe_=now+.6;
            if(normal.safe&&direct_lookahead_clear(grid,p,goal,cfg))return out;
            active_=true;episode_at_=now;episode_attempts_=0;next_plan_=now;
            progress_pose_=p;progress_at_=now;
        }
        if(now-episode_at_>75.)return fail("recovery_episode_timeout");
        if(std::hypot(p.x-progress_pose_.x,p.y-progress_pose_.y)>.04||
           std::abs(detail::wrap(p.yaw-progress_pose_.yaw))>.08) {progress_pose_=p;progress_at_=now;}
        if(now-progress_at_>6.) {
            // One failed recovery round is six seconds without measured motion,
            // not one inexpensive map/search refresh.
            ++episode_attempts_;path_.clear();next_plan_=now;progress_at_=now;
        }
        if(path_.empty()) {
            if(now<next_plan_)return stop("recovery_waiting_replan");
            if(episode_attempts_>=10)return fail("recovery_stall_rounds_exhausted");
            if(total_plans_>=120)return fail("recovery_plan_budget_exhausted");
            ++total_plans_;next_plan_=now+1.;
            auto route=search_local_route(grid,p,goal,cfg);
            last_search_=route.reason;last_expanded_=route.expanded;rear_checked_=false;
            if(route.found) {path_=std::move(route.points);step_=0;}
            else if((rear_checked_=true) && (rear_certified_=certified_reverse(raw,grid,p,std::min(.08,cfg.max_vx),cfg)) && reverse_count_<2) {
                ++reverse_count_;reversing_=true;reverse_start_=p;reverse_at_=now;
                return stop("recovery_reverse_start");
            } else return stop("recovery_no_route_or_certified_rear");
        }
        while(step_<path_.size()) {
            const auto& point=path_[step_];
            const double distance=std::hypot(point.pose.x-p.x,point.pose.y-p.y);
            const double error=detail::wrap(point.pose.yaw-p.yaw);
            if((point.rotate&&std::abs(error)<.025)||(!point.rotate&&distance<.04))++step_;
            else break;
        }
        if(step_==path_.size()) {active_=false;path_.clear();next_probe_=now+.2;return stop("recovery_route_complete");}
        const auto& point=path_[step_];
        const double error=detail::wrap((point.rotate?point.pose.yaw:
                          std::atan2(point.pose.y-p.y,point.pose.x-p.x))-p.yaw);
        const double route_v=std::min(cfg.soft_buffer_enabled?cfg.buffer_max_vx:.20,cfg.max_vx);
        const double route_w=std::min(cfg.soft_buffer_enabled?cfg.buffer_max_wz:.30,cfg.max_wz);
        double v=point.rotate||std::abs(error)>.45?0.:route_v*std::max(.4,std::cos(error));
        const double w=std::clamp(1.0*error,-route_w,route_w);
        // Follow the route at a stopping-safe speed; every issued command gets a
        // fresh second check at the HAL, including during recovery.
        Command selected;
        for(double scale:{1.,.6,.3})if(swept_safe(grid,p,v*scale,w*scale,cfg)) {
            selected={true,v*scale,w*scale,"bounded local route"};break;
        }
        if(!selected.safe) {path_.clear();return stop("recovery_route_changed");}
        out.active=true;out.command=selected;out.state=v==0?"recovering_turn":"detouring";out.detail=diagnostics();return out;
    }
    bool active()const{return active_;}
    int plan_count()const{return total_plans_;}
    std::string diagnostics()const {
        return "plans="+std::to_string(total_plans_)+" stall_rounds="+std::to_string(episode_attempts_)+" stall_limit=10"+
            " last_search="+last_search_+" expanded="+std::to_string(last_expanded_)+
            " rear_checked="+std::to_string(rear_checked_)+" rear_certified="+std::to_string(rear_certified_)+
            " reverse_count="+std::to_string(reverse_count_)+" recovery_seconds="+std::to_string(spent_);
    }
private:
    RecoveryDecision stop(const char* why)const {
        RecoveryDecision out;out.active=true;out.command={true,0,0,why};out.state=why;out.detail=diagnostics();return out;
    }
    RecoveryDecision fail(const char* why)const {
        auto out=stop(why);out.failed=true;return out;
    }
    std::string last_search_{"not_started"};int last_expanded_{0};
    bool rear_checked_{false},rear_certified_{false};
    bool active_{false},reversing_{false},have_time_{false};
    double last_time_{0},spent_{0},episode_at_{0},next_plan_{0},next_probe_{0},progress_at_{0},reverse_at_{0};
    int episode_attempts_{0},total_plans_{0},reverse_count_{0};
    Pose progress_pose_,reverse_start_;std::vector<RoutePoint> path_;std::size_t step_{0};
};
}

