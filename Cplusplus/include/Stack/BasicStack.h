/**
 * @brief Basic Stack
 *
 * @details
 * A stack is a container of objects that are inserted and removed according to the last-in first-out (LIFO) principle.
 * Objects can be inserted into a stack at any time, but only the most recently inserted (that is, "last") object can be removed at any time.
 * 
 * This basic stack implement a stack by storing its elements in an array.
 * Specifically, the stack in this implementation consists of an N-element array S plus an integer variable t that gives the index of the top element in array S.
 */
#ifndef _BASIC_STACK_H
#define _BASIC_STACK_H 1

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

/* Macro */

/* Type */

namespace Stack
{

/** A simple array-based stack class */
template<typename T> // Class T is the stack element type
class BasicStack
{
    // Default stack capacity
    enum class DefaultCapacity : uint32_t
    {
        DEFAULT = 100,
        MAX     = UINT32_MAX
    };

    // Array index
    enum class ArrayIndex : uint32_t
    {
        EMPTY_STACK_INDEX = 0
    };

public:
    /** The @p v1 is the capacity */
    BasicStack(uint32_t v1 = static_cast<uint32_t>(DefaultCapacity::DEFAULT)); // Constructor
    BasicStack(const BasicStack<T>& v1);                                       // A copy constructor in case of the shallow copy since this class allocates memory
    ~BasicStack();                                                             // Destructor

    bool empty() const;        // Check whether the stack is empty
    uint32_t size() const;     // Get the size of the stack (Number of items in stack)
    uint32_t capacity() const; // Get the capacity of the stack
    const T& top() const;      // Get the top element
    void push(const T& e);     // Push element e onto the stack
    void pop();                // Remove the top element
    void clear();              // Remove all the elements

    BasicStack<T>& operator=(const BasicStack<T>& v1); // Overload the assignment operator in case of the shallow copy since this class allocates memory
    /** Read element at the @p index */
    T operator[](uint32_t index);

private:
    /* Data */

    T* array                   = {}; // Array storing the stack element
    uint32_t array_length      = {}; // Length of array (Stack capacity)
    uint32_t number_of_element = {}; // Number of element in the stack, [number_of_element - 1] is the index of top of the stack
};

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template class]
template class BasicStack<int>;
template class BasicStack<BasicStack<int>>; // Templated arguments

/* Prototype */

/* Variable */

/* Function */

} // namespace Stack

#endif /* _BASIC_STACK_H */
