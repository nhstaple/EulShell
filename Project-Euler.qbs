import qbs

CppApplication {
    consoleApplication: true
    files: [
        "src/cpp/library/Graphs/Typedata.h",
        "src/cpp/library/Graphs/dataitem.h",
        "src/cpp/library/Graphs/node.cpp",
        "src/cpp/library/Graphs/node.h",
        "src/cpp/main.cpp",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
