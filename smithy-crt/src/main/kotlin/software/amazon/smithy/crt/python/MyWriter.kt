
package software.amazon.smithy.crt.python

import software.amazon.smithy.codegen.core.Symbol
import software.amazon.smithy.codegen.core.writer.CodegenWriter
import software.amazon.smithy.codegen.core.writer.ImportContainer


class MyWriter(namespace: String) :
    CodegenWriter<MyWriter, ImportContainer>(null, MyImportContainer(namespace)) {

    class MyImportContainer(private var namespace: String) : ImportContainer {
        override fun importSymbol(symbol: Symbol?, alias: String?) {
            namespace = ""
        }
    }

    fun writeNewLine() {
        write("")
    }
}