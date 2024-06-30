/**
 * @brief Factorial Function
 * 
 * The factorial of a positive integer n, denoted n!, is defined as the product of the integers from 1 to n.
 * If n = 0, then n! is defined as 1 by convention. More formally, for any integer n>= 0,
 * n! = (1) 1;                               if n = 0
 *      (2) n · (n−1) · (n−2) ··· 3 · 2 · 1. if n >= 1.
 */
#ifndef _FACTORIAL_H
#define _FACTORIAL_H 1

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
 * The factorial function
 * 
 * @param[in] number A positive integer for factorial
 * 
 * @return The result of the factorial of @p number
 */
template<class T>
T recursiveFactorial(const T number);

} // namespace Recursion

#endif /* _FACTORIAL_H */
