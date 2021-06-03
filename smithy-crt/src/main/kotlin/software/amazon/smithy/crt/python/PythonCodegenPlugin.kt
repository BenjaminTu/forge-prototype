
package software.amazon.smithy.crt.python

import software.amazon.smithy.build.PluginContext
import software.amazon.smithy.build.SmithyBuildPlugin
import software.amazon.smithy.model.shapes.StructureShape
import java.sql.Struct
import java.util.logging.Level
import java.util.logging.Logger

class PythonCodegenPlugin : SmithyBuildPlugin {
    private val LOG = Logger.getLogger(PythonCodegenPlugin::class.simpleName)

    override fun getName(): String {
        return "python-codegen"
    }

    override fun execute(pluginContext: PluginContext) {
        val root = Logger.getLogger("")
        root.level = Level.ALL
        root.handlers.forEach {
            it.level = Level.ALL
        }
        LOG.warning("Running PythonCodegenPlugin...")

        try {
            val model = pluginContext.model

            // each method
            val operations = model.operationShapes
            operations.forEach {
                var modelName = it
                var input = model.getShape(it.input.orNull()).orNull() as? StructureShape
                var output = model.getShape(it.output.orNull()).orNull() as? StructureShape

                println(modelName)
                println(input)
                processInput(input)
                println(output)
                println()
            }

//            it.accept(pluginContext.fileManifest.baseDir) { pythonFile ->
//                pluginContext.fileManifest.addFile(pythonFile)
//                LOG.info("Generated ${pythonFile.toAbsolutePath()}")
//            }
/*
            val aws = PythonWriter("aws.c", "aws", "Python interface for the test aws in C library")
            aws.writeFunc("static","PyObject *", "aws_crt_init", "Python interface for the C library")
            aws.writeFunc("static","PyObject *", "aws_crt_clean_up", "Python interface for the C library")
            aws.writeFunc("static","PyObject *", "aws_crt_test_error", "Python interface for the C library")
            aws.writeFunc("static","PyObject *", "aws_crt_mem_acquire", "Python interface for the C library")
            aws.writeFunc("static","PyObject *", "aws_crt_mem_release")

            aws.defModule(-1)
            aws.setupPy("1.0.0", "Benjamin Tu", "bnjamit@amazon.com")
*/
        } catch (ex: Throwable) {
            System.err.println(ex.message)
        }
    }
}
