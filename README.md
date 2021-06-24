the smithy models are in: `./smithy-crt-test/model`

to generate code: `./gradlew :smithy-crt-test:build`

to run generated extension: ` python3 -m pip install . --verbose` (recommend using a virtual environment)

all the library files for the extension are in `./smithy-crt-test/lib/`

`aws.c` is generated and copied into the library

The extensions are `aws` and `input_stream_py`