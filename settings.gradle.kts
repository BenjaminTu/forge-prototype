/*
 * This file was generated by the Gradle 'init' task.
 *
 * The settings file is used to specify which projects to include in your build.
 *
 * Detailed information about configuring a multi-project build in Gradle can be found
 * in the user manual at https://docs.gradle.org/6.8/userguide/multi_project_builds.html
 */

rootProject.name = "language_binding_toy"

pluginManagement {
    repositories {
        maven("https://dl.bintray.com/kotlin/kotlin-eap")
        mavenCentral()
        maven("https://plugins.gradle.org/m2/")
        google()
        gradlePluginPortal()
    }
}

include(":smithy-crt")
include(":smithy-crt-test")