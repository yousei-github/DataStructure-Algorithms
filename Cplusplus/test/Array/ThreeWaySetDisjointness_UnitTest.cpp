/* Header */
#include "Array/ThreeWaySetDisjointness.h"
#include "gtest/gtest.h"

/* Macro */

/* Type */

/* Test */

TEST(ThreeWaySetDisjointness, True)
{
    /* Arrange */

    const std::vector<int> setA = {0, 1, 2};
    const std::vector<int> setB = {3, 4, 5};
    const std::vector<int> setC = {6, 7, 8};

    /* Act */
    const bool result           = Array::areDisjoint(setA, setB, setC);

    /* Assert */
    EXPECT_TRUE(result);
}

TEST(ThreeWaySetDisjointness, False)
{
    /* Arrange */

    const std::vector<int> setA = {0, 1, 2};
    const std::vector<int> setB = {3, 2, 4};
    const std::vector<int> setC = {2, 5, 6};

    /* Act */
    const bool result           = Array::areDisjoint(setA, setB, setC);

    /* Assert */
    EXPECT_FALSE(result);
}
