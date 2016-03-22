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
  return Py_BuildValue("i", result);
}

static PyMethodDef MendelMethods[] = {
    {"mandel", mandel_wrapper, METH_VARARGS, "computes nb of iterations for mandelbrot set for a given complex number"},
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initmandel(void) {
  (void) Py_InitModule("mandel", MendelMethods);
}
