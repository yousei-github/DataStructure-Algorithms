/* Header */
#include <stdlib.h>
#include <string.h>

#include "SortingAlgorithm/InsertionSort.h"
#include "gtest/gtest.h"

/* Macro */

/* Type */

typedef int instantiationType;

class InsertionSorting : public testing::Test
{
protected:
    // You can remove any or all of the following functions if their bodies would be empty.

    InsertionSorting()
    {
        // You can do set-up work for each test here.
    }

    ~InsertionSorting()
    {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up and cleaning up each test, you can define the following methods:
    void SetUp() override
    {
        // Code here will be called immediately after the constructor (right before each test, which means the per-test set-up).

        ascendingOrderArray  = new instantiationType[arrayLength];
        descendingOrderArray = new instantiationType[arrayLength];

        for (size_t index = 0; index < arrayLength; index++)
        {
            ascendingOrderArray[index]  = index;
            descendingOrderArray[index] = arrayLength - index - 1;
        }
    }

    void TearDown() override
    {
        // Code here will be called immediately after each test (right before the destructor, which means the per-test tear-down).

        delete[] ascendingOrderArray;
        delete[] descendingOrderArray;

        descendingOrderArray = {};
        ascendingOrderArray  = {};
    }

    // Class members declared here can be used by all tests in the test suite for InsertionSorting fixture class.
    instantiationType* ascendingOrderArray  = {};
    instantiationType* descendingOrderArray = {};
    const uint32_t arrayLength              = 128;
};

/* Prototype */

/* Variable */

/* Function */

TEST_F(InsertionSorting, SortAArrayInAscendingOrder)
{
    /* Arrange */
    const instantiationType* expectResult = ascendingOrderArray;

    /* Act */
    SortingAlgorithm::insertionSort<instantiationType>(descendingOrderArray, arrayLength);

    /* Assert */
    for (size_t index = 0; index < arrayLength; index++)
    {
        EXPECT_EQ(descendingOrderArray[index], expectResult[index]);
    }
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
