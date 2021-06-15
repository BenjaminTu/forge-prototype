namespace com.aws.ffi

// AWS_CRT_API aws_crt_credentials_provider_static_options *aws_crt_credentials_provider_static_options_new(void);
structure aws_crt_credentials_provider_static_options_new_output {
    ret: aws_crt_credentials_provider_static_options
}

operation aws_crt_credentials_provider_static_options_new {
    input: void,
    output: aws_crt_credentials_provider_static_options_new_output
}

// AWS_CRT_API void aws_crt_credentials_provider_static_options_release(
//     aws_crt_credentials_provider_static_options *options);
structure aws_crt_credentials_provider_static_options_release_input {
    options: aws_crt_credentials_provider_static_options
}

operation aws_crt_credentials_provider_static_options_release {
    input: aws_crt_credentials_provider_static_options_release_input,
    output: void
}

// AWS_CRT_API void aws_crt_credentials_provider_static_options_set_access_key_id(
//     aws_crt_credentials_provider_static_options *options,
//     const uint8_t *access_key_id,
//     size_t access_key_id_length);
structure aws_crt_credentials_provider_static_options_set_access_key_id_input {
    options: aws_crt_credentials_provider_static_options,
    @const
    @pointer
    access_key_id: uint8_t,
    access_key_id_length: size_t
}

operation aws_crt_credentials_provider_static_options_set_access_key_id {
    input: aws_crt_credentials_provider_static_options_set_access_key_id_input,
    output: void
}

// AWS_CRT_API void aws_crt_credentials_provider_static_options_set_secret_access_key(
//     aws_crt_credentials_provider_static_options *options,
//     const uint8_t *secret_access_key,
//     size_t secret_access_key_length);
structure aws_crt_credentials_provider_static_options_set_secret_access_input {
    options: aws_crt_credentials_provider_static_options,
    @const
    @pointer
    secret_access_key: uint8_t,
    secret_access_key_length: size_t
}

operation aws_crt_credentials_provider_static_options_set_secret_access_key {
    input: aws_crt_credentials_provider_static_options_set_secret_access_input,
    output: void
}

// AWS_CRT_API void aws_crt_credentials_provider_static_options_set_session_token(
//     aws_crt_credentials_provider_static_options *options,
//     const uint8_t *session_token,
//     size_t session_token_length);
structure aws_crt_credentials_provider_static_options_set_session_token_input {
    options: aws_crt_credentials_provider_static_options,
    @const
    @pointer
    session_token: uint8_t,
    session_token_length: size_t
}

operation aws_crt_credentials_provider_static_options_set_session_token {
    input: aws_crt_credentials_provider_static_options_set_session_token_input,
    output: void
}

// AWS_CRT_API aws_crt_credentials_provider *aws_crt_credentials_provider_static_new(
//     const aws_crt_credentials_provider_static_options *options);
structure aws_crt_credentials_provider_static_new_input {
    @const
    options: aws_crt_credentials_provider_static_options,
}

structure aws_crt_credentials_provider_static_new_output {
    ret: aws_crt_credentials_provider
}

operation aws_crt_credentials_provider_static_new {
    input: aws_crt_credentials_provider_static_new_input,
    output: aws_crt_credentials_provider_static_new_output
}