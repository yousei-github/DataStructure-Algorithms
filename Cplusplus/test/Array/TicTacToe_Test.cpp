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

TEST(TicTacToe, XWinRow)
{
    /* Arrange */
    Game::TicTacToe sut;
    int8_t expectMark                = sut.X;
    Game::TicTacToe::WinType wintype = Game::TicTacToe::WinType::Row;

    /* Act */
    sut.putMark(0, 0);
    sut.putMark(1, 1);
    sut.putMark(0, 1);
    sut.putMark(2, 2);
    sut.putMark(0, 2);

    /* Assert */
    sut.printBoard();

    const int8_t winner = sut.getWinner();
    EXPECT_EQ(winner, expectMark);
    EXPECT_EQ(sut.getWinType(winner), wintype);
}

TEST(TicTacToe, OWinRow)
{
    /* Arrange */
    Game::TicTacToe sut;
    int8_t expectMark                = sut.O;
    Game::TicTacToe::WinType wintype = Game::TicTacToe::WinType::Row;

    /* Act */
    sut.putMark(0, 0);
    sut.putMark(1, 1);
    sut.putMark(2, 0);
    sut.putMark(1, 0);
    sut.putMark(0, 2);
    sut.putMark(1, 2);

    /* Assert */
    sut.printBoard();

    const int8_t winner = sut.getWinner();
    EXPECT_EQ(winner, expectMark);
    EXPECT_EQ(sut.getWinType(winner), wintype);
}

TEST(TicTacToe, XWinColumn)
{
    /* Arrange */
    Game::TicTacToe sut;
    int8_t expectMark                = sut.X;
    Game::TicTacToe::WinType wintype = Game::TicTacToe::WinType::Column;

    /* Act */
    sut.putMark(0, 1);
    sut.putMark(0, 0);
    sut.putMark(1, 1);
    sut.putMark(2, 2);
    sut.putMark(2, 1);

    /* Assert */
    sut.printBoard();

    const int8_t winner = sut.getWinner();
    EXPECT_EQ(winner, expectMark);
    EXPECT_EQ(sut.getWinType(winner), wintype);
}

TEST(TicTacToe, OWinColumn)
{
    /* Arrange */
    Game::TicTacToe sut;
    int8_t expectMark                = sut.O;
    Game::TicTacToe::WinType wintype = Game::TicTacToe::WinType::Column;

    /* Act */
    sut.putMark(1, 0);
    sut.putMark(1, 1);
    sut.putMark(0, 2);
    sut.putMark(0, 1);
    sut.putMark(2, 2);
    sut.putMark(2, 1);

    /* Assert */
    sut.printBoard();

    const int8_t winner = sut.getWinner();
    EXPECT_EQ(winner, expectMark);
    EXPECT_EQ(sut.getWinType(winner), wintype);
}

TEST(TicTacToe, XWinDiagonal)
{
    /* Arrange */
    Game::TicTacToe sut;
    int8_t expectMark                = sut.X;
    Game::TicTacToe::WinType wintype = Game::TicTacToe::WinType::Diagonal;

    /* Act */
    sut.putMark(0, 0);
    sut.putMark(0, 2);
    sut.putMark(1, 1);
    sut.putMark(2, 1);
    sut.putMark(2, 2);

    /* Assert */
    sut.printBoard();

    const int8_t winner = sut.getWinner();
    EXPECT_EQ(winner, expectMark);
    EXPECT_EQ(sut.getWinType(winner), wintype);
}

TEST(TicTacToe, OWinDiagonal)
{
    /* Arrange */
    Game::TicTacToe sut;
    int8_t expectMark                = sut.O;
    Game::TicTacToe::WinType wintype = Game::TicTacToe::WinType::Diagonal;

    /* Act */
    sut.putMark(1, 0);
    sut.putMark(1, 1);
    sut.putMark(1, 2);
    sut.putMark(0, 2);
    sut.putMark(2, 1);
    sut.putMark(2, 0);

    /* Assert */
    sut.printBoard();

    const int8_t winner = sut.getWinner();
    EXPECT_EQ(winner, expectMark);
    EXPECT_EQ(sut.getWinType(winner), wintype);
}

TEST(TicTacToe, Tie)
{
    /* Arrange */
    Game::TicTacToe sut;
    int8_t expectMark                = sut.EMPTY;
    Game::TicTacToe::WinType wintype = Game::TicTacToe::WinType::Tie;

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

    const int8_t winner = sut.getWinner();
    EXPECT_EQ(winner, expectMark);
    EXPECT_EQ(sut.getWinType(winner), wintype);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
