#!/usr/bin/env python3
"""Real-hardware USB-PWM neutral self-check. Not part of pytest.

Outputs only the configured neutral pulse (default 1500 us) on the two chosen
channels, holds it, then writes neutral again and stops the group.

    python3 test/usbgpio_neutral_check.py --yes [--seconds 3]

Wiring prerequisite: ESCs/motors disconnected or independently secured.
"""
import argparse
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from tracked_base_bridge.pwm import (SerialTransport, UsbGpioPWM,
                                     USB_RESOLUTION, USB_PERIOD_COUNTS)


class LoggingTransport(SerialTransport):
    """Print every byte sent to the module."""
    def write(self, data):
        print('TX', bytes(data).hex(' '))
        super().write(data)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--port', required=True, help='/dev/serial/by-id/... path')
    parser.add_argument('--group', type=int, default=1, choices=(1, 2, 3))
    parser.add_argument('--left', type=int, default=1, choices=(1, 2, 3, 4))
    parser.add_argument('--right', type=int, default=2, choices=(1, 2, 3, 4))
    parser.add_argument('--baud', type=int, default=115200)
    parser.add_argument('--seconds', type=float, default=3.0)
    parser.add_argument('--yes', action='store_true',
                        help='required: confirms no ESC/motor is driven by this test')
    args = parser.parse_args()
    if not args.yes or args.left == args.right or args.seconds <= 0:
        parser.error('--yes required; left/right must differ; seconds > 0')
    pwm = UsbGpioPWM(args.port, args.group, [args.left, args.right], (1500, 1500),
                     allow_hardware=True, mapping_confirmed=True, baud=args.baud,
                     resolution=USB_RESOLUTION, period_counts=USB_PERIOD_COUNTS,
                     transport=LoggingTransport(args.port, args.baud))
    try:
        print('neutral %d us on group %d channels %d/%d; holding %.1f s'
              % (1500, args.group, args.left, args.right, args.seconds))
        pwm.write(1500, 1500)
        import time
        time.sleep(args.seconds)
    finally:
        pwm.close()
    print('closed: neutral then group output off')


if __name__ == '__main__':
    main()
