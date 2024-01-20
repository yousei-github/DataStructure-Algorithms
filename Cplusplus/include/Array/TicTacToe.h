/**
 * @brief Tic-Tac-Toe
 * 
 * Tic-Tac-Toe is a game played on a three-by-three board.
 * Two players, X and O, alternate in placing their respective marks in the cells of this board, starting with player X.
 * If either player succeeds in getting three of his or her marks in a row, column, or diagonal, then that player wins.
 * Otherwise, the game is tie.
 */
#ifndef _TICTACTOE_H
#define _TICTACTOE_H 1

/* Header */
// Project configuration
#include "ProjectConfiguration.h"

// C standard libraries:
#include <stdint.h>

/* Macro */

/* Type */

namespace Game
{

class TicTacToe
{
public:
    /* Data */

    static const uint8_t ROWSIZE = 3, COLUMNSIZE = 3;
    static const int8_t X = 1, O = -1, EMPTY = 0; // Possible marks

    enum class WinType : int8_t
    {
        None = 0,
        Row,
        Column,
        Diagonal,
        Tie,
        Max
    };

    /* Function */

    TicTacToe(); // Constructor

    void clearBoard();                         // Clear the board
    void putMark(uint8_t row, uint8_t column); // Mark row i column j
    bool isWin(int8_t mark);                   // Is mark the winner?
    int8_t getWinner();                        // Who wins? (EMPTY means tie)
    WinType getWinType(int8_t mark);           // Get the win type of the specified mark
    void printBoard();                         // Print the board

private:
    /* Data */

    const int8_t winTable[3]          = {3 * X, 3 * O, 3 * EMPTY};

    int8_t board[ROWSIZE][COLUMNSIZE] = {}; // Playing board
    int8_t currentPlayer              = {}; // Current player (X or O)
};

/* Prototype */

/* Variable */

/* Function */

} // namespace Game

#endif /* _TICTACTOE_H */
