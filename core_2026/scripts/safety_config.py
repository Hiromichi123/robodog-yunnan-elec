"""Startup-only task safety configuration. No ROS imports and no process control."""
import copy
from contextlib import contextmanager
import hashlib
import json
import math
import os
from pathlib import Path
import tempfile
import threading

SCHEMA_VERSION = 3
SOFT_FIELDS = {"soft_buffer_enabled", "hard_margin", "buffer_max_vx", "buffer_max_wz"}
POLICY = {
    'sensor_source': 'lidar',
    'calibration_required': False,
    'self_filter': {'half_length': .55, 'half_width': .35,
                    'min_z': -.30, 'max_z': .15, 'min_range_m': .60},
}
# group, name, label, unit, default, min, max, step, advanced
_SPECS = [
    ('control', 'max_vx', '最大前进速度', 'm/s', .15, .01, .5, .01, False),
    ('control', 'max_wz', '最大转向速度', 'rad/s', .35, .01, 1., .01, False),
    ('control', 'margin', '期望缓冲间距', 'm', .15, 0., 1., .01, False),
    ('control', 'soft_buffer_enabled', '启用可消耗缓冲区', '', True, 0., 1., 1., False),
    ('control', 'hard_margin', '车身外硬保护距离', 'm', .05, 0., .2, .01, False),
    ('control', 'buffer_max_vx', '缓冲区最大前进速度', 'm/s', .30, .01, .5, .01, False),
    ('control', 'buffer_max_wz', '缓冲区最大转向速度', 'rad/s', .45, .01, 1., .01, False),
    ('control', 'max_lateral_shift', '目标最大侧向修正', 'm', 1.5, 0., 3., .05, False),
    ('control', 'max_longitudinal_loss', '目标最大纵向退让', 'm', .2, 0., 1., .01, False),
    ('control', 'footprint_front', '车体前向长度', 'm', .5, .01, 3., .01, True),
    ('control', 'footprint_rear', '车体后向长度', 'm', .4, .01, 3., .01, True),
    ('control', 'half_width', '车体半宽', 'm', .32, .01, 2., .01, True),
    ('control', 'reaction_s', '反应时间', 's', .35, .01, 3., .01, True),
    ('control', 'decel', '线制动减速度', 'm/s²', .3, .01, 5., .01, True),
    ('control', 'angular_decel', '角制动减速度', 'rad/s²', .5, .01, 10., .01, True),
    ('control', 'timeout_s', '安全地图超时', 's', .5, .05, 1., .01, True),
    ('perception', 'ground_z', '启动导航系地面高度', 'm', -.35, -2., 2., .01, True),
    ('perception', 'obstacle_min_height', '最低障碍高度', 'm', .06, .01, .5, .01, True),
    ('perception', 'obstacle_max_height', '最高障碍高度', 'm', .72, .1, 2., .01, True),
    ('perception', 'free_ttl_s', '自由空间证据有效期', 's', .8, .1, 2., .05, True),
    ('perception', 'floor_ttl_s', '地面证据有效期', 's', 1.5, .1, 3., .05, True),
    ('perception', 'max_observation_age_s', '最大观测年龄', 's', .4, .05, 1., .01, True),
    ('perception', 'max_pose_gap_s', '位姿最大插值间隔', 's', .2, .02, .5, .01, True),
    ('perception', 'max_range_m', '最大感知距离', 'm', 5., .5, 5., .1, True),
]
FIELDS = [dict(zip(('group', 'name', 'label', 'unit', 'default', 'min', 'max', 'step', 'advanced'), s),
               description='启动时加载；无人工标定门禁，仍检查实时数据及足迹，参数应符合实际机体与制停能力。') for s in _SPECS]
for _field in FIELDS:
    _field['type'] = 'boolean' if _field['name'] == 'soft_buffer_enabled' else 'number'
    _field['description'] = {
        'margin': '车身外期望保持的总间距，已包含硬保护距离；不是在硬保护外再加一圈。软缓冲开启时允许低速消耗。',
        'soft_buffer_enabled': '开启后可在硬保护之外消耗缓冲区用于转向、绕行与脱离；关闭后整个期望间距按硬边界处理。',
        'hard_margin': '真实车身外禁止侵入的保护距离；不得大于期望缓冲间距。5cm为工程初值，仍需按实机误差设置。',
        'buffer_max_vx': '消耗缓冲区时的前进速度上限；同时受最大前进速度和完整制停检查约束。',
        'buffer_max_wz': '消耗缓冲区时的转向速度上限；同时受最大转向速度和完整制停检查约束。',
    }.get(_field['name'], _field['description'])
