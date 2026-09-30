#include "layer3_mission/mission_plan.hpp"

#include <cmath>
#include <cstdio>
#include <string>

#include <nlohmann/json.hpp>

namespace mission {

namespace {

using nlohmann::json;

// ── 取值的几个小工具 ─────────────────────────────────────────────────────
// 为什么不用 json::at() + try/catch：报错信息要能说清"是缺字段还是字段类型不对"，
// 异常里那句话对操作员没用（网页上要显示中文原因）。

enum class FieldState { Missing, Ok, WrongType };

FieldState read_number(const json& obj, const char* key, double& out) {
    const auto it = obj.find(key);
    if (it == obj.end() || it->is_null()) return FieldState::Missing;
    if (!it->is_number()) return FieldState::WrongType;
    out = it->get<double>();
    return FieldState::Ok;
}

FieldState read_string(const json& obj, const char* key, std::string& out) {
    const auto it = obj.find(key);
    if (it == obj.end() || it->is_null()) return FieldState::Missing;
    if (!it->is_string()) return FieldState::WrongType;
    out = it->get<std::string>();
    return FieldState::Ok;
}

/** 把 JSON 值原样印成一行短文本，只用于报错时说清"你给的是什么"。 */
std::string brief(const json& obj, const char* key) {
    const auto it = obj.find(key);
    if (it == obj.end()) return "缺";
    std::string s = it->dump();
    if (s.size() > 40) s = s.substr(0, 40) + "…";
    return s;
}

/** 数值必须有限 —— JSON 本身写不出 NaN，但 1e999 之类解析出来会是 inf。 */
bool finite(double v) { return std::isfinite(v); }

// 不用 M_PI：它是 glibc 的扩展，`-std=c++17`（而不是 gnu++17）下 __USE_MISC 关掉就没有了。
constexpr double kTwoPi = 6.283185307179586476925286766559;

/**
 * 报错信息里的数字格式化。
 * std::to_string(0.7) 是 "0.700000"，直接塞进给操作员看的中文句子里太丑 ——
 * 用 %g 留 3 位有效数字（同时顺手去掉尾随的 0 和小数点）。
 */
std::string fmt_num(double v) {
    char buf[32];
    std::snprintf(buf, sizeof(buf), "%.3g", v);
    return std::string(buf);
}

}  // namespace

const char* to_string(StepType t) {
    switch (t) {
        case StepType::CheckStand: return "check_stand";
        case StepType::GetUp:      return "getup";
        case StepType::Locomotion: return "locomotion";
        case StepType::Move:       return "move";
        case StepType::Goto:       return "goto";
        case StepType::Wait:       return "wait";
        case StepType::GetDown:    return "getdown";
    }
    return "unknown";
}

bool step_type_from_string(const std::string& s, StepType& out) {
    if (s == "check_stand") { out = StepType::CheckStand; return true; }
    if (s == "getup")       { out = StepType::GetUp;      return true; }
    if (s == "locomotion")  { out = StepType::Locomotion; return true; }
    if (s == "move")        { out = StepType::Move;       return true; }
    if (s == "goto")        { out = StepType::Goto;       return true; }
    if (s == "wait")        { out = StepType::Wait;       return true; }
    if (s == "getdown")     { out = StepType::GetDown;    return true; }
    return false;
}

bool is_dangerous_step(StepType t) {
    switch (t) {
        case StepType::GetUp:
        case StepType::Locomotion:
        case StepType::Move:
        case StepType::Goto:
        case StepType::GetDown:
            return true;
        case StepType::CheckStand:
        case StepType::Wait:
            return false;
    }
    return true;  // 说不清的按危险处理
}

bool needs_rl_mode(StepType t) {
    return t == StepType::Move || t == StepType::Goto;
}

ParseResult parse_mission_json(const std::string& text) {
    ParseResult r;

    const json root = json::parse(text, /*cb=*/nullptr, /*allow_exceptions=*/false);
    if (root.is_discarded()) {
        r.error = "不是合法的 JSON 文本";
        return r;
    }
    if (!root.is_object()) {
        r.error = "任务 JSON 的顶层必须是一个对象 {}";
        return r;
    }

    // ---- version ----
    double ver = 1.0;
    switch (read_number(root, "version", ver)) {
        case FieldState::Ok:
            if (ver != 1.0) {
                r.error = "不认识的 version=" + brief(root, "version") + "（本版只认 1）";
                return r;
            }
            break;
        case FieldState::WrongType:
            r.error = "version 必须是数字，收到 " + brief(root, "version");
            return r;
        case FieldState::Missing:
            break;  // 缺省按 1 处理
    }
    r.plan.version = 1;

    // ---- name（可选）----
    std::string name;
    if (read_string(root, "name", name) == FieldState::Ok && !name.empty()) {
        r.plan.name = name;
    } else {
        r.plan.name = "未命名任务";
    }

    // ---- confirm（可选，缺省 each = 最安全）----
    std::string confirm;
    switch (read_string(root, "confirm", confirm)) {
        case FieldState::Ok:
            if (confirm == "each")      r.plan.confirm = ConfirmMode::Each;
            else if (confirm == "none") r.plan.confirm = ConfirmMode::None;
            else {
                r.error = "confirm 只能是 \"each\" 或 \"none\"，收到 " + brief(root, "confirm");
                return r;
            }
            break;
        case FieldState::WrongType:
            r.error = "confirm 必须是字符串，收到 " + brief(root, "confirm");
            return r;
        case FieldState::Missing:
            r.plan.confirm = ConfirmMode::Each;
            break;
    }

    // ---- steps ----
    const auto steps_it = root.find("steps");
    if (steps_it == root.end()) {
        r.error = "任务里没有 steps 字段";
        return r;
    }
    if (!steps_it->is_array()) {
        r.error = "steps 必须是数组";
        return r;
    }
    if (steps_it->size() > kMaxSteps) {
        r.error = "步骤太多了（" + std::to_string(steps_it->size()) + " 步，上限 " +
                  std::to_string(kMaxSteps) + "）";
        return r;
    }

    int idx = 0;
    for (const auto& js : *steps_it) {
        ++idx;
        const std::string where = "第 " + std::to_string(idx) + " 步：";
        if (!js.is_object()) {
            r.error = where + "每个步骤必须是一个对象 {}";
            return r;
        }

        MissionStep st;
        std::string type_s;
        const auto tstate = read_string(js, "type", type_s);
        if (tstate == FieldState::Missing) {
            r.error = where + "缺少 type 字段";
            return r;
        }
        if (tstate == FieldState::WrongType) {
            r.error = where + "type 必须是字符串，收到 " + brief(js, "type");
            return r;
        }
        if (!step_type_from_string(type_s, st.type)) {
            r.error = where + "不认识的 type=" + type_s +
                      "（可用：check_stand / getup / locomotion / move / goto / wait / getdown）";
            return r;
        }

        // 逐字段读；类型不对就明确报错，缺字段就用缺省值（缺省值在 validate 里判合不合法）
        struct Reader {
            const json& js;
            const std::string& where;
            ParseResult& r;
            bool ok = true;

            void num(const char* key, double& out) {
                if (!ok) return;
                switch (read_number(js, key, out)) {
                    case FieldState::Ok:
                        if (!finite(out)) {
                            r.error = where + std::string(key) + " 不是有限数字（" +
                                      brief(js, key) + "）";
                            ok = false;
                        }
                        break;
                    case FieldState::WrongType:
                        r.error = where + std::string(key) + " 必须是数字，收到 " + brief(js, key);
                        ok = false;
                        break;
                    case FieldState::Missing:
                        break;
                }
            }
        } rd{js, where, r};

        rd.num("timeout_s", st.timeout_s);
        rd.num("settle_s", st.settle_s);
        rd.num("vx", st.vx);
        rd.num("vy", st.vy);
        rd.num("wz", st.wz);
        rd.num("duration_s", st.duration_s);
        rd.num("x", st.x);
        rd.num("y", st.y);
        rd.num("yaw", st.yaw);
        rd.num("goto_timeout_s", st.goto_timeout_s);
        if (!rd.ok) return r;

        r.plan.steps.push_back(st);
    }

    r.ok = true;
    return r;
}

std::string validate_plan(const MissionPlan& plan) {
    if (plan.steps.empty()) {
        return "任务里没有任何步骤";
    }
    if (plan.steps.size() > kMaxSteps) {
        return "步骤太多了（上限 " + std::to_string(kMaxSteps) + "）";
    }

    for (std::size_t i = 0; i < plan.steps.size(); ++i) {
        const MissionStep& st = plan.steps[i];
        const std::string where = "第 " + std::to_string(i + 1) + " 步（" +
                                  to_string(st.type) + "）：";

        switch (st.type) {
            case StepType::CheckStand:
                // timeout_s <= 0 = 用 HAL 默认值，合法
                if (st.timeout_s > 60.0) return where + "timeout_s 太大了（上限 60 s）";
                break;

            case StepType::GetUp:
            case StepType::GetDown:
                // settle_s < 0 = 用 HAL 默认值，合法
                if (st.settle_s > 120.0) return where + "settle_s 太大了（上限 120 s）";
                break;

            case StepType::Move:
                if (!(std::abs(st.vx) <= kMaxVx)) {
                    return where + "vx=" + fmt_num(st.vx) + " 超出 ±" + fmt_num(kMaxVx) + " m/s";
                }
                if (!(std::abs(st.vy) <= kMaxVy)) {
                    return where + "vy=" + fmt_num(st.vy) + " 超出 ±" + fmt_num(kMaxVy) + " m/s";
                }
                if (!(std::abs(st.wz) <= kMaxWz)) {
                    return where + "wz=" + fmt_num(st.wz) + " 超出 ±" + fmt_num(kMaxWz) + " rad/s";
                }
                if (!(st.duration_s > 0.0)) {
                    return where + "duration_s 必须大于 0（收到 " + fmt_num(st.duration_s) + "）";
                }
                if (st.duration_s > kMaxDuration) {
                    return where + "duration_s 太长了（上限 " + fmt_num(kMaxDuration) + " s）";
                }
                break;

            case StepType::Goto:
                if (!(std::abs(st.x) <= kMaxAbsXy) || !(std::abs(st.y) <= kMaxAbsXy)) {
                    return where + "目标点 (x, y) 超出 ±" + fmt_num(kMaxAbsXy) + " m 范围";
                }
                if (!(std::abs(st.yaw) <= kTwoPi + 1e-6)) {
                    return where + "yaw 超出 ±2π";
                }
                if (!(st.goto_timeout_s > 0.0)) {
                    return where + "goto_timeout_s 必须大于 0";
                }
                if (st.goto_timeout_s > kMaxDuration) {
                    return where + "goto_timeout_s 太长了（上限 " + fmt_num(kMaxDuration) + " s）";
                }
                break;

            case StepType::Wait:
                // wait 允许 0（等于什么都不做），但不允许负数
                if (!(st.duration_s >= 0.0)) {
                    return where + "duration_s 不能是负数（收到 " + fmt_num(st.duration_s) + "）";
                }
                if (st.duration_s > kMaxDuration) {
                    return where + "duration_s 太长了（上限 " + fmt_num(kMaxDuration) + " s）";
                }
                break;

            case StepType::Locomotion:
                break;
        }
    }

    return {};  // 通过
}

}  // namespace mission
