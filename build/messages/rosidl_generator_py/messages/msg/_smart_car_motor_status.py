# generated from rosidl_generator_py/resource/_idl.py.em
# with input from messages:msg/SmartCarMotorStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SmartCarMotorStatus(type):
    """Metaclass of message 'SmartCarMotorStatus'."""

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
                'messages.msg.SmartCarMotorStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__smart_car_motor_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__smart_car_motor_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__smart_car_motor_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__smart_car_motor_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__smart_car_motor_status

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


class SmartCarMotorStatus(metaclass=Metaclass_SmartCarMotorStatus):
    """Message class 'SmartCarMotorStatus'."""

    __slots__ = [
        '_stamp',
        '_time_boot_ms',
        '_target_rpm_1',
        '_target_rpm_2',
        '_actual_rpm_1',
        '_actual_rpm_2',
        '_current_cmd_1',
        '_current_cmd_2',
        '_feedback_current_1',
        '_feedback_current_2',
        '_angle_1',
        '_angle_2',
        '_online_mask',
        '_can_tx_busy_count',
        '_can_error_count',
    ]

    _fields_and_field_types = {
        'stamp': 'builtin_interfaces/Time',
        'time_boot_ms': 'uint32',
        'target_rpm_1': 'int16',
        'target_rpm_2': 'int16',
        'actual_rpm_1': 'int16',
        'actual_rpm_2': 'int16',
        'current_cmd_1': 'int16',
        'current_cmd_2': 'int16',
        'feedback_current_1': 'int16',
        'feedback_current_2': 'int16',
        'angle_1': 'uint16',
        'angle_2': 'uint16',
        'online_mask': 'uint8',
        'can_tx_busy_count': 'uint32',
        'can_error_count': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())
        self.time_boot_ms = kwargs.get('time_boot_ms', int())
        self.target_rpm_1 = kwargs.get('target_rpm_1', int())
        self.target_rpm_2 = kwargs.get('target_rpm_2', int())
        self.actual_rpm_1 = kwargs.get('actual_rpm_1', int())
        self.actual_rpm_2 = kwargs.get('actual_rpm_2', int())
        self.current_cmd_1 = kwargs.get('current_cmd_1', int())
        self.current_cmd_2 = kwargs.get('current_cmd_2', int())
        self.feedback_current_1 = kwargs.get('feedback_current_1', int())
        self.feedback_current_2 = kwargs.get('feedback_current_2', int())
        self.angle_1 = kwargs.get('angle_1', int())
        self.angle_2 = kwargs.get('angle_2', int())
        self.online_mask = kwargs.get('online_mask', int())
        self.can_tx_busy_count = kwargs.get('can_tx_busy_count', int())
        self.can_error_count = kwargs.get('can_error_count', int())

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
        if self.target_rpm_1 != other.target_rpm_1:
            return False
        if self.target_rpm_2 != other.target_rpm_2:
            return False
        if self.actual_rpm_1 != other.actual_rpm_1:
            return False
        if self.actual_rpm_2 != other.actual_rpm_2:
            return False
        if self.current_cmd_1 != other.current_cmd_1:
            return False
        if self.current_cmd_2 != other.current_cmd_2:
            return False
        if self.feedback_current_1 != other.feedback_current_1:
            return False
        if self.feedback_current_2 != other.feedback_current_2:
            return False
        if self.angle_1 != other.angle_1:
            return False
        if self.angle_2 != other.angle_2:
            return False
        if self.online_mask != other.online_mask:
            return False
        if self.can_tx_busy_count != other.can_tx_busy_count:
            return False
        if self.can_error_count != other.can_error_count:
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
    def target_rpm_1(self):
        """Message field 'target_rpm_1'."""
        return self._target_rpm_1

    @target_rpm_1.setter
    def target_rpm_1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'target_rpm_1' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'target_rpm_1' field must be an integer in [-32768, 32767]"
        self._target_rpm_1 = value

    @builtins.property
    def target_rpm_2(self):
        """Message field 'target_rpm_2'."""
        return self._target_rpm_2

    @target_rpm_2.setter
    def target_rpm_2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'target_rpm_2' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'target_rpm_2' field must be an integer in [-32768, 32767]"
        self._target_rpm_2 = value

    @builtins.property
    def actual_rpm_1(self):
        """Message field 'actual_rpm_1'."""
        return self._actual_rpm_1

    @actual_rpm_1.setter
    def actual_rpm_1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'actual_rpm_1' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'actual_rpm_1' field must be an integer in [-32768, 32767]"
        self._actual_rpm_1 = value

    @builtins.property
    def actual_rpm_2(self):
        """Message field 'actual_rpm_2'."""
        return self._actual_rpm_2

    @actual_rpm_2.setter
    def actual_rpm_2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'actual_rpm_2' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'actual_rpm_2' field must be an integer in [-32768, 32767]"
        self._actual_rpm_2 = value

    @builtins.property
    def current_cmd_1(self):
        """Message field 'current_cmd_1'."""
        return self._current_cmd_1

    @current_cmd_1.setter
    def current_cmd_1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_cmd_1' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'current_cmd_1' field must be an integer in [-32768, 32767]"
        self._current_cmd_1 = value

    @builtins.property
    def current_cmd_2(self):
        """Message field 'current_cmd_2'."""
        return self._current_cmd_2

    @current_cmd_2.setter
    def current_cmd_2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_cmd_2' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'current_cmd_2' field must be an integer in [-32768, 32767]"
        self._current_cmd_2 = value

    @builtins.property
    def feedback_current_1(self):
        """Message field 'feedback_current_1'."""
        return self._feedback_current_1

    @feedback_current_1.setter
    def feedback_current_1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'feedback_current_1' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'feedback_current_1' field must be an integer in [-32768, 32767]"
        self._feedback_current_1 = value

    @builtins.property
    def feedback_current_2(self):
        """Message field 'feedback_current_2'."""
        return self._feedback_current_2

    @feedback_current_2.setter
    def feedback_current_2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'feedback_current_2' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'feedback_current_2' field must be an integer in [-32768, 32767]"
        self._feedback_current_2 = value

    @builtins.property
    def angle_1(self):
        """Message field 'angle_1'."""
        return self._angle_1

    @angle_1.setter
    def angle_1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'angle_1' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'angle_1' field must be an unsigned integer in [0, 65535]"
        self._angle_1 = value

    @builtins.property
    def angle_2(self):
        """Message field 'angle_2'."""
        return self._angle_2

    @angle_2.setter
    def angle_2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'angle_2' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'angle_2' field must be an unsigned integer in [0, 65535]"
        self._angle_2 = value

    @builtins.property
    def online_mask(self):
        """Message field 'online_mask'."""
        return self._online_mask

    @online_mask.setter
    def online_mask(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'online_mask' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'online_mask' field must be an unsigned integer in [0, 255]"
        self._online_mask = value

    @builtins.property
    def can_tx_busy_count(self):
        """Message field 'can_tx_busy_count'."""
        return self._can_tx_busy_count

    @can_tx_busy_count.setter
    def can_tx_busy_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'can_tx_busy_count' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'can_tx_busy_count' field must be an unsigned integer in [0, 4294967295]"
        self._can_tx_busy_count = value

    @builtins.property
    def can_error_count(self):
        """Message field 'can_error_count'."""
        return self._can_error_count

    @can_error_count.setter
    def can_error_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'can_error_count' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'can_error_count' field must be an unsigned integer in [0, 4294967295]"
        self._can_error_count = value
