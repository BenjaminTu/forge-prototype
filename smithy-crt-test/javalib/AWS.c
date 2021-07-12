#include <jni.h>
#include <stdio.h>
#include <stdint.h>
#include "AWS.h"
#include "api.h"

JNIEXPORT jobject JNICALL Java_AWS_httpHeadersNewFromBlob(JNIEnv *env, jobject obj, jbyteArray blob, jint blob_length) {
    (void)obj;
    jbyte *a;

    a = (*env)->GetByteArrayElements(env, blob, 0);
    aws_crt_http_headers *ret = aws_crt_http_headers_new_from_blob((uint8_t *) a, (int) blob_length);

    jclass cls = (*env)->FindClass(env, "AWS$Pointer");
    jmethodID constructor = (*env)->GetMethodID(env, cls, "<init>", "(J)");
    return (*env)->NewObject(env, cls, constructor, (long)ret);
}

JNIEXPORT void JNICALL Java_AWS_crtInit(JNIEnv *env, jobject obj) {
    (void)env;
    (void)obj;
    aws_crt_init();
}