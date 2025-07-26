/**
 * @brief Singly Linked List
 *
 */
#ifndef _SINGLY_LINKED_LIST_H
#define _SINGLY_LINKED_LIST_H 1

/* Header */
// Project configuration
#include "ProjectConfiguration.h"

// C standard libraries:
#include <stdint.h>

// C++ standard libraries:
#include <cassert>

/* Macro */

/* Type */

namespace LinkedList
{

template<class T>          // Class T is the list element type
class SinglyLinkedListNode // Singly linked list node
{
public:
    T element {};                            // Node element value
    SinglyLinkedListNode<T>* next = nullptr; // Next node in list

    SinglyLinkedListNode() {};                               // Constructor
    SinglyLinkedListNode(const SinglyLinkedListNode<T>& v1); // Constructor
    SinglyLinkedListNode<T>& operator=(const SinglyLinkedListNode<T>& v1);
};

template<class T> // Cass T is the list element type
class SinglyLinkedList
{
public:
    SinglyLinkedList();                              // Constructor
    SinglyLinkedList(const SinglyLinkedList<T>& v1); // A copy constructor in case of the shallow copy since this class allocates memory
    ~SinglyLinkedList();                             // Destructor

    bool empty() const;                 // Check whether the list is empty
    uint32_t size() const;              // Get the size of the list
    const T& front() const;             // Get front element; an error results if the list is empty
    const T& get(uint32_t index) const; // Return the [index]th element; an error results if the list is empty

    void addFront(const T& e); // Add to front of list
    void removeFront();        // Remove from front
    void clear();              // Remove all the nodes

    static void reverseList(SinglyLinkedList<T>& list) // Reverse the elements of the list
    {
        SinglyLinkedList<T> firstReversedTemp, secondReversedTemp;

        while (! list.empty())
        {
            T element = list.front();
            list.removeFront();
            firstReversedTemp.addFront(element);
        }

        while (! firstReversedTemp.empty())
        {
            T element = firstReversedTemp.front();
            firstReversedTemp.removeFront();
            secondReversedTemp.addFront(element);
        }

        while (! secondReversedTemp.empty())
        {
            T element = secondReversedTemp.front();
            secondReversedTemp.removeFront();
            list.addFront(element);
        }
    }

    SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>& v1); // Overload the assignment operator in case of the shallow copy since this class allocates memory

private:
    SinglyLinkedListNode<T>* head = {}; // Pointer to the head of list
    uint32_t list_size            = {}; // The size of the list
};

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template class]
template class SinglyLinkedList<int>;
template class SinglyLinkedListNode<int>;

/* Prototype */

/* Variable */

/* Function */

} /* namespace LinkedList */

#endif /* _SINGLY_LINKED_LIST_H */
