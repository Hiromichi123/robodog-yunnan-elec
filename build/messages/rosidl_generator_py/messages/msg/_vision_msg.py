# generated from rosidl_generator_py/resource/_idl.py.em
# with input from messages:msg/VisionMsg.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_VisionMsg(type):
    """Metaclass of message 'VisionMsg'."""

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
                'messages.msg.VisionMsg')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__vision_msg
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__vision_msg
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__vision_msg
            cls._TYPE_SUPPORT = module.type_support_msg__msg__vision_msg
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__vision_msg

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class VisionMsg(metaclass=Metaclass_VisionMsg):
    """Message class 'VisionMsg'."""

    __slots__ = [
        '_is_line_detected',
        '_lateral_error',
        '_angle_error',
        '_is_square_detected',
        '_center_x1_error',
        '_center_y1_error',
        '_is_circle_detected',
        '_center_x2_error',
        '_center_y2_error',
    ]

    _fields_and_field_types = {
        'is_line_detected': 'boolean',
        'lateral_error': 'int32',
        'angle_error': 'float',
        'is_square_detected': 'boolean',
        'center_x1_error': 'int32',
        'center_y1_error': 'int32',
        'is_circle_detected': 'boolean',
        'center_x2_error': 'int32',
        'center_y2_error': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.is_line_detected = kwargs.get('is_line_detected', bool())
        self.lateral_error = kwargs.get('lateral_error', int())
        self.angle_error = kwargs.get('angle_error', float())
        self.is_square_detected = kwargs.get('is_square_detected', bool())
        self.center_x1_error = kwargs.get('center_x1_error', int())
        self.center_y1_error = kwargs.get('center_y1_error', int())
        self.is_circle_detected = kwargs.get('is_circle_detected', bool())
        self.center_x2_error = kwargs.get('center_x2_error', int())
        self.center_y2_error = kwargs.get('center_y2_error', int())

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
        if self.is_line_detected != other.is_line_detected:
            return False
        if self.lateral_error != other.lateral_error:
            return False
        if self.angle_error != other.angle_error:
            return False
        if self.is_square_detected != other.is_square_detected:
            return False
        if self.center_x1_error != other.center_x1_error:
            return False
        if self.center_y1_error != other.center_y1_error:
            return False
        if self.is_circle_detected != other.is_circle_detected:
            return False
        if self.center_x2_error != other.center_x2_error:
            return False
        if self.center_y2_error != other.center_y2_error:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def is_line_detected(self):
        """Message field 'is_line_detected'."""
        return self._is_line_detected

    @is_line_detected.setter
    def is_line_detected(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_line_detected' field must be of type 'bool'"
        self._is_line_detected = value

    @builtins.property
    def lateral_error(self):
        """Message field 'lateral_error'."""
        return self._lateral_error

    @lateral_error.setter
    def lateral_error(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'lateral_error' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'lateral_error' field must be an integer in [-2147483648, 2147483647]"
        self._lateral_error = value

    @builtins.property
    def angle_error(self):
        """Message field 'angle_error'."""
        return self._angle_error

    @angle_error.setter
    def angle_error(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'angle_error' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'angle_error' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._angle_error = value

    @builtins.property
    def is_square_detected(self):
        """Message field 'is_square_detected'."""
        return self._is_square_detected

    @is_square_detected.setter
    def is_square_detected(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_square_detected' field must be of type 'bool'"
        self._is_square_detected = value

    @builtins.property
    def center_x1_error(self):
        """Message field 'center_x1_error'."""
        return self._center_x1_error

    @center_x1_error.setter
    def center_x1_error(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'center_x1_error' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'center_x1_error' field must be an integer in [-2147483648, 2147483647]"
        self._center_x1_error = value

    @builtins.property
    def center_y1_error(self):
        """Message field 'center_y1_error'."""
        return self._center_y1_error

    @center_y1_error.setter
    def center_y1_error(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'center_y1_error' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'center_y1_error' field must be an integer in [-2147483648, 2147483647]"
        self._center_y1_error = value

    @builtins.property
    def is_circle_detected(self):
        """Message field 'is_circle_detected'."""
        return self._is_circle_detected

    @is_circle_detected.setter
    def is_circle_detected(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_circle_detected' field must be of type 'bool'"
        self._is_circle_detected = value

    @builtins.property
    def center_x2_error(self):
        """Message field 'center_x2_error'."""
        return self._center_x2_error

    @center_x2_error.setter
    def center_x2_error(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'center_x2_error' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'center_x2_error' field must be an integer in [-2147483648, 2147483647]"
        self._center_x2_error = value

    @builtins.property
    def center_y2_error(self):
        """Message field 'center_y2_error'."""
        return self._center_y2_error

    @center_y2_error.setter
    def center_y2_error(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'center_y2_error' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'center_y2_error' field must be an integer in [-2147483648, 2147483647]"
        self._center_y2_error = value
