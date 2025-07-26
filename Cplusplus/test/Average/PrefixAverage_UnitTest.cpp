/* Header */
#include "Average/PrefixAverage.h"
#include "gtest/gtest.h"

// C standard libraries:
#include <stddef.h>
#include <string.h>

/* Macro */

/* Type */

/* Test */

TEST(PrefixAverage, Calculate1Element)
{
    /* Arrange */
#ifdef NUMBER_OF_ELEMENTS
#undef NUMBER_OF_ELEMENTS
#endif /* NUMBER_OF_ELEMENTS */
#define NUMBER_OF_ELEMENTS (1u)

    int array[NUMBER_OF_ELEMENTS]                 = {1};
    const int expected_result[NUMBER_OF_ELEMENTS] = {1};

    /* Act */
    Average::prefixAverage(array, NUMBER_OF_ELEMENTS);

    /* Assert */
    EXPECT_EQ(0, memcmp(expected_result, array, sizeof(int) * NUMBER_OF_ELEMENTS));
}

TEST(PrefixAverage, Calculate3Elements)
{
    /* Arrange */
#ifdef NUMBER_OF_ELEMENTS
#undef NUMBER_OF_ELEMENTS
#endif /* NUMBER_OF_ELEMENTS */
#define NUMBER_OF_ELEMENTS (5u)

    int array[NUMBER_OF_ELEMENTS]                 = {1, 2, 3, 4, 5};
    const int expected_result[NUMBER_OF_ELEMENTS] = {1, 1, 2, 2, 3};

    /* Act */
    Average::prefixAverage(array, NUMBER_OF_ELEMENTS);

    /* Assert */
    EXPECT_EQ(0, memcmp(expected_result, array, sizeof(int) * NUMBER_OF_ELEMENTS));
}

TEST(FastPrefixAverage, Calculate1Element)
{
    /* Arrange */
#ifdef NUMBER_OF_ELEMENTS
#undef NUMBER_OF_ELEMENTS
#endif /* NUMBER_OF_ELEMENTS */
#define NUMBER_OF_ELEMENTS (1u)

    int array[NUMBER_OF_ELEMENTS]                 = {1};
    const int expected_result[NUMBER_OF_ELEMENTS] = {1};

    /* Act */
    Average::fastPrefixAverage(array, NUMBER_OF_ELEMENTS);

    /* Assert */
    EXPECT_EQ(0, memcmp(expected_result, array, sizeof(int) * NUMBER_OF_ELEMENTS));
}

TEST(FastPrefixAverage, Calculate3Elements)
{
    /* Arrange */
#ifdef NUMBER_OF_ELEMENTS
#undef NUMBER_OF_ELEMENTS
#endif /* NUMBER_OF_ELEMENTS */
#define NUMBER_OF_ELEMENTS (5u)

    int array[NUMBER_OF_ELEMENTS]                 = {1, 2, 3, 4, 5};
    const int expected_result[NUMBER_OF_ELEMENTS] = {1, 1, 2, 2, 3};

    /* Act */
    Average::fastPrefixAverage(array, NUMBER_OF_ELEMENTS);

    /* Assert */
    EXPECT_EQ(0, memcmp(expected_result, array, sizeof(int) * NUMBER_OF_ELEMENTS));
}
