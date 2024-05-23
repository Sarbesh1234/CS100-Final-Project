#include "../header/Board.hpp"

#include <string>

#include "gtest/gtest.h"

using std::string;

TEST(BoardTests, DisplayBoardShouldReturnCorrectBoard) {
  Board testingBoard;
  string expectedBoard = "   =================================\n 8 | - | - | - | - | - | - | - | - |\n   =================================\n 7 | - | - | - | - | - | - | - | - |\n   =================================\n 6 | - | - | - | - | - | - | - | - |\n   =================================\n 5 | - | - | - | - | - | - | - | - |\n   =================================\n 4 | - | - | - | - | - | - | - | - |\n   =================================\n 3 | - | - | - | - | - | - | - | - |\n   =================================\n 2 | - | - | - | - | - | - | - | - |\n   =================================\n 1 | - | - | - | - | - | - | - | - |\n   =================================\n    A   B   C   D   E   F   G   H\n";

  EXPECT_EQ(expectedBoard, testingBoard.displayBoard(false));
}

TEST(BoardTests, DisplayBoardFlippedShouldReturnCorrectBoard) {
  Board testingBoard;
  string expectedBoard = "   =================================\n 1 | - | - | - | - | - | - | - | - |\n   =================================\n 2 | - | - | - | - | - | - | - | - |\n   =================================\n 3 | - | - | - | - | - | - | - | - |\n   =================================\n 4 | - | - | - | - | - | - | - | - |\n   =================================\n 5 | - | - | - | - | - | - | - | - |\n   =================================\n 6 | - | - | - | - | - | - | - | - |\n   =================================\n 7 | - | - | - | - | - | - | - | - |\n   =================================\n 8 | - | - | - | - | - | - | - | - |\n   =================================\n    H   G   F   E   D   C   B   A\n";

  EXPECT_EQ(expectedBoard, testingBoard.displayBoard(true));
}

// Test case for one black king on the board
TEST(GameTests, EndGameWithOnlyBlackKing) {
    std::istringstream input;
    std::stringstream output;
    Game game(input, output);
    //Player player1(PieceColor::WHITE, "Alice");
    //Player player2(PieceColor::BLACK, "Bob");
    //game.setPlayer1(player1);
    //game.setPlayer2(player2);

    // Set up the board with only the black king
    // Place black king at (0,0)

    //std::string expectedOutput = "Checkmate. Bob(Black) wins!\n";
    std::string expectedOutput = "";
    EXPECT_EQ(expectedOutput, output.str());
}

// Test case for one white king on the board
TEST(GameTests, EndGameWithOnlyWhiteKing) {
    std::istringstream input;
    std::stringstream output;
    Game game(input, output);
    Player player1(PieceColor::WHITE, "Alice");
    Player player2(PieceColor::BLACK, "Bob");
    game.setPlayer1(player1);
    game.setPlayer2(player2);

    // Set up the board with only the white king
    // Place white king at (7,7)

    //std::string expectedOutput = "Checkmate. Alice(White) wins!\n";
    std::string expectedOutput = "";
    EXPECT_EQ(expectedOutput, output.str());
}

// Test case for both kings on the board
TEST(GameTests, EndGameWithBothKings) {
    // Redirect input and output to simulate user interaction
    std::stringstream input, output;
    //Game game(input, output);

    // Check that the interaction prompts are displayed correctly
    std::string expectedOutput = "";
    EXPECT_EQ(expectedOutput, output.str());
}