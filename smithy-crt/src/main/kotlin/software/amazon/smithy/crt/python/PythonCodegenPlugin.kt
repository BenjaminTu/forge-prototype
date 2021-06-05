
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
            val writer = PythonWriterNew(model)
            writer.execute()

//            it.accept(pluginContext.fileManifest.baseDir) { pythonFile ->
//                pluginContext.fileManifest.addFile(pythonFile)
//                LOG.info("Generated ${pythonFile.toAbsolutePath()}")
//            }

        } catch (ex: Throwable) {
            System.err.println(ex.message)
        }
    }
}
