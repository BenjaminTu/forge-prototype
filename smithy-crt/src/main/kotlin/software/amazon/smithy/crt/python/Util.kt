package software.amazon.smithy.crt.python

import java.util.Optional

fun <T> Optional<T>.orNull(): T? = this.orElse(null)
