/**
 * @brief
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

/* Prototype */
namespace LinkedLists
{

template<class T>          // class T is the list element type
class DoublyLinkedListNode // Doubly linked list node
{
public:
    T element;                                   // Node element value
    DoublyLinkedListNode<T>* previous = nullptr; // Previous node in list
    DoublyLinkedListNode<T>* next     = nullptr; // Next node in list
};

template<class T> // class T is the list element type
class DoublyLinkedList
{
public:
    DoublyLinkedList();        // Constructor
    ~DoublyLinkedList();       // Destructor
    bool empty() const;        // Check whether the list is empty
    const T& front() const;    // Get front element
    const T& back() const;     // Get back element
    void addFront(const T& e); // Add to front of list
    void addBack(const T& e);  // Add to back of list
    void removeFront();        // Remove from front
    void removeBack();         // Remove from back

private:
    // List sentinels: the benefit is effectively handling the special cases by storing extra information
    DoublyLinkedListNode<T>* header  = nullptr;
    DoublyLinkedListNode<T>* trailer = nullptr;

protected:
    // Local utilities
    void add(DoublyLinkedListNode<T>* v, const T& e); // Insert new node before v
    void remove(DoublyLinkedListNode<T>* v);          // Remove node v
};

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template class]
template class DoublyLinkedList<int>;

/* Variable */

/* Function */

} /* namespace LinkedLists */

#endif /* _DOUBLYLINKEDLIST_H */
