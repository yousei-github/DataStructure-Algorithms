/* Header */
#include "Recursion/Factorial.h"
#include "gtest/gtest.h"

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

TEST(FactorialFunction, NumberZero)
{
    /* Arrange */

    /* Act */
    const uint32_t result = Recursion::recursiveFactorial(0);

    /* Assert */
    EXPECT_EQ(1, result);
}

TEST(FactorialFunction, NumberOne)
{
    /* Arrange */

    /* Act */
    const uint32_t result = Recursion::recursiveFactorial(1);

    /* Assert */
    EXPECT_EQ(1, result);
}

TEST(FactorialFunction, NumberThree)
{
    /* Arrange */

    /* Act */
    const uint32_t result = Recursion::recursiveFactorial(3);

    /* Assert */
    EXPECT_EQ(3 * 2, result);
}
