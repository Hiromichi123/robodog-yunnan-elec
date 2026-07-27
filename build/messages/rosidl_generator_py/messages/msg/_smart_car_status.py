# generated from rosidl_generator_py/resource/_idl.py.em
# with input from messages:msg/SmartCarStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SmartCarStatus(type):
    """Metaclass of message 'SmartCarStatus'."""

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
        'SMART_CAR_STATE_IDLE': 0,
        'SMART_CAR_STATE_ARMED': 1,
        'SMART_CAR_STATE_RUNNING': 2,
        'SMART_CAR_STATE_FAULT': 3,
        'SMART_CAR_STATE_CALIB': 4,
        'SMART_CAR_FAULT_CMD_TIMEOUT': 1,
        'SMART_CAR_FAULT_MOTOR1_OFFLINE': 2,
        'SMART_CAR_FAULT_MOTOR2_OFFLINE': 4,
        'SMART_CAR_FAULT_IMU_NOT_READY': 8,
        'SMART_CAR_FAULT_CAN_ERROR': 16,
        'SMART_CAR_FAULT_SERVO_CLAMPED': 32,
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
                'messages.msg.SmartCarStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__smart_car_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__smart_car_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__smart_car_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__smart_car_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__smart_car_status

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

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
            'SMART_CAR_STATE_IDLE': cls.__constants['SMART_CAR_STATE_IDLE'],
            'SMART_CAR_STATE_ARMED': cls.__constants['SMART_CAR_STATE_ARMED'],
            'SMART_CAR_STATE_RUNNING': cls.__constants['SMART_CAR_STATE_RUNNING'],
            'SMART_CAR_STATE_FAULT': cls.__constants['SMART_CAR_STATE_FAULT'],
            'SMART_CAR_STATE_CALIB': cls.__constants['SMART_CAR_STATE_CALIB'],
            'SMART_CAR_FAULT_CMD_TIMEOUT': cls.__constants['SMART_CAR_FAULT_CMD_TIMEOUT'],
            'SMART_CAR_FAULT_MOTOR1_OFFLINE': cls.__constants['SMART_CAR_FAULT_MOTOR1_OFFLINE'],
            'SMART_CAR_FAULT_MOTOR2_OFFLINE': cls.__constants['SMART_CAR_FAULT_MOTOR2_OFFLINE'],
            'SMART_CAR_FAULT_IMU_NOT_READY': cls.__constants['SMART_CAR_FAULT_IMU_NOT_READY'],
            'SMART_CAR_FAULT_CAN_ERROR': cls.__constants['SMART_CAR_FAULT_CAN_ERROR'],
            'SMART_CAR_FAULT_SERVO_CLAMPED': cls.__constants['SMART_CAR_FAULT_SERVO_CLAMPED'],
        }

    @property
    def SMART_CAR_MODE_IDLE(self):
        """Message constant 'SMART_CAR_MODE_IDLE'."""
        return Metaclass_SmartCarStatus.__constants['SMART_CAR_MODE_IDLE']

    @property
    def SMART_CAR_MODE_MANUAL(self):
        """Message constant 'SMART_CAR_MODE_MANUAL'."""
        return Metaclass_SmartCarStatus.__constants['SMART_CAR_MODE_MANUAL']

    @property
    def SMART_CAR_MODE_AUTO(self):
        """Message constant 'SMART_CAR_MODE_AUTO'."""
        return Metaclass_SmartCarStatus.__constants['SMART_CAR_MODE_AUTO']

    @property
    def SMART_CAR_MODE_CALIB(self):
        """Message constant 'SMART_CAR_MODE_CALIB'."""
        return Metaclass_SmartCarStatus.__constants['SMART_CAR_MODE_CALIB']

    @property
    def SMART_CAR_STATE_IDLE(self):
        """Message constant 'SMART_CAR_STATE_IDLE'."""
        return Metaclass_SmartCarStatus.__constants['SMART_CAR_STATE_IDLE']

    @property
    def SMART_CAR_STATE_ARMED(self):
        """Message constant 'SMART_CAR_STATE_ARMED'."""
        return Metaclass_SmartCarStatus.__constants['SMART_CAR_STATE_ARMED']

    @property
    def SMART_CAR_STATE_RUNNING(self):
        """Message constant 'SMART_CAR_STATE_RUNNING'."""
        return Metaclass_SmartCarStatus.__constants['SMART_CAR_STATE_RUNNING']

    @property
    def SMART_CAR_STATE_FAULT(self):
        """Message constant 'SMART_CAR_STATE_FAULT'."""
        return Metaclass_SmartCarStatus.__constants['SMART_CAR_STATE_FAULT']

    @property
    def SMART_CAR_STATE_CALIB(self):
        """Message constant 'SMART_CAR_STATE_CALIB'."""
        return Metaclass_SmartCarStatus.__constants['SMART_CAR_STATE_CALIB']

    @property
    def SMART_CAR_FAULT_CMD_TIMEOUT(self):
        """Message constant 'SMART_CAR_FAULT_CMD_TIMEOUT'."""
        return Metaclass_SmartCarStatus.__constants['SMART_CAR_FAULT_CMD_TIMEOUT']

    @property
    def SMART_CAR_FAULT_MOTOR1_OFFLINE(self):
        """Message constant 'SMART_CAR_FAULT_MOTOR1_OFFLINE'."""
        return Metaclass_SmartCarStatus.__constants['SMART_CAR_FAULT_MOTOR1_OFFLINE']

    @property
    def SMART_CAR_FAULT_MOTOR2_OFFLINE(self):
        """Message constant 'SMART_CAR_FAULT_MOTOR2_OFFLINE'."""
        return Metaclass_SmartCarStatus.__constants['SMART_CAR_FAULT_MOTOR2_OFFLINE']

    @property
    def SMART_CAR_FAULT_IMU_NOT_READY(self):
        """Message constant 'SMART_CAR_FAULT_IMU_NOT_READY'."""
        return Metaclass_SmartCarStatus.__constants['SMART_CAR_FAULT_IMU_NOT_READY']

    @property
    def SMART_CAR_FAULT_CAN_ERROR(self):
        """Message constant 'SMART_CAR_FAULT_CAN_ERROR'."""
        return Metaclass_SmartCarStatus.__constants['SMART_CAR_FAULT_CAN_ERROR']

    @property
    def SMART_CAR_FAULT_SERVO_CLAMPED(self):
        """Message constant 'SMART_CAR_FAULT_SERVO_CLAMPED'."""
        return Metaclass_SmartCarStatus.__constants['SMART_CAR_FAULT_SERVO_CLAMPED']


