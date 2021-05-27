import java.io.File
import java.lang.StringBuilder

// import software.amazon.smithy.model.shapes.*

class PythonWriter (name: String, moduleName: String) {
    private val filename: String = name
    private val commentCharacter: String = "//"
    private val fileObj: File = File(name)
    private val moduleName = moduleName
    private var methodList = mutableListOf<Pair<String, String>>()

    init {
        fileObj.writeText("#include <Python.h>" + System.lineSeparator() + System.lineSeparator())
    }

    private fun writeToFile(text: String) {
        fileObj.appendText(text + System.lineSeparator() + System.lineSeparator())
    }

    private fun defFunc() {
        var methods = StringBuilder("static PyMethodDef ${moduleName}Methods[] = {\n")
        methodList.forEach {
            methods.append("\t{\"${it.first}\", method_${it.first}, METH_VARARGS, \"${it.second}\"},\n")
        }
        // remove last comma
        methods.setLength(methods.length - 2)
        methods.append("\n};")

        writeToFile(methods.toString())
    }

    fun defModule(comment: String, memorySize: Int) {
        defFunc()
        writeToFile(
        """
            static struct PyModuleDef ${moduleName}_module = {
                PyModuleDef_HEAD_INIT,
                "$moduleName",
                "$comment",
                $memorySize,
                ${moduleName}Methods
            };

            PyMODINIT_FUNC PyInit_${moduleName}(void) {
                return PyModule_Create(&${moduleName}_module);
            }
        """.trimIndent())
    }

    fun writeFunc(attribute: String, returnType: String, funcName: String, comment: String) {
        // add method to list
        methodList.add(Pair<String, String>(funcName, comment))

        writeToFile(
        """
            $attribute $returnType $funcName(PyObject *self, PyObject *args) {
                // placeholder for parsing argument
                // return placeholder
            }
        """.trimIndent())
    }
}

fun main() {
    val aws = PythonWriter("aws.c", "aws")
    aws.writeFunc("static","PyObject *", "aws_crt_init", "Python interface for the C library")
    aws.writeFunc("static","PyObject *", "aws_crt_clean_up", "Python interface for the C library")
    aws.writeFunc("static","PyObject *", "aws_crt_test_error", "Python interface for the C library")
    aws.writeFunc("static","PyObject *", "aws_crt_mem_acquire", "Python interface for the C library")
    aws.writeFunc("static","PyObject *", "aws_crt_mem_release", "Python interface for the C library")

    aws.defModule("Python interface for the test aws in C library",-1)
}