#ifndef QHOTKEY_WIN_H
#define QHOTKEY_WIN_H
#include <QtCore>

#ifdef Q_OS_WIN
#include "qhotkey.h"
#include "helper.h"
#include <Windows.h>

int Qt::QHotkey::_ghkid = 0;
struct Qt::QHotkey::PlatformData
{
    int thrId;
    UINT wmId;
};

Qt::QHotkey::QHotkey(const Qt::ModifierKey modifiers, const Qt::Key key)
    : _modifiers(modifiers), _key(key),
      _hkid(_ghkid++), _registered(false),
      _loop(&Qt::QHotkey::registerHotkey, this),
      _pData(new PlatformData)
{}

Qt::QHotkey::~QHotkey()
{
    // Send WM_QHOTKEY_UNHOOK message to messageLoop()
    PostThreadMessage(_pData->thrId, _pData->wmId, NULL, NULL);
    _loop.join();
    UnregisterHotKey(NULL, _hkid);
    delete _pData;
}

void Qt::QHotkey::registerHotkey()
{
    _pData->wmId = RegisterWindowMessage(L"WM_QHOTKEY_UNHOOK");
    _pData->thrId = GetCurrentThreadId();

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
        if (msg.message == _pData->wmId) return;
        if (msg.message == WM_HOTKEY &&
            msg.wParam == _hkid) {
            if (msg.wParam == _hkid) {
                emit pressed(*this); // Qt callback slot
            }
        }
    }
}
#endif // Q_OS_WIN

#endif // QHOTKEY_WIN_H
