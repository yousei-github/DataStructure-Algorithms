/**
 * @brief Progression
 *
 */
#ifndef _PROGRESSION_H
#define _PROGRESSION_H 1

/* Header */
// Project configuration
#include "ProjectConfiguration.h"

// C standard libraries:
#include <stdint.h>

/* Macro */

/* Type */

namespace NumericProgression
{

/** A generic progression defined by the abstract base class */
class Progression
{
public:
    /** The @p v1 is the first value */
    Progression(uint64_t v1 = 0)
    : first(v1), current(v1) {}; // Constructor
    virtual ~Progression() {};   // Virtual destructor of the abstract base class to avoid a memory leak in case the derived class needs to implement a destructor

    /** Print @p v1 values */
    void printProgression(uint64_t v1);

    /** @todo A well-defined API for test */

protected:
    /** Reset */
    virtual uint64_t firstValue();
    /** Advance */
    virtual uint64_t nextValue() = 0; // Pure virtual function

    /* Data */

    uint64_t first;   // First value
    uint64_t current; // Current value
};

/* Prototype */

/* Variable */

/* Function */

} // namespace NumericProgression

#endif /* _PROGRESSION_H */
