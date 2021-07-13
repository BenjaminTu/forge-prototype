#include <Python.h>
#include "api.h"

static PyObject *method_aws_crt_http_message_release(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        printf("method_aws_crt_http_message_release parsing error\n");
        return NULL;
    }
    aws_crt_http_message * b;
    b = (aws_crt_http_message *) PyCapsule_GetPointer(a, "aws_crt_http_message *");
    aws_crt_http_message_release(b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_options_set_expiration_timepoint_seconds(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    uint64_t b;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "OI", &a, &b)) {
        printf("method_aws_crt_credentials_options_set_expiration_timepoint_seconds parsing error\n");
        return NULL;
    }
    aws_crt_credentials_options * c;
    c = (aws_crt_credentials_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_options *");
    aws_crt_credentials_options_set_expiration_timepoint_seconds(c, b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_provider_static_options_new(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *ret = PyCapsule_New((void *)aws_crt_credentials_provider_static_options_new(), "aws_crt_credentials_provider_static_options *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_error_debug_str(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    int32_t a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "i", &a)) {
        printf("method_aws_crt_error_debug_str parsing error\n");
        return NULL;
    }
    const char * ret = aws_crt_error_debug_str(a);
    return PyUnicode_FromString(ret);
}

static PyObject *method_aws_crt_credentials_provider_static_options_release(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        printf("method_aws_crt_credentials_provider_static_options_release parsing error\n");
        return NULL;
    }
    aws_crt_credentials_provider_static_options * b;
    b = (aws_crt_credentials_provider_static_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_provider_static_options *");
    aws_crt_credentials_provider_static_options_release(b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_last_error(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    int32_t ret = aws_crt_last_error();
    return PyLong_FromLong(ret);
}

static PyObject *method_aws_crt_event_loop_group_release(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        printf("method_aws_crt_event_loop_group_release parsing error\n");
        return NULL;
    }
    aws_crt_event_loop_group * b;
    b = (aws_crt_event_loop_group *) PyCapsule_GetPointer(a, "aws_crt_event_loop_group *");
    aws_crt_event_loop_group_release(b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_options_new(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *ret = PyCapsule_New((void *)aws_crt_credentials_options_new(), "aws_crt_credentials_options *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_mem_acquire(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    size_t a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "n", &a)) {
        printf("method_aws_crt_mem_acquire parsing error\n");
        return NULL;
    }
    PyObject *ret = PyCapsule_New((void *)aws_crt_mem_acquire(a), "void *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_event_loop_group_options_new(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *ret = PyCapsule_New((void *)aws_crt_event_loop_group_options_new(), "aws_crt_event_loop_group_options *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_http_message_to_blob(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    PyObject *b;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "OO", &a, &b)) {
        printf("method_aws_crt_http_message_to_blob parsing error\n");
        return NULL;
    }
    const aws_crt_http_message * c;
    c = (const aws_crt_http_message *) PyCapsule_GetPointer(a, "aws_crt_http_message *");
    aws_crt_buf * d;
    d = (aws_crt_buf *) PyCapsule_GetPointer(b, "aws_crt_buf *");
    aws_crt_http_message_to_blob(c, d);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_provider_acquire(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        printf("method_aws_crt_credentials_provider_acquire parsing error\n");
        return NULL;
    }
    aws_crt_credentials_provider * b;
    b = (aws_crt_credentials_provider *) PyCapsule_GetPointer(a, "aws_crt_credentials_provider *");
    PyObject *ret = PyCapsule_New((void *)aws_crt_credentials_provider_acquire(b), "aws_crt_credentials_provider *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_credentials_provider_release(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        printf("method_aws_crt_credentials_provider_release parsing error\n");
        return NULL;
    }
    aws_crt_credentials_provider * b;
    b = (aws_crt_credentials_provider *) PyCapsule_GetPointer(a, "aws_crt_credentials_provider *");
    aws_crt_credentials_provider_release(b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_event_loop_group_acquire(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        printf("method_aws_crt_event_loop_group_acquire parsing error\n");
        return NULL;
    }
    aws_crt_event_loop_group * b;
    b = (aws_crt_event_loop_group *) PyCapsule_GetPointer(a, "aws_crt_event_loop_group *");
    PyObject *ret = PyCapsule_New((void *)aws_crt_event_loop_group_acquire(b), "aws_crt_event_loop_group *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_mem_release(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        printf("method_aws_crt_mem_release parsing error\n");
        return NULL;
    }
    void * b;
    b = (void *) PyCapsule_GetPointer(a, "void *");
    aws_crt_mem_release(b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_http_message_new_from_blob(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    Py_buffer a;
    size_t b;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "y*n", &a, &b)) {
        printf("method_aws_crt_http_message_new_from_blob parsing error\n");
        return NULL;
    }
    const uint8_t * c = (const uint8_t *) a.buf;
    PyObject *ret = PyCapsule_New((void *)aws_crt_http_message_new_from_blob(c, b), "aws_crt_http_message *", NULL);
    PyBuffer_Release(&a);
    return (ret);
}

static PyObject *method_aws_crt_http_headers_release(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        printf("method_aws_crt_http_headers_release parsing error\n");
        return NULL;
    }
    aws_crt_http_headers * b;
    b = (aws_crt_http_headers *) PyCapsule_GetPointer(a, "aws_crt_http_headers *");
    aws_crt_http_headers_release(b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_init(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    aws_crt_init();
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_options_set_access_key_id(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    Py_buffer b;
    size_t c;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "Oy*n", &a, &b, &c)) {
        printf("method_aws_crt_credentials_options_set_access_key_id parsing error\n");
        return NULL;
    }
    aws_crt_credentials_options * d;
    d = (aws_crt_credentials_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_options *");
    const uint8_t * e = (const uint8_t *) b.buf;
    aws_crt_credentials_options_set_access_key_id(d, e, c);
    PyBuffer_Release(&b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_default_allocator(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *ret = PyCapsule_New((void *)aws_crt_default_allocator(), "aws_crt_allocator *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_credentials_new(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        printf("method_aws_crt_credentials_new parsing error\n");
        return NULL;
    }
    const aws_crt_credentials_options * b;
    b = (const aws_crt_credentials_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_options *");
    PyObject *ret = PyCapsule_New((void *)aws_crt_credentials_new(b), "aws_crt_credentials *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_credentials_acquire(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        printf("method_aws_crt_credentials_acquire parsing error\n");
        return NULL;
    }
    aws_crt_credentials * b;
    b = (aws_crt_credentials *) PyCapsule_GetPointer(a, "aws_crt_credentials *");
    PyObject *ret = PyCapsule_New((void *)aws_crt_credentials_acquire(b), "aws_crt_credentials *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_credentials_provider_static_options_set_session_token(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    Py_buffer b;
    size_t c;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "Oy*n", &a, &b, &c)) {
        printf("method_aws_crt_credentials_provider_static_options_set_session_token parsing error\n");
        return NULL;
    }
    aws_crt_credentials_provider_static_options * d;
    d = (aws_crt_credentials_provider_static_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_provider_static_options *");
    const uint8_t * e = (const uint8_t *) b.buf;
    aws_crt_credentials_provider_static_options_set_session_token(d, e, c);
    PyBuffer_Release(&b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_release(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        printf("method_aws_crt_credentials_release parsing error\n");
        return NULL;
    }
    aws_crt_credentials * b;
    b = (aws_crt_credentials *) PyCapsule_GetPointer(a, "aws_crt_credentials *");
    aws_crt_credentials_release(b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_test_error(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    int32_t a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "i", &a)) {
        printf("method_aws_crt_test_error parsing error\n");
        return NULL;
    }
    int32_t ret = aws_crt_test_error(a);
    return PyLong_FromLong(ret);
}

static PyObject *method_aws_crt_http_headers_to_blob(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    PyObject *b;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "OO", &a, &b)) {
        printf("method_aws_crt_http_headers_to_blob parsing error\n");
        return NULL;
    }
    const aws_crt_http_headers * c;
    c = (const aws_crt_http_headers *) PyCapsule_GetPointer(a, "aws_crt_http_headers *");
    aws_crt_buf * d;
    d = (aws_crt_buf *) PyCapsule_GetPointer(b, "aws_crt_buf *");
    aws_crt_http_headers_to_blob(c, d);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_options_set_secret_access_key(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    Py_buffer b;
    size_t c;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "Oy*n", &a, &b, &c)) {
        printf("method_aws_crt_credentials_options_set_secret_access_key parsing error\n");
        return NULL;
    }
    aws_crt_credentials_options * d;
    d = (aws_crt_credentials_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_options *");
    const uint8_t * e = (const uint8_t *) b.buf;
    aws_crt_credentials_options_set_secret_access_key(d, e, c);
    PyBuffer_Release(&b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_options_set_session_token(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    Py_buffer b;
    size_t c;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "Oy*n", &a, &b, &c)) {
        printf("method_aws_crt_credentials_options_set_session_token parsing error\n");
        return NULL;
    }
    aws_crt_credentials_options * d;
    d = (aws_crt_credentials_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_options *");
    const uint8_t * e = (const uint8_t *) b.buf;
    aws_crt_credentials_options_set_session_token(d, e, c);
    PyBuffer_Release(&b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_http_headers_new_from_blob(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    Py_buffer a;
    size_t b;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "y*n", &a, &b)) {
        printf("method_aws_crt_http_headers_new_from_blob parsing error\n");
        return NULL;
    }
    const uint8_t * c = (const uint8_t *) a.buf;
    PyObject *ret = PyCapsule_New((void *)aws_crt_http_headers_new_from_blob(c, b), "aws_crt_http_headers *", NULL);
    PyBuffer_Release(&a);
    return (ret);
}

static PyObject *method_aws_crt_error_str(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    int32_t a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "i", &a)) {
        printf("method_aws_crt_error_str parsing error\n");
        return NULL;
    }
    const char * ret = aws_crt_error_str(a);
    return PyUnicode_FromString(ret);
}

static PyObject *method_aws_crt_credentials_provider_static_new(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        printf("method_aws_crt_credentials_provider_static_new parsing error\n");
        return NULL;
    }
    const aws_crt_credentials_provider_static_options * b;
    b = (const aws_crt_credentials_provider_static_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_provider_static_options *");
    PyObject *ret = PyCapsule_New((void *)aws_crt_credentials_provider_static_new(b), "aws_crt_credentials_provider *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_credentials_options_release(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        printf("method_aws_crt_credentials_options_release parsing error\n");
        return NULL;
    }
    aws_crt_credentials_options * b;
    b = (aws_crt_credentials_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_options *");
    aws_crt_credentials_options_release(b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_provider_static_options_set_access_key_id(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    Py_buffer b;
    size_t c;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "Oy*n", &a, &b, &c)) {
        printf("method_aws_crt_credentials_provider_static_options_set_access_key_id parsing error\n");
        return NULL;
    }
    aws_crt_credentials_provider_static_options * d;
    d = (aws_crt_credentials_provider_static_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_provider_static_options *");
    const uint8_t * e = (const uint8_t *) b.buf;
    aws_crt_credentials_provider_static_options_set_access_key_id(d, e, c);
    PyBuffer_Release(&b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_clean_up(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    aws_crt_clean_up();
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_http_headers_acquire(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        printf("method_aws_crt_http_headers_acquire parsing error\n");
        return NULL;
    }
    aws_crt_http_headers * b;
    b = (aws_crt_http_headers *) PyCapsule_GetPointer(a, "aws_crt_http_headers *");
    PyObject *ret = PyCapsule_New((void *)aws_crt_http_headers_acquire(b), "aws_crt_http_headers *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_http_message_set_body_stream(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    PyObject *b;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "OO", &a, &b)) {
        printf("method_aws_crt_http_message_set_body_stream parsing error\n");
        return NULL;
    }
    aws_crt_http_message * c;
    c = (aws_crt_http_message *) PyCapsule_GetPointer(a, "aws_crt_http_message *");
    aws_crt_input_stream * d;
    d = (aws_crt_input_stream *) PyCapsule_GetPointer(b, "aws_crt_input_stream *");
    aws_crt_http_message_set_body_stream(c, d);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_error_name(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    int32_t a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "i", &a)) {
        printf("method_aws_crt_error_name parsing error\n");
        return NULL;
    }
    const char * ret = aws_crt_error_name(a);
    return PyUnicode_FromString(ret);
}

static PyObject *method_aws_crt_credentials_provider_static_options_set_secret_access_key(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    Py_buffer b;
    size_t c;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "Oy*n", &a, &b, &c)) {
        printf("method_aws_crt_credentials_provider_static_options_set_secret_access_key parsing error\n");
        return NULL;
    }
    aws_crt_credentials_provider_static_options * d;
    d = (aws_crt_credentials_provider_static_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_provider_static_options *");
    const uint8_t * e = (const uint8_t *) b.buf;
    aws_crt_credentials_provider_static_options_set_secret_access_key(d, e, c);
    PyBuffer_Release(&b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_event_loop_group_options_release(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        printf("method_aws_crt_event_loop_group_options_release parsing error\n");
        return NULL;
    }
    aws_crt_event_loop_group_options * b;
    b = (aws_crt_event_loop_group_options *) PyCapsule_GetPointer(a, "aws_crt_event_loop_group_options *");
    aws_crt_event_loop_group_options_release(b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_reset_error(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    aws_crt_reset_error();
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_event_loop_group_new(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        printf("method_aws_crt_event_loop_group_new parsing error\n");
        return NULL;
    }
    const aws_crt_event_loop_group_options * b;
    b = (const aws_crt_event_loop_group_options *) PyCapsule_GetPointer(a, "aws_crt_event_loop_group_options *");
    PyObject *ret = PyCapsule_New((void *)aws_crt_event_loop_group_new(b), "aws_crt_event_loop_group *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_event_loop_group_options_set_max_threads(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    uint16_t b;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "Oi", &a, &b)) {
        printf("method_aws_crt_event_loop_group_options_set_max_threads parsing error\n");
        return NULL;
    }
    aws_crt_event_loop_group_options * c;
    c = (aws_crt_event_loop_group_options *) PyCapsule_GetPointer(a, "aws_crt_event_loop_group_options *");
    aws_crt_event_loop_group_options_set_max_threads(c, b);
    Py_RETURN_NONE;
}

static PyMethodDef aws_methods[] = {
    {"aws_crt_http_message_release", method_aws_crt_http_message_release, METH_VARARGS, ""},
    {"aws_crt_credentials_options_set_expiration_timepoint_seconds", method_aws_crt_credentials_options_set_expiration_timepoint_seconds, METH_VARARGS, ""},
    {"aws_crt_credentials_provider_static_options_new", method_aws_crt_credentials_provider_static_options_new, METH_VARARGS, ""},
    {"aws_crt_error_debug_str", method_aws_crt_error_debug_str, METH_VARARGS, ""},
    {"aws_crt_credentials_provider_static_options_release", method_aws_crt_credentials_provider_static_options_release, METH_VARARGS, ""},
    {"aws_crt_last_error", method_aws_crt_last_error, METH_VARARGS, ""},
    {"aws_crt_event_loop_group_release", method_aws_crt_event_loop_group_release, METH_VARARGS, ""},
    {"aws_crt_credentials_options_new", method_aws_crt_credentials_options_new, METH_VARARGS, ""},
    {"aws_crt_mem_acquire", method_aws_crt_mem_acquire, METH_VARARGS, ""},
    {"aws_crt_event_loop_group_options_new", method_aws_crt_event_loop_group_options_new, METH_VARARGS, ""},
    {"aws_crt_http_message_to_blob", method_aws_crt_http_message_to_blob, METH_VARARGS, ""},
    {"aws_crt_credentials_provider_acquire", method_aws_crt_credentials_provider_acquire, METH_VARARGS, ""},
    {"aws_crt_credentials_provider_release", method_aws_crt_credentials_provider_release, METH_VARARGS, ""},
    {"aws_crt_event_loop_group_acquire", method_aws_crt_event_loop_group_acquire, METH_VARARGS, ""},
    {"aws_crt_mem_release", method_aws_crt_mem_release, METH_VARARGS, ""},
    {"aws_crt_http_message_new_from_blob", method_aws_crt_http_message_new_from_blob, METH_VARARGS, ""},
    {"aws_crt_http_headers_release", method_aws_crt_http_headers_release, METH_VARARGS, ""},
    {"aws_crt_init", method_aws_crt_init, METH_VARARGS, ""},
    {"aws_crt_credentials_options_set_access_key_id", method_aws_crt_credentials_options_set_access_key_id, METH_VARARGS, ""},
    {"aws_crt_default_allocator", method_aws_crt_default_allocator, METH_VARARGS, ""},
    {"aws_crt_credentials_new", method_aws_crt_credentials_new, METH_VARARGS, ""},
    {"aws_crt_credentials_acquire", method_aws_crt_credentials_acquire, METH_VARARGS, ""},
    {"aws_crt_credentials_provider_static_options_set_session_token", method_aws_crt_credentials_provider_static_options_set_session_token, METH_VARARGS, ""},
    {"aws_crt_credentials_release", method_aws_crt_credentials_release, METH_VARARGS, ""},
    {"aws_crt_test_error", method_aws_crt_test_error, METH_VARARGS, ""},
    {"aws_crt_http_headers_to_blob", method_aws_crt_http_headers_to_blob, METH_VARARGS, ""},
    {"aws_crt_credentials_options_set_secret_access_key", method_aws_crt_credentials_options_set_secret_access_key, METH_VARARGS, ""},
    {"aws_crt_credentials_options_set_session_token", method_aws_crt_credentials_options_set_session_token, METH_VARARGS, ""},
    {"aws_crt_http_headers_new_from_blob", method_aws_crt_http_headers_new_from_blob, METH_VARARGS, ""},
    {"aws_crt_error_str", method_aws_crt_error_str, METH_VARARGS, ""},
    {"aws_crt_credentials_provider_static_new", method_aws_crt_credentials_provider_static_new, METH_VARARGS, ""},
    {"aws_crt_credentials_options_release", method_aws_crt_credentials_options_release, METH_VARARGS, ""},
    {"aws_crt_credentials_provider_static_options_set_access_key_id", method_aws_crt_credentials_provider_static_options_set_access_key_id, METH_VARARGS, ""},
    {"aws_crt_clean_up", method_aws_crt_clean_up, METH_VARARGS, ""},
    {"aws_crt_http_headers_acquire", method_aws_crt_http_headers_acquire, METH_VARARGS, ""},
    {"aws_crt_http_message_set_body_stream", method_aws_crt_http_message_set_body_stream, METH_VARARGS, ""},
    {"aws_crt_error_name", method_aws_crt_error_name, METH_VARARGS, ""},
    {"aws_crt_credentials_provider_static_options_set_secret_access_key", method_aws_crt_credentials_provider_static_options_set_secret_access_key, METH_VARARGS, ""},
    {"aws_crt_event_loop_group_options_release", method_aws_crt_event_loop_group_options_release, METH_VARARGS, ""},
    {"aws_crt_reset_error", method_aws_crt_reset_error, METH_VARARGS, ""},
    {"aws_crt_event_loop_group_new", method_aws_crt_event_loop_group_new, METH_VARARGS, ""},
    {"aws_crt_event_loop_group_options_set_max_threads", method_aws_crt_event_loop_group_options_set_max_threads, METH_VARARGS, ""},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef aws_module = {
    PyModuleDef_HEAD_INIT,
    "aws",
    "",
    -1,
    aws_methods,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_aws(void) {
    return PyModule_Create(&aws_module);
}
