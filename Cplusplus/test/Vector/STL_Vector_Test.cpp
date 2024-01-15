/* Header */
#include <vector>

#include "gtest/gtest.h"

/* Macro */

/* Type */

typedef int instantiationType;

enum class Element : instantiationType
{
    One = 0,
    Two,
    Three,
    Max
};

/* Prototype */

/* Variable */

/* Function */

TEST(STL_Vector, CopyByConstructor)
{
    /* Arrange */
    std::vector<instantiationType> vectorA(instantiationType(Element::Max));
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        vectorA[i] = i;
    }

    /* Act */
    std::vector<instantiationType> sut(vectorA);

    /* Assert */
    EXPECT_EQ(sut.size(), vectorA.size());
    for (size_t i = 0; i < sut.size(); i++)
    {
        EXPECT_EQ(sut[i], vectorA[i]);
    }
}

TEST(STL_Vector, CopyByOperator)
{
    /* Arrange */
    std::vector<instantiationType> vectorA(instantiationType(Element::Max));
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        vectorA[i] = i;
    }

    std::vector<instantiationType> sut;

    /* Act */
    sut = vectorA;

    /* Assert */
    EXPECT_EQ(sut.size(), vectorA.size());
    for (size_t i = 0; i < sut.size(); i++)
    {
        EXPECT_EQ(sut[i], vectorA[i]);
    }
}

TEST(STL_Vector, SecondCopy)
{
    /* Arrange */
    std::vector<instantiationType> vectorA(instantiationType(Element::Max)), vectorB;
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        vectorA[i] = i;
    }

    std::vector<instantiationType> sut;

    /* Act */
    sut = vectorB = vectorA;

    /* Assert */
    EXPECT_EQ(sut.size(), vectorA.size());
    for (size_t i = 0; i < sut.size(); i++)
    {
        EXPECT_EQ(sut[i], vectorA[i]);
    }
}

TEST(STL_Vector, Empty)
{
    /* Arrange */
    std::vector<instantiationType> sut(0);

    /* Act */
    bool isEmpty = sut.empty();

    /* Assert */
    EXPECT_TRUE(isEmpty) << "The vector should be empty";
}

TEST(STL_Vector, MaximumSize)
{
    /* Arrange */
    std::vector<instantiationType> sut(instantiationType(Element::Max));

    /* Act */
    uint32_t size = sut.size();

    /* Assert */
    EXPECT_EQ(size, instantiationType(Element::Max)) << "The size of vector should be " << instantiationType(Element::Max);
}

TEST(STL_Vector, GetThirdElement)
{
    /* Arrange */;
    std::vector<instantiationType> sut(instantiationType(Element::Max));
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        sut[i] = i;
    }

    /* Act */
    instantiationType thirdElement = sut[2];

    /* Assert */
    EXPECT_EQ(thirdElement, instantiationType(Element::Three)) << "The third element should be " << instantiationType(Element::Three);
}

TEST(STL_Vector, RemoveAllElements)
{
    /* Arrange */
    std::vector<instantiationType> sut(instantiationType(Element::Max));
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        sut[i] = i;
    }

    /* Act */
    sut.clear();

    /* Assert */
    EXPECT_EQ(sut.size(), 0) << "The size of vector should be 0";
}

TEST(STL_Vector, TemplatedArguments)
{
    /* Arrange */
    std::vector<instantiationType> vectorA(instantiationType(Element::Max));
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        vectorA[i] = i;
    }

    std::vector<std::vector<instantiationType>> sut(instantiationType(Element::Max));

    /* Act */
    for (size_t row = instantiationType(Element::One); row < instantiationType(Element::Max); row++)
    {
        sut[row] = vectorA;
    }

    /* Assert */
    for (size_t row = instantiationType(Element::One); row < instantiationType(Element::Max); row++)
    {
        EXPECT_EQ(sut[row].size(), vectorA.size());
        for (size_t column = instantiationType(Element::One); column < instantiationType(Element::Max); column++)
        {
            EXPECT_EQ(sut[row][column], vectorA[column]);
        }
    }
}

TEST(STL_Vector, Matrix)
{
    /**
     * @test
     * Test the STL vector-based matrix implementation
     * 
     * A two-dimensional array is also called a matrix which is an array of row pointers
    */

    /* Arrange */
    const uint32_t rowSize    = 7;
    const uint32_t columnSize = 24;
    instantiationType element = {};

    /* Act */
    std::vector<std::vector<instantiationType>> matrix(rowSize, std::vector<instantiationType>(columnSize));

    /* Assert */
    for (auto& rowEntry : matrix)
    {
        for (auto& columnEntry : rowEntry)
        {
            columnEntry = element++;
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
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
