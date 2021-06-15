from aws import *
aws_crt_init()

pt = aws_crt_mem_acquire(100)
aws_crt_mem_release(pt)

new_cred = aws_crt_credentials_options_new()
pt = aws_crt_credentials_new(new_cred)
aws_crt_credentials_release(pt)

aws_crt_clean_up()