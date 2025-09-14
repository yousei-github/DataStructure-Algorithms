/**
 * @brief Circularly Doubly Linked List
 *
 */
#ifndef _CIRCULARLY_DOUBLY_LINKED_LIST_H
#define _CIRCULARLY_DOUBLY_LINKED_LIST_H 1

/* Header */
// Project configuration
#include "ProjectConfiguration.h"

// C standard libraries:
#include <stdint.h>

// C++ standard libraries:
#include <cassert>

#include "LinkedList/DoublyLinkedList.h"

/* Macro */

/* Type */

namespace LinkedList
{

template<class T> // Class T is the list element type
class CircularlyDoublyLinkedList
{
public:
    CircularlyDoublyLinkedList();                                        // Constructor
    CircularlyDoublyLinkedList(const CircularlyDoublyLinkedList<T>& v1); // A copy constructor in case of the shallow copy since this class allocates memory
    ~CircularlyDoublyLinkedList();                                       // Destructor

    bool empty() const;                 // Check whether the list is empty
    uint32_t size() const;              // Get the size of the list
    const T& front() const;             // Return the element immediately after the cursor; an error results if the list is empty
    const T& back() const;              // Return the element referenced by the cursor; an error results if the list is empty
    const T& get(uint32_t index) const; // Return the [index]th element after the cursor; an error results if the list is empty

    void advance();            // Advance the cursor to the next node in the list
    void retreat();            // Retreat the cursor to the previous node in the list
    void add(const T& e);      // Insert a new node with element e immediately after the cursor; if the list is empty, then this node becomes the cursor and its next pointer points to itself
    void remove();             // Remove the node immediately after the cursor (not the cursor itself, unless it is the only node); if the list becomes empty, the cursor is set to nullptr
    void addFront(const T& e); // Add to front of list
    void addBack(const T& e);  // Add to back of list
    void removeFront();        // Remove from front
    void removeBack();         // Remove from back
    void clear();              // Remove all the nodes

    static void reverseList(CircularlyDoublyLinkedList<T>& list) // Reverse the elements of the list
    {
        CircularlyDoublyLinkedList<T> temp;

        while (! list.empty())
        {
            T element = list.front();
            list.removeFront();
            temp.addFront(element);
        }

        while (! temp.empty())
        {
            T element = temp.front();
            temp.removeFront();
            list.addBack(element);
        }
    }

    CircularlyDoublyLinkedList<T>& operator=(const CircularlyDoublyLinkedList<T>& v1); // Overload the assignment operator in case of the shallow copy since this class allocates memory

private:
    // The node referenced by the cursor is called the back node, and the node following the back node is called the front node in the circular order
    DoublyLinkedListNode<T>* cursor = {};
    uint32_t list_size              = {}; // The size of the list
};

/* Prototype */

/* Variable */

/* Function */

} /* namespace LinkedList */

#endif /* _CIRCULARLY_DOUBLY_LINKED_LIST_H */
