/**
 * @brief Fibonacci Progression
 *
 */
#ifndef _FIBONACCI_PROGRESSION_H
#define _FIBONACCI_PROGRESSION_H 1

/* Header */
// Project configuration
#include "ProjectConfiguration.h"

// C standard libraries:
#include <stdint.h>

#include "NumericProgression/Progression.h"

/* Macro */

/* Type */

namespace NumericProgression
{

/** Fibonacci progression */
class FibonacciProgression : public Progression
{
public:
    /** The @p v1 is the first value, @p v2 is the Second value */
    FibonacciProgression(uint64_t v1, uint64_t v2 = 1); // Constructor

protected:
    /** Reset */
    virtual uint64_t firstValue();
    /** Advance */
    virtual uint64_t nextValue();

    /* Data */

    uint64_t second;   // Second value
    uint64_t previous; // Previous value
};

/* Prototype */

/* Variable */

/* Function */

} // namespace NumericProgression

#endif /* _FIBONACCI_PROGRESSION_H */
