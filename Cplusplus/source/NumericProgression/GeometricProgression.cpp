/* Header */
#include "NumericProgression/GeometricProgression.h"

// C++ standard libraries:
#include <cassert>

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace NumericProgression
{

GeometricProgression::GeometricProgression(uint64_t v1, uint64_t v2)
: Progression(v1), base(v2)
{
}

uint64_t GeometricProgression::nextValue()
{
    current *= base; // Advance by multiplying
    return current;
}

} // namespace NumericProgression
