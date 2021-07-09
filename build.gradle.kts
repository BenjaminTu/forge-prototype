/*
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

plugins {
    `java-library`
    kotlin("jvm") version "1.4.20" apply false
}

buildscript {
    repositories {
        google()
        jcenter()
    }

    dependencies {
        classpath("org.jetbrains.kotlin:kotlin-gradle-plugin:1.4.20")
    }
}

group = "software.amazon.awssdk.crt"
version = "1.0.0-SNAPSHOT"
description = "software.amazon.awssdk.crt:aws-crt"

sourceSets {
    main {
        java {
            setSrcDirs(listOf("smithy-crt-test/javalib"))
        }
        // include shared libraries built by cmake/CI/CD in the lib folder
        resources {
            srcDir("${buildDir}/cmake-build/lib")
        }
    }
}

java {
    withJavadocJar()
    withSourcesJar()
    sourceCompatibility = JavaVersion.VERSION_1_8
    targetCompatibility = JavaVersion.VERSION_1_8
}

tasks.compileJava {
    dependsOn(":smithy-crt-test:cmakeBuild")
}

allprojects {
    repositories {
        mavenLocal()
        mavenCentral()
        jcenter()
        google()
    }
}














