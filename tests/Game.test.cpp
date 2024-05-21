#include <gtest/gtest.h>
#include "Game.hpp" 

// Test startGame() function
TEST(GameTest, StartGame) {
    // Simulate user input
    std::istringstream input("START\n");

    // Simulate output
    std::ostringstream output;

    // Set input and output streams for the game
    Game game(input, output);

    // Call the function to be tested
    game.startGame();

    // Check if the output is as expected
    std::string expectedOutput = "Please enter your game name: ";
    expectedOutput += "Please enter Player 1's name: ";
    expectedOutput += "Please enter Player 2's name:" ;

    ASSERT_EQ(output.str(), expectedOutput);
}

// Test startNewGame() function
TEST(GameTest, StartNewGame) {
    // Simulate user input
    std::istringstream input("QUIT\n");

    // Simulate output
    std::ostringstream output;

    // Set input and output streams for the game
    Game game(input, output);

    // Call the function to be tested
    game.startNewGame();

    // Check if the output is as expected
    std::string expectedOutput = "Please enter your game name: ";
    expectedOutput += "Please enter Player 1's name: ";
    expectedOutput += "Please enter Player 2's name:" ;

    ASSERT_EQ(output.str(), expectedOutput);
}

// Test startGame() function with invalid input
TEST(GameTest, StartGame_InvalidInput) {
    // Simulate user input
    std::istringstream input("INVALID\nSTART\n");

    // Simulate output
    std::ostringstream output;

    // Set input and output streams for the game
    Game game(input, output);

    // Call the function to be tested
    game.startGame();

    // Check if the output prompts the user to enter valid input
    std::string expectedOutput = "This is not valid input, please try again.\n";
    expectedOutput += "Please enter your game name: ";
    expectedOutput += "Please enter Player 1's name: ";
    expectedOutput += "Please enter Player 2's name:" ;

    ASSERT_EQ(output.str(), expectedOutput);
}

// Test startGame() function with empty input
TEST(GameTest, StartGame_EmptyInput) {
    // Simulate user input
    std::istringstream input("");

    // Simulate output
    std::ostringstream output;

    // Set input and output streams for the game
    Game game(input, output);

    // Call the function to be tested
    game.startGame();

    // Check if the output prompts the user to enter valid input
    std::string expectedOutput = "Please enter your game name: ";
    expectedOutput += "Please enter Player 1's name: ";
    expectedOutput += "Please enter Player 2's name:" ;

    ASSERT_EQ(output.str(), expectedOutput);
}

// Test startNewGame() function with quit input immediately
TEST(GameTest, StartNewGame_QuitImmediately) {
    // Simulate user input
    std::istringstream input("QUIT\n");

    // Simulate output
    std::ostringstream output;

    // Set input and output streams for the game
    Game game(input, output);

    // Call the function to be tested
    game.startNewGame();

    // Check if the output is as expected
    std::string expectedOutput = "Please enter your game name: ";
    expectedOutput += "Please enter Player 1's name: ";
    expectedOutput += "Please enter Player 2's name:" ;

    ASSERT_EQ(output.str(), expectedOutput);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

