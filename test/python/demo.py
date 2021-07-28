from aws import *
import binascii

msg = b'hello'
print(binascii.crc32(msg))
print(aws_crt_crc32(msg, len(msg), 0))