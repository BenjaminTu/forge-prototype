package software.amazon.smithy.crt.traits;

import software.amazon.smithy.model.node.ObjectNode;
import software.amazon.smithy.model.shapes.ShapeId;
import software.amazon.smithy.model.traits.AnnotationTrait;

public final class ConstTrait extends AnnotationTrait {
    public static final ShapeId ID = ShapeId.from("com.aws.ffi#const");

    public ConstTrait(ObjectNode node) {
        super(ID, node);
    }

    public static final class Provider extends AnnotationTrait.Provider<ConstTrait> {
        public Provider() {
            super(ID, ConstTrait::new);
        }
    }
}