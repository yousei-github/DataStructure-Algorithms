/* Header */
#include "Recursion/Fibonacci.h"
#include "gtest/gtest.h"

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

TEST(LinearFibonacci, IndexOne)
{
    /* Arrange */
    const uint32_t index                                      = 1;
    const Recursion::fibonacci_pair<uint32_t> expected_result = {.f_k = 1, .f_k_1 = 0};

    /* Act */
    const Recursion::fibonacci_pair<uint32_t> result          = Recursion::linearFibonacci(index);

    /* Assert */
    EXPECT_EQ(expected_result.f_k, result.f_k);
}

TEST(LinearFibonacci, IndexTwo)
{
    /* Arrange */
    const uint32_t index                                      = 2;
    const Recursion::fibonacci_pair<uint32_t> expected_result = {.f_k = 1, .f_k_1 = 1};

    /* Act */
    const Recursion::fibonacci_pair<uint32_t> result          = Recursion::linearFibonacci(index);

    /* Assert */
    EXPECT_EQ(expected_result.f_k, result.f_k);
}

TEST(LinearFibonacci, IndexThree)
{
    /* Arrange */
    const uint32_t index                                      = 3;
    const Recursion::fibonacci_pair<uint32_t> expected_result = {.f_k = 2, .f_k_1 = 1};

    /* Act */
    const Recursion::fibonacci_pair<uint32_t> result          = Recursion::linearFibonacci(index);

    /* Assert */
    EXPECT_EQ(expected_result.f_k, result.f_k);
}

TEST(LinearFibonacci, IndexTen)
{
    /* Arrange */
    const uint32_t index                                      = 10;
    const Recursion::fibonacci_pair<uint32_t> expected_result = {.f_k = 55, .f_k_1 = 34};

    /* Act */
    const Recursion::fibonacci_pair<uint32_t> result          = Recursion::linearFibonacci(index);

    /* Assert */
    EXPECT_EQ(expected_result.f_k, result.f_k);
}
