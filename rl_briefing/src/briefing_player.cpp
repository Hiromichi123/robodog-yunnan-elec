// 作业交底语音播报节点（预设音频 + topic 触发）
//
// 订阅 /rl_briefing/play (std_msgs/String)：
//   "<名称>"      -> 播放 <audio_dir>/<名称>.wav（名称可带 .wav 后缀）
//   "<a,b,c>"     -> 逗号分隔，按顺序连播（网页多选就是这种）
//   "list"        -> 通过 /rl_briefing/status 列出 audio_dir 下所有 wav
//   "stop"        -> 打断当前播放
//
// 移植说明（2026-09-29）：原版跑在小脑上、输出到一块 USB 声卡（plughw:3,0），
// 那块卡现在已经不在了。大脑板载有 codec（RT5616，系统默认设备），所以：
//   · device 默认改成 "default"（要指别的就传参数）
//   · audio_dir 默认改成 /home/jinjiao/briefing_audio
//   · 补上了**逗号连播**：原版会把 "forklift,elevator" 当成一个文件名去找
// 预设 wav 支持任意采样率（内部线性插值重采样到 sample_rate）。
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include "rl_briefing/alsa_player.hpp"

#include <algorithm>
#include <atomic>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

namespace fs = std::filesystem;

namespace {

struct WavData {
    int sample_rate = 0;
    int channels = 0;
    std::vector<int16_t> mono;
};

// 极简 WAV(PCM16)解析，抽出单声道样本（多声道取第一声道）。
bool load_wav_mono(const std::string& path, WavData& out) {
    std::ifstream f(path, std::ios::binary);
    if (!f) return false;

    auto read_u16 = [&f]() -> uint16_t {
        uint16_t v = 0;
        f.read(reinterpret_cast<char*>(&v), 2);
        return v;
    };
    auto read_u32 = [&f]() -> uint32_t {
        uint32_t v = 0;
        f.read(reinterpret_cast<char*>(&v), 4);
        return v;
    };

    char riff[4];
    f.read(riff, 4);
    if (std::string(riff, 4) != "RIFF") return false;
    read_u32();
    char wave[4];
    f.read(wave, 4);
    if (std::string(wave, 4) != "WAVE") return false;

    uint16_t fmt_channels = 1;
    uint32_t fmt_sr = 48000;
    uint16_t bits = 16;
    std::vector<char> data;

    while (f) {
        char id[4];
        f.read(id, 4);
        if (!f) break;
        uint32_t size = read_u32();
        std::string cid(id, 4);
        if (cid == "fmt ") {
            read_u16();
            fmt_channels = read_u16();
            fmt_sr = read_u32();
            read_u32();
            read_u16();
            bits = read_u16();
        } else if (cid == "data") {
            data.resize(size);
            f.read(data.data(), static_cast<std::streamsize>(size));
        } else {
            f.seekg(static_cast<std::streamoff>(size), std::ios::cur);
        }
    }
    if (bits != 16) return false;

    size_t n = data.size() / 2;
    std::vector<int16_t> samples(n);
    std::memcpy(samples.data(), data.data(), n * 2);

    if (fmt_channels <= 1) {
        out.mono = std::move(samples);
    } else {
        out.mono.reserve(n / fmt_channels);
        for (size_t i = 0; i < n; i += fmt_channels) {
            out.mono.push_back(samples[i]);
        }
    }
    out.sample_rate = static_cast<int>(fmt_sr);
    out.channels = fmt_channels;
    return !out.mono.empty();
}

// 线性插值重采样（单声道 int16），用于把任意采样率 wav 转到播放器采样率。
std::vector<int16_t> resample_mono(const std::vector<int16_t>& in, int src_sr,
                                   int dst_sr) {
    if (src_sr == dst_sr || in.empty()) return in;
    double ratio = static_cast<double>(dst_sr) / src_sr;
    size_t n_out = static_cast<size_t>(in.size() * ratio);
    std::vector<int16_t> out(n_out);
    for (size_t i = 0; i < n_out; ++i) {
        double pos = i / ratio;
        size_t i0 = static_cast<size_t>(pos);
        size_t i1 = std::min(i0 + 1, in.size() - 1);
        double frac = pos - static_cast<double>(i0);
        double v = in[i0] * (1.0 - frac) + in[i1] * frac;
        out[i] = static_cast<int16_t>(v);
    }
    return out;
}

/**
 * 逗号分隔的场景名 → 列表。去掉每项首尾空白、丢掉空项。
 * 网页多选就是按点选顺序拼成 "forklift,elevator" 发过来的（见 js/main.js 的
 * `_briefingOrder.join(',')`），所以这里必须拆开逐个播 —— 原版没拆，
 * 会把整串当成一个文件名去找 "forklift,elevator.wav" 然后报 not found。
 */
std::vector<std::string> split_scenes(const std::string& s) {
    std::vector<std::string> out;
    size_t i = 0;
    while (i <= s.size()) {
        size_t j = s.find(',', i);
        if (j == std::string::npos) j = s.size();
        std::string t = s.substr(i, j - i);
        while (!t.empty() && std::isspace(static_cast<unsigned char>(t.front()))) t.erase(t.begin());
        while (!t.empty() && std::isspace(static_cast<unsigned char>(t.back()))) t.pop_back();
        if (!t.empty()) out.push_back(t);
        i = j + 1;
    }
    return out;
}

std::string join(const std::vector<std::string>& v, const char* sep = ",") {
    std::string out;
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) out += sep;
        out += v[i];
    }
    return out;
}

}  // namespace

