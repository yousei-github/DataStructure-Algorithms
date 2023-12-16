/* Header */
#include "NumericProgression/ArithmeticProgression.h"

// C++ standard libraries:
#include <cassert>

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace NumericProgression
{

ArithmeticProgression::ArithmeticProgression(uint64_t v1, uint64_t v2)
: Progression(v1), increment(v2)
{
}

uint64_t ArithmeticProgression::nextValue()
{
    current += increment; // Advance by adding
    return current;
}

} // namespace NumericProgression
