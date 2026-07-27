# generated from rosidl_generator_py/resource/_idl.py.em
# with input from messages:msg/Vision.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Vision(type):
    """Metaclass of message 'Vision'."""

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
                'messages.msg.Vision')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__vision
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__vision
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__vision
            cls._TYPE_SUPPORT = module.type_support_msg__msg__vision
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__vision

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Vision(metaclass=Metaclass_Vision):
    """Message class 'Vision'."""

    __slots__ = [
        '_is_detected',
        '_center_x',
        '_center_y',
        '_center_x1_error',
        '_label',
    ]

    _fields_and_field_types = {
        'is_detected': 'boolean',
        'center_x': 'int32',
        'center_y': 'int32',
        'center_x1_error': 'int32',
        'label': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.is_detected = kwargs.get('is_detected', bool())
        self.center_x = kwargs.get('center_x', int())
        self.center_y = kwargs.get('center_y', int())
        self.center_x1_error = kwargs.get('center_x1_error', int())
        self.label = kwargs.get('label', str())

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
        if self.is_detected != other.is_detected:
            return False
        if self.center_x != other.center_x:
            return False
        if self.center_y != other.center_y:
            return False
        if self.center_x1_error != other.center_x1_error:
            return False
        if self.label != other.label:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def is_detected(self):
        """Message field 'is_detected'."""
        return self._is_detected

    @is_detected.setter
    def is_detected(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_detected' field must be of type 'bool'"
        self._is_detected = value

    @builtins.property
    def center_x(self):
        """Message field 'center_x'."""
        return self._center_x

    @center_x.setter
    def center_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'center_x' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'center_x' field must be an integer in [-2147483648, 2147483647]"
        self._center_x = value

    @builtins.property
    def center_y(self):
        """Message field 'center_y'."""
        return self._center_y

    @center_y.setter
    def center_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'center_y' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'center_y' field must be an integer in [-2147483648, 2147483647]"
        self._center_y = value

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
    def label(self):
        """Message field 'label'."""
        return self._label

    @label.setter
    def label(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'label' field must be of type 'str'"
        self._label = value
