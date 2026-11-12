"""Differential tracked drive; no ROS or hardware dependencies."""
from dataclasses import dataclass, field
import math
import time


@dataclass(frozen=True)
class Mapping:
    reverse_us: int = 1000
    neutral_us: int = 1500
    forward_us: int = 2000
    inverted: bool = False
    deadband: float = 0.02

    def validate(self):
        values = (self.reverse_us, self.neutral_us, self.forward_us)
        if any(type(v) is not int for v in values):
            raise ValueError('pulse widths must be integer microseconds')
        if not 1000 <= self.reverse_us < self.neutral_us < self.forward_us <= 2000:
            raise ValueError('require 1000 <= reverse < neutral < forward <= 2000 us')
        if not math.isfinite(self.deadband) or not 0 <= self.deadband < 1:
            raise ValueError('deadband must be finite in [0, 1)')
        if type(self.inverted) is not bool:
            raise ValueError('inverted must be boolean')

    def pulse(self, normalized):
        value = -normalized if self.inverted else normalized
        value = max(-1.0, min(1.0, value))
        if abs(value) <= self.deadband:
            return self.neutral_us
        value = math.copysign((abs(value) - self.deadband) / (1 - self.deadband), value)
        span = self.forward_us - self.neutral_us if value > 0 else self.neutral_us - self.reverse_us
        return round(self.neutral_us + value * span)


@dataclass(frozen=True)
class Config:
    track_width_m: float = 0.4
    max_track_speed_mps: float = 0.5
    max_vx_mps: float = 0.5
    max_wz_rps: float = 1.0
    timeout_s: float = 0.5
    left: Mapping = field(default_factory=Mapping)
    right: Mapping = field(default_factory=Mapping)

    def validate(self):
        for name in ('track_width_m', 'max_track_speed_mps', 'max_vx_mps', 'max_wz_rps', 'timeout_s'):
            value = getattr(self, name)
            if not math.isfinite(value) or value <= 0:
                raise ValueError(name + ' must be finite and positive')
        self.left.validate()
        self.right.validate()

    @property
    def neutral(self):
        return self.left.neutral_us, self.right.neutral_us

    def mix(self, vx, wz, unsupported=(0.0, 0.0, 0.0, 0.0)):
        if not all(math.isfinite(v) for v in (vx, wz, *unsupported)):
            raise ValueError('non-finite velocity')
        if any(v != 0 for v in unsupported):
            raise ValueError('only linear.x and angular.z are supported')
        scale = max(1.0, abs(vx) / self.max_vx_mps, abs(wz) / self.max_wz_rps)
        vx, wz = vx / scale, wz / scale
        left = vx - wz * self.track_width_m / 2
        right = vx + wz * self.track_width_m / 2
        scale = max(1.0, abs(left) / self.max_track_speed_mps, abs(right) / self.max_track_speed_mps)
        left, right = left / scale, right / scale
        return (self.left.pulse(left / self.max_track_speed_mps),
                self.right.pulse(right / self.max_track_speed_mps))


class Controller:
    """Single-threaded controller. A FAULT requires process restart after diagnosis."""

    def __init__(self, config, backend, clock=time.monotonic):
        config.validate()
        self.config, self.backend, self.clock = config, backend, clock
        self.state, self.fault = 'DISARMED', ''
        self.target = config.neutral
        self.last_velocity = None
        self.enabled_at = None
        self.reason = 'startup'
        self.closed = False
        self._write(self.target)

    def _write(self, pulses):
        try:
            self.backend.write(*pulses)
        except Exception as exc:
            self.fault = str(exc)
            self.state = 'FAULT'
            self.target = self.config.neutral
            self.last_velocity = None
            try:
                self.backend.safe_stop()
            except Exception:
                pass
            return False
        return True

    def stop(self, disarm=True, reason='stop'):
        self.target = self.config.neutral
        self.last_velocity = None
        self.enabled_at = self.clock() if not disarm else None
        self.reason = reason
        if self.state != 'FAULT' and disarm:
            self.state = 'DISARMED'
        return self._write(self.target)

    def command(self, command):
        if self.closed:
            return False, 'controller closed'
        if command == 'status':
            return True, self.reason
        if command in ('disable', 'vel_stop'):
            ok = self.stop(disarm=command == 'disable', reason=command)
            return ok and self.state != 'FAULT', self.fault or command
        if command != 'enable':
            return False, 'unsupported command (dog posture/RL commands are not applicable)'
        if self.state == 'FAULT':
            return False, self.fault
        # Idempotent enable must not reset the watchdog or resurrect an old target.
        if self.state == 'ENABLED':
            return True, 'already enabled'
        if not self.stop(reason='enable awaiting fresh velocity'):
            return False, self.fault
        self.state = 'ENABLED'
        self.enabled_at = self.clock()
        return True, self.reason

    def velocity(self, vx, wz, unsupported=(0.0, 0.0, 0.0, 0.0)):
        if self.closed:
            return False
        try:
            pulses = self.config.mix(vx, wz, unsupported)
        except (ValueError, TypeError, OverflowError) as exc:
            self.stop(reason=str(exc))
            return False
        if self.state != 'ENABLED':
            return False
        now = self.clock()
        reference = self.last_velocity if self.last_velocity is not None else self.enabled_at
        if now - reference >= self.config.timeout_s:
            self.stop(reason='velocity timeout')
            return False
        self.target, self.last_velocity = pulses, now
        self.reason = 'velocity accepted'
        return True

    def tick(self):
        if self.closed or self.state != 'ENABLED':
            return
        reference = self.last_velocity if self.last_velocity is not None else self.enabled_at
        if self.clock() - reference >= self.config.timeout_s:
            self.stop(reason='velocity timeout')
        else:
            self._write(self.target)

    def close(self):
        if self.closed:
            return
        self.stop(reason='shutdown')
        self.closed = True
        try:
            self.backend.close()
        except Exception as exc:
            self.state, self.fault = 'FAULT', str(exc)
