#include <jni.h>
#include <stdio.h>
#include "AWS.h"
#include "api.h"
 
JNIEXPORT jobject JNICALL Java_AWS_httpHeadersNewFromBlob(JNIEnv *env, jobject obj, jbyteArray blob, jint blob_length) {
    printf("Hello World\n");
    return NULL;
}