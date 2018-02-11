#ifndef QHOTKEY_H
#define QHOTKEY_H
#include <QtCore>

/*!
 * \brief An enum representing modifier keys on the keyboard
 */
enum class Modifier
{
    None    = 1 << 1,
    Control = 1 << 1,
    Shift   = 1 << 2,
    Alt     = 1 << 3,
    Meta    = 1 << 4
};

class QHotkey
{

public:
    QHotkey();
};

#endif // QHOTKEY_H
