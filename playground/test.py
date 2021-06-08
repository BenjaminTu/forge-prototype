from aws import *
aws_crt_init()
b = aws_crt_test_error()
print(aws_crt_error_name(b))
aws_crt_clean_up()