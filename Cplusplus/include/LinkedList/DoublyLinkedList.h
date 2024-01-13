/**
 * @brief Doubly Linked List
 *
 */
#ifndef _DOUBLYLINKEDLIST_H
#define _DOUBLYLINKEDLIST_H 1

/* Header */
// Project configuration
#include "ProjectConfiguration.h"

// C standard libraries:
#include <stdint.h>

// C++ standard libraries:
#include <cassert>
#include <cstdio>

/* Macro */

/* Type */

namespace LinkedList
{

template<class T>          // class T is the list element type
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

template<class T> // class T is the list element type
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
    void addFront(const T& e);          // Add to front of list
    void addBack(const T& e);           // Add to back of list
    void removeFront();                 // Remove from front
    void removeBack();                  // Remove from back
    void clear();                       // Remove all the nodes

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

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template class]
template class DoublyLinkedList<int>;
template class DoublyLinkedListNode<int>;

/* Prototype */

/* Variable */

/* Function */

} /* namespace LinkedList */

#endif /* _DOUBLYLINKEDLIST_H */
