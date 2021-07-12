package software.amazon.smithy.crt.util

import software.amazon.smithy.crt.traits.CTypeTrait
import software.amazon.smithy.crt.traits.ConstTrait
import software.amazon.smithy.crt.traits.OpaqueTrait
import software.amazon.smithy.crt.traits.PointerTrait
import software.amazon.smithy.model.Model
import software.amazon.smithy.model.SourceLocation
import software.amazon.smithy.model.node.ExpectationNotMetException
import software.amazon.smithy.model.shapes.MemberShape
import software.amazon.smithy.model.shapes.StructureShape
import java.util.*

private fun getCTypeName(shape: MemberShape, model: Model): String {
    val str = StringJoiner(" ")

    if (shape.hasTrait(ConstTrait::class.java)) {
        str.add("const")
    }

    val trait = model.expectShape(shape.target).expectTrait(CTypeTrait::class.java)
    str.add(trait.value)

    // TODO: Should not both exist, try to see if can be enforced on model
    if (model.expectShape(shape.target).hasTrait(OpaqueTrait::class.java)) {
        str.add("*")
    } else if (shape.hasTrait(PointerTrait::class.java)) {
        val pointerTrait = shape.expectTrait(PointerTrait::class.java)
        if (pointerTrait.doublePointer.orElse(false)) {
            str.add("**")
        } else {
            str.add("*")
        }
    }

    return str.toString()
}

private fun getFields(struct: StructureShape, model: Model): List<String> {
    return struct.allMembers.toList().map{
        getCTypeName(it.second, model)
    }
}

fun getInputFields(struct: StructureShape, model: Model): List<String> {
    return getFields(struct, model)
}

fun getOutputFields(struct: StructureShape, model: Model): String? {
    val ret = getFields(struct, model)
    if (ret.size > 1) {
        throw ExpectationNotMetException("Output structures ${struct.id} should have at most 1 field", SourceLocation.NONE)
    }
    return ret.firstOrNull()
}