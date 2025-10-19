/* Header */
#include "LinkedList/SinglyLinkedList_UsingStaticMemoryAllocation.h"
#include "gtest/gtest.h"

// C standard libraries:
#include <stddef.h>

/* Macro */

/* Type */

typedef int instantiationType;

class StaticSinglyLinkedList_TestSuite : public testing::Test
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

    StaticSinglyLinkedList_TestSuite()
    {
        // You can do set-up work for each test here.
    }

    ~StaticSinglyLinkedList_TestSuite()
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

    // Class members declared here can be used by all tests in the test suite for StaticSinglyLinkedList_TestSuite.

    static std::array<instantiationType, NUMBER_OF_ELEMENTS> elementArray;
};

/* Prototype */

/* Variable */

// Define the shared resource of member variables

std::array<instantiationType, NUMBER_OF_ELEMENTS> StaticSinglyLinkedList_TestSuite::elementArray;

/* Function */

TEST(StaticSinglyLinkedListNode, CopyByConstructor)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> nodeA;
    nodeA.element = instantiationType(2);

    /* Act */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> sut(nodeA);

    /* Assert */
    EXPECT_EQ(sut.element, nodeA.element);
    EXPECT_EQ(sut.next_index, nodeA.next_index);
}

TEST(StaticSinglyLinkedListNode, CopyByOperator)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> nodeA;
    nodeA.element = instantiationType(2);

    LinkedList::StaticSinglyLinkedListNode<instantiationType> sut;

    /* Act */
    sut = nodeA;

    /* Assert */
    EXPECT_EQ(sut.element, nodeA.element);
    EXPECT_EQ(sut.next_index, nodeA.next_index);
}

TEST(StaticSinglyLinkedListNode, SecondCopy)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> nodeA, nodeB;
    nodeA.element = instantiationType(2);

    LinkedList::StaticSinglyLinkedListNode<instantiationType> sut;

    /* Act */
    sut = nodeB = nodeA;

    /* Assert */
    EXPECT_EQ(sut.element, nodeA.element);
    EXPECT_EQ(sut.next_index, nodeA.next_index);
}

TEST_F(StaticSinglyLinkedList_TestSuite, Empty)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);

    /* Act */
    const bool isEmpty = sut.empty();

    /* Assert */
    EXPECT_TRUE(isEmpty) << "The singly linked list should be empty";
    EXPECT_EQ(sut.headIndex(), static_cast<uint32_t>(LinkedList::StaticSinglyLinkedList<instantiationType>::ArrayIndex::END_NODE_INDEX)) << "The head index of singly linked list should be invalid";
    EXPECT_EQ(freeList.size(), NUMBER_OF_ELEMENTS) << "The size of free linked list should be " << NUMBER_OF_ELEMENTS;

    /* Clean Up */
    sut.clear(freeList);
}

TEST_F(StaticSinglyLinkedList_TestSuite, MaximumSize)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    for (const auto entry : elementArray)
    {
        sut.addFront(freeList, entry);
    }

    /* Act */
    const uint32_t size = sut.size();

    /* Assert */
    EXPECT_EQ(size, elementArray.size()) << "The size of singly linked list should be " << elementArray.size();
    EXPECT_EQ(sut.headIndex(), NUMBER_OF_ELEMENTS - 1) << "The head index of singly linked list should be " << NUMBER_OF_ELEMENTS - 1;
    EXPECT_EQ(freeList.size(), 0) << "The size of free linked list should be 0";

    /* Clean Up */
    sut.clear(freeList);
}

TEST_F(StaticSinglyLinkedList_TestSuite, GetFront)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    for (const auto entry : elementArray)
    {
        sut.addFront(freeList, entry);
    }

    /* Act */
    const LinkedList::StaticSinglyLinkedListNode<instantiationType> front = sut.front();

    /* Assert */
    EXPECT_EQ(front.element, elementArray.at(NUMBER_OF_ELEMENTS - 1));

    /* Clean Up */
    sut.clear(freeList);
}

