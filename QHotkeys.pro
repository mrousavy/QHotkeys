QT -= gui

TARGET = QHotkeys
TEMPLATE = lib
CONFIG += staticlib

DEFINES += QT_DEPRECATED_WARNINGS

# If compiling .dll (shared library):
# DEFINES += QHOTKEYS_SHAREDLIB
# DEFINES += QHOTKEYS_EXPORT

HEADERS += \
    src/qhotkey.h \
    src/helper.h

msvc {
    SOURCES += src/qhotkey_win.cpp
    LIBS += -luser32
} else:linux {
    SOURCES += src/qhotkey_linux.cpp
} else:mingw {
    SOURCES += src/qhotkey_linux.cpp
} else:macx {
    SOURCES += src/qhotkey_osx.cpp
} else {
    SOURCES += src/qhotkey.cpp
}
