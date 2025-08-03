/**
 * @brief Element uniqueness problem
 * 
 * Given a range, i, i+1, ..., j, of indices for an array, A,
 * we want to determine if the elements of this range, A⁡[i], A⁡[i+1], ..., A⁡[j], are all unique,
 * that is, there is no repeated element in this group of array entries. 
 */
#ifndef _ELEMENT_UNIQUENESS_H
#define _ELEMENT_UNIQUENESS_H 1

/* Header */
// Project configuration
#include "ProjectConfiguration.h"

// C standard libraries:
#include <stdint.h>

// C++ standard libraries:
#include <vector>

/* Macro */

/* Type */

namespace Array
{

/* Prototype */

/* Variable */

/* Function */

/**
 * @brief
 * Determine if there is no repeated element in this group of array entries, which takes O(2^n - 1) time
 * 
 * @param[in] array The vector of array A
 * @param[in] start The index of start entry
 * @param[in] end   The index of end entry
 * 
 * @retval true  No repeated element
 * @retval false Otherwise
 */
template<class T>
bool isUnique(const std::vector<T>& array, const uint32_t start, const uint32_t end);

/**
 * @brief
 * Determine if there is no repeated element in this group of array entries using loop technique, which takes O(n^2) time
 * 
 * @param[in] array The vector of array A
 * @param[in] start The index of start entry
 * @param[in] end   The index of end entry
 * 
 * @retval true  No repeated element
 * @retval false Otherwise
 */
template<class T>
bool fastIsUnique(const std::vector<T>& array, const uint32_t start, const uint32_t end);

/**
 * @brief
 * Determine if there is no repeated element in this group of array entries using sorting technique, which takes O(nlog(n)) time
 * 
 * @param[in] array The vector of array A
 * @param[in] start The index of start entry
 * @param[in] end   The index of end entry
 * 
 * @retval true  No repeated element
 * @retval false Otherwise
 */
template<class T>
bool isUniqueBySort(const std::vector<T>& array, const uint32_t start, const uint32_t end);

} // namespace Array

#endif /* _ELEMENT_UNIQUENESS_H */
