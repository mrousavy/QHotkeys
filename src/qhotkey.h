#ifndef QHOTKEY_H
#define QHOTKEY_H
#include <QtCore>
#include <functional>

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
    using callback_t = std::function<void(const QHotkey&)>;

public:
    /*!
     * \brief QHotkey Create and hook a new Global Hotkey
     * \param modifiers The modifier keys for the hotkey (e.g. ::Control | ::Alt)
     * \param key The actual key to be registered as a hotkey
     */
    QHotkey(const Modifier modifiers, const Qt::Key key,
            const callback_t callback);

private:
    const Modifier _modifiers;
    const Qt::Key _key;
    const callback_t _callback;
    const size_t _hkid;

    static size_t _ghkid;

private:
    void registerHotkey() const;
    void messageLoop() const;
    /*!
     * \brief getKey Convert the given modifier to a platform specific modifier ID
     * \param modifier The given Modifier
     * \return A platform specific modifier ID for OS calls
     */
    int getMod(const Modifier& modifier) const noexcept;
    /*!
     * \brief getKey Convert the given Qt key to a platform specific key ID
     * \param key The given Qt::Key
     * \return A platform specific key ID for OS calls
     */
    int getKey(const Qt::Key& key) const noexcept;
};

#endif // QHOTKEY_H
