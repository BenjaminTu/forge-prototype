import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.zip.CRC32;
import java.util.zip.CRC32C;

public class Test {
    public static void main(String[] args) {
        // Test Driver
        AWS test = new AWS();
        test.awsCrtInit();
        System.out.println("Initiated\n");

        // CRT testing
        System.out.println("Basic memory allocation/deallocation testing");
        AWS.Pointer pt = test.awsCrtMemAcquire(100);
        System.out.println("Memory acquired");
        test.awsCrtMemRelease(pt);
        System.out.println("Memory released\n");

        byte[] key = "TESTSECRETaccesskeyThatDefinitelyDoesntWork".getBytes();
        byte[] token = "ThisIsMyTestSessionTokenIMadeItUpMyself".getBytes();
        byte[] key_id = "TESTAWSACCESSKEYID".getBytes();

        // Credentials Testing
        System.out.println("Credentials testing");
        AWS.Pointer newCred = test.awsCrtCredentialsOptionsNew();
        test.awsCrtCredentialsOptionsSetAccessKeyId(newCred, key_id, key_id.length);
        test.awsCrtCredentialsOptionsSetSecretAccessKey(newCred, key, key.length);
        test.awsCrtCredentialsOptionsSetSessionToken(newCred, token, token.length);
        test.awsCrtCredentialsOptionsSetExpirationTimepointSeconds(newCred, 42);
        System.out.println("Credentials options created");

        pt = test.awsCrtCredentialsNew(newCred);
        System.out.println("Credentials created");
        test.awsCrtCredentialsRelease(pt);
        System.out.println("Credentials released");
        test.awsCrtCredentialsOptionsRelease(newCred);
        System.out.println("Credentials options released\n");

        // Credentials Provider Testing
        System.out.println("Credentials Provider testing");
        AWS.Pointer newCredOption = test.awsCrtCredentialsProviderStaticOptionsNew();
        test.awsCrtCredentialsProviderStaticOptionsSetAccessKeyId(newCredOption, key_id, key_id.length);
        test.awsCrtCredentialsProviderStaticOptionsSetSecretAccessKey(newCredOption, key, key.length);
        test.awsCrtCredentialsProviderStaticOptionsSetSessionToken(newCredOption, token, token.length);
        System.out.println("Credentials Provider Static Options created");

        pt = test.awsCrtCredentialsProviderStaticNew(newCredOption);
        System.out.println("Credentials Provider created");
        test.awsCrtCredentialsProviderRelease(pt);
        System.out.println("Credentials Provider released");
        test.awsCrtCredentialsProviderStaticOptionsRelease(newCredOption);
        System.out.println("Credentials Provider Static Options released\n");

        // Event Group Testing
        System.out.println("Event group testing");
        AWS.Pointer option = test.awsCrtEventLoopGroupOptionsNew();
        System.out.println("Event Group Options created");
        test.awsCrtEventLoopGroupOptionsSetMaxThreads(option, 10);
        pt = test.awsCrtEventLoopGroupNew(option);
        System.out.println("Event Group created");
        test.awsCrtEventLoopGroupRelease(pt);
        System.out.println("Event Group released");
        test.awsCrtEventLoopGroupOptionsRelease(option);
        System.out.println("Event Group Options released\n");

        String k = "host";
        String v = "s3.amazonaws.com";
        ByteBuffer blob = ByteBuffer.allocate(Integer.BYTES * 2 + k.length() + v.length());
        // Java int is Big-Endian
        blob.putInt(k.length());
        blob.put(k.getBytes());
        blob.putInt(v.length());
        blob.put(v.getBytes());

        // HTTP Testing
        System.out.println("Http testing");
        test.awsCrtHttpHeadersNewFromBlob(blob.array(), blob.position());
        System.out.println("Http Headers created");
        test.awsCrtHttpMessageNewFromBlob(blob.array(), blob.position());
        System.out.println("Http Message created\n");

        // CRC Testing
        System.out.println("Crc testing");
        byte[] msg = "hello world".getBytes();

        CRC32 crc = new CRC32();
        crc.update(msg);
        assert(crc.getValue() == test.awsCrtCrc32(msg, msg.length, 0));
        System.out.println("Crc32 passed");

        CRC32C crcc = new CRC32C();
        crcc.update(msg);
        assert(crcc.getValue() == test.awsCrtCrc32c(msg, msg.length, 0));
        System.out.println("Crc32c passed");

        test.awsCrtCleanUp();
        System.out.println("Cleaned up\n");
        System.out.println("All tests passed!");

    }
}