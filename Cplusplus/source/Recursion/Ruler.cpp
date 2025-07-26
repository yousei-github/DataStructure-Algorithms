/* Header */
#include "Recursion/Ruler.h"

// C++ standard libraries:
#include <iostream>

// C standard libraries:
#include <stddef.h>

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace Recursion
{

/** One tick with optional label */
static void drawOneTick(const uint32_t tickLength, const int32_t tickLabel = -1)
{
    for (size_t i = 0; i < tickLength; i++)
    {
        std::cout << "-";
    }

    if (tickLabel >= 0)
    {
        std::cout << " " << tickLabel;
    }

    std::cout << std::endl;
}

/** Draw ticks of given length */
static void drawTicks(const uint32_t tickLength)
{
    if (tickLength > 0) // Stop when length drops to 0
    {
        drawTicks(tickLength - 1); // Recursively draw left ticks
        drawOneTick(tickLength);   // Draw center tick
        drawTicks(tickLength - 1); // Recursively draw right ticks
    }
}

/** Draw the entire ruler */
void drawRuler(const uint32_t nInches, const uint32_t majorLength)
{
    drawOneTick(majorLength, 0); // Draw tick 0 and its label
    for (size_t i = 1; i <= nInches; i++)
    {
        drawTicks(majorLength - 1);  // Draw ticks for this inch
        drawOneTick(majorLength, i); // Draw tick i and its label
    }
}

} // namespace Recursion
