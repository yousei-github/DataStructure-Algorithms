/* Header */
#include "Array/TicTacToe.h"
#include "gtest/gtest.h"

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

TEST(TicTacToe, PrintBoard)
{
    /* Arrange */
    Game::TicTacToe sut;

    /* Act */
    sut.printBoard();

    /* Assert */
    // No code here
}

TEST(TicTacToe, WinRow)
{
    /* Arrange */
    Game::TicTacToe sut;
    int8_t expectMark = sut.X;

    /* Act */
    sut.putMark(0, 0);
    sut.putMark(1, 1);
    sut.putMark(0, 1);
    sut.putMark(2, 2);
    sut.putMark(0, 2);

    /* Assert */
    sut.printBoard();
    EXPECT_EQ(sut.getWinner(), expectMark);
}

TEST(TicTacToe, WinColumn)
{
    /* Arrange */
    Game::TicTacToe sut;
    int8_t expectMark = sut.X;

    /* Act */
    sut.putMark(0, 1);
    sut.putMark(0, 0);
    sut.putMark(1, 1);
    sut.putMark(2, 2);
    sut.putMark(2, 1);

    /* Assert */
    sut.printBoard();
    EXPECT_EQ(sut.getWinner(), expectMark);
}

TEST(TicTacToe, WinDiagonal)
{
    /* Arrange */
    Game::TicTacToe sut;
    int8_t expectMark = sut.X;

    /* Act */
    sut.putMark(0, 0);
    sut.putMark(0, 2);
    sut.putMark(1, 1);
    sut.putMark(2, 1);
    sut.putMark(2, 2);

    /* Assert */
    sut.printBoard();
    EXPECT_EQ(sut.getWinner(), expectMark);
}

TEST(TicTacToe, Tie)
{
    /* Arrange */
    Game::TicTacToe sut;
    int8_t expectMark = sut.EMPTY;

    /* Act */
    sut.putMark(0, 0);
    sut.putMark(0, 2);
    sut.putMark(1, 2);
    sut.putMark(1, 1);
    sut.putMark(2, 0);
    sut.putMark(1, 0);
    sut.putMark(2, 2);
    sut.putMark(2, 1);
    sut.putMark(0, 1);

    /* Assert */
    sut.printBoard();
    EXPECT_EQ(sut.getWinner(), expectMark);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
