/* Header */
#include "Recursion/Fibonacci.h"

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace Recursion
{

template<class T>
fibonacci_pair<T> linearFibonacci(T index)
{
    fibonacci_pair<T> pair = {.f_k = index, .f_k_1 = 0};
    if (index <= 1)
    {
        return pair;
    }
    else
    {
        pair                         = linearFibonacci(index - 1);

        const fibonacci_pair<T> temp = {.f_k = pair.f_k + pair.f_k_1, .f_k_1 = pair.f_k};
        return temp;
    }
}

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template function]
template fibonacci_pair<int> linearFibonacci<int>(int index);
template fibonacci_pair<uint32_t> linearFibonacci<uint32_t>(uint32_t index);

} // namespace Recursion
