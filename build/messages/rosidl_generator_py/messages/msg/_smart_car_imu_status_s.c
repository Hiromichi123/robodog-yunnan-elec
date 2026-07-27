// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from messages:msg/SmartCarImuStatus.idl
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
#include "messages/msg/detail/smart_car_imu_status__struct.h"
#include "messages/msg/detail/smart_car_imu_status__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool builtin_interfaces__msg__time__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * builtin_interfaces__msg__time__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool messages__msg__smart_car_imu_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[53];
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
    assert(strncmp("messages.msg._smart_car_imu_status.SmartCarImuStatus", full_classname_dest, 52) == 0);
  }
  messages__msg__SmartCarImuStatus * ros_message = _ros_message;
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
  {  // sample_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "sample_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sample_count = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // overrun_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "overrun_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->overrun_count = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // error_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "error_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->error_count = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // gyro_x_mdps
    PyObject * field = PyObject_GetAttrString(_pymsg, "gyro_x_mdps");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gyro_x_mdps = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // gyro_y_mdps
    PyObject * field = PyObject_GetAttrString(_pymsg, "gyro_y_mdps");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gyro_y_mdps = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // gyro_z_mdps
    PyObject * field = PyObject_GetAttrString(_pymsg, "gyro_z_mdps");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gyro_z_mdps = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // yaw_rate_raw_dps
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw_rate_raw_dps");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw_rate_raw_dps = (float)PyFloat_AS_DOUBLE(field);
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
  {  // gyro_bias_z_dps
    PyObject * field = PyObject_GetAttrString(_pymsg, "gyro_bias_z_dps");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gyro_bias_z_dps = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // accel_x_mg
    PyObject * field = PyObject_GetAttrString(_pymsg, "accel_x_mg");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->accel_x_mg = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // accel_y_mg
    PyObject * field = PyObject_GetAttrString(_pymsg, "accel_y_mg");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->accel_y_mg = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // accel_z_mg
    PyObject * field = PyObject_GetAttrString(_pymsg, "accel_z_mg");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->accel_z_mg = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // temperature_c_x100
    PyObject * field = PyObject_GetAttrString(_pymsg, "temperature_c_x100");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->temperature_c_x100 = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // calibrated
    PyObject * field = PyObject_GetAttrString(_pymsg, "calibrated");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->calibrated = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * messages__msg__smart_car_imu_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SmartCarImuStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("messages.msg._smart_car_imu_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SmartCarImuStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  messages__msg__SmartCarImuStatus * ros_message = (messages__msg__SmartCarImuStatus *)raw_ros_message;
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
  {  // sample_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->sample_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sample_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // overrun_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->overrun_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "overrun_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // error_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->error_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "error_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gyro_x_mdps
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->gyro_x_mdps);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gyro_x_mdps", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gyro_y_mdps
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->gyro_y_mdps);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gyro_y_mdps", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gyro_z_mdps
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->gyro_z_mdps);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gyro_z_mdps", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw_rate_raw_dps
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw_rate_raw_dps);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw_rate_raw_dps", field);
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
  {  // gyro_bias_z_dps
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gyro_bias_z_dps);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gyro_bias_z_dps", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // accel_x_mg
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->accel_x_mg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "accel_x_mg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // accel_y_mg
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->accel_y_mg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "accel_y_mg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // accel_z_mg
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->accel_z_mg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "accel_z_mg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // temperature_c_x100
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->temperature_c_x100);
    {
      int rc = PyObject_SetAttrString(_pymessage, "temperature_c_x100", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // calibrated
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->calibrated);
    {
      int rc = PyObject_SetAttrString(_pymessage, "calibrated", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
