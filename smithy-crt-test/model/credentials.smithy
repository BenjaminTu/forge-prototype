namespace com.aws.ffi

// AWS_CRT_API aws_crt_credentials_options *aws_crt_credentials_options_new(void);
structure aws_crt_credentials_options_new_output {
    ret: aws_crt_credentials_options
}

operation aws_crt_credentials_options_new {
    input: void,
    output: aws_crt_credentials_options_new_output
}

// AWS_CRT_API void aws_crt_credentials_options_release(aws_crt_credentials_options *options);
structure aws_crt_credentials_options_release_input {
    options: aws_crt_credentials_options
}

operation aws_crt_credentials_options_release {
    input: aws_crt_credentials_options_release_input,
    output: void
}

// AWS_CRT_API void aws_crt_credentials_options_set_access_key_id(
//     aws_crt_credentials_options *options,
//     const uint8_t *access_key_id,
//     size_t access_key_id_length);
structure aws_crt_credentials_options_set_access_key_id_input {
    @required
    options: aws_crt_credentials_options,
    @required
    @const
    @pointer
    access_key_id: uint8_t,
    @required
    access_key_id_length: size_t
}

operation aws_crt_credentials_options_set_access_key_id {
    input: aws_crt_credentials_options_set_access_key_id_input,
    output: void
}

// AWS_CRT_API void aws_crt_credentials_options_set_secret_access_key(
//     aws_crt_credentials_options *options,
//     const uint8_t *secret_access_key,
//     size_t secret_access_key_length);
structure aws_crt_credentials_options_set_secret_access_key_input {
    @required
    options: aws_crt_credentials_options,
    @required
    @const
    @pointer
    secret_access_key: uint8_t,
    @required
    secret_access_key_length: size_t
}

operation aws_crt_credentials_options_set_secret_access_key {
    input: aws_crt_credentials_options_set_secret_access_key_input,
    output: void
}

// AWS_CRT_API void aws_crt_credentials_options_set_session_token(
//     aws_crt_credentials_options *options,
//     const uint8_t *session_token,
//     size_t session_token_length);
structure aws_crt_credentials_options_set_session_token_input {
    @required
    options: aws_crt_credentials_options,
    @required
    @const
    @pointer
    session_token: uint8_t,
    @required
    session_token_length: size_t
}

operation aws_crt_credentials_options_set_session_token {
    input: aws_crt_credentials_options_set_session_token_input,
    output: void
}

// AWS_CRT_API void aws_crt_credentials_options_set_expiration_timepoint_seconds(
//     aws_crt_credentials_options *options,
//     uint64_t expiration_timepoint_seconds);
structure aws_crt_credentials_options_set_expiration_timepoint_seconds_input {
    @required
    options: aws_crt_credentials_options,
    @required
    expiration_timepoint_seconds: uint64_t
}

operation aws_crt_credentials_options_set_expiration_timepoint_seconds {
    input: aws_crt_credentials_options_set_expiration_timepoint_seconds_input,
    output: void
}

// AWS_CRT_API aws_crt_credentials *aws_crt_credentials_new(const aws_crt_credentials_options *options);

structure aws_crt_credentials_new_input {
    @required
    options: aws_crt_credentials_options,
}

structure aws_crt_credentials_new_output {
    @required
    ret: aws_crt_credentials,
}

operation aws_crt_credentials_new {
    input: aws_crt_credentials_new_input,
    output: aws_crt_credentials_new_output
}

// AWS_CRT_API aws_crt_credentials *aws_crt_credentials_acquire(aws_crt_credentials *credentials);
structure aws_crt_credentials_acquire_input {
    @required
    credentials: aws_crt_credentials,
}

structure aws_crt_credentials_acquire_output {
    @required
    ret: aws_crt_credentials,
}

operation aws_crt_credentials_acquire {
    input: aws_crt_credentials_acquire_input,
    output: aws_crt_credentials_acquire_output
}

// AWS_CRT_API void aws_crt_credentials_release(aws_crt_credentials *credentials);
structure aws_crt_credentials_release_input {
    @required
    credentials: aws_crt_credentials,
}

operation aws_crt_credentials_release {
    input: aws_crt_credentials_release_input,
    output: void
}