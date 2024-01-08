/* Header */
#include "LinkedList/CircularlyDoublyLinkedList.h"
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

TEST(CircularlyDoublyLinkedList, CopyByConstructor)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> listA;
    instantiationType elementOne = instantiationType(Element::One);
    listA.add(elementOne);
    instantiationType elementTwo = instantiationType(Element::Two);
    listA.add(elementTwo);
    instantiationType elementThree = instantiationType(Element::Three);
    listA.add(elementThree);

    /* Act */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut(listA);

    /* Assert */
    EXPECT_EQ(sut.size(), listA.size());
    EXPECT_EQ(sut.front(), listA.front());
    EXPECT_EQ(sut.get(1), listA.get(1));
    EXPECT_EQ(sut.back(), listA.back());
}

TEST(CircularlyDoublyLinkedList, CopyByOperator)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> listA;
    instantiationType elementOne = instantiationType(Element::One);
    listA.add(elementOne);
    instantiationType elementTwo = instantiationType(Element::Two);
    listA.add(elementTwo);
    instantiationType elementThree = instantiationType(Element::Three);
    listA.add(elementThree);

    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;

    /* Act */
    sut = listA;

    /* Assert */
    EXPECT_EQ(sut.size(), listA.size());
    EXPECT_EQ(sut.front(), listA.front());
    EXPECT_EQ(sut.get(1), listA.get(1));
    EXPECT_EQ(sut.back(), listA.back());
}

TEST(CircularlyDoublyLinkedList, SecondCopy)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> listA, listB;
    instantiationType elementOne = instantiationType(Element::One);
    listA.add(elementOne);
    instantiationType elementTwo = instantiationType(Element::Two);
    listA.add(elementTwo);
    instantiationType elementThree = instantiationType(Element::Three);
    listA.add(elementThree);

    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;

    /* Act */
    sut = listB = listA;

    /* Assert */
    EXPECT_EQ(sut.size(), listA.size());
    EXPECT_EQ(sut.front(), listA.front());
    EXPECT_EQ(sut.get(1), listA.get(1));
    EXPECT_EQ(sut.back(), listA.back());
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

TEST(CircularlyDoublyLinkedList, MaximumSize)
{
    /* Arrange */
    LinkedList::CircularlyDoublyLinkedList<instantiationType> sut;
    sut.add(instantiationType(Element::One));
    sut.add(instantiationType(Element::Two));
    sut.add(instantiationType(Element::Three));

    /* Act */
    uint32_t size = sut.size();

    /* Assert */
    EXPECT_EQ(size, instantiationType(Element::Max)) << "The size of circularly doubly linked list should be " << instantiationType(Element::Max);
}

// TEST(CircularlyDoublyLinkedList, AddOneNodeInFront)
// {
//     /* Arrange */
//     LinkedList::DoublyLinkedList<instantiationType> sut;
//     instantiationType element = instantiationType(Element::One);

//     /* Act */
//     sut.addFront(element);

//     /* Assert */
//     EXPECT_EQ(sut.front(), element) << "The element in the front node should be " << element;
// }

// TEST(CircularlyDoublyLinkedList, AddOneNodeInBack)
// {
//     /* Arrange */
//     LinkedList::DoublyLinkedList<instantiationType> sut;
//     instantiationType element = instantiationType(Element::Two);

//     /* Act */
//     sut.addBack(element);

//     /* Assert */
//     EXPECT_EQ(sut.back(), element) << "The element in the back node should be " << element;
// }

// TEST(CircularlyDoublyLinkedList, AddSecondNodeInFront)
// {
//     /* Arrange */
//     LinkedList::DoublyLinkedList<instantiationType> sut;
//     instantiationType elementOne = instantiationType(Element::One);
//     sut.addFront(elementOne);

//     instantiationType elementTwo = instantiationType(Element::Two);

//     /* Act */
//     sut.addFront(elementTwo);

//     /* Assert */
//     EXPECT_EQ(sut.front(), elementTwo) << "The element in the front node should be " << elementTwo;
// }

// TEST(CircularlyDoublyLinkedList, GetThirdNode)
// {
//     /* Arrange */
//     LinkedList::DoublyLinkedList<instantiationType> sut;
//     instantiationType elementOne = instantiationType(Element::One);
//     sut.addFront(elementOne);
//     instantiationType elementTwo = instantiationType(Element::Two);
//     sut.addFront(elementTwo);
//     instantiationType elementThree = instantiationType(Element::Three);
//     sut.addFront(elementThree);

//     /* Act */
//     instantiationType thirdNode = sut.get(2);

//     /* Assert */
//     EXPECT_EQ(thirdNode, elementOne) << "The element in the third node should be " << elementOne;
// }

// TEST(CircularlyDoublyLinkedList, RemoveFrontNode)
// {
//     /* Arrange */
//     LinkedList::DoublyLinkedList<instantiationType> sut;
//     instantiationType elementOne = instantiationType(Element::One);
//     sut.addFront(elementOne);
//     instantiationType elementTwo = instantiationType(Element::Two);
//     sut.addFront(elementTwo);

//     /* Act */
//     sut.removeFront();

//     /* Assert */
//     EXPECT_EQ(sut.front(), elementOne) << "The element in the front node should be " << elementOne;
// }

// TEST(CircularlyDoublyLinkedList, RemoveBackNode)
// {
//     /* Arrange */
//     LinkedList::DoublyLinkedList<instantiationType> sut;
//     instantiationType elementOne = instantiationType(Element::One);
//     sut.addFront(elementOne);
//     instantiationType elementTwo = instantiationType(Element::Two);
//     sut.addFront(elementTwo);

//     /* Act */
//     sut.removeBack();

//     /* Assert */
//     EXPECT_EQ(sut.front(), elementTwo) << "The element in the front node should be " << elementTwo;
// }

// TEST(CircularlyDoublyLinkedList, RemoveAllNodes)
// {
//     /* Arrange */
//     LinkedList::DoublyLinkedList<instantiationType> sut;
//     instantiationType elementOne = instantiationType(Element::One);
//     sut.addFront(elementOne);
//     instantiationType elementTwo = instantiationType(Element::Two);
//     sut.addFront(elementTwo);
//     instantiationType elementThree = instantiationType(Element::Three);
//     sut.addFront(elementThree);

//     /* Act */
//     sut.clear();

//     /* Assert */
//     EXPECT_EQ(sut.size(), 0) << "The size of doubly linked list should be 0";
// }

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
