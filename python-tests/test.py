from aws import *
aws_crt_init()

# crt testing
pt = aws_crt_mem_acquire(100)
aws_crt_mem_release(pt)

key = 'TESTSECRETaccesskeyThatDefinitelyDoesntWork'
token = 'ThisIsMyTestSessionTokenIMadeItUpMyself'
key_id = 'TESTAWSACCESSKEYID'

# credentials_options testing
new_cred = aws_crt_credentials_options_new()
aws_crt_credentials_options_set_access_key_id(new_cred, key_id, len(key_id))
aws_crt_credentials_options_set_secret_access_key(new_cred, key, len(key))
aws_crt_credentials_options_set_session_token(new_cred, token, len(token))
aws_crt_credentials_options_set_expiration_timepoint_seconds(new_cred, 42)

# credentials testing
pt = aws_crt_credentials_new(new_cred)
aws_crt_credentials_release(pt)

# credentials_provider_static_options testing
new_cred_option = aws_crt_credentials_provider_static_options_new()
aws_crt_credentials_provider_static_options_set_access_key_id(new_cred_option, key_id, len(key_id))
aws_crt_credentials_provider_static_options_set_secret_access_key(new_cred_option, key, len(key))
aws_crt_credentials_provider_static_options_set_session_token(new_cred_option, token, len(token))

pt = aws_crt_credentials_provider_static_new(new_cred_option)
aws_crt_credentials_provider_release(pt)

aws_crt_clean_up()