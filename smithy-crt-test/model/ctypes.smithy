namespace com.aws.ffi

// /* Ctypes */

@ctype("uint8_t")
structure uint8_t {
    @required
    value: Integer
}

@ctype("int32_t")
structure int32_t {
    @required
    value: Integer
}

@ctype("int64_t")
structure int64_t {
    @required
    value: BigInteger
}

@ctype("uint64_t")
structure uint64_t {
    @required
    value: BigInteger
}

@ctype("size_t")
structure size_t {
    @required
    value: BigInteger
}

@ctype("char *")
structure string {
    @required
    value: String
}

@ctype("void")
structure void {}
