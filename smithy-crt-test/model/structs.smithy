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


