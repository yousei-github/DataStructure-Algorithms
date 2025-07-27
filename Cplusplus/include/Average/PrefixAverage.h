/**
 * @brief Prefix Average
 *
 * Prefix averages of a sequence of numbers.
 * Namely, given an array X storing n numbers, we want to compute an array A such that A⁡[i] is the average of elements X⁡[0], ..., X⁡[i], for i=0, ... , n-1, that is,
 * A⁡[i] = Sum(X, 0, i + 1) / (i + 1)
 */
#ifndef _PREFIX_AVERAGE_H
#define _PREFIX_AVERAGE_H 1

/* Header */
// Project configuration
#include "ProjectConfiguration.h"

// C standard libraries:
#include <stdint.h>

/* Macro */

/* Type */

namespace Average
{
/* Prototype */

/* Variable */

/* Function */

/**
 * @brief
 * The prefix average calculation, which takes O(n^2) time
 * 
 * @param[inout] array The pointer of an array
 * @param[in] number   The number of elements (or length) of the array
 * 
 * @note The result of prefix average is saved in the @p array
 */
template<class T>
void prefixAverage(T* const array, const uint32_t number);

/**
 * @brief
 * The prefix average calculation utilizing prefix sum for performance, which takes O(n) time
 * 
 * @param[inout] array The pointer of an array
 * @param[in] number   The number of elements (or length) of the array
 * 
 * @note The result of prefix average is saved in the @p array
 */
template<class T>
void fastPrefixAverage(T* const array, const uint32_t number);

} // namespace Average

#endif /* _PREFIX_AVERAGE_H */
