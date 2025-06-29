/**
 * @brief Power Function
 *
 * A power function is a function of the form p(x, n) = x^n, where 'x' is the variable, and 'n' is a real number exponent.
 * It represents a single term where a variable is raised to a constant power.
 *
 * This function has an immediate recursive definition based on linear recursion:
 * p(x, n) = (1) 1;         if n = 0
 *         = (2) x · p(x, n-1). if n >= 1.
 * 
 * We can compute the power function much faster than this, however, by using the following alternative definition,
 * also based on linear recursion, which employs a squaring technique:
 * p(x, n) = (1) 1;                   if n = 0
 *         = (2) x · p(x, (n-1)/2)^2. if n > 0 is odd
 *         = (3) p(x, n/2)^2.         if n > 0 is even.
 */
#ifndef _POWER_H
#define _POWER_H 1

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
 * The power function
 * 
 * @param[in] number   A positive integer for the variable of power
 * @param[in] exponent A nonnegative integer for the exponent of power
 * 
 * @return The result of the power function of @p number and @p exponent
 */
template<class T>
T recursivePower(const T number, const T exponent);

/**
 * @brief
 * The power function employing a squaring technique
 * 
 * @param[in] number   A positive integer for the variable of power
 * @param[in] exponent A nonnegative integer for the exponent of power
 * 
 * @return The result of the power function of @p number and @p exponent
 */
template<class T>
T fastRecursivePower(const T number, const T exponent);

} // namespace Recursion

#endif /* _POWER_H */
