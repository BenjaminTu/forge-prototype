namespace com.aws.ffi

// /* Self-defined Structs */

// typedef struct aws_allocator aws_crt_allocator;
@ctype("aws_crt_allocator")
@opaque
structure aws_crt_allocator {}

// typedef struct aws_credentials aws_crt_credentials;
@ctype("aws_crt_credentials")
@opaque
structure aws_crt_credentials {}

// typedef struct _aws_crt_credentials_options aws_crt_credentials_options;
@ctype("aws_crt_credentials_options")
@opaque
structure aws_crt_credentials_options {}

// typedef struct aws_credentials_provider aws_crt_credentials_provider;
@ctype("aws_crt_credentials_provider")
@opaque
structure aws_crt_credentials_provider {}

// typedef struct _aws_crt_credentials_provider_static_options aws_crt_credentials_provider_static_options;
@ctype("aws_crt_credentials_provider_static_options")
@opaque
structure aws_crt_credentials_provider_static_options {}

// typedef struct aws_event_loop_group aws_crt_event_loop_group;
@ctype("aws_crt_event_loop_group")
@opaque
structure aws_crt_event_loop_group {}

// typedef struct _aws_crt_event_loop_group_options aws_crt_event_loop_group_options;
@ctype("aws_crt_event_loop_group_options")
@opaque
structure aws_crt_event_loop_group_options {}

// typedef struct _aws_crt_input_stream_options aws_crt_input_stream_options;
@ctype("aws_crt_input_stream_options")
@opaque
structure aws_crt_input_stream_options {}

// typedef struct aws_input_stream aws_crt_input_stream;
@ctype("aws_crt_input_stream")
@opaque
structure aws_crt_input_stream {}

// typedef struct aws_crt_buf {
//     uint8_t *blob;
//     size_t length;
// } aws_crt_buf;
@ctype("aws_crt_buf")
structure aws_crt_buf {
    @pointer
    blob: uint8_t,
    length: size_t
}

// typedef struct _aws_crt_http_headers aws_crt_http_headers;
@ctype("aws_crt_http_headers")
@opaque
structure aws_crt_http_headers {}

// typedef struct _aws_crt_http_message aws_crt_http_message;
@ctype("aws_crt_http_message")
@opaque
structure aws_crt_http_message {}
