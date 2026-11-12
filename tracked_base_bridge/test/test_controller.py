import math
from dataclasses import replace
import pytest
from tracked_base_bridge.core import Config, Mapping, Controller
from tracked_base_bridge.pwm import MockPWM
from tracked_base_bridge.protocol import Commands, parse_command


class Clock:
    now = 10.0
    def __call__(self):
        return self.now


def fixture():
    config = Config(left=Mapping(deadband=0), right=Mapping(deadband=0))
    clock = Clock()
    pwm = MockPWM(config.neutral)
    return Controller(config, pwm, clock), pwm, clock


@pytest.mark.parametrize('vx,wz,expected', [
    (.5, 0, (2000, 2000)), (-.5, 0, (1000, 1000)),
    (0, 1, (1300, 1700)), (0, -1, (1700, 1300)),
    (.25, 1, (1550, 1950)), (.25, -1, (1950, 1550)),
    (.5, 1, (1714, 2000)), (0, 0, (1500, 1500))])
def test_mix(vx, wz, expected):
    c, _, _ = fixture()
    assert c.config.mix(vx, wz) == expected


def test_mapping():
    m = Mapping(inverted=True, deadband=.1)
    assert m.pulse(1) == 1000
    assert m.pulse(-1) == 2000
    assert m.pulse(.05) == 1500
    assert m.pulse(.55) == 1250
    assert Mapping(neutral_us=1450, deadband=0).pulse(-.5) == 1225


@pytest.mark.parametrize('change', [dict(track_width_m=0), dict(timeout_s=-1),
                                     dict(max_vx_mps=math.inf), dict(max_wz_rps=math.nan),
                                     dict(max_track_speed_mps=0)])
def test_bad_config(change):
    with pytest.raises(ValueError):
        replace(Config(), **change).validate()


@pytest.mark.parametrize('mapping', [Mapping(neutral_us=1000), Mapping(reverse_us=999),
                                     Mapping(forward_us=2001), Mapping(neutral_us=1500.0),
                                     Mapping(deadband=1), Mapping(deadband=math.nan)])
def test_bad_map(mapping):
    with pytest.raises(ValueError):
        mapping.validate()


def test_enable_fresh_stop_timeout():
    c, pwm, clock = fixture()
    assert not c.velocity(.5, 0)
    assert c.command('enable')[0]
    c.tick()
    assert pwm.pulses == (1500, 1500)
    assert c.velocity(.5, 0)
    c.tick()
    assert pwm.pulses == (2000, 2000)
    assert c.command('vel_stop')[0]
    c.tick()
    assert pwm.pulses == (1500, 1500)
    clock.now += .5
    c.tick()
    assert c.state == 'DISARMED'
    assert not c.velocity(.5, 0)
    c.command('enable')
    c.tick()
    assert pwm.pulses == (1500, 1500)
    c.command('disable')
    assert c.state == 'DISARMED'


def test_late_velocity_does_not_bypass_watchdog():
    c, pwm, clock = fixture()
    c.command('enable')
    clock.now += .6
    assert not c.velocity(.5, 0)
    assert c.state == 'DISARMED'
    assert pwm.pulses == (1500, 1500)


def test_repeated_enable_does_not_extend_watchdog():
    c, _, clock = fixture()
    c.command('enable')
    clock.now += .4
    c.command('enable')
    clock.now += .11
    c.tick()
    assert c.state == 'DISARMED'


@pytest.mark.parametrize('vx,wz,extra', [(math.nan, 0, (0, 0, 0, 0)),
    (0, math.inf, (0, 0, 0, 0)), (.1, 0, (1, 0, 0, 0)),
    (.1, 0, (0, 0, math.nan, 0))])
def test_invalid_input_stops(vx, wz, extra):
    c, pwm, _ = fixture()
    c.command('enable'); c.velocity(.5, 0); c.tick()
    assert not c.velocity(vx, wz, extra)
    assert pwm.pulses == (1500, 1500)
    assert c.state == 'DISARMED'


def test_fault_latches_and_shutdown():
    c, pwm, _ = fixture()
    c.command('enable')
    def broken(*args):
        raise OSError('injected failure')
    pwm.write = broken
    c.tick()
    assert c.state == 'FAULT'
    assert not c.command('enable')[0]
    assert not c.command('disable')[0]
    c.close()
    assert not c.velocity(.5, 0)


def test_protocol():
    c, _, _ = fixture()
    commands = Commands(c)
    events = commands.execute('{"cmd":"enable","seq":1}')
    assert [e['code'] for e in events] == [0, 2]
    assert events[-1]['state'] == 'ENABLED'
    c.command('disable')
    assert commands.execute('{"cmd":"enable","seq":1}')[-1]['code'] == 4
    assert c.state == 'DISARMED'
    for cmd in ('getup', 'getdown', 'passive', 'locomotion', 'nav_on', 'zero'):
        assert commands.execute(cmd)[-1]['code'] == 4
    for cmd in ('', '{bad', '{"cmd":"enable","seq":true}', '{"cmd":3}', '{"cmd":"enable","x":1}'):
        assert commands.execute(cmd)[-1]['code'] == 4
    assert parse_command('status') == ('status', 0)
    assert commands.execute('status')[-1]['code'] == 2
