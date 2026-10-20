#include "layer2_control/local_recovery.hpp"
#include "recovery_deadlock_fixture.hpp"
#include <chrono>
#include <cstdio>
#include <cstdlib>
using namespace local_nav;
int checks=0;
void check(bool okay,const char* name){++checks;std::printf("%s %s\n",okay?"PASS":"FAIL",name);if(!okay)std::exit(1);}
Grid open(){Grid g;g.valid=true;g.width=g.height=120;g.resolution=.1;g.origin_x=g.origin_y=-6;g.cells.assign(14400,0);return g;}
void rect(Grid& g,double x0,double x1,double y0,double y1,int value){for(int y=0;y<g.height;++y)for(int x=0;x<g.width;++x){double px=g.origin_x+(x+.5)*g.resolution,py=g.origin_y+(y+.5)*g.resolution;if(px>=x0&&px<x1&&py>=y0&&py<y1)g.cells[y*g.width+x]=value;}}
Config config(){Config c;c.footprint_front=.5;c.footprint_rear=.4;c.half_width=.32;c.margin=.15;c.max_vx=.3;c.max_wz=.35;return c;}
Command normal(const Grid& g,const Pose& p,const Pose& goal,const Config& c){double error=detail::wrap(std::atan2(goal.y-p.y,goal.x-p.x)-p.yaw);double v=std::abs(error)>.785?0:std::min(c.max_vx,.3)*std::cos(error);return select_command(g,p,goal,v,std::clamp(.8*error,-c.max_wz,c.max_wz),c);}
bool simulate(Grid g,Pose p,Pose goal,const Config& c,bool expect_reverse=false){
 LocalRecovery recovery;bool reverse_seen=false,turn_seen=false,detour_seen=false;
 for(int i=0;i<1800;++i){double now=i*.1;if(std::hypot(goal.x-p.x,goal.y-p.y)<.25){check(turn_seen,"route includes safe steering/rotation");check(detour_seen,"detour state is exercised");if(expect_reverse)check(reverse_seen,"tight front clearance triggers bounded reverse");return true;}
  auto candidate=normal(g,p,goal,c);auto decision=recovery.update(g,g,p,goal,c,candidate,now);
  if(decision.failed){std::printf("simulation failed t=%.1f pose=(%.3f %.3f %.3f) reason=%s\n",now,p.x,p.y,p.yaw,decision.state.c_str());std::printf("%s\n",decision.detail.c_str());return false;}
  if(decision.active)candidate=decision.command;
  if(!candidate.safe)candidate={true,0,0,"hold"};
  if(decision.reverse){reverse_seen=true;check(certified_reverse(g,g,p,-candidate.vx,c),"reverse command has real free evidence");}
  else if(!swept_safe(g,p,candidate.vx,candidate.wz,c)){std::puts("unsafe command");return false;}
  turn_seen|=std::abs(candidate.wz)>.05;detour_seen|=decision.state=="detouring";
  p=detail::integrate(p,candidate.vx,candidate.wz,.1);
  if(!footprint_safe(g,p,c)){std::puts("collision during independent integration");return false;}
 }
 std::printf("simulation did not arrive pose %.2f %.2f %.2f\n",p.x,p.y,p.yaw);return false;
}
int main(){
 auto c=config();auto g=open();Pose p{0,0,0};
 check(certified_reverse(g,g,p,.08,c),"free measured rear permits recovery reverse");
 auto unknown=g;unknown.cells.assign(unknown.cells.size(),-1);
 check(!certified_reverse(unknown,g,p,.08,c),"unknown-as-free cannot certify rear motion");
 auto rear=g;rect(rear,-.9,-.6,-.5,.5,100);
 check(!certified_reverse(rear,rear,p,.08,c),"rear obstacle rejects reverse braking sweep");
 check(!certified_reverse(g,g,p,.09,c),"reverse speed cap cannot be exceeded");
 check(!swept_safe(g,p,-.08,0,c),"ordinary motion channel still rejects reverse");
 auto obstacle=g;rect(obstacle,1.0,1.3,-.8,.8,100);
 check(!direct_lookahead_clear(obstacle,p,{4,0,0},c),"forward probe detects obstacle before contact");
 auto before=std::chrono::steady_clock::now();auto route=search_local_route(obstacle,p,{4,0,0},c);
 std::printf("route found=%d expanded=%d points=%zu time_ms=%.1f\n",route.found,route.expanded,route.points.size(),std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-before).count());
 check(route.found,"hybrid search finds route around frontal obstacle");
 check(simulate(obstacle,p,{4,0,0},c),"recovery reaches original goal around obstacle without collision");
 auto tight=g;rect(tight,.7,.9,-.8,.8,100);
 check(simulate(tight,p,{3,0,0},c,true),"near obstacle can reverse then turn and rejoin original route");
 auto recorded=recovery_fixture::control();auto measured=recovery_fixture::observed();
 auto actual_pose=recovery_fixture::pose();const auto actual_start=actual_pose;
 const auto actual_goal=recovery_fixture::goal();const auto actual_config=recovery_fixture::config();
 check(!primitive_clear(recorded,actual_pose,0,-.3,(3.141592653589793/8)/.3,actual_config),
       "recorded failure cannot execute coarse turn at original safety margin");
 check(primitive_clear(recorded,actual_pose,0,-.15,(3.141592653589793/32)/.15,actual_config),
       "recorded failure admits fine turn without reducing safety margin");
 LocalRecovery precise;bool escaped=false;
 for(int tick=0;tick<500;++tick) {
   auto candidate=normal(recorded,actual_pose,actual_goal,actual_config);
   auto decision=precise.update(recorded,measured,actual_pose,actual_goal,actual_config,candidate,tick*.05);
   if(decision.failed){std::printf("recorded escape %s %s\n",decision.state.c_str(),decision.detail.c_str());break;}
   if(decision.active)candidate=decision.command;
   if(!candidate.safe||candidate.vx<0||!swept_safe(recorded,actual_pose,candidate.vx,candidate.wz,actual_config))break;
   actual_pose=detail::integrate(actual_pose,candidate.vx,candidate.wz,.05);
   if(!footprint_safe(recorded,actual_pose,actual_config))break;
   if(std::hypot(actual_pose.x-actual_start.x,actual_pose.y-actual_start.y)>1.5){escaped=true;break;}
 }
 check(escaped,"recorded deadlock escapes 1.5m through fine steering without uncertified reverse");
 auto enclosed=g;rect(enclosed,.7,.9,-4,4,100);rect(enclosed,-4,-.6,-4,4,100);rect(enclosed,-4,4,.5,4,100);rect(enclosed,-4,4,-4,-.5,100);
 LocalRecovery stuck;bool failed=false;
 for(int i=0;i<800;++i){auto d=stuck.update(enclosed,unknown,p,{4,0,0},c,{false,0,0,"blocked"},i*.1);if(d.reverse)check(false,"unobserved rear must never reverse");if(i<=30)check(!d.failed,"search refreshes cannot exhaust recovery in three seconds");if(d.failed){check(i>=600,"ten no-progress rounds require at least sixty seconds");failed=true;break;}}
 check(failed,"enclosed/unobserved recovery stops after bounded attempts");
 LocalRecovery invalid;auto bad=g;bad.valid=false;check(invalid.update(bad,g,p,{4,0,0},c,{},0).failed,"invalid perception stops recovery");
 std::printf("local_recovery_selftest: %d checks passed\n",checks);
}

