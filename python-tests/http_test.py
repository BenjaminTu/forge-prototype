from aws import *
from input_stream_py import InputStream
from crt_util import *
import struct
import io

def get_blob(key, val):
    return struct.pack(">I", len(key)) + key + struct.pack(">I", len(val)) + val

aws_crt_init()

key = b'host'
val = b'example.org'
blob = get_blob(key, val)

# http header test
buf = aws_crt_new_buf()
header = aws_crt_http_headers_new_from_blob(blob, len(blob))
aws_crt_http_headers_to_blob(header, buf)
test_http(buf)
print("expected: %s" % str([b for b in blob]))
print("len: %d" % len(blob))
aws_crt_http_headers_release(header)

# http msg test
src_data = b'a long string here'
python_stream = io.BytesIO(src_data)
test = InputStream(python_stream)

blob = get_blob(b'GET', b'/') + blob
msg = aws_crt_http_message_new_from_blob(blob, len(blob))
aws_crt_http_message_set_body_stream(msg, test.i_stream)
aws_crt_http_message_to_blob(msg, buf)
# prints out content in buf
test_http(buf)
print("expected: " + str([b for b in blob]))
print("len: " + str(len(blob)))
aws_crt_http_message_release(msg)

aws_crt_clean_up()
