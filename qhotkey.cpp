#include "qhotkey.h"


QHotkey::QHotkey(Modifier modifiers, Qt::Key key)
    : _modifiers(modifiers), _key(key)
{
}
