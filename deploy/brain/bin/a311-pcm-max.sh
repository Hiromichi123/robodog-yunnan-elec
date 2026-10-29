#!/bin/bash
# Yundea A31-1 (ALSA 卡名 A311) USB 喇叭声卡：上电/重插后 PCM 回出厂 30%，
# 本脚本把它拉到硬件最大（100% = raw 147 ≈ -0.94 dB）。
# 触发：a311-pcm-max.service（开机）+ udev 规则（卡每次出现，含热插拔）。
for _ in $(seq 1 20); do
    if amixer -c A311 sset PCM 100% >/dev/null 2>&1; then
        amixer -c A311 sset PCM unmute >/dev/null 2>&1
        if amixer -c A311 sget PCM 2>/dev/null | grep -q '\[100%\]'; then
            exit 0
        fi
    fi
    sleep 0.5
done
logger -t a311-pcm-max "card A311 not ready, gave up (PCM not set)"
exit 0
