namespace com.aws.ffi

// AWS_CRT_API void aws_crt_init(void);
operation aws_crt_init {
    input: void,
    output: void
}

// AWS_CRT_API void aws_crt_clean_up(void);
operation aws_crt_clean_up {
    input: void,
    output: void
}

// AWS_CRT_API int aws_crt_test_error(int err);
structure aws_crt_test_error_input {
    @required
    err: int32_t
}

structure aws_crt_test_error_output {
    @required
    ret: int32_t
}

operation aws_crt_test_error {
    input: aws_crt_test_error_input,
    output: aws_crt_test_error_output
}

// AWS_CRT_API aws_crt_allocator *aws_crt_default_allocator(void);
structure aws_crt_default_allocator_output {
    @required
    @pointer
    ret: aws_crt_allocator
}

operation aws_crt_default_allocator {
    input: void,
    output: aws_crt_default_allocator_output
}

// AWS_CRT_API void *aws_crt_mem_acquire(size_t size);
structure aws_crt_mem_acquire_input {
    @required
    size: size_t
}

structure aws_crt_mem_acquire_output {
    @required
    @pointer
    ret: void
}

operation aws_crt_mem_acquire {
    input: aws_crt_mem_acquire_input,
    output: aws_crt_mem_acquire_output
}

// AWS_CRT_API void aws_crt_mem_release(void *mem);
structure aws_crt_mem_release_input {
    @required
    @pointer
    mem: void
}

operation aws_crt_mem_release {
    input: aws_crt_mem_release_input,
    output: void
}