/* Header */
#include "Recursion/ReverseArray.h"
#include "gtest/gtest.h"

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

TEST(ReverseArray, Reverse50Elements)
{
    /* Arrange */
#define NUMBER_OF_ELEMENTS (50u)
    uint32_t array[NUMBER_OF_ELEMENTS]           = {};
    uint32_t expected_result[NUMBER_OF_ELEMENTS] = {};
    for (size_t index = 0; index < NUMBER_OF_ELEMENTS; index++)
    {
        array[index]                                    = index + 1;
        expected_result[NUMBER_OF_ELEMENTS - index - 1] = array[index];
    }

    /* Act */
    Recursion::reverseArray(array, 0, NUMBER_OF_ELEMENTS - 1);

    /* Assert */
    for (size_t index = 0; index < NUMBER_OF_ELEMENTS; index++)
    {
        EXPECT_EQ(expected_result[index], array[index]);
    }
}
