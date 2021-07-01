import input_stream

class InputStream:
    stream = None
    def seek(self, offset, whence):
        print("calling seek")

    def read(self, length):
        print("calling read")

    def get_status(self):
        print("calling get_status")

    def get_length(self):
        print("calling get_length")

    def destroy(self):
        print("calling destroy")

# print(aws.aws_crt_init())
# print(aws.aws_crt_clean_up())
# print(aws.aws_crt_test_error(1))
# print(aws.aws_crt_mem_acquire(2))
# print(aws.aws_crt_mem_release(0x01234567))
# print(aws.aws_crt_default_allocator())