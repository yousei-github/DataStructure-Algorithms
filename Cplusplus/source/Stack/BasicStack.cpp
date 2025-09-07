/* Header */
#include "Stack/BasicStack.h"

// C standard libraries:
#include <stddef.h>

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace Stack
{

template<class T>
BasicStack<T>::BasicStack(uint32_t v1)
: array(new T[v1]), array_length(v1), number_of_element(static_cast<uint32_t>(ArrayIndex::EMPTY_STACK_INDEX))
{
    if (array_length != 0)
    {
        assert(array != nullptr);
    }
}

template<class T>
BasicStack<T>::BasicStack(const BasicStack<T>& v1)
{
    array_length = v1.array_length;
    array        = new T[array_length];

    if (array_length != 0)
    {
        assert(array != nullptr);
    }

    for (size_t i = 0; i < array_length; i++)
    {
        array[i] = v1.array[i];
    }

    number_of_element = v1.number_of_element;
}

template<class T>
BasicStack<T>::~BasicStack()
{
    if (! empty())
    {
        delete[] array;
    }
}

template<class T>
bool BasicStack<T>::empty() const
{
    // The empty state: check whether the number of elements is zero
    return (number_of_element == static_cast<uint32_t>(ArrayIndex::EMPTY_STACK_INDEX));
}

template<class T>
uint32_t BasicStack<T>::size() const
{
    return number_of_element;
}

template<class T>
uint32_t BasicStack<T>::capacity() const
{
    return array_length;
}

template<class T>
const T& BasicStack<T>::top() const
{
    // Top of empty stack
    assert(empty() == false);

    const uint32_t top_index = number_of_element - 1;
    return array[top_index];
}

template<class T>
void BasicStack<T>::push(const T& e)
{
    // Push to full stack
    assert(size() != array_length);

    array[number_of_element] = e;
    ++number_of_element;
}

template<class T>
void BasicStack<T>::pop()
{
    // Pop from empty stack
    assert(empty() == false);

    --number_of_element;
}

template<class T>
void BasicStack<T>::clear()
{
    if (! empty())
    {
        delete[] array;
        array_length      = {};
        number_of_element = static_cast<uint32_t>(ArrayIndex::EMPTY_STACK_INDEX);
    }
}

template<class T>
BasicStack<T>& BasicStack<T>::operator=(const BasicStack<T>& v1)
{
    if (this != &v1) // Avoid self-assignment
    {
        clear(); // Delete old data

        array_length = v1.array_length;
        array        = new T[array_length];

        if (array_length != 0)
        {
            assert(array != nullptr);
        }

        for (size_t i = 0; i < array_length; i++)
        {
            array[i] = v1.array[i];
        }

        number_of_element = v1.number_of_element;
    }

    return *this; // Allow to chain together assignments
}

} // namespace Stack
