#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept>
#include "ros2_tools/local_safety_evidence.hpp"
#include "ros2_tools/local_safety_filter.hpp"

namespace {
int checks=0;
void check(bool value,const char* name) {
    ++checks;
    if (!value) { std::cerr << "FAIL: " << name << '\n'; std::exit(1); }
}
using Grid=local_safety::EvidenceGrid;
void free_frame(Grid& g,double stamp,bool floor=true,int bands=Grid::kBands) {
    const auto& c=g.config();
    g.begin_frame();
    if (floor) g.ray({{-0.4,0.05,0.3}},{{1.05,0.05,c.ground_z}});
    for (int b=0;b<bands;++b) {
        const double h=c.ground_z+c.obstacle_min_height+
            (b+0.5)*(c.obstacle_max_height-c.obstacle_min_height)/Grid::kBands;
        g.ray({{-0.4,0.05,h}},{{2.05,0.05,h}});
    }
    g.end_frame(stamp);
}
int at(const Grid& g,double now) { return g.snapshot(now).at(g.index(1.05,0.05)); }
}
int main() {
    const auto box=[](double x,double y,double z) {
        return local_safety::inside_self_box(x,y,z,.55,.35,-.30,.15);
    };
    check(box(0,0,0),"body inside exclusion");
    check(box(.55,.35,.15) && box(-.55,-.35,-.30),"box boundaries included");
    check(!box(.551,0,0) && !box(-.551,0,0),"front/rear outside retained");
    check(!box(0,.351,0) && !box(0,-.351,0),"left/right outside retained");
    check(!box(0,0,.151) && !box(0,0,-.301),"vertical outside retained");
    check(!local_safety::sensor_return_in_range(.599,0,0,.6,3),"under 60cm excluded");
    check(local_safety::sensor_return_in_range(.600,0,0,.6,3),"exact 60cm range retained");
    check(local_safety::sensor_return_in_range(.601,0,0,.6,3),"above 60cm range retained");
    check(!local_safety::sensor_return_in_range(INFINITY,0,0,.3,3) &&
          !local_safety::sensor_return_in_range(NAN,0,0,.3,3),"nonfinite range rejected");
    check(!local_safety::sensor_return_in_range(3.001,0,0,.3,3),"maximum range enforced");

    Grid::Config wide_config; wide_config.width=120;
    Grid wide(wide_config); wide.recenter(0,0);
    check(wide.index(5.0,0)>=0 && wide.index(-5.0,0)>=0 &&
          wide.index(0,5.0)>=0 && wide.index(0,-5.0)>=0,
          "expanded grid contains all four 5m range boundaries");
    wide.begin_frame();wide.ray({{0,0,.2}},{{9.0,0,.2}},true,5.0);wide.end_frame(1);
    check(wide.snapshot(1).at(wide.index(4.95,0))!=100,
          "far real return clipped at 5m creates no synthetic occupied boundary");

    Grid::Config c;
    c.ground_z=0;
    Grid g(c); g.recenter(0,0);
    check(at(g,1)==-1,"empty is unknown");
    for (int i=0;i<4;++i) {
        g.begin_frame();
        if (!box(.5,.1,0)) g.ray({{0,0,0}},{{.5,.1,0}});
        g.end_frame(.1*i);
    }
    check(g.snapshot(.3).at(g.index(.5,.1))==-1,"self excluded returns do not clear or occupy");
    g.clear();

    for (int i=0;i<3;++i) free_frame(g,1+0.1*i,false);
    check(at(g,1.2)==-1,"rays without ground support remain unknown");
    g.clear();
    for (int i=0;i<3;++i) free_frame(g,2+0.1*i,true,1);
    check(at(g,2.2)==-1,"ground and one height band not full clearance");
    g.clear();
    free_frame(g,3); free_frame(g,3.1);
    check(at(g,3.1)==-1,"clearing needs distinct frames");
    free_frame(g,3.2);
    check(at(g,3.2)==0,"floor and all bands confirm free");
    check(at(g,4.1)==-1,"free expires to unknown");
    g.begin_frame();g.ray({{-0.4,0.05,0.1}},{{1.05,0.05,0.1}});g.end_frame(4.2);
    check(at(g,4.2)==100,"thin low hit occupies immediately");
    check(at(g,100)==100,"age alone never clears occupied");
    g.begin_frame();g.ray({{-0.4,0.05,0.65}},{{2.05,0.05,0.65}});g.end_frame(4.3);
    check(at(g,4.3)==100,"high ray cannot erase low obstacle");
    free_frame(g,4.4);free_frame(g,4.5);
    check(at(g,4.5)==100,"two observations do not clear existing obstacle");
    free_frame(g,4.6);
    check(at(g,4.6)==0,"three positive same-band frames clear obstacle");
    g.begin_frame();
    g.ray({{-0.4,0.05,0.1}},{{1.05,0.05,0.1}});
    g.ray({{-0.4,0.05,0.1}},{{2.05,0.05,0.1}});
    g.end_frame(4.7);
    check(at(g,4.7)==100,"hit wins over clearing in same frame");
    free_frame(g,4.8);free_frame(g,4.8);free_frame(g,4.8);
    check(at(g,4.8)==100,"duplicate timestamp cannot supply three confirmations");
    g.recenter(0.5,0.5);
    check(at(g,4.8)==100,"rolling map retains world obstacle");
    g.recenter(100,100);
    check(g.index(1.05,0.05)==-1,"outside rolling map unknown");
    g.recenter(0,0); g.clear();
    g.begin_frame();g.ray({{0,0,0.2}},{{std::numeric_limits<double>::quiet_NaN(),0,0}});g.end_frame(5);
    check(at(g,5)==-1,"invalid return cannot clear space");
    g.begin_frame();g.ray({{-0.4,0.05,0.1}},{{1.05,0.05,0.1}},false);g.end_frame(6);
    check(at(g,6)==100,"clear-ray subsampling retains all occupied hits");
    // Far endpoints provide real rays only within the near-field sphere.
    g.clear();
    for (int frame=0;frame<3;++frame) {
        g.begin_frame();
        g.ray({{-.4,.05,.3}},{{1.05,.05,0}},true,3.0);
        for (int b=0;b<Grid::kBands;++b) {
            const double z=c.obstacle_min_height+(b+.5)*
                (c.obstacle_max_height-c.obstacle_min_height)/Grid::kBands;
            g.ray({{-.4,.05,z}},{{9.05,.05,z}},true,3.0);
        }
        g.end_frame(10+.1*frame);
    }
    check(at(g,10.2)==0,"far measured returns clear near field with full evidence");
    check(g.snapshot(10.2).at(g.index(2.65,.05))==-1,"clipped ray boundary is not an occupied hit");
    check(g.snapshot(10.2).at(g.index(3.05,.05))==-1,"outside near radius remains unknown");
    g.clear();
    for (int i=0;i<3;++i) {
        g.begin_frame();
        g.ray({{-.4,.05,.1}},{{3.05,.05,.1}},true,3.0);
        g.end_frame(11+.1*i);
    }
    check(g.snapshot(11.2).at(g.index(3.05,.05))==-1,"far real endpoint cannot create near-field hit");
    g.clear();
    g.begin_frame();g.ray({{0,.05,.1}},{{10.001,.05,.1}},true,3.0);g.end_frame(12);
    check(at(g,12)==-1,"over ten metre return supplies no evidence");
    g.begin_frame();g.ray({{0,.05,.1}},{{1.05,.05,.1}},true,3.0);g.end_frame(12.1);
    check(at(g,12.1)==100,"near real obstacle remains occupied");
    check(local_safety::sensor_return_in_range(10,0,0,.3,10),"ten metre input boundary accepted");
    check(!local_safety::sensor_return_in_range(10.001,0,0,.3,10),"beyond ten metre input rejected");
    bool rejected=false;
    try { auto bad=c;bad.resolution=0;Grid invalid(bad); } catch(const std::invalid_argument&) {rejected=true;}
    check(rejected,"invalid resolution rejected");
    std::cout << "local_safety_evidence_selftest: " << checks << " passed\n";
}
