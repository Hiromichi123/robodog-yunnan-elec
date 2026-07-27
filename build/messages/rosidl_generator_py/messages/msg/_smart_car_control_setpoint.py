# generated from rosidl_generator_py/resource/_idl.py.em
# with input from messages:msg/SmartCarControlSetpoint.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SmartCarControlSetpoint(type):
    """Metaclass of message 'SmartCarControlSetpoint'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'SMART_CAR_MODE_IDLE': 0,
        'SMART_CAR_MODE_MANUAL': 1,
        'SMART_CAR_MODE_AUTO': 2,
        'SMART_CAR_MODE_CALIB': 3,
        'SMART_CAR_CONTROL_FLAG_ENABLE': 1,
        'SMART_CAR_CONTROL_FLAG_BRAKE': 2,
        'SMART_CAR_CONTROL_FLAG_REVERSE': 4,
        'SMART_CAR_CONTROL_FLAG_HOLD': 8,
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
                'messages.msg.SmartCarControlSetpoint')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__smart_car_control_setpoint
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__smart_car_control_setpoint
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__smart_car_control_setpoint
            cls._TYPE_SUPPORT = module.type_support_msg__msg__smart_car_control_setpoint
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__smart_car_control_setpoint

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'SMART_CAR_MODE_IDLE': cls.__constants['SMART_CAR_MODE_IDLE'],
            'SMART_CAR_MODE_MANUAL': cls.__constants['SMART_CAR_MODE_MANUAL'],
            'SMART_CAR_MODE_AUTO': cls.__constants['SMART_CAR_MODE_AUTO'],
            'SMART_CAR_MODE_CALIB': cls.__constants['SMART_CAR_MODE_CALIB'],
            'SMART_CAR_CONTROL_FLAG_ENABLE': cls.__constants['SMART_CAR_CONTROL_FLAG_ENABLE'],
            'SMART_CAR_CONTROL_FLAG_BRAKE': cls.__constants['SMART_CAR_CONTROL_FLAG_BRAKE'],
            'SMART_CAR_CONTROL_FLAG_REVERSE': cls.__constants['SMART_CAR_CONTROL_FLAG_REVERSE'],
            'SMART_CAR_CONTROL_FLAG_HOLD': cls.__constants['SMART_CAR_CONTROL_FLAG_HOLD'],
        }

    @property
    def SMART_CAR_MODE_IDLE(self):
        """Message constant 'SMART_CAR_MODE_IDLE'."""
        return Metaclass_SmartCarControlSetpoint.__constants['SMART_CAR_MODE_IDLE']

    @property
    def SMART_CAR_MODE_MANUAL(self):
        """Message constant 'SMART_CAR_MODE_MANUAL'."""
        return Metaclass_SmartCarControlSetpoint.__constants['SMART_CAR_MODE_MANUAL']

    @property
    def SMART_CAR_MODE_AUTO(self):
        """Message constant 'SMART_CAR_MODE_AUTO'."""
        return Metaclass_SmartCarControlSetpoint.__constants['SMART_CAR_MODE_AUTO']

    @property
    def SMART_CAR_MODE_CALIB(self):
        """Message constant 'SMART_CAR_MODE_CALIB'."""
        return Metaclass_SmartCarControlSetpoint.__constants['SMART_CAR_MODE_CALIB']

    @property
    def SMART_CAR_CONTROL_FLAG_ENABLE(self):
        """Message constant 'SMART_CAR_CONTROL_FLAG_ENABLE'."""
        return Metaclass_SmartCarControlSetpoint.__constants['SMART_CAR_CONTROL_FLAG_ENABLE']

    @property
    def SMART_CAR_CONTROL_FLAG_BRAKE(self):
        """Message constant 'SMART_CAR_CONTROL_FLAG_BRAKE'."""
        return Metaclass_SmartCarControlSetpoint.__constants['SMART_CAR_CONTROL_FLAG_BRAKE']

    @property
    def SMART_CAR_CONTROL_FLAG_REVERSE(self):
        """Message constant 'SMART_CAR_CONTROL_FLAG_REVERSE'."""
        return Metaclass_SmartCarControlSetpoint.__constants['SMART_CAR_CONTROL_FLAG_REVERSE']

    @property
    def SMART_CAR_CONTROL_FLAG_HOLD(self):
        """Message constant 'SMART_CAR_CONTROL_FLAG_HOLD'."""
        return Metaclass_SmartCarControlSetpoint.__constants['SMART_CAR_CONTROL_FLAG_HOLD']


class SmartCarControlSetpoint(metaclass=Metaclass_SmartCarControlSetpoint):
    """
    Message class 'SmartCarControlSetpoint'.

    Constants:
      SMART_CAR_MODE_IDLE
      SMART_CAR_MODE_MANUAL
      SMART_CAR_MODE_AUTO
      SMART_CAR_MODE_CALIB
      SMART_CAR_CONTROL_FLAG_ENABLE
      SMART_CAR_CONTROL_FLAG_BRAKE
      SMART_CAR_CONTROL_FLAG_REVERSE
      SMART_CAR_CONTROL_FLAG_HOLD
    """

    __slots__ = [
        '_mode',
        '_flags',
        '_target_speed_mps',
        '_target_curvature',
        '_target_yaw_rate_dps',
        '_target_accel_mps2',
    ]

    _fields_and_field_types = {
        'mode': 'uint8',
        'flags': 'uint16',
        'target_speed_mps': 'float',
        'target_curvature': 'float',
        'target_yaw_rate_dps': 'float',
        'target_accel_mps2': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.mode = kwargs.get('mode', int())
        self.flags = kwargs.get('flags', int())
        self.target_speed_mps = kwargs.get('target_speed_mps', float())
        self.target_curvature = kwargs.get('target_curvature', float())
        self.target_yaw_rate_dps = kwargs.get('target_yaw_rate_dps', float())
        self.target_accel_mps2 = kwargs.get('target_accel_mps2', float())

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
        if self.mode != other.mode:
            return False
        if self.flags != other.flags:
            return False
        if self.target_speed_mps != other.target_speed_mps:
            return False
        if self.target_curvature != other.target_curvature:
            return False
        if self.target_yaw_rate_dps != other.target_yaw_rate_dps:
            return False
        if self.target_accel_mps2 != other.target_accel_mps2:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def mode(self):
        """Message field 'mode'."""
        return self._mode

    @mode.setter
    def mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'mode' field must be an unsigned integer in [0, 255]"
        self._mode = value

    @builtins.property
    def flags(self):
        """Message field 'flags'."""
        return self._flags

    @flags.setter
    def flags(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'flags' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'flags' field must be an unsigned integer in [0, 65535]"
        self._flags = value

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
    def target_curvature(self):
        """Message field 'target_curvature'."""
        return self._target_curvature

    @target_curvature.setter
    def target_curvature(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'target_curvature' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'target_curvature' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._target_curvature = value

    @builtins.property
    def target_yaw_rate_dps(self):
        """Message field 'target_yaw_rate_dps'."""
        return self._target_yaw_rate_dps

    @target_yaw_rate_dps.setter
    def target_yaw_rate_dps(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'target_yaw_rate_dps' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'target_yaw_rate_dps' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._target_yaw_rate_dps = value

    @builtins.property
    def target_accel_mps2(self):
        """Message field 'target_accel_mps2'."""
        return self._target_accel_mps2

    @target_accel_mps2.setter
    def target_accel_mps2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'target_accel_mps2' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'target_accel_mps2' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._target_accel_mps2 = value
