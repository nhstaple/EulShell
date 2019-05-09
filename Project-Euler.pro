TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/cpp/library/App/Parser/EulerInterface/EulerInterface.cpp \
    src/cpp/library/App/Parser/Parser.cpp \
    src/cpp/library/App/App.cpp \
    src/cpp/library/App/AppSetup.cpp \
    src/cpp/library/Graphs/DataItem.cpp \
    src/cpp/main.cpp \
    src/cpp/library/Graphs/Node.cpp \
    src/cpp/library/App/Parser/ParserObject.cpp \
    src/cpp/euler/e001/e001.cpp \
    src/cpp/library/App/cd.cpp \
    src/cpp/library/App/ls.cpp \
    src/cpp/library/App/pwd.cpp \
    src/cpp/library/App/read.cpp

HEADERS += \
    src/cpp/euler/001/e001.h \
    src/cpp/euler/Euler.h \
    src/cpp/library/App/Parser/EulerInterface/EulerInterface.h \
    src/cpp/library/App/Parser/EulerInterface/InterfaceAtom.h \
    src/cpp/library/App/Parser/Parser.h \
    src/cpp/library/App/Parser/ParserObject.h \
    src/cpp/library/App/App.h \
    src/cpp/library/App/AppObject.h \
    src/cpp/library/Utility/Typedata.h \
    src/cpp/library/Graphs/DataItem.h \
    src/cpp/library/Graphs/Node.h \
    src/cpp/library/App/Parser/Termcolor.h

DISTFILES += \
    src/cpp/Makefile