_LOCK = threading.RLock()


class ConfigError(ValueError):
    pass


class ConflictError(ConfigError):
    pass


def config_path():
    return Path.home() / '.config' / 'robodog' / 'local_safety.json'


def defaults():
    result = {'mode': 'enforce', 'control': {}, 'perception': {}}
    for field in FIELDS:
        result[field['group']][field['name']] = field['default']
    return result


def validate(config, *, legacy=False):
    if not isinstance(config, dict) or set(config) != {'mode', 'control', 'perception'}:
        raise ConfigError('配置必须包含且仅包含 mode/control/perception')
    if config['mode'] != 'enforce':
        raise ConfigError('任务通道避障固定开启，仅允许 enforce 模式')
    result = {'mode': config['mode'], 'control': {}, 'perception': {}}
    for group in ('control', 'perception'):
        fields = [f for f in FIELDS if f['group'] == group and not (legacy and f['name'] in SOFT_FIELDS)]
        if not isinstance(config[group], dict) or set(config[group]) != {f['name'] for f in fields}:
            raise ConfigError(f'{group} 参数缺失或包含不支持的字段')
        for f in fields:
            value = config[group][f['name']]
            if f['type'] == 'boolean':
                if type(value) is not bool:
                    raise ConfigError(f"{f['label']} 必须是布尔值")
                result[group][f['name']] = value
                continue
            if type(value) not in (int, float) or not math.isfinite(value) or not f['min'] <= value <= f['max']:
                raise ConfigError(f"{f['label']} 必须是 {f['min']}～{f['max']} 的有限数值")
            result[group][f['name']] = float(value)
    p, c = result['perception'], result['control']
    if not legacy and c['hard_margin'] > c['margin']:
        raise ConfigError('硬保护距离不得大于期望缓冲间距')
    if p['obstacle_min_height'] >= p['obstacle_max_height']:
        raise ConfigError('最低障碍高度必须小于最高障碍高度')
    if p['max_pose_gap_s'] > p['max_observation_age_s']:
        raise ConfigError('位姿插值间隔不能超过观测年龄上限')
    if p['max_observation_age_s'] > c['timeout_s']:
        raise ConfigError('观测年龄上限不能超过安全地图超时')
    if min(p['free_ttl_s'], p['floor_ttl_s']) < p['max_observation_age_s']:
        raise ConfigError('证据有效期不能短于观测年龄上限')
    return result


def _revision(config, schema_version):
    content = {'schema_version': schema_version, 'config': validate(config, legacy=schema_version < 3)}
    if schema_version >= 2:
        content['policy'] = POLICY
    canonical = json.dumps(content, sort_keys=True, separators=(',', ':'), allow_nan=False)
    return hashlib.sha256(canonical.encode()).hexdigest()


def revision(config):
    return _revision(config, SCHEMA_VERSION)


def document(config, saved=True):
    config = validate(config)
    return {'schema_version': SCHEMA_VERSION, 'revision': revision(config), 'config': config,
            'policy': copy.deepcopy(POLICY), 'saved': saved}


def strict_json(text):
    def pairs(items):
        result = {}
        for k, v in items:
            if k in result:
                raise ConfigError('重复 JSON 字段: ' + k)
            result[k] = v
        return result
    def constant(value):
        raise ConfigError('不支持非有限 JSON 数值: ' + value)
    try:
        return json.loads(text, object_pairs_hook=pairs, parse_constant=constant)
    except (ValueError, UnicodeError) as exc:
        raise ConfigError(str(exc)) from exc


def load(path=None, *, missing_ok=True, allow_legacy=True):
    path = Path(path) if path is not None else config_path()
    try:
        raw = path.read_bytes()
    except FileNotFoundError:
        if missing_ok:
            return document(defaults(), saved=False)
        raise ConfigError('启动快照不存在')
    if len(raw) > 32768:
        raise ConfigError('配置文件过大')
    data = strict_json(raw)
    if not isinstance(data, dict) or type(data.get('schema_version')) is not int:
        raise ConfigError('配置文件结构无效，请核查文件，不会自动关闭保护')
    version = data['schema_version']
    if version not in (1, 2, SCHEMA_VERSION):
        raise ConfigError('不支持的避障配置版本')
    keys = {'schema_version', 'revision', 'config', 'saved'}
    if version >= 2:
        keys.add('policy')
    if set(data) != keys:
        raise ConfigError('配置文件结构无效，请核查文件，不会自动关闭保护')
    if data['revision'] != _revision(data['config'], version) or data['saved'] is not True:
        raise ConfigError('配置摘要不一致或保存标识无效')
    if version < SCHEMA_VERSION:
        if version >= 2 and data['policy'] != POLICY:
            raise ConfigError('旧版避障策略与当前程序不一致')
        if not allow_legacy:
            raise ConfigError('旧版避障启动快照不可复用，请停止旧链路并重新启动')
        # Migrate only in memory: GET/start never rewrites the user's saved values.
        values = validate(data['config'], legacy=True)
        for name in SOFT_FIELDS:
            values['control'][name] = defaults()['control'][name]
        values['control']['hard_margin'] = min(values['control']['hard_margin'], values['control']['margin'])
        return document(values)
    if json.dumps(data['policy'], sort_keys=True) != json.dumps(POLICY, sort_keys=True):
        raise ConfigError('避障策略与当前程序不一致，请重新启动链路')
    return document(data['config'])


