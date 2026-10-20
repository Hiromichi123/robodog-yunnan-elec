#include "layer1_hal/goto_persistence.hpp"

#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <filesystem>
#include <set>
#include <stdexcept>
#include <vector>
#include <fcntl.h>
#include <unistd.h>

namespace mission {
namespace {
constexpr std::size_t kMaxBytes = 16384;
void io_error(const char* operation) {
    throw std::runtime_error(std::string(operation) + ": " + std::strerror(errno));
}
}

std::string goto_default_config_path() {
    const char* home = std::getenv("HOME");
    if (!home || !*home) throw std::runtime_error("HOME 未设置，无法定位保存文件");
    return std::string(home) + "/.config/robodog/goto_tuning.json";
}

nlohmann::json goto_config_json(const GotoConfig& config) {
    nlohmann::json result = nlohmann::json::object();
    for (const auto& spec : kGotoParameterSpecs) result[spec.name] = config.*(spec.member);
    return result;
}

GotoSavedConfig parse_goto_saved(const std::string& text) {
    if (text.size() > kMaxBytes) throw std::runtime_error("配置文件过大");
    std::vector<std::set<std::string>> keys;
    const auto doc = nlohmann::json::parse(text, [&](int, nlohmann::json::parse_event_t event,
                                                    nlohmann::json& parsed) {
        using Event = nlohmann::json::parse_event_t;
        if (event == Event::object_start) keys.emplace_back();
        if (event == Event::key && !keys.back().insert(parsed.get<std::string>()).second)
            throw std::runtime_error("配置含重复键");
        if (event == Event::object_end) keys.pop_back();
        return true;
    });
    if (!doc.is_object() || doc.size() != 3 || !doc.contains("schema_version") ||
        !doc.at("schema_version").is_number_integer() || doc.at("schema_version") != 1 ||
        !doc.contains("parameters") || !doc.at("parameters").is_object() ||
        doc.at("parameters").size() != kGotoParameterSpecs.size() ||
        !doc.contains("saved_at") || !doc.at("saved_at").is_string() ||
        doc.at("saved_at").get<std::string>().empty())
        throw std::runtime_error("保存配置版本或结构无效");
    GotoSavedConfig saved;
    saved.saved_at = doc.at("saved_at").get<std::string>();
    for (const auto& spec : kGotoParameterSpecs) {
        const auto& value = doc.at("parameters").at(spec.name);
        if (!value.is_number()) throw std::runtime_error(std::string("参数不是数字：") + spec.name);
        saved.config.*(spec.member) = value.get<double>();
    }
    if (!valid_goto_config(saved.config)) throw std::runtime_error("保存参数越界或非有限数");
    return saved;
}

bool load_goto_saved(const std::string& path, GotoSavedConfig& output) {
    const int fd = ::open(path.c_str(), O_RDONLY | O_CLOEXEC | O_NOFOLLOW | O_NONBLOCK);
    if (fd < 0) {
        if (errno == ENOENT) return false;
        io_error("读取保存配置失败");
    }
    std::string text;
    try {
        char buffer[4096];
        while (true) {
            const auto n = ::read(fd, buffer, sizeof(buffer));
            if (n < 0) { if (errno == EINTR) continue; io_error("读取配置失败"); }
            if (!n) break;
            text.append(buffer, static_cast<std::size_t>(n));
            if (text.size() > kMaxBytes) throw std::runtime_error("配置文件过大");
        }
    } catch (...) { ::close(fd); throw; }
    ::close(fd);
    output = parse_goto_saved(text);
    return true;
}

GotoSavedConfig save_goto_config(const std::string& path, const GotoConfig& config) {
    if (!valid_goto_config(config)) throw std::runtime_error("拒绝保存无效参数");
    GotoSavedConfig saved;
    saved.config = config;
    const auto now = std::time(nullptr);
    std::tm utc{};
    if (!gmtime_r(&now, &utc)) throw std::runtime_error("无法读取保存时间");
    char timestamp[32];
    std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%dT%H:%M:%SZ", &utc);
    saved.saved_at = timestamp;
    const auto text = nlohmann::json{{"schema_version", 1}, {"parameters", goto_config_json(config)},
                                    {"saved_at", saved.saved_at}}.dump(2) + "\n";
    const auto parent = std::filesystem::path(path).parent_path();
    std::filesystem::create_directories(parent);
    const int dir = ::open(parent.c_str(), O_RDONLY | O_DIRECTORY | O_CLOEXEC);
    if (dir < 0) io_error("打开配置目录失败");
    std::string temp = path + ".tmp.XXXXXX";
    int fd = ::mkstemp(temp.data());  // exclusive and 0600, same filesystem as destination
    if (fd < 0) { const int error = errno; ::close(dir); errno = error; io_error("创建临时文件失败"); }
    bool renamed = false;
    try {
        std::size_t pos = 0;
        while (pos < text.size()) {
            const auto n = ::write(fd, text.data() + pos, text.size() - pos);
            if (n < 0) { if (errno == EINTR) continue; io_error("写入配置失败"); }
            if (!n) throw std::runtime_error("写入配置未取得进展");
            pos += static_cast<std::size_t>(n);
        }
        if (::fsync(fd)) io_error("同步配置失败");
        const int closed = ::close(fd); fd = -1;
        if (closed) io_error("关闭配置失败");
        if (::rename(temp.c_str(), path.c_str())) io_error("替换配置失败");
        renamed = true;
        if (::fsync(dir)) throw std::runtime_error("配置已替换，但目录同步失败，持久性未确认");
        ::close(dir);
    } catch (...) {
        if (fd >= 0) ::close(fd);
        if (!renamed) ::unlink(temp.c_str());
        ::close(dir);
        throw;
    }
    return saved;
}

}  // namespace mission
