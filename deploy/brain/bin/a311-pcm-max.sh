#!/bin/bash
# Yundea A31-1 (ALSA 卡名 A311) USB 声卡：
#   · PCM（播放）上电/重插后回出厂 30% → 拉到硬件最大（100% = raw 147 ≈ -0.94 dB）；
#   · Mic（采集）出厂是 0% → 拉到 100%，否则 ASR 只能录到数字静音。
# 触发：a311-pcm-max.service（开机）+ udev 规则（卡每次出现，含热插拔）。
for _ in $(seq 1 20); do
    if amixer -c A311 sset PCM 100% >/dev/null 2>&1; then
        amixer -c A311 sset PCM unmute >/dev/null 2>&1
        # 采集音量与开关；老固件/别的卡可能没有 Mic 控件，失败不影响播放设置
        amixer -c A311 sset Mic 100% >/dev/null 2>&1
        amixer -c A311 sset Mic unmute >/dev/null 2>&1
        if amixer -c A311 sget PCM 2>/dev/null | grep -q '\[100%\]'; then
            exit 0
        fi
    fi
    sleep 0.5
done
logger -t a311-pcm-max "card A311 not ready, gave up (PCM/Mic not set)"
exit 0
