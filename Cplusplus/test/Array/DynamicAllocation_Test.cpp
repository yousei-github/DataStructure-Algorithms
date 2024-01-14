/* Header */
#include <stdint.h>

#include "gtest/gtest.h"

/* Macro */

/* Type */

typedef int instantiationType;

/* Prototype */

/* Variable */

/* Function */

TEST(DynamicAllocation, Matrix)
{
    /**
     * @test 
     * Test the dynamic allocation of matrices
     * 
     * A two-dimensional array is also called a matrix which is an array of row pointers
    */

    /* Arrange */
    const uint32_t rowSize     = 7;
    const uint32_t columnSize  = 24;
    instantiationType** Matrix = {};
    instantiationType element  = {};

    /* Act */
    Matrix                     = new instantiationType*[rowSize]; // Allocate an array of row pointers
    for (size_t row = 0; row < rowSize; row++)
    {
        Matrix[row] = new instantiationType[columnSize]; // Allocate the i-th row

        for (size_t column = 0; column < columnSize; column++)
        {
            Matrix[row][column] = element++;
        }
    }

    /* Assert */
    EXPECT_NE(Matrix, nullptr);

    element = {};
    for (size_t row = 0; row < rowSize; row++)
    {
        for (size_t column = 0; column < columnSize; column++)
        {
            EXPECT_EQ(Matrix[row][column], element) << "Matrix[" << row << "][" << column << "] should be " << element;
            element++;
        }
    }

    /* TearDown */
    for (size_t row = 0; row < rowSize; row++)
    {
        delete[] Matrix[row]; // Delete the i-th row
    }
    delete[] Matrix; // Delete the array of row pointers
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
