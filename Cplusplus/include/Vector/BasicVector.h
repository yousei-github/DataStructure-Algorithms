/**
 * @brief Basic Vector
 *
 */
#ifndef _BASICVECTOR_H
#define _BASICVECTOR_H 1

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
template<typename T>
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
// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template class]
template class BasicVector<int>;
template class BasicVector<BasicVector<int>>; // Templated arguments

/* Variable */

/* Function */

} // namespace Vector

#endif /* _BASICVECTOR_H */
