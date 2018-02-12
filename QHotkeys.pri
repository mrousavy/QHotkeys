DEFINES += QHOTKEYS

HEADERS += \
    src/qhotkey.h \
    src/helper.h

msvc {
    SOURCES += src/qhotkey_win.cpp
    LIBS += -luser32
} else:linux {
    SOURCES += src/qhotkey_linux.cpp
} else:macx {
    SOURCES += src/qhotkey_osx.cpp
} else {
    SOURCES += src/qhotkey.cpp
}