def response(path=None):
    return {'ok': True, **load(path), 'defaults': defaults(), 'fields': copy.deepcopy(FIELDS),
            'calibration': {'required': False, 'validated': False,
                            'reason': '雷达单源；不设人工标定门禁，仍检查雷达、位姿、时间戳、坐标及足迹有效性'}}


@contextmanager
def file_lock(path):
    with _LOCK:
        path.parent.mkdir(parents=True, exist_ok=True)
        with path.with_suffix(path.suffix + '.lock').open('a+b') as handle:
            if os.name == 'nt':
                import msvcrt
                handle.seek(0, 2)
                if handle.tell() == 0:
                    handle.write(b'0'); handle.flush()
                handle.seek(0)
                msvcrt.locking(handle.fileno(), msvcrt.LK_LOCK, 1)
            else:
                import fcntl
                fcntl.flock(handle, fcntl.LOCK_EX)
            try:
                yield
            finally:
                if os.name == 'nt':
                    handle.seek(0); msvcrt.locking(handle.fileno(), msvcrt.LK_UNLCK, 1)
                else:
                    fcntl.flock(handle, fcntl.LOCK_UN)


def atomic_write(path, data):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = None
    try:
        with tempfile.NamedTemporaryFile(mode='w', encoding='utf-8', dir=path.parent,
                                         prefix='.' + path.name, delete=False) as out:
            temporary = out.name
            json.dump(data, out, ensure_ascii=False, indent=2, allow_nan=False)
            out.write('\n'); out.flush(); os.fsync(out.fileno())
        os.replace(temporary, path)
        temporary = None
        if os.name != 'nt':
            fd = os.open(path.parent, os.O_RDONLY | os.O_DIRECTORY)
            try:
                os.fsync(fd)
            finally:
                os.close(fd)
    finally:
        if temporary:
            try:
                os.unlink(temporary)
            except FileNotFoundError:
                pass


def save(config, expected_revision, path=None):
    path = Path(path) if path is not None else config_path()
    data = document(config)
    with file_lock(path):
        if expected_revision != load(path)['revision']:
            raise ConflictError('配置已被其他页面修改，请重新读取后再保存')
        atomic_write(path, data)
    return response(path)


def freeze(directory):
    """Immutable by content identity; the live file is never passed to a child."""
    data = load()
    data['saved'] = True
    path = Path(directory) / ('safety-' + data['revision'] + '.json')
    with file_lock(path):
        if path.exists():
            if load(path, missing_ok=False, allow_legacy=False)['revision'] != data['revision']:
                raise ConfigError('已有启动快照不一致')
        else:
            atomic_write(path, data)
    return path, data


def startup():
    path = os.environ.get('ROBODOG_SAFETY_SNAPSHOT')
    return load(path, missing_ok=False, allow_legacy=False) if path else load()


def control_parameters(data):
    if data['config']['mode'] != 'enforce':
        raise ConfigError('任务通道避障固定开启，仅允许 enforce 模式')
    return {'safety_mode': data['config']['mode'],
            'safety_config_revision': data['revision'],
            'safety_unknown_as_free': True,
            'safety_unknown_exploration_range_m': data['config']['perception']['max_range_m'],
            **{'safety_' + k: v for k, v in data['config']['control'].items()}}


def perception_parameters(data):
    return {'config_revision': data['revision'],
            'max_return_range_m': 10.0,
            'self_half_length': POLICY['self_filter']['half_length'],
            'self_half_width': POLICY['self_filter']['half_width'],
            'self_min_z': POLICY['self_filter']['min_z'],
            'self_max_z': POLICY['self_filter']['max_z'],
            'min_range_m': POLICY['self_filter']['min_range_m'],
            **data['config']['perception']}
