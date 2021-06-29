from aws import *
from input_stream_py import InputStream
from crt_util import *
import struct
import io

aws_crt_init()

key = b'host'
val = b'example.org'

# http header test
blob = struct.pack(">I", len(key)) + key + struct.pack(">I", len(val)) + val
header = aws_crt_http_headers_new_from_blob(blob, len(blob))
aws_crt_http_headers_release(header)

# http msg test
src_data = b'a long string here'
python_stream = io.BytesIO(src_data)
test = InputStream(python_stream)

buf = aws_crt_new_buf()
msg = aws_crt_http_message_new_from_blob(blob, len(blob))
aws_crt_http_message_set_body_stream(msg, test.i_stream)
aws_crt_http_message_to_blob(msg, buf)

aws_crt_http_message_release(msg)

aws_crt_clean_up()
