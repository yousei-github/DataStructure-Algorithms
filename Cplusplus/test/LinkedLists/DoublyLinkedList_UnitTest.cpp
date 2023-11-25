/* Header */
#include "LinkedLists/DoublyLinkedList.h"
#include "gtest/gtest.h"

/* Macro */

/* Type */
typedef int instantiationType;

/* Prototype */

/* Variable */

/* Function */

TEST(DoublyLinkedList, Empty)
{
    /* Arrange */
    LinkedLists::DoublyLinkedList<instantiationType> sut;

    /* Act */
    bool isEmpty = sut.empty();

    /* Assert */
    EXPECT_TRUE(isEmpty) << "The doubly linked list should be empty.";
}

TEST(DoublyLinkedList, AddOneInFront)
{
    /* Arrange */
    LinkedLists::DoublyLinkedList<instantiationType> sut;
    instantiationType element = 6;

    /* Act */
    sut.addFront(element);

    /* Assert */
    EXPECT_EQ(sut.front(), element) << "The element in the front node should be " << element;
}

TEST(DoublyLinkedList, AddOneInBack)
{
    /* Arrange */
    LinkedLists::DoublyLinkedList<instantiationType> sut;
    instantiationType element = 8;

    /* Act */
    sut.addBack(element);

    /* Assert */
    EXPECT_EQ(sut.back(), element) << "The element in the back node should be " << element;
}
