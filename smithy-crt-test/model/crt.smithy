namespace com.aws.ffi

// /* CRT */
// AWS_CRT_API void aws_crt_init(void);
operation aws_crt_init {}

// AWS_CRT_API void aws_crt_clean_up(void);
operation aws_crt_clean_up {}

// AWS_CRT_API int aws_crt_test_error(int);
operation aws_crt_test_error {
    input: int32_t,
    output: int32_t
}

// AWS_CRT_API void *aws_crt_mem_acquire(size_t size);
operation aws_crt_mem_acquire {
    input: int32_t,
    output: void
}

// AWS_CRT_API void aws_crt_mem_release(void *mem);
operation aws_crt_mem_release {
    input: void_p
}

// /* Errors */
// AWS_CRT_API int aws_crt_last_error(void);
operation aws_crt_last_error {
    output: int32_t
}

// AWS_CRT_API const char *aws_crt_error_str(int);
operation aws_crt_error_str {
    input: int32_t,
    output: string
}

// AWS_CRT_API const char *aws_crt_error_name(int);
operation aws_crt_error_name {
    input: int32_t,
    output: string
}

// AWS_CRT_API const char *aws_crt_error_debug_str(int);
operation aws_crt_error_debug_str {
    input: int32_t,
    output: string
}

// AWS_CRT_API void aws_crt_reset_error(void);
operation aws_crt_reset_error {}