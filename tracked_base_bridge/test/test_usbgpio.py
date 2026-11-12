import sys

import pytest

from tracked_base_bridge.pwm import UsbGpioPWM, _usb_count

pytestmark = pytest.mark.skipif(sys.platform != 'linux', reason='flock-based port guard')

FIRMWARE = b'chip_gdf303, PwmMainFre_120M, software_V4.0\x00D'
ZERO4 = b'\x00' * 16
NEUTRAL = 1500


class FakeTransport:
    def __init__(self, firmware=FIRMWARE):
        self.firmware = firmware
        self.frames = []
        self.reads = 0
        self.opened = False
        self.closed = False
        self.fail_on = None   # callable(frame) -> exception

    def open(self):
        self.opened = True

    def write(self, data):
        frame = bytes(data)
        if self.fail_on is not None:
            exc = self.fail_on(frame)
            if exc is not None:
                raise exc
        self.frames.append(frame)

    def read(self, timeout=1.0, quiet=0.25):
        self.reads += 1
        return self.firmware

    def drain(self):
        pass

    def close(self):
        self.closed = True


def make(tmp_path, **overrides):
    transport = overrides.pop('transport', FakeTransport())
    kwargs = dict(serial_port='/dev/ttyACM0', group=1, channels=[1, 2],
                  neutral=(NEUTRAL, NEUTRAL), allow_hardware=True,
                  mapping_confirmed=True, transport=transport,
                  lock_dir=str(tmp_path))
    kwargs.update(overrides)
    return UsbGpioPWM(**kwargs), transport


def pin_frame(pins):
    frame = bytes([0x01, len(pins)])
    for pin in pins:
        frame += bytes([pin, 6, 0])
    return frame


def duty_frame(group, counts):
    return bytes([0x22, group]) + b''.join(c.to_bytes(4, 'little') for c in counts)


def test_guards_required_before_any_write(tmp_path):
    for flag in ('allow_hardware', 'mapping_confirmed'):
        transport = FakeTransport()
        with pytest.raises(ValueError):
            make(tmp_path, transport=transport, **{flag: False})
        assert transport.frames == []
        assert transport.closed is False


def test_init_frames_and_firmware_query(tmp_path):
    pwm, transport = make(tmp_path)
    assert transport.frames == [
        b'\x41',
        pin_frame([17, 18]),
        b'\x21\x01\x78\x00\x20\x4e\x00\x00\x30',
        duty_frame(1, [NEUTRAL, NEUTRAL, 0, 0]),
        b'\x23\x01\x01',
    ]
    assert transport.reads == 1
    assert pwm.name == 'usbgpio'
    pwm.close()


def test_groups_map_to_g17_g28(tmp_path):
    pwm, transport = make(tmp_path, group=3, channels=[3, 4])
    assert transport.frames[1] == pin_frame([27, 28])
    assert transport.frames[2] == b'\x21\x03\x78\x00\x20\x4e\x00\x00\xc0'
    assert transport.frames[3] == duty_frame(3, [0, 0, NEUTRAL, NEUTRAL])
    assert transport.frames[4] == b'\x23\x03\x01'
    pwm.close()


def test_write_is_one_atomic_duty_frame(tmp_path):
    pwm, transport = make(tmp_path)
    pwm.write(1000, 2000)
    assert transport.frames[-1] == duty_frame(1, [1000, 2000, 0, 0])
    pwm.write(2000, 1000)
    assert transport.frames[-1] == duty_frame(1, [2000, 1000, 0, 0])
    pwm.close()


def test_close_neutral_then_disable_and_idempotent(tmp_path):
    pwm, transport = make(tmp_path)
    pwm.close()
    assert transport.frames[-2:] == [duty_frame(1, [NEUTRAL, NEUTRAL, 0, 0]),
                                     b'\x23\x01\x00']
    assert transport.closed is True
    count = len(transport.frames)
    pwm.close()
    assert len(transport.frames) == count


def test_wrong_firmware_refused_before_pwm(tmp_path):
    transport = FakeTransport(firmware=b'some other CDC device')
    with pytest.raises(ValueError):
        make(tmp_path, transport=transport)
    assert transport.frames == [b'\x41']
    assert transport.closed is True


def test_write_failure_propagates(tmp_path):
    pwm, transport = make(tmp_path)
    transport.fail_on = lambda frame: OSError('injected write failure') if frame[0] == 0x22 else None
    with pytest.raises(OSError):
        pwm.write(1000, 1000)
    with pytest.raises(Exception):
        pwm.safe_stop()


def test_port_lock_rejects_second_instance(tmp_path):
    first, _ = make(tmp_path)
    with pytest.raises(OSError):
        make(tmp_path)
    first.close()


@pytest.mark.parametrize('overrides', [
    dict(group=0), dict(group=4), dict(channels=[1]), dict(channels=[1, 1]),
    dict(channels=[0, 2]), dict(channels=[1, 5]), dict(serial_port=''),
    dict(resolution=100), dict(period_counts=10000), dict(baud=1234),
])
def test_invalid_configuration_rejected(tmp_path, overrides):
    transport = FakeTransport()
    with pytest.raises(ValueError):
        make(tmp_path, transport=transport, **overrides)
    assert transport.frames == []


def test_non_50hz_configuration_rejected(tmp_path):
    # 120 MHz / 120 / 20000 = 50 Hz; changing either must be refused.
    with pytest.raises(ValueError):
        make(tmp_path, resolution=60)
    with pytest.raises(ValueError):
        make(tmp_path, period_counts=40000)


def test_pulse_conversion():
    assert _usb_count(1000, 120) == 1000
    assert _usb_count(2000, 120) == 2000
    assert _usb_count(1500, 120) == 1500
    for bad in (999, 2001, 1500.0, True):
        with pytest.raises(ValueError):
            _usb_count(bad, 120)
