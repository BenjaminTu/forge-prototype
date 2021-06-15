package software.amazon.smithy.crt.traits;

import software.amazon.smithy.model.node.Node;
import software.amazon.smithy.model.node.ObjectNode;
import software.amazon.smithy.model.shapes.ShapeId;
import software.amazon.smithy.model.traits.AnnotationTrait;

public final class OpaqueTrait extends AnnotationTrait {
    public static final ShapeId ID = ShapeId.from("com.aws.ffi#opaque");

    public OpaqueTrait(ObjectNode node) {
        super(ID, node);
    }

    public static final class Provider extends AnnotationTrait.Provider<OpaqueTrait> {
        public Provider() {
            super(ID, OpaqueTrait::new);
        }
    }
}