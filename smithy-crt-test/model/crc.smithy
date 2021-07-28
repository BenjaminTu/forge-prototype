namespace com.aws.ffi

structure aws_crt_crc32_input {
    @const
    @pointer
    input: uint8_t,
    length: size_t,
    previous: uint32_t
}

structure aws_crt_crc32_output {
    ret: uint32_t
}

operation aws_crt_crc32 {
    input: aws_crt_crc32_input,
    output: aws_crt_crc32_output
}

structure aws_crt_crc32c_input {
    @const
    @pointer
    input: uint8_t,
    length: size_t,
    previous: uint32_t
}

structure aws_crt_crc32c_output {
    ret: uint32_t
}

operation aws_crt_crc32c {
    input: aws_crt_crc32c_input,
    output: aws_crt_crc32c_output
}