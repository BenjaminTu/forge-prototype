import input_stream as ist

class InputStream:
    def __init__(self, stream):
        self.stream = stream
        self.opt = ist.aws_crt_input_stream_options_new()
        ist.aws_crt_input_stream_options_set_seek(self.opt, self.seek)
        ist.aws_crt_input_stream_options_set_read(self.opt, self.read)
        ist.aws_crt_input_stream_options_set_get_status(self.opt, self.get_status)
        ist.aws_crt_input_stream_options_set_get_length(self.opt, self.get_length)
        ist.aws_crt_input_stream_options_set_destroy(self.opt, self.destroy)
        self.i_stream = ist.aws_crt_input_stream_new(self.opt)

    def seek(self, offset, whence):
        print("calling seek from python")
        self.stream.seek(offset, whence)

    def read(self, m):
        print("calling read from python")
        data = self.stream.read(len(m))
        n = len(data)
        m[:n] = data
        return n

    def get_status(self):
        print("calling get_status from python")

    def get_length(self):
        print("calling get_length from python")

    def destroy(self):
        print("calling destroy from python")