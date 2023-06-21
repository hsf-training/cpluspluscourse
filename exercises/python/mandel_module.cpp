#include <Python.h>
#include "mandel.hpp"

static PyObject * mandel_wrapper(PyObject * self,
                                 PyObject * args) {
  // Parse Input
  float r, i;
  if (!PyArg_ParseTuple(args, "ff", &r, &i)) return NULL;
  // Call C function
  int result = mandel(Complex(r, i));
  // Build returned objects
  return PyLong_FromLong(result);
}

static PyMethodDef mandelMethods[] = {
    {"mandel", mandel_wrapper, METH_VARARGS, "computes nb of iterations for mandelbrot set for a given complex number"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef mandelModule = {
    PyModuleDef_HEAD_INIT,
    "mandel", /* name of module */
    NULL,     /* module documentation */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    mandelMethods
};

PyMODINIT_FUNC PyInit_mandel(void) {
  return PyModule_Create(&mandelModule);
}
