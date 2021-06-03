
package software.amazon.smithy.crt.python;

import java.io.File
import java.lang.StringBuilder

// import software.amazon.smithy.model.shapes.*

class PythonWriter (name: String, moduleName: String, description: String) {
    private val filename: String = name
    private val commentCharacter: String = "//"
    private val fileObj: File = File(name)
    private val moduleName = moduleName
    private val moduleDescription : String = description
    private var methodList = mutableListOf<Pair<String, String>>()

    init {
        fileObj.writeText("#include <Python.h>" + System.lineSeparator() + System.lineSeparator())
    }

    private fun writeToFile(text: String) {
        fileObj.appendText(text + System.lineSeparator() + System.lineSeparator())
    }

    private fun defFunc() {
        var methods = StringBuilder("static PyMethodDef ${moduleName}_methods[] = {" + System.lineSeparator())
        methodList.forEach {
            methods.append("\t{\"${it.first}\", method_${it.first}, METH_VARARGS, \"${it.second}\"}," + System.lineSeparator())
        }
        // remove last comma
        // methods.setLength(methods.length - 2)
        // methods.append(System.lineSeparator() + "};")

        methods.append("\t{NULL, NULL, 0, NULL}" + System.lineSeparator())
        methods.append("};")

        writeToFile(methods.toString())
    }

    fun defModule(memorySize: Int) {
        defFunc()
        writeToFile(
        """
            static struct PyModuleDef ${moduleName}_module = {
                PyModuleDef_HEAD_INIT,
                "$moduleName",
                "$moduleDescription",
                $memorySize,
                ${moduleName}_methods
            };

            PyMODINIT_FUNC PyInit_${moduleName}(void) {
                return PyModule_Create(&${moduleName}_module);
            }
        """.trimIndent())
    }

    fun writeFunc(attribute: String, returnType: String, funcName: String, comment: String = "") {
        // add method to list
        methodList.add(Pair<String, String>(funcName, comment))

        writeToFile(
        """
            $attribute $returnType method_$funcName(PyObject *self, PyObject *args) {
                // placeholder for parsing argument
                // return placeholder
            }
        """.trimIndent())
    }

    fun setupPy(version: String, author: String, email:String ) {
        var setupFile = File("setup.py")
        setupFile.writeText(
            """
            from distutils.core import setup, Extension

            def main():
                setup(name="$moduleName",
                      version="$version",
                      description="$moduleDescription",
                      author="$author",
                      author_email="$email",
                      ext_modules=[Extension("$moduleName", ["$filename"])])

            if __name__ == "__main__":
                main()
        """.trimIndent())
    }
}