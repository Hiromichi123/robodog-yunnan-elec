"""50 Hz hardware PWM backends: Linux sysfs, USB-GPIO V4, and a mock.

Mock never touches hardware. Both hardware backends require
``allow_hardware`` and ``mapping_confirmed``.
"""
import os
from pathlib import Path
import time

PERIOD_NS = 20_000_000

# USB-GPIO V4 module (GD32 CDC ACM): 120 MHz PWM clock, 3 groups of 4 channels.
USB_CLOCK_HZ = 120_000_000
USB_FIRMWARE_MARKER = b'software_v4'
USB_RESOLUTION = 120          # counts per tick: 120 MHz / 120 = 1 us
USB_PERIOD_COUNTS = 20_000    # 20,000 ticks @ 1 us = 50 Hz
USB_BAUDS = {9600: 'B9600', 19200: 'B19200', 38400: 'B38400', 57600: 'B57600',
             115200: 'B115200', 230400: 'B230400', 460800: 'B460800', 921600: 'B921600'}


def _usb_count(pulse_us, resolution):
    """Convert a pulse width to module ticks (rounded)."""
    if type(pulse_us) is not int or not 1000 <= pulse_us <= 2000:
        raise ValueError('pulse must be an integer in 1000..2000 us')
    if type(resolution) is not int or resolution <= 0:
        raise ValueError('resolution must be a positive integer')
    numerator = pulse_us * USB_CLOCK_HZ + 500_000 * resolution
    return numerator // (1_000_000 * resolution)


def _pin_config_frame(pins, pin_type=6, initial_level=0):
    """0x01 + count + (pin, type, initial level) x N; type 6 = PWM output."""
    frame = bytes([0x01, len(pins)])
    for pin in pins:
        frame += bytes([pin, pin_type, initial_level])
    return frame


def _period_frame(group, resolution, period_counts, level_byte):
    """0x21 group, u16 resolution, u32 period, levels (little-endian numbers)."""
    return (bytes([0x21, group]) + resolution.to_bytes(2, 'little') +
            period_counts.to_bytes(4, 'little') + bytes([level_byte]))


def _duty_frame(group, counts):
    """0x22 group, four little-endian u32 duty counts (Px1..Px4)."""
    if len(counts) != 4 or any(type(c) is not int or c < 0 for c in counts):
        raise ValueError('exactly four nonnegative duty counts required')
    return bytes([0x22, group]) + b''.join(c.to_bytes(4, 'little') for c in counts)


def _enable_frame(group, state):
    """0x23 group, 0 = stop, 1 = run."""
    return bytes([0x23, group, 1 if state else 0])


def _acquire_port_lock(path, lock_dir=None):
    import fcntl
    import hashlib
    directory = Path(lock_dir or os.environ.get('XDG_RUNTIME_DIR', '/tmp'))
    key = hashlib.sha256(('usbgpio:' + os.path.realpath(path)).encode()).hexdigest()[:24]
    fd = os.open(directory / f'usbgpio-{key}.lock',
                 os.O_CREAT | os.O_RDWR | os.O_NOFOLLOW | os.O_CLOEXEC, 0o600)
    try:
        fcntl.flock(fd, fcntl.LOCK_EX | fcntl.LOCK_NB)
    except BaseException:
        os.close(fd)
        raise
    return fd


