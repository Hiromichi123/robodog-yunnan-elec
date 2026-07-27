# generated from rosidl_generator_py/resource/_idl.py.em
# with input from messages:msg/SmartCarImuStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SmartCarImuStatus(type):
    """Metaclass of message 'SmartCarImuStatus'."""

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
                'messages.msg.SmartCarImuStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__smart_car_imu_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__smart_car_imu_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__smart_car_imu_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__smart_car_imu_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__smart_car_imu_status

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


class SmartCarImuStatus(metaclass=Metaclass_SmartCarImuStatus):
    """Message class 'SmartCarImuStatus'."""

    __slots__ = [
        '_stamp',
        '_time_boot_ms',
        '_sample_count',
        '_overrun_count',
        '_error_count',
        '_gyro_x_mdps',
        '_gyro_y_mdps',
        '_gyro_z_mdps',
        '_yaw_rate_raw_dps',
        '_yaw_rate_dps',
        '_gyro_bias_z_dps',
        '_accel_x_mg',
        '_accel_y_mg',
        '_accel_z_mg',
        '_temperature_c_x100',
        '_calibrated',
    ]

    _fields_and_field_types = {
        'stamp': 'builtin_interfaces/Time',
        'time_boot_ms': 'uint32',
        'sample_count': 'uint32',
        'overrun_count': 'uint32',
        'error_count': 'uint32',
        'gyro_x_mdps': 'int32',
        'gyro_y_mdps': 'int32',
        'gyro_z_mdps': 'int32',
        'yaw_rate_raw_dps': 'float',
        'yaw_rate_dps': 'float',
        'gyro_bias_z_dps': 'float',
        'accel_x_mg': 'int16',
        'accel_y_mg': 'int16',
        'accel_z_mg': 'int16',
        'temperature_c_x100': 'int16',
        'calibrated': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())
        self.time_boot_ms = kwargs.get('time_boot_ms', int())
        self.sample_count = kwargs.get('sample_count', int())
        self.overrun_count = kwargs.get('overrun_count', int())
        self.error_count = kwargs.get('error_count', int())
        self.gyro_x_mdps = kwargs.get('gyro_x_mdps', int())
        self.gyro_y_mdps = kwargs.get('gyro_y_mdps', int())
        self.gyro_z_mdps = kwargs.get('gyro_z_mdps', int())
        self.yaw_rate_raw_dps = kwargs.get('yaw_rate_raw_dps', float())
        self.yaw_rate_dps = kwargs.get('yaw_rate_dps', float())
        self.gyro_bias_z_dps = kwargs.get('gyro_bias_z_dps', float())
        self.accel_x_mg = kwargs.get('accel_x_mg', int())
        self.accel_y_mg = kwargs.get('accel_y_mg', int())
        self.accel_z_mg = kwargs.get('accel_z_mg', int())
        self.temperature_c_x100 = kwargs.get('temperature_c_x100', int())
        self.calibrated = kwargs.get('calibrated', int())

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
        if self.sample_count != other.sample_count:
            return False
        if self.overrun_count != other.overrun_count:
            return False
        if self.error_count != other.error_count:
            return False
        if self.gyro_x_mdps != other.gyro_x_mdps:
            return False
        if self.gyro_y_mdps != other.gyro_y_mdps:
            return False
        if self.gyro_z_mdps != other.gyro_z_mdps:
            return False
        if self.yaw_rate_raw_dps != other.yaw_rate_raw_dps:
            return False
        if self.yaw_rate_dps != other.yaw_rate_dps:
            return False
        if self.gyro_bias_z_dps != other.gyro_bias_z_dps:
            return False
        if self.accel_x_mg != other.accel_x_mg:
            return False
        if self.accel_y_mg != other.accel_y_mg:
            return False
        if self.accel_z_mg != other.accel_z_mg:
            return False
        if self.temperature_c_x100 != other.temperature_c_x100:
            return False
        if self.calibrated != other.calibrated:
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
    def sample_count(self):
        """Message field 'sample_count'."""
        return self._sample_count

    @sample_count.setter
    def sample_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sample_count' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'sample_count' field must be an unsigned integer in [0, 4294967295]"
        self._sample_count = value

    @builtins.property
    def overrun_count(self):
        """Message field 'overrun_count'."""
        return self._overrun_count

    @overrun_count.setter
    def overrun_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'overrun_count' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'overrun_count' field must be an unsigned integer in [0, 4294967295]"
        self._overrun_count = value

    @builtins.property
    def error_count(self):
        """Message field 'error_count'."""
        return self._error_count

    @error_count.setter
    def error_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'error_count' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'error_count' field must be an unsigned integer in [0, 4294967295]"
        self._error_count = value

    @builtins.property
    def gyro_x_mdps(self):
        """Message field 'gyro_x_mdps'."""
        return self._gyro_x_mdps

    @gyro_x_mdps.setter
    def gyro_x_mdps(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gyro_x_mdps' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'gyro_x_mdps' field must be an integer in [-2147483648, 2147483647]"
        self._gyro_x_mdps = value

    @builtins.property
    def gyro_y_mdps(self):
        """Message field 'gyro_y_mdps'."""
        return self._gyro_y_mdps

    @gyro_y_mdps.setter
    def gyro_y_mdps(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gyro_y_mdps' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'gyro_y_mdps' field must be an integer in [-2147483648, 2147483647]"
        self._gyro_y_mdps = value

    @builtins.property
    def gyro_z_mdps(self):
        """Message field 'gyro_z_mdps'."""
        return self._gyro_z_mdps

    @gyro_z_mdps.setter
    def gyro_z_mdps(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gyro_z_mdps' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'gyro_z_mdps' field must be an integer in [-2147483648, 2147483647]"
        self._gyro_z_mdps = value

    @builtins.property
    def yaw_rate_raw_dps(self):
        """Message field 'yaw_rate_raw_dps'."""
        return self._yaw_rate_raw_dps

    @yaw_rate_raw_dps.setter
    def yaw_rate_raw_dps(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw_rate_raw_dps' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw_rate_raw_dps' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw_rate_raw_dps = value

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
    def gyro_bias_z_dps(self):
        """Message field 'gyro_bias_z_dps'."""
        return self._gyro_bias_z_dps

    @gyro_bias_z_dps.setter
    def gyro_bias_z_dps(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gyro_bias_z_dps' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'gyro_bias_z_dps' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._gyro_bias_z_dps = value

    @builtins.property
    def accel_x_mg(self):
        """Message field 'accel_x_mg'."""
        return self._accel_x_mg

    @accel_x_mg.setter
    def accel_x_mg(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'accel_x_mg' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'accel_x_mg' field must be an integer in [-32768, 32767]"
        self._accel_x_mg = value

    @builtins.property
    def accel_y_mg(self):
        """Message field 'accel_y_mg'."""
        return self._accel_y_mg

    @accel_y_mg.setter
    def accel_y_mg(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'accel_y_mg' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'accel_y_mg' field must be an integer in [-32768, 32767]"
        self._accel_y_mg = value

    @builtins.property
    def accel_z_mg(self):
        """Message field 'accel_z_mg'."""
        return self._accel_z_mg

    @accel_z_mg.setter
    def accel_z_mg(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'accel_z_mg' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'accel_z_mg' field must be an integer in [-32768, 32767]"
        self._accel_z_mg = value

    @builtins.property
    def temperature_c_x100(self):
        """Message field 'temperature_c_x100'."""
        return self._temperature_c_x100

    @temperature_c_x100.setter
    def temperature_c_x100(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'temperature_c_x100' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'temperature_c_x100' field must be an integer in [-32768, 32767]"
        self._temperature_c_x100 = value

    @builtins.property
    def calibrated(self):
        """Message field 'calibrated'."""
        return self._calibrated

    @calibrated.setter
    def calibrated(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'calibrated' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'calibrated' field must be an unsigned integer in [0, 255]"
        self._calibrated = value
