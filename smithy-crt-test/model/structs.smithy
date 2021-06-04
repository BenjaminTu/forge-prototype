namespace com.aws.ffi

// /* Traits */
@trait
structure ctype {
    @required
    typename: String
}

@trait
structure pointer {}

@trait
structure opaque {}

// /* Ctypes */

@ctype(typename: "uint8_t")
structure uint8_t {
    @required
    value: Integer
}

@pointer
structure uint8_t_p {
    @required
    value: uint8_t
}

@ctype(typename: "int32_t")
structure int32_t {
    @required
    value: Integer
}

@pointer
structure int32_t_p {
    @required
    value: int32_t
}

@ctype(typename: "int64_t")
structure int64_t {
    @required
    value: BigInteger
}

@pointer
structure int64_t_p {
    @required
    value: int64_t
}

@ctype(typename: "size_t")
structure size_t {
    @required
    value: BigInteger
}

@pointer
structure size_t_p {
    @required
    value: size_t
}

@ctype(typename: "char *")
structure string {
    @required
    value: String
}

@ctype(typename: "void")
structure void {}

@pointer
structure void_p {
    @required
    value: void
}

// Self-defined Structs

// /* Auth */
// typedef struct aws_credentials aws_crt_credentials;
@ctype(typename: "aws_crt_credentials")
@opaque
structure aws_crt_credentials {}

// typedef struct _aws_crt_credentials_options aws_crt_credentials_options;
@ctype(typename: "aws_crt_credentials_options")
@opaque
structure aws_crt_credentials_options {}

// /* Credentials providers */
// typedef struct aws_credentials_provider aws_crt_credentials_provider;
@ctype(typename: "aws_crt_credentials_provider")
@opaque
structure aws_crt_credentials_provider {}

// /* Public function definitions */



// /* Auth */
// AWS_CRT_API aws_crt_credentials_options *aws_crt_credentials_options_new(void);
operation aws_crt_credentials_options_new {
    output: aws_crt_credentials_options
    // errors: []
}

// AWS_CRT_API void aws_crt_credentials_options_release(aws_crt_credentials_options *options);
operation aws_crt_credentials_options_release {
    input: aws_crt_credentials_options
    // errors: []
}

// // Input for setting aws_crt_credentials_options
// structure aws_crt_credentials_options_set_input {
//     @required
//     options: aws_crt_credentials_options,
//     @required
//     data: UInt8_TPointer,
//     @required
//     size: IntegerWrapper
// }

// // AWS_CRT_API void aws_crt_credentials_options_set_access_key_id(
// //     aws_crt_credentials_options *options,
// //     const uint8_t *access_key_id,
// //     size_t access_key_id_length);

// operation aws_crt_credentials_options_set_access_key_id {
//     input: aws_crt_credentials_options_set_input
//     // errors: []
// }

// // AWS_CRT_API void aws_crt_credentials_options_set_secret_access_key(
// //     aws_crt_credentials_options *options,
// //     const uint8_t *secret_access_key,
// //     size_t secret_access_key_length);
// operation aws_crt_credentials_options_set_secret_access_key {
//     input: aws_crt_credentials_options_set_input
//     // errors: []
// }

// // AWS_CRT_API void aws_crt_credentials_options_set_session_token(
// //     aws_crt_credentials_options *options,
// //     const uint8_t *session_token,
// //     size_t session_token_length);
// operation aws_crt_credentials_options_set_session_token {
//     input: aws_crt_credentials_options_set_input
//     // errors: []
// }

// // AWS_CRT_API void aws_crt_credentials_options_set_expiration_timepoint_seconds(
// //     aws_crt_credentials_options *options,
// //     uint64_t expiration_timepoint_seconds);
// structure aws_crt_credentials_options_set_time_input {
//     @required
//     options: aws_crt_credentials_options,
//     @required
//     expiration_timepoint_seconds: BigIntegerWrapper
// }

// operation aws_crt_credentials_options_set_expiration_timepoint_seconds {
//     input: aws_crt_credentials_options_set_time_input
//     // errors: []
// }

// // AWS_CRT_API aws_crt_credentials *aws_crt_credentials_new(const aws_crt_credentials_options *options);
// operation aws_crt_credentials_new {
//     input: aws_crt_credentials_options,
//     output: aws_crt_credentials
//     // errors: []
// }

// // AWS_CRT_API aws_crt_credentials *aws_crt_credentials_acquire(aws_crt_credentials *credentials);
// operation aws_crt_credentials_acquire {
//     input: aws_crt_credentials,
//     output: aws_crt_credentials
//     // errors: []
// }

// // AWS_CRT_API void aws_crt_credentials_release(aws_crt_credentials *credentials);
// operation aws_crt_credentials_release {
//     input: aws_crt_credentials,
//     // errors: []
// }

// // /* Credentials providers */
// // /* Generic credentials provider acquire/release */

// // AWS_CRT_API aws_crt_credentials_provider *aws_crt_credentials_provider_acquire(
// //     aws_crt_credentials_provider *credentials_provider);
// operation aws_crt_credentials_provider_acquire {
//     input: aws_crt_credentials_provider,
//     output: aws_crt_credentials_provider
//     // errors: []
// }

// // AWS_CRT_API void aws_crt_credentials_provider_release(aws_crt_credentials_provider *credentials_provider);
// operation aws_crt_credentials_provider_release {
//     input: aws_crt_credentials_provider,
//     // errors: []
// }