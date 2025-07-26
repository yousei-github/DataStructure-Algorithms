/* Header */
#include "Average/PrefixAverage.h"

// C standard libraries:
#include <stddef.h>
#include <string.h>

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace Average
{

template<class T>
void prefixAverage(T* const array, const uint32_t number)
{
    T* const input = new T[number];
    memcpy(input, array, sizeof(T) * number);

    for (size_t index = 0; index < number; index++)
    {
        T sum {}; // Zero initialization

        for (size_t subIndex = 0; subIndex <= index; subIndex++)
        {
            sum += input[subIndex];
        }

        array[index] = sum / (index + 1);
    }

    delete[] input;
}

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template function]
template void prefixAverage<int>(int* const array, const uint32_t number);

} // namespace Average
