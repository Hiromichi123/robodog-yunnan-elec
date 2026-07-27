# generated from rosidl_generator_py/resource/_idl.py.em
# with input from messages:msg/SmartCarMotionState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SmartCarMotionState(type):
    """Metaclass of message 'SmartCarMotionState'."""

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
                'messages.msg.SmartCarMotionState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__smart_car_motion_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__smart_car_motion_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__smart_car_motion_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__smart_car_motion_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__smart_car_motion_state

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


class SmartCarMotionState(metaclass=Metaclass_SmartCarMotionState):
    """Message class 'SmartCarMotionState'."""

    __slots__ = [
        '_stamp',
        '_time_boot_ms',
        '_speed_mps',
        '_target_speed_mps',
        '_yaw_rate_dps',
        '_yaw_deg',
        '_curvature_meas',
        '_curvature_cmd',
        '_steering_angle_deg',
        '_steering_pwm_us',
        '_steering_clamped',
    ]

    _fields_and_field_types = {
        'stamp': 'builtin_interfaces/Time',
        'time_boot_ms': 'uint32',
        'speed_mps': 'float',
        'target_speed_mps': 'float',
        'yaw_rate_dps': 'float',
        'yaw_deg': 'float',
        'curvature_meas': 'float',
        'curvature_cmd': 'float',
        'steering_angle_deg': 'float',
        'steering_pwm_us': 'uint16',
        'steering_clamped': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())
        self.time_boot_ms = kwargs.get('time_boot_ms', int())
        self.speed_mps = kwargs.get('speed_mps', float())
        self.target_speed_mps = kwargs.get('target_speed_mps', float())
        self.yaw_rate_dps = kwargs.get('yaw_rate_dps', float())
        self.yaw_deg = kwargs.get('yaw_deg', float())
        self.curvature_meas = kwargs.get('curvature_meas', float())
        self.curvature_cmd = kwargs.get('curvature_cmd', float())
        self.steering_angle_deg = kwargs.get('steering_angle_deg', float())
        self.steering_pwm_us = kwargs.get('steering_pwm_us', int())
        self.steering_clamped = kwargs.get('steering_clamped', int())

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
        if self.speed_mps != other.speed_mps:
            return False
        if self.target_speed_mps != other.target_speed_mps:
            return False
        if self.yaw_rate_dps != other.yaw_rate_dps:
            return False
        if self.yaw_deg != other.yaw_deg:
            return False
        if self.curvature_meas != other.curvature_meas:
            return False
        if self.curvature_cmd != other.curvature_cmd:
            return False
        if self.steering_angle_deg != other.steering_angle_deg:
            return False
        if self.steering_pwm_us != other.steering_pwm_us:
            return False
        if self.steering_clamped != other.steering_clamped:
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
    def speed_mps(self):
        """Message field 'speed_mps'."""
        return self._speed_mps

    @speed_mps.setter
    def speed_mps(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed_mps' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'speed_mps' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._speed_mps = value

    @builtins.property
    def target_speed_mps(self):
        """Message field 'target_speed_mps'."""
        return self._target_speed_mps

    @target_speed_mps.setter
    def target_speed_mps(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'target_speed_mps' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'target_speed_mps' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._target_speed_mps = value

    @builtins.property
    def yaw_rate_dps(self):
        """Message field 'yaw_rate_dps'."""
        return self._yaw_rate_dps

    @yaw_rate_dps.setter
    def yaw_rate_dps(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw_rate_dps' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw_rate_dps' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw_rate_dps = value

    @builtins.property
    def yaw_deg(self):
        """Message field 'yaw_deg'."""
        return self._yaw_deg

    @yaw_deg.setter
    def yaw_deg(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw_deg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw_deg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw_deg = value

    @builtins.property
    def curvature_meas(self):
        """Message field 'curvature_meas'."""
        return self._curvature_meas

    @curvature_meas.setter
    def curvature_meas(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'curvature_meas' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'curvature_meas' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._curvature_meas = value

    @builtins.property
    def curvature_cmd(self):
        """Message field 'curvature_cmd'."""
        return self._curvature_cmd

    @curvature_cmd.setter
    def curvature_cmd(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'curvature_cmd' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'curvature_cmd' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._curvature_cmd = value

    @builtins.property
    def steering_angle_deg(self):
        """Message field 'steering_angle_deg'."""
        return self._steering_angle_deg

    @steering_angle_deg.setter
    def steering_angle_deg(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'steering_angle_deg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'steering_angle_deg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._steering_angle_deg = value

    @builtins.property
    def steering_pwm_us(self):
        """Message field 'steering_pwm_us'."""
        return self._steering_pwm_us

    @steering_pwm_us.setter
    def steering_pwm_us(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'steering_pwm_us' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'steering_pwm_us' field must be an unsigned integer in [0, 65535]"
        self._steering_pwm_us = value

    @builtins.property
    def steering_clamped(self):
        """Message field 'steering_clamped'."""
        return self._steering_clamped

    @steering_clamped.setter
    def steering_clamped(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'steering_clamped' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'steering_clamped' field must be an unsigned integer in [0, 255]"
        self._steering_clamped = value
