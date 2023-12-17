/* Header */
#include "NumericProgression/FibonacciProgression.h"

// C++ standard libraries:
#include <cassert>

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace NumericProgression
{

FibonacciProgression::FibonacciProgression(uint64_t v1, uint64_t v2)
: Progression(v1), second(v2), previous(second - first)
{
}

uint64_t FibonacciProgression::firstValue()
{
    current  = first;
    previous = second - first; // Create fictious previous value
    return current;
}

uint64_t FibonacciProgression::nextValue()
{
    uint64_t temp = previous;
    previous      = current;
    current += temp;
    return current;
}

} // namespace NumericProgression
