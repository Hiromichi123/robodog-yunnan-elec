// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from messages:msg/SmartCarStatus.idl
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
#include "messages/msg/detail/smart_car_status__struct.h"
#include "messages/msg/detail/smart_car_status__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool builtin_interfaces__msg__time__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * builtin_interfaces__msg__time__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool messages__msg__smart_car_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[46];
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
    assert(strncmp("messages.msg._smart_car_status.SmartCarStatus", full_classname_dest, 45) == 0);
  }
  messages__msg__SmartCarStatus * ros_message = _ros_message;
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
  {  // mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mode = (uint8_t)PyLong_AsUnsignedLong(field);
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
  {  // fault_flags
    PyObject * field = PyObject_GetAttrString(_pymsg, "fault_flags");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->fault_flags = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // warn_flags
    PyObject * field = PyObject_GetAttrString(_pymsg, "warn_flags");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->warn_flags = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // cmd_age_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "cmd_age_ms");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cmd_age_ms = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // control_loop_hz
    PyObject * field = PyObject_GetAttrString(_pymsg, "control_loop_hz");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->control_loop_hz = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // imu_online
    PyObject * field = PyObject_GetAttrString(_pymsg, "imu_online");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->imu_online = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // can_online
    PyObject * field = PyObject_GetAttrString(_pymsg, "can_online");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->can_online = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // host_online
    PyObject * field = PyObject_GetAttrString(_pymsg, "host_online");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->host_online = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // servo_online
    PyObject * field = PyObject_GetAttrString(_pymsg, "servo_online");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->servo_online = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // motor_online_mask
    PyObject * field = PyObject_GetAttrString(_pymsg, "motor_online_mask");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->motor_online_mask = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * messages__msg__smart_car_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SmartCarStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("messages.msg._smart_car_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SmartCarStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  messages__msg__SmartCarStatus * ros_message = (messages__msg__SmartCarStatus *)raw_ros_message;
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
  {  // fault_flags
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->fault_flags);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fault_flags", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // warn_flags
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->warn_flags);
    {
      int rc = PyObject_SetAttrString(_pymessage, "warn_flags", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cmd_age_ms
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->cmd_age_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cmd_age_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // control_loop_hz
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->control_loop_hz);
    {
      int rc = PyObject_SetAttrString(_pymessage, "control_loop_hz", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // imu_online
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->imu_online);
    {
      int rc = PyObject_SetAttrString(_pymessage, "imu_online", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // can_online
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->can_online);
    {
      int rc = PyObject_SetAttrString(_pymessage, "can_online", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // host_online
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->host_online);
    {
      int rc = PyObject_SetAttrString(_pymessage, "host_online", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // servo_online
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->servo_online);
    {
      int rc = PyObject_SetAttrString(_pymessage, "servo_online", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // motor_online_mask
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->motor_online_mask);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motor_online_mask", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
