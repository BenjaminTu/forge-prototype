namespace com.aws.ffi

// /* Ctypes */

@ctype("uint8_t")
structure uint8_t {
    value: Integer
}

@ctype("int32_t")
structure int32_t {
    value: Integer
}

@ctype("int64_t")
structure int64_t {
    value: BigInteger
}

@ctype("uint64_t")
structure uint64_t {
    value: BigInteger
}

@ctype("size_t")
structure size_t {
    value: BigInteger
}

@ctype("char *")
structure string {
    value: String
}

@ctype("void")
structure void {}
