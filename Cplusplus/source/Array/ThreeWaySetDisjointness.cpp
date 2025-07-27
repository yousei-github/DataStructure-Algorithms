/* Header */
#include "Array/ThreeWaySetDisjointness.h"

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace Array
{

template<class T>
bool areDisjoint(const std::vector<T>& a, const std::vector<T>& b, const std::vector<T>& c)
{
    for (size_t a_index = 0; a_index < a.size(); a_index++)
    {
        for (size_t b_index = 0; b_index < b.size(); b_index++)
        {
            for (size_t c_index = 0; c_index < c.size(); c_index++)
            {
                if ((a[a_index] == b[b_index]) && (b[b_index] == c[c_index]))
                {
                    return false;
                }
            }
        }
    }

    return true;
}

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template function]
template bool areDisjoint<int>(const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c);

} // namespace Array
