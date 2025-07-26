/* Header */
#include "Average/PrefixAverage.h"
#include "gtest/gtest.h"

// C standard libraries:
#include <stddef.h>
#include <string.h>

/* Macro */

/* Type */

/* Test */

template<class T>
bool areAllSame(T* const array, const uint32_t number, const T element)
{
    // Handle empty array
    if (number == 0)
    {
        return false;
    }

    // Compare each element to the target element
    for (size_t index = 0; index < number; index++)
    {
        if (array[index] != element)
        {
            return false; // Found a different element
        }
    }

    return true; // All elements are the same
}

TEST(PrefixAverage, Calculate3Elements)
{
    /* Arrange */
#ifdef NUMBER_OF_ELEMENTS
#undef NUMBER_OF_ELEMENTS
#endif /* NUMBER_OF_ELEMENTS */
#define NUMBER_OF_ELEMENTS (3u)

    int array[NUMBER_OF_ELEMENTS]                 = {1, 2, 3};
    const int expected_result[NUMBER_OF_ELEMENTS] = {1, 1, 2};

    /* Act */
    Average::prefixAverage(array, NUMBER_OF_ELEMENTS);

    /* Assert */
    EXPECT_EQ(0, memcmp(expected_result, array, sizeof(int) * NUMBER_OF_ELEMENTS));
}
