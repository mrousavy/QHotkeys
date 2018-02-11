#include "qhotkey.h"
#include <QtCore>
#include <thread>

#ifdef Q_OS_WIN
 #include <Windows.h>
#elif defined(Q_OS_OSX)
 #include <aqua>
#elif defined(Q_OS_LINUX)
 #include <X11>
#endif

// TODO: REMOVE
#include <QDebug>


namespace Qt
{
int QHotkey::_ghkid = 0;

QHotkey::QHotkey(const ModifierKey modifiers, const Qt::Key key,
                 const callback_t callback)
    : _modifiers(modifiers), _key(key),
      _callback(callback), _hkid(_ghkid++),
      _loop(&QHotkey::registerHotkey, this),
      _stopReq(false), _registered(false)
{}

QHotkey::~QHotkey()
{
    _stopReq = true;
#ifdef Q_OS_WIN
    UnregisterHotKey(NULL, _hkid);
#elif defined(Q_OS_OSX)
    // TODO: OSX IMPLEMENTATION
#elif defined(Q_OS_LINUX)
    // TODO: LINUX IMPLEMENTATION
    int XUngrabKey(Display *display, int keycode, unsigned int
    modifiers, Window grab_window);
#else
#error This OS is not supported. You can implement this yourself at https://github.com/mrousavy/QHotkeys
#endif
    //_loop.join();
}

void QHotkey::messageLoop() const
{
#ifdef Q_OS_WIN
    MSG msg;
    while (GetMessage(&msg, NULL, NULL, NULL)) {
        if (_stopReq) return;
        if (msg.message == WM_HOTKEY &&
            msg.wParam == _hkid) {
            if (msg.wParam == _hkid) {
                _callback(*this);
            }
        }
    }
#elif defined(Q_OS_OSX)
    // TODO: OSX IMPLEMENTATION
#elif defined(Q_OS_LINUX)
    // TODO: LINUX IMPLEMENTATION
#else
 #error This OS is not supported. You can implement this yourself at https://github.com/mrousavy/QHotkeys
#endif
}

void QHotkey::registerHotkey()
{
    qDebug() << _registered;
    if (_registered)
        throw std::runtime_error("This QHotkey instance is already registered!");
#ifdef Q_OS_WIN
    auto result = RegisterHotKey(NULL, _hkid, getMod(_modifiers), getKey(_key));
    if (result == FALSE)
        throw std::runtime_error("Could not register hotkey! #" + GetLastError());
    _registered = result == 0;
    messageLoop();
#elif defined(Q_OS_OSX)
    // TODO: OSX IMPLEMENTATION
#elif defined(Q_OS_LINUX)
    // TODO: LINUX IMPLEMENTATION
    int XGrabKey(Display *display, int keycode, unsigned int
    modifiers, Window grab_window, Bool owner_events, int pointer_mode, int keyboard_mode);
#else
 #error This OS is not supported. You can implement this yourself at https://github.com/mrousavy/QHotkeys
#endif
}


int QHotkey::getMod(const ModifierKey& modifier) noexcept
{
    return static_cast<int>(modifier);
}
int QHotkey::getKey(const Qt::Key& key) noexcept
{
    return static_cast<int>(key);
}
}
