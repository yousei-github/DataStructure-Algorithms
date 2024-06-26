/* Header */
#include "LinkedList/SinglyLinkedList.h"
#include "gtest/gtest.h"

/* Macro */

/* Type */

typedef int instantiationType;

class SinglyLinkedList_TestSuite : public testing::Test
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

    SinglyLinkedList_TestSuite()
    {
        // You can do set-up work for each test here.
    }

    ~SinglyLinkedList_TestSuite()
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

    // Class members declared here can be used by all tests in the test suite for SinglyLinkedList_TestSuite.

    static std::array<instantiationType, NUMBER_OF_ELEMENTS> elementArray;
};

/* Prototype */

/* Variable */

// Define the shared resource of member variables

std::array<instantiationType, NUMBER_OF_ELEMENTS> SinglyLinkedList_TestSuite::elementArray;

/* Function */

TEST(SinglyLinkedListNode, CopyByConstructor) // @todo
{
    /* Arrange */
    LinkedList::SinglyLinkedListNode<instantiationType> nodeA;
    nodeA.element = instantiationType(2);

    /* Act */
    LinkedList::SinglyLinkedListNode<instantiationType> sut(nodeA);

    /* Assert */
    EXPECT_EQ(sut.element, nodeA.element);
    EXPECT_EQ(sut.next, nodeA.next);
}

TEST(SinglyLinkedListNode, CopyByOperator)
{
    /* Arrange */
    LinkedList::SinglyLinkedListNode<instantiationType> nodeA;
    nodeA.element = instantiationType(2);

    LinkedList::SinglyLinkedListNode<instantiationType> sut;

    /* Act */
    sut = nodeA;

    /* Assert */
    EXPECT_EQ(sut.element, nodeA.element);
    EXPECT_EQ(sut.next, nodeA.next);
}

TEST(SinglyLinkedListNode, SecondCopy)
{
    /* Arrange */
    LinkedList::SinglyLinkedListNode<instantiationType> nodeA, nodeB;
    nodeA.element = instantiationType(2);

    LinkedList::SinglyLinkedListNode<instantiationType> sut;

    /* Act */
    sut = nodeB = nodeA;

    /* Assert */
    EXPECT_EQ(sut.element, nodeA.element);
    EXPECT_EQ(sut.next, nodeA.next);
}

TEST_F(SinglyLinkedList_TestSuite, CopyByConstructor)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> listA;
    for (const auto entry : elementArray)
    {
        listA.addFront(entry);
    }

    /* Act */
    LinkedList::SinglyLinkedList<instantiationType> sut(listA);

    /* Assert */
    EXPECT_EQ(sut.size(), listA.size());
    EXPECT_EQ(sut.front(), listA.front());
    for (size_t index = 0; index < elementArray.size(); index++)
    {
        EXPECT_EQ(sut.get(index), listA.get(index));
    }
}

TEST_F(SinglyLinkedList_TestSuite, CopyByOperator)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> listA;
    for (const auto entry : elementArray)
    {
        listA.addFront(entry);
    }

    LinkedList::SinglyLinkedList<instantiationType> sut;

    /* Act */
    sut = listA;

    /* Assert */
    EXPECT_EQ(sut.size(), listA.size());
    EXPECT_EQ(sut.front(), listA.front());
    for (size_t index = 0; index < elementArray.size(); index++)
    {
        EXPECT_EQ(sut.get(index), listA.get(index));
    }
}

TEST_F(SinglyLinkedList_TestSuite, SecondCopy)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> listA, listB;
    for (const auto entry : elementArray)
    {
        listA.addFront(entry);
    }

    LinkedList::SinglyLinkedList<instantiationType> sut;

    /* Act */
    sut = listB = listA;

    /* Assert */
    EXPECT_EQ(sut.size(), listA.size());
    EXPECT_EQ(sut.front(), listA.front());
    for (size_t index = 0; index < elementArray.size(); index++)
    {
        EXPECT_EQ(sut.get(index), listA.get(index));
    }
}

TEST_F(SinglyLinkedList_TestSuite, Empty)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> sut;

    /* Act */
    bool isEmpty = sut.empty();

    /* Assert */
    EXPECT_TRUE(isEmpty) << "The singly linked list should be empty";
}

TEST_F(SinglyLinkedList_TestSuite, MaximumSize)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> sut;
    for (const auto entry : elementArray)
    {
        sut.addFront(entry);
    }

    /* Act */
    uint32_t size = sut.size();

    /* Assert */
    EXPECT_EQ(size, elementArray.size()) << "The size of singly linked list should be " << elementArray.size();
}

TEST_F(SinglyLinkedList_TestSuite, AddOneNodeInFront)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> sut;
    instantiationType element = elementArray.at(0);

    /* Act */
    sut.addFront(element);

    /* Assert */
    EXPECT_EQ(sut.front(), element) << "The element in the front node should be " << element;
}

TEST_F(SinglyLinkedList_TestSuite, AddSecondNodeInFront)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> sut;
    instantiationType elementOne = elementArray.at(0);
    sut.addFront(elementOne);

    instantiationType elementTwo = elementArray.at(1);

    /* Act */
    sut.addFront(elementTwo);

    /* Assert */
    EXPECT_EQ(sut.front(), elementTwo) << "The element in the front node should be " << elementTwo;
}

TEST_F(SinglyLinkedList_TestSuite, GetThirdNode)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> sut;
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

TEST_F(SinglyLinkedList_TestSuite, RemoveFrontNode)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> sut;
    instantiationType elementOne = elementArray.at(0);
    sut.addFront(elementOne);
    instantiationType elementTwo = elementArray.at(1);
    sut.addFront(elementTwo);

    /* Act */
    sut.removeFront();

    /* Assert */
    EXPECT_EQ(sut.front(), elementOne) << "The element in the front node should be " << elementOne;
}

TEST_F(SinglyLinkedList_TestSuite, RemoveAllNodes)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> sut;
    for (const auto entry : elementArray)
    {
        sut.addFront(entry);
    }

    /* Act */
    sut.clear();

    /* Assert */
    EXPECT_EQ(sut.size(), 0) << "The size of singly linked list should be 0";
}

TEST_F(SinglyLinkedList_TestSuite, ReverseList)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> sut;
    for (const auto entry : elementArray)
    {
        sut.addFront(entry);
    }

    /* Act */
    LinkedList::SinglyLinkedList<instantiationType>::reverseList(sut);

    /* Assert */
    for (size_t index = 0; index < elementArray.size(); index++)
    {
        EXPECT_EQ(sut.get(index), elementArray.at(index));
    }
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
