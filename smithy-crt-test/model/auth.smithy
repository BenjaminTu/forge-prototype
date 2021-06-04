namespace com.aws.ffi

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