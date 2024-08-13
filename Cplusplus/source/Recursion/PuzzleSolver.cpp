/* Header */
#include "Recursion/PuzzleSolver.h"

// C++ standard libraries:
#include <cassert>

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace Recursion
{

template<class T>
PuzzleSolver<T>::PuzzleSolver(testPuzzle v1)
: puzzle(v1)
{
}

template<class T>
PuzzleSolver<T>::~PuzzleSolver()
{
}

template<class T>
void PuzzleSolver<T>::solvePuzzle(uint32_t k, std::deque<T>& sequence, std::vector<T>& set)
{
    assert(k != 0);
    assert(set.size() != 0);

    // for (auto iterator = set.begin(); iterator != set.end(); iterator++)
    for (size_t index = 0; index < set.size(); index++)
    {
        if (set.at(index) == INVALID_ELEMENT)
        {
            continue;
        }

        T element  = set[index];
        set[index] = INVALID_ELEMENT; // Remove the element from set

        sequence.push_back(element); // Add the element to the end of sequence

        if (k == 1)
        {
            // Test whether the sequence is a configuration that solves the puzzle
            const bool result = puzzle(sequence);
            if (result)
            {
                answers.push(sequence);
            }
        }
        else
        {
            solvePuzzle(k - 1, sequence, set);
        }

        set[index] = element; // Add the element back to set

        sequence.pop_back(); // Remove the element from the end of sequence
    }
}

template<class T>
uint32_t PuzzleSolver<T>::size() const
{
    return answers.size();
}

template<class T>
const std::queue<std::deque<T>>& PuzzleSolver<T>::GetAnswer() const
{
    return answers;
}

} // namespace Recursion
