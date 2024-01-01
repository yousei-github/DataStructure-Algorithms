/* Header */
#include "LinkedLists/DoublyLinkedList.h"
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

TEST(DoublyLinkedListNode, CopyByConstructor)
{
    /* Arrange */
    LinkedLists::DoublyLinkedListNode<instantiationType> nodeA;
    nodeA.element = instantiationType(Element::Two);

    /* Act */
    LinkedLists::DoublyLinkedListNode<instantiationType> sut(nodeA);

    /* Assert */
    EXPECT_EQ(sut.element, nodeA.element);
    EXPECT_EQ(sut.previous, nodeA.previous);
    EXPECT_EQ(sut.next, nodeA.next);
}

TEST(DoublyLinkedListNode, CopyByOperator)
{
    /* Arrange */
    LinkedLists::DoublyLinkedListNode<instantiationType> nodeA;
    nodeA.element = instantiationType(Element::Two);

    LinkedLists::DoublyLinkedListNode<instantiationType> sut;

    /* Act */
    sut = nodeA;

    /* Assert */
    EXPECT_EQ(sut.element, nodeA.element);
    EXPECT_EQ(sut.previous, nodeA.previous);
    EXPECT_EQ(sut.next, nodeA.next);
}

TEST(DoublyLinkedListNode, SecondCopy)
{
    /* Arrange */
    LinkedLists::DoublyLinkedListNode<instantiationType> nodeA, nodeB;
    nodeA.element = instantiationType(Element::Two);

    LinkedLists::DoublyLinkedListNode<instantiationType> sut;

    /* Act */
    sut = nodeB = nodeA;

    /* Assert */
    EXPECT_EQ(sut.element, nodeA.element);
    EXPECT_EQ(sut.previous, nodeA.previous);
    EXPECT_EQ(sut.next, nodeA.next);
}

TEST(DoublyLinkedList, CopyByConstructor)
{
    /* Arrange */
    LinkedLists::DoublyLinkedList<instantiationType> listA;
    instantiationType elementOne = instantiationType(Element::One);
    listA.addFront(elementOne);
    instantiationType elementTwo = instantiationType(Element::Two);
    listA.addFront(elementTwo);
    instantiationType elementThree = instantiationType(Element::Three);
    listA.addFront(elementThree);

    /* Act */
    LinkedLists::DoublyLinkedList<instantiationType> sut(listA);

    /* Assert */
    EXPECT_EQ(sut.size(), listA.size());
    EXPECT_EQ(sut.front(), listA.front());
    EXPECT_EQ(sut.get(1), listA.get(1));
    EXPECT_EQ(sut.back(), listA.back());
}

TEST(DoublyLinkedList, CopyByOperator)
{
    /* Arrange */
    LinkedLists::DoublyLinkedList<instantiationType> listA;
    instantiationType elementOne = instantiationType(Element::One);
    listA.addFront(elementOne);
    instantiationType elementTwo = instantiationType(Element::Two);
    listA.addFront(elementTwo);
    instantiationType elementThree = instantiationType(Element::Three);
    listA.addFront(elementThree);

    LinkedLists::DoublyLinkedList<instantiationType> sut;

    /* Act */
    sut = listA;

    /* Assert */
    EXPECT_EQ(sut.size(), listA.size());
    EXPECT_EQ(sut.front(), listA.front());
    EXPECT_EQ(sut.get(1), listA.get(1));
    EXPECT_EQ(sut.back(), listA.back());
}

TEST(DoublyLinkedList, SecondCopy)
{
    /* Arrange */
    LinkedLists::DoublyLinkedList<instantiationType> listA, listB;
    instantiationType elementOne = instantiationType(Element::One);
    listA.addFront(elementOne);
    instantiationType elementTwo = instantiationType(Element::Two);
    listA.addFront(elementTwo);
    instantiationType elementThree = instantiationType(Element::Three);
    listA.addFront(elementThree);

    LinkedLists::DoublyLinkedList<instantiationType> sut;

    /* Act */
    sut = listB = listA;

    /* Assert */
    EXPECT_EQ(sut.size(), listA.size());
    EXPECT_EQ(sut.front(), listA.front());
    EXPECT_EQ(sut.get(1), listA.get(1));
    EXPECT_EQ(sut.back(), listA.back());
}

