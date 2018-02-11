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

/*!
 * \brief A hooked global hotkey
 */
class QHotkey
{
public:
    /*!
     * \brief QHotkey Create and hook a new Global Hotkey
     * \param modifiers The modifier keys for the hotkey (e.g. ::Control | ::Alt)
     * \param key The actual key to be registered as a hotkey
     */
    QHotkey(Modifier modifiers, Qt::Key key);

private:
    Modifier _modifiers;
    Qt::Key _key;
};

#endif // QHOTKEY_H
