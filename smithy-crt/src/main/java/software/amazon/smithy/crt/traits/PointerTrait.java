package software.amazon.smithy.crt.traits;

import java.util.Optional;

import software.amazon.smithy.model.node.Node;
import software.amazon.smithy.model.node.ObjectNode;
import software.amazon.smithy.model.shapes.ShapeId;
import software.amazon.smithy.model.traits.AbstractTraitBuilder;
import software.amazon.smithy.model.traits.TraitService;
import software.amazon.smithy.utils.MapUtils;
import software.amazon.smithy.utils.ToSmithyBuilder;
import software.amazon.smithy.model.traits.AbstractTrait;

/**
 * Constrains a shape to minimum and maximum number of elements or size.
 */
public final class PointerTrait extends AbstractTrait implements ToSmithyBuilder<PointerTrait> {
    public static final ShapeId ID = ShapeId.from("com.aws.ffi#pointer");

    private final Boolean doublePointer;

    private PointerTrait(Builder builder) {
        super(ID, builder.getSourceLocation());
        this.doublePointer = builder.doublePointer;
    }

    public Optional<Boolean> getDoublePointer() {
        return Optional.ofNullable(doublePointer);
    }

    @Override
    protected Node createNode() {
        return new ObjectNode(MapUtils.of(), getSourceLocation())
                .withOptionalMember("doublePointer", getDoublePointer().map(Node::from));
    }

    @Override
    public Builder toBuilder() {
        return builder().doublePointer(doublePointer).sourceLocation(getSourceLocation());
    }

    /**
     * @return Returns a builder used to create a pointer trait.
     */
    public static Builder builder() {
        return new Builder();
    }

    /**
     * Builder used to create a PointerTrait.
     */
    public static final class Builder extends AbstractTraitBuilder<PointerTrait, Builder> {
        private Boolean doublePointer;

        public Builder doublePointer(Boolean doublePointer) {
            this.doublePointer = doublePointer;
            return this;
        }

        @Override
        public PointerTrait build() {
            return new PointerTrait(this);
        }
    }

    public static final class Provider implements TraitService {
        @Override
        public ShapeId getShapeId() {
            return ID;
        }

        @Override
        public PointerTrait createTrait(ShapeId target, Node value) {
            ObjectNode objectNode = value.expectObjectNode();
            Boolean doublePointerValue = objectNode.getMember("doublePointer")
                    .map(v -> v.expectBooleanNode().getValue()).orElse(null);
            return builder().sourceLocation(value).doublePointer(doublePointerValue).build();
        }
    }
}