#ifndef QHOTKEY_LINUX_H
#define QHOTKEY_LINUX_H
#include <QtCore>

#ifdef Q_OS_LINUX
#include "qhotkey.h"
#include "helper.h"
#include <X11>

int Qt::QHotkey::_ghkid = 0;
struct Qt::QHotkey::PlatformData
{
    int _thrId;
    // TODO: PLATFORMDATA
};

Qt::QHotkey::QHotkey(const Qt::Key hotkeys)
    : _keys(hotkeys), _hkid(_ghkid++),
      _loop(&Qt::QHotkey::registerHotkey, this),
      _registered(false), _pData(new PlatformData)
{}

Qt::QHotkey::~QHotkey()
{
    // TODO: LINUX IMPLEMENTATION
    int XUngrabKey(Display *display, int keycode, unsigned int
                modifiers, Window grab_window);
}

void Qt::QHotkey::registerHotkey()
{
    qDebug() << _registered;
    if (_registered)
        throw std::runtime_error("This QHotkey instance is already registered!");

    // TODO: LINUX IMPLEMENTATION
    int XGrabKey(Display *display, int keycode, unsigned int
                 modifiers, Window grab_window, Bool owner_events, int pointer_mode, int keyboard_mode);
    _registered = result == 0;
    messageLoop();
}

void Qt::QHotkey::messageLoop() const
{
    // TODO: LINUX IMPLEMENTATION
}
#endif // Q_OS_LINUX

#endif // QHOTKEY_LINUX_H
