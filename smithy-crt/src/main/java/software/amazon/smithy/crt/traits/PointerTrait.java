package software.amazon.smithy.crt.traits;

import software.amazon.smithy.model.node.Node;
import software.amazon.smithy.model.node.ObjectNode;
import software.amazon.smithy.model.shapes.ShapeId;
import software.amazon.smithy.model.traits.AnnotationTrait;

public final class PointerTrait extends AnnotationTrait {
    public static final ShapeId ID = ShapeId.from("com.aws.ffi#pointer");

    public PointerTrait(ObjectNode node) {
        super(ID, node);
    }

    public PointerTrait() {
        this(Node.objectNode());
    }

    public static final class Provider extends AnnotationTrait.Provider<PointerTrait> {
        public Provider() {
            super(ID, PointerTrait::new);
        }
    }
}