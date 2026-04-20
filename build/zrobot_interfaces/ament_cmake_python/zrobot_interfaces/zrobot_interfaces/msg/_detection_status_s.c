// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from zrobot_interfaces:msg/DetectionStatus.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "zrobot_interfaces/msg/detail/detection_status__struct.h"
#include "zrobot_interfaces/msg/detail/detection_status__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool zrobot_interfaces__msg__detection_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[56];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("zrobot_interfaces.msg._detection_status.DetectionStatus", full_classname_dest, 55) == 0);
  }
  zrobot_interfaces__msg__DetectionStatus * ros_message = _ros_message;
  {  // target_object
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_object");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->target_object, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // target_found
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_found");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->target_found = (Py_True == field);
    Py_DECREF(field);
  }
  {  // zone
    PyObject * field = PyObject_GetAttrString(_pymsg, "zone");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->zone, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // target_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->target_count = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // confidence
    PyObject * field = PyObject_GetAttrString(_pymsg, "confidence");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->confidence = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // inference_time_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "inference_time_ms");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->inference_time_ms = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // fps
    PyObject * field = PyObject_GetAttrString(_pymsg, "fps");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->fps = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // frame_width
    PyObject * field = PyObject_GetAttrString(_pymsg, "frame_width");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->frame_width = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // frame_height
    PyObject * field = PyObject_GetAttrString(_pymsg, "frame_height");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->frame_height = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // target_center_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_center_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->target_center_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * zrobot_interfaces__msg__detection_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DetectionStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("zrobot_interfaces.msg._detection_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DetectionStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  zrobot_interfaces__msg__DetectionStatus * ros_message = (zrobot_interfaces__msg__DetectionStatus *)raw_ros_message;
  {  // target_object
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->target_object.data,
      strlen(ros_message->target_object.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_object", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_found
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->target_found ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_found", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // zone
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->zone.data,
      strlen(ros_message->zone.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "zone", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_count
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->target_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // confidence
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->confidence);
    {
      int rc = PyObject_SetAttrString(_pymessage, "confidence", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // inference_time_ms
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->inference_time_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "inference_time_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fps
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->fps);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fps", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // frame_width
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->frame_width);
    {
      int rc = PyObject_SetAttrString(_pymessage, "frame_width", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // frame_height
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->frame_height);
    {
      int rc = PyObject_SetAttrString(_pymessage, "frame_height", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_center_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->target_center_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_center_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
