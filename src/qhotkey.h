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
     * \param hotkeys The keys to bind the QHotkey to (e.g. ::Control | ::Alt | ::I)
     */
    QHotkey(const Key hotkeys);
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
    const Key _keys;
    const int _hkid;
    std::thread _loop;
    bool _registered;

    struct PlatformData;
    PlatformData* _pData;

    static int _ghkid;

/////////////////
/// FUNCTIONS ///
/////////////////
private:
    void registerHotkey();
    void messageLoop() const;

    static inline bool has(Qt::Key enumVar, Qt::Key flag) {
        return (enumVar & flag) != 0;
    }
};
}
#endif // QHOTKEY_H
