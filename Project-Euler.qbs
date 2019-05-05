import qbs

CppApplication {
    consoleApplication: true
    files: [
        "src/c:c++/main.cpp",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
