public class AWS {  // Save as AWS.java
    static {
        System.loadLibrary("aws-crt-jni");
    }

    private class Pointer {
        private long address;
        public Pointer(long addr) {
            address = addr;
        }
    }

    public native Pointer httpHeadersNewFromBlob(byte[] blob, int blob_length);
    public native void crtInit();
}



// typedef struct aws_crt_buf {
//     uint8_t *blob;
//     size_t length;
// } aws_crt_buf;
// typedef struct _aws_crt_http_headers aws_crt_http_headers;
// AWS_CRT_API aws_crt_http_headers *aws_crt_http_headers_new_from_blob(const uint8_t *blob, size_t blob_length);
// AWS_CRT_API aws_crt_http_headers *aws_crt_http_headers_acquire(aws_crt_http_headers *headers);
// AWS_CRT_API void aws_crt_http_headers_release(aws_crt_http_headers *headers);
// AWS_CRT_API void aws_crt_http_headers_to_blob(const aws_crt_http_headers *headers, aws_crt_buf *out_blob);

// typedef struct _aws_crt_http_message aws_crt_http_message;
// AWS_CRT_API aws_crt_http_message *aws_crt_http_message_new_from_blob(const uint8_t *blob, size_t blob_length);
// AWS_CRT_API void aws_crt_http_message_set_body_stream(aws_crt_http_message *message, aws_crt_input_stream *body_stream);
// AWS_CRT_API void aws_crt_http_message_release(aws_crt_http_message *message);
// AWS_CRT_API void aws_crt_http_message_to_blob(const aws_crt_http_message *message, aws_crt_buf *out_blob);