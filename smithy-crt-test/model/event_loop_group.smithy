namespace com.aws.ffi

// AWS_CRT_API aws_crt_event_loop_group_options *aws_crt_event_loop_group_options_new(void);
structure aws_crt_event_loop_group_options_new_output {
    ret: aws_crt_event_loop_group_options
}

operation aws_crt_event_loop_group_options_new {
    input: void,
    output: aws_crt_event_loop_group_options_new_output
}

// AWS_CRT_API void aws_crt_event_loop_group_options_release(aws_crt_event_loop_group_options *options);
structure aws_crt_event_loop_group_options_release_input {
    options: aws_crt_event_loop_group_options
}

operation aws_crt_event_loop_group_options_release {
    input: aws_crt_event_loop_group_options_release_input,
    output: void
}

// AWS_CRT_API void aws_crt_event_loop_group_options_set_max_threads(
//     aws_crt_event_loop_group_options *options,
//     uint16_t max_threads);
structure aws_crt_event_loop_group_options_set_max_threads_input {
    options: aws_crt_event_loop_group_options,
    max_threads: uint16_t
}

operation aws_crt_event_loop_group_options_set_max_threads {
    input: aws_crt_event_loop_group_options_set_max_threads_input,
    output: void
}

// AWS_CRT_API aws_crt_event_loop_group *aws_crt_event_loop_group_new(const aws_crt_event_loop_group_options *options);
structure aws_crt_event_loop_group_new_input {
    @const
    options: aws_crt_event_loop_group_options
}

structure aws_crt_event_loop_group_new_output {
     ret: aws_crt_event_loop_group
}

operation aws_crt_event_loop_group_new {
    input: aws_crt_event_loop_group_new_input,
    output: aws_crt_event_loop_group_new_output
}

// AWS_CRT_API aws_crt_event_loop_group *aws_crt_event_loop_group_acquire(aws_crt_event_loop_group *elg);
structure aws_crt_event_loop_group_acquire_input {
    elg: aws_crt_event_loop_group
}

structure aws_crt_event_loop_group_acquire_output {
     ret: aws_crt_event_loop_group
}

operation aws_crt_event_loop_group_acquire {
    input: aws_crt_event_loop_group_acquire_input,
    output: aws_crt_event_loop_group_acquire_output
}

// AWS_CRT_API void aws_crt_event_loop_group_release(aws_crt_event_loop_group *elg);
structure aws_crt_event_loop_group_release_input {
    elg: aws_crt_event_loop_group
}

operation aws_crt_event_loop_group_release {
    input: aws_crt_event_loop_group_release_input,
    output: void
}