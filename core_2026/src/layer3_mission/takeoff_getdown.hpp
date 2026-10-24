#pragma once

#include <cmath>
#include <cstdint>
#include <string>
#include <nlohmann/json.hpp>

namespace mission {
struct TakeoffGetdownEvent {
    std::string event_id, session, run_id;
    std::uint64_t seq{0};
    double at{0.0}, expires_at{0.0};
};

inline bool takeoff_getdown_event(const std::string& text, double now,
                                  TakeoffGetdownEvent& event) {
    if (text.size() > 4096 || !std::isfinite(now)) return false;
    const auto j = nlohmann::json::parse(text, nullptr, false);
    if (!j.is_object()) return false;
    const auto string_field = [&j](const char* key) {
        return j.contains(key) && j[key].is_string();
    };
    const auto number_field = [&j](const char* key) {
        return j.contains(key) && j[key].is_number() &&
               std::isfinite(j[key].get<double>());
    };
    for (const auto* key : {"event_id", "session", "run_id", "stage"})
        if (!string_field(key)) return false;
    for (const auto* key : {"at", "expires_at", "thrust"})
        if (!number_field(key)) return false;
    if (!j.contains("version") || !j["version"].is_number_integer() || j["version"] != 1 ||
        !j.contains("seq") || !j["seq"].is_number_unsigned() ||
        !j.contains("armed") || !j["armed"].is_boolean() || j["armed"] != true ||
        !j.contains("connected") || !j["connected"].is_boolean() || j["connected"] != true ||
        j["stage"] != "takeoff") return false;
    const auto session = j["session"].get<std::string>();
    const auto run = j["run_id"].get<std::string>();
    if (session.empty() || session.size() > 64 || run.size() != 32) return false;
    for (const auto c : run)
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f'))) return false;
    const auto id = j["event_id"].get<std::string>();
    if (id != session + "/" + run) return false;
    const double at = j["at"].get<double>(), end = j["expires_at"].get<double>();
    const double thrust = j["thrust"].get<double>();
    if (thrust < .43 || thrust > 1.0 || at > now + .05 || now - at > .75 ||
        end <= now || end < at || end - at > .751) return false;
    event = {id, session, run, j["seq"].get<std::uint64_t>(), at, end};
    return true;
}
}  // namespace mission
