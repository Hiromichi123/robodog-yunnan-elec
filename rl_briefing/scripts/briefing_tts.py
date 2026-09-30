#!/usr/bin/env python3
"""交底语音合成脚本：读 safety_briefings.yaml 的某个专项，逐句 NPU TTS 合成，拼接成 48kHz 单声道 wav。

复用 voice-assistant 的 MatchaRknnTts：
    文本 -> 前端(lexicon/espeak, CPU) -> Matcha 声学模型(CPU ONNX Runtime)
         -> Vocos 声码器(NPU RKNN) -> 16kHz 音频

本脚本把 16kHz 重采样到 48kHz、峰值归一化、句间补静音垫，输出供 C++ ALSA
播放器直接播放的 wav(48kHz / 16-bit / mono)。

用法:
    /opt/voice-assistant/.venv/bin/python briefing_tts.py \
        --section forklift --out /home/kickpi/.cache/briefing_tts/forklift.wav \
        --config /opt/voice-assistant/config/safety_briefings.yaml
    # --section all 连播全部专项
"""
from __future__ import annotations

import argparse
import sys
import wave
from pathlib import Path

# 让本脚本能 import voice_assistant(部署在 /opt/voice-assistant)
_VA_SRC = "/opt/voice-assistant/src"
if _VA_SRC not in sys.path:
    sys.path.insert(0, _VA_SRC)

import numpy as np  # noqa: E402
import yaml  # noqa: E402

from voice_assistant.audio.utils import resample  # noqa: E402
from voice_assistant.tts.matcha_rknn_backend import MatchaRknnTts  # noqa: E402

SAMPLE_RATE_OUT = 48000   # USB 声卡(Yundea A31-1)只支持 48000Hz
LEAD_S = 0.11             # 句首静音垫(弱起字防吞字)
TAIL_S = 0.14             # 句尾静音垫(自然停顿)


def synth_section(tts, lines, speed):
    """逐句合成并拼接,返回 float32 单声道(48kHz)或 None。"""
    lead = np.zeros(int(SAMPLE_RATE_OUT * LEAD_S), dtype=np.float32)
    tail = np.zeros(int(SAMPLE_RATE_OUT * TAIL_S), dtype=np.float32)
    buf = []
    for text in lines:
        text = text.strip()
        if not text:
            continue
        res = tts.synthesize(text, speed=speed)
        s = resample(res.samples, res.sample_rate, SAMPLE_RATE_OUT)
        # 峰值归一化:Matcha 对句首字幅偏小(如"在的"),归一化保证每句音量一致
        peak = float(np.max(np.abs(s))) if len(s) else 0.0
        if 0.0 < peak < 0.9:
            s = s * min(0.9 / peak, 6.0)
        buf.append(lead)
        buf.append(s)
        buf.append(tail)
    if not buf:
        return None
    return np.concatenate(buf).astype(np.float32)


def write_wav(path, samples, sr):
    pcm = (np.clip(samples, -1.0, 1.0) * 32767.0).astype(np.int16)
    with wave.open(str(path), "wb") as wf:
        wf.setnchannels(1)
        wf.setsampwidth(2)
        wf.setframerate(sr)
        wf.writeframes(pcm.tobytes())


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--section", required=True, help="专项 id 或 'all'")
    ap.add_argument("--out", required=True, help="输出 wav 路径")
    ap.add_argument("--config", default="/opt/voice-assistant/config/safety_briefings.yaml")
    ap.add_argument("--model-dir", default="/opt/voice-assistant/models/tts/matcha-rknn")
    ap.add_argument("--speed", type=float, default=None, help="语速倍率,默认用 yaml 里的 speed")
    args = ap.parse_args()

    cfg = yaml.safe_load(Path(args.config).read_text(encoding="utf-8"))
    sections = cfg.get("sections", []) or []
    by_id = {s.get("id"): s for s in sections}

    if args.section == "all":
        chosen = sections
    else:
        s = by_id.get(args.section)
        if s is None:
            print(f"未知专项: {args.section}", file=sys.stderr)
            return 2
        chosen = [s]

    lines = []
    for s in chosen:
        lines.extend(s.get("lines", []) or [])

    speed = args.speed if args.speed is not None else cfg.get("speed", 1.0)

    tts = MatchaRknnTts(args.model_dir, speed=speed, acoustic="ort")
    try:
        samples = synth_section(tts, lines, speed)
        if samples is None:
            print("没有可合成的文本", file=sys.stderr)
            return 3
        out = Path(args.out)
        out.parent.mkdir(parents=True, exist_ok=True)
        write_wav(out, samples, SAMPLE_RATE_OUT)
        print(f"OK {out} ({len(samples) / SAMPLE_RATE_OUT:.1f}s)")
    finally:
        tts.close()
    return 0


if __name__ == "__main__":
    sys.exit(main())
