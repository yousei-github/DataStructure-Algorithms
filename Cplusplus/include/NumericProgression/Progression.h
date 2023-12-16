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

/** A generic progression */
class Progression
{
public:
    /** The @p v1 is the first value */
    Progression(uint64_t v1 = 0)
    : first(v1), current(v1) {}; // Constructor
    virtual ~Progression() {};   // Destructor

    /** Print @p v1 values */
    void printProgression(uint64_t v1);

protected:
    /** Reset */
    virtual uint64_t firstValue();

    /** Advance */
    virtual uint64_t nextValue();

    /* Data */

    uint64_t first;   // First value
    uint64_t current; // Current value
};

/* Prototype */

/* Variable */

/* Function */

} // namespace NumericProgression

#endif /* _PROGRESSION_H */
