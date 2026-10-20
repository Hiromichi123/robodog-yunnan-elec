#include "layer0_common/goto_config.hpp"
#include <atomic>
#include <cstdio>
#include <limits>
#include <thread>

int main() {
    using namespace mission;
    int total = 0, failed = 0;
    auto check = [&](bool ok, const char* label) {
        ++total; if (!ok) ++failed;
        std::printf("%s %s\n", ok ? "PASS" : "FAIL", label);
    };
    GotoConfigStore store;
    check(valid_goto_config(store.snapshot().config), "defaults valid");
    check(store.snapshot().config.max_vx == 0.4 && store.snapshot().config.kp_vx == 0.7,
          "latest speed defaults retained");
    for (const auto& spec : kGotoParameterSpecs) {
        check(store.apply({{spec.name, spec.min}}).empty(), "lower bound accepted");
        check(store.apply({{spec.name, spec.max}}).empty(), "upper bound accepted");
        const auto before = store.snapshot();
        check(!store.apply({{"kp_yaw", 0.8}, {spec.name, spec.max + 1}}).empty(), "invalid batch rejected");
        check(store.snapshot().revision == before.revision, "failed batch leaves all fields unchanged");
        check(!store.apply({{spec.name, std::numeric_limits<double>::quiet_NaN()}}).empty(), "NaN rejected");
        check(!store.apply({{spec.name, std::numeric_limits<double>::infinity()}}).empty(), "Inf rejected");
    }
    check(!store.apply({{"unknown", 0.1}}).empty(), "unknown key rejected");
    check(!store.apply({{"kp_vx", 0.5}, {"kp_vx", 0.6}}).empty(), "duplicate key rejected");
    auto rev = store.snapshot().tolerance_revision;
    store.apply({{"kp_vx", 0.7}});
    check(store.snapshot().tolerance_revision == rev, "gain change preserves tolerance revision");
    store.apply({{"tol_xy", 0.4}}); store.apply({{"tol_xy", 0.5}});
    check(store.snapshot().tolerance_revision == rev + 2, "tolerance roundtrip remains observable between ticks");
    const auto before = store.snapshot().revision;
    check(store.apply({}).empty() && store.snapshot().revision == before, "empty patch is no-op");
    store.apply({{"kp_vx", 0.5}, {"kp_yaw", 0.5}});
    std::atomic<bool> stop{false}, torn{false};
    std::thread reader([&] {
        while (!stop) {
            const auto c = store.snapshot().config;
            if (c.kp_vx != c.kp_yaw) torn = true;
        }
    });
    for (int i = 0; i < 10000; ++i) {
        double v = i % 2 ? 0.5 : 0.9;
        store.apply({{"kp_vx", v}, {"kp_yaw", v}});
    }
    stop = true; reader.join();
    check(!torn, "concurrent snapshots never tear a config batch");
    std::printf("%d checks, %d failed\n", total, failed);
    return failed ? 1 : 0;
}
