/**
 * mission_plan 的离线自测：不连 ROS、不碰硬件，纯解析 + 校验。
 *
 * 为什么值得单独写一个可执行文件：任务 JSON 是**网页和狗之间的契约**，
 * 而 core_2026 之前一个测试都没有。一旦"网页生成的 JSON"和"狗认的 JSON"对不上，
 * 现象是狗不动、且现场看不出来是谁的问题。这里把契约钉住，编译完直接跑。
 *
 * 编译（由 core_2026/CMakeLists.txt 的 mission_plan_selftest 目标负责）：
 *   ~/ros2_ws/build.sh --packages-select core_2026
 *   ./build/core_2026/mission_plan_selftest
 *
 * 另外支持"验一份任务文件"（手写任务、或网页导出的 JSON 都能这么验）：
 *   ./build/core_2026/mission_plan_selftest --parse-file ~/my_mission.json
 */

#include "layer3_mission/mission_plan.hpp"

#include <cstdio>
#include <fstream>
#include <iterator>
#include <string>

namespace {

int g_failed = 0;
int g_total  = 0;

void check(bool cond, const std::string& what) {
    ++g_total;
    if (cond) {
        std::printf("  ✓ %s\n", what.c_str());
    } else {
        ++g_failed;
        std::printf("  ✗ %s\n", what.c_str());
    }
}

/** 断言解析成功，并返回 plan 供继续断言。 */
mission::MissionPlan must_parse(const std::string& json, const std::string& what) {
    const auto r = mission::parse_mission_json(json);
    check(r.ok, what + " —— 应当解析成功" +
                    (r.ok ? "" : "，实际报错：" + r.error));
    return r.plan;
}

/** 断言校验通过。 */
void must_validate(const mission::MissionPlan& plan, const std::string& what) {
    const std::string err = mission::validate_plan(plan);
    check(err.empty(), what + " —— 校验应当通过" + (err.empty() ? "" : "，实际：" + err));
}

/** 断言校验被拒，且原因里包含某个关键词（关键词用来确认拒绝的理由是对的）。 */
void must_reject(const mission::MissionPlan& plan, const std::string& keyword,
                 const std::string& what) {
    const std::string err = mission::validate_plan(plan);
    const bool got = !err.empty() && err.find(keyword) != std::string::npos;
    check(got, what + " —— 应当被拒且原因含「" + keyword + "」" +
                    (got ? "" : "，实际：" + (err.empty() ? "（通过了！）" : err)));
}

/** 断言解析失败，且原因里包含关键词。 */
void must_fail_parse(const std::string& json, const std::string& keyword,
                     const std::string& what) {
    const auto r = mission::parse_mission_json(json);
    const bool got = !r.ok && r.error.find(keyword) != std::string::npos;
    check(got, what + " —— 应当解析失败且原因含「" + keyword + "」" +
                    (got ? "" : "，实际：" + (r.ok ? "（居然成功了）" : r.error)));
}

// ── 一份"网页会发出来的完整任务"，各用例都从它改写 ──────────────────────
const char* kFullMission = R"({
  "version": 1,
  "name": "巡检A",
  "confirm": "each",
  "steps": [
    {"type": "check_stand", "timeout_s": 5},
    {"type": "getup", "settle_s": 10},
    {"type": "locomotion"},
    {"type": "move", "vx": 0.1, "vy": 0.0, "wz": 0.0, "duration_s": 3.0},
    {"type": "goto", "x": 1.5, "y": 0.5, "yaw": 0.0, "goto_timeout_s": 60},
    {"type": "wait", "duration_s": 5.0},
    {"type": "getdown"}
  ]
})";

}  // namespace

/**
 * 交叉校验模式：把一份任务 JSON 文件喂给**狗端真正用的那个解析器 + 校验器**。
 *
 *   mission_plan_selftest --parse-file /path/to/mission.json
 *
 * 两个用处：
 *   1. 跨语言契约测试 —— 网页 `js/mission-view.js` 生成的 JSON 直接用这条命令验，
 *      能挡住"字段名差一个字母 / 少个字段"这种双方都不报错、狗就是不动的问题。
 *   2. 手写任务先本地验一遍，别拿真狗试错。
 */
