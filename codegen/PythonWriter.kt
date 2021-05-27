import java.util.*
import java.io.File
import software.amazon.smithy.model.shapes.*

class PythonWriter {
    private val filename: String,
    private val commentCharacter: String = "//",
    private val fileObj: File,

    constructor

    fun createFile(name: String) {
        this.filename = name;
        this.fileObj = File.createNewFile(this.filename);
    }

    fun writeFunct(): {
        fileObj.printWriter()
    }
}

fun main() {
    println("Hello World!")
}