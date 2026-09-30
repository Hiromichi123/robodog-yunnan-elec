#pragma once

#include <string>
#include <vector>

/**
 * @brief 任务计划：网页拼装、JSON 下发的那份东西的**内存表示**。
 *
 * 这个文件刻意**不 include 任何 ROS 头**：解析和校验是纯逻辑，能脱离 ROS 单独编译、
 * 单独跑自测（见 test/mission_plan_selftest.cpp）。执行部分在 dog_plan_executor 里。
 *
 * ── 与网页的契约（改这里必须同步改 ~/web/js/mission-view.js）──────────────
 *   {"version":1, "name":"巡检A", "confirm":"each",
 *    "steps":[{"type":"check_stand","timeout_s":5},
 *             {"type":"getup","settle_s":10},
 *             {"type":"locomotion"},
 *             {"type":"move","vx":0.1,"vy":0.0,"wz":0.0,"duration_s":3.0},
 *             {"type":"goto","x":1.5,"y":0.5,"yaw":0.0},
 *             {"type":"wait","duration_s":5.0},
 *             {"type":"getdown"}]}
 *
 * **没有 passive**（2026-09-29 用户定：passive 的卸力不可靠，失败一律 getdown 回趴下）。
 */
namespace mission {

/** 步骤类型。字符串名字就是 JSON 里的 type 字段，见 to_string / from_string。 */
enum class StepType {
    CheckStand,   // 站立前自检（只读电机/IMU，不动）
    GetUp,        // 起立（Passive → GetUp）
    Locomotion,   // 进 RL 运动模式（GetUp → RLLocomotion）
    Move,         // 定速移动：vx/vy/wz × duration
    Goto,         // 闭环到点 (x, y, yaw)
    Wait,         // 原地等
    GetDown,      // 平滑趴下（RLLocomotion → GetDown）
};

/** 确认闸门模式：每个危险步骤都问 / 一次都不问。 */
enum class ConfirmMode {
    Each,   // 缺省：危险步骤前停下，等网页点"继续"
    None,   // 一口气跑完
};

const char* to_string(StepType t);

/** 解析 type 字符串；不认识返回 false（调用方给报错信息）。 */
bool step_type_from_string(const std::string& s, StepType& out);

/**
 * 这一步会不会让狗改变姿态或位置（= 要不要过确认闸门）。
 *
 * 尺度照现有代码：只有真正会动的那几步才拦（原来只有"前进前"要按回车，起立/趴下也要）。
 * check_stand 只读电机状态、wait 什么都不做，都不拦。
 */
bool is_dangerous_step(StepType t);

/**
 * 这一步要不要狗已经在 RL 运动模式里。
 *
 * 注意：**这只是给网页做提示用的**，不是执行门槛 —— 执行时以 **狗当时的真实 FSM 状态**
 * 为准（dog_plan_executor 在发速度前会查）。原因：狗上一轮任务结束时可能还站着没趴，
 * 这时一条"只移动"的任务是完全合法的；反过来，计划里写了 getup 但狗已经站着，
 * getup 的前置判断反而会失败。按计划文本判会两头出错。
 */
bool needs_rl_mode(StepType t);

/** 一个步骤。所有参数都带缺省值，JSON 里给多少算多少。 */
struct MissionStep {
    StepType type{StepType::Wait};

    // check_stand
    double timeout_s{5.0};        // 等自检结果的上限；<=0 表示用 HAL 的 check_stand_timeout_s

    // getup / getdown
    double settle_s{-1.0};        // 稳定延迟；<0 表示用 HAL 的默认值（起立 10 s / 其它 1 s）

    // move：机体系定速，走 duration_s 秒；wait：原地等 duration_s 秒
    // （两者共用同一个字段名 —— 网页那边 `duration_s` 是同一个输入框语义，
    //   分成两个字段只会让 JSON 契约平白多一种写法）
    double vx{0.0};
    double vy{0.0};
    double wz{0.0};
    double duration_s{0.0};

    // goto：世界系（Point-LIO 建图坐标系）
    double x{0.0};
    double y{0.0};
    double yaw{0.0};
    double goto_timeout_s{60.0};  // 到点闭环的总超时
};

struct MissionPlan {
    int version{1};
    std::string name;
    ConfirmMode confirm{ConfirmMode::Each};
    std::vector<MissionStep> steps;
};

struct ParseResult {
    bool ok{false};
    MissionPlan plan;
    std::string error;   // 中文，直接显示到网页上
};

/**
 * 解析任务 JSON。
 *
 * 只做**结构**解析，不做语义校验（那是 validate_plan 的事）—— 这样调用方能先看
 * "文本是不是合法 JSON"，再看"内容对不对"，报错信息更准。
 */
ParseResult parse_mission_json(const std::string& text);

/**
 * 执行前的护栏。返回空串 = 通过；否则是拒绝原因（中文）。
 *
 * 校验内容（都是"一步都不动就能判死"的硬错误）：
 *   - 至少一步，且不超过 kMaxSteps 步
 *   - move：duration_s 必须有限且 > 0；三轴速度必须有限且在物理合理范围内
 *   - goto：坐标必须有限、在合理范围内；总超时必须有限且 > 0
 *   - wait：时长必须有限且 >= 0
 *   - check_stand：超时必须有限且 > 0（<= 0 走 HAL 默认值时可省略）
 *
 * **刻意不校验**"移动步骤前面必须有 getup+locomotion"：那是执行期的事，见 needs_rl_mode 的注释。
 */
std::string validate_plan(const MissionPlan& plan);

// ── 硬限值（超了就拒，不是裁剪 —— 悄悄改掉操作员填的数字比报错更糟）──────
inline constexpr double kMaxVx        = 0.5;    // m/s
inline constexpr double kMaxVy        = 0.5;    // m/s
inline constexpr double kMaxWz        = 1.0;    // rad/s
inline constexpr double kMaxAbsXy     = 50.0;   // m，世界系坐标绝对值上限
inline constexpr double kMaxDuration  = 300.0;  // s，单步时长上限
inline constexpr std::size_t kMaxSteps = 200;

}  // namespace mission
