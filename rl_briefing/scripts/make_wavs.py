#!/usr/bin/env python3
"""交底 wav 生成：读 config/safety_briefings.yaml，按场景合成 48kHz 单声道 PCM16 wav。

产出给 rl_briefing 的播放节点直接用（它按场景名找 <audio_dir>/<id>.wav）。
**音频不在包里面**，是可替换资源：换更好的 TTS 就重新跑这个脚本，别改代码。

两个后端（都靠 ffmpeg 转码，统一成 48k 单声道）：
  --backend edge    Microsoft edge-tts（云，中文自然）。在**能联网的机器**上跑，
                    生成完把 wav 传到板子的 ~/briefing_audio/ 即可 —— 板子不用装东西。
  --backend espeak  本地 espeak-ng（离线；音质机械，但板子上装了就能直接用）。
                    apt: sudo apt install espeak-ng

电平：每个场景**峰值归一化到 0.9 满量程（最多放大 6 倍）** —— 与原 NPU 脚本
（briefing_tts.py 里 min(0.9/peak, 6.0)）一致。edge-tts 原始输出只有 ~65%，
不归一化会明显偏轻。嫌不够响再叠播放节点的 `gain` 参数（默认 2.0，带软限幅）。

原来的 NPU 方案（voice-assistant + Matcha + RKNN）见同目录 briefing_tts.py ——
那套部署在小脑上，随重刷系统丢了，所以才有这个可移植版本。

用法:
    python3 make_wavs.py --backend edge --out ~/briefing_audio --voice zh-CN-YunjianNeural
    python3 make_wavs.py --backend espeak --out /home/jinjiao/briefing_audio
    python3 make_wavs.py --backend edge --out out --scene forklift   # 只生成一个
"""
from __future__ import annotations

import argparse
import array
import shutil
import subprocess
import sys
import tempfile
import time
import wave
from pathlib import Path

import yaml

SAMPLE_RATE = 48000      # 与播放节点默认一致
LEAD_S = 0.11            # 句首静音（弱起字防吞字）—— 与原 NPU 脚本一致
TAIL_S = 0.14            # 句尾静音（自然停顿）
NORM_TARGET = 0.9        # 峰值归一化目标（相对满量程）
NORM_MAX_GAIN = 6.0      # 归一化最多放大多少倍（防把底噪也拉满）
HERE = Path(__file__).resolve().parent
DEFAULT_YAML = HERE.parent / 'config' / 'safety_briefings.yaml'


def silence(seconds: float) -> bytes:
    return b'\x00\x00' * int(SAMPLE_RATE * seconds)


def to_pcm48k_mono(src: Path, ffmpeg: str) -> bytes:
    """任意音频 → 48k 单声道 s16le 原始 PCM。"""
    out = subprocess.run(
        [ffmpeg, '-v', 'error', '-i', str(src),
         '-f', 's16le', '-acodec', 'pcm_s16le', '-ac', '1', '-ar', str(SAMPLE_RATE), '-'],
        check=True, capture_output=True)
    return out.stdout


def synth_edge(text: str, dst_mp3: Path, voice: str, rate: str) -> None:
    import asyncio
    import edge_tts

    async def go():
        await edge_tts.Communicate(text, voice, rate=rate).save(str(dst_mp3))
    asyncio.run(go())


def synth_espeak(text: str, dst_wav: Path, voice: str, speed: int) -> None:
    subprocess.run(['espeak-ng', '-v', voice, '-s', str(speed), '-w', str(dst_wav), text],
                   check=True, capture_output=True)


def normalize_pcm16(pcm: bytes) -> tuple:
    """峰值归一化到 NORM_TARGET（最多 NORM_MAX_GAIN 倍）。返回 (新 pcm, 实际倍数)。

    pcm 是**字节**：样本要用 array('h') 解出来再改 —— 直接迭代 bytes 拿到的是 0..255，
    量出来的"峰值"是假的，改回去还会越界。
    """
    samples = array.array('h')
    samples.frombytes(pcm)
    peak = max((abs(v) for v in samples), default=0)
    if not (0 < peak < NORM_TARGET * 32767):
        return pcm, 1.0
    k = min(NORM_TARGET * 32767 / peak, NORM_MAX_GAIN)
    for i, v in enumerate(samples):
        samples[i] = max(-32768, min(32767, int(v * k)))
    return samples.tobytes(), k


