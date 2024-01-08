/* Header */
#include "Array/BasicArray.h"

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace Array
{

template<class T>
ArrayEntry<T>::ArrayEntry(const T& v1, uint32_t v2)
: element(v1), number(v2)
{
}

template<class T>
T ArrayEntry<T>::getElement() const
{
    return element;
}

template<class T>
uint32_t ArrayEntry<T>::getNumber() const
{
    return number;
}

template<class T>
BasicArray<T>::BasicArray(uint32_t v1)
{
    maxEntries = v1;                            // Save the max size
    entries    = new ArrayEntry<T>[maxEntries]; // Allocate array storage

    if (maxEntries != 0)
    {
        assert(entries != nullptr);
    }

    numberOfEntries = 0; // Initially no elements
}

template<class T>
BasicArray<T>::BasicArray(const BasicArray<T>& v1)
{
    maxEntries = v1.maxEntries;                 // Save the max size
    entries    = new ArrayEntry<T>[maxEntries]; // Allocate array storage

    if (maxEntries != 0)
    {
        assert(entries != nullptr);
    }

    for (size_t index = 0; index < v1.numberOfEntries; index++)
    {
        entries[index] = v1.entries[index];
    }
    numberOfEntries = v1.numberOfEntries;
}

template<class T>
BasicArray<T>::~BasicArray()
{
    if (! empty())
    {
        delete[] entries;
    }
}

template<class T>
bool BasicArray<T>::empty() const
{
    // The empty state: check whether the maxEntries is zero
    return (maxEntries == 0);
}

template<class T>
uint32_t BasicArray<T>::size() const
{
    return maxEntries;
}

template<class T>
void BasicArray<T>::clear()
{
    if (! empty())
    {
        delete[] entries;
        maxEntries      = {};
        numberOfEntries = {};
    }
}

template<class T>
uint32_t BasicArray<T>::occupancy() const
{
    return numberOfEntries;
}

template<class T>
void BasicArray<T>::add(const ArrayEntry<T>& v1)
{
    uint32_t newNumber = v1.getNumber(); // Number to add

    if (numberOfEntries == 0)
    {
        // The array's occupancy is zero
        entries[0] = v1; // Put v1 at the index 0
        numberOfEntries++;
        return;
    }

    if (numberOfEntries == maxEntries)
    {
        // The array is full, the smallest will be removed
        if (newNumber <= entries[maxEntries - 1].getNumber())
        {
            return; // Not high enough, thus ignore
        }
    }
    else
    {
        numberOfEntries++; // If not full, one more entry
    }

    uint32_t index = numberOfEntries - 1; // Start with the last
    while ((index > 0) && (newNumber > entries[index - 1].getNumber()))
    {
        entries[index] = entries[index - 1]; // Shift right if smaller
        index--;
    }
    entries[index] = v1; // Put v1 in the empty spot
}

template<class T>
ArrayEntry<T> BasicArray<T>::remove(uint32_t index)
{
    assert(index < numberOfEntries); // Invalid index

    ArrayEntry<T> entry = entries[index]; // Save the removed object
    for (size_t i = index + 1; i < numberOfEntries; i++)
    {
        entries[i - 1] = entries[i]; // Shift entries left
    }
    numberOfEntries--;
    return entry; // Return the removed object
}

template<class T>
BasicArray<T>& BasicArray<T>::operator=(const BasicArray<T>& v1)
{
    if (this != &v1) // Avoid self-assignment
    {
        clear(); // Delete old data

        maxEntries = v1.maxEntries;                 // Save the max size
        entries    = new ArrayEntry<T>[maxEntries]; // Allocate array storage

        if (maxEntries != 0)
        {
            assert(entries != nullptr);
        }

        for (size_t index = 0; index < v1.numberOfEntries; index++)
        {
            entries[index] = v1.entries[index];
        }
        numberOfEntries = v1.numberOfEntries;
    }

    return *this; // Allow to chain together assignments
}

} // namespace Array
