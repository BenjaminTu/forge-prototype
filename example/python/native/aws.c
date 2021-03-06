#include <Python.h>

typedef struct aws_allocator aws_crt_allocator;
aws_crt_allocator *aws_crt_default_allocator(void);

typedef int(aws_crt_input_stream_seek_fn)(void *user_data, int64_t offset, aws_crt_input_stream_seek_basis seek_basis);
void aws_crt_input_stream_options_set_seek(
    int *options,
    aws_crt_input_stream_seek_fn *seek_fn);

const char *aws_crt_init(void);
const char *aws_crt_clean_up(void);
const char *aws_crt_test_error(int);
const char *aws_crt_mem_acquire(size_t size);
const char *aws_crt_mem_release(void *mem);

aws_crt_allocator *aws_crt_default_allocator() {
    return malloc(10);
}

const char *aws_crt_init() {
    return "calling aws_crt_init";
}

const char *aws_crt_clean_up() {
    return "calling aws_crt_clean_up";
}

const char *aws_crt_test_error(int a) {
    return "calling aws_crt_test_error";
}

const char *aws_crt_mem_acquire(size_t size) {
    return "calling aws_crt_test_error";
}

const char *aws_crt_mem_release(void *mem) {
    return "calling aws_crt_test_error";
}

static PyObject *method_aws_crt_default_allocator(PyObject *self, PyObject *args) {
    aws_crt_allocator * ret = aws_crt_default_allocator();
    return PyLong_FromVoidPtr((void *)ret);
}

static PyObject *method_aws_crt_init(PyObject *self, PyObject *args) {
    const char *ret = aws_crt_init();
    return PyUnicode_FromString(ret);
}

static PyObject *method_aws_crt_clean_up(PyObject *self, PyObject *args) {
    const char *ret = aws_crt_clean_up();
    return PyUnicode_FromString(ret);
}

static PyObject *method_aws_crt_test_error(PyObject *self, PyObject *args) {
    size_t a;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "n", &a)) {
        return NULL;
    }

    const char *ret = aws_crt_test_error(a);
    return PyUnicode_FromString(ret);
}

static PyObject *method_aws_crt_mem_acquire(PyObject *self, PyObject *args) {
    size_t a;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "n", &a)) {
        return NULL;
    }
    const char *ret = aws_crt_mem_acquire(a);
    return PyUnicode_FromString(ret);
}

static PyObject *method_aws_crt_mem_release(PyObject *self, PyObject *args) {
    void *a;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "O", &a)) {
        return NULL;
    }

    const char *ret = aws_crt_mem_release(a);
    return PyUnicode_FromString(ret);
}

static PyMethodDef AwsMethods[] = {
    {"aws_crt_init", method_aws_crt_init, METH_VARARGS, "Python interface for the C library"},
    {"aws_crt_clean_up", method_aws_crt_clean_up, METH_VARARGS, "Python interface for the C library"},
    {"aws_crt_test_error", method_aws_crt_test_error, METH_VARARGS, "Python interface for the C library"},
    {"aws_crt_mem_acquire", method_aws_crt_mem_acquire, METH_VARARGS, "Python interface for the C library"},
    {"aws_crt_mem_release", method_aws_crt_mem_release, METH_VARARGS, "Python interface for the C library"},
    {"aws_crt_default_allocator", method_aws_crt_default_allocator, METH_VARARGS, "Python interface for the C library"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef awsmodule = {
    PyModuleDef_HEAD_INIT,
    "aws",
    "Python interface for the test aws in C library",
    -1,
    AwsMethods
};

PyMODINIT_FUNC PyInit_aws(void) {
    return PyModule_Create(&awsmodule);
}