class SerialTransport:
    """Raw 8N1 serial link with DTR/RTS asserted (the module needs DTR to answer)."""

    def __init__(self, port, baud=115200):
        self.port, self.baud, self.fd = port, baud, None

    def open(self):
        import fcntl
        import struct
        import termios
        if self.baud not in USB_BAUDS:
            raise ValueError('unsupported baud rate')
        fd = os.open(self.port, os.O_RDWR | os.O_NOCTTY | os.O_NONBLOCK)
        try:
            attrs = termios.tcgetattr(fd)
            attrs[0] = 0
            attrs[1] = 0
            attrs[2] = termios.CS8 | termios.CREAD | termios.CLOCAL
            attrs[3] = 0
            speed = getattr(termios, USB_BAUDS[self.baud])
            attrs[4] = attrs[5] = speed
            attrs[6][termios.VMIN] = 0
            attrs[6][termios.VTIME] = 0
            termios.tcsetattr(fd, termios.TCSANOW, attrs)
            fcntl.ioctl(fd, termios.TIOCMBIS,
                        struct.pack('i', termios.TIOCM_DTR | termios.TIOCM_RTS))
        except BaseException:
            os.close(fd)
            raise
        self.fd = fd
        time.sleep(0.15)

    def write(self, data):
        if self.fd is None:
            raise RuntimeError('serial transport not open')
        view = memoryview(data)
        deadline = time.monotonic() + 0.1
        while view:
            try:
                written = os.write(self.fd, view)
            except BlockingIOError:
                written = 0
            except InterruptedError:
                continue
            if written:
                view = view[written:]
            elif time.monotonic() >= deadline:
                raise OSError('USB-PWM serial write timeout')
            else:
                time.sleep(0.002)

    def read(self, timeout=1.0, quiet=0.25):
        import select
        if self.fd is None:
            raise RuntimeError('serial transport not open')
        deadline = time.monotonic() + timeout
        last = time.monotonic()
        data = b''
        while time.monotonic() < deadline:
            wait = min(0.05, max(0.0, deadline - time.monotonic()))
            if not select.select([self.fd], [], [], wait)[0]:
                if data and time.monotonic() - last >= quiet:
                    break
                continue
            try:
                chunk = os.read(self.fd, 256)
            except (BlockingIOError, InterruptedError):
                continue
            if chunk:
                data += chunk
                last = time.monotonic()
            else:
                time.sleep(0.005)
        return data

    def drain(self):
        if self.fd is None:
            return
        while True:
            try:
                if not os.read(self.fd, 256):
                    return
            except (BlockingIOError, InterruptedError):
                return

    def close(self):
        if self.fd is not None:
            fd, self.fd = self.fd, None
            os.close(fd)


def pulse_ns(value):
    if type(value) is not int or not 1000 <= value <= 2000:
        raise ValueError('pulse must be an integer in 1000..2000 us')
    return value * 1000


class MockPWM:
    name = 'mock'

    def __init__(self, neutral):
        self.neutral = neutral
        self.pulses = neutral
        self.writes = 0

    def write(self, left, right):
        pulse_ns(left)
        pulse_ns(right)
        self.pulses = (left, right)
        self.writes += 1

    def safe_stop(self):
        self.write(*self.neutral)

    def close(self):
        self.safe_stop()


