plugins {
    id("software.amazon.smithy").version("0.5.3")
    `c`
}

dependencies {
    implementation(project(":smithy-crt"))
}

description = "JNI bindings for the AWS Common Runtime"
val srcDir = File("$rootDir")
val cmakeBuildDir = File(srcDir, "build")
var buildType = "RelWithDebInfo"

sourceSets {
    main {
        // include shared libraries built by cmake/CI/CD in the lib folder
        resources {
            srcDir("${buildDir}/cmake-build/lib")
        }
    }
}

val cmakeConfigure = tasks.register("cmakeConfigure") {
    var cmakeArgs = listOf(
        "-B${cmakeBuildDir}/cmake-build",
        "-H${srcDir}",
        "-DCMAKE_BUILD_TYPE=${buildType}",
        "-DCMAKE_INSTALL_PREFIX=${cmakeBuildDir}/cmake-build",
        "-DCMAKE_EXPORT_COMPILE_COMMANDS=ON",
        "-DBUILD_DEPS=ON",
        "-DBUILD_TESTING=OFF"
    )

    inputs.file("${srcDir.path}/CMakeLists.txt")
    outputs.file("${cmakeBuildDir}/cmake-build/CMakeCache.txt")

    doLast {
        val argsStr = cmakeArgs.joinToString(separator=" ")
        logger.info("cmake ${argsStr}")
        exec {
            executable("cmake")
            args(cmakeArgs)
            environment(mapOf<String, String>("JAVA_HOME" to System.getProperty("java.home")))
        }
    }
}

val cmakeBuild = tasks.register("cmakeBuild") {
    dependsOn(cmakeConfigure)
    inputs.file("${srcDir.path}/CMakeLists.txt")
    inputs.file("${cmakeBuildDir}/cmake-build/CMakeCache.txt")
    inputs.files(fileTree("${srcDir.path}").matching {
        include(listOf("**/*.c", "**/*.h"))
    })
    inputs.files(fileTree("${srcDir.path}/crt").matching {
        include(listOf("**/CMakeLists.txt", "**/*.c", "**/*.h"))
    })
    outputs.file("${cmakeBuildDir}/cmake-build/lib/libaws-crt-jni.so")
    outputs.upToDateWhen { false }  //shared lib doesn't seem to get placed in jar without this

    var cmakeArgs = listOf(
        "--build", "${cmakeBuildDir}/cmake-build",
        "--target", "all"
    )

    doLast {
        val argsStr = cmakeArgs.joinToString(separator=" ")
        logger.info("cmake $argsStr")
        exec {
            executable("cmake")
            args(cmakeArgs)
        }
    }
}

val copyToPythonLib = tasks.register<Copy>("copyToPythonLib") {
    from(layout.buildDirectory.dir("smithyprojections/smithy-crt-test/apigateway/python-codegen"))
    into(layout.projectDirectory.dir("pythonlib"))
}

val copyToJavaLib = tasks.register<Copy>("copyToJavaLib") {
    dependsOn("build")
    from(layout.buildDirectory.dir("smithyprojections/smithy-crt-test/apigateway/java-codegen"))
    into(layout.projectDirectory.dir("javalib"))
}

val copyJavaLib = tasks.register<Copy>("copyJavaLib") {
    dependsOn(cmakeBuild)
    from("$rootDir/build/cmake-build/lib/libaws-crt-jni.dylib")
    into("$rootDir/test/java")
}

tasks.register("java") {
    dependsOn(copyToJavaLib, copyJavaLib)
}

tasks.register("python") {
    dependsOn("build")
    dependsOn(copyToPythonLib)
}

tasks["jar"].enabled = false

tasks["build"].finalizedBy("copyToPythonLib", "copyToJavaLib")