class AudioPlayerNode : public rclcpp::Node {
public:
    AudioPlayerNode() : Node("briefing_player") {
        audio_dir_ = declare_parameter<std::string>(
            "audio_dir", "/home/jinjiao/briefing_audio");
        // 机器人的喇叭接在一块 USB 免驱声卡上（Yundea A31-1）——
        // 就是原版在小脑上用的那块，插到大脑上后是 card 2，所以这里用**卡名**而不是
        // 卡号（插拔别的 USB 设备会让号变）。原版写死 plughw:3,0 是它当时在小脑上的号。
        // 传别的设备也行：aplay -L 能列全（例如板载 codec 是 plughw:CARD=realtekrt5616co,DEV=0）。
        device_ = declare_parameter<std::string>("device", "plughw:CARD=A311,DEV=0");
        sample_rate_ = declare_parameter<int>("sample_rate", 48000);
        channels_ = declare_parameter<int>("channels", 2);
        // 软件增益。1.0 = wav 原始电平；2.0 = "200%"（现场要够响，默认按 2.0）。
        // 语音的波峰因数很高（实测 RMS 只有峰值的 1/10），只调硬件音量往往还是听不清，
        // 得在波形上做增益 —— 但不能直接乘（波峰会削顶，出爆音），见 apply_gain()。
        gain_ = declare_parameter<double>("gain", 2.0);

        player_ = std::make_unique<rl_briefing::AlsaPlayer>(
            device_, sample_rate_, channels_);

        sub_ = create_subscription<std_msgs::msg::String>(
            "/rl_briefing/play", rclcpp::QoS(10),
            [this](const std_msgs::msg::String::SharedPtr msg) {
                on_command(msg->data);
            });
        status_pub_ = create_publisher<std_msgs::msg::String>(
            "/rl_briefing/status", 10);

        // 2Hz 空闲心跳：网页靠它判断"播报节点在不在"（状态只在事件时发的话，
        // 页面点下去没声音就无从判断：是节点没起、还是喇叭没插）。
        // 播放中的进度由 play_sequence 自己发（playing: X (2/3)），心跳不掺和。
        heartbeat_ = create_wall_timer(std::chrono::milliseconds(500), [this]() {
            if (!playing_.load()) publish_status("idle");
        });

        RCLCPP_INFO(get_logger(),
                    "音频播放器就绪: device=%s sr=%d ch=%d gain=%.2f dir=%s",
                    device_.c_str(), sample_rate_, channels_, gain_,
                    audio_dir_.c_str());
    }

    ~AudioPlayerNode() override {
        stop_ = true;
        player_->interrupt();
        std::lock_guard<std::mutex> lk(mtx_);
        if (worker_.joinable()) worker_.join();
    }

private:
    void publish_status(const std::string& s) {
        auto m = std_msgs::msg::String();
        m.data = s;
        status_pub_->publish(m);
        RCLCPP_INFO(get_logger(), "[status] %s", s.c_str());
    }

    void on_command(const std::string& raw) {
        std::string cmd = raw;
        // 去掉首尾空白
        while (!cmd.empty() && (cmd.back() == ' ' || cmd.back() == '\n' ||
                                cmd.back() == '\r' || cmd.back() == '\t')) {
            cmd.pop_back();
        }
        while (!cmd.empty() && (cmd.front() == ' ' || cmd.front() == '\t')) {
            cmd.erase(cmd.begin());
        }

        if (cmd.empty()) return;

        if (cmd == "stop") {
            // 必须同时把 stop_ 置起来：worker 就是靠它判断"是我被打断了"，
            // 否则它会接着往下报 interrupted / nothing played（实测踩到过 ——
            // 按一下停止，状态里冒出三条，操作员以为出错了）。
            stop_ = true;
            player_->interrupt();
            playing_ = false;
            publish_status("stopped");
            return;
        }
        if (cmd == "list") {
            list_files();
            return;
        }

        const std::vector<std::string> names = split_scenes(cmd);
        if (names.empty()) return;

        std::lock_guard<std::mutex> lk(mtx_);
        ++gen_;
        player_->interrupt();
        if (worker_.joinable()) worker_.join();
        stop_ = false;
        const uint64_t gen = gen_;
        worker_ = std::thread([this, names, gen]() { play_sequence(names, gen); });
    }

