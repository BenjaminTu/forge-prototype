package software.amazon.smithy.crt.python

import software.amazon.smithy.codegen.core.writer.CodegenWriterFactory

class MyWriterFactory : CodegenWriterFactory<MyWriter> {
    override fun apply(filename: String, namespace: String): MyWriter {
        return MyWriter(namespace)
    }
}