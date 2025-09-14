/**
 * @brief Linked Stack
 *
 * @details
 * The stack is implemented by a singly linked list.
 */
#ifndef _LINKED_STACK_H
#define _LINKED_STACK_H 1

/* Header */

// Project configuration
#include "ProjectConfiguration.h"

// C++ standard libraries:
#include <cassert>

// C standard libraries:
#include <stdint.h>

#if (USE_EXCEPTION == ENABLE)
#include "Exception/BasicException.h"
#endif /* USE_EXCEPTION */

#include "LinkedList/SinglyLinkedList.h"

/* Macro */

/* Type */

namespace Stack
{

/** A linked stack class */
template<typename T> // Class T is the stack element type
class LinkedStack
{
public:
    /** The @p v1 is the capacity */
    LinkedStack();                         // Constructor
    LinkedStack(const LinkedStack<T>& v1); // A copy constructor in case of the shallow copy since this class allocates memory
    ~LinkedStack();                        // Destructor

    bool empty() const;    // Check whether the stack is empty
    uint32_t size() const; // Get the size of the stack (Number of items in stack)
    const T& top() const;  // Get the top element
    void push(const T& e); // Push element e onto the stack
    void pop();            // Remove the top element
    void clear();          // Remove all the elements

    LinkedStack<T>& operator=(const LinkedStack<T>& v1); // Overload the assignment operator in case of the shallow copy since this class allocates memory
    /** Read element at the @p index */
    T operator[](uint32_t index);

private:
    /* Data */

    LinkedList::SinglyLinkedList<T> list; // Singly linked list storing the stack element
};

/* Prototype */

/* Variable */

/* Function */

// Place template definitions to the header file to solve the compiling problem in C++ programming, which is ["undefined reference to" template class]

template<class T>
LinkedStack<T>::LinkedStack()
: list()
{
}

template<class T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& v1)
: list(v1.list)
{
}

template<class T>
LinkedStack<T>::~LinkedStack()
{
}

template<class T>
bool LinkedStack<T>::empty() const
{
    // The empty state: check whether the number of elements is zero
    return list.empty();
}

template<class T>
uint32_t LinkedStack<T>::size() const
{
    return list.size();
}

template<class T>
const T& LinkedStack<T>::top() const
{
    return list.front();
}

template<class T>
void LinkedStack<T>::push(const T& e)
{
    list.addFront(e);
}

template<class T>
void LinkedStack<T>::pop()
{
    list.removeFront();
}

template<class T>
void LinkedStack<T>::clear()
{
    list.clear();
}

template<class T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& v1)
{
    if (this != &v1) // Avoid self-assignment
    {
        clear(); // Delete old data

        list = v1.list;
    }

    return *this; // Allow to chain together assignments
}

template<class T>
T LinkedStack<T>::operator[](uint32_t index)
{
    return list.get(index);
}

} // namespace Stack

#endif /* _LINKED_STACK_H */
