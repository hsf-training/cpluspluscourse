#include <Python.h>
#include "mendel.hpp"

static PyObject * mendel_wrapper(PyObject * self,
                                 PyObject * args) {
  // Parse Input
  float r, i;
  if (!PyArg_ParseTuple(args, "ff", &r, &i)) return NULL;
  // Call C function
  int result = mendel(Complex(r, i));
  // Build returned objects
  return Py_BuildValue("i", result);
}

static PyMethodDef MendelMethods[] = {
    {"mendel", mendel_wrapper, METH_VARARGS, "computes nb of iterations for mendelbrot set for a given complex number"},
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initmendel(void) {
  (void) Py_InitModule("mendel", MendelMethods);
}
