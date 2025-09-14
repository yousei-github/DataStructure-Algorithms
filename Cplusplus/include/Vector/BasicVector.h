/**
 * @brief Basic Vector
 *
 */
#ifndef _BASIC_VECTOR_H
#define _BASIC_VECTOR_H 1

/* Header */
// Project configuration
#include "ProjectConfiguration.h"

// C++ standard libraries:
#include <cassert>

// C standard libraries:
#include <stdint.h>

/* Macro */

/* Type */

namespace Vector
{

/** A simple vector class */
template<typename T> // Class T is the vector element type
class BasicVector
{
public:
    /** The @p v1 is the capacity */
    BasicVector(uint32_t v1 = 10);         // Constructor
    BasicVector(const BasicVector<T>& v1); // A copy constructor in case of the shallow copy since this class allocates memory
    ~BasicVector();                        // Destructor

    bool empty() const;    // Check whether the vector is empty
    uint32_t size() const; // Get the size of the vector
    void clear();          // Remove all the elements

    BasicVector<T>& operator=(const BasicVector<T>& v1); // Overload the assignment operator in case of the shallow copy since this class allocates memory

    /** Access element at the @p index */
    T& operator[](uint32_t index)
    {
        assert(index < capacity);
        return array[index];
    }

private:
    /* Data */

    T* array          = {}; // Array storing the element
    uint32_t capacity = {}; // Length of array
};

/* Prototype */

/* Variable */

/* Function */

} // namespace Vector

#endif /* _BASIC_VECTOR_H */
