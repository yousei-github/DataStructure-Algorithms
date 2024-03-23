/* Header */
#include <array>

#include "LinkedList/CircularlyDoublyLinkedList.h"
#include "gtest/gtest.h"

/* Macro */

/* Type */

typedef int instantiationType;

class CircularlyDoublyLinkedList_TestSuite : public testing::Test
{
#define NUMBER_OF_ELEMENTS (50)

public:
    /**
     * Per-test-suite set-up.
     * Called before the first test in this test suite.
     * Can be omitted if not needed.
     */
    static void SetUpTestSuite()
    {
        instantiationType elementOne = 0;
        for (size_t index = 0; index < elementArray.size(); index++)
        {
            elementArray[index] = elementOne;
            elementOne += 2;
        }
    }

    /**
     * Per-test-suite tear-down.
     * Called after the last test in this test suite.
     * Can be omitted if not needed.
     */
    static void TearDownTestSuite()
    {
    }

protected:
    // You can remove any or all of the following functions if their bodies would be empty.

    CircularlyDoublyLinkedList_TestSuite()
    {
        // You can do set-up work for each test here.
    }

    ~CircularlyDoublyLinkedList_TestSuite()
    {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up and cleaning up each test, you can define the following methods:
    void SetUp() override
    {
        // Code here will be called immediately after the constructor (right before each test, which means the per-test set-up).
    }

    void TearDown() override
    {
        // Code here will be called immediately after each test (right before the destructor, which means the per-test tear-down).
    }

    // Class members declared here can be used by all tests in the test suite for CircularlyDoublyLinkedList_TestSuite.

    static std::array<instantiationType, NUMBER_OF_ELEMENTS> elementArray;
};

/* Prototype */

/* Variable */

// Define the shared resource of member variables

std::array<instantiationType, NUMBER_OF_ELEMENTS> CircularlyDoublyLinkedList_TestSuite::elementArray;

/* Function */

TEST_F(CircularlyDoublyLinkedList_TestSuite, CopyByConstructor)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> listA;
    for (const auto entry : elementArray)
    {
        listA.add(entry);
    }

    /* Act */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut(listA);

    /* Assert */
    EXPECT_EQ(sut.size(), listA.size());
    EXPECT_EQ(sut.front(), listA.front());
    EXPECT_EQ(sut.back(), listA.back());
    for (size_t index = 0; index < elementArray.size(); index++)
    {
        EXPECT_EQ(sut.get(index), listA.get(index));
    }
}

TEST_F(CircularlyDoublyLinkedList_TestSuite, CopyByOperator)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> listA;
    for (const auto entry : elementArray)
    {
        listA.add(entry);
    }

    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;

    /* Act */
    sut = listA;

    /* Assert */
    EXPECT_EQ(sut.size(), listA.size());
    EXPECT_EQ(sut.front(), listA.front());
    EXPECT_EQ(sut.back(), listA.back());
    for (size_t index = 0; index < elementArray.size(); index++)
    {
        EXPECT_EQ(sut.get(index), listA.get(index));
    }
}

TEST_F(CircularlyDoublyLinkedList_TestSuite, SecondCopy)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> listA, listB;
    for (const auto entry : elementArray)
    {
        listA.add(entry);
    }

    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;

    /* Act */
    sut = listB = listA;

    /* Assert */
    EXPECT_EQ(sut.size(), listA.size());
    EXPECT_EQ(sut.front(), listA.front());
    EXPECT_EQ(sut.back(), listA.back());
    for (size_t index = 0; index < elementArray.size(); index++)
    {
        EXPECT_EQ(sut.get(index), listA.get(index));
    }
}

TEST(CircularlyDoublyLinkedList, Empty)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;

    /* Act */
    bool isEmpty = sut.empty();

    /* Assert */
    EXPECT_TRUE(isEmpty) << "The circularly doubly linked list should be empty";
}

TEST_F(CircularlyDoublyLinkedList_TestSuite, MaximumSize)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;
    for (const auto entry : elementArray)
    {
        sut.add(entry);
    }

    /* Act */
    uint32_t size = sut.size();

    /* Assert */
    EXPECT_EQ(size, elementArray.size()) << "The size of circularly doubly linked list should be " << elementArray.size();
}

TEST_F(CircularlyDoublyLinkedList_TestSuite, AdvanceOneStep)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;
    for (const auto entry : elementArray)
    {
        sut.addBack(entry);
    }

    /* Act */
    sut.advance();

    /* Assert */
    EXPECT_EQ(sut.size(), elementArray.size());
    EXPECT_EQ(sut.front(), elementArray.at(1));
    EXPECT_EQ(sut.back(), elementArray.at(0));
}

