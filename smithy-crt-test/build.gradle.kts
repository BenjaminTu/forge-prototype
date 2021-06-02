plugins {
    id("software.amazon.smithy").version("0.5.3")
}

dependencies {
    implementation(project(":smithy-crt"))
}

tasks["jar"].enabled = false
