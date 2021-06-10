the smithy models are in: `./smithy-crt-test/model`

to generate code: `./gradlew :smithy-crt-test:build`

to run generated extension: ` python3 -m pip install . --verbose` (recommend using a virtual environment)

all the generated files are in `./smithy-crt-test/build/smithyprojections/smithy-crt-test/apigateway/python-codegen/`