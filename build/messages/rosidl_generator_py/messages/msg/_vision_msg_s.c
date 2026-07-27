// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from messages:msg/VisionMsg.idl
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
#include "messages/msg/detail/vision_msg__struct.h"
#include "messages/msg/detail/vision_msg__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool messages__msg__vision_msg__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[35];
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
    assert(strncmp("messages.msg._vision_msg.VisionMsg", full_classname_dest, 34) == 0);
  }
  messages__msg__VisionMsg * ros_message = _ros_message;
  {  // is_line_detected
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_line_detected");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_line_detected = (Py_True == field);
    Py_DECREF(field);
  }
  {  // lateral_error
    PyObject * field = PyObject_GetAttrString(_pymsg, "lateral_error");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->lateral_error = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // angle_error
    PyObject * field = PyObject_GetAttrString(_pymsg, "angle_error");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->angle_error = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // is_square_detected
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_square_detected");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_square_detected = (Py_True == field);
    Py_DECREF(field);
  }
  {  // center_x1_error
    PyObject * field = PyObject_GetAttrString(_pymsg, "center_x1_error");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->center_x1_error = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // center_y1_error
    PyObject * field = PyObject_GetAttrString(_pymsg, "center_y1_error");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->center_y1_error = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // is_circle_detected
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_circle_detected");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_circle_detected = (Py_True == field);
    Py_DECREF(field);
  }
  {  // center_x2_error
    PyObject * field = PyObject_GetAttrString(_pymsg, "center_x2_error");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->center_x2_error = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // center_y2_error
    PyObject * field = PyObject_GetAttrString(_pymsg, "center_y2_error");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->center_y2_error = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * messages__msg__vision_msg__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of VisionMsg */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("messages.msg._vision_msg");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "VisionMsg");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  messages__msg__VisionMsg * ros_message = (messages__msg__VisionMsg *)raw_ros_message;
  {  // is_line_detected
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_line_detected ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_line_detected", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lateral_error
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->lateral_error);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lateral_error", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // angle_error
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->angle_error);
    {
      int rc = PyObject_SetAttrString(_pymessage, "angle_error", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_square_detected
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_square_detected ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_square_detected", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // center_x1_error
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->center_x1_error);
    {
      int rc = PyObject_SetAttrString(_pymessage, "center_x1_error", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // center_y1_error
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->center_y1_error);
    {
      int rc = PyObject_SetAttrString(_pymessage, "center_y1_error", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_circle_detected
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_circle_detected ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_circle_detected", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // center_x2_error
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->center_x2_error);
    {
      int rc = PyObject_SetAttrString(_pymessage, "center_x2_error", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // center_y2_error
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->center_y2_error);
    {
      int rc = PyObject_SetAttrString(_pymessage, "center_y2_error", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
