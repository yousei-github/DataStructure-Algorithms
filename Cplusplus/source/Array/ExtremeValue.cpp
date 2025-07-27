/* Header */
#include "Array/ExtremeValue.h"

// C++ standard libraries:
#include <cassert>

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace Array
{

template<class T>
T findMax(const T* const array, const uint32_t number)
{
    assert(array);

    if (number == 0)
    {
        return T {};
    }

    T max = array[0];
    for (size_t index = 1; index < number; index++)
    {
        if (max < array[index])
        {
            max = array[index];
        }
    }

    return max;
}

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template function]
template int findMax<int>(const int* const array, const uint32_t number);

template<class T>
T findMin(const T* const array, const uint32_t number)
{
    assert(array);

    if (number == 0)
    {
        return T {};
    }

    T min = array[0];
    for (size_t index = 1; index < number; index++)
    {
        if (array[index] < min)
        {
            min = array[index];
        }
    }

    return min;
}

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template function]
template int findMin<int>(const int* const array, const uint32_t number);

} // namespace Array
