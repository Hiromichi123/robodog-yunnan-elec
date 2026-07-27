// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from messages:msg/SmartCarMotionState.idl
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
#include "messages/msg/detail/smart_car_motion_state__struct.h"
#include "messages/msg/detail/smart_car_motion_state__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool builtin_interfaces__msg__time__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * builtin_interfaces__msg__time__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool messages__msg__smart_car_motion_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[57];
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
    assert(strncmp("messages.msg._smart_car_motion_state.SmartCarMotionState", full_classname_dest, 56) == 0);
  }
  messages__msg__SmartCarMotionState * ros_message = _ros_message;
  {  // stamp
    PyObject * field = PyObject_GetAttrString(_pymsg, "stamp");
    if (!field) {
      return false;
    }
    if (!builtin_interfaces__msg__time__convert_from_py(field, &ros_message->stamp)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // time_boot_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "time_boot_ms");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->time_boot_ms = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // speed_mps
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_mps");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed_mps = (float)PyFloat_AS_DOUBLE(field);
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
  {  // yaw_rate_dps
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw_rate_dps");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw_rate_dps = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // yaw_deg
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw_deg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw_deg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // curvature_meas
    PyObject * field = PyObject_GetAttrString(_pymsg, "curvature_meas");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->curvature_meas = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // curvature_cmd
    PyObject * field = PyObject_GetAttrString(_pymsg, "curvature_cmd");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->curvature_cmd = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // steering_angle_deg
    PyObject * field = PyObject_GetAttrString(_pymsg, "steering_angle_deg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->steering_angle_deg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // steering_pwm_us
    PyObject * field = PyObject_GetAttrString(_pymsg, "steering_pwm_us");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->steering_pwm_us = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // steering_clamped
    PyObject * field = PyObject_GetAttrString(_pymsg, "steering_clamped");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->steering_clamped = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * messages__msg__smart_car_motion_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SmartCarMotionState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("messages.msg._smart_car_motion_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SmartCarMotionState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  messages__msg__SmartCarMotionState * ros_message = (messages__msg__SmartCarMotionState *)raw_ros_message;
  {  // stamp
    PyObject * field = NULL;
    field = builtin_interfaces__msg__time__convert_to_py(&ros_message->stamp);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "stamp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // time_boot_ms
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->time_boot_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "time_boot_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed_mps
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed_mps);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_mps", field);
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
  {  // yaw_rate_dps
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw_rate_dps);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw_rate_dps", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw_deg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw_deg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw_deg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // curvature_meas
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->curvature_meas);
    {
      int rc = PyObject_SetAttrString(_pymessage, "curvature_meas", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // curvature_cmd
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->curvature_cmd);
    {
      int rc = PyObject_SetAttrString(_pymessage, "curvature_cmd", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // steering_angle_deg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->steering_angle_deg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "steering_angle_deg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // steering_pwm_us
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->steering_pwm_us);
    {
      int rc = PyObject_SetAttrString(_pymessage, "steering_pwm_us", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // steering_clamped
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->steering_clamped);
    {
      int rc = PyObject_SetAttrString(_pymessage, "steering_clamped", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
