/* Header */
#include "NumericProgression/Progression.h"

// C++ standard libraries:
#include <cassert>
#include <iostream>

// C standard libraries:
#include <stddef.h>

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace NumericProgression
{

void Progression::printProgression(uint64_t v1)
{
    assert(0 < v1); // The first value starts from the index 1

    std::cout << firstValue();       // Print the first value
    for (size_t i = 2; i <= v1; i++) // Print 2 through v1
    {
        std::cout << ' ' << nextValue();
    }
    std::cout << std::endl;
}

uint64_t Progression::firstValue()
{
    current = first;
    return current;
}

uint64_t Progression::nextValue()
{
    return ++current;
}

} // namespace NumericProgression