TEST_F(StaticSinglyLinkedList_TestSuite, GetThirdNode)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    const instantiationType elementOne = elementArray.at(0);
    sut.addFront(freeList, elementOne);
    const instantiationType elementTwo = elementArray.at(1);
    sut.addFront(freeList, elementTwo);
    const instantiationType elementThree = elementArray.at(2);
    sut.addFront(freeList, elementThree);

    /* Act */
    const instantiationType thirdNode = sut.get(2).element;

    /* Assert */
    EXPECT_EQ(thirdNode, elementOne) << "The element in the third node should be " << elementOne;

    /* Clean Up */
    sut.clear(freeList);
}

TEST_F(StaticSinglyLinkedList_TestSuite, GetHeadIndex)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    for (const auto entry : elementArray)
    {
        sut.addFront(freeList, entry);
    }

    // Remove 1st node
    LinkedList::StaticSinglyLinkedListNode<instantiationType>* node = {};
    uint32_t nodeIndex                                              = {};
    sut.remove(0, node, nodeIndex);

    /* Act */
    const uint32_t headIndex = sut.headIndex();

    /* Assert */
    EXPECT_EQ(headIndex, NUMBER_OF_ELEMENTS - 2) << "The head index of singly linked list should be " << NUMBER_OF_ELEMENTS - 2;

    /* Clean Up */
    sut.clear(freeList);
}

TEST_F(StaticSinglyLinkedList_TestSuite, AddOneNodeInFrontFromFreeList)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    const instantiationType element = elementArray.at(0);

    /* Act */
    sut.addFront(freeList, element);

    /* Assert */
    EXPECT_EQ(sut.front().element, element) << "The element in the front node should be " << element;
    EXPECT_EQ(sut.size(), 1) << "The size of singly linked list should be " << 1;
    EXPECT_EQ(sut.headIndex(), 0) << "The head index of singly linked list should be 0";
    EXPECT_EQ(freeList.size(), NUMBER_OF_ELEMENTS - 1) << "The size of free linked list should be " << NUMBER_OF_ELEMENTS - 1;

    /* Clean Up */
    sut.clear(freeList);
}

TEST_F(StaticSinglyLinkedList_TestSuite, AddSecondNodeInFrontFromFreeList)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    const instantiationType elementOne = elementArray.at(0);
    sut.addFront(freeList, elementOne);

    const instantiationType elementTwo = elementArray.at(1);

    /* Act */
    sut.addFront(freeList, elementTwo);

    /* Assert */
    EXPECT_EQ(sut.front().element, elementTwo) << "The element in the front node should be " << elementTwo;
    EXPECT_EQ(sut.size(), 2) << "The size of singly linked list should be " << 2;
    EXPECT_EQ(sut.headIndex(), 1) << "The head index of singly linked list should be 1";
    EXPECT_EQ(freeList.size(), NUMBER_OF_ELEMENTS - 2) << "The size of free linked list should be " << NUMBER_OF_ELEMENTS - 2;

    /* Clean Up */
    sut.clear(freeList);
}

TEST_F(StaticSinglyLinkedList_TestSuite, AddOneNodeInFront)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    const instantiationType element                                 = elementArray.at(0);

    LinkedList::StaticSinglyLinkedListNode<instantiationType>* node = {};
    uint32_t nodeIndex                                              = {};
    freeList.removeFront(node, nodeIndex);

    /* Act */
    sut.addFront(*node, nodeIndex, element);

    /* Assert */
    EXPECT_EQ(sut.front().element, element) << "The element in the front node should be " << element;
    EXPECT_EQ(sut.size(), 1) << "The size of singly linked list should be " << 1;
    EXPECT_EQ(sut.headIndex(), 0) << "The head index of singly linked list should be 0";
    EXPECT_EQ(freeList.size(), NUMBER_OF_ELEMENTS - 1) << "The size of free linked list should be " << NUMBER_OF_ELEMENTS - 1;

    /* Clean Up */
    sut.clear(freeList);
}