def build_scene(sec: dict, out_dir: Path, args, ffmpeg: str) -> int:
    sid = sec['id']
    lines = sec.get('lines') or []
    if not lines:
        print('  ! %s 没有 lines，跳过' % sid)
        return 0

    pcm = bytearray(silence(LEAD_S))
    done = 0
    tmp = Path(tempfile.mkdtemp(prefix='tts_'))
    try:
        for i, text in enumerate(lines, 1):
            text = str(text).strip()
            if not text:
                continue
            try:
                if args.backend == 'edge':
                    f = tmp / ('%d.mp3' % i)
                    synth_edge(text, f, args.voice, args.rate)
                else:
                    f = tmp / ('%d.wav' % i)
                    synth_espeak(text, f, args.voice, args.speed)
                pcm += to_pcm48k_mono(f, ffmpeg)
                done += 1
            except Exception as exc:                      # noqa: BLE001
                print('  ! %s 第 %d 句合成失败（跳过）：%s' % (sid, i, exc))
            pcm += silence(TAIL_S)
            print('\r  %s: %d/%d 句' % (sid, i, len(lines)), end='', flush=True)
    finally:
        shutil.rmtree(tmp, ignore_errors=True)

    rate_k = 1.0
    if not args.no_normalize:
        pcm, rate_k = normalize_pcm16(bytes(pcm))

    out = out_dir / ('%s.wav' % sid)
    with wave.open(str(out), 'wb') as w:
        w.setnchannels(1)
        w.setsampwidth(2)
        w.setframerate(SAMPLE_RATE)
        w.writeframes(pcm)
    print('\r  [ok] %s  %.1fMB  %.0fs  归一化×%.2f  (%d/%d 句)'
          % (out, out.stat().st_size / 1e6, len(pcm) / 2 / SAMPLE_RATE,
             rate_k, done, len(lines)))
    return done


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument('--backend', choices=['edge', 'espeak'], default='edge')
    ap.add_argument('--out', required=True, help='wav 输出目录（板子上一般是 ~/briefing_audio）')
    ap.add_argument('--yaml', default=str(DEFAULT_YAML))
    ap.add_argument('--scene', default='all', help='场景 id（elevator/forklift/...）或 all')
    ap.add_argument('--voice', default=None,
                    help='edge: zh-CN-YunjianNeural(默认,男声播报) / espeak: cmn')
    ap.add_argument('--rate', default='-8%', help='edge 语速（交底比日常慢一点更清楚）')
    ap.add_argument('--speed', type=int, default=140, help='espeak 语速（词/分）')
    ap.add_argument('--no-normalize', action='store_true', help='不做峰值归一化')
    args = ap.parse_args()

    if args.voice is None:
        args.voice = 'zh-CN-YunjianNeural' if args.backend == 'edge' else 'cmn'

    ffmpeg = shutil.which('ffmpeg')
    if not ffmpeg:
        print('[x] 找不到 ffmpeg（用来转码成 48k 单声道）—— 装一个或加进 PATH', file=sys.stderr)
        return 2
    if args.backend == 'espeak' and not shutil.which('espeak-ng'):
        print('[x] 找不到 espeak-ng（sudo apt install espeak-ng）', file=sys.stderr)
        return 2

    doc = yaml.safe_load(Path(args.yaml).read_text(encoding='utf-8'))
    sections = doc.get('sections') or []
    if args.scene != 'all':
        sections = [s for s in sections if s.get('id') == args.scene]
        if not sections:
            print('[x] yaml 里没有场景 %s' % args.scene, file=sys.stderr)
            return 2

    out_dir = Path(args.out).expanduser()
    out_dir.mkdir(parents=True, exist_ok=True)
    print('后端=%s 声音=%s 输出=%s 场景=%d 个' % (args.backend, args.voice, out_dir, len(sections)))

    t0 = time.time()
    total = sum(build_scene(s, out_dir, args, ffmpeg) for s in sections)
    print('完成：%d 句 / %.0fs' % (total, time.time() - t0))
    print('播放节点默认读 %s；换目录用 audio_dir 参数或 launch 里的 audio_dir:=' % out_dir)
    return 0


if __name__ == '__main__':
    sys.exit(main())
