#include <Python.h>
#include "../aws-crt-ffi/src/api.h"

static PyObject *method_aws_crt_credentials_options_set_secret_access_key(PyObject *self, PyObject *args) {
	(void)self;
	(void)args;
	aws_crt_credentials_options * a;
	const uint8_t * b;
	size_t c;

	/* Parse arguments */
	if (!PyArg_ParseTuple(args, "oon", &a, &b, &c)) {
		 return NULL;
	}
	aws_crt_credentials_options_set_secret_access_key(a, b, c);
	Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_options_set_session_token(PyObject *self, PyObject *args) {
	(void)self;
	(void)args;
	aws_crt_credentials_options * a;
	const uint8_t * b;
	size_t c;

	/* Parse arguments */
	if (!PyArg_ParseTuple(args, "oon", &a, &b, &c)) {
		 return NULL;
	}
	aws_crt_credentials_options_set_session_token(a, b, c);
	Py_RETURN_NONE;
}

static PyObject *method_aws_crt_default_allocator(PyObject *self, PyObject *args) {
	(void)self;
	(void)args;
	aws_crt_allocator * ret = aws_crt_default_allocator();
	return PyLong_FromVoidPtr((void *)ret);
}

static PyObject *method_aws_crt_credentials_new(PyObject *self, PyObject *args) {
	(void)self;
	(void)args;
	aws_crt_credentials_options * a;

	/* Parse arguments */
	if (!PyArg_ParseTuple(args, "o", &a)) {
		 return NULL;
	}
	aws_crt_credentials * ret = aws_crt_credentials_new(a);
	return PyLong_FromVoidPtr((void *)ret);
}

static PyObject *method_aws_crt_credentials_options_release(PyObject *self, PyObject *args) {
	(void)self;
	(void)args;
	aws_crt_credentials_options * a;

	/* Parse arguments */
	if (!PyArg_ParseTuple(args, "o", &a)) {
		 return NULL;
	}
	aws_crt_credentials_options_release(a);
	Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_options_set_expiration_timepoint_seconds(PyObject *self, PyObject *args) {
	(void)self;
	(void)args;
	aws_crt_credentials_options * a;
	uint64_t b;

	/* Parse arguments */
	if (!PyArg_ParseTuple(args, "oI", &a, &b)) {
		 return NULL;
	}
	aws_crt_credentials_options_set_expiration_timepoint_seconds(a, b);
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

static PyObject *method_aws_crt_credentials_release(PyObject *self, PyObject *args) {
	(void)self;
	(void)args;
	aws_crt_credentials * a;

	/* Parse arguments */
	if (!PyArg_ParseTuple(args, "o", &a)) {
		 return NULL;
	}
	aws_crt_credentials_release(a);
	Py_RETURN_NONE;
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

static PyObject *method_aws_crt_init(PyObject *self, PyObject *args) {
	(void)self;
	(void)args;
	aws_crt_init();
	Py_RETURN_NONE;
}

static PyObject *method_aws_crt_reset_error(PyObject *self, PyObject *args) {
	(void)self;
	(void)args;
	aws_crt_reset_error();
	Py_RETURN_NONE;
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

static PyObject *method_aws_crt_mem_release(PyObject *self, PyObject *args) {
	(void)self;
	(void)args;
	void * a;

	/* Parse arguments */
	if (!PyArg_ParseTuple(args, "o", &a)) {
		 return NULL;
	}
	aws_crt_mem_release(a);
	Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_options_set_access_key_id(PyObject *self, PyObject *args) {
	(void)self;
	(void)args;
	aws_crt_credentials_options * a;
	const uint8_t * b;
	size_t c;

	/* Parse arguments */
	if (!PyArg_ParseTuple(args, "oon", &a, &b, &c)) {
		 return NULL;
	}
	aws_crt_credentials_options_set_access_key_id(a, b, c);
	Py_RETURN_NONE;
}

static PyObject *method_aws_crt_credentials_options_new(PyObject *self, PyObject *args) {
	(void)self;
	(void)args;
	aws_crt_credentials_options * ret = aws_crt_credentials_options_new();
	return PyLong_FromVoidPtr((void *)ret);
}

static PyObject *method_aws_crt_mem_acquire(PyObject *self, PyObject *args) {
	(void)self;
	(void)args;
	size_t a;

	/* Parse arguments */
	if (!PyArg_ParseTuple(args, "n", &a)) {
		 return NULL;
	}
	void * ret = aws_crt_mem_acquire(a);
	return PyLong_FromVoidPtr((void *)ret);
}

static PyObject *method_aws_crt_credentials_acquire(PyObject *self, PyObject *args) {
	(void)self;
	(void)args;
	aws_crt_credentials * a;

	/* Parse arguments */
	if (!PyArg_ParseTuple(args, "o", &a)) {
		 return NULL;
	}
	aws_crt_credentials * ret = aws_crt_credentials_acquire(a);
	return PyLong_FromVoidPtr((void *)ret);
}

static PyObject *method_aws_crt_clean_up(PyObject *self, PyObject *args) {
	(void)self;
	(void)args;
	aws_crt_clean_up();
	Py_RETURN_NONE;
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

static PyObject *method_aws_crt_last_error(PyObject *self, PyObject *args) {
	(void)self;
	(void)args;
	int32_t ret = aws_crt_last_error();
	return PyLong_FromLong(ret);
}

static PyMethodDef aws_methods[] = {
	{"aws_crt_credentials_options_set_secret_access_key", method_aws_crt_credentials_options_set_secret_access_key, METH_VARARGS, ""},
	{"aws_crt_credentials_options_set_session_token", method_aws_crt_credentials_options_set_session_token, METH_VARARGS, ""},
	{"aws_crt_default_allocator", method_aws_crt_default_allocator, METH_VARARGS, ""},
	{"aws_crt_credentials_new", method_aws_crt_credentials_new, METH_VARARGS, ""},
	{"aws_crt_credentials_options_release", method_aws_crt_credentials_options_release, METH_VARARGS, ""},
	{"aws_crt_credentials_options_set_expiration_timepoint_seconds", method_aws_crt_credentials_options_set_expiration_timepoint_seconds, METH_VARARGS, ""},
	{"aws_crt_error_debug_str", method_aws_crt_error_debug_str, METH_VARARGS, ""},
	{"aws_crt_credentials_release", method_aws_crt_credentials_release, METH_VARARGS, ""},
	{"aws_crt_error_name", method_aws_crt_error_name, METH_VARARGS, ""},
	{"aws_crt_init", method_aws_crt_init, METH_VARARGS, ""},
	{"aws_crt_reset_error", method_aws_crt_reset_error, METH_VARARGS, ""},
	{"aws_crt_test_error", method_aws_crt_test_error, METH_VARARGS, ""},
	{"aws_crt_mem_release", method_aws_crt_mem_release, METH_VARARGS, ""},
	{"aws_crt_credentials_options_set_access_key_id", method_aws_crt_credentials_options_set_access_key_id, METH_VARARGS, ""},
	{"aws_crt_credentials_options_new", method_aws_crt_credentials_options_new, METH_VARARGS, ""},
	{"aws_crt_mem_acquire", method_aws_crt_mem_acquire, METH_VARARGS, ""},
	{"aws_crt_credentials_acquire", method_aws_crt_credentials_acquire, METH_VARARGS, ""},
	{"aws_crt_clean_up", method_aws_crt_clean_up, METH_VARARGS, ""},
	{"aws_crt_error_str", method_aws_crt_error_str, METH_VARARGS, ""},
	{"aws_crt_last_error", method_aws_crt_last_error, METH_VARARGS, ""},
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