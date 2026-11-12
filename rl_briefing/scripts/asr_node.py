#!/usr/bin/env python3
"""离线语音转写节点（Vosk + ALSA arecord）。

给作业交底语音包补上"听"的能力：麦克风采集 → 离线 Vosk 中文模型 → 话题。

话题（全部 std_msgs/msg/String，和 /rl_briefing/* 保持同一套简单协议）：
  /rl_asr/control   上位机 → 本节点   start | stop | status
  /rl_asr/text      本节点 → 上位机   一句话的最终转写（可能为空，空不发）
  /rl_asr/partial   本节点 → 上位机   实时中间结果，最终结果出来后清空（发空串）
  /rl_asr/status    本节点 → 上位机   listening | stopped | error: <原因>
                                      0.5s 心跳；网页靠它判断节点是否在线

为什么用 arecord 子进程而不是 sounddevice/PortAudio：
  板子上只要 ALSA 工具可用就行，不引入 PortAudio 编译依赖；`plughw:` 设备名
  自带格式/采样率转换，模型固定要 16k 单声道。

麦克风音量：Yundea A31-1（ALSA 卡名 A311）的 Mic 采集出厂是 0%，只听得到
静音。本节点启动/每次开始聆听时会尝试 `amixer -c A311 sset Mic 100%`
（best-effort，失败只告警）。系统级持久化见 deploy/brain/bin/a311-pcm-max.sh。

模型不进包（可替换资源），默认 ~/asr_models/vosk-model-small-cn-0.22。
"""
from __future__ import annotations

import fcntl
import json
import os
import re
import subprocess
import threading
import time
from collections import deque

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

try:
    from vosk import Model, KaldiRecognizer, SetLogLevel
    _VOSK_IMPORT_ERROR = None
except Exception as _exc:  # noqa: BLE001 - 缺依赖时节点要能起来并报状态，而不是直接崩
    Model = KaldiRecognizer = SetLogLevel = None
    _VOSK_IMPORT_ERROR = _exc


_DEFAULT_MODEL = os.path.expanduser("~/asr_models/vosk-model-small-cn-0.22")
_DEFAULT_DEVICE = "plughw:CARD=A311,DEV=0"

# Vosk 的中文结果按字/词用空格分隔；只去掉"两个汉字之间"的空格，
# 数字、英文单词、标点之间的空格保留。
_CJK_SPACE_RE = re.compile(r"(?<=[㐀-鿿])\s+(?=[㐀-鿿])")


