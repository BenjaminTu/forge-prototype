
package software.amazon.smithy.crt.traits.python

import software.amazon.smithy.build.PluginContext
import software.amazon.smithy.build.SmithyBuildPlugin
import software.amazon.smithy.codegen.core.writer.CodegenWriterDelegator
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
            val gen = CodegenWriterDelegator<MyWriter>(
                pluginContext.fileManifest,
                null,
                MyWriterFactory()
            )

            gen.useFileWriter("aws.c") {
                PythonWriter(it, pluginContext.model).execute()
            }

            // generate
            gen.flushWriters()

        } catch (ex: Throwable) {
            System.err.println(ex.message)
        }
    }
}
