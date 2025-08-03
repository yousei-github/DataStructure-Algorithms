/* Header */
#include "Array/ElementUniqueness.h"

// C++ standard libraries:
#include <algorithm>

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace Array
{

template<class T>
bool isUnique(const std::vector<T>& array, const uint32_t start, const uint32_t end)
{
    if (start >= end)
    {
        return true;
    }

    if (! isUnique(array, start, end - 1))
    {
        return false;
    }

    if (! isUnique(array, start + 1, end))
    {
        return false;
    }

    return (array[start] != array[end]);
}

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template function]
template bool isUnique<int>(const std::vector<int>& array, const uint32_t start, const uint32_t end);

template<class T>
bool fastIsUnique(const std::vector<T>& array, const uint32_t start, const uint32_t end)
{
    if (start >= end)
    {
        return true;
    }

    for (size_t index = start; index < end; index++)
    {
        for (size_t subIndex = index + 1; subIndex <= end; subIndex++)
        {
            if (array[index] == array[subIndex])
            {
                return false;
            }
        }
    }

    return true;
}

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template function]
template bool fastIsUnique<int>(const std::vector<int>& array, const uint32_t start, const uint32_t end);

template<class T>
bool isUniqueBySort(const std::vector<T>& array, const uint32_t start, const uint32_t end)
{
    if (start >= end)
    {
        return true;
    }

    std::vector<T> buffer(array);                            // Duplicate copy of array
    std::sort(buffer.begin() + start, buffer.begin() + end); // Sort the subarray

    for (size_t index = start; index < end; index++) // Check for duplicates
    {
        if (array[index] == array[index + 1])
        {
            return false;
        }
    }

    return true;
}

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template function]
template bool isUniqueBySort<int>(const std::vector<int>& array, const uint32_t start, const uint32_t end);

} // namespace Array
