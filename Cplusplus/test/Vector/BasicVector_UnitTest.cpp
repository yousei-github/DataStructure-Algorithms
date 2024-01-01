/* Header */
#include "Vector/BasicVector.h"
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

TEST(BasicVector, CopyByConstructor)
{
    /* Arrange */
    Vector::BasicVector<instantiationType> vectorA(instantiationType(Element::Max));
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        vectorA[i] = i;
    }

    /* Act */
    Vector::BasicVector<instantiationType> sut(vectorA);

    /* Assert */
    EXPECT_EQ(sut.size(), vectorA.size());
    for (size_t i = 0; i < sut.size(); i++)
    {
        EXPECT_EQ(sut[i], vectorA[i]);
    }
}

TEST(BasicVector, CopyByOperator)
{
    /* Arrange */
    Vector::BasicVector<instantiationType> vectorA(instantiationType(Element::Max));
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        vectorA[i] = i;
    }

    Vector::BasicVector<instantiationType> sut;

    /* Act */
    sut = vectorA;

    /* Assert */
    EXPECT_EQ(sut.size(), vectorA.size());
    for (size_t i = 0; i < sut.size(); i++)
    {
        EXPECT_EQ(sut[i], vectorA[i]);
    }
}

TEST(BasicVector, SecondCopy)
{
    /* Arrange */
    Vector::BasicVector<instantiationType> vectorA(instantiationType(Element::Max)), vectorB;
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        vectorA[i] = i;
    }

    Vector::BasicVector<instantiationType> sut;

    /* Act */
    sut = vectorB = vectorA;

    /* Assert */
    EXPECT_EQ(sut.size(), vectorA.size());
    for (size_t i = 0; i < sut.size(); i++)
    {
        EXPECT_EQ(sut[i], vectorA[i]);
    }
}

TEST(BasicVector, Empty)
{
    /* Arrange */
    Vector::BasicVector<instantiationType> sut(0);

    /* Act */
    bool isEmpty = sut.empty();

    /* Assert */
    EXPECT_TRUE(isEmpty) << "The vector should be empty";
}

TEST(BasicVector, MaximumSize)
{
    /* Arrange */
    Vector::BasicVector<instantiationType> sut(instantiationType(Element::Max));

    /* Act */
    uint32_t size = sut.size();

    /* Assert */
    EXPECT_EQ(size, instantiationType(Element::Max)) << "The size of vector should be " << instantiationType(Element::Max);
}

TEST(BasicVector, GetThirdElement)
{
    /* Arrange */;
    Vector::BasicVector<instantiationType> sut(instantiationType(Element::Max));
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        sut[i] = i;
    }

    /* Act */
    instantiationType thirdElement = sut[2];

    /* Assert */
    EXPECT_EQ(thirdElement, instantiationType(Element::Three)) << "The third element should be " << instantiationType(Element::Three);
}

TEST(BasicVector, RemoveAllElements)
{
    /* Arrange */
    Vector::BasicVector<instantiationType> sut(instantiationType(Element::Max));
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        sut[i] = i;
    }

    /* Act */
    sut.clear();

    /* Assert */
    EXPECT_EQ(sut.size(), 0) << "The size of vector should be 0";
}

TEST(BasicVector, TemplatedArguments)
{
    /* Arrange */
    Vector::BasicVector<instantiationType> vectorA(instantiationType(Element::Max));
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        vectorA[i] = i;
    }

    Vector::BasicVector<Vector::BasicVector<instantiationType>> sut(instantiationType(Element::Max));

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

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
