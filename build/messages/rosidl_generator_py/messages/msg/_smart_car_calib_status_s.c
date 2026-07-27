// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from messages:msg/SmartCarCalibStatus.idl
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
#include "messages/msg/detail/smart_car_calib_status__struct.h"
#include "messages/msg/detail/smart_car_calib_status__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool builtin_interfaces__msg__time__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * builtin_interfaces__msg__time__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool messages__msg__smart_car_calib_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("messages.msg._smart_car_calib_status.SmartCarCalibStatus", full_classname_dest, 56) == 0);
  }
  messages__msg__SmartCarCalibStatus * ros_message = _ros_message;
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
  {  // point_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "point_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->point_id = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // sweep_index
    PyObject * field = PyObject_GetAttrString(_pymsg, "sweep_index");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sweep_index = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // sweep_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "sweep_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sweep_count = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // valid_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "valid_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->valid_count = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // invalid_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "invalid_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->invalid_count = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // v_center_avg
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_center_avg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_center_avg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // yaw_rate_avg
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw_rate_avg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw_rate_avg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // kappa_avg
    PyObject * field = PyObject_GetAttrString(_pymsg, "kappa_avg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->kappa_avg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // radius_est
    PyObject * field = PyObject_GetAttrString(_pymsg, "radius_est");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->radius_est = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // target_rpm
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_rpm");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->target_rpm = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // servo_pwm_us
    PyObject * field = PyObject_GetAttrString(_pymsg, "servo_pwm_us");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->servo_pwm_us = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // state
    PyObject * field = PyObject_GetAttrString(_pymsg, "state");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->state = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // sweep_enabled
    PyObject * field = PyObject_GetAttrString(_pymsg, "sweep_enabled");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sweep_enabled = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // yaw_sign_inverted
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw_sign_inverted");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->yaw_sign_inverted = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * messages__msg__smart_car_calib_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SmartCarCalibStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("messages.msg._smart_car_calib_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SmartCarCalibStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  messages__msg__SmartCarCalibStatus * ros_message = (messages__msg__SmartCarCalibStatus *)raw_ros_message;
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
  {  // point_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->point_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "point_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sweep_index
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->sweep_index);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sweep_index", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sweep_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->sweep_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sweep_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // valid_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->valid_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "valid_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // invalid_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->invalid_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "invalid_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_center_avg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_center_avg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_center_avg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw_rate_avg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw_rate_avg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw_rate_avg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // kappa_avg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->kappa_avg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "kappa_avg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // radius_est
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->radius_est);
    {
      int rc = PyObject_SetAttrString(_pymessage, "radius_est", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_rpm
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->target_rpm);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_rpm", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // servo_pwm_us
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->servo_pwm_us);
    {
      int rc = PyObject_SetAttrString(_pymessage, "servo_pwm_us", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // state
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->state);
    {
      int rc = PyObject_SetAttrString(_pymessage, "state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sweep_enabled
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->sweep_enabled);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sweep_enabled", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw_sign_inverted
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->yaw_sign_inverted);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw_sign_inverted", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