    void list_files() {
        std::string out = "audio list:";
        std::error_code ec;
        if (!fs::is_directory(audio_dir_, ec)) {
            publish_status("audio_dir not found: " + audio_dir_);
            return;
        }
        for (const auto& e : fs::directory_iterator(audio_dir_)) {
            if (e.path().extension() == ".wav") {
                out += " " + e.path().stem().string();
            }
        }
        publish_status(out);
    }

    /** 顺序播一串场景；每个场景内部可被 stop()/新命令打断。 */
    void play_sequence(const std::vector<std::string>& names, uint64_t gen) {
        playing_ = true;
        const size_t total = names.size();
        size_t played = 0;
        for (size_t k = 0; k < total; ++k) {
            if (stop_ || gen != gen_) { playing_ = false; return; }
            // 多场景时报进度（网页把状态原文 toast 出来，操作员能看出播到第几段）
            const std::string tag = total > 1
                ? names[k] + " (" + std::to_string(k + 1) + "/" + std::to_string(total) + ")"
                : names[k];
            // 单段失败（缺文件/解码失败/开不了声卡）只报不改流程：
            // 一套交底里少一段，剩下的照播，比整条任务停掉有用。
            if (play_one(names[k], gen, tag)) ++played;
        }
        playing_ = false;
        if (gen != gen_ || stop_) return;
        // 一段都没播成时说"完成"是误导（操作员会以为播过了）—— 单独报
        if (played == 0) {
            publish_status("nothing played: " + join(names));
        } else {
            publish_status(total > 1 ? "done: " + join(names) : "done: " + names[0]);
        }
    }

    /** 播一个场景；自己负责报错与状态文案。@return 真的播完了才 true */
    bool play_one(const std::string& name_in, uint64_t gen, const std::string& tag) {
        // 兼容带 .wav 后缀的命令
        std::string name = name_in;
        if (name.size() > 4 && name.substr(name.size() - 4) == ".wav") {
            name = name.substr(0, name.size() - 4);
        }
        fs::path wav = fs::path(audio_dir_) / (name + ".wav");

        if (!fs::exists(wav)) {
            publish_status("not found: " + name);
            return false;
        }

        WavData wd;
        if (!load_wav_mono(wav.string(), wd)) {
            publish_status("wav load failed: " + name);
            return false;
        }

        if (stop_ || gen != gen_) return false;

        std::vector<int16_t> pcm = resample_mono(wd.mono, wd.sample_rate,
                                                 sample_rate_);
        apply_gain(pcm);

        if (!player_->open()) {
            publish_status("audio open failed: " + device_);
            return false;
        }
        publish_status("playing: " + tag);
        const bool ok = player_->play(pcm.data(), pcm.size());
        player_->close();
        // 被打断时（stop / 新命令顶掉）不发 done —— 上面 stop 分支已经报过 stopped
        if (gen == gen_ && !stop_ && !ok) {
            publish_status("interrupted: " + name);
        }
        return ok;
    }

    /**
     * 增益 + **软限幅**（tanh 拐点）。
     *
     * 为什么不是直接乘：语音波峰因数高（实测峰值 65%FS 而 RMS 只有 6.5%），
     * 乘 2 会让波峰冲到 130% 后被硬削 —— 听起来是"破"而不是"响"。
     * 这里超过 thr 的部分按 tanh 平滑压过去，听感是更响、不失真。
     */
    void apply_gain(std::vector<int16_t>& pcm) const {
        if (gain_ <= 0.0 || std::abs(gain_ - 1.0) < 1e-6) return;
        constexpr double kFull = 32767.0;
        constexpr double kThr = 0.90;              // 拐点（相对满量程）
        const double kn = 1.0 - kThr;
        for (int16_t& s : pcm) {
            double x = s / kFull * gain_;
            const double a = std::abs(x);
            if (a > kThr) {
                x = std::copysign(kThr + kn * std::tanh((a - kThr) / kn), x);
            }
            s = static_cast<int16_t>(std::lround(std::clamp(x, -1.0, 1.0) * kFull));
        }
    }

    std::string audio_dir_;
    std::string device_;
    int sample_rate_ = 48000;
    int channels_ = 2;
    double gain_ = 2.0;

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr status_pub_;

    std::unique_ptr<rl_briefing::AlsaPlayer> player_;
    rclcpp::TimerBase::SharedPtr heartbeat_;
    std::atomic<bool> playing_{false};   // 心跳只在空闲时发，别和进度抢话
    std::mutex mtx_;
    std::thread worker_;
    std::atomic<uint64_t> gen_{0};
    std::atomic<bool> stop_{false};
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AudioPlayerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
