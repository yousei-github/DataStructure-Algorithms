/* Header */
#include "Array/TicTacToe.h"

// C++ standard libraries:
#include <cassert>
#include <iostream>

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace Game
{

TicTacToe::TicTacToe()
{
    clearBoard();
}

void TicTacToe::clearBoard()
{
    for (size_t row = 0; row < ROWSIZE; row++)
    {
        for (size_t column = 0; column < COLUMNSIZE; column++)
        {
            board[row][column] = EMPTY;
        }
    }
    currentPlayer = X;
}

void TicTacToe::putMark(uint8_t row, uint8_t column)
{
    assert((row < ROWSIZE) && (column < COLUMNSIZE));
    assert(board[row][column] == EMPTY);

    board[row][column] = currentPlayer;  // Mark with current player
    currentPlayer      = -currentPlayer; // Switch players
}

bool TicTacToe::isWin(int8_t mark)
{
    WinType wintype = getWinType(mark);

    return ((wintype == WinType::Row) || (wintype == WinType::Column) || (wintype == WinType::Diagonal));
}

int8_t TicTacToe::getWinner()
{
    if (isWin(X))
    {
        return X;
    }
    else if (isWin(O))
    {
        return O;
    }
    else
    {
        return EMPTY;
    }
}

TicTacToe::WinType TicTacToe::getWinType(int8_t mark)
{
    int8_t win = {};
    switch (mark)
    {
    case X:
    {
        win = winTable[0];
    }
    break;
    case O:
    {
        win = winTable[1];
    }
    break;
    default:
    {
        return WinType::Tie;
    }
    break;
    }

    if ((board[0][0] + board[0][1] + board[0][2] == win) || (board[1][0] + board[1][1] + board[1][2] == win) || (board[2][0] + board[2][1] + board[2][2] == win))
    {
        // Row 0, row 1, row 2
        return WinType::Row;
    }
    else if ((board[0][0] + board[1][0] + board[2][0] == win) || (board[0][1] + board[1][1] + board[2][1] == win) || (board[0][2] + board[1][2] + board[2][2] == win))
    {
        // Column 0, Column 1, Column 2
        return WinType::Column;
    }
    else if ((board[0][0] + board[1][1] + board[2][2] == win) || (board[2][0] + board[1][1] + board[0][2] == win))
    {
        // Diagonal
        return WinType::Diagonal;
    }
    else
    {
        return WinType::Tie;
    }
}

void TicTacToe::printBoard()
{
    for (size_t row = 0; row < ROWSIZE; row++)
    {
        for (size_t column = 0; column < COLUMNSIZE; column++)
        {
            switch (board[row][column])
            {
            case X:
            {
                std::cout << "X";
            }
            break;
            case O:
            {
                std::cout << "O";
            }
            break;
            case EMPTY:
            {
                std::cout << " ";
            }
            break;
            default:
            {
                assert(false);
            }
            break;
            }

            if (column < (COLUMNSIZE - 1))
            {
                std::cout << "|"; // Column boundary
            }
        }

        if (row < (ROWSIZE - 1))
        {
            std::cout << "\n-+-+-\n"; // Row boundary
        }
        else
        {
            std::cout << "\n";
        }
    }
}

} // namespace Game