class AsrNode(Node):
    def __init__(self) -> None:
        super().__init__("asr_node")

        self.declare_parameter("model_path", _DEFAULT_MODEL)
        self.declare_parameter("device", _DEFAULT_DEVICE)
        self.declare_parameter("sample_rate", 16000)
        self.declare_parameter("auto_start", True)
        self.declare_parameter("status_period_s", 0.5)
        self.declare_parameter("partial_interval_s", 0.3)
        # 环境噪声常被 Vosk 切成单字（"了"/"人"/"上"…）。最终结果短于这个
        # 字数就不发，网页只显示有意义的句子；要收单字命令可设 1。
        self.declare_parameter("min_text_chars", 2)
        self.declare_parameter("set_mic_volume", True)
        self.declare_parameter("mixer_card", "A311")
        self.declare_parameter("mic_control", "Mic")
        self.declare_parameter("mic_volume", 100)

        self._model_path = os.path.expanduser(
            self.get_parameter("model_path").value)
        self._device = str(self.get_parameter("device").value)
        self._sample_rate = int(self.get_parameter("sample_rate").value)
        self._partial_interval = float(
            self.get_parameter("partial_interval_s").value)
        self._min_text_chars = int(
            self.get_parameter("min_text_chars").value)
        self._set_mic_volume = bool(
            self.get_parameter("set_mic_volume").value)
        self._mixer_card = str(self.get_parameter("mixer_card").value)
        self._mic_control = str(self.get_parameter("mic_control").value)
        self._mic_volume = int(self.get_parameter("mic_volume").value)

        self._model = None
        self._state = "stopped"
        self._state_lock = threading.Lock()
        self._lifecycle_lock = threading.Lock()

        self._proc = None
        self._reader = None
        self._stop_event = threading.Event()   # 让当前采集循环退出
        self._desired = False                  # 操作员希望"在听"

        # 单实例保护：ASR 可能既被 dog_web 拉起、又被手动 launch 拉起。
        # 两个实例抢同一个麦克风只会让后一个 arecord 报 busy，这里用文件锁让
        # 后来者安静退出（exit 0，ros2 launch 不会因此停掉其它节点）。
        self._lock_file = self._acquire_instance_lock()
        if self._lock_file is None:
            self.get_logger().error(
                "已有另一个 asr_node 在运行，本实例退出（不重复占用麦克风）")
            raise SystemExit(0)

        self._text_pub = self.create_publisher(String, "/rl_asr/text", 10)
        self._partial_pub = self.create_publisher(
            String, "/rl_asr/partial", 10)
        self._status_pub = self.create_publisher(
            String, "/rl_asr/status", 10)

        self.create_subscription(
            String, "/rl_asr/control", self._on_control, 10)
        self.create_timer(
            float(self.get_parameter("status_period_s").value),
            self._heartbeat)

        self.get_logger().info(
            f"ASR 节点就绪: model={self._model_path} "
            f"device={self._device} sr={self._sample_rate}")

        if bool(self.get_parameter("auto_start").value):
            self.start_listening(reason="auto_start")

    # ── 状态与发布 ────────────────────────────────────────────────

    @staticmethod
    def _acquire_instance_lock():
        """进程级单实例锁；拿不到返回 None。"""
        try:
            handle = open("/tmp/rl_asr_node.lock", "w")  # noqa: SIM115
            fcntl.flock(handle, fcntl.LOCK_EX | fcntl.LOCK_NB)
            handle.write(str(os.getpid()))
            handle.flush()
            return handle
        except OSError:
            return None

    def _publish(self, pub, text: str) -> None:
        msg = String()
        msg.data = text
        pub.publish(msg)

    def _set_state(self, state: str) -> None:
        with self._state_lock:
            changed = state != self._state
            self._state = state
        if changed:
            self.get_logger().info(f"[status] {state}")
            self._publish(self._status_pub, state)

    def _current_state(self) -> str:
        with self._state_lock:
            return self._state

    def _heartbeat(self) -> None:
        # 事件状态（error）也照心跳重发，网页断开重连后能立刻看到；
        # 网页侧按内容去重，不会刷屏。
        self._publish(self._status_pub, self._current_state())

    # ── 模型 / 麦克风 ─────────────────────────────────────────────

    def _ensure_model(self) -> bool:
        if self._model is not None:
            return True
        if _VOSK_IMPORT_ERROR is not None:
            self._set_state(f"error: vosk import failed: {_VOSK_IMPORT_ERROR}")
            return False
        if not os.path.isdir(self._model_path):
            self._set_state(f"error: model not found: {self._model_path}")
            return False
        try:
            SetLogLevel(-1)   # 关掉 Kaldi 每次加载刷屏的 LOG
            self._model = Model(self._model_path)
        except Exception as exc:  # noqa: BLE001
            self._set_state(f"error: model load failed: {exc}")
            return False
        self.get_logger().info(f"Vosk 模型已加载: {self._model_path}")
        return True

    def _ensure_mic_volume(self) -> None:
        if not self._set_mic_volume:
            return
        try:
            res = subprocess.run(
                ["amixer", "-c", self._mixer_card, "sset",
                 self._mic_control, f"{self._mic_volume}%"],
                stdout=subprocess.DEVNULL, stderr=subprocess.PIPE,
                timeout=5, text=True)
            if res.returncode != 0:
                self.get_logger().warn(
                    f"设置麦克风音量失败({self._mixer_card}/"
                    f"{self._mic_control}): {(res.stderr or '').strip()}")
        except Exception as exc:  # noqa: BLE001
            self.get_logger().warn(f"设置麦克风音量异常: {exc}")

    # ── 采集生命周期 ──────────────────────────────────────────────

    def start_listening(self, reason: str = "") -> None:
        with self._lifecycle_lock:
            if not self._ensure_model():
                return
            old = self._reader
            if old is not None and old.is_alive():
                # 先让上一轮干净退出，避免两条采集流抢同一个麦克风。
                self._desired = False
                self._stop_event.set()
                self._terminate_proc()
                old.join(timeout=2.0)
            self._desired = True
            self._stop_event.clear()
            self._reader = threading.Thread(
                target=self._reader_loop, name="asr-reader", daemon=True)
            self._reader.start()
        self.get_logger().info(
            "开始聆听" + (f"（{reason}）" if reason else ""))

    def stop_listening(self) -> None:
        with self._lifecycle_lock:
            self._desired = False
            self._stop_event.set()
            self._terminate_proc()
        self._set_state("stopped")
        self._publish(self._partial_pub, "")

    def _terminate_proc(self) -> None:
        proc = self._proc
        if proc is None:
            return
        try:
            proc.terminate()
        except Exception:  # noqa: BLE001
            pass

    def _drain_stderr(self, proc, lines: deque) -> None:
        try:
            for raw in iter(proc.stderr.readline, b""):
                line = raw.decode("utf-8", "replace").strip()
                if line:
                    lines.append(line)
        except Exception:  # noqa: BLE001
            pass

    def _reader_loop(self) -> None:
        backoff = 1.0
        while (rclpy.ok() and self._desired
               and not self._stop_event.is_set()):
            cmd = [
                "arecord", "-q", "-D", self._device,
                "-f", "S16_LE", "-r", str(self._sample_rate),
                "-c", "1", "-t", "raw",
            ]
            try:
                proc = subprocess.Popen(
                    cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                    bufsize=0)
            except Exception as exc:  # noqa: BLE001
                self._set_state(f"error: arecord start failed: {exc}")
                time.sleep(backoff)
                backoff = min(backoff * 2.0, 10.0)
                continue

            self._proc = proc
            err_lines: deque = deque(maxlen=6)
            threading.Thread(
                target=self._drain_stderr, args=(proc, err_lines),
                daemon=True).start()
            self._ensure_mic_volume()
            recognizer = KaldiRecognizer(self._model, self._sample_rate)
            self._set_state("listening")
            backoff = 1.0
            last_partial_at = 0.0
            last_partial = ""

            while (self._desired and not self._stop_event.is_set()):
                data = proc.stdout.read(4000)   # 0.125s @16k mono s16
                if not data:
                    break
                try:
                    final = recognizer.AcceptWaveform(data)
                except Exception as exc:  # noqa: BLE001
                    self._set_state(f"error: recognizer failed: {exc}")
                    break
                if final:
                    text = self._clean_text(
                        json.loads(recognizer.Result()).get("text", ""))
                    if text and len(text) >= self._min_text_chars:
                        self._publish(self._text_pub, text)
                    # 只有界面上真的显示过中间结果才清空，避免静音时反复发空串
                    if last_partial:
                        self._publish(self._partial_pub, "")
                    last_partial = ""
                else:
                    now = time.monotonic()
                    if now - last_partial_at >= self._partial_interval:
                        last_partial_at = now
                        try:
                            part = self._clean_text(
                                json.loads(
                                    recognizer.PartialResult()
                                ).get("partial", ""))
                        except Exception:  # noqa: BLE001
                            part = ""
                        if part != last_partial:
                            last_partial = part
                            self._publish(self._partial_pub, part)

            # 采集流结束：正常停止时不再补发最终结果，避免"停止后突然冒一句"。
            try:
                proc.terminate()
            except Exception:  # noqa: BLE001
                pass
            try:
                proc.wait(timeout=2.0)
            except Exception:  # noqa: BLE001
                try:
                    proc.kill()
                except Exception:  # noqa: BLE001
                    pass
            self._proc = None

            if self._desired and not self._stop_event.is_set():
                rc = proc.returncode
                tail = " | ".join(err_lines)
                self._set_state(
                    f"error: arecord exited rc={rc}"
                    + (f": {tail}" if tail else ""))
                time.sleep(backoff)
                backoff = min(backoff * 2.0, 10.0)

        self._publish(self._partial_pub, "")
        if not self._desired:
            self._set_state("stopped")

    @staticmethod
    def _clean_text(text: str) -> str:
        text = (text or "").strip()
        if not text:
            return ""
        text = _CJK_SPACE_RE.sub("", text)
        return re.sub(r"\s{2,}", " ", text)

    # ── 控制话题 ──────────────────────────────────────────────────

    def _on_control(self, msg: String) -> None:
        cmd = (msg.data or "").strip().lower()
        if cmd in ("start", "listen", "on"):
            self.start_listening(reason="web")
        elif cmd in ("stop", "off"):
            self.stop_listening()
        elif cmd in ("status", "info", "list"):
            self._publish(self._status_pub, self._current_state())
        elif cmd:
            self.get_logger().warn(
                f"未知控制命令: {msg.data!r}（支持 start/stop/status）")

    def destroy_node(self) -> bool:
        self._desired = False
        self._stop_event.set()
        self._terminate_proc()
        reader = self._reader
        if reader is not None and reader.is_alive():
            reader.join(timeout=2.0)
        if self._lock_file is not None:
            try:
                self._lock_file.close()   # 关闭即释放 flock
            except Exception:  # noqa: BLE001
                pass
            self._lock_file = None
        return super().destroy_node()


def main(args=None) -> None:
    rclpy.init(args=args)
    node = AsrNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
