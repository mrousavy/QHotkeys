DEFINES += QHOTKEYS

HEADERS += \
    $$PWD/src/qhotkey.h \
    $$PWD/src/helper.h

msvc {
    SOURCES += $$PWD/src/qhotkey_win.cpp
    LIBS += -luser32
} else:linux {
    SOURCES += $$PWD/src/qhotkey_linux.cpp
} else:macx {
    SOURCES += $$PWD/src/qhotkey_osx.cpp
} else {
    SOURCES += $$PWD/src/qhotkey.cpp
}