TEST_F(StaticSinglyLinkedList_TestSuite, AddSecondNodeInFront)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    const instantiationType elementOne                              = elementArray.at(0);

    LinkedList::StaticSinglyLinkedListNode<instantiationType>* node = {};
    uint32_t nodeIndex                                              = {};
    freeList.removeFront(node, nodeIndex);
    sut.addFront(*node, nodeIndex, elementOne);

    const instantiationType elementTwo = elementArray.at(1);

    freeList.removeFront(node, nodeIndex);

    /* Act */
    sut.addFront(*node, nodeIndex, elementTwo);

    /* Assert */
    EXPECT_EQ(sut.front().element, elementTwo) << "The element in the front node should be " << elementTwo;
    EXPECT_EQ(sut.size(), 2) << "The size of singly linked list should be " << 2;
    EXPECT_EQ(sut.headIndex(), 1) << "The head index of singly linked list should be 1";
    EXPECT_EQ(freeList.size(), NUMBER_OF_ELEMENTS - 2) << "The size of free linked list should be " << NUMBER_OF_ELEMENTS - 2;

    /* Clean Up */
    sut.clear(freeList);
}

TEST_F(StaticSinglyLinkedList_TestSuite, InsertOneElementFromFreeList)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    const instantiationType element = elementArray.at(0);

    /* Act */
    sut.insert(0, freeList, element);

    /* Assert */
    EXPECT_EQ(sut.front().element, element) << "The element in the front node should be " << element;
    EXPECT_EQ(sut.size(), 1) << "The size of singly linked list should be 1";
    EXPECT_EQ(sut.headIndex(), 0) << "The head index of singly linked list should be 0";
    EXPECT_EQ(freeList.size(), NUMBER_OF_ELEMENTS - 1) << "The size of free linked list should be " << NUMBER_OF_ELEMENTS - 1;

    /* Clean Up */
    sut.clear(freeList);
}

TEST_F(StaticSinglyLinkedList_TestSuite, InsertSecondElementFromFreeList)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    const instantiationType elementOne = elementArray.at(0);
    sut.insert(0, freeList, elementOne);

    const instantiationType elementTwo = elementArray.at(1);

    /* Act */
    sut.insert(1, freeList, elementTwo);

    /* Assert */
    EXPECT_EQ(sut.front().element, elementOne) << "The element in the front node should be " << elementOne;
    EXPECT_EQ(sut.get(1).element, elementTwo) << "The element at index 1 should be " << elementTwo;
    EXPECT_EQ(sut.size(), 2) << "The size of singly linked list should be 2";
    EXPECT_EQ(sut.headIndex(), 0) << "The head index of singly linked list should be 0";
    EXPECT_EQ(freeList.size(), NUMBER_OF_ELEMENTS - 2) << "The size of free linked list should be " << NUMBER_OF_ELEMENTS - 2;

    /* Clean Up */
    sut.clear(freeList);
}

TEST_F(StaticSinglyLinkedList_TestSuite, InsertThirdElementFromFreeList)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    const instantiationType elementOne = elementArray.at(0);
    sut.insert(0, freeList, elementOne);

    const instantiationType elementTwo = elementArray.at(1);
    sut.insert(1, freeList, elementTwo);

    const instantiationType elementThree = elementArray.at(2);

    /* Act */
    sut.insert(1, freeList, elementThree);

    /* Assert */
    EXPECT_EQ(sut.front().element, elementOne) << "The element in the front node should be " << elementOne;
    EXPECT_EQ(sut.get(1).element, elementThree) << "The element at index 1 should be " << elementThree;
    EXPECT_EQ(sut.get(2).element, elementTwo) << "The element at index 2 should be " << elementTwo;
    EXPECT_EQ(sut.size(), 3) << "The size of singly linked list should be 3";
    EXPECT_EQ(sut.headIndex(), 0) << "The head index of singly linked list should be 0";
    EXPECT_EQ(freeList.size(), NUMBER_OF_ELEMENTS - 3) << "The size of free linked list should be " << NUMBER_OF_ELEMENTS - 3;

    /* Clean Up */
    sut.clear(freeList);
}

