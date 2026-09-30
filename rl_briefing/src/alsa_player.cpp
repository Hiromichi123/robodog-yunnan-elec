#include "rl_briefing/alsa_player.hpp"

#include <alsa/asoundlib.h>

#include <algorithm>
#include <utility>
#include <vector>

namespace rl_briefing {

AlsaPlayer::AlsaPlayer(std::string device, int sample_rate, int channels)
    : device_(std::move(device)), sample_rate_(sample_rate), channels_(channels) {}

AlsaPlayer::~AlsaPlayer() { close(); }

bool AlsaPlayer::open() {
    if (pcm_) return true;
    int rc = snd_pcm_open(&pcm_, device_.c_str(), SND_PCM_STREAM_PLAYBACK, 0);
    if (rc < 0) {
        pcm_ = nullptr;
        return false;
    }
    // USB 声卡(Yundea A31-1)固定 48kHz；plughw 会自动做采样率/格式转换
    rc = snd_pcm_set_params(pcm_, SND_PCM_FORMAT_S16_LE,
                            SND_PCM_ACCESS_RW_INTERLEAVED,
                            channels_, sample_rate_, 1, 100000 /* 100ms */);
    if (rc < 0) {
        snd_pcm_close(pcm_);
        pcm_ = nullptr;
        return false;
    }
    return true;
}

void AlsaPlayer::close() {
    if (pcm_) {
        snd_pcm_drain(pcm_);
        snd_pcm_close(pcm_);
        pcm_ = nullptr;
    }
}

void AlsaPlayer::interrupt() { interrupt_.store(true); }

bool AlsaPlayer::play(const int16_t* mono, size_t frames) {
    if (!pcm_) return false;
    interrupt_.store(false);

    const size_t period_frames = 1024;
    std::vector<int16_t> interleaved;
    if (channels_ > 1) interleaved.resize(period_frames * channels_);

    size_t pos = 0;
    while (pos < frames) {
        if (interrupt_.load()) {
            snd_pcm_drop(pcm_);
            return false;
        }
        size_t n = std::min(period_frames, frames - pos);
        snd_pcm_sframes_t w;
        if (channels_ == 1) {
            w = snd_pcm_writei(pcm_, mono + pos, static_cast<snd_pcm_uframes_t>(n));
        } else {
            for (size_t i = 0; i < n; ++i) {
                for (int c = 0; c < channels_; ++c) {
                    interleaved[i * channels_ + c] = mono[pos + i];
                }
            }
            w = snd_pcm_writei(pcm_, interleaved.data(), static_cast<snd_pcm_uframes_t>(n));
        }
        if (w < 0) {
            w = snd_pcm_recover(pcm_, w, 1);
            if (w < 0) return false;
            continue;
        }
        pos += static_cast<size_t>(w);
    }
    snd_pcm_drain(pcm_);
    return true;
}

}  // namespace rl_briefing
