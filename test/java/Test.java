import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class Test {
    public static void main(String[] args) {
        String k = "test";
        String v = "string";
        ByteBuffer a = ByteBuffer.allocate(Integer.BYTES * 2 + k.length() + v.length());
        // Java int is Big-Endian
        a.putInt(k.length());
        a.put(k.getBytes());
        a.putInt(v.length());
        a.put(v.getBytes());
        // Test Driver
        AWS test = new AWS();
         test.awsCrtInit();
//         test.awsCrtHttpHeadersNewFromBlob(a.array(), a.position());
    }
}