TEST_F(StaticSinglyLinkedList_TestSuite, InsertBeyondListFromFreeList)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    const instantiationType elementOne = elementArray.at(0);
    sut.insert(0, freeList, elementOne);

    const instantiationType elementTwo = elementArray.at(1);
    sut.insert(1, freeList, elementTwo);

    const instantiationType elementThree = elementArray.at(2);

    /* Act */
    sut.insert(NUMBER_OF_ELEMENTS, freeList, elementThree);

    /* Assert */
    EXPECT_EQ(sut.front().element, elementOne) << "The element in the front node should be " << elementOne;
    EXPECT_EQ(sut.get(1).element, elementTwo) << "The element at index 1 should be " << elementTwo;
    EXPECT_EQ(sut.get(2).element, elementThree) << "The element at index 2 should be " << elementThree;
    EXPECT_EQ(sut.size(), 3) << "The size of singly linked list should be 3";
    EXPECT_EQ(sut.headIndex(), 0) << "The head index of singly linked list should be 0";
    EXPECT_EQ(freeList.size(), NUMBER_OF_ELEMENTS - 3) << "The size of free linked list should be " << NUMBER_OF_ELEMENTS - 3;

    /* Clean Up */
    sut.clear(freeList);
}

TEST_F(StaticSinglyLinkedList_TestSuite, InsertOneElement)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    const instantiationType element                                 = elementArray.at(0);

    LinkedList::StaticSinglyLinkedListNode<instantiationType>* node = {};
    uint32_t nodeIndex                                              = {};
    freeList.removeFront(node, nodeIndex);

    /* Act */
    sut.insert(0, *node, nodeIndex, element);

    /* Assert */
    EXPECT_EQ(sut.front().element, element) << "The element in the front node should be " << element;
    EXPECT_EQ(sut.size(), 1) << "The size of singly linked list should be 1";
    EXPECT_EQ(sut.headIndex(), 0) << "The head index of singly linked list should be 0";
    EXPECT_EQ(freeList.size(), NUMBER_OF_ELEMENTS - 1) << "The size of free linked list should be " << NUMBER_OF_ELEMENTS - 1;

    /* Clean Up */
    sut.clear(freeList);
}

TEST_F(StaticSinglyLinkedList_TestSuite, InsertSecondElement)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    const instantiationType elementOne                              = elementArray.at(0);

    LinkedList::StaticSinglyLinkedListNode<instantiationType>* node = {};
    uint32_t nodeIndex                                              = {};
    freeList.removeFront(node, nodeIndex);
    sut.insert(0, *node, nodeIndex, elementOne);

    const instantiationType elementTwo = elementArray.at(1);
    freeList.removeFront(node, nodeIndex);

    /* Act */
    sut.insert(1, *node, nodeIndex, elementTwo);

    /* Assert */
    EXPECT_EQ(sut.front().element, elementOne) << "The element in the front node should be " << elementOne;
    EXPECT_EQ(sut.get(1).element, elementTwo) << "The element at index 1 should be " << elementTwo;
    EXPECT_EQ(sut.size(), 2) << "The size of singly linked list should be 2";
    EXPECT_EQ(sut.headIndex(), 0) << "The head index of singly linked list should be 0";
    EXPECT_EQ(freeList.size(), NUMBER_OF_ELEMENTS - 2) << "The size of free linked list should be " << NUMBER_OF_ELEMENTS - 2;

    /* Clean Up */
    sut.clear(freeList);
}

