package software.amazon.smithy.crt.java

import software.amazon.smithy.crt.util.MyWriter
import software.amazon.smithy.model.Model
import software.amazon.smithy.model.shapes.OperationShape

const val MODULE_NAME = "aws"
// At most 26 variable names... Should be enough!
val varName = "abcdefghijklmnopqrstuvwxyz".toCharArray()

private val varMap = mapOf(
    "const char *" to "String",
    "int32_t" to "int",
    "size_t" to "int",
    "uint8_t" to "int",
    "uint16_t" to "int",
    "uint64_t" to "long",
    "const uint8_t *" to "byte[]",
)

class JavaWriter(private val writer: MyWriter, private val model: Model) {
    private fun toCamelCase(name: String): String {
        val sb = StringBuilder("Java_AWS_")
        val words = name.split("_")
        sb.append(words.first())
        for (str in words.subList(1, words.size)) {
            sb.append(str.substring(0, 1).toUpperCase())
            sb.append(str.substring(1))
        }
        return sb.toString()
    }

    private fun writeFun(op: OperationShape) {
        val funName = toCamelCase(op.id.name)

        writer.openBlock("JNIEXPORT jobject JNICALL $funName(JNIEnv *env) {")
        writer.write(funName)
        writer.closeBlock("}")
    }

    fun execute() {
        // for each method
        model.operationShapes.forEach {
            writeFun(it)
        }
//        finalize()
    }
}