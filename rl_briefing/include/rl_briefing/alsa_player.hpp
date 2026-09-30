#pragma once

#include <atomic>
#include <cstdint>
#include <string>

// ALSA 前向声明（实现在 .cpp 中链接 libasound）
extern "C" {
struct _snd_pcm;
typedef struct _snd_pcm snd_pcm_t;
}

namespace rl_briefing {

/// 低延迟 ALSA 播放器：播放单声道 16-bit PCM，内部复制为多声道，支持打断。
class AlsaPlayer {
public:
    AlsaPlayer(std::string device, int sample_rate, int channels);
    ~AlsaPlayer();

    AlsaPlayer(const AlsaPlayer&) = delete;
    AlsaPlayer& operator=(const AlsaPlayer&) = delete;

    /// 打开设备；成功返回 true（已打开则幂等返回 true）。
    bool open();

    /// 关闭设备。
    void close();

    /// 请求打断当前正在进行的 play() 调用。
    void interrupt();

    /// 播放单声道 16-bit PCM；channels_>1 时复制为 interleaved 多声道。
    /// 返回 true 表示完整播完，false 表示被打断或出错。
    bool play(const int16_t* mono, size_t frames);

    bool is_open() const { return pcm_ != nullptr; }

private:
    std::string device_;
    int sample_rate_;
    int channels_;
    snd_pcm_t* pcm_ = nullptr;
    std::atomic<bool> interrupt_{false};
};

}  // namespace rl_briefing
