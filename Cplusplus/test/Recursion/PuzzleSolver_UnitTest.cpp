/* Header */
#include <iostream>

#include "Recursion/PuzzleSolver.h"
#include "gtest/gtest.h"

// C standard libraries:
#include <stddef.h>

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

#if 0
TEST(PuzzleSolver, SummationPuzzleOne)
{
    /* Arrange */
    const uint32_t lengthOfSequence = 13;

    auto testPuzzle                 = [](std::deque<uint32_t>& sequence) -> bool
    {
        assert(sequence.size() == lengthOfSequence);
        /**
         * Puzzle:
         * pot + pan  = bib
         * dog + cat  = pig
         * boy + girl = baby
         *
         * The ordering of sequence:
         * p, o, t, a, n, b, i, d, g, c, y, r, l
         */
        if ((sequence[0] + sequence[1] + sequence[2] + sequence[0] + sequence[3] + sequence[4]) != (sequence[5] + sequence[6] + sequence[5]))
        {
            return false;
        }

        if ((sequence[7] + sequence[1] + sequence[8] + sequence[9] + sequence[3] + sequence[2]) != (sequence[0] + sequence[6] + sequence[8]))
        {
            return false;
        }

        if ((sequence[5] + sequence[1] + sequence[10] + sequence[8] + sequence[6] + sequence[11] + sequence[12]) != (sequence[5] + sequence[3] + sequence[5] + sequence[10]))
        {
            return false;
        }

        return true;
    };

    Recursion::PuzzleSolver<uint32_t> sut(testPuzzle);
    std::deque<uint32_t> sequence = {};
    std::vector<uint32_t> set     = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    /* Act */
    sut.solvePuzzle(lengthOfSequence, sequence, set);

    /* Assert */
    std::cout << "The number of the answers is " << sut.size() << std::endl;

    std::queue<std::deque<uint32_t>> answers = sut.GetAnswer();
    size_t index                             = 0;
    while (! answers.empty())
    {
        std::deque<uint32_t>& element = answers.front();
        std::cout << index << ": ";
        for (auto& entry : element)
        {
            std::cout << entry << " ";
        }
        std::cout << std::endl;

        answers.pop();
        index++;
    }
}
#endif

TEST(PuzzleSolver, SummationPuzzleTwo)
{
    /* Arrange */
    const uint32_t lengthOfSequence = 3;

    auto testPuzzle                 = [](std::deque<uint32_t>& sequence) -> bool
    {
        assert(sequence.size() == lengthOfSequence);
        /**
         * Puzzle:
         * a + b  = c
         * 
         * The ordering of sequence:
         * a, b, c
         */
        if ((sequence[0] + sequence[1]) != (sequence[2]))
        {
            return false;
        }

        return true;
    };

    Recursion::PuzzleSolver<uint32_t> sut(testPuzzle);
    std::deque<uint32_t> sequence = {};
    std::vector<uint32_t> set     = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    /* Act */
    sut.solvePuzzle(lengthOfSequence, sequence, set);

    /* Assert */
    std::cout << "The number of the answers is " << sut.size() << std::endl;

    std::queue<std::deque<uint32_t>> answers = sut.GetAnswer();
    size_t index                             = 0;
    while (! answers.empty())
    {
        std::deque<uint32_t>& element = answers.front();
        std::cout << index << ": ";
        for (auto& entry : element)
        {
            std::cout << entry << " ";
        }
        std::cout << std::endl;

        answers.pop();
        index++;
    }
}

TEST(PuzzleSolver, Clear)
{
    /* Arrange */
    const uint32_t lengthOfSequence = 4;

    auto testPuzzle                 = [](std::deque<uint32_t>& sequence) -> bool
    {
        assert(sequence.size() == lengthOfSequence);
        /**
         * Puzzle:
         * a + b  = c + d
         * 
         * The ordering of sequence:
         * a, b, c, d
         */
        if ((sequence[0] + sequence[1]) != (sequence[2] + sequence[3]))
        {
            return false;
        }

        return true;
    };

    Recursion::PuzzleSolver<uint32_t> sut(testPuzzle);
    std::deque<uint32_t> sequence = {};
    std::vector<uint32_t> set     = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    sut.solvePuzzle(lengthOfSequence, sequence, set);
    std::cout << "The number of the answers is " << sut.size() << std::endl;

    /* Act */
    sut.clear();

    /* Assert */
    EXPECT_EQ(0, sut.size());
}
