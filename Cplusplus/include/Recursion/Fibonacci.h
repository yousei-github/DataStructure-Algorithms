/**
 * @brief Fibonacci
 * Fibonacci number
 */
#ifndef _FIBONACCI_H
#define _FIBONACCI_H 1

/* Header */
// Project configuration
#include "ProjectConfiguration.h"

// C standard libraries:
#include <stdint.h>

/* Macro */

/* Type */

namespace Recursion
{

/**
 * A pair of consecutive Fibonacci number (F^i, F^(i-1))
 * 
 * @note F^(-1) = 0
 */
template<class T>
struct fibonacci_pair
{
    T f_k;
    T f_k_1;
};

/* Prototype */

/* Variable */

/* Function */

/**
 * @brief
 * Fibonacci number
 * 
 * @param[in] index The index of the index-th Fibonacci number
 * 
 * @return A pair of Fibonacci number
 */
template<class T>
fibonacci_pair<T> linearFibonacci(T index);

} // namespace Recursion

#endif /* _FIBONACCI_H */
