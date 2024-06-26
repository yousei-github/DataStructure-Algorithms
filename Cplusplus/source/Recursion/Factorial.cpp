/* Header */
#include "Recursion/Factorial.h"

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace Recursion
{

template<class T>
T recursiveFactorial(const T number)
{
    // Recursive factorial function
    if (number == 0)
    {
        // Basis case
        return 1;
    }
    else
    {
        // Recursive case
        return number * recursiveFactorial(number - 1);
    }
}

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template function]
template int recursiveFactorial<int>(const int number);

} // namespace Recursion
