#include "qhotkey.h"
#include <QtCore>

#if !defined(Q_OS_WIN) && !defined(Q_OS_LINUX) && !defined(Q_OS_MACOS)
 #error This OS is not yet implemented. You can help at https://github.com/mrousavy/QHotkeys
#endif
