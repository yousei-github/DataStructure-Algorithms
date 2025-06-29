/* Header */
#include "Recursion/Power.h"

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace Recursion
{

template<class T>
T recursivePower(const T number, const T exponent)
{
    // Recursive factorial function
    if (exponent == 0)
    {
        // Basis case
        return 1;
    }
    else
    {
        // Recursive case
        return number * recursivePower(number, exponent - 1);
    }
}

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template function]
template int recursivePower<int>(const int number, const int exponent);

template<class T>
T fastRecursivePower(const T number, const T exponent)
{
    const bool isEven = (exponent % 2) ? false : true;

    // Recursive factorial function
    if (exponent == 0)
    {
        // Basis case
        return 1;
    }
    else if (isEven)
    {
        // Recursive case when number is even
        const T result = fastRecursivePower(number, exponent / 2);
        return result * result;
    }
    else
    {
        // Recursive case when number is odd
        const T result = fastRecursivePower(number, (exponent - 1) / 2);
        return number * result * result;
    }
}

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template function]
template int fastRecursivePower<int>(const int number, const int exponent);

} // namespace Recursion
