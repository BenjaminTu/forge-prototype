#include <Python.h>
#include "api.h"

PyObject *method_aws_crt_new_buf(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;

    aws_crt_buf *buf = aws_crt_mem_calloc(1, sizeof(aws_crt_buf));

    PyObject *ret = PyCapsule_New(buf, "aws_crt_buf *", NULL);
    return ret;
}

PyObject *method_test_io(PyObject *self, PyObject *args) {
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
    printf("is_end_of_stream: %d\n", c->is_end_of_stream);
    printf("is_valid: %d\n", c->is_valid);

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
    aws_crt_input_stream_read(b, d, 4);
    printf("buffer from c: %s\n", d);

    aws_crt_input_stream_get_status(b, c);
    printf("is_end_of_stream: %d\n", c->is_end_of_stream);
    printf("is_valid: %d\n", c->is_valid);

    Py_RETURN_NONE;
}

PyObject *method_test_http(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;

    PyObject *a;

    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        return NULL;
    }
    aws_crt_buf *b = (aws_crt_buf *) PyCapsule_GetPointer(a, "aws_crt_buf *");
    printf("Expected buffer: [");
    for (size_t i = 0; i < b->length; i++) {
        printf("%d, ", (b->blob)[i]);
    }
    printf("]\nActual buffer len: %zu\n", b->length);

    Py_RETURN_NONE;
}