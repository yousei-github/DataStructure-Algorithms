/**
 * @brief Doubly Linked List
 *
 */
#ifndef _DOUBLY_LINKED_LIST_H
#define _DOUBLY_LINKED_LIST_H 1

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
class DoublyLinkedListNode // Doubly linked list node
{
public:
    T element {};                                // Node element value
    DoublyLinkedListNode<T>* previous = nullptr; // Previous node in list
    DoublyLinkedListNode<T>* next     = nullptr; // Next node in list

    DoublyLinkedListNode() {};                               // Constructor
    DoublyLinkedListNode(const DoublyLinkedListNode<T>& v1); // Constructor
    DoublyLinkedListNode<T>& operator=(const DoublyLinkedListNode<T>& v1);
};

template<class T> // Cass T is the list element type
class DoublyLinkedList
{
public:
    DoublyLinkedList();                              // Constructor
    DoublyLinkedList(const DoublyLinkedList<T>& v1); // A copy constructor in case of the shallow copy since this class allocates memory
    ~DoublyLinkedList();                             // Destructor

    bool empty() const;                 // Check whether the list is empty
    uint32_t size() const;              // Get the size of the list
    const T& front() const;             // Get front element; an error results if the list is empty
    const T& back() const;              // Get back element; an error results if the list is empty
    const T& get(uint32_t index) const; // Return the [index]th element; an error results if the list is empty

    void addFront(const T& e); // Add to front of list
    void addBack(const T& e);  // Add to back of list
    void removeFront();        // Remove from front
    void removeBack();         // Remove from back
    void clear();              // Remove all the nodes

    static void reverseList(DoublyLinkedList<T>& list) // Reverse the elements of the list
    {
        DoublyLinkedList<T> temp;

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

    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& v1); // Overload the assignment operator in case of the shallow copy since this class allocates memory

private:
    // List sentinels: the benefit is effectively handling the special cases by storing extra information
    DoublyLinkedListNode<T>* header  = {};
    DoublyLinkedListNode<T>* trailer = {};
    uint32_t list_size               = {}; // The size of the list

protected:
    // Local utilities
    void add(DoublyLinkedListNode<T>* v, const T& e); // Insert new node before v
    void remove(DoublyLinkedListNode<T>* v);          // Remove node v
};

/* Prototype */

/* Variable */

/* Function */

} /* namespace LinkedList */

#endif /* _DOUBLY_LINKED_LIST_H */
