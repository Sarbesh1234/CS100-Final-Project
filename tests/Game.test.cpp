#include "gtest/gtest.h"
#include "../header/Game.hpp"

class GameTest : public ::testing::Test {
protected:
  std::stringstream testInput;
  std::stringstream testOutput;
};

TEST_F(GameTest, StartGameAsksForInput) {
  Game game(testInput, testOutput);
  testInput << "START\n";
  game.startGame();
  std::string input = testInput.str();
  EXPECT_TRUE(input.find("START") != std::string::npos);
  EXPECT_TRUE(input.find("CONTINUE") != std::string::npos);
}

TEST_F(GameTest, StartGameValidStartInput) {
  Game game(testInput, testOutput);
  testInput << "START\nNewGameName\nPlayer1\nPlayer2\n";
  game.startGame();
  std::string output = testOutput.str();
  EXPECT_TRUE(output.find("game name") != std::string::npos);
  EXPECT_TRUE(output.find("Player 1's name") != std::string::npos);
  EXPECT_TRUE(output.find("Player 2's name") != std::string::npos);
}

TEST_F(GameTest, StartGameValidContinueInput) {
  Game game(testInput, testOutput);
  testInput << "CONTINUE\n";
  game.startGame();
}

TEST_F(GameTest, StartGameInvalidInput) {
  Game game(testInput, testOutput);
  testInput << "INVALID\nSTART\n";
  game.startGame();
  std::string output = testOutput.str();
  EXPECT_TRUE(output.find("This is not valid input") != std::string::npos);
  EXPECT_TRUE(output.find("game name") != std::string::npos); // Valid input after invalid is processed
}

TEST_F(GameTest, StartNewGameAsksForGameName) {
  Game game(testInput, testOutput);
  testInput << "START\n";
  game.startGame();
  std::string output = testOutput.str();
  EXPECT_TRUE(output.find("game name") != std::string::npos);
}

TEST_F(GameTest, StartNewGameAsksForPlayerNames) {
  Game game(testInput, testOutput);
  testInput << "START\nNewGameName\n";
  game.startGame();
  std::string output = testOutput.str();
  EXPECT_TRUE(output.find("Player 1's name") != std::string::npos);
  EXPECT_TRUE(output.find("Player 2's name") != std::string::npos);
}