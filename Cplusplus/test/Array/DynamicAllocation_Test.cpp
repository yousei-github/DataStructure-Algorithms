/* Header */
#include <stdint.h>

#include "gtest/gtest.h"

/* Macro */

/* Type */

typedef int instantiationType;

/* Prototype */

/* Variable */

/* Function */

/**
 * @test 
 * Test the dynamic allocation of matrices
 * 
 * A two-dimensional array is also called a matrix which is an array of row pointers
*/
TEST(DynamicAllocation, Matrix)
{
    /* Arrange */
    const uint32_t rowSize     = 7;
    const uint32_t columnSize  = 24;
    instantiationType** matrix = {};
    instantiationType element  = {};

    /* Act */
    matrix                     = new instantiationType*[rowSize]; // Allocate an array of row pointers
    for (size_t row = 0; row < rowSize; row++)
    {
        matrix[row] = new instantiationType[columnSize]; // Allocate the i-th row
    }

    /* Assert */
    EXPECT_NE(matrix, nullptr);

    // Store elements in the matrix
    for (size_t row = 0; row < rowSize; row++)
    {
        for (size_t column = 0; column < columnSize; column++)
        {
            matrix[row][column] = element++;
        }
    }

    element = {};
    for (size_t row = 0; row < rowSize; row++)
    {
        for (size_t column = 0; column < columnSize; column++)
        {
            EXPECT_EQ(matrix[row][column], element) << "Matrix[" << row << "][" << column << "] should be " << element;
            element++;
        }
    }

    /* TearDown */
    for (size_t row = 0; row < rowSize; row++)
    {
        delete[] matrix[row]; // Delete the i-th row
    }
    delete[] matrix; // Delete the array of row pointers
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
