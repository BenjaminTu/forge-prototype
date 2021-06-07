package software.amazon.smithy.crt.python

import software.amazon.smithy.model.Model
import software.amazon.smithy.model.shapes.OperationShape
import software.amazon.smithy.model.shapes.ShapeId
import software.amazon.smithy.model.shapes.StructureShape
import java.lang.StringBuilder

const val CTYPE_TRAIT = "com.aws.ffi#ctype"
const val POINTER_TRAIT = "com.aws.ffi#pointer"
const val CONST_TRAIT = "com.aws.ffi#const"
const val OPAQUE_TRAIT = "com.aws.ffi#opaque"

val MODULE_NAME = "aws"
val varName = "abcdefghijklmnopqrstuvwxyz".toCharArray()

val varMap = mapOf(
    "const char *" to 's',
    "int32_t" to 'i',
    "size_t" to 'n',
    "uint8_t" to 'I',
    "uint64_t" to 'I',
)

val returnMap = mapOf(
    "const char *" to "PyUnicode_FromString",
    "int32_t" to "PyLong_From_Long",
    "size_t" to "PyLong_fromSize_t",
)

class PythonWriterNew (private val model: Model) {
    private var methodList = mutableListOf<String>()

    private fun getCTypeName(id: ShapeId): String {
        // TODO: should use expectTrait instead of findTrait
        val cTypeTrait = model.expectShape(id).findTrait(CTYPE_TRAIT).orNull()
        val res = cTypeTrait?.toNode()?.expectObjectNode()?.expectStringMember("typename").toString()
        // TODO: same here
        val opaqueTrait = model.expectShape(id).findTrait(OPAQUE_TRAIT).orNull()
        return if (opaqueTrait != null) "$res *" else res
    }

    /**
     * Get structure's(input/output) fields
     *
     * @param struct StructureShape to analyze
     * @return Returns the Ids of the field as a List of ShapeId
     */

    private fun getFields(struct: StructureShape): List<String> {
        return struct.allMembers.toList().map{
            val str = StringBuilder()

            if (it.second.hasTrait(CONST_TRAIT)) {
                str.append("const ")
            }

            str.append(getCTypeName(it.second.target))

            if (it.second.hasTrait(POINTER_TRAIT)) {
                str.append(" *")
            }

            str.toString()
        }
    }

    private fun getInputFields(struct: StructureShape): List<String> {
        return getFields(struct)
    }

    private fun getOutputFields(struct: StructureShape): String? {
        val ret = getFields(struct)
        if (ret.size != 1) {
            // TODO: raise exception
        }
        return ret.firstOrNull()
    }

    private fun getReturnType(returnType: String?): String {
        return when {
            returnType == null -> {
                // no return type (void)
                "Py_RETURN_NONE"
            }
            returnMap[returnType] == null -> {
                // object pointers (no entry)
                "PyLong_FromVoidPtr((void *)ret)"
            }
            else -> {
                // primitive (entry exists)
                "${returnMap[returnType]}(ret)"
            }
        }
    }

    private fun getFormat(cTypeName: String): Char {
        // return format, else treat as object pointer
        return varMap[cTypeName] ?: 'o'
    }

    private fun defFun(): String {
        var methods = StringBuilder("static PyMethodDef ${MODULE_NAME}_methods[] = {" + System.lineSeparator())
        methodList.forEach {
            methods.append("\t{\"$it\", method_$it, METH_VARARGS, \"\"}," + System.lineSeparator())
        }

        methods.append("\t{NULL, NULL, 0, NULL}" + System.lineSeparator())
        methods.append("};")
        return methods.toString()
    }

    private fun defModule(): String {
        return """
            static struct PyModuleDef ${MODULE_NAME}_module = {
                PyModuleDef_HEAD_INIT,
                "$MODULE_NAME",
                "",
                -1,
                ${MODULE_NAME}_methods
            };

            PyMODINIT_FUNC PyInit_${MODULE_NAME}(void) {
                return PyModule_Create(&${MODULE_NAME}_module);
            }
        """.trimIndent()
    }

    private fun setupPy(): String {
        return """
            from distutils.core import setup, Extension

            def main():
                setup(name="$MODULE_NAME",
                      version="1.0.0",
                      description="",
                      author="",
                      author_email="",
                      ext_modules=[Extension("$MODULE_NAME", ["$MODULE_NAME.c"])])

            if __name__ == "__main__":
                main()
        """.trimIndent()
    }

    private fun writeFun(op: OperationShape): String {
        methodList.add(op.id.name)

        val input = model.expectShape(op.input.orNull(), StructureShape::class.java)
        val output = model.expectShape(op.output.orNull(), StructureShape::class.java)

        val inputFields = getInputFields(input)
        val outputField = getOutputFields(output)

        val str = StringBuilder("static PyObject *method_${op.id.name} (PyObject *self, PyObject *args) {" + System.lineSeparator())

        // argument parse
        if (inputFields.isNotEmpty()) {
            // At most 26 arguments... Should be enough!
            inputFields.forEachIndexed { i, it ->
                str.append("\t$it ${varName[i]};" + System.lineSeparator())
            }

            val format = inputFields.map { getFormat(it) }.joinToString("")
            val formatArgs = inputFields.mapIndexed { i, _ -> "&${varName[i]}" }.joinToString (", ")
            str.append(System.lineSeparator())
            str.append("\t/* Parse arguments */" + System.lineSeparator())
            str.append("\tif (!PyArg_ParseTuple(args, \"$format\", $formatArgs) {" + System.lineSeparator())
            str.append("\t\t return NULL;" + System.lineSeparator())
            str.append("\t}" + System.lineSeparator())
        }

        // function call
        str.append("\t")
        if (outputField != null) {
            str.append("$outputField ret = ")
        }
        val params = inputFields.mapIndexed { i, _ -> "${varName[i]}" }.joinToString (", ")
        str.append("${op.id.name}($params);" + System.lineSeparator())

        // return
        str.append("\treturn ${getReturnType(outputField)}" + System.lineSeparator())

        str.append("}" + System.lineSeparator())
        return str.toString()
    }

    fun finalize() {
        println(defFun())
        println(defModule())
        println(setupPy())
    }

    fun execute() {
        // for each method
        println("#include <Python.h>" + System.lineSeparator())
        val operations = model.operationShapes
        operations.forEach {
            println(writeFun(it))
        }
        finalize()
    }
}