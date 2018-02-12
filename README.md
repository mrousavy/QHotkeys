# QHotkeys
🔠 A small and lightweight cross platform C++ library implementing a system-wide hotkey system for Qt

There are implementations available for the following compilers/platforms:
* msvc - Windows
* linux - Linux/X11
* macx - MacOSX

## Usage
#### Install
Run this command in your project's directory:
```sh
git submodule add https://github.com/mrousavy/QHotkeys
```

Add these lines to your Qt Project file (`.pro`):
```qmake
include(QHotkeys/QHotkeys.pri)
DEPENDPATH  += QHotkeys/src/
INCLUDEPATH += QHotkeys/src/
```

#### Code
```cpp
#include <qhotkeys.h>
using namespace Qt;
// ...
void myCallback(const QHotkey& hotkey) {
  // This is executed on a seperate thread!
  cout << "Hotkey pressed!";
}
// ...
QHotkey hotkey(ModifierKey::Control | ModifierKey::Alt, Key_I);
QObject::connect(hotkey, &QHotkey::pressed, &myCallback);
```
