the smithy models are in: `./smithy-crt-test/model`

to generate code: `./gradlew :smithy-crt-test:build`

to copy/install dependencies for testing: `./gradlew :smithy-crt-test:python`, `./gradlew :smithy-crt-test:java`

- to install generated python extension: ` python3 -m pip install . --verbose` (recommend using a virtual environment)
- to use generated java extension: make sure your current directory is in `test/java` or add `test/java` to your java libray path to load `lib-aws-jni.dylib`

all the library files(both generated and handwritten) for the extension are in `./smithy-crt-test/pythonlib/`, `./smithy-crt-test/javalib/`

refer to the test files to see how the bindings are used.