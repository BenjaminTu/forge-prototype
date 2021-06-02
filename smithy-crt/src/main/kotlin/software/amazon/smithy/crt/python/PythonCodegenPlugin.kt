
package software.amazon.smithy.crt.python;

import software.amazon.smithy.build.PluginContext;
import software.amazon.smithy.build.SmithyBuildPlugin;
import java.util.logging.Level

import java.util.logging.Logger;

class PythonCodegenPlugin : SmithyBuildPlugin {
    private val LOG = Logger.getLogger(PythonCodegenPlugin::class.simpleName);

    override fun getName(): String {
        return "python-codegen"
    }

    override fun execute(pluginContext: PluginContext) {
        val root = Logger.getLogger("")
        root.level = Level.ALL
        root.handlers.forEach {
            it.level = Level.ALL
        }
        LOG.warning("Running PythonCodegenPlugin...");

        try {
            val aws = PythonWriter("aws.c", "aws", "Python interface for the test aws in C library")
            aws.writeFunc("static","PyObject *", "aws_crt_init", "Python interface for the C library")
            aws.writeFunc("static","PyObject *", "aws_crt_clean_up", "Python interface for the C library")
            aws.writeFunc("static","PyObject *", "aws_crt_test_error", "Python interface for the C library")
            aws.writeFunc("static","PyObject *", "aws_crt_mem_acquire", "Python interface for the C library")
            aws.writeFunc("static","PyObject *", "aws_crt_mem_release")

            aws.defModule(-1)
            aws.setupPy("1.0.0", "Benjamin Tu", "bnjamit@amazon.com")

        } catch (ex: Throwable) {
            System.err.println(ex.message)
        }
    }
}
