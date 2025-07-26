/* Header */
#include "Recursion/BinarySum.h"
#include "gtest/gtest.h"

// C standard libraries:
#include <stddef.h>

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

TEST(BinarySum, Sum50Elements)
{
    /* Arrange */
#ifdef NUMBER_OF_ELEMENTS
#undef NUMBER_OF_ELEMENTS
#endif /* NUMBER_OF_ELEMENTS */
#define NUMBER_OF_ELEMENTS (50u)

    uint32_t array[NUMBER_OF_ELEMENTS] = {};
    uint32_t expected_result           = {};
    for (size_t index = 0; index < NUMBER_OF_ELEMENTS; index++)
    {
        array[index] = index + 1;
        expected_result += array[index];
    }

    /* Act */
    const uint32_t result = Recursion::binarySum(array, 0, NUMBER_OF_ELEMENTS);

    /* Assert */
    EXPECT_EQ(expected_result, result);
}

TEST(BinarySum, Sum51Elements)
{
    /* Arrange */
#ifdef NUMBER_OF_ELEMENTS
#undef NUMBER_OF_ELEMENTS
#endif /* NUMBER_OF_ELEMENTS */
#define NUMBER_OF_ELEMENTS (51u)

    uint32_t array[NUMBER_OF_ELEMENTS] = {};
    uint32_t expected_result           = {};
    for (size_t index = 0; index < NUMBER_OF_ELEMENTS; index++)
    {
        array[index] = index + 1;
        expected_result += array[index];
    }

    /* Act */
    const uint32_t result = Recursion::binarySum(array, 0, NUMBER_OF_ELEMENTS);

    /* Assert */
    EXPECT_EQ(expected_result, result);
}
