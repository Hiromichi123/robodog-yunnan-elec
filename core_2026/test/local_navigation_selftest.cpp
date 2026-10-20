#include "layer2_control/startup_unknown.hpp"

#include <cstdio>
#include <limits>

namespace {
local_nav::Grid open_grid() {
    local_nav::Grid g;
    g.resolution = 0.1;
    g.origin_x = -5.0; g.origin_y = -4.0;
    g.width = 120; g.height = 80;
    g.cells.assign(static_cast<std::size_t>(g.width) * g.height, 0);
    g.valid = true;
    return g;
}

void rect(local_nav::Grid& g, double left, double right, double bottom, double top,
          std::int8_t value) {
    for (int y = 0; y < g.height; ++y) for (int x = 0; x < g.width; ++x) {
        const double px = g.origin_x + (x + 0.5) * g.resolution;
        const double py = g.origin_y + (y + 0.5) * g.resolution;
        if (px >= left && px < right && py >= bottom && py < top)
            g.cells[static_cast<std::size_t>(y) * g.width + x] = value;
    }
}

local_nav::Grid corridor() {
    auto g = open_grid();
    rect(g, -5, 7, 1, 4, 100);
    rect(g, -5, 7, -4, -1, 100);
    return g;
}
}  // namespace

int main() {
    using namespace local_nav;
    constexpr double pi = 3.14159265358979323846;
    const double nan = std::numeric_limits<double>::quiet_NaN();
    int total = 0, failed = 0;
    const auto check = [&](bool ok, const char* label) {
        ++total;
        if (!ok) ++failed;
        std::printf("%s %s\n", ok ? "PASS" : "FAIL", label);
    };
    Config c;
    const Pose robot{0, 0, 0};
    auto g = corridor();
    check(valid_config(c), "suggested config is numerically valid, not a calibration certificate");
    check(footprint_safe(g, robot, c), "2m corridor fits padded footprint");
    check(swept_safe(g, robot, 0.15, 0, c), "forward motion includes safe stopping sweep");
    auto cmd = select_command(g, robot, {4, 0, 0}, 0.4, 0, c);
    check(cmd.safe && cmd.vx > 0 && cmd.vx <= c.max_vx && cmd.wz == 0,
          "clear corridor progresses with configured low speed cap");
    check(swept_safe(g, robot, static_cast<float>(c.max_vx), 0, c) &&
          swept_safe(g, robot, 0, static_cast<float>(c.max_wz), c),
          "float32 velocity roundtrip is not rejected at configured cap");
    check(!swept_safe(g, robot, -0.01, 0, c), "reverse velocity is never accepted");
    check(!swept_safe(g, robot, 0.16, 0, c), "guard rejects speed above calibrated limit");
    check(!swept_safe(g, robot, 0.1, 0.36, c), "guard rejects yaw above calibrated limit");
    check(!select_command(g, robot, {4, 0, 0}, -0.1, 0, c).safe,
          "negative nominal speed cannot turn into forward motion");

    auto unknown = g;
    rect(unknown, 0.7, 1.0, -0.6, 0.6, -1);
    check(!swept_safe(unknown, robot, 0.15, 0, c), "unknown cells in braking sweep block motion");
    auto boundary = robot;
    boundary.x = -4.5;
    check(!footprint_safe(g, boundary, c), "footprint at map boundary is not free");
    check(!goal_occupied(g, {100, 100, 0}, c), "out of map goal is unknown, not blocked goal evidence");
    check(!find_adjusted_goal(g, robot, {100, 100, 0}, robot, c).found,
          "unknown distant goal cannot be prematurely adjusted");
    unknown.cells.assign(unknown.cells.size(), -1);
    check(!goal_occupied(unknown, robot, c), "all unknown grid supplies no positive obstacle evidence");
    check(!footprint_safe(unknown, robot, c), "all unknown grid supplies no free footprint");

    auto near_wall = open_grid();
    rect(near_wall, -5, 7, 0.5, 4, 100);
    check(footprint_safe(near_wall, robot, c), "initial rectangle clears nearby side wall");
    check(!swept_safe(near_wall, robot, 0, 0.35, c), "turning corner sweeps into side wall");
    check(swept_safe(g, robot, 0, 0.35, c), "rotation allowed when complete footprint sweep fits");
    cmd = select_command(g, robot, {0, 0, 1}, 0, 0.35, c);
    check(cmd.safe && cmd.vx == 0 && cmd.wz > 0, "final yaw never invents translation");
    cmd = select_command(g, robot, {0, 0, -1}, 0, -0.35, c);
    check(cmd.safe && cmd.vx == 0 && cmd.wz < 0, "negative final yaw keeps requested sign");
    auto wall_ahead = g;
    rect(wall_ahead, 0.8, 1.0, -1, 1, 100);
    check(!swept_safe(wall_ahead, robot, 0.15, 0, c), "full speed cannot stop before front wall");
    cmd = select_command(wall_ahead, robot, {4, 0, 0}, 0.15, 0, c);
    check(cmd.safe && cmd.vx > 0 && cmd.vx < 0.15, "candidate selection slows near front obstacle");
    auto sealed = g;
    rect(sealed, 0.65, 1.0, -1, 1, 100);
    cmd = select_command(sealed, robot, {4, 0, 0}, 0.15, 0, c);
    check(!cmd.safe && cmd.vx == 0 && cmd.wz == 0, "no viable forward trajectory returns blocked, not endless spin");

    const Pose start{-2, 0, 0}, goal{3, 1, 0.2};
    check(goal_occupied(g, goal, c), "goal footprint positively intersects corridor wall");
    const auto adjusted = find_adjusted_goal(g, robot, goal, start, c);
    check(adjusted.found, "one metre lateral error can yield a reachable shifted corridor goal");
    if (adjusted.found) {
        const double length = std::hypot(goal.x - start.x, goal.y - start.y);
        const double ux = (goal.x - start.x) / length, uy = (goal.y - start.y) / length;
        const double loss = (goal.x - adjusted.goal.x) * ux + (goal.y - adjusted.goal.y) * uy;
        const double lateral = -(adjusted.goal.x - goal.x) * uy + (adjusted.goal.y - goal.y) * ux;
        check(std::abs(loss) < 1e-9, "first choice preserves exact longitudinal progress");
        check(std::abs(lateral) <= c.max_lateral_shift + 1e-9, "lateral correction remains bounded");
        check(adjusted.goal.yaw == goal.yaw, "goal correction preserves required final yaw");
        check(footprint_safe(g, adjusted.goal, c), "corrected goal footprint is known free");
        check(std::hypot(adjusted.goal.x - robot.x, adjusted.goal.y - robot.y) > 2.0,
              "goal adjustment does not use current position as fake success");
    }
    // Only a moving 3m horizon is observed. Until the endpoint enters it, the
    // controller must follow visible corridor clearance instead of chasing its wall.
    Pose simulated{0, 0, 0};
    const Pose skew_goal{5.0, 1.0, 0.0};
    Pose effective = skew_goal;
    bool simulation_ok = true, simulation_adjusted = false;
    int stopped_ticks = 0;
    for (int tick = 0; tick < 1400; ++tick) {
        auto local = g;
        rect(local, simulated.x + 3.0, 7.0, -4.0, 4.0, -1);
        rect(local, -5.0, simulated.x - 1.5, -4.0, 4.0, -1);
        if (!simulation_adjusted && goal_occupied(local, skew_goal, c)) {
            const auto correction = find_adjusted_goal(local, simulated, skew_goal, robot, c);
            if (correction.found) { effective = correction.goal; simulation_adjusted = true; }
        }
        const double distance = std::hypot(effective.x - simulated.x, effective.y - simulated.y);
        if (simulation_adjusted && distance < 0.2) break;
        const double error = detail::wrap(std::atan2(effective.y - simulated.y,
                                                    effective.x - simulated.x) - simulated.yaw);
        const double nominal_v = std::abs(error) > pi / 4 ? 0.0 :
                                 std::min(c.max_vx, 0.7 * distance) * std::cos(error);
        const double nominal_w = std::clamp(0.75 * error, -c.max_wz, c.max_wz);
        const auto selected = select_command(local, simulated, effective, nominal_v, nominal_w, c);
        if (!selected.safe) {
            if (++stopped_ticks > 10) { simulation_ok = false; break; }
            continue;
        }
        stopped_ticks = 0;
        if (!swept_safe(local, simulated, selected.vx, selected.wz, c)) {
            simulation_ok = false; break;
        }
        simulated = detail::integrate(simulated, selected.vx, selected.wz, 0.1);
        if (!footprint_safe(g, simulated, c)) { simulation_ok = false; break; }
    }
    check(simulation_ok && simulated.x > 4.7 && simulation_adjusted &&
          std::hypot(effective.x - simulated.x, effective.y - simulated.y) < 0.2,
          "rolling-horizon skew-goal corridor reaches a shifted endpoint without wall deadlock");
    if (!simulation_ok || !simulation_adjusted || simulated.x < 4.7)
        std::printf("  simulation x=%.3f y=%.3f yaw=%.3f adjusted=%d target=(%.3f,%.3f)\n",
                    simulated.x, simulated.y, simulated.yaw, simulation_adjusted,
                    effective.x, effective.y);

    Config narrow = c;
    narrow.max_lateral_shift = 0.1;
    check(!find_adjusted_goal(g, robot, goal, start, narrow).found,
          "insufficient correction budget fails instead of exceeding it");
    auto disconnected = g;
    rect(disconnected, 1.0, 1.2, -1, 1, 100);
    check(!find_adjusted_goal(disconnected, robot, goal, start, c).found,
          "safe island behind solid wall is not reachable");
    auto diagonal = open_grid();
    rect(diagonal, 0.5, 0.6, -4, 0.6, 100);
    rect(diagonal, 0.6, 7, 0.5, 0.6, 100);
    rect(diagonal, 3, 4, 1, 2, 100);
    check(!find_adjusted_goal(diagonal, {-1, -1, 0}, {3, 1.2, 0}, {-2, -1, 0}, c).found,
          "touching diagonal obstacle corners cannot be crossed");
    auto end_wall = g;
    rect(end_wall, 2.0, 2.2, -1, 1, 100);
    check(!find_adjusted_goal(end_wall, robot, {2, 0, 0}, robot, c).found,
          "frontal wall cannot be solved by losing excessive longitudinal progress");
    check(!find_adjusted_goal(g, robot, {3, 0, 0}, start, c).found,
          "already free goal is not silently corrected");

    auto seed_grid = open_grid();
    rect(seed_grid, -0.2, 0.3, -0.2, 0.2, -1);
    check(!swept_safe(seed_grid, robot, 0.05, 0, c), "unknown initial footprint blocks without explicit seed option");
    Config seed = c;
    seed.seed_current_footprint_unknown = true;
    check(swept_safe(seed_grid, robot, 0.05, 0, seed), "only whole cells inside initial unpadded footprint can be seeded");
    rect(seed_grid, 0, 0.1, 0, 0.1, 100);
    check(!swept_safe(seed_grid, robot, 0.05, 0, seed), "seed exception never suppresses positive obstacle evidence");
    seed_grid = open_grid();
    rect(seed_grid, 0.5, 0.6, -0.1, 0.1, -1);
    check(!swept_safe(seed_grid, robot, 0.05, 0, seed), "seed exception does not clear nearby blind strip");

    // A fixed startup disk can admit crawl while all proportional high-speed
    // candidates exceed its boundary. Unknown space outside stays blocking.
    auto crawl_grid = open_grid();
    crawl_grid.cells.assign(crawl_grid.cells.size(), -1);
    Config crawl = c; crawl.footprint_front=.5; crawl.footprint_rear=.4;
    crawl.half_width=.3; crawl.margin=.2; crawl.max_vx=.3;
    const Pose crawl_start{.059,.023,.025};
    apply_startup_unknown(crawl_grid,crawl_start,crawl);
    const Pose crawl_goal{4.027,-1.213,0};
    const auto crawl_cmd=select_command(crawl_grid,crawl_start,crawl_goal,.3,-.16,crawl);
    check(crawl_cmd.safe && crawl_cmd.vx>0 && crawl_cmd.vx<=.3 &&
          swept_safe(crawl_grid,crawl_start,crawl_cmd.vx,crawl_cmd.wz,crawl),
          "startup disk supports configured speed with certified stopping sweep");
    check(swept_safe(crawl_grid,crawl_start,.3,0,crawl),
          "authorised startup disk covers 0.30m/s forward braking sweep");
    check(select_command(crawl_grid,crawl_start,crawl_goal,.02,0,crawl).vx<=.02,
          "crawl candidates never exceed requested speed");
    rect(crawl_grid,-.2,.3,-.2,.2,100);
    check(!select_command(crawl_grid,crawl_start,crawl_goal,.3,-.16,crawl).safe,
          "crawl cannot bypass occupied initial footprint");

    auto explore_grid=open_grid();
    explore_grid.cells.assign(explore_grid.cells.size(),-1);
    Config explore=c; explore.max_vx=.3;
    check(apply_unknown_exploration(explore_grid,5.)>0,
          "explicit exploration converts near-field unknown cells");
    const auto explore_cmd=select_command(explore_grid,{.51,0,-.26},{4.027,-1.213,0},.3,0,explore);
    check(explore_cmd.safe && explore_cmd.vx==.3,
          "exploration allows full 0.30m/s across former startup boundary");
    check(explore_grid.cells.front()==-1,"exploration leaves out-of-range unknown cells unchanged");
    rect(explore_grid,.5,.6,0,.1,100);
    apply_unknown_exploration(explore_grid,5.);
    check(!select_command(explore_grid,{.51,0,-.26},{4,0,0},.3,0,explore).safe,
          "exploration never erases observed occupied cells");
    explore_grid.valid=false;
    check(apply_unknown_exploration(explore_grid,5.)==0,
          "invalid map cannot grant unknown exploration");

    auto bad = g;
    bad.valid = false;
    check(!footprint_safe(bad, robot, c) && !select_command(bad, robot, goal, 0.1, 0, c).safe,
          "invalid map fails closed");
    bad = g; bad.cells.pop_back();
    check(!swept_safe(bad, robot, 0.1, 0, c), "truncated map fails closed");
    bad = g; bad.resolution = nan;
    check(!footprint_safe(bad, robot, c), "NaN resolution fails closed");
    bad = g; bad.width = std::numeric_limits<int>::max();
    check(!footprint_safe(bad, robot, c), "oversized map dimensions fail before arithmetic overflow");
    Config bad_config = c; bad_config.decel = 0;
    check(!valid_config(bad_config) && !swept_safe(g, robot, 0.1, 0, bad_config),
          "zero stopping deceleration cannot authorize motion");
    bad_config = c; bad_config.margin = nan;
    check(!valid_config(bad_config), "NaN config fails closed");
    check(!swept_safe(g, {nan, 0, 0}, 0.1, 0, c), "NaN pose fails closed");
    check(!swept_safe(g, robot, nan, 0, c), "NaN velocity fails closed");
    check(!select_command(g, robot, {3, nan, 0}, 0.1, 0, c).safe, "NaN target fails closed");
    check(!footprint_safe(g, {1e300, 0, 0}, c), "distant finite coordinate cannot overflow cell index");
    check(!find_adjusted_goal(g, robot, goal, goal, c).found, "zero-length segment has no correction axis");
    check(footprint_safe(g, {0, 0, 2 * pi}, c), "wrapped heading preserves footprint geometry");

    std::printf("local_navigation_selftest: %d/%d passed\n", total - failed, total);
    return failed ? 1 : 0;
}
