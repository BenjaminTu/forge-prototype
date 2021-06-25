namespace com.aws.ffi

// AWS_CRT_API aws_crt_http_headers *aws_crt_http_headers_new_from_blob(const uint8_t *blob, size_t blob_length);
structure aws_crt_http_headers_new_from_blob_input {
    @const
    @pointer
    blob: uint8_t,
    blob_length: size_t
}

structure aws_crt_http_headers_new_from_blob_output {
    ret: aws_crt_http_headers,
}

operation aws_crt_http_headers_new_from_blob {
    input: aws_crt_http_headers_new_from_blob_input,
    output: aws_crt_http_headers_new_from_blob_output
}

// AWS_CRT_API aws_crt_http_headers *aws_crt_http_headers_acquire(aws_crt_http_headers *headers);
structure aws_crt_http_headers_acquire_input {
    headers: aws_crt_http_headers
}

structure aws_crt_http_headers_acquire_output {
    ret: aws_crt_http_headers,
}

operation aws_crt_http_headers_acquire {
    input: aws_crt_http_headers_acquire_input,
    output: aws_crt_http_headers_acquire_output
}

// AWS_CRT_API void aws_crt_http_headers_release(aws_crt_http_headers *headers);
structure aws_crt_http_headers_release_input {
    ret: aws_crt_http_headers,
}

operation aws_crt_http_headers_release {
    input: aws_crt_http_headers_release_input,
    output: void
}

// AWS_CRT_API void aws_crt_http_headers_to_blob(
//     const aws_crt_http_headers *headers,
//     uint8_t **out_blob,
//     size_t *out_blob_length);
structure aws_crt_http_headers_to_blob_input {
    @const
    headers: aws_crt_http_headers,
    @pointer
    out_blob: aws_crt_buf
}

operation aws_crt_http_headers_to_blob {
    input: aws_crt_http_headers_to_blob_input,
    output: void
}

// AWS_CRT_API aws_crt_http_message *aws_crt_http_message_new_from_blob(const uint8_t *blob, size_t blob_length);
structure aws_crt_http_message_new_from_blob_input {
    @const
    @pointer
    blob: uint8_t,
    blob_length: size_t,
}

structure aws_crt_http_message_new_from_blob_output {
    ret: aws_crt_http_message,
}

operation aws_crt_http_message_new_from_blob {
    input: aws_crt_http_message_new_from_blob_input,
    output: aws_crt_http_message_new_from_blob_output
}

// AWS_CRT_API void aws_crt_http_message_set_body_stream(aws_crt_http_message *message, aws_crt_input_stream *body_stream);
structure aws_crt_http_message_set_body_stream_input {
    message: aws_crt_http_message,
    body_stream: aws_crt_input_stream
}

operation aws_crt_http_message_set_body_stream {
    input: aws_crt_http_message_set_body_stream_input,
    output: void
}

// AWS_CRT_API void aws_crt_http_message_release(aws_crt_http_message *message);
structure aws_crt_http_message_release_input {
    ret: aws_crt_http_message,
}

operation aws_crt_http_message_release {
    input: aws_crt_http_message_release_input,
    output: void
}

// AWS_CRT_API void aws_crt_http_message_to_blob(
//     const aws_crt_http_message *message,
//     uint8_t **out_blob,
//     size_t *out_blob_length);
structure aws_crt_http_message_to_blob_input {
    @const
    message: aws_crt_http_message,
    @pointer
    out_blob: aws_crt_buf
}

operation aws_crt_http_message_to_blob {
    input: aws_crt_http_message_to_blob_input,
    output: void
}