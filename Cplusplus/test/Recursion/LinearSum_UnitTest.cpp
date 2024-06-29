/* Header */
#include "Recursion/LinearSum.h"
#include "gtest/gtest.h"

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

TEST(LinearSum, Sum50Elements)
{
    /* Arrange */
#define NUMBER_OF_ELEMENTs (50u)
    uint32_t array[NUMBER_OF_ELEMENTs] = {};
    uint32_t expected_result           = {};
    for (size_t index = 0; index < NUMBER_OF_ELEMENTs; index++)
    {
        array[index] = index + 1;
        expected_result += array[index];
    }

    /* Act */
    const uint32_t result = Recursion::linearSum(array, NUMBER_OF_ELEMENTs);

    /* Assert */
    EXPECT_EQ(expected_result, result);
}