TEST_F(StaticSinglyLinkedList_TestSuite, InsertThirdElement)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    const instantiationType elementOne                              = elementArray.at(0);

    LinkedList::StaticSinglyLinkedListNode<instantiationType>* node = {};
    uint32_t nodeIndex                                              = {};
    freeList.removeFront(node, nodeIndex);
    sut.insert(0, *node, nodeIndex, elementOne);

    const instantiationType elementTwo = elementArray.at(1);
    freeList.removeFront(node, nodeIndex);
    sut.insert(1, *node, nodeIndex, elementTwo);

    const instantiationType elementThree = elementArray.at(2);
    freeList.removeFront(node, nodeIndex);

    /* Act */
    sut.insert(1, *node, nodeIndex, elementThree);

    /* Assert */
    EXPECT_EQ(sut.front().element, elementOne) << "The element in the front node should be " << elementOne;
    EXPECT_EQ(sut.get(1).element, elementThree) << "The element at index 1 should be " << elementThree;
    EXPECT_EQ(sut.get(2).element, elementTwo) << "The element at index 2 should be " << elementTwo;
    EXPECT_EQ(sut.size(), 3) << "The size of singly linked list should be 3";
    EXPECT_EQ(sut.headIndex(), 0) << "The head index of singly linked list should be 0";
    EXPECT_EQ(freeList.size(), NUMBER_OF_ELEMENTS - 3) << "The size of free linked list should be " << NUMBER_OF_ELEMENTS - 3;

    /* Clean Up */
    sut.clear(freeList);
}

TEST_F(StaticSinglyLinkedList_TestSuite, InsertBeyondList)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    const instantiationType elementOne                              = elementArray.at(0);

    LinkedList::StaticSinglyLinkedListNode<instantiationType>* node = {};
    uint32_t nodeIndex                                              = {};
    freeList.removeFront(node, nodeIndex);
    sut.insert(0, *node, nodeIndex, elementOne);

    const instantiationType elementTwo = elementArray.at(1);
    freeList.removeFront(node, nodeIndex);
    sut.insert(1, *node, nodeIndex, elementTwo);

    const instantiationType elementThree = elementArray.at(2);
    freeList.removeFront(node, nodeIndex);

    /* Act */
    sut.insert(NUMBER_OF_ELEMENTS, *node, nodeIndex, elementThree);

    /* Assert */
    EXPECT_EQ(sut.front().element, elementOne) << "The element in the front node should be " << elementOne;
    EXPECT_EQ(sut.get(1).element, elementTwo) << "The element at index 1 should be " << elementTwo;
    EXPECT_EQ(sut.get(2).element, elementThree) << "The element at index 2 should be " << elementThree;
    EXPECT_EQ(sut.size(), 3) << "The size of singly linked list should be 3";
    EXPECT_EQ(sut.headIndex(), 0) << "The head index of singly linked list should be 0";
    EXPECT_EQ(freeList.size(), NUMBER_OF_ELEMENTS - 3) << "The size of free linked list should be " << NUMBER_OF_ELEMENTS - 3;

    /* Clean Up */
    sut.clear(freeList);
}

TEST_F(StaticSinglyLinkedList_TestSuite, RemoveFrontNode)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    const instantiationType elementOne = elementArray.at(0);
    sut.addFront(freeList, elementOne);
    const instantiationType elementTwo = elementArray.at(1);
    sut.addFront(freeList, elementTwo);

    LinkedList::StaticSinglyLinkedListNode<instantiationType>* node = {};
    uint32_t nodeIndex                                              = {};

    /* Act */
    sut.removeFront(node, nodeIndex);

    /* Assert */
    EXPECT_EQ(sut.front().element, elementOne) << "The element in the front node should be " << elementOne;
    EXPECT_EQ(sut.size(), 1);
    EXPECT_EQ(sut.headIndex(), 0) << "The head index of singly linked list should be 0";
    EXPECT_EQ(freeList.size(), NUMBER_OF_ELEMENTS - 2) << "The size of free linked list should be " << NUMBER_OF_ELEMENTS - 2;

    /* Clean Up */
    freeList.addFront(*node, nodeIndex, node->element);
    sut.clear(freeList);
}

class RemoveSpecifiedNodeTest : public StaticSinglyLinkedList_TestSuite, public testing::WithParamInterface<uint32_t>
{
    // No code here
};