int parse_file_mode(const char* path) {
    using namespace mission;

    std::ifstream in(path);
    if (!in) {
        std::printf("✗ 打不开文件：%s\n", path);
        return 2;
    }
    const std::string text{std::istreambuf_iterator<char>(in),
                           std::istreambuf_iterator<char>()};

    const auto r = parse_mission_json(text);
    if (!r.ok) {
        std::printf("✗ 解析失败：%s\n", r.error.c_str());
        return 1;
    }
    const std::string err = validate_plan(r.plan);
    if (!err.empty()) {
        std::printf("✗ 校验未通过：%s\n", err.c_str());
        return 1;
    }

    std::printf("✓ %s\n", path);
    std::printf("  任务名「%s」，确认方式=%s，共 %zu 步\n",
                r.plan.name.c_str(),
                r.plan.confirm == ConfirmMode::Each ? "each（逐步确认）" : "none（一次授权）",
                r.plan.steps.size());
    for (std::size_t i = 0; i < r.plan.steps.size(); ++i) {
        const MissionStep& st = r.plan.steps[i];
        std::printf("  %2zu. %-12s", i + 1, to_string(st.type));
        switch (st.type) {
            case StepType::CheckStand:
                std::printf("timeout=%.1fs", st.timeout_s); break;
            case StepType::GetUp:
            case StepType::GetDown:
                std::printf("settle=%.1fs%s", st.settle_s,
                            st.settle_s < 0 ? "（用 HAL 默认）" : ""); break;
            case StepType::Move:
                std::printf("vx=%.2f vy=%.2f wz=%.2f × %.1fs", st.vx, st.vy, st.wz,
                            st.duration_s); break;
            case StepType::Goto:
                std::printf("(%.2f, %.2f, %.2f) 超时 %.0fs", st.x, st.y, st.yaw,
                            st.goto_timeout_s); break;
            case StepType::Wait:
                std::printf("%.1fs", st.duration_s); break;
            case StepType::Locomotion:
                break;
        }
        if (is_dangerous_step(st.type)) std::printf("   [需确认]");
        std::printf("\n");
    }
    return 0;
}

