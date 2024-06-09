/* Header */
#include "Recursion/Factorial.h"

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace Recursion
{

uint32_t recursiveFactorial(const uint32_t number)
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

} // namespace Recursion
