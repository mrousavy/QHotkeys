#include "qhotkey.h"

#ifdef Q_OS_WIN
#include <windows.h>
#elif defined(Q_OS_OSX)
#include <aqua>
#elif defined(Q_OS_LINUX)
#include <X11>
#endif

size_t QHotkey::_ghkid = 0;

QHotkey::QHotkey(const Modifier modifiers, const Qt::Key key,
                 const callback_t callback)
    : _modifiers(modifiers), _key(key),
      _callback(callback), _hkid(_ghkid++)
{
    registerHotkey();
}

void QHotkey::messageLoop() const
{
#ifdef Q_OS_WIN
    MSG msg;
    while (GetMessage(&msg, 0, 0, 0))
    {
        switch (msg.message)
        {
        case WM_HOTKEY:
            if (msg.wParam == _hkid)
            {
                _callback(*this);
            }
        }
    }
#elif defined(Q_OS_OSX)
    // TODO:
#elif defined(Q_OS_LINUX)
    // TODO:
#endif
}

void QHotkey::registerHotkey() const
{
#ifdef Q_OS_WIN
    WINBOOL result = RegisterHotKey(0, _hkid, getMod(_modifiers), getKey(_key));
    if (result == FALSE)
        throw std::runtime_error("Could not register hotkey! " + GetLastError());
#elif defined(Q_OS_OSX)
    // TODO:
#elif defined(Q_OS_LINUX)
    // TODO:
#endif
}


int QHotkey::getMod(const Modifier& modifier) const noexcept
{
    return static_cast<int>(modifier);
}
int QHotkey::getKey(const Qt::Key& key) const noexcept
{
    return static_cast<int>(key);
}
