#include <jni.h>        // JNI header provided by JDK
#include <stdio.h>      // C Standard IO Header
#include "AWS.h"   // Generated
 
JNIEXPORT jobject JNICALL Java_AWS_http_1headers_1new_1from_1blob(JNIEnv *env, jobject obj, jbyteArray blob, jint blob_length) {
    printf("Hello World!\n");
    return NULL;
}