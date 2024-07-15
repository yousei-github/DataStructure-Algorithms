/**
 * @brief Linear Sum
 * Sum the elements of an array recursively
 */
#ifndef _LINEARSUM_H
#define _LINEARSUM_H 1

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
 * The binary sum
 * 
 * @param[in] array      The pointer of an array
 * @param[in] startIndex The starting index of the array
 * @param[in] number     The number of elements (or length) in the array
 * 
 * @return The result of linear sum
 */
template<class T>
T binarySum(T* array, const uint32_t startIndex, const uint32_t number);

} // namespace Recursion

#endif /* _LINEARSUM_H */
