
import org.jetbrains.kotlin.gradle.dsl.KotlinJvmCompile

description = "Generates Code from smithy model"

repositories {
    mavenLocal()
    mavenCentral()
}

plugins {
    kotlin("jvm")
}

tasks.named<KotlinJvmCompile>("compileKotlin") {
    kotlinOptions.jvmTarget = "1.8"
}

tasks.named<KotlinJvmCompile>("compileTestKotlin") {
    kotlinOptions.jvmTarget = "1.8"
}

dependencies {
    implementation("com.atlassian.commonmark:commonmark:0.14.0")
    implementation("org.jsoup:jsoup:1.13.1")
    implementation("software.amazon.smithy:smithy-codegen-core:[1.0.2,1.1.0[")
    implementation("software.amazon.smithy:smithy-protocol-test-traits:[1.0.2,1.1.0[")
    implementation("software.amazon.smithy:smithy-model:1.8.0")
    implementation("software.amazon.smithy:smithy-aws-traits:1.8.0")
}
