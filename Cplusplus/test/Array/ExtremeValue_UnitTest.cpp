/* Header */
#include "Array/ExtremeValue.h"
#include "gtest/gtest.h"

/* Macro */

/* Type */

/* Test */

TEST(FindMax, ZeroLength)
{
    /* Arrange */
#ifdef NUMBER_OF_ELEMENTS
#undef NUMBER_OF_ELEMENTS
#endif /* NUMBER_OF_ELEMENTS */
#define NUMBER_OF_ELEMENTS (3u)

    const int expected_result           = int {};
    const int array[NUMBER_OF_ELEMENTS] = {0, 1, 2};

    /* Act */
    const int maximum                   = Array::findMax(array, 0);

    /* Assert */
    EXPECT_EQ(expected_result, maximum);
}

TEST(FindMax, Maximum5)
{
    /* Arrange */
#ifdef NUMBER_OF_ELEMENTS
#undef NUMBER_OF_ELEMENTS
#endif /* NUMBER_OF_ELEMENTS */
#define NUMBER_OF_ELEMENTS (3u)

    const int expected_result           = 5;
    const int array[NUMBER_OF_ELEMENTS] = {0, expected_result, expected_result - 1};

    /* Act */
    const int maximum                   = Array::findMax(array, NUMBER_OF_ELEMENTS);

    /* Assert */
    EXPECT_EQ(expected_result, maximum);
}

TEST(FindMaxFromVector, ZeroLength)
{
    /* Arrange */

    const int expected_result = int {};
    std::vector<int> array {};

    /* Act */
    const int maximum = Array::findMax(array);

    /* Assert */
    EXPECT_EQ(expected_result, maximum);
}

TEST(FindMaxFromVector, Maximum5)
{
    /* Arrange */

    const int expected_result = 5;
    std::vector<int> array    = {0, expected_result, expected_result - 1};

    /* Act */
    const int maximum         = Array::findMax(array);

    /* Assert */
    EXPECT_EQ(expected_result, maximum);
}

TEST(FindMin, ZeroLength)
{
    /* Arrange */
#ifdef NUMBER_OF_ELEMENTS
#undef NUMBER_OF_ELEMENTS
#endif /* NUMBER_OF_ELEMENTS */
#define NUMBER_OF_ELEMENTS (3u)

    const int expected_result           = int {};
    const int array[NUMBER_OF_ELEMENTS] = {0, 1, 2};

    /* Act */
    const int minimum                   = Array::findMin(array, 0);

    /* Assert */
    EXPECT_EQ(expected_result, minimum);
}

TEST(FindMin, Minimum5)
{
    /* Arrange */
#ifdef NUMBER_OF_ELEMENTS
#undef NUMBER_OF_ELEMENTS
#endif /* NUMBER_OF_ELEMENTS */
#define NUMBER_OF_ELEMENTS (3u)

    const int expected_result           = 1;
    const int array[NUMBER_OF_ELEMENTS] = {expected_result + 1, expected_result, expected_result + 2};

    /* Act */
    const int minimum                   = Array::findMin(array, NUMBER_OF_ELEMENTS);

    /* Assert */
    EXPECT_EQ(expected_result, minimum);
}

TEST(FindMinFromVector, ZeroLength)
{
    /* Arrange */

    const int expected_result = int {};
    std::vector<int> array {};

    /* Act */
    const int minimum = Array::findMin(array);

    /* Assert */
    EXPECT_EQ(expected_result, minimum);
}

TEST(FindMinFromVector, Minimum5)
{
    /* Arrange */

    const int expected_result = 1;
    std::vector<int> array    = {expected_result + 1, expected_result, expected_result + 2};

    /* Act */
    const int minimum         = Array::findMin(array);

    /* Assert */
    EXPECT_EQ(expected_result, minimum);
}