class SmartCarStatus(metaclass=Metaclass_SmartCarStatus):
    """
    Message class 'SmartCarStatus'.

    Constants:
      SMART_CAR_MODE_IDLE
      SMART_CAR_MODE_MANUAL
      SMART_CAR_MODE_AUTO
      SMART_CAR_MODE_CALIB
      SMART_CAR_STATE_IDLE
      SMART_CAR_STATE_ARMED
      SMART_CAR_STATE_RUNNING
      SMART_CAR_STATE_FAULT
      SMART_CAR_STATE_CALIB
      SMART_CAR_FAULT_CMD_TIMEOUT
      SMART_CAR_FAULT_MOTOR1_OFFLINE
      SMART_CAR_FAULT_MOTOR2_OFFLINE
      SMART_CAR_FAULT_IMU_NOT_READY
      SMART_CAR_FAULT_CAN_ERROR
      SMART_CAR_FAULT_SERVO_CLAMPED
    """

    __slots__ = [
        '_stamp',
        '_time_boot_ms',
        '_mode',
        '_state',
        '_fault_flags',
        '_warn_flags',
        '_cmd_age_ms',
        '_control_loop_hz',
        '_imu_online',
        '_can_online',
        '_host_online',
        '_servo_online',
        '_motor_online_mask',
    ]

    _fields_and_field_types = {
        'stamp': 'builtin_interfaces/Time',
        'time_boot_ms': 'uint32',
        'mode': 'uint8',
        'state': 'uint8',
        'fault_flags': 'uint32',
        'warn_flags': 'uint32',
        'cmd_age_ms': 'uint16',
        'control_loop_hz': 'uint16',
        'imu_online': 'uint8',
        'can_online': 'uint8',
        'host_online': 'uint8',
        'servo_online': 'uint8',
        'motor_online_mask': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
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
        self.mode = kwargs.get('mode', int())
        self.state = kwargs.get('state', int())
        self.fault_flags = kwargs.get('fault_flags', int())
        self.warn_flags = kwargs.get('warn_flags', int())
        self.cmd_age_ms = kwargs.get('cmd_age_ms', int())
        self.control_loop_hz = kwargs.get('control_loop_hz', int())
        self.imu_online = kwargs.get('imu_online', int())
        self.can_online = kwargs.get('can_online', int())
        self.host_online = kwargs.get('host_online', int())
        self.servo_online = kwargs.get('servo_online', int())
        self.motor_online_mask = kwargs.get('motor_online_mask', int())

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
        if self.mode != other.mode:
            return False
        if self.state != other.state:
            return False
        if self.fault_flags != other.fault_flags:
            return False
        if self.warn_flags != other.warn_flags:
            return False
        if self.cmd_age_ms != other.cmd_age_ms:
            return False
        if self.control_loop_hz != other.control_loop_hz:
            return False
        if self.imu_online != other.imu_online:
            return False
        if self.can_online != other.can_online:
            return False
        if self.host_online != other.host_online:
            return False
        if self.servo_online != other.servo_online:
            return False
        if self.motor_online_mask != other.motor_online_mask:
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
    def fault_flags(self):
        """Message field 'fault_flags'."""
        return self._fault_flags

    @fault_flags.setter
    def fault_flags(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'fault_flags' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'fault_flags' field must be an unsigned integer in [0, 4294967295]"
        self._fault_flags = value

    @builtins.property
    def warn_flags(self):
        """Message field 'warn_flags'."""
        return self._warn_flags

    @warn_flags.setter
    def warn_flags(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'warn_flags' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'warn_flags' field must be an unsigned integer in [0, 4294967295]"
        self._warn_flags = value

    @builtins.property
    def cmd_age_ms(self):
        """Message field 'cmd_age_ms'."""
        return self._cmd_age_ms

    @cmd_age_ms.setter
    def cmd_age_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cmd_age_ms' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'cmd_age_ms' field must be an unsigned integer in [0, 65535]"
        self._cmd_age_ms = value

    @builtins.property
    def control_loop_hz(self):
        """Message field 'control_loop_hz'."""
        return self._control_loop_hz

    @control_loop_hz.setter
    def control_loop_hz(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'control_loop_hz' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'control_loop_hz' field must be an unsigned integer in [0, 65535]"
        self._control_loop_hz = value

    @builtins.property
    def imu_online(self):
        """Message field 'imu_online'."""
        return self._imu_online

    @imu_online.setter
    def imu_online(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'imu_online' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'imu_online' field must be an unsigned integer in [0, 255]"
        self._imu_online = value

    @builtins.property
    def can_online(self):
        """Message field 'can_online'."""
        return self._can_online

    @can_online.setter
    def can_online(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'can_online' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'can_online' field must be an unsigned integer in [0, 255]"
        self._can_online = value

    @builtins.property
    def host_online(self):
        """Message field 'host_online'."""
        return self._host_online

    @host_online.setter
    def host_online(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'host_online' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'host_online' field must be an unsigned integer in [0, 255]"
        self._host_online = value

    @builtins.property
    def servo_online(self):
        """Message field 'servo_online'."""
        return self._servo_online

    @servo_online.setter
    def servo_online(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'servo_online' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'servo_online' field must be an unsigned integer in [0, 255]"
        self._servo_online = value

    @builtins.property
    def motor_online_mask(self):
        """Message field 'motor_online_mask'."""
        return self._motor_online_mask

    @motor_online_mask.setter
    def motor_online_mask(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'motor_online_mask' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'motor_online_mask' field must be an unsigned integer in [0, 255]"
        self._motor_online_mask = value
