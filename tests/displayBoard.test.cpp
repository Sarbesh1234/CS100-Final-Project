#include "../header/DisplayBoard.hpp"
#include "../header/Board.hpp"
#include "Game.hpp"

#include <string>

#include "gtest/gtest.h"

using std::string;

TEST(DisplayBoardTests, DisplayBoardShouldReturnCorrectBoard) {
  Board testingBoard;
  DisplayBoard testingDisplayBoard(testingBoard);
  testingBoard.initializeBoard();
  string expectedBoard = "   ==========================================\n 8 | Rb | Nb | Bb | Kb | Qb | Bb | Nb | Rb |\n   ==========================================\n 7 | Pb | Pb | Pb | Pb | Pb | Pb | Pb | Pb |\n   ==========================================\n 6 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 5 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 4 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 3 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 2 | Pw | Pw | Pw | Pw | Pw | Pw | Pw | Pw |\n   ==========================================\n 1 | Rw | Nw | Bw | Kw | Qw | Bw | Nw | Rw |\n   ==========================================\n     A    B    C    D    E    F    G    H    \n";

  EXPECT_EQ(expectedBoard, testingDisplayBoard.displayBoard(false));
}

TEST(DisplayBoardTests, DisplayBoardFlippedShouldReturnCorrectBoard) {
  Board testingBoard;
  DisplayBoard testingDisplayBoard(testingBoard);
  testingBoard.initializeBoard();
  string expectedBoard = "   ==========================================\n 1 | Rw | Nw | Bw | Qw | Kw | Bw | Nw | Rw |\n   ==========================================\n 2 | Pw | Pw | Pw | Pw | Pw | Pw | Pw | Pw |\n   ==========================================\n 3 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 4 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 5 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 6 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 7 | Pb | Pb | Pb | Pb | Pb | Pb | Pb | Pb |\n   ==========================================\n 8 | Rb | Nb | Bb | Qb | Kb | Bb | Nb | Rb |\n   ==========================================\n     H    G    F    E    D    C    B    A\n";

  EXPECT_EQ(expectedBoard, testingDisplayBoard.displayBoard(true));
}