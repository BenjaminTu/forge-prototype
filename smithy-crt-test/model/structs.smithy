namespace com.aws.ffi

// /* Traits */
@trait
structure ctype {
    @required
    typename: String
}

@trait
structure const {}

@trait
structure pointer {}

@trait
structure opaque {}

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

// /* Self-defined Structs */

// typedef struct aws_allocator aws_crt_allocator;
@ctype(typename: "aws_crt_allocator")
@opaque
structure aws_crt_allocator {}

// typedef struct aws_credentials aws_crt_credentials;
@ctype(typename: "aws_crt_credentials")
@opaque
structure aws_crt_credentials {}

// typedef struct _aws_crt_credentials_options aws_crt_credentials_options;
@ctype(typename: "aws_crt_credentials_options")
@opaque
structure aws_crt_credentials_options {}

// typedef struct aws_credentials_provider aws_crt_credentials_provider;
@ctype(typename: "aws_crt_credentials_provider")
@opaque
structure aws_crt_credentials_provider {}





