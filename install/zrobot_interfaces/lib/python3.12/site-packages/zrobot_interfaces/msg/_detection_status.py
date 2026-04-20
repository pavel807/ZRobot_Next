# generated from rosidl_generator_py/resource/_idl.py.em
# with input from zrobot_interfaces:msg/DetectionStatus.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DetectionStatus(type):
    """Metaclass of message 'DetectionStatus'."""

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
            module = import_type_support('zrobot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'zrobot_interfaces.msg.DetectionStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__detection_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__detection_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__detection_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__detection_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__detection_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DetectionStatus(metaclass=Metaclass_DetectionStatus):
    """Message class 'DetectionStatus'."""

    __slots__ = [
        '_target_object',
        '_target_found',
        '_zone',
        '_target_count',
        '_confidence',
        '_inference_time_ms',
        '_fps',
        '_frame_width',
        '_frame_height',
        '_target_center_x',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'target_object': 'string',
        'target_found': 'boolean',
        'zone': 'string',
        'target_count': 'int32',
        'confidence': 'float',
        'inference_time_ms': 'float',
        'fps': 'int32',
        'frame_width': 'int32',
        'frame_height': 'int32',
        'target_center_x': 'float',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.target_object = kwargs.get('target_object', str())
        self.target_found = kwargs.get('target_found', bool())
        self.zone = kwargs.get('zone', str())
        self.target_count = kwargs.get('target_count', int())
        self.confidence = kwargs.get('confidence', float())
        self.inference_time_ms = kwargs.get('inference_time_ms', float())
        self.fps = kwargs.get('fps', int())
        self.frame_width = kwargs.get('frame_width', int())
        self.frame_height = kwargs.get('frame_height', int())
        self.target_center_x = kwargs.get('target_center_x', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
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
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.target_object != other.target_object:
            return False
        if self.target_found != other.target_found:
            return False
        if self.zone != other.zone:
            return False
        if self.target_count != other.target_count:
            return False
        if self.confidence != other.confidence:
            return False
        if self.inference_time_ms != other.inference_time_ms:
            return False
        if self.fps != other.fps:
            return False
        if self.frame_width != other.frame_width:
            return False
        if self.frame_height != other.frame_height:
            return False
        if self.target_center_x != other.target_center_x:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def target_object(self):
        """Message field 'target_object'."""
        return self._target_object

    @target_object.setter
    def target_object(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'target_object' field must be of type 'str'"
        self._target_object = value

    @builtins.property
    def target_found(self):
        """Message field 'target_found'."""
        return self._target_found

    @target_found.setter
    def target_found(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'target_found' field must be of type 'bool'"
        self._target_found = value

    @builtins.property
    def zone(self):
        """Message field 'zone'."""
        return self._zone

    @zone.setter
    def zone(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'zone' field must be of type 'str'"
        self._zone = value

    @builtins.property
    def target_count(self):
        """Message field 'target_count'."""
        return self._target_count

    @target_count.setter
    def target_count(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'target_count' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'target_count' field must be an integer in [-2147483648, 2147483647]"
        self._target_count = value

    @builtins.property
    def confidence(self):
        """Message field 'confidence'."""
        return self._confidence

    @confidence.setter
    def confidence(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'confidence' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'confidence' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._confidence = value

    @builtins.property
    def inference_time_ms(self):
        """Message field 'inference_time_ms'."""
        return self._inference_time_ms

    @inference_time_ms.setter
    def inference_time_ms(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'inference_time_ms' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'inference_time_ms' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._inference_time_ms = value

    @builtins.property
    def fps(self):
        """Message field 'fps'."""
        return self._fps

    @fps.setter
    def fps(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'fps' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'fps' field must be an integer in [-2147483648, 2147483647]"
        self._fps = value

    @builtins.property
    def frame_width(self):
        """Message field 'frame_width'."""
        return self._frame_width

    @frame_width.setter
    def frame_width(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'frame_width' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'frame_width' field must be an integer in [-2147483648, 2147483647]"
        self._frame_width = value

    @builtins.property
    def frame_height(self):
        """Message field 'frame_height'."""
        return self._frame_height

    @frame_height.setter
    def frame_height(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'frame_height' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'frame_height' field must be an integer in [-2147483648, 2147483647]"
        self._frame_height = value

    @builtins.property
    def target_center_x(self):
        """Message field 'target_center_x'."""
        return self._target_center_x

    @target_center_x.setter
    def target_center_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'target_center_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'target_center_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._target_center_x = value
