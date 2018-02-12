#ifndef QHOTKEY_H
#define QHOTKEY_H
#include <QtCore>
#include <thread>
#include <functional>

#ifdef QHOTKEYS_SHAREDLIB
 #ifdef QHOTKEYS_EXPORT
  #define QHOTKEYS_DLLSPEC Q_DECL_EXPORT
 #else
  #define QHOTKEYS_DLLSPEC Q_DECL_IMPORT
 #endif
#else
 #define QHOTKEYS_DLLSPEC
#endif

namespace Qt
{
/*!
 * \brief An enum representing modifier keys on the keyboard
 */
enum class QHOTKEYS_DLLSPEC ModifierKey
{
    None    = 1 << 0,
    Control = 1 << 1,
    Shift   = 1 << 2,
    Alt     = 1 << 3,
    Meta    = 1 << 4
};
inline ModifierKey operator|(ModifierKey a, ModifierKey b)
{
    return static_cast<ModifierKey>(static_cast<int>(a) | static_cast<int>(b));
}

/*!
 * \brief A hooked global hotkey
 */
class QHOTKEYS_DLLSPEC QHotkey : public QObject
{
    Q_OBJECT
    using callback_t = std::function<void(const QHotkey&)>;

/////////////////
/// FUNCTIONS ///
/////////////////
public:
    /*!
     * \brief QHotkey Create and hook a new Global Hotkey
     * \param modifiers The modifier keys for the hotkey (e.g. ::Control | ::Alt)
     * \param key The actual key to be registered as a hotkey
     */
    QHotkey(const ModifierKey modifiers, const Key key);
    /*!
      * \brief ~QHotkey Destroy and unhook the Hotkey
      */
    ~QHotkey();

signals:
    /*!
     * \brief pressed The Callback function which gets emitted
     * once the hotkey has been pressed. Connect this function
     * to a valid SLOT to handle this event.
     */
    void pressed(const QHotkey&) const;

/////////////////
///  MEMBER   ///
/////////////////
private:
    const ModifierKey _modifiers;
    const Key _key;
    const int _hkid;
    bool _registered;
    std::thread _loop;

    struct PlatformData;
    PlatformData* _pData;

    static int _ghkid;

/////////////////
/// FUNCTIONS ///
/////////////////
private:
    void registerHotkey();
    void messageLoop() const;
};
}
#endif // QHOTKEY_H
