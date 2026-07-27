# generated from rosidl_generator_py/resource/_idl.py.em
# with input from messages:srv/SmartCarCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SmartCarCommand_Request(type):
    """Metaclass of message 'SmartCarCommand_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'SMART_CAR_COMMAND_ENABLE': 1,
        'SMART_CAR_COMMAND_DISABLE': 2,
        'SMART_CAR_COMMAND_STOP': 3,
        'SMART_CAR_COMMAND_RECENTER_SERVO': 4,
        'SMART_CAR_COMMAND_GYRO_CAL': 5,
        'SMART_CAR_COMMAND_CLEAR_FAULTS': 6,
        'SMART_CAR_COMMAND_START_CURVATURE_CAL_POINT': 7,
        'SMART_CAR_COMMAND_START_CURVATURE_CAL_LEFT': 8,
        'SMART_CAR_COMMAND_START_CURVATURE_CAL_RIGHT': 9,
        'SMART_CAR_COMMAND_STOP_CURVATURE_CAL': 10,
        'SMART_CAR_COMMAND_FIREWATER_OFF': 11,
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
                'messages.srv.SmartCarCommand_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__smart_car_command__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__smart_car_command__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__smart_car_command__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__smart_car_command__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__smart_car_command__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'SMART_CAR_COMMAND_ENABLE': cls.__constants['SMART_CAR_COMMAND_ENABLE'],
            'SMART_CAR_COMMAND_DISABLE': cls.__constants['SMART_CAR_COMMAND_DISABLE'],
            'SMART_CAR_COMMAND_STOP': cls.__constants['SMART_CAR_COMMAND_STOP'],
            'SMART_CAR_COMMAND_RECENTER_SERVO': cls.__constants['SMART_CAR_COMMAND_RECENTER_SERVO'],
            'SMART_CAR_COMMAND_GYRO_CAL': cls.__constants['SMART_CAR_COMMAND_GYRO_CAL'],
            'SMART_CAR_COMMAND_CLEAR_FAULTS': cls.__constants['SMART_CAR_COMMAND_CLEAR_FAULTS'],
            'SMART_CAR_COMMAND_START_CURVATURE_CAL_POINT': cls.__constants['SMART_CAR_COMMAND_START_CURVATURE_CAL_POINT'],
            'SMART_CAR_COMMAND_START_CURVATURE_CAL_LEFT': cls.__constants['SMART_CAR_COMMAND_START_CURVATURE_CAL_LEFT'],
            'SMART_CAR_COMMAND_START_CURVATURE_CAL_RIGHT': cls.__constants['SMART_CAR_COMMAND_START_CURVATURE_CAL_RIGHT'],
            'SMART_CAR_COMMAND_STOP_CURVATURE_CAL': cls.__constants['SMART_CAR_COMMAND_STOP_CURVATURE_CAL'],
            'SMART_CAR_COMMAND_FIREWATER_OFF': cls.__constants['SMART_CAR_COMMAND_FIREWATER_OFF'],
        }

    @property
    def SMART_CAR_COMMAND_ENABLE(self):
        """Message constant 'SMART_CAR_COMMAND_ENABLE'."""
        return Metaclass_SmartCarCommand_Request.__constants['SMART_CAR_COMMAND_ENABLE']

    @property
    def SMART_CAR_COMMAND_DISABLE(self):
        """Message constant 'SMART_CAR_COMMAND_DISABLE'."""
        return Metaclass_SmartCarCommand_Request.__constants['SMART_CAR_COMMAND_DISABLE']

    @property
    def SMART_CAR_COMMAND_STOP(self):
        """Message constant 'SMART_CAR_COMMAND_STOP'."""
        return Metaclass_SmartCarCommand_Request.__constants['SMART_CAR_COMMAND_STOP']

    @property
    def SMART_CAR_COMMAND_RECENTER_SERVO(self):
        """Message constant 'SMART_CAR_COMMAND_RECENTER_SERVO'."""
        return Metaclass_SmartCarCommand_Request.__constants['SMART_CAR_COMMAND_RECENTER_SERVO']

    @property
    def SMART_CAR_COMMAND_GYRO_CAL(self):
        """Message constant 'SMART_CAR_COMMAND_GYRO_CAL'."""
        return Metaclass_SmartCarCommand_Request.__constants['SMART_CAR_COMMAND_GYRO_CAL']

    @property
    def SMART_CAR_COMMAND_CLEAR_FAULTS(self):
        """Message constant 'SMART_CAR_COMMAND_CLEAR_FAULTS'."""
        return Metaclass_SmartCarCommand_Request.__constants['SMART_CAR_COMMAND_CLEAR_FAULTS']

    @property
    def SMART_CAR_COMMAND_START_CURVATURE_CAL_POINT(self):
        """Message constant 'SMART_CAR_COMMAND_START_CURVATURE_CAL_POINT'."""
        return Metaclass_SmartCarCommand_Request.__constants['SMART_CAR_COMMAND_START_CURVATURE_CAL_POINT']

    @property
    def SMART_CAR_COMMAND_START_CURVATURE_CAL_LEFT(self):
        """Message constant 'SMART_CAR_COMMAND_START_CURVATURE_CAL_LEFT'."""
        return Metaclass_SmartCarCommand_Request.__constants['SMART_CAR_COMMAND_START_CURVATURE_CAL_LEFT']

    @property
    def SMART_CAR_COMMAND_START_CURVATURE_CAL_RIGHT(self):
        """Message constant 'SMART_CAR_COMMAND_START_CURVATURE_CAL_RIGHT'."""
        return Metaclass_SmartCarCommand_Request.__constants['SMART_CAR_COMMAND_START_CURVATURE_CAL_RIGHT']

    @property
    def SMART_CAR_COMMAND_STOP_CURVATURE_CAL(self):
        """Message constant 'SMART_CAR_COMMAND_STOP_CURVATURE_CAL'."""
        return Metaclass_SmartCarCommand_Request.__constants['SMART_CAR_COMMAND_STOP_CURVATURE_CAL']

    @property
    def SMART_CAR_COMMAND_FIREWATER_OFF(self):
        """Message constant 'SMART_CAR_COMMAND_FIREWATER_OFF'."""
        return Metaclass_SmartCarCommand_Request.__constants['SMART_CAR_COMMAND_FIREWATER_OFF']


class SmartCarCommand_Request(metaclass=Metaclass_SmartCarCommand_Request):
    """
    Message class 'SmartCarCommand_Request'.

    Constants:
      SMART_CAR_COMMAND_ENABLE
      SMART_CAR_COMMAND_DISABLE
      SMART_CAR_COMMAND_STOP
      SMART_CAR_COMMAND_RECENTER_SERVO
      SMART_CAR_COMMAND_GYRO_CAL
      SMART_CAR_COMMAND_CLEAR_FAULTS
      SMART_CAR_COMMAND_START_CURVATURE_CAL_POINT
      SMART_CAR_COMMAND_START_CURVATURE_CAL_LEFT
      SMART_CAR_COMMAND_START_CURVATURE_CAL_RIGHT
      SMART_CAR_COMMAND_STOP_CURVATURE_CAL
      SMART_CAR_COMMAND_FIREWATER_OFF
    """

    __slots__ = [
        '_command',
        '_param1',
        '_param2',
        '_param3',
        '_param4',
    ]

    _fields_and_field_types = {
        'command': 'uint16',
        'param1': 'float',
        'param2': 'float',
        'param3': 'float',
        'param4': 'float',
    }

    SLOT_TYPES = (
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
        self.command = kwargs.get('command', int())
        self.param1 = kwargs.get('param1', float())
        self.param2 = kwargs.get('param2', float())
        self.param3 = kwargs.get('param3', float())
        self.param4 = kwargs.get('param4', float())

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
        if self.command != other.command:
            return False
        if self.param1 != other.param1:
            return False
        if self.param2 != other.param2:
            return False
        if self.param3 != other.param3:
            return False
        if self.param4 != other.param4:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def command(self):
        """Message field 'command'."""
        return self._command

    @command.setter
    def command(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'command' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'command' field must be an unsigned integer in [0, 65535]"
        self._command = value

    @builtins.property
    def param1(self):
        """Message field 'param1'."""
        return self._param1

    @param1.setter
    def param1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'param1' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'param1' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._param1 = value

    @builtins.property
    def param2(self):
        """Message field 'param2'."""
        return self._param2

    @param2.setter
    def param2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'param2' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'param2' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._param2 = value

    @builtins.property
    def param3(self):
        """Message field 'param3'."""
        return self._param3

    @param3.setter
    def param3(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'param3' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'param3' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._param3 = value

    @builtins.property
    def param4(self):
        """Message field 'param4'."""
        return self._param4

    @param4.setter
    def param4(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'param4' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'param4' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._param4 = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SmartCarCommand_Response(type):
    """Metaclass of message 'SmartCarCommand_Response'."""

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
                'messages.srv.SmartCarCommand_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__smart_car_command__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__smart_car_command__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__smart_car_command__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__smart_car_command__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__smart_car_command__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SmartCarCommand_Response(metaclass=Metaclass_SmartCarCommand_Response):
    """Message class 'SmartCarCommand_Response'."""

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


class Metaclass_SmartCarCommand(type):
    """Metaclass of service 'SmartCarCommand'."""

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
                'messages.srv.SmartCarCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__smart_car_command

            from messages.srv import _smart_car_command
            if _smart_car_command.Metaclass_SmartCarCommand_Request._TYPE_SUPPORT is None:
                _smart_car_command.Metaclass_SmartCarCommand_Request.__import_type_support__()
            if _smart_car_command.Metaclass_SmartCarCommand_Response._TYPE_SUPPORT is None:
                _smart_car_command.Metaclass_SmartCarCommand_Response.__import_type_support__()


class SmartCarCommand(metaclass=Metaclass_SmartCarCommand):
    from messages.srv._smart_car_command import SmartCarCommand_Request as Request
    from messages.srv._smart_car_command import SmartCarCommand_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
