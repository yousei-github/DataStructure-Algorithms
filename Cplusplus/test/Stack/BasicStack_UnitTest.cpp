/* Header */
#include "Stack/BasicStack.h"
#include "gtest/gtest.h"

// C standard libraries:
#include <stddef.h>

/* Type */

typedef int instantiationType;

enum class Element : instantiationType
{
    One = 0,
    Two,
    Three,
    Max
};

/* Test case */

TEST(BasicStack, CopyByConstructor)
{
    /* Arrange */
    Stack::BasicStack<instantiationType> stackA(instantiationType(Element::Max));
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        stackA.push(i);
    }

    /* Act */
    Stack::BasicStack<instantiationType> sut(stackA);

    /* Assert */
    EXPECT_EQ(sut.size(), stackA.size());
    for (size_t i = 0; i < sut.size(); i++)
    {
        EXPECT_EQ(sut[i], stackA[i]);
    }
}

TEST(BasicStack, CopyByOperator)
{
    /* Arrange */
    Stack::BasicStack<instantiationType> stackA(instantiationType(Element::Max));
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        stackA.push(i);
    }

    Stack::BasicStack<instantiationType> sut;

    /* Act */
    sut = stackA;

    /* Assert */
    EXPECT_EQ(sut.size(), stackA.size());
    for (size_t i = 0; i < sut.size(); i++)
    {
        EXPECT_EQ(sut[i], stackA[i]);
    }
}

TEST(BasicStack, SecondCopy)
{
    /* Arrange */
    Stack::BasicStack<instantiationType> stackA(instantiationType(Element::Max)), stackB;
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        stackA.push(i);
    }

    Stack::BasicStack<instantiationType> sut;

    /* Act */
    sut = stackB = stackA;

    /* Assert */
    EXPECT_EQ(sut.size(), stackA.size());
    for (size_t i = 0; i < sut.size(); i++)
    {
        EXPECT_EQ(sut[i], stackA[i]);
    }
}

TEST(BasicStack, Empty)
{
    /* Arrange */
    Stack::BasicStack<instantiationType> sut;

    /* Act */
    bool isEmpty = sut.empty();

    /* Assert */
    EXPECT_TRUE(isEmpty) << "The stack should be empty";
}

TEST(BasicStack, MaximumSize)
{
    /* Arrange */
    Stack::BasicStack<instantiationType> sut(instantiationType(Element::Max));
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        sut.push(i);
    }

    /* Act */
    const uint32_t size = sut.size();

    /* Assert */
    EXPECT_EQ(size, instantiationType(Element::Max)) << "The size of stack should be " << instantiationType(Element::Max);
}

TEST(BasicStack, MaximumCapacity)
{
    /* Arrange */
    Stack::BasicStack<instantiationType> sut(instantiationType(Element::Max));

    /* Act */
    const uint32_t capacity = sut.capacity();

    /* Assert */
    EXPECT_EQ(capacity, instantiationType(Element::Max)) << "The capacity of stack should be " << instantiationType(Element::Max);
}

TEST(BasicStack, GetTopElement)
{
    /* Arrange */
    Stack::BasicStack<instantiationType> sut(instantiationType(Element::Max));
    sut.push(instantiationType(Element::One));

    /* Act */
    const instantiationType top_element = sut.top();

    /* Assert */
    EXPECT_EQ(top_element, instantiationType(Element::One)) << "The top element of stack should be " << instantiationType(Element::One);
}

class PushParameterizedTest : public testing ::TestWithParam<instantiationType>
{
    // No code here
};

INSTANTIATE_TEST_SUITE_P(InstantiationOne, PushParameterizedTest, testing::Range(instantiationType(Element::One), instantiationType(Element::Max)));

TEST_P(PushParameterizedTest, PushElement)
{
    /* Arrange */
    Stack::BasicStack<instantiationType> sut(instantiationType(Element::Max));
    const instantiationType expect_element = GetParam();

    for (size_t i = instantiationType(Element::One); i < static_cast<size_t>(expect_element); i++)
    {
        sut.push(i);
    }

    /* Act */
    sut.push(expect_element);

    /* Assert */
    EXPECT_EQ(sut[expect_element], expect_element);
    EXPECT_EQ(sut.size(), expect_element + 1);
}

class PopParameterizedTest : public PushParameterizedTest
{
    // No code here
};

INSTANTIATE_TEST_SUITE_P(InstantiationOne, PopParameterizedTest, testing::Range(instantiationType(Element::One), instantiationType(Element::Max)));

TEST_P(PopParameterizedTest, PopElement)
{
    /* Arrange */
    Stack::BasicStack<instantiationType> sut(instantiationType(Element::Max));
    const instantiationType expect_element = GetParam();

    for (size_t i = instantiationType(Element::One); i <= static_cast<size_t>(expect_element); i++)
    {
        sut.push(i);
    }

    /* Act */
    sut.pop();

    /* Assert */
    EXPECT_EQ(sut.size(), expect_element);
}

TEST(BasicStack, GetThirdElement)
{
    /* Arrange */;
    Stack::BasicStack<instantiationType> sut(instantiationType(Element::Max));
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        sut.push(i);
    }

    /* Act */
    const instantiationType thirdElement = sut[2];

    /* Assert */
    EXPECT_EQ(thirdElement, instantiationType(Element::Three)) << "The third element should be " << instantiationType(Element::Three);
}

TEST(BasicStack, RemoveAllElements)
{
    /* Arrange */
    Stack::BasicStack<instantiationType> sut(instantiationType(Element::Max));
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        sut.push(i);
    }

    /* Act */
    sut.clear();

    /* Assert */
    EXPECT_EQ(sut.size(), 0) << "The size of stack should be 0";
}

TEST(BasicStack, TemplatedArguments)
{
    /* Arrange */
    Stack::BasicStack<instantiationType> stackA(instantiationType(Element::Max));
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        stackA.push(i);
    }

    Stack::BasicStack<Stack::BasicStack<instantiationType>> sut(instantiationType(Element::Max));

    /* Act */
    for (size_t row = instantiationType(Element::One); row < instantiationType(Element::Max); row++)
    {
        sut.push(stackA);
    }

    /* Assert */
    for (size_t row = instantiationType(Element::One); row < instantiationType(Element::Max); row++)
    {
        EXPECT_EQ(sut[row].size(), stackA.size());
        for (size_t column = instantiationType(Element::One); column < instantiationType(Element::Max); column++)
        {
            EXPECT_EQ(sut[row][column], stackA[column]);
        }
    }
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
