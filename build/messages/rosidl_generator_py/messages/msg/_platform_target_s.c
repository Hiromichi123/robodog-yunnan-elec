// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from messages:msg/PlatformTarget.idl
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
#include "messages/msg/detail/platform_target__struct.h"
#include "messages/msg/detail/platform_target__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool messages__msg__platform_target__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[45];
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
    assert(strncmp("messages.msg._platform_target.PlatformTarget", full_classname_dest, 44) == 0);
  }
  messages__msg__PlatformTarget * ros_message = _ros_message;
  {  // platform
    PyObject * field = PyObject_GetAttrString(_pymsg, "platform");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->platform = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // x
    PyObject * field = PyObject_GetAttrString(_pymsg, "x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y
    PyObject * field = PyObject_GetAttrString(_pymsg, "y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // z
    PyObject * field = PyObject_GetAttrString(_pymsg, "z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->z = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vx_mps
    PyObject * field = PyObject_GetAttrString(_pymsg, "vx_mps");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vx_mps = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vy_mps
    PyObject * field = PyObject_GetAttrString(_pymsg, "vy_mps");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vy_mps = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vz_mps
    PyObject * field = PyObject_GetAttrString(_pymsg, "vz_mps");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vz_mps = (float)PyFloat_AS_DOUBLE(field);
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
  {  // curvature
    PyObject * field = PyObject_GetAttrString(_pymsg, "curvature");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->curvature = (float)PyFloat_AS_DOUBLE(field);
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

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * messages__msg__platform_target__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PlatformTarget */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("messages.msg._platform_target");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PlatformTarget");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  messages__msg__PlatformTarget * ros_message = (messages__msg__PlatformTarget *)raw_ros_message;
  {  // platform
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->platform);
    {
      int rc = PyObject_SetAttrString(_pymessage, "platform", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vx_mps
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vx_mps);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vx_mps", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vy_mps
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vy_mps);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vy_mps", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vz_mps
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vz_mps);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vz_mps", field);
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
  {  // curvature
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->curvature);
    {
      int rc = PyObject_SetAttrString(_pymessage, "curvature", field);
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

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
