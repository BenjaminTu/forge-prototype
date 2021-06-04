namespace com.aws.ffi

// AWS_CRT_API int aws_crt_last_error(void);
structure aws_crt_last_error_output {
    @required
    ret: int32_t
}

operation aws_crt_last_error {
    input: void,
    output: aws_crt_last_error_output
}

// AWS_CRT_API const char *aws_crt_error_str(int err);
structure aws_crt_error_str_input {
    @required
    err: int32_t
}

structure aws_crt_error_str_output {
    @required
    ret: string
}

operation aws_crt_error_str {
    input: aws_crt_error_str_input,
    output: aws_crt_error_str_output
}

// AWS_CRT_API const char *aws_crt_error_name(int err);
structure aws_crt_error_name_input {
    @required
    err: int32_t
}

structure aws_crt_error_name_output {
    @required
    ret: string
}

operation aws_crt_error_name {
    input: aws_crt_error_name_input,
    output: aws_crt_error_name_output
}

// AWS_CRT_API const char *aws_crt_error_debug_str(int err);
structure aws_crt_error_debug_str_input {
    @required
    err: int32_t
}

structure aws_crt_error_debug_str_output {
    @required
    ret: string
}

operation aws_crt_error_debug_str {
    input: aws_crt_error_debug_str_input,
    output: aws_crt_error_debug_str_output
}

// AWS_CRT_API void aws_crt_reset_error(void);
operation aws_crt_reset_error {
    input: void,
    output: void
}