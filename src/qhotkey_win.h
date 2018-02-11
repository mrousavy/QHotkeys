#ifndef QHOTKEY_WIN_H
#define QHOTKEY_WIN_H
#include "qhotkey.h"
#include "helper.h"
#include <Windows.h>

struct Qt::QHotkey::PlatformData
{
    // TODO: PLATFORMDATA
};

Qt::QHotkey::~QHotkey()
{
    UnregisterHotKey(NULL, _hkid);
}

void Qt::QHotkey::registerHotkey()
{
    qDebug() << _registered;
    if (_registered)
        throw std::runtime_error("This QHotkey instance is already registered!");

    auto result = RegisterHotKey(NULL, _hkid, getMod(_modifiers), getKey(_key));
    if (result == FALSE)
        throw std::runtime_error("Could not register hotkey! #" + GetLastError());

    _registered = result == 0;
    messageLoop();
}

void Qt::QHotkey::messageLoop() const
{
    MSG msg;
    while (GetMessage(&msg, NULL, NULL, NULL)) {
        if (msg.message == WM_HOTKEY &&
            msg.wParam == _hkid) {
            if (msg.wParam == _hkid) {
                _callback(*this);
            }
        }
    }
}

#endif // QHOTKEY_WIN_H
