#include <Python.h>
#include "api.h"

static PyObject *method_aws_crt_new_buf(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;

    aws_crt_buf *buf = aws_crt_mem_acquire(sizeof(aws_crt_buf));

    PyObject *ret = PyCapsule_New(buf, "aws_crt_buf *", NULL);
    return ret;
}

static PyObject *method_test_io(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;

    PyObject *a;

    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        return NULL;
    }
    aws_crt_input_stream *b;
    b = (aws_crt_input_stream *) PyCapsule_GetPointer(a, "aws_crt_input_stream *");
    aws_crt_input_stream_status *c = aws_crt_mem_calloc(1, sizeof(aws_crt_input_stream_status));
    aws_crt_input_stream_get_status(b, c);
    printf("%d\n", c->is_end_of_stream);
    printf("%d\n", c->is_valid);

    uint8_t *d;
    d = aws_crt_mem_calloc(1, 4 * sizeof(char));
    aws_crt_input_stream_read(b, d, 4);
    printf("buffer from c: %s\n", d);
    aws_crt_input_stream_read(b, d, 4);
    printf("buffer from c: %s\n", d);
    aws_crt_input_stream_read(b, d, 4);
    printf("buffer from c: %s\n", d);
    aws_crt_input_stream_read(b, d, 4);
    printf("buffer from c: %s\n", d);
    aws_crt_input_stream_read(b, d, 4);
    printf("buffer from c: %s\n", d);

    Py_RETURN_NONE;
}

static PyObject *method_test_http(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;

    PyObject *a;

    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        return NULL;
    }
    aws_crt_buf *b = (aws_crt_buf *) PyCapsule_GetPointer(a, "aws_crt_buf *");
    printf("I got: ");
    for (size_t i = 0; i < b->length; i++) {
        printf("%d, ", (b->blob)[i]);
    }
    printf("\nI got: %zu\n", b->length);

    Py_RETURN_NONE;
}

static PyMethodDef crt_util_methods[] = {
    {"aws_crt_new_buf", method_aws_crt_new_buf, METH_VARARGS, ""},
    {"test_io", method_test_io, METH_VARARGS, ""},
    {"test_http", method_test_http, METH_VARARGS, ""},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef crt_util_module = {
    PyModuleDef_HEAD_INIT,
    "crt_util",
    "",
    -1,
    crt_util_methods,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_crt_util(void) {
    return PyModule_Create(&crt_util_module);
}