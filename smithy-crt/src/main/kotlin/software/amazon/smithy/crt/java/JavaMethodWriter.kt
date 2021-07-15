package software.amazon.smithy.crt.java

import software.amazon.smithy.crt.util.MyWriter
import software.amazon.smithy.crt.util.getInputFields
import software.amazon.smithy.crt.util.getOutputFields
import software.amazon.smithy.model.Model
import software.amazon.smithy.model.shapes.StructureShape

private val varMap = mapOf(
    "const char *" to "String",
    "int32_t" to "int",
    "size_t" to "int",
    "uint8_t" to "int",
    "uint16_t" to "int",
    "uint64_t" to "long",
    "const uint8_t *" to "byte[]",
).withDefault {
    "Pointer"
}


class JavaMethodWriter(private val writer: MyWriter, private val model: Model) {

    private fun toJNIName(name: String): String {
        val sb = StringBuilder()
        val words = name.split("_")
        sb.append(words.first())
        for (str in words.subList(1, words.size)) {
            sb.append(str.substring(0, 1).uppercase())
            sb.append(str.substring(1))
        }
        return sb.toString()
    }

    fun execute() {
        writer.openBlock("public class AWS {")
            .write(
                """                
                static {
                    System.loadLibrary("aws-crt-jni");
                }

                public class Pointer {
                    private long address;
                    public Pointer(long addr) {
                        address = addr;
                    }
                    
                    public long getAddr() {
                        return address;
                    }
                }
                """.trimIndent()
            )
        writer.writeNewLine()

        model.operationShapes.forEach { op ->
            val funName = op.id.name
            val input = model.expectShape(op.input.orElse(null), StructureShape::class.java)
            val output = model.expectShape(op.output.orElse(null), StructureShape::class.java)

            val inputFields = getInputFields(input, model)
            val outputField = getOutputFields(output, model)

            val returnType = if (outputField == null) "void" else varMap.getValue(outputField)
            val fieldNames = input.memberNames
            val params = inputFields.map{ varMap.getValue(it) }

            val args = params.zip(fieldNames).map {
                "${it.first} ${it.second}"
            }
            writer.write("public native $returnType ${toJNIName(funName)}(${args.joinToString(", ")});")
        }
        writer.closeBlock("}")
        writer.writeNewLine()

    }
}