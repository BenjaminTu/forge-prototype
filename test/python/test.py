from aws import *
from input_stream_py import InputStream
import struct

aws_crt_init()
print("Initiated\n")
# crt testing
print("Basic memory allocation/deallocation testing")
pt = aws_crt_mem_acquire(100)
print("Memory acquired")
aws_crt_mem_release(pt)
print("Memory released\n")

key = b'TESTSECRETaccesskeyThatDefinitelyDoesntWork'
token = b'ThisIsMyTestSessionTokenIMadeItUpMyself'
key_id = b'TESTAWSACCESSKEYID'

# credentials testing
print("Credentials testing")
new_cred = aws_crt_credentials_options_new()
aws_crt_credentials_options_set_access_key_id(new_cred, key_id, len(key_id))
aws_crt_credentials_options_set_secret_access_key(new_cred, key, len(key))
aws_crt_credentials_options_set_session_token(new_cred, token, len(token))
aws_crt_credentials_options_set_expiration_timepoint_seconds(new_cred, 42)
print("Credentials options created")

pt = aws_crt_credentials_new(new_cred)
print("Credentials created")
aws_crt_credentials_release(pt)
print("Credentials released")
aws_crt_credentials_options_release(new_cred)
print("Credentials options released\n")

# credentials_provider testing
print("Credentials Provider testing")
new_cred_option = aws_crt_credentials_provider_static_options_new()
aws_crt_credentials_provider_static_options_set_access_key_id(new_cred_option, key_id, len(key_id))
aws_crt_credentials_provider_static_options_set_secret_access_key(new_cred_option, key, len(key))
aws_crt_credentials_provider_static_options_set_session_token(new_cred_option, token, len(token))
print("Credentials Provider Static Options created")

pt = aws_crt_credentials_provider_static_new(new_cred_option)
print("Credentials Provider created")
aws_crt_credentials_provider_release(pt)
print("Credentials Provider released")
aws_crt_credentials_provider_static_options_release(new_cred_option)
print("Credentials Provider Static Options released\n")

# event group testing
print("Event group testing")
option = aws_crt_event_loop_group_options_new()
print("Event Group Options created")
aws_crt_event_loop_group_options_set_max_threads(option, 10)
pt = aws_crt_event_loop_group_new(option)
print("Event Group created")
aws_crt_event_loop_group_release(pt)
print("Event Group released")
aws_crt_event_loop_group_options_release(option)
print("Event Group Options released\n")


blob = struct.pack(">I", 4) + b'host' + struct.pack(">I", 16) + b's3.amazonaws.com'
# http testing
print("Http testing")
aws_crt_http_headers_new_from_blob(blob, len(blob))
print("Http Headers created")
aws_crt_http_message_new_from_blob(blob, len(blob))
print("Http Message created\n")

aws_crt_clean_up()
print("Cleaned up\n")

print("All tests passed!")