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

@trait
structure malloc {}

@trait
structure free {}