# generated from rosidl_generator_py/resource/_idl.py.em
# with input from messages:srv/SmartCarActuatorTest.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SmartCarActuatorTest_Request(type):
    """Metaclass of message 'SmartCarActuatorTest_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'TEST_SERVO_ANGLE': 1,
        'TEST_SERVO_PWM': 2,
        'TEST_MOTOR_RPM': 4,
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
                'messages.srv.SmartCarActuatorTest_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__smart_car_actuator_test__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__smart_car_actuator_test__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__smart_car_actuator_test__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__smart_car_actuator_test__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__smart_car_actuator_test__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'TEST_SERVO_ANGLE': cls.__constants['TEST_SERVO_ANGLE'],
            'TEST_SERVO_PWM': cls.__constants['TEST_SERVO_PWM'],
            'TEST_MOTOR_RPM': cls.__constants['TEST_MOTOR_RPM'],
        }

    @property
    def TEST_SERVO_ANGLE(self):
        """Message constant 'TEST_SERVO_ANGLE'."""
        return Metaclass_SmartCarActuatorTest_Request.__constants['TEST_SERVO_ANGLE']

    @property
    def TEST_SERVO_PWM(self):
        """Message constant 'TEST_SERVO_PWM'."""
        return Metaclass_SmartCarActuatorTest_Request.__constants['TEST_SERVO_PWM']

    @property
    def TEST_MOTOR_RPM(self):
        """Message constant 'TEST_MOTOR_RPM'."""
        return Metaclass_SmartCarActuatorTest_Request.__constants['TEST_MOTOR_RPM']


class SmartCarActuatorTest_Request(metaclass=Metaclass_SmartCarActuatorTest_Request):
    """
    Message class 'SmartCarActuatorTest_Request'.

    Constants:
      TEST_SERVO_ANGLE
      TEST_SERVO_PWM
      TEST_MOTOR_RPM
    """

    __slots__ = [
        '_test_mask',
        '_servo_angle_deg',
        '_servo_pwm_us',
        '_motor1_rpm',
        '_motor2_rpm',
        '_duration_ms',
    ]

    _fields_and_field_types = {
        'test_mask': 'uint16',
        'servo_angle_deg': 'float',
        'servo_pwm_us': 'uint16',
        'motor1_rpm': 'int16',
        'motor2_rpm': 'int16',
        'duration_ms': 'uint16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.test_mask = kwargs.get('test_mask', int())
        self.servo_angle_deg = kwargs.get('servo_angle_deg', float())
        self.servo_pwm_us = kwargs.get('servo_pwm_us', int())
        self.motor1_rpm = kwargs.get('motor1_rpm', int())
        self.motor2_rpm = kwargs.get('motor2_rpm', int())
        self.duration_ms = kwargs.get('duration_ms', int())

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
        if self.test_mask != other.test_mask:
            return False
        if self.servo_angle_deg != other.servo_angle_deg:
            return False
        if self.servo_pwm_us != other.servo_pwm_us:
            return False
        if self.motor1_rpm != other.motor1_rpm:
            return False
        if self.motor2_rpm != other.motor2_rpm:
            return False
        if self.duration_ms != other.duration_ms:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def test_mask(self):
        """Message field 'test_mask'."""
        return self._test_mask

    @test_mask.setter
    def test_mask(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'test_mask' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'test_mask' field must be an unsigned integer in [0, 65535]"
        self._test_mask = value

    @builtins.property
    def servo_angle_deg(self):
        """Message field 'servo_angle_deg'."""
        return self._servo_angle_deg

    @servo_angle_deg.setter
    def servo_angle_deg(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'servo_angle_deg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'servo_angle_deg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._servo_angle_deg = value

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
    def motor1_rpm(self):
        """Message field 'motor1_rpm'."""
        return self._motor1_rpm

    @motor1_rpm.setter
    def motor1_rpm(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'motor1_rpm' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'motor1_rpm' field must be an integer in [-32768, 32767]"
        self._motor1_rpm = value

    @builtins.property
    def motor2_rpm(self):
        """Message field 'motor2_rpm'."""
        return self._motor2_rpm

    @motor2_rpm.setter
    def motor2_rpm(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'motor2_rpm' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'motor2_rpm' field must be an integer in [-32768, 32767]"
        self._motor2_rpm = value

    @builtins.property
    def duration_ms(self):
        """Message field 'duration_ms'."""
        return self._duration_ms

    @duration_ms.setter
    def duration_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'duration_ms' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'duration_ms' field must be an unsigned integer in [0, 65535]"
        self._duration_ms = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SmartCarActuatorTest_Response(type):
    """Metaclass of message 'SmartCarActuatorTest_Response'."""

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
                'messages.srv.SmartCarActuatorTest_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__smart_car_actuator_test__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__smart_car_actuator_test__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__smart_car_actuator_test__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__smart_car_actuator_test__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__smart_car_actuator_test__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SmartCarActuatorTest_Response(metaclass=Metaclass_SmartCarActuatorTest_Response):
    """Message class 'SmartCarActuatorTest_Response'."""

    __slots__ = [
        '_accepted',
        '_message',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        self.message = kwargs.get('message', str())

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
        if self.accepted != other.accepted:
            return False
        if self.message != other.message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


class Metaclass_SmartCarActuatorTest(type):
    """Metaclass of service 'SmartCarActuatorTest'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('messages')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'messages.srv.SmartCarActuatorTest')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__smart_car_actuator_test

            from messages.srv import _smart_car_actuator_test
            if _smart_car_actuator_test.Metaclass_SmartCarActuatorTest_Request._TYPE_SUPPORT is None:
                _smart_car_actuator_test.Metaclass_SmartCarActuatorTest_Request.__import_type_support__()
            if _smart_car_actuator_test.Metaclass_SmartCarActuatorTest_Response._TYPE_SUPPORT is None:
                _smart_car_actuator_test.Metaclass_SmartCarActuatorTest_Response.__import_type_support__()


class SmartCarActuatorTest(metaclass=Metaclass_SmartCarActuatorTest):
    from messages.srv._smart_car_actuator_test import SmartCarActuatorTest_Request as Request
    from messages.srv._smart_car_actuator_test import SmartCarActuatorTest_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
