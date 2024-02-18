#include <Python.h>

static PyObject *calculator_add(PyObject *self, PyObject *args) {
  PyObject *arg1, *arg2;
  if (!PyArg_ParseTuple(args, "OO", &arg1, &arg2)) {
    return NULL;
  }

  if (PyLong_Check(arg1) && PyLong_Check(arg2)) {
    long a = PyLong_AsLong(arg1);
    long b = PyLong_AsLong(arg2);
    long result = a + b;
    return Py_BuildValue("i", result);
  } else if (PyFloat_Check(arg1) && PyFloat_Check(arg2)) {
    double a = PyFloat_AsDouble(arg1);
    double b = PyFloat_AsDouble(arg2);
    double result = a + b;
    return Py_BuildValue("d", result);
  } else {
    PyErr_SetString(PyExc_TypeError, "Unsupported argument types");
    return NULL;
  }
}

static PyObject *calculator_sub(PyObject *self, PyObject *args) {
  PyObject *arg1, *arg2;
  if (!PyArg_ParseTuple(args, "OO", &arg1, &arg2)) {
    return NULL;
  }

  if (PyLong_Check(arg1) && PyLong_Check(arg2)) {
    long a = PyLong_AsLong(arg1);
    long b = PyLong_AsLong(arg2);
    long result = a - b;
    return Py_BuildValue("i", result);
  } else if (PyFloat_Check(arg1) && PyFloat_Check(arg2)) {
    double a = PyFloat_AsDouble(arg1);
    double b = PyFloat_AsDouble(arg2);
    double result = a - b;
    return Py_BuildValue("d", result);
  } else {
    PyErr_SetString(PyExc_TypeError, "Unsupported argument types");
    return NULL;
  }
}

static PyObject *calculator_mul(PyObject *self, PyObject *args) {
  PyObject *arg1, *arg2;
  if (!PyArg_ParseTuple(args, "OO", &arg1, &arg2)) {
    return NULL;
  }

  if (PyLong_Check(arg1) && PyLong_Check(arg2)) {
    long a = PyLong_AsLong(arg1);
    long b = PyLong_AsLong(arg2);
    long result = a * b;
    return Py_BuildValue("i", result);
  } else if (PyFloat_Check(arg1) && PyFloat_Check(arg2)) {
    double a = PyFloat_AsDouble(arg1);
    double b = PyFloat_AsDouble(arg2);
    double result = a * b;
    return Py_BuildValue("d", result);
  } else {
    PyErr_SetString(PyExc_TypeError, "Unsupported argument types");
    return NULL;
  }
}

static PyObject *calculator_div(PyObject *self, PyObject *args) {
  PyObject *arg1, *arg2;
  if (!PyArg_ParseTuple(args, "OO", &arg1, &arg2)) {
    return NULL;
  }

  if (PyLong_Check(arg1) && PyLong_Check(arg2)) {
    long a = PyLong_AsLong(arg1);
    long b = PyLong_AsLong(arg2);
    long result = a / b;
    return Py_BuildValue("i", result);
  } else if (PyFloat_Check(arg1) && PyFloat_Check(arg2)) {
    double a = PyFloat_AsDouble(arg1);
    double b = PyFloat_AsDouble(arg2);
    double result = a / b;
    return Py_BuildValue("d", result);
  } else {
    PyErr_SetString(PyExc_TypeError, "Unsupported argument types");
    return NULL;
  }
}

static PyMethodDef CalculatorMethods[] = {
    {"add", calculator_add, METH_VARARGS, "Addition"},
    {"sub", calculator_sub, METH_VARARGS, "Subtraction"},
    {"mul", calculator_mul, METH_VARARGS, "Multiplication"},
    {"div", calculator_div, METH_VARARGS, "Division"},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef calculatormodule = {
    PyModuleDef_HEAD_INIT,
    "calculator",  // имя модуля
    NULL,          // описание
    -1,            // счетчик ссылок не используется
    CalculatorMethods};

PyMODINIT_FUNC PyInit_calculator(void) {
  return PyModule_Create(&calculatormodule);
}
