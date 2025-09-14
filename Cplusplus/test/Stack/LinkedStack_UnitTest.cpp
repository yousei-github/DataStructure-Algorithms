/* Header */
#include "Stack/LinkedStack.h"
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

TEST(LinkedStack, CopyByConstructor)
{
    /* Arrange */
    Stack::LinkedStack<instantiationType> stackA;
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        stackA.push(i);
    }

    /* Act */
    Stack::LinkedStack<instantiationType> sut(stackA);

    /* Assert */
    EXPECT_EQ(sut.size(), stackA.size());
    for (size_t i = 0; i < sut.size(); i++)
    {
        EXPECT_EQ(sut[i], stackA[i]);
    }
}

TEST(LinkedStack, CopyByOperator)
{
    /* Arrange */
    Stack::LinkedStack<instantiationType> stackA;
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        stackA.push(i);
    }

    Stack::LinkedStack<instantiationType> sut;

    /* Act */
    sut = stackA;

    /* Assert */
    EXPECT_EQ(sut.size(), stackA.size());
    for (size_t i = 0; i < sut.size(); i++)
    {
        EXPECT_EQ(sut[i], stackA[i]);
    }
}

TEST(LinkedStack, SecondCopy)
{
    /* Arrange */
    Stack::LinkedStack<instantiationType> stackA, stackB;
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        stackA.push(i);
    }

    Stack::LinkedStack<instantiationType> sut;

    /* Act */
    sut = stackB = stackA;

    /* Assert */
    EXPECT_EQ(sut.size(), stackA.size());
    for (size_t i = 0; i < sut.size(); i++)
    {
        EXPECT_EQ(sut[i], stackA[i]);
    }
}

TEST(LinkedStack, Empty)
{
    /* Arrange */
    Stack::LinkedStack<instantiationType> sut;

    /* Act */
    bool isEmpty = sut.empty();

    /* Assert */
    EXPECT_TRUE(isEmpty) << "The stack should be empty";
}

TEST(LinkedStack, MaximumSize)
{
    /* Arrange */
    Stack::LinkedStack<instantiationType> sut;
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        sut.push(i);
    }

    /* Act */
    const uint32_t size = sut.size();

    /* Assert */
    EXPECT_EQ(size, instantiationType(Element::Max)) << "The size of stack should be " << instantiationType(Element::Max);
}

TEST(LinkedStack, GetTopElement)
{
    /* Arrange */
    Stack::LinkedStack<instantiationType> sut;
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
    Stack::LinkedStack<instantiationType> sut;
    const instantiationType expect_element = GetParam();

    for (size_t i = instantiationType(Element::One); i < static_cast<size_t>(expect_element); i++)
    {
        sut.push(i);
    }

    /* Act */
    sut.push(expect_element);

    /* Assert */
    EXPECT_EQ(sut[0], expect_element);
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
    Stack::LinkedStack<instantiationType> sut;
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

TEST(LinkedStack, GetThirdElement)
{
    /* Arrange */;
    Stack::LinkedStack<instantiationType> sut;
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        sut.push(i);
    }

    /* Act */
    const instantiationType thirdElement = sut[2];

    /* Assert */
    EXPECT_EQ(thirdElement, instantiationType(Element::One)) << "The third element should be " << instantiationType(Element::One);
}

TEST(LinkedStack, RemoveAllElements)
{
    /* Arrange */
    Stack::LinkedStack<instantiationType> sut;
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        sut.push(i);
    }

    /* Act */
    sut.clear();

    /* Assert */
    EXPECT_EQ(sut.size(), 0) << "The size of stack should be 0";
}

TEST(LinkedStack, TemplatedArguments)
{
    /* Arrange */
    Stack::LinkedStack<instantiationType> stackA;
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        stackA.push(i);
    }

    Stack::LinkedStack<Stack::LinkedStack<instantiationType>> sut;

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
