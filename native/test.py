import aws

print(aws.aws_crt_init())
print(aws.aws_crt_clean_up())
print(aws.aws_crt_test_error(1))
print(aws.aws_crt_mem_acquire(2))
print(aws.aws_crt_mem_release(0x01234567))