/* Header */
#include "LinkedList/SinglyLinkedList.h"
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

TEST(SinglyLinkedListNode, CopyByConstructor)
{
    /* Arrange */
    LinkedList::SinglyLinkedListNode<instantiationType> nodeA;
    nodeA.element = instantiationType(Element::Two);

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
    nodeA.element = instantiationType(Element::Two);

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
    nodeA.element = instantiationType(Element::Two);

    LinkedList::SinglyLinkedListNode<instantiationType> sut;

    /* Act */
    sut = nodeB = nodeA;

    /* Assert */
    EXPECT_EQ(sut.element, nodeA.element);
    EXPECT_EQ(sut.next, nodeA.next);
}

TEST(SinglyLinkedList, CopyByConstructor)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> listA;
    instantiationType elementOne = instantiationType(Element::One);
    listA.addFront(elementOne);
    instantiationType elementTwo = instantiationType(Element::Two);
    listA.addFront(elementTwo);
    instantiationType elementThree = instantiationType(Element::Three);
    listA.addFront(elementThree);

    /* Act */
    LinkedList::SinglyLinkedList<instantiationType> sut(listA);

    /* Assert */
    EXPECT_EQ(sut.size(), listA.size());
    EXPECT_EQ(sut.front(), listA.front());
    EXPECT_EQ(sut.get(1), listA.get(1));
    EXPECT_EQ(sut.get(2), listA.get(2));
}

TEST(SinglyLinkedList, CopyByOperator)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> listA;
    instantiationType elementOne = instantiationType(Element::One);
    listA.addFront(elementOne);
    instantiationType elementTwo = instantiationType(Element::Two);
    listA.addFront(elementTwo);
    instantiationType elementThree = instantiationType(Element::Three);
    listA.addFront(elementThree);

    LinkedList::SinglyLinkedList<instantiationType> sut;

    /* Act */
    sut = listA;

    /* Assert */
    EXPECT_EQ(sut.size(), listA.size());
    EXPECT_EQ(sut.front(), listA.front());
    EXPECT_EQ(sut.get(1), listA.get(1));
    EXPECT_EQ(sut.get(2), listA.get(2));
}

TEST(SinglyLinkedList, SecondCopy)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> listA, listB;
    instantiationType elementOne = instantiationType(Element::One);
    listA.addFront(elementOne);
    instantiationType elementTwo = instantiationType(Element::Two);
    listA.addFront(elementTwo);
    instantiationType elementThree = instantiationType(Element::Three);
    listA.addFront(elementThree);

    LinkedList::SinglyLinkedList<instantiationType> sut;

    /* Act */
    sut = listB = listA;

    /* Assert */
    EXPECT_EQ(sut.size(), listA.size());
    EXPECT_EQ(sut.front(), listA.front());
    EXPECT_EQ(sut.get(1), listA.get(1));
    EXPECT_EQ(sut.get(2), listA.get(2));
}

TEST(SinglyLinkedList, Empty)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> sut;

    /* Act */
    bool isEmpty = sut.empty();

    /* Assert */
    EXPECT_TRUE(isEmpty) << "The singly linked list should be empty";
}

TEST(SinglyLinkedList, MaximumSize)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> sut;
    sut.addFront(instantiationType(Element::One));
    sut.addFront(instantiationType(Element::Two));
    sut.addFront(instantiationType(Element::Three));

    /* Act */
    uint32_t size = sut.size();

    /* Assert */
    EXPECT_EQ(size, instantiationType(Element::Max)) << "The size of singly linked list should be " << instantiationType(Element::Max);
}

TEST(SinglyLinkedList, AddOneNodeInFront)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> sut;
    instantiationType element = instantiationType(Element::One);

    /* Act */
    sut.addFront(element);

    /* Assert */
    EXPECT_EQ(sut.front(), element) << "The element in the front node should be " << element;
}

TEST(SinglyLinkedList, AddSecondNodeInFront)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> sut;
    instantiationType elementOne = instantiationType(Element::One);
    sut.addFront(elementOne);

    instantiationType elementTwo = instantiationType(Element::Two);

    /* Act */
    sut.addFront(elementTwo);

    /* Assert */
    EXPECT_EQ(sut.front(), elementTwo) << "The element in the front node should be " << elementTwo;
}

TEST(SinglyLinkedList, GetThirdNode)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> sut;
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

TEST(SinglyLinkedList, RemoveFrontNode)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> sut;
    instantiationType elementOne = instantiationType(Element::One);
    sut.addFront(elementOne);
    instantiationType elementTwo = instantiationType(Element::Two);
    sut.addFront(elementTwo);

    /* Act */
    sut.removeFront();

    /* Assert */
    EXPECT_EQ(sut.front(), elementOne) << "The element in the front node should be " << elementOne;
}

TEST(SinglyLinkedList, RemoveAllNodes)
{
    /* Arrange */
    LinkedList::SinglyLinkedList<instantiationType> sut;
    instantiationType elementOne = instantiationType(Element::One);
    sut.addFront(elementOne);
    instantiationType elementTwo = instantiationType(Element::Two);
    sut.addFront(elementTwo);
    instantiationType elementThree = instantiationType(Element::Three);
    sut.addFront(elementThree);

    /* Act */
    sut.clear();

    /* Assert */
    EXPECT_EQ(sut.size(), 0) << "The size of singly linked list should be 0";
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