TEST_F(CircularlyDoublyLinkedList_TestSuite, RetreatOneStep)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;
    for (const auto entry : elementArray)
    {
        sut.addBack(entry);
    }

    /* Act */
    sut.retreat();

    /* Assert */
    EXPECT_EQ(sut.size(), elementArray.size());
    EXPECT_EQ(sut.front(), elementArray.back());
    EXPECT_EQ(sut.back(), elementArray.at(elementArray.size() - 2));
}

TEST_F(CircularlyDoublyLinkedList_TestSuite, AddOneNode)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;
    instantiationType element = elementArray.at(0);

    /* Act */
    sut.add(element);

    /* Assert */
    EXPECT_EQ(sut.front(), element) << "The element in the front node should be " << element;
}

TEST_F(CircularlyDoublyLinkedList_TestSuite, RemoveOneNode)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;
    instantiationType elementOne = elementArray.at(0);
    sut.addFront(elementOne);
    instantiationType elementTwo = elementArray.at(1);
    sut.addFront(elementTwo);

    /* Act */
    sut.remove();

    /* Assert */
    EXPECT_EQ(sut.front(), elementOne) << "The element in the front node should be " << elementOne;
}

TEST_F(CircularlyDoublyLinkedList_TestSuite, AddOneNodeInFront)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;
    instantiationType element = elementArray.at(0);

    /* Act */
    sut.addFront(element);

    /* Assert */
    EXPECT_EQ(sut.front(), element) << "The element in the front node should be " << element;
}

TEST_F(CircularlyDoublyLinkedList_TestSuite, AddOneNodeInBack)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;
    instantiationType element = elementArray.at(1);

    /* Act */
    sut.addBack(element);

    /* Assert */
    EXPECT_EQ(sut.back(), element) << "The element in the back node should be " << element;
}

TEST_F(CircularlyDoublyLinkedList_TestSuite, AddSecondNodeInFront)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;
    instantiationType elementOne = elementArray.at(0);
    sut.addFront(elementOne);

    instantiationType elementTwo = elementArray.at(1);

    /* Act */
    sut.addFront(elementTwo);

    /* Assert */
    EXPECT_EQ(sut.front(), elementTwo) << "The element in the front node should be " << elementTwo;
}

TEST_F(CircularlyDoublyLinkedList_TestSuite, AddSecondNodeInBack)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;
    instantiationType elementOne = elementArray.at(0);
    sut.addBack(elementOne);

    instantiationType elementTwo = elementArray.at(1);

    /* Act */
    sut.addBack(elementTwo);

    /* Assert */
    EXPECT_EQ(sut.back(), elementTwo) << "The element in the back node should be " << elementTwo;
}

TEST_F(CircularlyDoublyLinkedList_TestSuite, GetThirdNode)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;
    instantiationType elementOne = elementArray.at(0);
    sut.addFront(elementOne);
    instantiationType elementTwo = elementArray.at(1);
    sut.addFront(elementTwo);
    instantiationType elementThree = elementArray.at(2);
    sut.addFront(elementThree);

    /* Act */
    instantiationType thirdNode = sut.get(2);

    /* Assert */
    EXPECT_EQ(thirdNode, elementOne) << "The element in the third node should be " << elementOne;
}

TEST_F(CircularlyDoublyLinkedList_TestSuite, RemoveFrontNode)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;
    instantiationType elementOne = elementArray.at(0);
    sut.addFront(elementOne);
    instantiationType elementTwo = elementArray.at(1);
    sut.addFront(elementTwo);

    /* Act */
    sut.removeFront();

    /* Assert */
    EXPECT_EQ(sut.front(), elementOne) << "The element in the front node should be " << elementOne;
}

TEST_F(CircularlyDoublyLinkedList_TestSuite, RemoveBackNode)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;
    instantiationType elementOne = elementArray.at(0);
    sut.addFront(elementOne);
    instantiationType elementTwo = elementArray.at(1);
    sut.addFront(elementTwo);

    /* Act */
    sut.removeBack();

    /* Assert */
    EXPECT_EQ(sut.front(), elementTwo) << "The element in the front node should be " << elementTwo;
}

TEST_F(CircularlyDoublyLinkedList_TestSuite, RemoveAllNodes)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;
    for (const auto entry : elementArray)
    {
        sut.add(entry);
    }

    /* Act */
    sut.clear();

    /* Assert */
    EXPECT_EQ(sut.size(), 0) << "The size of doubly linked list should be 0";
}

TEST_F(CircularlyDoublyLinkedList_TestSuite, ReverseList)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;
    for (const auto entry : elementArray)
    {
        sut.addBack(entry);
    }

    /* Act */
    LinkedList::CircularlyDoublyLinkedList<instantiationType>::reverseList(sut);

    /* Assert */
    for (size_t index = 0; index < elementArray.size(); index++)
    {
        EXPECT_EQ(sut.get(index), elementArray.at(elementArray.size() - index - 1));
    }
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
