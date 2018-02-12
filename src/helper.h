#ifndef HELPER_H
#define HELPER_H
#include "qhotkey.h"

/*!
 * \brief getKey Convert the given modifier to a platform specific modifier ID
 * \param modifier The given Modifier
 * \return A platform specific modifier ID for OS calls
 */
inline int getMod(const Qt::ModifierKey& modifier) noexcept
{
    return static_cast<int>(modifier);
}
/*!
 * \brief getKey Convert the given Qt key to a platform specific key ID
 * \param key The given Qt::Key
 * \return A platform specific key ID for OS calls
 */
inline int getKey(const Qt::Key& key) noexcept
{
    return static_cast<int>(key);
}

#endif // HELPER_H
