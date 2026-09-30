#include "layer4_system/dog_system.hpp"

#include <chrono>

#include <rclcpp/executors/single_threaded_executor.hpp>

using namespace fly_to_target_args;

DogSystem::DogSystem() {
    // Layer 1: 机器狗 HAL
    hal_ = std::make_shared<RobotDogHAL>();

    // Layer 2: 飞行控制器 (地面 PID)
    PidConfig dog_pid;
    dog_pid.xy  = PidGains{0.3f, 0.05f, 0.1f, 0.3f, 0.0f};
    dog_pid.z   = PidGains{0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    dog_pid.yaw = PidGains{0.5f, 0.1f, 0.1f, 0.3f, 0.3f};

    fc_ = std::make_unique<FlightController>(
        *hal_,              // IStateProvider&
        *hal_,              // ICommandPublisher&
        hal_->get_logger(),
        hal_->get_clock(),
        20,
        dog_pid);

    // Layer 3: 机器狗任务执行器
    mission_ = std::make_unique<DogMissionExecutor>(
        *fc_, *hal_, *hal_, *hal_, *hal_, hal_->get_logger(), *hal_, 0.0f);

    // Layer 3': 网页下发的 JSON 任务（与上面并列，不共用状态机）
    channel_   = std::make_shared<mission::DogMissionChannel>();
    plan_exec_ = std::make_unique<mission::DogPlanExecutor>(
        *hal_, *fc_, *channel_, hal_->get_logger());

    // 急停钩子：**在 spin 线程里就动手**，不等主线程。
    // 主线程可能正阻塞在某条命令的等待上（最长 8s），那几秒里狗还在动。
    // 钩子里只做两件不阻塞的事：
    //   1. 置中止位 → 主线程在下一个检查点（每 50ms 一次）退出并回趴下
    //   2. 伪造成终态打断正在等的命令 → 阻塞的等待立刻返回
    channel_->set_abort_hook([this]() {
        if (plan_exec_) plan_exec_->request_abort();
        if (hal_)       hal_->cancel_pending_command();
    });

    // Spin 线程：一个 executor 带两个节点（HAL + 任务通道）。
    // 单线程、共用 wait set —— 回调之间没有新的并发，主线程仍独占所有阻塞操作。
    auto executor = std::make_shared<rclcpp::executors::SingleThreadedExecutor>();
    executor->add_node(hal_);
    executor->add_node(channel_);
    spin_thread_ = std::make_shared<std::thread>([executor]() {
        while (rclcpp::ok()) {
            executor->spin_some();
            std::this_thread::sleep_for(std::chrono::milliseconds(2));
        }
    });

    // ⚠️ 这里**不能**写 rclcpp::on_shutdown(join spin 线程) —— 2026-09-30 实测死锁。
    // Ctrl-C 触发的 shutdown 跑在 rclcpp 的信号处理线程里；在那个回调里 join spin
    // 线程时，即使 spin 线程的函数体已经跑完、正在退出，join 也**永远不返回**
    // （本板最小复现 10/10：线程打印了「走到结尾」，join 仍不返回）。
    // 后果：进程退不掉，而且**再按 Ctrl-C 也没用** —— 信号处理线程正卡在这个回调
    // 里，只有 kill -9 能收场。这就是 dog_node「Ctrl-C 退不出」的经常性 bug。
    // Ctrl-C 起效的那几次，是主线程自己抢到了 shutdown（回调跑在主线程上，join 正常）。
    //
    // 现在 join 只在析构里做（见 ~DogSystem）：main 先 rclcpp::shutdown()、再走析构，
    // 那时 spin 线程早已因 ok()==false 退出，join 立刻返回，且顺序仍在 hal_/channel_
    // 析构之前 —— 原来想用 on_shutdown 保护的东西一点没少（已实测退出码 0）。

    RCLCPP_INFO(hal_->get_logger(), "[DogSystem] 初始化完成");
}

DogSystem::~DogSystem() {
    // 全进程**唯一**的 join 点 —— 别再加第二个，尤其别放进 on_shutdown
    // （理由见构造函数里 2026-09-30 那段注释：会死锁，Ctrl-C 就退不出了）。
    if (spin_thread_ && spin_thread_->joinable()) spin_thread_->join();
}

void DogSystem::run() {
    if (!wait_for_lidar()) return;

    if (hal_->get_wait_for_mission()) {
        // 网页驱动：预检交出去，变成任务里的步骤（操作员在网页上看得见、可编排）
        run_mission_loop();
        return;
    }

    // ── 旧路径：固定流程 + 终端回车闸门（一字不改）────────────────────
    if (!pre_flight_checks()) {
        RCLCPP_ERROR(hal_->get_logger(),
                     "[DogSystem] 预检未通过，不执行任务（狗按安全流程处置）");
        return;
    }
    mission_->run();
}

bool DogSystem::wait_for_lidar() {
    RCLCPP_INFO(hal_->get_logger(), "[PreFlight] 等待 LiDAR 定位...");
    while (rclcpp::ok() && !hal_->has_state()) {
        RCLCPP_WARN_THROTTLE(hal_->get_logger(), *hal_->get_clock(), 5000,
            "[PreFlight] 未收到 lidar_data 定位数据");
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    return rclcpp::ok();
}

void DogSystem::run_mission_loop() {
    RCLCPP_INFO(hal_->get_logger(),
                "[任务] 网页驱动模式：等 /dog/mission 上的任务（预检由任务步骤负责）");

    // 先报一帧 idle：网页靠它判断"狗端在线"。刷新页面也靠这个自动对齐。
    {
        mission::DogMissionChannel::Status s;
        s.phase = "idle";
        s.msg   = "等待网页下发任务";
        channel_->set_status(s);
        channel_->publish_status_now();
    }

    rclcpp::Rate rate(10);   // 10Hz 查一次有没有新任务
    std::string doc;

    while (rclcpp::ok()) {
        if (!channel_->take_doc(doc)) {
            rate.sleep();
            continue;
        }

        // ── 解析 + 校验：不过就**一步都不动**，把原因如实回给网页 ──────
        const auto parsed = mission::parse_mission_json(doc);
        if (!parsed.ok) {
            RCLCPP_ERROR(hal_->get_logger(), "[任务] 解析失败：%s", parsed.error.c_str());
            mission::DogMissionChannel::Status s;
            s.phase = "rejected";
            s.msg   = "任务被拒：" + parsed.error;
            channel_->set_status(s);
            channel_->publish_status_now();
            continue;
        }
        const std::string verr = mission::validate_plan(parsed.plan);
        if (!verr.empty()) {
            RCLCPP_ERROR(hal_->get_logger(), "[任务] 校验未通过：%s", verr.c_str());
            mission::DogMissionChannel::Status s;
            s.phase = "rejected";
            s.name  = parsed.plan.name;
            s.msg   = "任务被拒：" + verr;
            s.total = static_cast<int>(parsed.plan.steps.size());
            channel_->set_status(s);
            channel_->publish_status_now();
            continue;
        }

        // 执行（阻塞到结束）。终态（done/failed/aborted）留在状态里不回退成 idle
        // —— 操作员要看结果；下一条任务到来时会自然覆盖。
        plan_exec_->execute(parsed.plan);
    }
}

bool DogSystem::pre_flight_checks() {
    // ── 第 1 步：站立前检查（照小脑 ~/ws_demo.py 的做法）────────────
    // check_stand 只检测、不动电机（电机零位 + IMU）。不过就中止，
    // 与 ws_demo.py「前一步失败即停」一致。
    //
    // 这里**不发任何安全动作**：预检没过时狗还趴着（Passive），本来就是安全的。
    // 2026-09-29 起不再发 passive —— 那条命令的卸力不可靠，而且趴着时发它
    // 只会被 FSM 拒，徒增误判。
    RCLCPP_INFO(hal_->get_logger(), "[PreFlight] 请求站立前检查 check_stand...");
    if (!hal_->run_check_stand(hal_->get_check_stand_timeout_s())) {
        RCLCPP_ERROR(hal_->get_logger(),
                     "[PreFlight] check_stand 未通过 —— 不可站立，任务中止（狗仍趴着，无需处置）");
        return false;
    }

    // ── 人工闸门：起立前确认现场安全（照 ~/dog_step_test.py）──────
    if (!hal_->wait_for_enter(
            "链路 OK，check_stand 通过。确认狗周围安全后按回车发起立")) {
        RCLCPP_WARN(hal_->get_logger(),
                    "[PreFlight] 操作员放弃（或无法交互）—— 不起立，直接中止");
        return false;
    }

    // ── 第 2 步：起立 ──────────────────────────────────────────────
    // 前置：狗必须是趴着的（RLFSMStatePassive）。
    // 确认：命令终态 DONE + FSM 状态码真的变成 RLFSMStateGetUp。
    // 延迟：stand_settle_s（默认 10s，从发命令起算）—— 双重保险的第二道，
    //       给狗留够真的站稳的时间，之后才允许进 RL 模式。
    RCLCPP_INFO(hal_->get_logger(), "[PreFlight] 请求机器狗站立...");
    if (!hal_->transition_to("getup", "RLFSMStateGetUp", "RLFSMStatePassive",
                             hal_->get_stand_settle_s())) {
        RCLCPP_ERROR(hal_->get_logger(),
                     "[PreFlight] 起立未确认完成 —— 任务中止（等人工确认后处置）");
        return false;
    }

    RCLCPP_INFO(hal_->get_logger(),
                "[PreFlight] 就绪！机器狗已站立且已稳定 %.0fs",
                hal_->get_stand_settle_s());
    return true;
}
