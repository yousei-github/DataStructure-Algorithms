/* Header */
#include "Array/ElementUniqueness.h"
#include "gtest/gtest.h"

/* Macro */

/* Type */

/* Test */

TEST(ElementUniqueness, True)
{
    /* Arrange */

    const std::vector<int> array = {0, 1, 2};

    /* Act */
    const bool result            = Array::isUnique(array, 0, array.capacity() - 1);

    /* Assert */
    EXPECT_TRUE(result);
}

TEST(ElementUniqueness, False)
{
    /* Arrange */

    const std::vector<int> array = {0, 1, 1};

    /* Act */
    const bool result            = Array::isUnique(array, 0, array.capacity() - 1);

    /* Assert */
    EXPECT_FALSE(result);
}

TEST(FastElementUniqueness, True)
{
    /* Arrange */

    const std::vector<int> array = {0, 1, 2};

    /* Act */
    const bool result            = Array::fastIsUnique(array, 0, array.capacity() - 1);

    /* Assert */
    EXPECT_TRUE(result);
}

TEST(FastElementUniqueness, False)
{
    /* Arrange */

    const std::vector<int> array = {0, 1, 1};

    /* Act */
    const bool result            = Array::fastIsUnique(array, 0, array.capacity() - 1);

    /* Assert */
    EXPECT_FALSE(result);
}

TEST(ElementUniquenessUsingSort, True)
{
    /* Arrange */

    const std::vector<int> array = {0, 1, 2};

    /* Act */
    const bool result            = Array::isUniqueBySort(array, 0, array.capacity() - 1);

    /* Assert */
    EXPECT_TRUE(result);
}

TEST(ElementUniquenessUsingSort, False)
{
    /* Arrange */

    const std::vector<int> array = {0, 1, 1};

    /* Act */
    const bool result            = Array::isUniqueBySort(array, 0, array.capacity() - 1);

    /* Assert */
    EXPECT_FALSE(result);
}
