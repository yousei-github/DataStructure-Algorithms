/* Header */
#include "SortingAlgorithm/InsertionSort.h"

// C++ standard libraries:
#include <cassert>

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace SortingAlgorithm
{

/** @brief Sort a array in ascending order
 * 
 *  @param array The pointer of the array
 *  @param length The length of the array
*/
template<class T>
void insertionSort(T* array, const uint32_t length)
{
    assert(array != nullptr);

    for (size_t index = 1; index < length; index++) // Insertion loop
    {
        T current       = array[index];                           // Current element to insert
        size_t subIndex = index;                                  // Start at the current element
        while ((subIndex > 0) && (array[subIndex - 1] > current)) // While array[subIndex - 1] is out of order
        {
            array[subIndex] = array[subIndex - 1]; // Move array[subIndex - 1]
            subIndex--;                            // Decrement subIndex
        }
        array[subIndex] = current; // This is the proper place for current
    }
}

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template function]
template void insertionSort<int>(int* array, const uint32_t length);

} // namespace SortingAlgorithm
