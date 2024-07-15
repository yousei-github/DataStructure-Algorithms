/* Header */
#include "Recursion/BinarySum.h"

// C++ standard libraries:
#include <cassert>

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace Recursion
{

template<class T>
T binarySum(T* array, const uint32_t startIndex, const uint32_t number)
{
    assert(array != nullptr);
    assert(number != 0);

    if (number == 1)
    {
        return array[startIndex];
    }

    const uint32_t roundUpHalfLength   = (number % 2) ? (number / 2 + 1) : (number / 2);
    const uint32_t roundDownHalfLength = number / 2;

    return binarySum(array, startIndex, roundUpHalfLength) + binarySum(array, startIndex + roundUpHalfLength, roundDownHalfLength);
}

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template function]
template int binarySum<int>(int* array, const uint32_t startIndex, const uint32_t number);
template uint32_t binarySum<uint32_t>(uint32_t* array, const uint32_t startIndex, const uint32_t number);

} // namespace Recursion
