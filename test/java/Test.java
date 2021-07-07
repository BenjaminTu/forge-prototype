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
        new AWS().http_headers_new_from_blob(a.array(), a.position());
    }
}