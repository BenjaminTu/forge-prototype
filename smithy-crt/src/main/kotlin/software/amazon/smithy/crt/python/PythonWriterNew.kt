package software.amazon.smithy.crt.python;

import software.amazon.smithy.model.Model
import software.amazon.smithy.model.node.StringNode
import software.amazon.smithy.model.shapes.Shape
import software.amazon.smithy.model.shapes.ShapeId
import software.amazon.smithy.model.shapes.StructureShape
import software.amazon.smithy.model.traits.Trait
import java.lang.StringBuilder

const val CTYPE_TRAIT = "com.aws.ffi#ctype"
const val POINTER_TRAIT = "com.aws.ffi#pointer"
const val CONST_TRAIT = "com.aws.ffi#const"
const val OPAQUE_TRAIT = "com.aws.ffi#opaque"

val varMap = mapOf(
    "const char *" to "s",
)

class PythonWriterNew (model: Model) {
    private val model: Model = model

    private fun getCTypeName(id: ShapeId): String {
        val cTypeTrait = model.expectShape(id).findTrait(CTYPE_TRAIT).orNull()
        var res = cTypeTrait?.toNode()?.expectObjectNode()?.expectStringMember("typename").toString()

        val opaqueTrait = model.expectShape(id).findTrait(OPAQUE_TRAIT).orNull()
        return if (opaqueTrait != null) "$res *" else res
    }

    /**
     * Get structure's(input/output) fields
     *
     * @param struct StructureShape to analyze
     * @return Returns the Ids of the field as a List of ShapeId
     */

    private fun getFields(struct: StructureShape): List<String> {
        return struct.allMembers.toList().map{
            var str = StringBuilder()
            if (it.second.hasTrait(CONST_TRAIT)) {
                str.append("const ")
            }
            str.append(getCTypeName(it.second.target))
            if (it.second.hasTrait(POINTER_TRAIT)) {
                str.append(" *")
            }

            str.toString()
        }
    }

    fun execute() {
        // for each method
        val operations = model.operationShapes
        operations.forEach {
            var modelName = it
            var input = model.expectShape(it.input.orNull()) as StructureShape
            var output = model.expectShape(it.output.orNull()) as StructureShape

            println("method: ${modelName.id}")

            println("input: ${input.id}")
            val inputFields = getFields(input)

            println(inputFields)
            println("output: ${output.id}")
            val outputFields = getFields(output)
            println(outputFields)

            println()
        }
    }

//fun formatMethod(List<String>) {
//    //        struct.expectTrait()
//    var field = it.value
//    val ctype = field.findTrait(CTYPE_TRAIT).orNull()
//    println(ctype)
//    if (ctype != null) {
//        println("lsdfnafnofin;oisfnsofnwefnwfn")
//        println(getCTypeName(ctype))
//    }
//}
}