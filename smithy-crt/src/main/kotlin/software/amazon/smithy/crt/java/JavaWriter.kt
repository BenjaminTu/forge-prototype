package software.amazon.smithy.crt.java

import software.amazon.smithy.crt.util.MyWriter
import software.amazon.smithy.model.Model
import software.amazon.smithy.model.shapes.OperationShape
import software.amazon.smithy.crt.util.*
import software.amazon.smithy.model.shapes.StructureShape

// At most 26 variable names... Should be enough!
val varName = "abcdefghijklmnopqrstuvwxyz".toCharArray()

private val varMap = mapOf(
    "const char *" to "jbyteArray",
    "int32_t" to "jint",
    "size_t" to "jint",
    "uint8_t" to "jint",
    "uint16_t" to "jint",
    "uint64_t" to "jlong",
    "const uint8_t *" to "jbyteArray",
).withDefault {
    "jobject"
}

private val returnMap = mapOf(
    "const char *" to "jstring",
    "int32_t" to "jint",
    "size_t" to "jint",
).withDefault {
    "jobject"
}

class JavaWriter(private val writer: MyWriter, private val model: Model) {
    private fun isObject(key: String): Boolean{
        return !varMap.containsKey(key)
    }

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
        return if (name == null) "void" else returnMap.getValue(name)
    }

    private fun parseArgHeaders(inputFields: List<String>): String {
        return if (inputFields.isEmpty()) {
            ""
        } else {
            inputFields.mapIndexed { i, it ->
                ", ${varMap.getValue(it)} ${varName[i]}"
            }.joinToString("")
        }
    }

    private fun parseArgs(inputFields: List<String>, params: MutableList<Char>) {
        if (inputFields.isNotEmpty()) {
            // If input is pointer
            val objectIndices = inputFields.withIndex().filter { isObject(it.value) }.map { it.index }

            objectIndices.forEachIndexed { i, it ->
                // unused variable names
                val tempName = varName[inputFields.size + i]
                // original variable name
                val oriName = varName[it]
                // type name
                val typeName = inputFields[it]

                writer.write("$typeName $tempName = ($typeName) ((*env)->GetLongField(env, $oriName, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, $oriName), \"address\", \"J\")));")

                // swap out variable in parameter
                params[it] = tempName
            }

            // If input is uint8_t *
            val strIndices = inputFields.withIndex().filter { varMap.getValue(it.value) == "jbyteArray" }.map { it.index }

            strIndices.forEachIndexed { i, it ->
                // unused variable names
                val tempName = varName[inputFields.size + objectIndices.size + i]
                // original variable name
                val oriName = varName[it]
                // type name
                val typeName = inputFields[it]

                // get string
                writer.write("$typeName $tempName = ($typeName) (*env)->GetByteArrayElements(env, $oriName, 0);")

                // swap out variable in parameter
                params[it] = tempName
            }
        }
    }

    private fun funCall(outputField: String?, funName: String, params: MutableList<Char>) {
        if (outputField == null) {
            writer.write("$funName(${params.joinToString() });")
        } else {
            if (isObject(outputField)) {
                // double $$ to avoid smithy type inference
                writer.write("""
                    $outputField ret = $funName(${params.joinToString()});
                    jclass cls = (*env)->FindClass(env, "AWS${"$$"}Pointer");
                    jmethodID constructor = (*env)->GetMethodID(env, cls, "<init>", "(J)");
                    return (*env)->NewObject(env, cls, constructor, (long)ret);
                """.trimIndent()
                )
            } else {
                if (returnMap.getValue(outputField) == "jstring") {
                    writer.write("return (*env)->NewStringUTF(env, $funName(${params.joinToString()}));")
                } else {
                    // primitives
                    writer.write("return $funName(${params.joinToString()});")
                }
            }
        }
    }

    private fun writeFun(op: OperationShape) {
        val funName = op.id.name

        val input = model.expectShape(op.input.orElse(null), StructureShape::class.java)
        val output = model.expectShape(op.output.orElse(null), StructureShape::class.java)

        val inputFields = getInputFields(input, model)
        val outputField = getOutputFields(output, model)

        val params = varName.slice(inputFields.indices).toMutableList()
        writer.openBlock("JNIEXPORT ${getReturnType(outputField)} JNICALL ${toJNIName(funName)}(JNIEnv *env, jobject obj${parseArgHeaders(inputFields)}) {")
            .write("(void)env;")
            .write("(void)obj;")
        writer.writeNewLine()

        parseArgs(inputFields, params)

        funCall(outputField, funName, params)

        writer.closeBlock("}")
        writer.writeNewLine()
    }

    fun execute() {
        writer.write("#include <jni.h>")
            .write("#include <stdint.h>")
            .write("#include \"api.h\"")
        writer.writeNewLine()

        // for each method
        model.operationShapes.forEach {
            writeFun(it)
        }
    }
}