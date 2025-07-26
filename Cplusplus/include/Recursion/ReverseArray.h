/**
 * @brief Reverse an Array
 * 
 */
#ifndef _REVERSE_ARRAY_H
#define _REVERSE_ARRAY_H 1

/* Header */
// Project configuration
#include "ProjectConfiguration.h"

// C standard libraries:
#include <stdint.h>

/* Macro */

/* Type */

namespace Recursion
{
/* Prototype */

/* Variable */

/* Function */

/**
 * @brief
 * Reverse an array by tail recursion
 * 
 * @param[in] array The pointer of an array
 * @param[in] startIndex The start index of the array
 * @param[in] endIndex The end index of the array
 * 
 * @return none
 */
template<class T>
void reverseArray(T* array, const uint32_t startIndex, const uint32_t endIndex);

/**
 * @brief
 * Reverse an array by iteration (non-recursive)
 * 
 * @param[in] array The pointer of an array
 * @param[in] startIndex The start index of the array
 * @param[in] endIndex The end index of the array
 * 
 * @return none
 */
template<class T>
void iterativeReverseArray(T* array, const uint32_t startIndex, const uint32_t endIndex);

} // namespace Recursion

#endif /* _REVERSE_ARRAY_H */
