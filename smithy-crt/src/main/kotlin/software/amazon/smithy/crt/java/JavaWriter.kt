package software.amazon.smithy.crt.java

import software.amazon.smithy.crt.util.MyWriter
import software.amazon.smithy.model.Model
import software.amazon.smithy.model.shapes.OperationShape
import software.amazon.smithy.crt.util.*
import software.amazon.smithy.model.shapes.MemberShape
import software.amazon.smithy.model.shapes.StructureShape


const val MODULE_NAME = "aws"
// At most 26 variable names... Should be enough!
val varName = "abcdefghijklmnopqrstuvwxyz".toCharArray()

private val varMap = mapOf(
    "const char *" to "String",
    "int32_t" to "jint",
    "size_t" to "jint",
    "uint8_t" to "jint",
    "uint16_t" to "jint",
    "uint64_t" to "jlong",
    "const uint8_t *" to "jbyteArray",
)

private val returnMap = mapOf(
    "const char *" to "String",
    "int32_t" to "int",
    "size_t" to "int",
    "uint8_t" to "int",
    "uint16_t" to "int",
    "uint64_t" to "long",
    "const uint8_t *" to "byte[]",
).withDefault {
    "jobject"
}

class JavaWriter(private val writer: MyWriter, private val model: Model) {
    private fun toJNIName(name: String): String {
        val sb = StringBuilder("Java_AWS_")
        val words = name.split("_")
        sb.append(words.first())
        for (str in words.subList(1, words.size)) {
            sb.append(str.substring(0, 1).uppercase())
            sb.append(str.substring(1))
        }
        return sb.toString()
    }

    private fun getReturnType(name: String?): String {
        return if (name == null) {
            "void"
        } else {
            "${returnMap.getValue(name)}"
        }
    }

    private fun parseArgs(inputFields: List<String>) {
        if (inputFields.isNotEmpty()) {

        }
    }

    private fun writeFun(op: OperationShape) {
        val funName = op.id.name

        val input = model.expectShape(op.input.orElse(null), StructureShape::class.java)
        val output = model.expectShape(op.output.orElse(null), StructureShape::class.java)

        val inputFields = getInputFields(input, model)
        val outputField = getOutputFields(output, model)

        val params = varName.slice(inputFields.indices)
        print(params)

        writer.openBlock("JNIEXPORT ${getReturnType(outputField)} JNICALL ${toJNIName(funName)}(JNIEnv *env, jobject obj) {")
            .write("(void)env")
            .write("(void)obj")

        parseArgs(inputFields)

        if (outputField == null) {
            writer.write("$funName($)")
        }

        writer.closeBlock("}")
    }

    fun execute() {
        // for each method
        model.operationShapes.forEach {
            writeFun(it)
        }
    }
}