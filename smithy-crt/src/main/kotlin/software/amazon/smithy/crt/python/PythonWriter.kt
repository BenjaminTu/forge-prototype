package software.amazon.smithy.crt.python

import software.amazon.smithy.crt.traits.CTypeTrait
import software.amazon.smithy.crt.traits.ConstTrait
import software.amazon.smithy.crt.traits.OpaqueTrait
import software.amazon.smithy.crt.traits.PointerTrait
import software.amazon.smithy.model.Model
import software.amazon.smithy.model.SourceLocation
import software.amazon.smithy.model.node.ExpectationNotMetException
import software.amazon.smithy.model.shapes.MemberShape
import software.amazon.smithy.model.shapes.OperationShape
import software.amazon.smithy.model.shapes.StructureShape
import java.lang.StringBuilder

const val MODULE_NAME = "aws"
// At most 26 arguments... Should be enough!
val varName = "abcdefghijklmnopqrstuvwxyz".toCharArray()

private val varMap = mapOf(
    "const char *" to 's',
    "int32_t" to 'i',
    "size_t" to 'n',
    "uint8_t" to 'I',
    "uint64_t" to 'I',
).withDefault {
    // objects
    'O'
}

private val returnMap = mapOf(
    "const char *" to "PyUnicode_FromString",
    "int32_t" to "PyLong_FromLong",
    "size_t" to "PyLong_fromSize_t",
).withDefault {
    // objects
    ""
}


class PythonWriter(private val writer: MyWriter, private val model: Model) {
    private val methodList = mutableListOf<String>()

    private fun isObject(key: String): Boolean{
        return !varMap.containsKey(key)
    }

    private fun getReturnType(returnType: String?): String {
        return if (returnType == null) {
            "Py_RETURN_NONE"
        } else {
            "return ${returnMap.getValue(returnType)}(ret)"
        }
    }

    private fun getCTypeName(shape: MemberShape): String {
        val str = StringBuilder()

        if (shape.hasTrait(ConstTrait::class.java)) {
            str.append("const ")
        }

        val trait = model.expectShape(shape.target).expectTrait(CTypeTrait::class.java)
        str.append(trait.value)

        // TODO: Should not both exist, try to see if can be enforced on model
        if (model.expectShape(shape.target).hasTrait(OpaqueTrait::class.java)) {
            str.append(" *")
        } else if (shape.hasTrait(PointerTrait::class.java)) {
            str.append(" *")
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

    private fun parseArgs(inputFields: List<String>, params: MutableList<Char>) {
        if (inputFields.isNotEmpty()) {
            inputFields.forEachIndexed { i, it ->
                if (!varMap.containsKey(it)) {
                    // override object variable declaration with PyObject *
                    writer.write("PyObject *${varName[i]};")
                } else {
                    writer.write("$it ${varName[i]};")
                }
            }
            writer.writeNewLine()

            val format = inputFields.map { varMap.getValue(it) }.joinToString("")
            val formatArgs = inputFields.mapIndexed { i, _ -> "&${varName[i]}" }.joinToString (", ")

            writer.write("/* Parse arguments */")
            writer.openBlock("if (!PyArg_ParseTuple(args, \"$format\", $formatArgs)) {")
                .write("return NULL;")
            writer.closeBlock("}")

            // If input is object, unwrap it with PyCapsule_GetPointer
            val objectIndices = inputFields.withIndex().filter { isObject(it.value) }.map { it.index }

            objectIndices.forEachIndexed { i, it ->
                // unused variable names
                val tempName = varName[inputFields.size + i]
                // original variable name
                val oriName = varName[i]

                // get pointer
                writer.write("void *$tempName;")
                writer.write("$tempName = (void *) PyCapsule_GetPointer($oriName, \"${inputFields[i]}\");")

                // swap out variable in parameter
                params[it] = tempName
            }
        }
    }

    private fun functionCall(funName:String, param: List<Char>, outputField: String?) {
        // collapse params to String
        val paramsString = param.joinToString (", ")

        if (outputField != null) {
            if (isObject(outputField)) {
                // object
                writer.write("PyObject *ret = PyCapsule_New(${funName}($paramsString), \"$outputField\", NULL);")
            } else {
                // primitives
                writer.write("$outputField ret = ${funName}($paramsString);")
            }
        } else {
            // no return
            writer.write("${funName}($paramsString);")
        }
    }

    private fun defFun() {
        writer.openBlock("static PyMethodDef ${MODULE_NAME}_methods[] = {")
            methodList.forEach {
                writer.write("{\"$it\", method_$it, METH_VARARGS, \"\"},")
            }
            writer.write("{NULL, NULL, 0, NULL}")
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
        val funName = op.id.name
        methodList.add(funName)

        val input = model.expectShape(op.input.orNull(), StructureShape::class.java)
        val output = model.expectShape(op.output.orNull(), StructureShape::class.java)

        val inputFields = getInputFields(input)
        val outputField = getOutputFields(output)

        writer.openBlock("static PyObject *method_${funName}(PyObject *self, PyObject *args) {")
            .write("(void)self;")
            .write("(void)args;")
        writer.writeNewLine()

        val params = varName.slice(inputFields.indices).toMutableList()

        // parse arguments
        parseArgs(inputFields, params)

        // function call
        functionCall(funName, params, outputField)

        // return statement
        writer.write("${getReturnType(outputField)};")

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

        writer.writeNewLine()
        model.operationShapes.forEach {
            writeFun(it)
        }

        finalize()
    }
}