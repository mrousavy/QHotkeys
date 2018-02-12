#ifndef QHOTKEY_OSX_H
#define QHOTKEY_OSX_H
#include <QtCore>

#ifdef Q_OS_MACOS
#include "qhotkey.h"
#include "helper.h"
#include <aqua>

int Qt::QHotkey::_ghkid = 0;
struct Qt::QHotkey::PlatformData
{
    int _thrId;
    // TODO: PLATFORMDATA
};

Qt::QHotkey::QHotkey(const Qt::ModifierKey modifiers, const Qt::Key key)
    : _modifiers(modifiers), _key(key),
      _hkid(_ghkid++), _registered(false),
      _loop(&Qt::QHotkey::registerHotkey, this),
      _pData(new PlatformData)
{}

Qt::QHotkey::~QHotkey()
{
    // TODO: OSX IMPLEMENTATION
}

void Qt::QHotkey::registerHotkey()
{
    qDebug() << _registered;
    if (_registered)
        throw std::runtime_error("This QHotkey instance is already registered!");

    // TODO: OSX IMPLEMENTATION
    _registered = result == 0;
    messageLoop();
}

void Qt::QHotkey::messageLoop() const
{
    // TODO: OSX IMPLEMENTATION
}
#endif // Q_OS_MACOS

#endif // QHOTKEY_OSX_H
