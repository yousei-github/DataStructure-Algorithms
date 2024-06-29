/* Header */
#include "Recursion/LinearSum.h"

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace Recursion
{

template<class T>
T linearSum(T* array, const uint32_t number)
{
    if (number == 1)
    {
        return array[0];
    }
    else
    {
        return linearSum(array, number - 1) + array[number - 1];
    }
}

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template function]
template int linearSum<int>(int* array, const uint32_t number);
template uint32_t linearSum<uint32_t>(uint32_t* array, const uint32_t number);

} // namespace Recursion