INSTANTIATE_TEST_SUITE_P(InstantiationOne, RemoveSpecifiedNodeTest, testing::Range(uint32_t(0), uint32_t(NUMBER_OF_ELEMENTS - 1)));

TEST_P(RemoveSpecifiedNodeTest, RemoveOneNodeExceptTail)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    for (const auto entry : elementArray)
    {
        sut.addFront(freeList, entry);
    }

    const uint32_t index                                            = GetParam();
    LinkedList::StaticSinglyLinkedListNode<instantiationType>* node = {};
    uint32_t nodeIndex                                              = {};

    /* Act */
    sut.remove(index, node, nodeIndex);

    /* Assert */
    EXPECT_EQ(sut.get(index).element, elementArray.at(NUMBER_OF_ELEMENTS - index - 1 - 1));
    EXPECT_EQ(sut.size(), NUMBER_OF_ELEMENTS - 1);
    EXPECT_EQ(freeList.size(), 0) << "The size of free linked list should be 0";

    /* Clean Up */
    freeList.addFront(*node, nodeIndex, node->element);
    sut.clear(freeList);
}

TEST_F(StaticSinglyLinkedList_TestSuite, RemoveTailNode)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    for (const auto entry : elementArray)
    {
        sut.addFront(freeList, entry);
    }

    const uint32_t index                                            = NUMBER_OF_ELEMENTS - 1;
    LinkedList::StaticSinglyLinkedListNode<instantiationType>* node = {};
    uint32_t nodeIndex                                              = {};

    /* Act */
    sut.remove(index, node, nodeIndex);

    /* Assert */
    EXPECT_EQ(sut.get(index - 1).element, elementArray.at(NUMBER_OF_ELEMENTS - index));
    EXPECT_EQ(sut.size(), NUMBER_OF_ELEMENTS - 1);
    EXPECT_EQ(sut.headIndex(), NUMBER_OF_ELEMENTS - 1) << "The head index of singly linked list should be " << NUMBER_OF_ELEMENTS - 1;
    EXPECT_EQ(freeList.size(), 0) << "The size of free linked list should be 0";

    /* Clean Up */
    freeList.addFront(*node, nodeIndex, node->element);
    sut.clear(freeList);
}

TEST_F(StaticSinglyLinkedList_TestSuite, RemoveAllNodes)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    for (const auto entry : elementArray)
    {
        sut.addFront(freeList, entry);
    }

    /* Act */
    sut.clear(freeList);

    /* Assert */
    EXPECT_EQ(sut.size(), 0) << "The size of singly linked list should be 0";
    EXPECT_EQ(sut.headIndex(), static_cast<uint32_t>(LinkedList::StaticSinglyLinkedList<instantiationType>::ArrayIndex::END_NODE_INDEX)) << "The head index of singly linked list should be invalid";
    EXPECT_EQ(freeList.size(), NUMBER_OF_ELEMENTS) << "The size of free linked list should be " << NUMBER_OF_ELEMENTS;
}

TEST_F(StaticSinglyLinkedList_TestSuite, ReverseList)
{
    /* Arrange */
    LinkedList::StaticSinglyLinkedListNode<instantiationType> pool[NUMBER_OF_ELEMENTS];
    LinkedList::StaticSinglyLinkedList<instantiationType> freeList = LinkedList::StaticSinglyLinkedList<instantiationType>::initializePool(pool, NUMBER_OF_ELEMENTS);

    LinkedList::StaticSinglyLinkedList<instantiationType> sut(pool);
    for (const auto entry : elementArray)
    {
        sut.addFront(freeList, entry);
    }

    /* Act */
    LinkedList::StaticSinglyLinkedList<instantiationType>::reverseList(pool, sut);

    /* Assert */
    for (size_t index = 0; index < elementArray.size(); index++)
    {
        EXPECT_EQ(sut.get(index).element, elementArray.at(index));
    }
    EXPECT_EQ(sut.headIndex(), 0) << "The head index of singly linked list should be 0";

    /* Clean Up */
    sut.clear(freeList);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
