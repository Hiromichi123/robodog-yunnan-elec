#include "layer3_mission/takeoff_getdown.hpp"
#include <cassert>
#include <iostream>

int main() {
    using nlohmann::json;
    mission::TakeoffGetdownEvent event;
    json j = {{"version",1}, {"session","boot"}, {"run_id",std::string(32,'a')},
              {"event_id","boot/"+std::string(32,'a')}, {"seq",1}, {"stage","takeoff"},
              {"thrust",.43}, {"armed",true}, {"connected",true}, {"at",100.0}, {"expires_at",100.75}};
    assert(mission::takeoff_getdown_event(j.dump(),100.1,event));
    auto check = [&](const char* field, const json& value) {
        auto bad=j;bad[field]=value;assert(!mission::takeoff_getdown_event(bad.dump(),100.1,event));
    };
    check("stage","inactive");check("thrust",.429);check("thrust",1.1);
    check("armed",false);check("connected",false);check("armed",1);
    check("seq",-1);check("seq",1.2);check("event_id","wrong");
    check("run_id",std::string(32,'z'));check("version",true);
    check("at",99.0);check("at",101.0);check("expires_at",101.0);
    check("expires_at",100.0);check("thrust","0.43");
    assert(!mission::takeoff_getdown_event(j.dump(),101.0,event));
    assert(!mission::takeoff_getdown_event("[]",100.1,event));
    assert(!mission::takeoff_getdown_event("{bad",100.1,event));
    std::cout << "takeoff_getdown_selftest: 20 cases passed\n";
}
