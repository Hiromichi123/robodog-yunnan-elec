import sys
from pathlib import Path
import pytest
from tracked_base_bridge.pwm import SysfsPWM, pulse_ns, PERIOD_NS

pytestmark = pytest.mark.skipif(sys.platform != 'linux', reason='Linux sysfs and flock tests')


class FakePWM(SysfsPWM):
    events = None
    fail_right_once = False

    def _put(self, path, value):
        self.events.append((str(path), value))
        if path.name == 'export':
            p = path.parent / ('pwm' + str(value))
            p.mkdir()
            for name in ('enable', 'duty_cycle', 'period', 'polarity'):
                (p / name).write_text('0')
        elif path.name == 'unexport':
            p = path.parent / ('pwm' + str(value))
            for child in p.iterdir(): child.unlink()
            p.rmdir()
        else:
            if self.fail_right_once and path.parent.parent.name == 'pwmchip1' and path.name == 'duty_cycle':
                self.fail_right_once = False
                raise OSError('injected right failure')
            super()._put(path, value)


def tree(tmp_path):
    for n in (0, 1):
        p = tmp_path / f'pwmchip{n}'
        p.mkdir()
        for name, value in [('npwm', '1'), ('export', ''), ('unexport', '')]:
            (p / name).write_text(value)
    return dict(chips=['pwmchip0', 'pwmchip1'], channels=[0, 0], neutral=(1450, 1550),
                allow_hardware=True, mapping_confirmed=True, root=str(tmp_path), lock_dir=str(tmp_path))


def test_unconfirmed_zero_writes(tmp_path):
    kw = tree(tmp_path)
    FakePWM.events = []
    for flag in ('mapping_confirmed', 'allow_hardware'):
        with pytest.raises(ValueError): FakePWM(**{**kw, flag: False})
    assert FakePWM.events == []


def test_init_order_and_units(tmp_path):
    FakePWM.events = []
    pwm = FakePWM(**tree(tmp_path))
    events = FakePWM.events
    assert PERIOD_NS == 20_000_000
    assert pulse_ns(1000) == 1_000_000
    enable_positions = [i for i, (p, v) in enumerate(events) if p.endswith('/enable') and v == 1]
    neutral_positions = [i for i, (p, v) in enumerate(events) if p.endswith('/duty_cycle') and v in (1450000, 1550000)]
    assert max(neutral_positions) < min(enable_positions)
    assert len([1 for p, v in events if p.endswith('/period') and v == PERIOD_NS]) == 2
    pwm.write(1000, 2000)
    assert (tmp_path/'pwmchip0/pwm0/duty_cycle').read_text() == '1000000'
    assert (tmp_path/'pwmchip1/pwm0/duty_cycle').read_text() == '2000000'
    pwm.close(); pwm.close()
    assert not (tmp_path/'pwmchip0/pwm0').exists()


def test_occupied_duplicate_and_invalid_channels(tmp_path):
    FakePWM.events = []
    kw = tree(tmp_path)
    for patch in [dict(chips=['pwmchip0', 'pwmchip0']), dict(channels=[0, 1]), dict(chips=['', 'pwmchip1'])]:
        with pytest.raises((ValueError, FileNotFoundError)): FakePWM(**{**kw, **patch})
    (tmp_path/'pwmchip0/pwm0').mkdir()
    with pytest.raises(ValueError): FakePWM(**kw)
    assert FakePWM.events == []


def test_single_side_failure_attempts_both_neutrals(tmp_path):
    FakePWM.events = []
    pwm = FakePWM(**tree(tmp_path))
    pwm.fail_right_once = True
    with pytest.raises(OSError): pwm.write(2000, 2000)
    assert (tmp_path/'pwmchip0/pwm0/duty_cycle').read_text() == '1450000'
    assert (tmp_path/'pwmchip1/pwm0/duty_cycle').read_text() == '1550000'
    pwm.close()


def test_partial_init_cleanup(tmp_path):
    FakePWM.events = []
    kw = tree(tmp_path)
    class Broken(FakePWM):
        def _put(self, path, value):
            if path.name == 'period' and path.parent.parent.name == 'pwmchip1':
                raise OSError('period failure')
            super()._put(path, value)
    with pytest.raises(OSError): Broken(**kw)
    assert not (tmp_path/'pwmchip0/pwm0').exists()
    assert not (tmp_path/'pwmchip1/pwm0').exists()


@pytest.mark.parametrize('value', [999, 2001, 1500.0, True])
def test_pulse_rejection(value):
    with pytest.raises(ValueError): pulse_ns(value)
