# generated from rosidl_generator_py/resource/_idl.py.em
# with input from messages:msg/SmartCarCalibStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SmartCarCalibStatus(type):
    """Metaclass of message 'SmartCarCalibStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('messages')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'messages.msg.SmartCarCalibStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__smart_car_calib_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__smart_car_calib_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__smart_car_calib_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__smart_car_calib_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__smart_car_calib_status

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SmartCarCalibStatus(metaclass=Metaclass_SmartCarCalibStatus):
    """Message class 'SmartCarCalibStatus'."""

    __slots__ = [
        '_stamp',
        '_time_boot_ms',
        '_point_id',
        '_sweep_index',
        '_sweep_count',
        '_valid_count',
        '_invalid_count',
        '_v_center_avg',
        '_yaw_rate_avg',
        '_kappa_avg',
        '_radius_est',
        '_target_rpm',
        '_servo_pwm_us',
        '_state',
        '_sweep_enabled',
        '_yaw_sign_inverted',
    ]

    _fields_and_field_types = {
        'stamp': 'builtin_interfaces/Time',
        'time_boot_ms': 'uint32',
        'point_id': 'uint32',
        'sweep_index': 'uint32',
        'sweep_count': 'uint32',
        'valid_count': 'uint32',
        'invalid_count': 'uint32',
        'v_center_avg': 'float',
        'yaw_rate_avg': 'float',
        'kappa_avg': 'float',
        'radius_est': 'float',
        'target_rpm': 'int16',
        'servo_pwm_us': 'uint16',
        'state': 'uint8',
        'sweep_enabled': 'uint8',
        'yaw_sign_inverted': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())
        self.time_boot_ms = kwargs.get('time_boot_ms', int())
        self.point_id = kwargs.get('point_id', int())
        self.sweep_index = kwargs.get('sweep_index', int())
        self.sweep_count = kwargs.get('sweep_count', int())
        self.valid_count = kwargs.get('valid_count', int())
        self.invalid_count = kwargs.get('invalid_count', int())
        self.v_center_avg = kwargs.get('v_center_avg', float())
        self.yaw_rate_avg = kwargs.get('yaw_rate_avg', float())
        self.kappa_avg = kwargs.get('kappa_avg', float())
        self.radius_est = kwargs.get('radius_est', float())
        self.target_rpm = kwargs.get('target_rpm', int())
        self.servo_pwm_us = kwargs.get('servo_pwm_us', int())
        self.state = kwargs.get('state', int())
        self.sweep_enabled = kwargs.get('sweep_enabled', int())
        self.yaw_sign_inverted = kwargs.get('yaw_sign_inverted', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.stamp != other.stamp:
            return False
        if self.time_boot_ms != other.time_boot_ms:
            return False
        if self.point_id != other.point_id:
            return False
        if self.sweep_index != other.sweep_index:
            return False
        if self.sweep_count != other.sweep_count:
            return False
        if self.valid_count != other.valid_count:
            return False
        if self.invalid_count != other.invalid_count:
            return False
        if self.v_center_avg != other.v_center_avg:
            return False
        if self.yaw_rate_avg != other.yaw_rate_avg:
            return False
        if self.kappa_avg != other.kappa_avg:
            return False
        if self.radius_est != other.radius_est:
            return False
        if self.target_rpm != other.target_rpm:
            return False
        if self.servo_pwm_us != other.servo_pwm_us:
            return False
        if self.state != other.state:
            return False
        if self.sweep_enabled != other.sweep_enabled:
            return False
        if self.yaw_sign_inverted != other.yaw_sign_inverted:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value

    @builtins.property
    def time_boot_ms(self):
        """Message field 'time_boot_ms'."""
        return self._time_boot_ms

    @time_boot_ms.setter
    def time_boot_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'time_boot_ms' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'time_boot_ms' field must be an unsigned integer in [0, 4294967295]"
        self._time_boot_ms = value

    @builtins.property
    def point_id(self):
        """Message field 'point_id'."""
        return self._point_id

    @point_id.setter
    def point_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'point_id' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'point_id' field must be an unsigned integer in [0, 4294967295]"
        self._point_id = value

    @builtins.property
    def sweep_index(self):
        """Message field 'sweep_index'."""
        return self._sweep_index

    @sweep_index.setter
    def sweep_index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sweep_index' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'sweep_index' field must be an unsigned integer in [0, 4294967295]"
        self._sweep_index = value

    @builtins.property
    def sweep_count(self):
        """Message field 'sweep_count'."""
        return self._sweep_count

    @sweep_count.setter
    def sweep_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sweep_count' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'sweep_count' field must be an unsigned integer in [0, 4294967295]"
        self._sweep_count = value

    @builtins.property
    def valid_count(self):
        """Message field 'valid_count'."""
        return self._valid_count

    @valid_count.setter
    def valid_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'valid_count' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'valid_count' field must be an unsigned integer in [0, 4294967295]"
        self._valid_count = value

    @builtins.property
    def invalid_count(self):
        """Message field 'invalid_count'."""
        return self._invalid_count

    @invalid_count.setter
    def invalid_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'invalid_count' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'invalid_count' field must be an unsigned integer in [0, 4294967295]"
        self._invalid_count = value

    @builtins.property
    def v_center_avg(self):
        """Message field 'v_center_avg'."""
        return self._v_center_avg

    @v_center_avg.setter
    def v_center_avg(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_center_avg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'v_center_avg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._v_center_avg = value

    @builtins.property
    def yaw_rate_avg(self):
        """Message field 'yaw_rate_avg'."""
        return self._yaw_rate_avg

    @yaw_rate_avg.setter
    def yaw_rate_avg(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw_rate_avg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw_rate_avg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw_rate_avg = value

    @builtins.property
    def kappa_avg(self):
        """Message field 'kappa_avg'."""
        return self._kappa_avg

    @kappa_avg.setter
    def kappa_avg(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'kappa_avg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'kappa_avg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._kappa_avg = value

    @builtins.property
    def radius_est(self):
        """Message field 'radius_est'."""
        return self._radius_est

    @radius_est.setter
    def radius_est(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'radius_est' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'radius_est' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._radius_est = value

    @builtins.property
    def target_rpm(self):
        """Message field 'target_rpm'."""
        return self._target_rpm

    @target_rpm.setter
    def target_rpm(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'target_rpm' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'target_rpm' field must be an integer in [-32768, 32767]"
        self._target_rpm = value

    @builtins.property
    def servo_pwm_us(self):
        """Message field 'servo_pwm_us'."""
        return self._servo_pwm_us

    @servo_pwm_us.setter
    def servo_pwm_us(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'servo_pwm_us' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'servo_pwm_us' field must be an unsigned integer in [0, 65535]"
        self._servo_pwm_us = value

    @builtins.property
    def state(self):
        """Message field 'state'."""
        return self._state

    @state.setter
    def state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'state' field must be an unsigned integer in [0, 255]"
        self._state = value

    @builtins.property
    def sweep_enabled(self):
        """Message field 'sweep_enabled'."""
        return self._sweep_enabled

    @sweep_enabled.setter
    def sweep_enabled(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sweep_enabled' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'sweep_enabled' field must be an unsigned integer in [0, 255]"
        self._sweep_enabled = value

    @builtins.property
    def yaw_sign_inverted(self):
        """Message field 'yaw_sign_inverted'."""
        return self._yaw_sign_inverted

    @yaw_sign_inverted.setter
    def yaw_sign_inverted(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'yaw_sign_inverted' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'yaw_sign_inverted' field must be an unsigned integer in [0, 255]"
        self._yaw_sign_inverted = value
