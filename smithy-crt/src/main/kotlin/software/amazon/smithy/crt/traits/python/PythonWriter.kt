package software.amazon.smithy.crt.traits.python

import software.amazon.smithy.crt.traits.CTypeTrait
import software.amazon.smithy.crt.traits.ConstTrait
import software.amazon.smithy.crt.traits.OpaqueTrait
import software.amazon.smithy.crt.traits.PointerTrait
import software.amazon.smithy.model.Model
import software.amazon.smithy.model.SourceLocation
import software.amazon.smithy.model.node.ExpectationNotMetException
import software.amazon.smithy.model.shapes.MemberShape
import software.amazon.smithy.model.shapes.OperationShape
import software.amazon.smithy.model.shapes.ShapeId
import software.amazon.smithy.model.shapes.StructureShape
import java.lang.StringBuilder
import java.lang.reflect.Member

const val MODULE_NAME = "aws"
val varName = "abcdefghijklmnopqrstuvwxyz".toCharArray()

private val varMap = mapOf(
    "const char *" to 's',
    "int32_t" to 'i',
    "size_t" to 'n',
    "uint8_t" to 'I',
    "uint64_t" to 'I',
)

private val returnMap = mapOf(
    "const char *" to "PyUnicode_FromString",
    "int32_t" to "PyLong_FromLong",
    "size_t" to "PyLong_fromSize_t",
)


class PythonWriter(private val writer: MyWriter, private val model: Model) {
    private var methodList = mutableListOf<String>()

    private fun getFormat(cTypeName: String): Char {
        // return format, else treat as object pointer
        return varMap[cTypeName] ?: 'o'
    }

    private fun getReturnType(returnType: String?): String {
        return when {
            returnType == null -> {
                // no return type (void)
                "Py_RETURN_NONE"
            }
            returnMap[returnType] == null -> {
                // object pointers (no entry)
                "return PyLong_FromVoidPtr((void *)ret)"
            }
            else -> {
                // primitive (entry exists)
                "return ${returnMap[returnType]}(ret)"
            }
        }
    }

    private fun getCTypeName(shape: MemberShape): String {
        val str = StringBuilder()

        if (shape.hasTrait(ConstTrait::class.java)) {
            str.append("const ")
        }

        if (model.expectShape(shape.target).hasTrait(CTypeTrait::class.java)) {
            val trait = model.expectShape(shape.target).expectTrait(CTypeTrait::class.java)
            if (varMap[trait.value] != null) {
                str.append("${trait.value} ")
            } else {
                str.append("PyObject ")
            }
        }

        // TODO: Should not both exist, try to see if can be enforced on model
        if (model.expectShape(shape.target).hasTrait(OpaqueTrait::class.java)) {
            str.append("*")
        } else if (shape.hasTrait(PointerTrait::class.java)) {
            str.append("*")
        }

        return str.toString()
    }

    /**
     * Get structure's(input/output) fields
     *
     * @param struct StructureShape to analyze
     * @return Returns the Ids of the field as a List of ShapeId
     */

    private fun getFields(struct: StructureShape): List<String> {
        return struct.allMembers.toList().map{
            getCTypeName(it.second)
        }
    }

    private fun getInputFields(struct: StructureShape): List<String> {
        return getFields(struct)
    }

    private fun getOutputFields(struct: StructureShape): String? {
        val ret = getFields(struct)
        if (ret.size > 1) {
            throw ExpectationNotMetException("Output structures ${struct.id} should have at most 1 field", SourceLocation.NONE)
        }
        return ret.firstOrNull()
    }

    private fun defFun() {
        writer.openBlock("static PyMethodDef ${MODULE_NAME}_methods[] = {")
            methodList.forEach {
                writer.write("{\"$it\", method_$it, METH_VARARGS, \"\"},")
            }
            writer.write("{NULL, NULL, 0, NULL}" + System.lineSeparator())
        writer.closeBlock("};")
    }

    private fun defModule() {
        writer.write("""
            static struct PyModuleDef ${MODULE_NAME}_module = {
                PyModuleDef_HEAD_INIT,
                "$MODULE_NAME",
                "",
                -1,
                ${MODULE_NAME}_methods,
                NULL,
                NULL,
                NULL,
                NULL
            };

            PyMODINIT_FUNC PyInit_$MODULE_NAME(void) {
                return PyModule_Create(&${MODULE_NAME}_module);
            }
        """.trimIndent())
    }

    private fun writeFun(op: OperationShape) {
        methodList.add(op.id.name)

        val input = model.expectShape(op.input.orNull(), StructureShape::class.java)
        val output = model.expectShape(op.output.orNull(), StructureShape::class.java)

        val inputFields = getInputFields(input)
        val outputField = getOutputFields(output)

        writer.openBlock("static PyObject *method_${op.id.name}(PyObject *self, PyObject *args) {")
            .write("(void)self;")
            .write("(void)args;")
        writer.writeNewLine()

        var params = inputFields.mapIndexed { i, _ -> varName[i] }.toMutableList()

        // argument parse
            if (inputFields.isNotEmpty()) {
                // At most 26 arguments... Should be enough!
                inputFields.forEachIndexed { i, it ->
                    writer.write("$it${varName[i]};")
                }
                writer.writeNewLine()

                val format = inputFields.map { getFormat(it) }.joinToString("")
                val formatArgs = inputFields.mapIndexed { i, _ -> "&${varName[i]}" }.joinToString (", ")

                writer.write("/* Parse arguments */")
                writer.openBlock("if (!PyArg_ParseTuple(args, \"$format\", $formatArgs)) {")
                    .write("return NULL;")
                writer.closeBlock("}")

                // If input is object, assume its PyCapsule and get the pointer
                var objectIndices = format.withIndex().filter { it.value =='o' }.map { it.index }

                objectIndices.forEachIndexed() { i, it ->
                    // unused variable names
                    var tempName = varName[inputFields.size + i]
                    // original variable name
                    var oriName = varName[i]

                    // get pointer
                    writer.write("void *$tempName;")
                    writer.write("$tempName = (void *) PyCapsule_GetPointer($oriName, \"${inputFields[i]}\");")

                    // swap out variable in parameter
                    params[it] = tempName
                }

            }

        // collapse to string
        val paramsString = params.joinToString (", ")

        // function call
        if (outputField != null) {
            if (varMap[outputField] == null) {
                // object
                writer.write("PyObject *ret = PyCapsule_New(${op.id.name}($paramsString), \"$outputField\", NULL);")
                writer.write("return ret;")
            } else {
                // primitives
                writer.write("$outputField ret = ${op.id.name}($paramsString);")
                writer.write("${getReturnType(outputField)};")
            }
        } else {
            // no returns
            writer.write("${op.id.name}($paramsString);")
            writer.write("${getReturnType(outputField)};")
        }

        writer.closeBlock("}")
        writer.writeNewLine()
    }

    private fun finalize() {
        defFun()
        writer.writeNewLine()
        defModule()
    }

    fun execute() {
        // for each method
        writer.write("#include <Python.h>")
            .write("#include \"api.h\"")
            .write("")

        model.operationShapes.forEach {
            writeFun(it)
        }

        finalize()
    }
}