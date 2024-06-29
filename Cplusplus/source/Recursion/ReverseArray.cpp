/* Header */
#include "Recursion/ReverseArray.h"

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
void reverseArray(T* array, const uint32_t startIndex, const uint32_t endIndex)
{
    assert(array != nullptr);

    if (startIndex < endIndex)
    {
        T temp            = array[startIndex];
        array[startIndex] = array[endIndex];
        array[endIndex]   = temp;

        reverseArray(array, startIndex + 1, endIndex - 1);
    }
}

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template function]
template void reverseArray<uint32_t>(uint32_t* array, const uint32_t startIndex, const uint32_t endIndex);

} // namespace Recursion
