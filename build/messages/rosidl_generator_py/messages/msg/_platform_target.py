# generated from rosidl_generator_py/resource/_idl.py.em
# with input from messages:msg/PlatformTarget.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PlatformTarget(type):
    """Metaclass of message 'PlatformTarget'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'PLATFORM_CAR': 0,
        'PLATFORM_FLIGHT': 1,
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
                'messages.msg.PlatformTarget')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__platform_target
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__platform_target
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__platform_target
            cls._TYPE_SUPPORT = module.type_support_msg__msg__platform_target
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__platform_target

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'PLATFORM_CAR': cls.__constants['PLATFORM_CAR'],
            'PLATFORM_FLIGHT': cls.__constants['PLATFORM_FLIGHT'],
        }

    @property
    def PLATFORM_CAR(self):
        """Message constant 'PLATFORM_CAR'."""
        return Metaclass_PlatformTarget.__constants['PLATFORM_CAR']

    @property
    def PLATFORM_FLIGHT(self):
        """Message constant 'PLATFORM_FLIGHT'."""
        return Metaclass_PlatformTarget.__constants['PLATFORM_FLIGHT']


class PlatformTarget(metaclass=Metaclass_PlatformTarget):
    """
    Message class 'PlatformTarget'.

    Constants:
      PLATFORM_CAR
      PLATFORM_FLIGHT
    """

    __slots__ = [
        '_platform',
        '_x',
        '_y',
        '_z',
        '_yaw',
        '_vx_mps',
        '_vy_mps',
        '_vz_mps',
        '_speed_mps',
        '_curvature',
        '_yaw_rate_dps',
    ]

    _fields_and_field_types = {
        'platform': 'uint8',
        'x': 'float',
        'y': 'float',
        'z': 'float',
        'yaw': 'float',
        'vx_mps': 'float',
        'vy_mps': 'float',
        'vz_mps': 'float',
        'speed_mps': 'float',
        'curvature': 'float',
        'yaw_rate_dps': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.platform = kwargs.get('platform', int())
        self.x = kwargs.get('x', float())
        self.y = kwargs.get('y', float())
        self.z = kwargs.get('z', float())
        self.yaw = kwargs.get('yaw', float())
        self.vx_mps = kwargs.get('vx_mps', float())
        self.vy_mps = kwargs.get('vy_mps', float())
        self.vz_mps = kwargs.get('vz_mps', float())
        self.speed_mps = kwargs.get('speed_mps', float())
        self.curvature = kwargs.get('curvature', float())
        self.yaw_rate_dps = kwargs.get('yaw_rate_dps', float())

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
        if self.platform != other.platform:
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.z != other.z:
            return False
        if self.yaw != other.yaw:
            return False
        if self.vx_mps != other.vx_mps:
            return False
        if self.vy_mps != other.vy_mps:
            return False
        if self.vz_mps != other.vz_mps:
            return False
        if self.speed_mps != other.speed_mps:
            return False
        if self.curvature != other.curvature:
            return False
        if self.yaw_rate_dps != other.yaw_rate_dps:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def platform(self):
        """Message field 'platform'."""
        return self._platform

    @platform.setter
    def platform(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'platform' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'platform' field must be an unsigned integer in [0, 255]"
        self._platform = value

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._y = value

    @builtins.property
    def z(self):
        """Message field 'z'."""
        return self._z

    @z.setter
    def z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._z = value

    @builtins.property
    def yaw(self):
        """Message field 'yaw'."""
        return self._yaw

    @yaw.setter
    def yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw = value

    @builtins.property
    def vx_mps(self):
        """Message field 'vx_mps'."""
        return self._vx_mps

    @vx_mps.setter
    def vx_mps(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vx_mps' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'vx_mps' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._vx_mps = value

    @builtins.property
    def vy_mps(self):
        """Message field 'vy_mps'."""
        return self._vy_mps

    @vy_mps.setter
    def vy_mps(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vy_mps' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'vy_mps' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._vy_mps = value

    @builtins.property
    def vz_mps(self):
        """Message field 'vz_mps'."""
        return self._vz_mps

    @vz_mps.setter
    def vz_mps(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vz_mps' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'vz_mps' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._vz_mps = value

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
    def curvature(self):
        """Message field 'curvature'."""
        return self._curvature

    @curvature.setter
    def curvature(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'curvature' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'curvature' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._curvature = value

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
