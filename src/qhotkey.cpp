#include "qhotkey.h"
#include <QtCore>

int Qt::QHotkey::_ghkid = 0;


Qt::QHotkey::QHotkey(const Qt::ModifierKey modifiers, const Qt::Key key,
                     const callback_t callback)
    : _modifiers(modifiers), _key(key),
      _callback(callback), _hkid(_ghkid++),
      _loop(&Qt::QHotkey::registerHotkey, this),
      _registered(false)
{}

#ifdef Q_OS_WIN
 #include "qhotkey_win.h"
#elif defined(Q_OS_OSX)
 #include "qhotkey_osx.h"
#elif defined(Q_OS_LINUX)
 #include "qhotkey_linux.h"
#else
 #error This OS is not yet implemented. You can help at https://github.com/mrousavy/QHotkeys
#endif