class SysfsPWM:
    name = 'sysfs'

    def __init__(self, chips, channels, neutral, *, allow_hardware=False,
                 mapping_confirmed=False, root='/sys/class/pwm', lock_dir=None):
        if allow_hardware is not True or mapping_confirmed is not True:
            raise ValueError('hardware requires allow_hardware and mapping_confirmed')
        import fcntl
        self._fcntl = fcntl
        self.neutral = tuple(neutral)
        for value in self.neutral:
            pulse_ns(value)
        if len(chips) != 2 or len(channels) != 2 or len(neutral) != 2:
            raise ValueError('exactly two PWM channels required')
        self.root = Path(root).resolve()
        self.paths, self.chips, self.channels = [], [], tuple(channels)
        self.owned, self.locks = [], []
        self.closed = False
        for chip, channel in zip(chips, channels):
            if not isinstance(chip, str) or not chip.startswith('pwmchip') or not chip[7:].isdigit():
                raise ValueError('explicit pwmchipN names required')
            if type(channel) is not int or channel < 0:
                raise ValueError('explicit nonnegative channel required')
            chip_path = self.root / chip
            if channel >= int((chip_path / 'npwm').read_text()):
                raise ValueError('channel outside npwm')
            self.chips.append(chip_path)
            self.paths.append(chip_path / ('pwm' + str(channel)))
        identities = [(p.resolve(), n) for p, n in zip(self.chips, channels)]
        if len(set(identities)) != 2:
            raise ValueError('left and right PWM channels must differ')
        if any(p.exists() for p in self.paths):
            raise ValueError('refuse to take over already exported PWM channel')
        for chip in self.chips:
            for name in ('export', 'unexport'):
                if not os.access(chip / name, os.W_OK):
                    raise PermissionError(str(chip / name))
        # Per-channel locks prevent overlapping pairs in cooperating instances.
        directory = Path(lock_dir or os.environ.get('XDG_RUNTIME_DIR', '/tmp'))
        try:
            for chip, channel in sorted(identities, key=str):
                import hashlib
                key = hashlib.sha256(f'{chip}:{channel}'.encode()).hexdigest()[:24]
                fd = os.open(directory / f'tracked-pwm-{key}.lock',
                             os.O_CREAT | os.O_RDWR | os.O_NOFOLLOW | os.O_CLOEXEC, 0o600)
                try:
                    fcntl.flock(fd, fcntl.LOCK_EX | fcntl.LOCK_NB)
                except BaseException:
                    os.close(fd)
                    raise
                self.locks.append(fd)
            if any(p.exists() for p in self.paths):
                raise ValueError('PWM exported while acquiring lock')
            for chip, channel, path in zip(self.chips, channels, self.paths):
                self._put(chip / 'export', channel)
                self.owned.append((chip, channel, path))
                deadline = time.monotonic() + 1.0
                while not (path / 'enable').exists():
                    if time.monotonic() >= deadline:
                        raise TimeoutError('PWM export did not appear')
                    time.sleep(0.01)
                self._put(path / 'enable', 0)
                self._put(path / 'duty_cycle', 0)
                self._put(path / 'period', PERIOD_NS)
                self._put(path / 'polarity', 'normal')
            self.write(*self.neutral)
            for path in self.paths:
                self._put(path / 'enable', 1)
        except BaseException:
            self.close()
            raise

    def _put(self, path, value):
        path.write_text(str(value))

    def write(self, left, right):
        values = (pulse_ns(left), pulse_ns(right))
        if self.closed:
            raise RuntimeError('PWM backend closed')
        try:
            for path, value in zip(self.paths, values):
                self._put(path / 'duty_cycle', value)
        except Exception:
            self.safe_stop()
            raise

    def safe_stop(self):
        # Attempt both sides even if one has failed. Disable only if neutral write fails.
        errors = []
        for (_, _, path), neutral in zip(self.owned, self.neutral):
            try:
                self._put(path / 'duty_cycle', pulse_ns(neutral))
            except Exception as exc:
                errors.append(exc)
                try:
                    self._put(path / 'enable', 0)
                except Exception as disable_exc:
                    errors.append(disable_exc)
        if errors:
            raise RuntimeError('PWM stop failed: ' + '; '.join(map(str, errors)))

    def close(self):
        if self.closed:
            return
        errors = []
        try:
            self.safe_stop()
        except Exception as exc:
            errors.append(exc)
        for chip, channel, path in reversed(self.owned):
            try:
                self._put(path / 'enable', 0)
                self._put(chip / 'unexport', channel)
            except Exception as exc:
                errors.append(exc)
        self.owned.clear()
        self.closed = True
        for fd in self.locks:
            os.close(fd)
        self.locks.clear()
        if errors:
            raise RuntimeError('PWM cleanup failed: ' + '; '.join(map(str, errors)))


