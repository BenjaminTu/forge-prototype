# Early Exploration into AWS Forge

This is a document of what Benjamin has done over his internship during summer 2021
Everything can be found here: https://github.com/BenjaminTu/forge-prototype

## Overview & Goal

SEATTLE September 2022. Amazon Web Services Inc. releases Forge, an Open Source suite of tools for allowing inter-operation between programming languages. Forge allows developers to write code in any language they can build to a shared library (e.g. C, C++, Rust), then use it in any supported language (e.g. Python, .NET, Java, etc) as an extension. Forge is built on the AWS Common Runtime’s extensive knowledge of building high performance language interop, and produces the lowest overhead language bindings possible in each target language.

The goal of Benjamin’s internship was to explore and document the process of what Forge would be like potentially by modeling, implementing and generating.

## Architectural change

[Image: Current architecture of AWS SDKs](https://github.com/BenjaminTu/forge-prototype/blob/master/cur-arch.png?raw=true)Current architecture of AWS SDKs

[Image: AWS SDK's architecture with Forge](https://github.com/BenjaminTu/forge-prototype/blob/master/forge-arch.png?raw=true)AWS SDK's architecture with Forge

With Forge, the SDK libraries are abstracted with [aws-crt-ffi](https://github.com/awslabs/aws-crt-ffi/), and along with the API model described in AWS Smithy, we can generate the necessary language bindings for each of the targeted language SDKs.

All the API exposed by `aws-crt-ffi` can be found [here](https://github.com/awslabs/aws-crt-ffi/blob/main/src/api.h)

## Project Structure

```c
.
├── CMakeLists.txt                   // Cmake for creating java libraries
├── README.md                        // README
├── aws-crt-ffi                      // FFI submodule
├── example                          // playground for simple language bindings
│             ├── java
│             └── python
├── gradlew                          // gradle wrapper
├── gradlew.bat
├── setup.py                         // setup script for python dependencies
├── smithy-crt                       // project of code generators
│             └── src
│                 └── main
│                     ├── java           // smithy traits
│                     ├── kotlin         // code generators
│                     └── resources      // smithy plugins/trait services
├── smithy-crt-test                  // project invoking codegen on mode
│             ├── javalib                // library for java bindings
│             ├── model                  // smithy models
│             ├── pythonlib              // library for python bindings
│             └── smithy-build.json      // codegen plugins
└── test                             // binding tests
    ├── java
    └── python
```

### Project Flow

Understanding the project flow helped me how to pinpoint where to look and modify when adding new functionalities.
The smithy code generation is executed as the following

1. code generators are defined in `smithy-crt`
2. `smithy-crt-test` invokes the code generators in `smithy-crt` and the models in the `model` directory are the “tests” for the generators.(in other words, it will consume the given model and code gen!), the generated files will be in `smithy-crt-test/build/smithyprojections/smithy-crt-test/apigateway/java-codegen`, though it will already be copied to our library directories by our gradle tasks
3. add your new smithy plugins into the resource folder in `smithy-crt` and `smithy-build.json` in `smith-crt-test`
4. `XXXCodegenPlugin` will be invoked and that is your code generation entry point:
   ```kotlin
   // generate a file
   gen.useFileWriter("AWS.java") {
      // pass model into custom writer   
      JavaMethodWriter(it, pluginContext.model).execute()
   }

   // generate files
   gen.flushWriters()
   ```
### Tasks

The project tasks can be split into two: code generation and library compilation.

Code generation is done via `:smithy-crt-test:build`  and both java and python code generator(in `smithy-crt`) is being invoked.

Library compilation is done with build as well, but we can specify `:smithy-crt-test:java` or `:smithy-crt-test:python` to compile/install the dependencies

The task that compiles the dependencies for java is `cmakeConfigure` and `cmakeBuild`
The tasks that finalizes the dependencies for java is: `copyToJavaLib` and `copyJavaLib` , which the former copies the code generation into our `javalib` and the latter copies the compiled jar file into our test directory for out `Test.java` to use. (remember to `javac AWS.java` before running `Test.java`)

The task `copyToPythonLib` copies the code generation into `pythonlib`. And to setup the library for python, the user would need to run `setup.py` on their own(using `python3 -m pip install . --verbose`)

## Smithy Modeling

To avoid tedious modeling and parsing, we use [AWS Smithy](https://awslabs.github.io/smithy/). With Smithy, we were able to model our API from `aws-crt-ffi` with the following:

### Traits

There are currently 4 kinds of trait:

* `ctype`: a descriptor of a c type name
* `opaque`:  an abstracted struct that the field is unknown
* `pointer(boolean doublePointer)`: indicates that a field is a pointer(only on primitives). There is an optional boolean that indicates the field is a double pointer, but that is discouraged and should require more thoughts before defining an api that uses double pointer
* `const`: indicates that the field is a const

Process of adding a custom trait:

1. Head over to `smithy-crt/src/main/java/software/amazon/smithy/crt/traits `and define your custom trait
2. Add the trait following the format to here: `smithy-crt/src/main/resources/META-INF/services/software.amazon.smithy.model.traits.TraitService`
3. lastly define the trait in `smithy-crt-test/model/traits.smithy`, note that different Trait classes requires different structures when defined.

For customizing your own trait visit AWS Smithy for more details

### Format

Currently the format of the API model is defined as the follow:
Let’s take `aws_crt_credentials_options_set_access_key_id` as an example

```c
AWS_CRT_API void aws_crt_credentials_options_set_access_key_id(
    aws_crt_credentials_options *options,
    const uint8_t *access_key_id,
    size_t access_key_id_length);
```

We would define the input/output structure for the method we want to model.
In this case we have three parameters: `aws_crt_credentials_options *options`, `const uint8_t *access_key_id` and `size_t access_key_id_length`

since the type `aws_crt_credentials_options` is opaque in the API, even though the input takes a pointer, the only way to access an opaque struct is a pointer anyways, we would not need the `pointer` trait on our input field.

the second parameter is a `const uint8_t`, so we would indicate that the field is of type `uint8_t` and attach a `const` and pointer `trait`

the third parameter is merely a `size_t` so, quite straight forward

Note that the output is void, so we can just put void as the output structure, this is how my generator is parsing the fields.
However, it is totally ok to define an output structure where there are no fields, given that your code generator is aware of that.

Lastly, the method name is to be put as the operation name, with the input/output structure

```
structure aws_crt_credentials_options_set_access_key_id_input {
    options: aws_crt_credentials_options,
    @const
    @pointer
    access_key_id: uint8_t,
    access_key_id_length: size_t
}

operation aws_crt_credentials_options_set_access_key_id {
    input: aws_crt_credentials_options_set_access_key_id_input,
    output: void
}
```

### Adding a new method

Due to the nature of smithy modeling and this project, adding a new method to the api and thus generate bindings for them is a breeze. Just add a method into the modeling file via the provided format(or your own if you are using your own generator), and build. Voila, you have your bindings now.

### Smithy modeling automation

Some efforts have been done to explore the possibility of this, but modeling automation is not in the scope of the internship. But it is definitely valuable to have this, as the modeling process is quite tedious.

## Code Generator

### Binding Structures

A lot of the language bindings are simple enough to be broken down into similar pieces:

* Parse inputs
* Function Call
* Return types accordingly

The tricky part that requires handling, at least what I encountered, is pointers and strings(byte buffers).
Described in each language section below

### Python

The first language that was targeted to be experimented is Python.
Python and C extensions have been very well documented and already in use in a lot of public libraries such as OpenCV.
First we would need to declare an extension method that binds to the python method, take `aws_crt_mem_release` as an example:

```c
static PyObject *method_aws_crt_mem_release(PyObject *self, PyObject *args) {
    // avoid unused variable warning
    (void)self;
    (void)args;
    
    PyObject *a;
    
    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &a)) {
        printf("method_aws_crt_mem_release parsing error\n");
        return NULL;
    }
    // parse input pointer object
    void * b;
    b = (void *) PyCapsule_GetPointer(a, "void *");
    
    // function call
    aws_crt_mem_release(b);
    
    // return type
    Py_RETURN_NONE;
}
```

then we can add the method to our method lists and add that to our module

```c
static PyMethodDef aws_methods[] = {
    ...
    {"aws_crt_mem_release", method_aws_crt_mem_release, METH_VARARGS, ""},
    ...
}

static struct PyModuleDef aws_module = {
    PyModuleDef_HEAD_INIT,
    "aws",
    "",
    -1,
    aws_methods,
    ...
};

PyMODINIT_FUNC PyInit_aws(void) {
    return PyModule_Create(&aws_module);
}
```

Strings are handled differently in every language, especially between C and other languages like the ones targeted here.
Python uses PyBuffer to encapsulate a byte array and requires the extension to release it before returning.

```c
Py_buffer b;
// parse input
const uint8_t * e = (const uint8_t *) b.buf;
// function call
PyBuffer_Release(&b);
```

Often times, high level languages does not expose the idea of pointers to end users, as so in Python and Java.
That means we need a way to pass pointers between C and our targeted language.
In Python, we used the PyCapsule Library to encapsulate a pointer for both input and output:

```c
const aws_crt_event_loop_group_options * b;
b = (const aws_crt_event_loop_group_options *) PyCapsule_GetPointer(a, "aws_crt_event_loop_group_options *");
PyObject *ret = PyCapsule_New((void *)aws_crt_event_loop_group_new(b), "aws_crt_event_loop_group *", NULL);
return (ret);
```

### Java

The second language we targeted was Java utilizing the JNI interface.
In Java, language extensions interfaces with Java Native Interface(JNI) and the structure is quite similar with Python’s.
Take `awsCrtCredentialsAcquire` as an example:

```c
JNIEXPORT jobject JNICALL Java_AWS_awsCrtCredentialsAcquire(JNIEnv *env, jobject obj, jobject a) { // argument types are generated(parse input)
    // avoid unused variable warning
    (void)env;
    (void)obj;
    
    // parse input pointer object
    aws_crt_credentials * b = (aws_crt_credentials *) ((*env)->GetLongField(env, a, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, a), "address", "J")));
  
    // function call
    aws_crt_credentials * ret = aws_crt_credentials_acquire(b);
    
    // return pointer object
    jclass cls = (*env)->FindClass(env, "AWS$Pointer");
    jmethodID constructor = (*env)->GetMethodID(env, cls, "<init>", "(LAWS;J)V");
    // since it's a inner class, we need to pass in the outer class obj as well
    return (*env)->NewObject(env, cls, constructor, obj, (long)ret);
}
```

In Java, since we want to pass in raw bytes into the extension for http methods, I mapped byte arrays to be the data type for JNI. We would need to extra the buffer from the array and then we can just use it as a byte pointer to pass into the FFI API.

```c
jbyteArray b = ...
const uint8_t * e = (const uint8_t *) (*env)->GetByteArrayElements(env, b, 0);
```

For pointers, I decided to use a wrapper class that encapsulated the pointer address and pass them around as Pointer objects which contains the address as long.

```java
private class Pointer {
    private long address;
    public Pointer(long addr) {
        address = addr;
    }
}
```

Some function declaration in Java, note that we return a pointer object here

```java
public native Pointer awsCrtHttpHeadersNewFromBlob(byte[] blob, int blob_length);
```

Some handling we need to do for returning a Pointer

```c
aws_crt_http_headers * ret = aws_crt_http_headers_new_from_blob(c, b);
jclass cls = (*env)->FindClass(env, "AWS$Pointer");
jmethodID constructor = (*env)->GetMethodID(env, cls, "<init>", "(LAWS;J)V");
// since Pointer is an inner class, we need to pass in the outter class obj as well
return (*env)->NewObject(env, cls, constructor, obj, (long)ret);
```


P.S. it’s slower to wrap the address in a class as shown in the java example rather than passing the address as a long. And please for the love of god, do not use subclasses in JNI, it’s hard to debug and get the format right(in my case, Pointer is a inner class of AWS). And if you need to find the method signature, you can use `javap -s -p AWS` to get the method signature of any methods

## Injecting Handwritten code

Sometimes code generation is not enough, or the binding code is just too complex to even generate. In these cases, which I’ve encountered, you can handwrite code like the old way.

In my case, I had to deal with `aws_input_stream` that has the functionality of setting callback functions. In brief, I would need to pass my Python function to the C layer and have C callback my python function. The complexity here does not follow our wrapper structure mentioned above. Therefore having a generator for this would be silly.

The way to implement such functionality it is creating our own vtable structure and pre-map our callback function, then set our callback function in the pre-mapped function.

Don’t worry about the details of that because I hope no one has to deal with this ever again. The important thing is to inject handwritten code. Currently, we just hardcode our handwritten code into the generated files (via the generator) and compile them as one library, for example:

```c
// hand written methods from other files
extern PyObject *method_aws_crt_new_buf(PyObject *, PyObject *);
extern PyObject *method_aws_crt_input_stream_options_new(PyObject *, PyObject *);
extern PyObject *method_aws_crt_input_stream_options_set_seek(PyObject *, PyObject *);
...
static PyMethodDef aws_methods[] = {
   ...
   // generated from model
    {"aws_crt_credentials_options_set_expiration_timepoint_seconds", method_aws_crt_credentials_options_set_expiration_timepoint_seconds, METH_VARARGS, ""},
   // handwritten methods
    {"aws_crt_new_buf", method_aws_crt_new_buf, METH_VARARGS, ""},
    {"test_io", method_test_io, METH_VARARGS, ""},
    {"test_http", method_test_http, METH_VARARGS, ""},
   ...
```

More robust ways can definitely be used such as using a setup script to separate handwritten and generated methods along with header files, but the focus of the internship was a concept of proof rather than a well-structured project.

## TLDR; Quick Guide to Run

- the smithy models are in: `./smithy-crt-test/model`
- to generate code: `./gradlew :smithy-crt-test:build`
- to copy/install dependencies for testing: `./gradlew :smithy-crt-test:python`, `./gradlew :smithy-crt-test:java`


- to install generated python extension: ` python3 -m pip install . --verbose` (recommend using a virtual environment)
to use generated java extension: make sure your current directory is in `test/java` or add `test/java` to your java library path to load `lib-aws-jni.dylib`


- all the library files(both generated and handwritten) for the extension are in `./smithy-crt-test/pythonlib/`, `./smithy-crt-test/javalib/`refer to the test files to see how the bindings are used.

## Acknowledgments

Special thanks to Justin for the major helping/overlooking this project.
Thanks to Misha, Michael, Itamar and the CRT team for helping out when I’m stuck
Thanks to AWS for this internship?
