/**
 * @brief Basic Array
 * 
 * Arrays are the concrete data structures that access their entries using integer indices.
 *
 */
#ifndef _BASICARRAY_H
#define _BASICARRAY_H 1

/* Header */
// Project configuration
#include "ProjectConfiguration.h"

// C++ standard libraries:
#include <cassert>

// C standard libraries:
#include <stdint.h>

/* Macro */

/* Type */

namespace Array
{

/** A array entry class */
template<typename T>
class ArrayEntry
{
public:
    ArrayEntry(const T& v1 = {}, uint32_t v2 = 0); // Constructor

    T getElement() const;       // Get entry's element
    uint32_t getNumber() const; // Get entry's number

    bool operator==(const ArrayEntry<T>& v1) const
    {
        if ((element == v1.element) && (number == v1.number))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    /* Data */

    T element;       // Entry's element, e.g., name, ...
    uint32_t number; // Entry's number
};

/** A simple array class that stores the highest numbers in the descending order */
template<typename T>
class BasicArray
{
public:
    /** The @p v1 is the maximum number of entries */
    BasicArray(uint32_t v1 = 10);        // Constructor
    BasicArray(const BasicArray<T>& v1); // A copy constructor in case of the shallow copy since this class allocates memory
    ~BasicArray();                       // Destructor

    bool empty() const;         // Check whether the array is empty
    uint32_t size() const;      // Get the size of the array
    void clear();               // Remove all the elements
    uint32_t occupancy() const; // Get the occupancy of the array

    void add(const ArrayEntry<T>& v1);    // Add a entry
    ArrayEntry<T> remove(uint32_t index); // Remove the entry at the specified index

    BasicArray<T>& operator=(const BasicArray<T>& v1); // Overload the assignment operator in case of the shallow copy since this class allocates memory

    /** Access entry at the @p index */
    ArrayEntry<T>& operator[](uint32_t index)
    {
        assert(index < numberOfEntries); // Invalid index
        return entries[index];
    }

private:
    uint32_t maxEntries      = {}; // Maximum number of entries
    uint32_t numberOfEntries = {}; // Actual number of entries
    ArrayEntry<T>* entries   = {};
};

/* Prototype */
// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template class]
template class ArrayEntry<int>;
template class BasicArray<int>;

/* Variable */

/* Function */

} // namespace Array

#endif /* _BASICARRAY_H */
