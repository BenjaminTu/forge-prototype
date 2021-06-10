#include <Python.h>

static PyObject *method_add(PyObject *self, PyObject *args) {
    int a, b;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }
    return PyLong_FromLong(a + b);
}

static PyMethodDef AddMethods[] = {
    {"add", method_add, METH_VARARGS, "Python interface for the add in C library"},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef addmodule = {
    PyModuleDef_HEAD_INIT,
    "add",
    "Python interface for the add in C library",
    -1,
    AddMethods
};

PyMODINIT_FUNC PyInit_add(void) {
    return PyModule_Create(&addmodule);
}