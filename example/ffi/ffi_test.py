import os
from ctypes import *

def wrap_function(lib, funcname, restype, argtypes):
    """Simplify wrapping ctypes functions"""
    func = lib.__getattr__(funcname)
    func.restype = restype
    func.argtypes = argtypes
    return func

cwd = os.getcwd()
_test = CDLL(cwd + '/libtest.so')

aws_crt_init = wrap_function(_test, 'aws_crt_init', c_char_p, None)
aws_crt_clean_up = wrap_function(_test, 'aws_crt_clean_up', c_char_p, None)
aws_crt_test_error = wrap_function(_test, 'aws_crt_test_error', c_char_p, [c_int])
aws_crt_mem_acquire = wrap_function(_test, 'aws_crt_mem_acquire', c_char_p, [c_size_t])
aws_crt_mem_release = wrap_function(_test, 'aws_crt_mem_release', c_char_p, [c_void_p])

print(_test.aws_crt_init())
print(_test.aws_crt_clean_up())
print(_test.aws_crt_test_error(1))
print(_test.aws_crt_mem_acquire(2))
print(_test.aws_crt_mem_release(0x01234567))