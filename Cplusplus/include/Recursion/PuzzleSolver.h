/**
 * @brief Puzzle Solver
 * A combinatorial puzzle solver using multiple recursion
 */
#ifndef _PUZZLE_SOLVER_H
#define _PUZZLE_SOLVER_H 1

/* Header */
// Project configuration
#include "ProjectConfiguration.h"

// C standard libraries:
#include <stdint.h>

// C++ standard libraries:
#include <deque>
#include <queue>
#include <vector>

/* Macro */

/* Type */

namespace Recursion
{

template<class T> // Class T is the sequence element type
class PuzzleSolver
{
public:
    // The type of function to test the puzzle
    typedef bool (*testPuzzle)(std::deque<T>& sequence);

    const T INVALID_ELEMENT = static_cast<T>(0xFFFFFFFF);

    PuzzleSolver(testPuzzle v1); // Constructor
    ~PuzzleSolver();             // Destructor

    bool empty() const;                                 // Check whether the answer is empty
    uint32_t size() const;                              // Get the number of the answers
    const std::queue<std::deque<T>>& GetAnswer() const; // Return the array stores all results

    /**
     * @brief Solve the puzzle recursively
     * 
     * @param[in] k The length of the sequence
     * @param[out] sequence The sequence to enumerate and test the possible configurations
     * @param[in] set The element set
     */
    void solvePuzzle(uint32_t k, std::deque<T>& sequence, std::vector<T>& set);
    void clear(); // Remove all answers

private:
    testPuzzle puzzle                 = nullptr; // The function to test the puzzle
    std::queue<std::deque<T>> answers = {};      // The array stores all results
};

// Explicitly instantiate the template to solve the compiling problem in C++ programming, which is ["undefined reference to" template class]
template class PuzzleSolver<int>;
template class PuzzleSolver<uint32_t>;

/* Prototype */

/* Variable */

/* Function */

} // namespace Recursion

#endif /* _PUZZLE_SOLVER_H */
