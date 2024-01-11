/* Header */
#include "SortingAlgorithm/InsertionSort.h"

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
void insertionSort(T* array, uint32_t length)
{
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

} // namespace SortingAlgorithm
