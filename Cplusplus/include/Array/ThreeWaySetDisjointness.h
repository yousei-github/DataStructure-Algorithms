/**
 * @brief Three-way set disjointness problem
 * 
 * Suppose we are given three sets, A, B, and C, with these sets stored in three different integer arrays, a, b, and c, respectively.
 * The three-way set disjointness problem is to determine if these three sets are disjoint, that is,
 * whether there is no element x such that x ∈ A, x ∈ B, and, x ∈ C.
 */
#ifndef _THREE_WAY_SET_DISJOINTNESS_H
#define _THREE_WAY_SET_DISJOINTNESS_H 1

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
 * Determine if three sets are disjoint, which takes O(n^3) time
 * 
 * @param[in] a The vector of set A
 * @param[in] b The vector of set B
 * @param[in] c The vector of set C
 * 
 * @retval true  Three sets are disjoint
 * @retval false Otherwise
 */
template<class T>
bool areDisjoint(const std::vector<T>& a, const std::vector<T>& b, const std::vector<T>& c);

} // namespace Array

#endif /* _THREE_WAY_SET_DISJOINTNESS_H */
