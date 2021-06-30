
package software.amazon.smithy.crt.java

import software.amazon.smithy.build.PluginContext
import software.amazon.smithy.build.SmithyBuildPlugin
import software.amazon.smithy.codegen.core.writer.CodegenWriterDelegator
import software.amazon.smithy.crt.util.MyWriter
import software.amazon.smithy.crt.util.MyWriterFactory
import java.util.logging.Level
import java.util.logging.Logger

class JavaCodegenPlugin : SmithyBuildPlugin {
    private val LOG = Logger.getLogger(JavaCodegenPlugin::class.simpleName)

    override fun getName(): String {
        return "python-codegen"
    }

    override fun execute(pluginContext: PluginContext) {
        val root = Logger.getLogger("")
        root.level = Level.ALL
        root.handlers.forEach {
            it.level = Level.ALL
        }
        LOG.warning("Running JavaCodegenPlugin...")

        try {
            val gen = CodegenWriterDelegator<MyWriter>(
                pluginContext.fileManifest,
                null,
                MyWriterFactory()
            )

            gen.useFileWriter("aws_java.c") {
                JavaWriter(it, pluginContext.model).execute()
            }

            // generate
            gen.flushWriters()

        } catch (ex: Throwable) {
            System.err.println(ex.message)
        }
    }
}
