#include "layer2_control/local_recovery.hpp"
#include "recovery_deadlock_fixture.hpp"
#include <cstdio>
#include <cstdlib>
using namespace local_nav;
int checks=0;
void check(bool ok,const char* label){++checks;printf("%s %s\n",ok?"PASS":"FAIL",label);if(!ok)std::exit(1);}
Grid grid(){Grid g;g.valid=true;g.width=g.height=120;g.resolution=.1;g.origin_x=g.origin_y=-6;g.cells.assign(14400,0);return g;}
void rect(Grid& g,double x0,double x1,double y0,double y1){for(int y=0;y<g.height;y++)for(int x=0;x<g.width;x++){double xx=g.origin_x+(x+.5)*g.resolution,yy=g.origin_y+(y+.5)*g.resolution;if(xx>=x0&&xx<x1&&yy>=y0&&yy<y1)g.cells[y*g.width+x]=100;}}
int main(){
 Config c;c.footprint_front=.31;c.footprint_rear=.30;c.half_width=.14;c.margin=.25;c.hard_margin=.05;c.max_vx=.45;c.max_wz=.45;c.soft_buffer_enabled=true;
 auto g=grid();Pose p{0,0,0};
 check(valid_config(c),"split protection config is valid");
 check(swept_safe(g,p,.45,0,c),"open space retains user speed cap");
 rect(g,-4,4,.3,.5);
 Config old=c;old.soft_buffer_enabled=false;
 check(!footprint_safe(g,p,old),"legacy 25cm envelope would be locked at this pose");
 check(footprint_safe(g,p,c),"obstacle inside preferred buffer is not hard collision");
 check(!preferred_clear(g,p,c),"preferred buffer detects close obstacle");
 check(swept_safe(g,p,.30,0,c),"buffer-speed motion along buffer is permitted");
 check(swept_safe(g,p,static_cast<float>(.30),0,c),"float mission velocity at .30 limit is accepted");
 check(!swept_safe(g,p,.40,0,c),"high speed is rejected inside preferred buffer");
 check(swept_safe(g,p,0,-.15,c),"slow steering away is permitted inside buffer");
 check(!swept_safe(g,p,0,-.35,c),"turn with colliding stopping sweep is rejected");
 check(!direct_lookahead_clear(g,p,{3,0,0},c),"preferred boundary triggers detouring before hard collision");
 auto command=select_command(g,p,{3,0,0},.45,0,c);
 check(command.safe&&command.vx>0&&command.vx<=.30+1e-9,"normal planner selects buffer-limited motion instead of deadlock");
 auto hard=grid();rect(hard,-1,1,.1,.2);
 check(!footprint_safe(hard,p,c),"actual body intersection is forbidden");
 check(!swept_safe(hard,p,.03,0,c),"crawl cannot bypass actual body collision");
 auto guard=grid();guard.resolution=.02;guard.origin_x=guard.origin_y=-1.2;rect(guard,-1,1,.16,.18);
 check(!footprint_safe(guard,p,c),"5cm hard protection remains forbidden");
 auto front=grid();rect(front,.8,1.,-1,1);
 check(swept_safe(front,p,.10,0,c),"slow approach has sufficient complete stopping distance");
 check(!swept_safe(front,p,.30,0,c),"full rollout reaction and braking reject fast approach");
 auto unknown=grid();unknown.cells.assign(unknown.cells.size(),-1);
 check(!swept_safe(unknown,p,.03,0,c),"soft buffer never converts unknown cells to free");
 check(!certified_reverse(unknown,g,p,.08,c),"unknown rear still cannot authorize retreat");
 auto destination=grid();rect(destination,2.3,2.5,-1,1);Pose target{1.8,0,0};
 check(footprint_safe(destination,target,c),"buffer-only destination clears hard body");
 check(!goal_occupied(destination,target,c)&&goal_needs_adjustment(destination,target,c),"destination inside preferred buffer triggers repair before hard collision");
 auto replacement=find_adjusted_goal(destination,p,target,p,c);
 check(replacement.found&&replacement.goal.x<target.x,"buffer destination retreats longitudinally to free region");
 check(goal_in_free_space(destination,replacement.goal,c),"repaired destination clears complete preferred footprint");
 check(oriented_direct_route(destination,p,replacement.goal,c),"repaired destination has continuously checked hard-footprint route");
 auto side=grid();rect(side,-4,4,.3,.5);Pose side_goal{2,0,0};
 auto side_repair=find_adjusted_goal(side,p,side_goal,p,c);
 check(!detail::direct_route(side,p,side_goal,c),"circumscribed disk rejects buffer-side start");
 check(side_repair.found&&goal_in_free_space(side,side_repair.goal,c),"buffer-side start can reach a full-clearance destination without requiring full buffer in transit");
 auto recorded=recovery_fixture::control();auto raw=recovery_fixture::observed();auto pose=recovery_fixture::pose();auto start=pose;auto goal=recovery_fixture::goal();auto actual=recovery_fixture::config();actual.soft_buffer_enabled=true;
 check(footprint_safe(recorded,pose,actual),"recorded pose clears hard protection");
 check(primitive_clear(recorded,pose,0,-.15,(3.141592653589793/8)/.15,actual),"recorded map now admits full 22.5 degree turn using buffer");
 LocalRecovery recovery;bool escaped=false;double maxw=0;
 for(int i=0;i<1000;i++){
   double error=detail::wrap(std::atan2(goal.y-pose.y,goal.x-pose.x)-pose.yaw);
   auto normal=select_command(recorded,pose,goal,std::abs(error)>.785?0.:.3,std::clamp(error,-.45,.45),actual);
   auto d=recovery.update(recorded,raw,pose,goal,actual,normal,i*.05);
   if(d.failed){printf("escape failed %s %s\n",d.state.c_str(),d.detail.c_str());break;}
   auto cmd=d.active?d.command:normal;if(!cmd.safe||d.reverse||!swept_safe(recorded,pose,cmd.vx,cmd.wz,actual))break;
   maxw=std::max(maxw,std::abs(cmd.wz));pose=detail::integrate(pose,cmd.vx,cmd.wz,.05);
   // Independent oriented rectangle-vs-square SAT: fixed physical body + 5cm,
   // no reuse of planner footprint or preferred envelope.
   bool collision=false;double co=cos(pose.yaw),si=sin(pose.yaw);
   for(int y=0;y<recorded.height;y++)for(int x=0;x<recorded.width;x++){
     if(recorded.cells[y*recorded.width+x]<=0)continue;
     double dx=recorded.origin_x+(x+.5)*recorded.resolution-(pose.x+.005*co);
     double dy=recorded.origin_y+(y+.5)*recorded.resolution-(pose.y+.005*si);
     double h=recorded.resolution*.5,a=.355,b=.19,ac=std::abs(co),as=std::abs(si);
     if(std::abs(dx)<=a*ac+b*as+h&&std::abs(dy)<=a*as+b*ac+h&&std::abs(co*dx+si*dy)<=a+h*(ac+as)&&std::abs(-si*dx+co*dy)<=b+h*(ac+as))collision=true;
   }
   if(collision){printf("independent collision tick=%d\n",i);break;}
   if(hypot(pose.x-start.x,pose.y-start.y)>1.5){printf("recorded soft escape seconds=%.2f max_w=%.3f\n",i*.05,maxw);escaped=true;break;}
 }
 check(escaped,"actual deadlock escapes with independent hard-body SAT and no uncertified reverse");
 printf("soft_buffer_selftest: %d checks passed\n",checks);
}
