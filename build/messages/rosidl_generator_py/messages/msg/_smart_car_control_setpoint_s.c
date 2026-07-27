// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from messages:msg/SmartCarControlSetpoint.idl
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
#include "messages/msg/detail/smart_car_control_setpoint__struct.h"
#include "messages/msg/detail/smart_car_control_setpoint__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool messages__msg__smart_car_control_setpoint__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[65];
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
    assert(strncmp("messages.msg._smart_car_control_setpoint.SmartCarControlSetpoint", full_classname_dest, 64) == 0);
  }
  messages__msg__SmartCarControlSetpoint * ros_message = _ros_message;
  {  // mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mode = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // flags
    PyObject * field = PyObject_GetAttrString(_pymsg, "flags");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->flags = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // target_speed_mps
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_speed_mps");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->target_speed_mps = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // target_curvature
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_curvature");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->target_curvature = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // target_yaw_rate_dps
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_yaw_rate_dps");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->target_yaw_rate_dps = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // target_accel_mps2
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_accel_mps2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->target_accel_mps2 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * messages__msg__smart_car_control_setpoint__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SmartCarControlSetpoint */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("messages.msg._smart_car_control_setpoint");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SmartCarControlSetpoint");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  messages__msg__SmartCarControlSetpoint * ros_message = (messages__msg__SmartCarControlSetpoint *)raw_ros_message;
  {  // mode
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // flags
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->flags);
    {
      int rc = PyObject_SetAttrString(_pymessage, "flags", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_speed_mps
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->target_speed_mps);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_speed_mps", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_curvature
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->target_curvature);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_curvature", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_yaw_rate_dps
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->target_yaw_rate_dps);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_yaw_rate_dps", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_accel_mps2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->target_accel_mps2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_accel_mps2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
