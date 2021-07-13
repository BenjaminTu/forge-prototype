#include <jni.h>
#include <stdint.h>
#include "api.h"

JNIEXPORT void JNICALL Java_AWS_awsCrtHttpMessageRelease(JNIEnv *env, jobject obj, jobject a) {
    (void)env;
    (void)obj;
    
    aws_crt_http_message * b = (aws_crt_http_message *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_http_message_release(b);
}

JNIEXPORT void JNICALL Java_AWS_awsCrtCredentialsOptionsSetExpirationTimepointSeconds(JNIEnv *env, jobject obj, jobject a, jlong b) {
    (void)env;
    (void)obj;
    
    aws_crt_credentials_options * c = (aws_crt_credentials_options *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_credentials_options_set_expiration_timepoint_seconds(c, b);
}

JNIEXPORT jobject JNICALL Java_AWS_awsCrtCredentialsProviderStaticOptionsNew(JNIEnv *env, jobject obj) {
    (void)env;
    (void)obj;
    
    aws_crt_credentials_provider_static_options * ret = aws_crt_credentials_provider_static_options_new();
    jclass cls = (*env)->FindClass(env, "AWS$Pointer");
    jmethodID constructor = (*env)->GetMethodID(env, cls, "<init>", "(J)");
    return (*env)->NewObject(env, cls, constructor, (long)ret);
}

JNIEXPORT jstring JNICALL Java_AWS_awsCrtErrorDebugStr(JNIEnv *env, jobject obj, jint a) {
    (void)env;
    (void)obj;
    
    return (*env)->NewStringUTF(env, aws_crt_error_debug_str(a));
}

JNIEXPORT void JNICALL Java_AWS_awsCrtCredentialsProviderStaticOptionsRelease(JNIEnv *env, jobject obj, jobject a) {
    (void)env;
    (void)obj;
    
    aws_crt_credentials_provider_static_options * b = (aws_crt_credentials_provider_static_options *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_credentials_provider_static_options_release(b);
}

JNIEXPORT jint JNICALL Java_AWS_awsCrtLastError(JNIEnv *env, jobject obj) {
    (void)env;
    (void)obj;
    
    return aws_crt_last_error();
}

JNIEXPORT void JNICALL Java_AWS_awsCrtEventLoopGroupRelease(JNIEnv *env, jobject obj, jobject a) {
    (void)env;
    (void)obj;
    
    aws_crt_event_loop_group * b = (aws_crt_event_loop_group *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_event_loop_group_release(b);
}

JNIEXPORT jobject JNICALL Java_AWS_awsCrtCredentialsOptionsNew(JNIEnv *env, jobject obj) {
    (void)env;
    (void)obj;
    
    aws_crt_credentials_options * ret = aws_crt_credentials_options_new();
    jclass cls = (*env)->FindClass(env, "AWS$Pointer");
    jmethodID constructor = (*env)->GetMethodID(env, cls, "<init>", "(J)");
    return (*env)->NewObject(env, cls, constructor, (long)ret);
}

JNIEXPORT jobject JNICALL Java_AWS_awsCrtMemAcquire(JNIEnv *env, jobject obj, jint a) {
    (void)env;
    (void)obj;
    
    void * ret = aws_crt_mem_acquire(a);
    jclass cls = (*env)->FindClass(env, "AWS$Pointer");
    jmethodID constructor = (*env)->GetMethodID(env, cls, "<init>", "(J)");
    return (*env)->NewObject(env, cls, constructor, (long)ret);
}

JNIEXPORT jobject JNICALL Java_AWS_awsCrtEventLoopGroupOptionsNew(JNIEnv *env, jobject obj) {
    (void)env;
    (void)obj;
    
    aws_crt_event_loop_group_options * ret = aws_crt_event_loop_group_options_new();
    jclass cls = (*env)->FindClass(env, "AWS$Pointer");
    jmethodID constructor = (*env)->GetMethodID(env, cls, "<init>", "(J)");
    return (*env)->NewObject(env, cls, constructor, (long)ret);
}

JNIEXPORT void JNICALL Java_AWS_awsCrtHttpMessageToBlob(JNIEnv *env, jobject obj, jobject a, jobject b) {
    (void)env;
    (void)obj;
    
    const aws_crt_http_message * c = (const aws_crt_http_message *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_buf * d = (aws_crt_buf *) ((*env)->GetLongField(env, b, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, b), "address", "J")));
    aws_crt_http_message_to_blob(c, d);
}

JNIEXPORT jobject JNICALL Java_AWS_awsCrtCredentialsProviderAcquire(JNIEnv *env, jobject obj, jobject a) {
    (void)env;
    (void)obj;
    
    aws_crt_credentials_provider * b = (aws_crt_credentials_provider *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_credentials_provider * ret = aws_crt_credentials_provider_acquire(b);
    jclass cls = (*env)->FindClass(env, "AWS$Pointer");
    jmethodID constructor = (*env)->GetMethodID(env, cls, "<init>", "(J)");
    return (*env)->NewObject(env, cls, constructor, (long)ret);
}

JNIEXPORT void JNICALL Java_AWS_awsCrtCredentialsProviderRelease(JNIEnv *env, jobject obj, jobject a) {
    (void)env;
    (void)obj;
    
    aws_crt_credentials_provider * b = (aws_crt_credentials_provider *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_credentials_provider_release(b);
}

JNIEXPORT jobject JNICALL Java_AWS_awsCrtEventLoopGroupAcquire(JNIEnv *env, jobject obj, jobject a) {
    (void)env;
    (void)obj;
    
    aws_crt_event_loop_group * b = (aws_crt_event_loop_group *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_event_loop_group * ret = aws_crt_event_loop_group_acquire(b);
    jclass cls = (*env)->FindClass(env, "AWS$Pointer");
    jmethodID constructor = (*env)->GetMethodID(env, cls, "<init>", "(J)");
    return (*env)->NewObject(env, cls, constructor, (long)ret);
}

JNIEXPORT void JNICALL Java_AWS_awsCrtMemRelease(JNIEnv *env, jobject obj, jobject a) {
    (void)env;
    (void)obj;
    
    void * b = (void *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_mem_release(b);
}

JNIEXPORT jobject JNICALL Java_AWS_awsCrtHttpMessageNewFromBlob(JNIEnv *env, jobject obj, jbyteArray a, jint b) {
    (void)env;
    (void)obj;
    
    const uint8_t * c = (const uint8_t *) (*env)->GetByteArrayElements(env, a, 0);
    aws_crt_http_message * ret = aws_crt_http_message_new_from_blob(c, b);
    jclass cls = (*env)->FindClass(env, "AWS$Pointer");
    jmethodID constructor = (*env)->GetMethodID(env, cls, "<init>", "(J)");
    return (*env)->NewObject(env, cls, constructor, (long)ret);
}

JNIEXPORT void JNICALL Java_AWS_awsCrtHttpHeadersRelease(JNIEnv *env, jobject obj, jobject a) {
    (void)env;
    (void)obj;
    
    aws_crt_http_headers * b = (aws_crt_http_headers *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_http_headers_release(b);
}

JNIEXPORT void JNICALL Java_AWS_awsCrtInit(JNIEnv *env, jobject obj) {
    (void)env;
    (void)obj;
    
    aws_crt_init();
}

JNIEXPORT void JNICALL Java_AWS_awsCrtCredentialsOptionsSetAccessKeyId(JNIEnv *env, jobject obj, jobject a, jbyteArray b, jint c) {
    (void)env;
    (void)obj;
    
    aws_crt_credentials_options * d = (aws_crt_credentials_options *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    const uint8_t * e = (const uint8_t *) (*env)->GetByteArrayElements(env, b, 0);
    aws_crt_credentials_options_set_access_key_id(d, e, c);
}

JNIEXPORT jobject JNICALL Java_AWS_awsCrtDefaultAllocator(JNIEnv *env, jobject obj) {
    (void)env;
    (void)obj;
    
    aws_crt_allocator * ret = aws_crt_default_allocator();
    jclass cls = (*env)->FindClass(env, "AWS$Pointer");
    jmethodID constructor = (*env)->GetMethodID(env, cls, "<init>", "(J)");
    return (*env)->NewObject(env, cls, constructor, (long)ret);
}

JNIEXPORT jobject JNICALL Java_AWS_awsCrtCredentialsNew(JNIEnv *env, jobject obj, jobject a) {
    (void)env;
    (void)obj;
    
    const aws_crt_credentials_options * b = (const aws_crt_credentials_options *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_credentials * ret = aws_crt_credentials_new(b);
    jclass cls = (*env)->FindClass(env, "AWS$Pointer");
    jmethodID constructor = (*env)->GetMethodID(env, cls, "<init>", "(J)");
    return (*env)->NewObject(env, cls, constructor, (long)ret);
}

JNIEXPORT jobject JNICALL Java_AWS_awsCrtCredentialsAcquire(JNIEnv *env, jobject obj, jobject a) {
    (void)env;
    (void)obj;
    
    aws_crt_credentials * b = (aws_crt_credentials *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_credentials * ret = aws_crt_credentials_acquire(b);
    jclass cls = (*env)->FindClass(env, "AWS$Pointer");
    jmethodID constructor = (*env)->GetMethodID(env, cls, "<init>", "(J)");
    return (*env)->NewObject(env, cls, constructor, (long)ret);
}

JNIEXPORT void JNICALL Java_AWS_awsCrtCredentialsProviderStaticOptionsSetSessionToken(JNIEnv *env, jobject obj, jobject a, jbyteArray b, jint c) {
    (void)env;
    (void)obj;
    
    aws_crt_credentials_provider_static_options * d = (aws_crt_credentials_provider_static_options *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    const uint8_t * e = (const uint8_t *) (*env)->GetByteArrayElements(env, b, 0);
    aws_crt_credentials_provider_static_options_set_session_token(d, e, c);
}

JNIEXPORT void JNICALL Java_AWS_awsCrtCredentialsRelease(JNIEnv *env, jobject obj, jobject a) {
    (void)env;
    (void)obj;
    
    aws_crt_credentials * b = (aws_crt_credentials *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_credentials_release(b);
}

JNIEXPORT jint JNICALL Java_AWS_awsCrtTestError(JNIEnv *env, jobject obj, jint a) {
    (void)env;
    (void)obj;
    
    return aws_crt_test_error(a);
}

JNIEXPORT void JNICALL Java_AWS_awsCrtHttpHeadersToBlob(JNIEnv *env, jobject obj, jobject a, jobject b) {
    (void)env;
    (void)obj;
    
    const aws_crt_http_headers * c = (const aws_crt_http_headers *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_buf * d = (aws_crt_buf *) ((*env)->GetLongField(env, b, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, b), "address", "J")));
    aws_crt_http_headers_to_blob(c, d);
}

JNIEXPORT void JNICALL Java_AWS_awsCrtCredentialsOptionsSetSecretAccessKey(JNIEnv *env, jobject obj, jobject a, jbyteArray b, jint c) {
    (void)env;
    (void)obj;
    
    aws_crt_credentials_options * d = (aws_crt_credentials_options *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    const uint8_t * e = (const uint8_t *) (*env)->GetByteArrayElements(env, b, 0);
    aws_crt_credentials_options_set_secret_access_key(d, e, c);
}

JNIEXPORT void JNICALL Java_AWS_awsCrtCredentialsOptionsSetSessionToken(JNIEnv *env, jobject obj, jobject a, jbyteArray b, jint c) {
    (void)env;
    (void)obj;
    
    aws_crt_credentials_options * d = (aws_crt_credentials_options *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    const uint8_t * e = (const uint8_t *) (*env)->GetByteArrayElements(env, b, 0);
    aws_crt_credentials_options_set_session_token(d, e, c);
}

JNIEXPORT jobject JNICALL Java_AWS_awsCrtHttpHeadersNewFromBlob(JNIEnv *env, jobject obj, jbyteArray a, jint b) {
    (void)env;
    (void)obj;
    
    const uint8_t * c = (const uint8_t *) (*env)->GetByteArrayElements(env, a, 0);
    aws_crt_http_headers * ret = aws_crt_http_headers_new_from_blob(c, b);
    jclass cls = (*env)->FindClass(env, "AWS$Pointer");
    jmethodID constructor = (*env)->GetMethodID(env, cls, "<init>", "(J)");
    return (*env)->NewObject(env, cls, constructor, (long)ret);
}

JNIEXPORT jstring JNICALL Java_AWS_awsCrtErrorStr(JNIEnv *env, jobject obj, jint a) {
    (void)env;
    (void)obj;
    
    return (*env)->NewStringUTF(env, aws_crt_error_str(a));
}

JNIEXPORT jobject JNICALL Java_AWS_awsCrtCredentialsProviderStaticNew(JNIEnv *env, jobject obj, jobject a) {
    (void)env;
    (void)obj;
    
    const aws_crt_credentials_provider_static_options * b = (const aws_crt_credentials_provider_static_options *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_credentials_provider * ret = aws_crt_credentials_provider_static_new(b);
    jclass cls = (*env)->FindClass(env, "AWS$Pointer");
    jmethodID constructor = (*env)->GetMethodID(env, cls, "<init>", "(J)");
    return (*env)->NewObject(env, cls, constructor, (long)ret);
}

JNIEXPORT void JNICALL Java_AWS_awsCrtCredentialsOptionsRelease(JNIEnv *env, jobject obj, jobject a) {
    (void)env;
    (void)obj;
    
    aws_crt_credentials_options * b = (aws_crt_credentials_options *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_credentials_options_release(b);
}

JNIEXPORT void JNICALL Java_AWS_awsCrtCredentialsProviderStaticOptionsSetAccessKeyId(JNIEnv *env, jobject obj, jobject a, jbyteArray b, jint c) {
    (void)env;
    (void)obj;
    
    aws_crt_credentials_provider_static_options * d = (aws_crt_credentials_provider_static_options *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    const uint8_t * e = (const uint8_t *) (*env)->GetByteArrayElements(env, b, 0);
    aws_crt_credentials_provider_static_options_set_access_key_id(d, e, c);
}

JNIEXPORT void JNICALL Java_AWS_awsCrtCleanUp(JNIEnv *env, jobject obj) {
    (void)env;
    (void)obj;
    
    aws_crt_clean_up();
}

JNIEXPORT jobject JNICALL Java_AWS_awsCrtHttpHeadersAcquire(JNIEnv *env, jobject obj, jobject a) {
    (void)env;
    (void)obj;
    
    aws_crt_http_headers * b = (aws_crt_http_headers *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_http_headers * ret = aws_crt_http_headers_acquire(b);
    jclass cls = (*env)->FindClass(env, "AWS$Pointer");
    jmethodID constructor = (*env)->GetMethodID(env, cls, "<init>", "(J)");
    return (*env)->NewObject(env, cls, constructor, (long)ret);
}

JNIEXPORT void JNICALL Java_AWS_awsCrtHttpMessageSetBodyStream(JNIEnv *env, jobject obj, jobject a, jobject b) {
    (void)env;
    (void)obj;
    
    aws_crt_http_message * c = (aws_crt_http_message *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_input_stream * d = (aws_crt_input_stream *) ((*env)->GetLongField(env, b, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, b), "address", "J")));
    aws_crt_http_message_set_body_stream(c, d);
}

JNIEXPORT jstring JNICALL Java_AWS_awsCrtErrorName(JNIEnv *env, jobject obj, jint a) {
    (void)env;
    (void)obj;
    
    return (*env)->NewStringUTF(env, aws_crt_error_name(a));
}

JNIEXPORT void JNICALL Java_AWS_awsCrtCredentialsProviderStaticOptionsSetSecretAccessKey(JNIEnv *env, jobject obj, jobject a, jbyteArray b, jint c) {
    (void)env;
    (void)obj;
    
    aws_crt_credentials_provider_static_options * d = (aws_crt_credentials_provider_static_options *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    const uint8_t * e = (const uint8_t *) (*env)->GetByteArrayElements(env, b, 0);
    aws_crt_credentials_provider_static_options_set_secret_access_key(d, e, c);
}

JNIEXPORT void JNICALL Java_AWS_awsCrtEventLoopGroupOptionsRelease(JNIEnv *env, jobject obj, jobject a) {
    (void)env;
    (void)obj;
    
    aws_crt_event_loop_group_options * b = (aws_crt_event_loop_group_options *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_event_loop_group_options_release(b);
}

JNIEXPORT void JNICALL Java_AWS_awsCrtResetError(JNIEnv *env, jobject obj) {
    (void)env;
    (void)obj;
    
    aws_crt_reset_error();
}

JNIEXPORT jobject JNICALL Java_AWS_awsCrtEventLoopGroupNew(JNIEnv *env, jobject obj, jobject a) {
    (void)env;
    (void)obj;
    
    const aws_crt_event_loop_group_options * b = (const aws_crt_event_loop_group_options *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_event_loop_group * ret = aws_crt_event_loop_group_new(b);
    jclass cls = (*env)->FindClass(env, "AWS$Pointer");
    jmethodID constructor = (*env)->GetMethodID(env, cls, "<init>", "(J)");
    return (*env)->NewObject(env, cls, constructor, (long)ret);
}

JNIEXPORT void JNICALL Java_AWS_awsCrtEventLoopGroupOptionsSetMaxThreads(JNIEnv *env, jobject obj, jobject a, jint b) {
    (void)env;
    (void)obj;
    
    aws_crt_event_loop_group_options * c = (aws_crt_event_loop_group_options *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
    aws_crt_event_loop_group_options_set_max_threads(c, b);
}

