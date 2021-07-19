package software.amazon.smithy.crt.python

import software.amazon.smithy.crt.util.MyWriter
import software.amazon.smithy.model.Model
import software.amazon.smithy.model.shapes.OperationShape
import software.amazon.smithy.model.shapes.StructureShape
import software.amazon.smithy.crt.util.*

const val MODULE_NAME = "aws"
// At most 26 variable names... Should be enough!
val varName = "abcdefghijklmnopqrstuvwxyz".toCharArray()

private val varMap = mapOf(
    "const char *" to "s",
    "int32_t" to "i",
    "size_t" to "n",
    "uint8_t" to "i",
    "uint16_t" to "i",
    "uint64_t" to "I",
    "const uint8_t *" to "y*",
    "Py_buffer" to "y*"
).withDefault {
    // objects
    "O"
}

private val returnMap = mapOf(
    "const char *" to "PyUnicode_FromString",
    "int32_t" to "PyLong_FromLong",
    "uint64_t" to "PyLong_FromUnsignedLong",
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

    private fun getWrapperName(name: String): String {
        return name.removePrefix("const ").trim()
    }

    private fun parseArgs(inputFields: List<String>, params: MutableList<Char>, funName: String) {
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

            val format = inputFields.joinToString("") { varMap.getValue(it) }
            val formatArgs = params.joinToString(", ") { "&$it" }

            writer.write("/* Parse arguments */")
            writer.openBlock("if (!PyArg_ParseTuple(args, \"$format\", $formatArgs)) {")
                .write("printf(\"method_$funName parsing error\\n\");")
                .write("return NULL;")
            writer.closeBlock("}")

            // If input is object, unwrap it with PyCapsule_GetPointer
            val objectIndices = inputFields.withIndex().filter { isObject(it.value) }.map { it.index }

            objectIndices.forEachIndexed { i, it ->
                // unused variable names
                val tempName = varName[inputFields.size + i]
                // original variable name
                val oriName = varName[it]

                // get pointer
                writer.write("${inputFields[i]} $tempName;")
                writer.write("$tempName = (${inputFields[i]}) PyCapsule_GetPointer($oriName, \"${getWrapperName(inputFields[i])}\");")

                // swap out variable in parameter
                params[it] = tempName
            }

            // If input is a uint8_t *, parameter is .buf instead
            val strIndices = inputFields.withIndex().filter { it.value == "Py_buffer" }.map { it.index }

            strIndices.forEachIndexed { i, it ->
                // unused variable names
                val tempName = varName[inputFields.size + objectIndices.size + i]
                // original variable name
                val oriName = varName[it]

                // assign buf
                writer.write("const uint8_t * $tempName = (const uint8_t *) $oriName.buf;")

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
                writer.write("PyObject *ret = PyCapsule_New((void *)${funName}($paramsString), \"${getWrapperName(outputField)}\", NULL);")
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
            // custom methods defined
            writer.write("""
                {"aws_crt_new_buf", method_aws_crt_new_buf, METH_VARARGS, ""},
                {"test_io", method_test_io, METH_VARARGS, ""},
                {"test_http", method_test_http, METH_VARARGS, ""},
                {"aws_crt_input_stream_options_new", method_aws_crt_input_stream_options_new, METH_VARARGS, ""},
                {"aws_crt_input_stream_options_set_seek", method_aws_crt_input_stream_options_set_seek, METH_VARARGS, ""},
                {"aws_crt_input_stream_options_set_read", method_aws_crt_input_stream_options_set_read, METH_VARARGS, ""},
                {"aws_crt_input_stream_options_set_get_status", method_aws_crt_input_stream_options_set_get_status, METH_VARARGS, ""},
                {"aws_crt_input_stream_options_set_get_length", method_aws_crt_input_stream_options_set_get_length, METH_VARARGS, ""},
                {"aws_crt_input_stream_options_set_destroy", method_aws_crt_input_stream_options_set_destroy, METH_VARARGS, ""},
                {"aws_crt_input_stream_new", method_aws_crt_input_stream_new, METH_VARARGS, ""},
                {"aws_crt_input_stream_release", method_aws_crt_input_stream_release, METH_VARARGS, ""},
            """.trimIndent())
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

        var input = model.expectShape(op.input.orElse(null), StructureShape::class.java)
        val output = model.expectShape(op.output.orElse(null), StructureShape::class.java)

        // override type to Py_buffer if type is uint8_t *
        val inputFields = getInputFields(input, model).toMutableList().map {
            if (it.contains("uint8_t *")) "Py_buffer" else it
        }
        val outputField = getOutputFields(output, model)


        writer.openBlock("static PyObject *method_${funName}(PyObject *self, PyObject *args) {")
            .write("(void)self;")
            .write("(void)args;")
        writer.writeNewLine()

        val params = varName.slice(inputFields.indices).toMutableList()

        // parse arguments
        parseArgs(inputFields, params, funName)

        // function call
        functionCall(funName, params, outputField)

        // release Py_buffer if necessary
        inputFields.withIndex().filter { it.value == "Py_buffer" }.map { it.index }.forEach {
            writer.write("PyBuffer_Release(&${varName[it]});")
        }

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
            // custom methods defined
            .write("""
                extern PyObject *method_aws_crt_new_buf(PyObject *, PyObject *);
                extern PyObject *method_test_io(PyObject *, PyObject *);
                extern PyObject *method_test_http(PyObject *, PyObject *);
                extern PyObject *method_aws_crt_input_stream_options_new(PyObject *, PyObject *);
                extern PyObject *method_aws_crt_input_stream_options_set_seek(PyObject *, PyObject *);
                extern PyObject *method_aws_crt_input_stream_options_set_read(PyObject *, PyObject *);
                extern PyObject *method_aws_crt_input_stream_options_set_get_status(PyObject *, PyObject *);
                extern PyObject *method_aws_crt_input_stream_options_set_get_length(PyObject *, PyObject *);
                extern PyObject *method_aws_crt_input_stream_options_set_destroy(PyObject *, PyObject *);
                extern PyObject *method_aws_crt_input_stream_new(PyObject *, PyObject *);
                extern PyObject *method_aws_crt_input_stream_release(PyObject *, PyObject *);
            """.trimIndent())

        writer.writeNewLine()
        model.operationShapes.forEach {
            writeFun(it)
        }

        finalize()
    }
}