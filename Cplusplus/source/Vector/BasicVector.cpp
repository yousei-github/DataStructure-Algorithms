/* Header */
#include "Vector/BasicVector.h"

// C standard libraries:
#include <stddef.h>

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace Vector
{

template<class T>
BasicVector<T>::BasicVector(uint32_t v1)
{
    capacity = v1;
    array    = new T[capacity];

    if (capacity != 0)
    {
        assert(array != nullptr);
    }
}

template<class T>
BasicVector<T>::BasicVector(const BasicVector<T>& v1)
{
    capacity = v1.capacity;
    array    = new T[capacity];

    if (capacity != 0)
    {
        assert(array != nullptr);
    }

    for (size_t i = 0; i < capacity; i++)
    {
        array[i] = v1.array[i];
    }
}

template<class T>
BasicVector<T>::~BasicVector()
{
    if (! empty())
    {
        delete[] array;
    }
}

template<class T>
bool BasicVector<T>::empty() const
{
    // The empty state: check whether the capacity is zero
    return (capacity == 0);
}

template<class T>
uint32_t BasicVector<T>::size() const
{
    return capacity;
}

template<class T>
void BasicVector<T>::clear()
{
    if (! empty())
    {
        delete[] array;
        capacity = {};
    }
}

template<class T>
BasicVector<T>& BasicVector<T>::operator=(const BasicVector<T>& v1)
{
    if (this != &v1) // Avoid self-assignment
    {
        clear(); // Delete old data

        capacity = v1.capacity;
        array    = new T[capacity];

        if (capacity != 0)
        {
            assert(array != nullptr);
        }

        for (size_t i = 0; i < capacity; i++)
        {
            array[i] = v1.array[i];
        }
    }

    return *this; // Allow to chain together assignments
}

} // namespace Vector
