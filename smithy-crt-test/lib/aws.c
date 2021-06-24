#include <Python.h>
#include "api.h"

static PyObject *method_aws_crt_credentials_new(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        return NULL;
    }
    const aws_crt_credentials_options * b;
    b = (const aws_crt_credentials_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_options *");
    PyObject *ret = PyCapsule_New((void *)aws_crt_credentials_new(b), "aws_crt_credentials *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_error_str(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    int32_t a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "i", &a)) {
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
        return NULL;
    }
    aws_crt_credentials_options * b;
    b = (aws_crt_credentials_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_options *");
    aws_crt_credentials_options_release(b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_options_set_secret_access_key(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    const uint8_t * b;
    size_t c;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "Osn", &a, &b, &c)) {
        return NULL;
    }
    aws_crt_credentials_options * d;
    d = (aws_crt_credentials_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_options *");
    aws_crt_credentials_options_set_secret_access_key(d, b, c);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_options_set_session_token(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    const uint8_t * b;
    size_t c;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "Osn", &a, &b, &c)) {
        return NULL;
    }
    aws_crt_credentials_options * d;
    d = (aws_crt_credentials_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_options *");
    aws_crt_credentials_options_set_session_token(d, b, c);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_provider_static_options_set_session_token(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    const uint8_t * b;
    size_t c;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "Osn", &a, &b, &c)) {
        return NULL;
    }
    aws_crt_credentials_provider_static_options * d;
    d = (aws_crt_credentials_provider_static_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_provider_static_options *");
    aws_crt_credentials_provider_static_options_set_session_token(d, b, c);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_event_loop_group_new(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        return NULL;
    }
    const aws_crt_event_loop_group_options * b;
    b = (const aws_crt_event_loop_group_options *) PyCapsule_GetPointer(a, "aws_crt_event_loop_group_options *");
    PyObject *ret = PyCapsule_New((void *)aws_crt_event_loop_group_new(b), "aws_crt_event_loop_group *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_credentials_provider_static_options_release(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        return NULL;
    }
    aws_crt_credentials_provider_static_options * b;
    b = (aws_crt_credentials_provider_static_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_provider_static_options *");
    aws_crt_credentials_provider_static_options_release(b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_provider_static_options_set_access_key_id(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    const uint8_t * b;
    size_t c;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "Osn", &a, &b, &c)) {
        return NULL;
    }
    aws_crt_credentials_provider_static_options * d;
    d = (aws_crt_credentials_provider_static_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_provider_static_options *");
    aws_crt_credentials_provider_static_options_set_access_key_id(d, b, c);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_options_new(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *ret = PyCapsule_New((void *)aws_crt_credentials_options_new(), "aws_crt_credentials_options *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_init(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    aws_crt_init();
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_provider_static_options_set_secret_access_key(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    const uint8_t * b;
    size_t c;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "Osn", &a, &b, &c)) {
        return NULL;
    }
    aws_crt_credentials_provider_static_options * d;
    d = (aws_crt_credentials_provider_static_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_provider_static_options *");
    aws_crt_credentials_provider_static_options_set_secret_access_key(d, b, c);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_last_error(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    int32_t ret = aws_crt_last_error();
    return PyLong_FromLong(ret);
}

static PyObject *method_aws_crt_clean_up(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    aws_crt_clean_up();
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_event_loop_group_release(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        return NULL;
    }
    aws_crt_event_loop_group * b;
    b = (aws_crt_event_loop_group *) PyCapsule_GetPointer(a, "aws_crt_event_loop_group *");
    aws_crt_event_loop_group_release(b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_default_allocator(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *ret = PyCapsule_New((void *)aws_crt_default_allocator(), "aws_crt_allocator *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_credentials_provider_acquire(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        return NULL;
    }
    aws_crt_credentials_provider * b;
    b = (aws_crt_credentials_provider *) PyCapsule_GetPointer(a, "aws_crt_credentials_provider *");
    PyObject *ret = PyCapsule_New((void *)aws_crt_credentials_provider_acquire(b), "aws_crt_credentials_provider *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_credentials_provider_static_options_new(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *ret = PyCapsule_New((void *)aws_crt_credentials_provider_static_options_new(), "aws_crt_credentials_provider_static_options *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_test_error(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    int32_t a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "i", &a)) {
        return NULL;
    }
    int32_t ret = aws_crt_test_error(a);
    return PyLong_FromLong(ret);
}

static PyObject *method_aws_crt_event_loop_group_options_set_max_threads(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    uint16_t b;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "OI", &a, &b)) {
        return NULL;
    }
    aws_crt_event_loop_group_options * c;
    c = (aws_crt_event_loop_group_options *) PyCapsule_GetPointer(a, "aws_crt_event_loop_group_options *");
    aws_crt_event_loop_group_options_set_max_threads(c, b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_release(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        return NULL;
    }
    aws_crt_credentials * b;
    b = (aws_crt_credentials *) PyCapsule_GetPointer(a, "aws_crt_credentials *");
    aws_crt_credentials_release(b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_event_loop_group_options_new(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *ret = PyCapsule_New((void *)aws_crt_event_loop_group_options_new(), "aws_crt_event_loop_group_options *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_mem_acquire(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    size_t a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "n", &a)) {
        return NULL;
    }
    PyObject *ret = PyCapsule_New((void *)aws_crt_mem_acquire(a), "void *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_credentials_options_set_access_key_id(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    const uint8_t * b;
    size_t c;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "Osn", &a, &b, &c)) {
        return NULL;
    }
    aws_crt_credentials_options * d;
    d = (aws_crt_credentials_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_options *");
    aws_crt_credentials_options_set_access_key_id(d, b, c);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_acquire(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        return NULL;
    }
    aws_crt_credentials * b;
    b = (aws_crt_credentials *) PyCapsule_GetPointer(a, "aws_crt_credentials *");
    PyObject *ret = PyCapsule_New((void *)aws_crt_credentials_acquire(b), "aws_crt_credentials *", NULL);
    return (ret);
}

static PyObject *method_aws_crt_error_name(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    int32_t a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "i", &a)) {
        return NULL;
    }
    const char * ret = aws_crt_error_name(a);
    return PyUnicode_FromString(ret);
}

static PyObject *method_aws_crt_credentials_options_set_expiration_timepoint_seconds(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    uint64_t b;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "OI", &a, &b)) {
        return NULL;
    }
    aws_crt_credentials_options * c;
    c = (aws_crt_credentials_options *) PyCapsule_GetPointer(a, "aws_crt_credentials_options *");
    aws_crt_credentials_options_set_expiration_timepoint_seconds(c, b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_reset_error(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    aws_crt_reset_error();
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_error_debug_str(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    int32_t a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "i", &a)) {
        return NULL;
    }
    const char * ret = aws_crt_error_debug_str(a);
    return PyUnicode_FromString(ret);
}

static PyObject *method_aws_crt_event_loop_group_options_release(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        return NULL;
    }
    aws_crt_event_loop_group_options * b;
    b = (aws_crt_event_loop_group_options *) PyCapsule_GetPointer(a, "aws_crt_event_loop_group_options *");
    aws_crt_event_loop_group_options_release(b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_mem_release(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        return NULL;
    }
    void * b;
    b = (void *) PyCapsule_GetPointer(a, "void *");
    aws_crt_mem_release(b);
    Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_provider_release(PyObject *self, PyObject *args) {
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
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
        return NULL;
    }
    aws_crt_event_loop_group * b;
    b = (aws_crt_event_loop_group *) PyCapsule_GetPointer(a, "aws_crt_event_loop_group *");
    PyObject *ret = PyCapsule_New((void *)aws_crt_event_loop_group_acquire(b), "aws_crt_event_loop_group *", NULL);
    return (ret);
}

static PyMethodDef aws_methods[] = {
    {"aws_crt_credentials_new", method_aws_crt_credentials_new, METH_VARARGS, ""},
    {"aws_crt_error_str", method_aws_crt_error_str, METH_VARARGS, ""},
    {"aws_crt_credentials_provider_static_new", method_aws_crt_credentials_provider_static_new, METH_VARARGS, ""},
    {"aws_crt_credentials_options_release", method_aws_crt_credentials_options_release, METH_VARARGS, ""},
    {"aws_crt_credentials_options_set_secret_access_key", method_aws_crt_credentials_options_set_secret_access_key, METH_VARARGS, ""},
    {"aws_crt_credentials_options_set_session_token", method_aws_crt_credentials_options_set_session_token, METH_VARARGS, ""},
    {"aws_crt_credentials_provider_static_options_set_session_token", method_aws_crt_credentials_provider_static_options_set_session_token, METH_VARARGS, ""},
    {"aws_crt_event_loop_group_new", method_aws_crt_event_loop_group_new, METH_VARARGS, ""},
    {"aws_crt_credentials_provider_static_options_release", method_aws_crt_credentials_provider_static_options_release, METH_VARARGS, ""},
    {"aws_crt_credentials_provider_static_options_set_access_key_id", method_aws_crt_credentials_provider_static_options_set_access_key_id, METH_VARARGS, ""},
    {"aws_crt_credentials_options_new", method_aws_crt_credentials_options_new, METH_VARARGS, ""},
    {"aws_crt_init", method_aws_crt_init, METH_VARARGS, ""},
    {"aws_crt_credentials_provider_static_options_set_secret_access_key", method_aws_crt_credentials_provider_static_options_set_secret_access_key, METH_VARARGS, ""},
    {"aws_crt_last_error", method_aws_crt_last_error, METH_VARARGS, ""},
    {"aws_crt_clean_up", method_aws_crt_clean_up, METH_VARARGS, ""},
    {"aws_crt_event_loop_group_release", method_aws_crt_event_loop_group_release, METH_VARARGS, ""},
    {"aws_crt_default_allocator", method_aws_crt_default_allocator, METH_VARARGS, ""},
    {"aws_crt_credentials_provider_acquire", method_aws_crt_credentials_provider_acquire, METH_VARARGS, ""},
    {"aws_crt_credentials_provider_static_options_new", method_aws_crt_credentials_provider_static_options_new, METH_VARARGS, ""},
    {"aws_crt_test_error", method_aws_crt_test_error, METH_VARARGS, ""},
    {"aws_crt_event_loop_group_options_set_max_threads", method_aws_crt_event_loop_group_options_set_max_threads, METH_VARARGS, ""},
    {"aws_crt_credentials_release", method_aws_crt_credentials_release, METH_VARARGS, ""},
    {"aws_crt_event_loop_group_options_new", method_aws_crt_event_loop_group_options_new, METH_VARARGS, ""},
    {"aws_crt_mem_acquire", method_aws_crt_mem_acquire, METH_VARARGS, ""},
    {"aws_crt_credentials_options_set_access_key_id", method_aws_crt_credentials_options_set_access_key_id, METH_VARARGS, ""},
    {"aws_crt_credentials_acquire", method_aws_crt_credentials_acquire, METH_VARARGS, ""},
    {"aws_crt_error_name", method_aws_crt_error_name, METH_VARARGS, ""},
    {"aws_crt_credentials_options_set_expiration_timepoint_seconds", method_aws_crt_credentials_options_set_expiration_timepoint_seconds, METH_VARARGS, ""},
    {"aws_crt_reset_error", method_aws_crt_reset_error, METH_VARARGS, ""},
    {"aws_crt_error_debug_str", method_aws_crt_error_debug_str, METH_VARARGS, ""},
    {"aws_crt_event_loop_group_options_release", method_aws_crt_event_loop_group_options_release, METH_VARARGS, ""},
    {"aws_crt_mem_release", method_aws_crt_mem_release, METH_VARARGS, ""},
    {"aws_crt_credentials_provider_release", method_aws_crt_credentials_provider_release, METH_VARARGS, ""},
    {"aws_crt_event_loop_group_acquire", method_aws_crt_event_loop_group_acquire, METH_VARARGS, ""},
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
