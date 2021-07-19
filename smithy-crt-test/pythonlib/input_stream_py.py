from aws import *

class InputStream:
    def __init__(self, stream):
        self.stream = stream
        self.opt = aws_crt_input_stream_options_new()
        aws_crt_init()
        aws_crt_input_stream_options_set_seek(self.opt, self.seek)
        aws_crt_input_stream_options_set_read(self.opt, self.read)
        aws_crt_input_stream_options_set_get_status(self.opt, self.get_status)
        aws_crt_input_stream_options_set_get_length(self.opt, self.get_length)
        aws_crt_input_stream_options_set_destroy(self.opt, self.destroy)
        self.i_stream = aws_crt_input_stream_new(self.opt)

    def seek(self, offset, whence):
        print("seek from python")
        self.stream.seek(offset, whence)

    def read(self, m):
        print("read from python")
        data = self.stream.read(len(m))
        n = len(data)
        m[:n] = data
        return n

    def get_status(self):
        print("get_status from python")

    def get_length(self):
        print("get_length from python")

    def destroy(self):
        print("destroy from python")