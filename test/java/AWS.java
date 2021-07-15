public class AWS {
    static {
        System.loadLibrary("aws-crt-jni");
    }
    
    public class Pointer {
        private long address;
        public Pointer(long addr) {
            address = addr;
        }
        
        public long getAddr() {
            return address;
        }
    }
    
    public native void awsCrtEventLoopGroupOptionsSetMaxThreads(Pointer options, int max_threads);
    public native Pointer awsCrtEventLoopGroupAcquire(Pointer elg);
    public native void awsCrtHttpMessageToBlob(Pointer message, Pointer out_blob);
    public native int awsCrtTestError(int err);
    public native Pointer awsCrtHttpMessageNewFromBlob(byte[] blob, int blob_length);
    public native void awsCrtEventLoopGroupRelease(Pointer elg);
    public native int awsCrtLastError();
    public native void awsCrtHttpHeadersRelease(Pointer headers);
    public native void awsCrtCredentialsRelease(Pointer credentials);
    public native Pointer awsCrtCredentialsAcquire(Pointer credentials);
    public native Pointer awsCrtDefaultAllocator();
    public native void awsCrtCredentialsOptionsSetAccessKeyId(Pointer options, byte[] access_key_id, int access_key_id_length);
    public native Pointer awsCrtCredentialsProviderStaticOptionsNew();
    public native void awsCrtCredentialsProviderStaticOptionsSetAccessKeyId(Pointer options, byte[] access_key_id, int access_key_id_length);
    public native void awsCrtCredentialsProviderStaticOptionsRelease(Pointer options);
    public native void awsCrtCredentialsOptionsRelease(Pointer options);
    public native Pointer awsCrtCredentialsOptionsNew();
    public native void awsCrtInit();
    public native Pointer awsCrtHttpHeadersNewFromBlob(byte[] blob, int blob_length);
    public native void awsCrtCredentialsOptionsSetSecretAccessKey(Pointer options, byte[] secret_access_key, int secret_access_key_length);
    public native void awsCrtCleanUp();
    public native Pointer awsCrtEventLoopGroupNew(Pointer options);
    public native long awsCrtMemCount();
    public native void awsCrtCredentialsProviderStaticOptionsSetSessionToken(Pointer options, byte[] session_token, int session_token_length);
    public native void awsCrtCredentialsProviderStaticOptionsSetSecretAccessKey(Pointer options, byte[] secret_access_key, int secret_access_key_length);
    public native String awsCrtErrorStr(int err);
    public native Pointer awsCrtCredentialsProviderStaticNew(Pointer options);
    public native long awsCrtMemBytes();
    public native Pointer awsCrtCredentialsNew(Pointer options);
    public native void awsCrtHttpHeadersToBlob(Pointer headers, Pointer out_blob);
    public native void awsCrtCredentialsOptionsSetExpirationTimepointSeconds(Pointer options, long expiration_timepoint_seconds);
    public native void awsCrtMemDump();
    public native void awsCrtHttpMessageRelease(Pointer message);
    public native Pointer awsCrtEventLoopGroupOptionsNew();
    public native Pointer awsCrtHttpHeadersAcquire(Pointer headers);
    public native String awsCrtErrorName(int err);
    public native void awsCrtMemRelease(Pointer mem);
    public native void awsCrtResetError();
    public native void awsCrtCredentialsProviderRelease(Pointer credentials_provider);
    public native Pointer awsCrtCredentialsProviderAcquire(Pointer credentials_provider);
    public native Pointer awsCrtMemAcquire(int size);
    public native void awsCrtCredentialsOptionsSetSessionToken(Pointer options, byte[] session_token, int session_token_length);
    public native String awsCrtErrorDebugStr(int err);
    public native void awsCrtHttpMessageSetBodyStream(Pointer message, Pointer body_stream);
    public native void awsCrtEventLoopGroupOptionsRelease(Pointer options);
}

