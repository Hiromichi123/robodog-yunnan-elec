"""String commands and command lifecycle, independently testable without ROS."""
import json
import time


def parse_command(text):
    text = text.strip()
    if not text or len(text) > 1024:
        raise ValueError('empty or oversized command')
    if text.startswith('{'):
        value = json.loads(text)
        if not isinstance(value, dict) or set(value) - {'cmd', 'seq'}:
            raise ValueError('expected {"cmd": string, "seq": nonnegative integer}')
        cmd, seq = value.get('cmd'), value.get('seq', 0)
    else:
        cmd, seq = text, 0
    if not isinstance(cmd, str) or not cmd or len(cmd) > 64:
        raise ValueError('invalid cmd')
    if type(seq) is not int or not 0 <= seq <= 2**53 - 1:
        raise ValueError('invalid seq')
    return cmd, seq


class Commands:
    def __init__(self, controller, clock=time.monotonic):
        self.controller, self.clock = controller, clock
        self.recent = {}

    def execute(self, text):
        start = self.clock()
        try:
            cmd, seq = parse_command(text)
        except (ValueError, TypeError) as exc:
            return [self.event('', 0, 4, str(exc), start)]
        key = (seq, cmd)
        if seq and key in self.recent:
            # Report current state, never replay an old enable's side effects.
            return [self.event(cmd, seq, 4, 'duplicate seq: not re-executed', start)]
        received = self.event(cmd, seq, 0, 'received', start)
        ok, reason = self.controller.command(cmd)
        code = 2 if ok else (3 if self.controller.state == 'FAULT' else 4)
        result = [received, self.event(cmd, seq, code, reason, start)]
        if seq:
            self.recent[key] = True
            if len(self.recent) > 256:
                del self.recent[next(iter(self.recent))]
        return result

    def event(self, cmd, seq, code, reason, start):
        return dict(seq=seq, cmd=cmd, code=code,
                    phase={0: 'RECEIVED', 1: 'EXECUTING', 2: 'DONE', 3: 'FAILED', 4: 'REJECTED'}[code],
                    target=None, state=self.controller.state,
                    elapsed_ms=max(0, int((self.clock() - start) * 1000)), reason=reason)
