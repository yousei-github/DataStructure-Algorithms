/* Header */
#include "Recursion/Power.h"
#include "gtest/gtest.h"

/* Macro */

/* Type */

/* Test */

TEST(PowerFunctionOfNumberZero, ExponentZero)
{
    /* Arrange */

    /* Act */
    const uint32_t result = Recursion::recursivePower(0, 0);

    /* Assert */
    EXPECT_EQ(1, result);
}

TEST(PowerFunctionOfNumberOne, ExponentZero)
{
    /* Arrange */

    /* Act */
    const uint32_t result = Recursion::recursivePower(1, 0);

    /* Assert */
    EXPECT_EQ(1, result);
}

TEST(PowerFunctionOfNumberOne, ExponentOne)
{
    /* Arrange */

    /* Act */
    const uint32_t result = Recursion::recursivePower(1, 1);

    /* Assert */
    EXPECT_EQ(1, result);
}

TEST(PowerFunctionOfNumberTwo, ExponentFour)
{
    /* Arrange */

    /* Act */
    const uint32_t result = Recursion::recursivePower(2, 4);

    /* Assert */
    EXPECT_EQ(16, result);
}

TEST(PowerFunctionOfNumberTwo, ExponentFive)
{
    /* Arrange */

    /* Act */
    const uint32_t result = Recursion::recursivePower(2, 5);

    /* Assert */
    EXPECT_EQ(32, result);
}

TEST(FastPowerFunctionOfNumberZero, ExponentZero)
{
    /* Arrange */

    /* Act */
    const uint32_t result = Recursion::fastRecursivePower(0, 0);

    /* Assert */
    EXPECT_EQ(1, result);
}

TEST(FastPowerFunctionOfNumberOne, ExponentZero)
{
    /* Arrange */

    /* Act */
    const uint32_t result = Recursion::fastRecursivePower(1, 0);

    /* Assert */
    EXPECT_EQ(1, result);
}

TEST(FastPowerFunctionOfNumberOne, ExponentOne)
{
    /* Arrange */

    /* Act */
    const uint32_t result = Recursion::fastRecursivePower(1, 1);

    /* Assert */
    EXPECT_EQ(1, result);
}

TEST(FastPowerFunctionOfNumberTwo, ExponentFour)
{
    /* Arrange */

    /* Act */
    const uint32_t result = Recursion::fastRecursivePower(2, 4);

    /* Assert */
    EXPECT_EQ(16, result);
}

TEST(FastPowerFunctionOfNumberTwo, ExponentFive)
{
    /* Arrange */

    /* Act */
    const uint32_t result = Recursion::fastRecursivePower(2, 5);

    /* Assert */
    EXPECT_EQ(32, result);
}
