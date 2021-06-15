from aws import *
aws_crt_init()

pt = aws_crt_mem_acquire(100)
aws_crt_mem_release(pt)

key = 'TESTSECRETaccesskeyThatDefinitelyDoesntWork'
token = 'ThisIsMyTestSessionTokenIMadeItUpMyself'
key_id = 'TESTAWSACCESSKEYID'

new_cred = aws_crt_credentials_options_new()
aws_crt_credentials_options_set_access_key_id(new_cred, key_id, len(key_id))
aws_crt_credentials_options_set_secret_access_key(new_cred, key, len(key))
aws_crt_credentials_options_set_session_token(new_cred, token, len(token))
aws_crt_credentials_options_set_expiration_timepoint_seconds(new_cred, 42)
pt = aws_crt_credentials_new(new_cred)
aws_crt_credentials_release(pt)

aws_crt_clean_up()