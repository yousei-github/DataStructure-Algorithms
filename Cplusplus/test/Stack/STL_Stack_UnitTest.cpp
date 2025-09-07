/* Header */
#include <stack>

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

TEST(STL_Stack, CopyByConstructor)
{
    /* Arrange */
    std::stack<instantiationType> stackA;
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        stackA.push(i);
    }

    /* Act */
    std::stack<instantiationType> sut(stackA);

    /* Assert */
    EXPECT_EQ(sut.size(), stackA.size());
    EXPECT_EQ(sut, stackA);
}

TEST(STL_Stack, CopyByOperator)
{
    /* Arrange */
    std::stack<instantiationType> stackA;
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        stackA.push(i);
    }

    std::stack<instantiationType> sut;

    /* Act */
    sut = stackA;

    /* Assert */
    EXPECT_EQ(sut.size(), stackA.size());
    EXPECT_EQ(sut, stackA);
}

TEST(STL_Stack, SecondCopy)
{
    /* Arrange */
    std::stack<instantiationType> stackA, stackB;
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        stackA.push(i);
    }

    std::stack<instantiationType> sut;

    /* Act */
    sut = stackB = stackA;

    /* Assert */
    EXPECT_EQ(sut.size(), stackA.size());
    EXPECT_EQ(sut, stackA);
}

TEST(STL_Stack, Empty)
{
    /* Arrange */
    std::stack<instantiationType> sut;

    /* Act */
    bool isEmpty = sut.empty();

    /* Assert */
    EXPECT_TRUE(isEmpty) << "The stack should be empty";
}

TEST(STL_Stack, MaximumSize)
{
    /* Arrange */
    std::stack<instantiationType> sut;
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        sut.push(i);
    }

    /* Act */
    const uint32_t size = sut.size();

    /* Assert */
    EXPECT_EQ(size, instantiationType(Element::Max)) << "The size of stack should be " << instantiationType(Element::Max);
}

TEST(STL_Stack, GetTopElement)
{
    /* Arrange */
    std::stack<instantiationType> sut;
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
    std::stack<instantiationType> sut;
    const instantiationType expect_element = GetParam();

    for (size_t i = instantiationType(Element::One); i < static_cast<size_t>(expect_element); i++)
    {
        sut.push(i);
    }

    /* Act */
    sut.push(expect_element);

    /* Assert */
    EXPECT_EQ(sut.top(), expect_element);
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
    std::stack<instantiationType> sut;
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

TEST(STL_Stack, TemplatedArguments)
{
    /* Arrange */
    std::stack<instantiationType> stackA;
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        stackA.push(i);
    }

    std::stack<std::stack<instantiationType>> sut;

    /* Act */
    for (size_t row = instantiationType(Element::One); row < instantiationType(Element::Max); row++)
    {
        sut.push(stackA);
    }

    /* Assert */
    for (size_t row = instantiationType(Element::One); row < instantiationType(Element::Max); row++)
    {
        EXPECT_EQ(sut.top().size(), stackA.size());
        EXPECT_EQ(sut.top(), stackA);
    }
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