TEST(DoublyLinkedList, Empty)
{
    /* Arrange */
    LinkedLists::DoublyLinkedList<instantiationType> sut;

    /* Act */
    bool isEmpty = sut.empty();

    /* Assert */
    EXPECT_TRUE(isEmpty) << "The doubly linked list should be empty";
}

TEST(DoublyLinkedList, MaximumSize)
{
    /* Arrange */
    LinkedLists::DoublyLinkedList<instantiationType> sut;
    sut.addFront(instantiationType(Element::One));
    sut.addFront(instantiationType(Element::Two));
    sut.addFront(instantiationType(Element::Three));

    /* Act */
    uint32_t size = sut.size();

    /* Assert */
    EXPECT_EQ(size, instantiationType(Element::Max)) << "The size of doubly linked list should be " << instantiationType(Element::Max);
}

TEST(DoublyLinkedList, AddOneNodeInFront)
{
    /* Arrange */
    LinkedLists::DoublyLinkedList<instantiationType> sut;
    instantiationType element = instantiationType(Element::One);

    /* Act */
    sut.addFront(element);

    /* Assert */
    EXPECT_EQ(sut.front(), element) << "The element in the front node should be " << element;
}

TEST(DoublyLinkedList, AddOneNodeInBack)
{
    /* Arrange */
    LinkedLists::DoublyLinkedList<instantiationType> sut;
    instantiationType element = instantiationType(Element::Two);

    /* Act */
    sut.addBack(element);

    /* Assert */
    EXPECT_EQ(sut.back(), element) << "The element in the back node should be " << element;
}

TEST(DoublyLinkedList, AddSecondNodeInFront)
{
    /* Arrange */
    LinkedLists::DoublyLinkedList<instantiationType> sut;
    instantiationType elementOne = instantiationType(Element::One);
    sut.addFront(elementOne);

    instantiationType elementTwo = instantiationType(Element::Two);

    /* Act */
    sut.addFront(elementTwo);

    /* Assert */
    EXPECT_EQ(sut.front(), elementTwo) << "The element in the front node should be " << elementTwo;
}

TEST(DoublyLinkedList, GetThirdNode)
{
    /* Arrange */
    LinkedLists::DoublyLinkedList<instantiationType> sut;
    instantiationType elementOne = instantiationType(Element::One);
    sut.addFront(elementOne);
    instantiationType elementTwo = instantiationType(Element::Two);
    sut.addFront(elementTwo);
    instantiationType elementThree = instantiationType(Element::Three);
    sut.addFront(elementThree);

    /* Act */
    instantiationType thirdNode = sut.get(2);

    /* Assert */
    EXPECT_EQ(thirdNode, elementOne) << "The element in the third node should be " << elementOne;
}

TEST(DoublyLinkedList, RemoveFrontNode)
{
    /* Arrange */
    LinkedLists::DoublyLinkedList<instantiationType> sut;
    instantiationType elementOne = instantiationType(Element::One);
    sut.addFront(elementOne);
    instantiationType elementTwo = instantiationType(Element::Two);
    sut.addFront(elementTwo);

    /* Act */
    sut.removeFront();

    /* Assert */
    EXPECT_EQ(sut.front(), elementOne) << "The element in the front node should be " << elementOne;
}

TEST(DoublyLinkedList, RemoveBackNode)
{
    /* Arrange */
    LinkedLists::DoublyLinkedList<instantiationType> sut;
    instantiationType elementOne = instantiationType(Element::One);
    sut.addFront(elementOne);
    instantiationType elementTwo = instantiationType(Element::Two);
    sut.addFront(elementTwo);

    /* Act */
    sut.removeBack();

    /* Assert */
    EXPECT_EQ(sut.front(), elementTwo) << "The element in the front node should be " << elementTwo;
}

TEST(DoublyLinkedList, RemoveAllNodes)
{
    /* Arrange */
    LinkedLists::DoublyLinkedList<instantiationType> sut;
    instantiationType elementOne = instantiationType(Element::One);
    sut.addFront(elementOne);
    instantiationType elementTwo = instantiationType(Element::Two);
    sut.addFront(elementTwo);
    instantiationType elementThree = instantiationType(Element::Three);
    sut.addFront(elementThree);

    /* Act */
    sut.clear();

    /* Assert */
    EXPECT_EQ(sut.size(), 0) << "The size of doubly linked list should be 0";
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
