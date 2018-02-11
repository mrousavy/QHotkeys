#-------------------------------------------------
#
# Project created by QtCreator 2018-02-11T11:11:37
#
#-------------------------------------------------

QT       -= gui

TARGET = QHotkeys
TEMPLATE = lib
CONFIG += staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS \
     QHOTKEYS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


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

unix {
    target.path = /usr/lib
    INSTALLS += target
}
