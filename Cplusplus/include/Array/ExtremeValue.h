/**
 * @brief Extreme Value
 */
#ifndef _EXTREME_VALUE_H
#define _BASIC_ARRAY_H 1

/* Header */
// Project configuration
#include "ProjectConfiguration.h"

// C standard libraries:
#include <stdint.h>

/* Macro */

/* Type */

namespace Array
{

/* Prototype */

/* Variable */

/* Function */

/**
 * @brief
 * Finding the largest value in an array
 * 
 * @param[in] array  The pointer of an array
 * @param[in] number The number of elements (or length) of the array
 * 
 * @return The largest value (Maximum)
 */
template<class T>
T findMax(const T* const array, const uint32_t number);

/**
 * @brief
 * Finding the smallest value in an array
 * 
 * @param[in] array  The pointer of an array
 * @param[in] number The number of elements (or length) of the array
 * 
 * @return The smallest value (Minimum)
 */
template<class T>
T findMin(const T* const array, const uint32_t number);

} // namespace Array

#endif /* _BASIC_ARRAY_H */