class UsbGpioPWM:
    """Two channels of one USB-GPIO V4 PWM group, 50 Hz, 1000..2000 us.

    Both sides share one ``0x22`` duty frame, so a pair update is atomic on
    the wire. Init order is: verify firmware, configure the two pins as PWM,
    set period, write neutral duty, enable the group.
    """

    name = 'usbgpio'

    def __init__(self, serial_port, group, channels, neutral, *,
                 allow_hardware=False, mapping_confirmed=False, baud=115200,
                 resolution=USB_RESOLUTION, period_counts=USB_PERIOD_COUNTS,
                 transport=None, lock_dir=None, require_firmware=True):
        if allow_hardware is not True or mapping_confirmed is not True:
            raise ValueError('hardware requires allow_hardware and mapping_confirmed')
        if not isinstance(serial_port, str) or not serial_port:
            raise ValueError('serial_port required')
        if type(group) is not int or not 1 <= group <= 3:
            raise ValueError('PWM group must be an integer in 1..3')
        if (len(channels) != 2 or any(type(c) is not int or not 1 <= c <= 4 for c in channels) or
                channels[0] == channels[1]):
            raise ValueError('two distinct PWM channels in 1..4 required')
        if type(baud) is not int or baud not in USB_BAUDS:
            raise ValueError('unsupported baud rate')
        if type(resolution) is not int or not 1 <= resolution <= 65535:
            raise ValueError('resolution must be an integer in 1..65535')
        if type(period_counts) is not int or not 1 <= period_counts <= 0xFFFFFFFF:
            raise ValueError('period_counts must be an integer in 1..2^32-1')
        frequency = USB_CLOCK_HZ / resolution / period_counts
        if abs(frequency - 50.0) > 0.5:
            raise ValueError('resolution and period must give 50 Hz, got %.3f Hz' % frequency)
        self.serial_port, self.group, self.channels = serial_port, group, tuple(channels)
        self.resolution, self.period_counts = resolution, period_counts
        self.neutral = tuple(neutral)
        if len(self.neutral) != 2:
            raise ValueError('exactly two neutral pulse widths required')
        self.neutral_counts = self._counts(*self.neutral)
        # G17..G28 map to groups 1..3, channels 1..4 (P1_1 = G17).
        self.pins = tuple(16 + 4 * (group - 1) + channel for channel in channels)
        self.level_byte = sum(1 << (channel - 1) for channel in channels) << 4
        self.closed = False
        self.lock = None
        self.transport = transport if transport is not None else SerialTransport(serial_port, baud)
        self.lock = _acquire_port_lock(serial_port, lock_dir)
        try:
            self.transport.open()
            if require_firmware:
                self._verify_firmware()
            self._send(_pin_config_frame(self.pins))
            self._send(_period_frame(group, resolution, period_counts, self.level_byte))
            self._send(self._duty(self.neutral_counts))
            self._send(_enable_frame(group, 1))
        except BaseException:
            try:
                self._cleanup()
            except Exception:
                pass
            raise

    def _verify_firmware(self):
        self.transport.write(bytes([0x41]))
        reply = self.transport.read(timeout=1.0)
        if USB_FIRMWARE_MARKER not in reply.lower():
            raise ValueError('USB-GPIO V4 firmware not recognized: %r' % reply[:64])

    def _counts(self, left, right):
        counts = [0, 0, 0, 0]
        for channel, pulse in zip(self.channels, (left, right)):
            value = _usb_count(pulse, self.resolution)
            if value > self.period_counts:
                raise ValueError('pulse exceeds PWM period')
            counts[channel - 1] = value
        return counts

    def _duty(self, counts):
        return _duty_frame(self.group, counts)

    def _send(self, frame):
        if self.closed:
            raise RuntimeError('PWM backend closed')
        self.transport.drain()
        self.transport.write(frame)

    def write(self, left, right):
        self._send(self._duty(self._counts(left, right)))

    def safe_stop(self):
        self._send(self._duty(list(self.neutral_counts)))

    def _cleanup(self):
        errors = []
        try:
            self.transport.close()
        except Exception as exc:
            errors.append(exc)
        if self.lock is not None:
            try:
                os.close(self.lock)
            except Exception as exc:
                errors.append(exc)
            self.lock = None
        if errors:
            raise RuntimeError('USB-PWM cleanup failed: ' + '; '.join(map(str, errors)))

    def close(self):
        if self.closed:
            return
        errors = []
        try:
            self.safe_stop()
        except Exception as exc:
            errors.append(exc)
        try:
            self._send(_enable_frame(self.group, 0))
        except Exception as exc:
            errors.append(exc)
        try:
            self.transport.close()
        except Exception as exc:
            errors.append(exc)
        self.closed = True
        if self.lock is not None:
            try:
                os.close(self.lock)
            except Exception as exc:
                errors.append(exc)
            self.lock = None
        if errors:
            raise RuntimeError('USB-PWM cleanup failed: ' + '; '.join(map(str, errors)))
