import qbs

CppApplication {
    consoleApplication: true
    files: [
        "src/cpp/library/App/Parser/EulerInterface/EulerInterface.cpp",
        "src/cpp/library/App/Parser/EulerInterface/EulerInterface.h",
        "src/cpp/library/Graphs/DataItem.h",
        "src/cpp/library/Graphs/Node.cpp",
        "src/cpp/library/Graphs/Node.h",
        "src/cpp/library/Utility/Typedata.h",
        "src/cpp/main.cpp",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
