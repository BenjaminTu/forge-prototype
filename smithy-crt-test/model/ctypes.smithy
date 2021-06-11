namespace com.aws.ffi

// /* Ctypes */

@ctype(typename: "uint8_t")
structure uint8_t {
    @required
    value: Integer
}

@ctype(typename: "int32_t")
structure int32_t {
    @required
    value: Integer
}

@ctype(typename: "int64_t")
structure int64_t {
    @required
    value: BigInteger
}

@ctype(typename: "uint64_t")
structure uint64_t {
    @required
    value: BigInteger
}

@ctype(typename: "size_t")
structure size_t {
    @required
    value: BigInteger
}

@ctype(typename: "char *")
structure string {
    @required
    value: String
}

@ctype(typename: "void")
structure void {}
