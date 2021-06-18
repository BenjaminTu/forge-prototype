#include <Python.h>
#include "../../aws-crt-ffi/src/api.h"

static int s_py_stream_seek(void *user_data, int64_t offset, aws_crt_input_stream_seek_basis basis) {
    aws_crt_input_stream *stream = user_data;
    return 1;
}

static int s_py_stream_read(void *user_data, uint8_t *dest, size_t dest_length) {
    aws_crt_input_stream *stream = user_data;
    return 1;
}

static int s_py_stream_get_length(void *user_data, int64_t *out_length) {
    aws_crt_input_stream *stream = user_data;
    return 1;
}

static int s_py_stream_get_status(void *user_data, aws_crt_input_stream_status *out_status) {
    aws_crt_input_stream *stream = user_data;
    return 1;
}

static void s_py_stream_destroy(void *user_data) {
    (void)user_data;
    /* no op, stream will be freed by PHP refcount dropping from InputStream::stream */
}

static PyObject *method_aws_crt_input_stream_options_new(PyObject *self, PyObject *args) {
    return NULL;
}

static PyObject *method_aws_crt_input_stream_options_release(PyObject *self, PyObject *args) {
    return NULL;
}

static PyObject *method_aws_crt_input_stream_options_set_user_data(PyObject *self, PyObject *args) {
    return NULL;
}

static PyObject *method_aws_crt_input_stream_options_set_seek(PyObject *self, PyObject *args) {
    // bind callback function to s_py_stream_seek
    return NULL;
}

static PyObject *method_aws_crt_input_stream_options_set_read(PyObject *self, PyObject *args) {
    // bind callback function to s_py_stream_read
    return NULL;
}

static PyObject *method_aws_crt_input_stream_options_set_get_status(PyObject *self, PyObject *args) {
    // bind callback function to s_py_stream_get_status
    return NULL;
}

static PyObject *method_aws_crt_input_stream_options_set_get_length(PyObject *self, PyObject *args) {
    // bind callback function to s_py_stream_get_length
    return NULL;
}

static PyObject *method_aws_crt_input_stream_options_set_destroy(PyObject *self, PyObject *args) {
    return NULL;
}

static PyObject *method_aws_crt_input_stream_new(PyObject *self, PyObject *args) {

    PyObject *a;

    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        return NULL;
    }
    aws_crt_input_stream_options * b;
    b = (aws_crt_input_stream_options *) PyCapsule_GetPointer(a, "aws_crt_input_stream_options *");

    aws_crt_input_stream_options_set_seek(b, s_py_stream_seek);
    aws_crt_input_stream_options_set_read(b, s_py_stream_read);
    aws_crt_input_stream_options_set_get_status(b, s_py_stream_get_status);
    aws_crt_input_stream_options_set_get_length(b, s_py_stream_get_length);
    aws_crt_input_stream_options_set_destroy(b, s_py_stream_destroy);
    return NULL;
}

static PyObject *method_aws_crt_input_stream_release(PyObject *self, PyObject *args) {
    return NULL;
}

static PyObject *method_aws_crt_input_stream_seek(PyObject *self, PyObject *args) {
    return NULL;
}

static PyObject *method_aws_crt_input_stream_read(PyObject *self, PyObject *args) {
    return NULL;
}

static PyObject *method_aws_crt_input_stream_get_status(PyObject *self, PyObject *args) {
    return NULL;
}

static PyObject *method_aws_crt_input_stream_get_length(PyObject *self, PyObject *args) {
    return NULL;
}


static PyMethodDef input_stream_methods[] = {
    {"aws_crt_input_stream_options_new", method_aws_crt_input_stream_options_new, METH_VARARGS, ""},
    {"aws_crt_input_stream_options_release", method_aws_crt_input_stream_options_release, METH_VARARGS, ""},
    {"aws_crt_input_stream_options_set_user_data", method_aws_crt_input_stream_options_set_user_data, METH_VARARGS, ""},
    {"aws_crt_input_stream_options_set_seek", method_aws_crt_input_stream_options_set_seek, METH_VARARGS, ""},
    {"aws_crt_input_stream_options_set_read", method_aws_crt_input_stream_options_set_read, METH_VARARGS, ""},
    {"aws_crt_input_stream_options_set_get_status", method_aws_crt_input_stream_options_set_get_status, METH_VARARGS, ""},
    {"aws_crt_input_stream_options_set_get_length", method_aws_crt_input_stream_options_set_get_length, METH_VARARGS, ""},
    {"aws_crt_input_stream_options_set_destroy", method_aws_crt_input_stream_options_set_destroy, METH_VARARGS, ""},
    {"aws_crt_input_stream_new", method_aws_crt_input_stream_new, METH_VARARGS, ""},
    {"aws_crt_input_stream_release", method_aws_crt_input_stream_release, METH_VARARGS, ""},
    {"aws_crt_input_stream_seek", method_aws_crt_input_stream_seek, METH_VARARGS, ""},
    {"aws_crt_input_stream_read", method_aws_crt_input_stream_read, METH_VARARGS, ""},
    {"aws_crt_input_stream_get_status", method_aws_crt_input_stream_get_status, METH_VARARGS, ""},
    {"aws_crt_input_stream_get_length", method_aws_crt_input_stream_get_length, METH_VARARGS, ""},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef input_stream_module = {
    PyModuleDef_HEAD_INIT,
    "input_stream",
    "",
    -1,
    input_stream_methods,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_input_stream(void) {
    return PyModule_Create(&input_stream_module);
}