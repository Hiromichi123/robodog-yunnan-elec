#include "layer1_hal/goto_persistence.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int count = 0, failed = 0;
    auto check = [&](bool ok, const char* text) {
        ++count; if (!ok) ++failed;
        std::cout << (ok ? "PASS " : "FAIL ") << text << '\n';
    };
    char tmp[] = "/tmp/goto-persistence-test-XXXXXX";
    if (!mkdtemp(tmp)) return 2;
    const std::string path = std::string(tmp) + "/nested/config.json";
    mission::GotoConfig config;
    mission::GotoSavedConfig loaded;
    check(!mission::load_goto_saved(path, loaded), "missing file is normal");
    config.max_vx = 0.23; config.tol_xy = 0.6;
    auto saved = mission::save_goto_config(path, config);
    check(mission::load_goto_saved(path, loaded) && loaded.config.max_vx == 0.23 && loaded.config.tol_xy == 0.6,
          "save/load full snapshot");
    check(mission::goto_config_json(loaded.config) == mission::goto_config_json(config), "all 8 values roundtrip");
    struct stat st{}; stat(path.c_str(), &st);
    check((st.st_mode & 0777) == 0600, "config permissions 0600");
    nlohmann::json doc{{"schema_version",1},{"saved_at",saved.saved_at},{"parameters",mission::goto_config_json(config)}};
    auto rejects = [&](const std::string& text) {
        try { mission::parse_goto_saved(text); return false; } catch (...) { return true; }
    };
    check(rejects("{"), "malformed JSON rejected");
    check(rejects(std::string(17000, ' ')), "oversize rejected");
    auto bad = doc; bad["schema_version"] = 2; check(rejects(bad.dump()), "unsupported version rejected");
    bad=doc; bad["schema_version"]=true; check(rejects(bad.dump()), "boolean version rejected");
    bad=doc; bad["parameters"].erase("max_vx"); check(rejects(bad.dump()), "missing field rejected");
    bad=doc; bad["parameters"]["extra"]=1; check(rejects(bad.dump()), "extra field rejected");
    bad=doc; bad["parameters"]["max_vx"]=true; check(rejects(bad.dump()), "boolean value rejected");
    bad=doc; bad["parameters"]["max_vx"]="0.2"; check(rejects(bad.dump()), "string value rejected");
    bad=doc; bad["parameters"]["max_vx"]=0.6; check(rejects(bad.dump()), "out of range rejected");
    bad=doc; bad["parameters"]["max_vx"]=nullptr; check(rejects(bad.dump()), "null value rejected");
    auto duplicate=doc.dump();duplicate.insert(1,"\"schema_version\":1,");check(rejects(duplicate),"duplicate key rejected");
    duplicate=doc.dump();auto pos=duplicate.find("\"parameters\":{");duplicate.insert(pos+14,"\"max_vx\":0.1,");
    check(rejects(duplicate), "nested duplicate key rejected");
    auto invalid=config;invalid.max_vx=std::numeric_limits<double>::infinity();
    try { mission::save_goto_config(path,invalid);check(false,"nonfinite save rejected"); } catch (...) {check(true,"nonfinite save rejected");}
    mission::load_goto_saved(path,loaded);check(loaded.config.max_vx==0.23,"failed validation preserves previous file");
    std::ofstream(std::string(tmp)+"/block") << "not a directory";
    try { mission::save_goto_config(std::string(tmp)+"/block/config",config);check(false,"directory failure reported"); }
    catch (...) {check(true,"directory failure reported");}
    chmod((std::string(tmp)+"/nested").c_str(),0500);
    try { mission::save_goto_config(path,config);check(false,"permission failure reported"); }
    catch (...) {check(true,"permission failure reported");}
    chmod((std::string(tmp)+"/nested").c_str(),0700);
    mission::load_goto_saved(path,loaded);check(loaded.config.max_vx==0.23,"I/O failure preserves prior file");
    std::ofstream(path) << "invalid";
    try { mission::load_goto_saved(path,loaded);check(false,"corrupt load reported"); }catch(...){check(true,"corrupt load reported");}
    check(loaded.config.max_vx==0.23,"corrupt load never partially updates output");
    std::filesystem::remove_all(tmp);
    std::cout << count << " checks, " << failed << " failed\n";
    return failed ? 1 : 0;
}