int main(int argc, char** argv) {
    using namespace mission;

    if (argc >= 3 && std::string(argv[1]) == "--parse-file") {
        return parse_file_mode(argv[2]);
    }

    std::printf("== mission_plan 自测 ==\n");

    // ── 1. 完整任务：字段都读对 ──────────────────────────────────────────
    std::printf("[1] 完整任务\n");
    {
        const auto plan = must_parse(kFullMission, "完整任务");
        check(plan.name == "巡检A", "name 读出来了");
        check(plan.confirm == ConfirmMode::Each, "confirm=each 读出来了");
        check(plan.steps.size() == 7, "7 个步骤一个不多一个不少");
        if (plan.steps.size() == 7) {
            check(plan.steps[0].type == StepType::CheckStand, "第 1 步是 check_stand");
            check(plan.steps[0].timeout_s == 5.0, "check_stand 的 timeout_s=5");
            check(plan.steps[1].type == StepType::GetUp, "第 2 步是 getup");
            check(plan.steps[1].settle_s == 10.0, "getup 的 settle_s=10");
            check(plan.steps[2].type == StepType::Locomotion, "第 3 步是 locomotion");
            check(plan.steps[3].type == StepType::Move, "第 4 步是 move");
            check(plan.steps[3].vx == 0.1 && plan.steps[3].duration_s == 3.0,
                  "move 的 vx / duration_s 读对");
            check(plan.steps[4].type == StepType::Goto, "第 5 步是 goto");
            check(plan.steps[4].x == 1.5 && plan.steps[4].y == 0.5,
                  "goto 的 x / y 读对");
            check(plan.steps[4].goto_timeout_s == 60.0, "goto 的 timeout 读对");
            check(plan.steps[5].type == StepType::Wait && plan.steps[5].duration_s == 5.0,
                  "wait 的时长读对（与 move 共用 duration_s 字段）");
            check(plan.steps[6].type == StepType::GetDown, "第 7 步是 getdown");
        }
        must_validate(plan, "完整任务");
    }

    // ── 2. 缺省值 ────────────────────────────────────────────────────────
    std::printf("[2] 缺省值\n");
    {
        const auto plan = must_parse(R"({"steps":[{"type":"getdown"}]})",
                                     "最简任务");
        check(plan.confirm == ConfirmMode::Each,
              "不写 confirm 时按 each 处理（缺省必须是最安全的那档）");
        check(plan.name == "未命名任务", "不写 name 时有兜底名字");
        check(plan.steps.size() == 1 && plan.steps[0].type == StepType::GetDown,
              "单步 getdown");
        must_validate(plan, "单步 getdown（settle_s 用 HAL 默认值）");
    }

    // ── 2b. 网页新加的字段必须被**安静忽略** ────────────────────────────
    // 2026-09-29 网页加了 `map`（这份任务的航点是在哪张点云图上取的，只给操作员看）。
    // 狗端不认也不需要它 —— 解析器只看已知键。**这个性质要钉住**：
    // 一旦解析改成"遇到未知键就报错"，网页那边加个 UI 字段就会让狗拒任务，
    // 而且现场看起来是"任务发下去了、狗不动"。
    std::printf("[2b] 未知顶层键（网页的 map 字段）要被忽略\n");
    {
        const auto plan = must_parse(
            R"({"version":1,"name":"带地图的任务","map":"map_20260929_113215.pcd",
                "steps":[{"type":"goto","x":0.5,"y":0.3,"yaw":0,"goto_timeout_s":30}]})",
            "带 map 字段的任务");
        check(plan.steps.size() == 1 && plan.steps[0].type == StepType::Goto,
              "map 字段被忽略，步骤照常解析");
        check(plan.name == "带地图的任务", "name 照常");
        must_validate(plan, "带 map 字段的任务");
    }

    // ── 3. confirm = none ───────────────────────────────────────────────
    std::printf("[3] confirm=none\n");
    {
        const auto plan = must_parse(R"({"confirm":"none","steps":[{"type":"wait","duration_s":1}]})",
                                     "confirm=none");
        check(plan.confirm == ConfirmMode::None, "confirm=none 读出来了");
    }

    // ── 4. 解析层的硬错误 ───────────────────────────────────────────────
    std::printf("[4] 解析错误\n");
    must_fail_parse("这不是 json", "不是合法", "非 JSON 文本");
    must_fail_parse("[1,2,3]", "顶层必须是一个对象", "顶层是数组");
    must_fail_parse(R"({"name":"x"})", "没有 steps", "缺 steps");
    must_fail_parse(R"({"steps":{}})", "必须是数组", "steps 不是数组");
    must_fail_parse(R"({"steps":["getup"]})", "必须是一个对象", "步骤是字符串");
    must_fail_parse(R"({"steps":[{"type":"passive"}]})", "不认识的 type",
                    "type=passive（已移除，必须明确拒绝）");
    must_fail_parse(R"({"steps":[{"vx":1}]})", "缺少 type", "步骤缺 type");
    must_fail_parse(R"({"steps":[{"type":"move","vx":"快"}]})", "必须是数字",
                    "vx 是字符串");
    // 1e999 超出 double 范围，nlohmann 在**解析层**就拒了（parse_error 406），
    // 根本轮不到我们的 isfinite 检查。两条路都能拒掉，这里只钉住"拒掉了"。
    must_fail_parse(R"({"steps":[{"type":"goto","x":1e999}]})", "合法",
                    "x=1e999（超范围数字，JSON 层直接拒）");
    must_fail_parse(R"({"version":2,"steps":[{"type":"wait"}]})", "不认识的 version",
                    "version=2");
    must_fail_parse(R"({"confirm":"maybe","steps":[{"type":"wait"}]})", "只能是",
                    "confirm 非法值");

    // ── 5. 校验层的硬错误 ───────────────────────────────────────────────
    std::printf("[5] 校验错误\n");
    {
        const auto empty = must_parse(R"({"steps":[]})", "空 steps");
        must_reject(empty, "没有任何步骤", "空任务");
    }
    {
        const auto slow = must_parse(R"({"steps":[{"type":"move","vx":0.9,"duration_s":1}]})",
                                     "vx 超限");
        must_reject(slow, "vx", "vx=0.9 超过 0.5 m/s");
    }
    {
        const auto zero = must_parse(R"({"steps":[{"type":"move","vx":0.1,"duration_s":0}]})",
                                     "duration=0");
        must_reject(zero, "duration_s", "move 的 duration_s=0");
    }
    {
        const auto far = must_parse(R"({"steps":[{"type":"goto","x":500,"y":0}]})",
                                    "坐标超范围");
        must_reject(far, "范围", "goto 到 500 m 外");
    }
    {
        const auto neg = must_parse(R"({"steps":[{"type":"wait","duration_s":-1}]})",
                                    "负等待");
        must_reject(neg, "负数", "wait 的 duration_s=-1");
    }
    {
        const auto toobig = must_parse(R"({"steps":[{"type":"wait","duration_s":9999}]})",
                                       "超长等待");
        must_reject(toobig, "太长", "wait 的 duration_s=9999");
    }

    // ── 6. 刻意**不**在校验层拦的那件事 ─────────────────────────────────
    // "没起立就要移动"故意留给执行期判（看狗当时的真实 FSM 状态）：
    // 计划里写了 getup、但狗已经站着时，getup 的前置判断反而会失败；
    // 而上轮任务结束时狗可能还站着没趴，这时一条"只移动"的任务完全合法。
    std::printf("[6] 「没起立就要移动」刻意放行到执行期\n");
    {
        const auto plan = must_parse(R"({"steps":[{"type":"move","vx":0.1,"duration_s":1}]})",
                                     "只移动");
        must_validate(plan, "只移动的任务（结构上合法，执行期查真实 FSM 状态）");
        check(needs_rl_mode(plan.steps[0].type),
              "move 被标为「需要在 RL 模式」—— 执行期据此拦");
    }

    // ── 7. 危险步骤分类（决定要不要过确认闸门）─────────────────────────
    std::printf("[7] 危险步骤分类\n");
    check(is_dangerous_step(StepType::GetUp),      "getup 会动 → 要确认");
    check(is_dangerous_step(StepType::Locomotion), "locomotion 会动 → 要确认");
    check(is_dangerous_step(StepType::Move),       "move 会动 → 要确认");
    check(is_dangerous_step(StepType::Goto),       "goto 会动 → 要确认");
    check(is_dangerous_step(StepType::GetDown),    "getdown 会动 → 要确认");
    check(!is_dangerous_step(StepType::CheckStand), "check_stand 只读 → 不拦");
    check(!is_dangerous_step(StepType::Wait),       "wait 不动 → 不拦");

    // ── 8. type 字符串往返 ──────────────────────────────────────────────
    std::printf("[8] type 字符串往返\n");
    {
        const StepType all[] = {StepType::CheckStand, StepType::GetUp, StepType::Locomotion,
                                StepType::Move, StepType::Goto, StepType::Wait,
                                StepType::GetDown};
        bool round_trip = true;
        for (StepType t : all) {
            StepType back{};
            if (!step_type_from_string(to_string(t), back) || back != t) round_trip = false;
        }
        check(round_trip, "每个类型的名字都能原样解析回来（网页照着 to_string 写）");
        StepType dummy{};
        check(!step_type_from_string("passive", dummy), "passive 不再是合法类型");
    }

    std::printf("\n== %d 项，失败 %d 项 ==\n", g_total, g_failed);
    return g_failed == 0 ? 0 : 1;
}
