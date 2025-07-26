/**
 * @brief Arithmetic Progression
 *
 */
#ifndef _ARITHMETIC_PROGRESSION_H
#define _ARITHMETIC_PROGRESSION_H 1

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

/** Arithmetic progression */
class ArithmeticProgression : public Progression
{
public:
    /** The @p v1 is the first value, @p v2 is the increment */
    ArithmeticProgression(uint64_t v1, uint64_t v2 = 1); // Constructor

protected:
    /** Advance */
    virtual uint64_t nextValue();

    /* Data */

    uint64_t increment; // Increment value
};

/* Prototype */

/* Variable */

/* Function */

} // namespace NumericProgression

#endif /* _ARITHMETIC_PROGRESSION_H */
