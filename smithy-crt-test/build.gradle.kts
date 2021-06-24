plugins {
    id("software.amazon.smithy").version("0.5.3")
}

dependencies {
    implementation(project(":smithy-crt"))
}

tasks.register<Copy>("copyToLib") {
    println(layout.projectDirectory)
    from(layout.buildDirectory.dir("smithyprojections/smithy-crt-test/apigateway/python-codegen"))
    into(layout.projectDirectory.dir("lib"))
}

tasks["jar"].enabled = false

tasks["build"].finalizedBy("copyToLib")