package software.amazon.smithy.crt.traits;

import software.amazon.smithy.model.SourceLocation;
import software.amazon.smithy.model.shapes.ShapeId;
import software.amazon.smithy.model.traits.StringTrait;

public final class CTypeTrait extends StringTrait {
    public static final ShapeId ID = ShapeId.from("com.aws.ffi#ctype");

    public CTypeTrait(String value, SourceLocation sourceLocation) {
        super(ID, value, sourceLocation);
    }

    public static final class Provider extends StringTrait.Provider<CTypeTrait> {
        public Provider() {
            super(ID, CTypeTrait::new);
        }
    }
}