#include <gtest/gtest.h>
#include "Game.hpp"



//Test AskUserForMove() function
TEST(GameTest, AskUserForMove) {
    // Simulate user input
    std::istringstream input("B6\nA5\n");

    // Simulate output
    std::ostringstream output;

    // Set input and output streams for the game
    Game game(input, output);
    
    // Call the function to be tested
    game.askUserForMove();

    // Check if the output is as expected
    std::string expectedOutput = "Enter position of piece you want to move: \nChoose position to move piece to: \n";
    ASSERT_EQ(output.str(), expectedOutput);
}

//Test AskUserForMove() function with invalid input
TEST(GameTest, AskUserForMove_InvalidInput) {
    // Simulate user input
    std::istringstream input("1234\nC0\nJ5\nF6\nA23\nE9\nS6\nH4\n");

    // Simulate output
    std::ostringstream output;

    // Set input and output streams for the game
    Game game(input, output);
    
    // Call the function to be tested
    game.askUserForMove();

    // Check if the output is as expected
    std::string expectedOutput = "Enter position of piece you want to move: \nInvalid Move! Please enter a valid position: \n";
    expectedOutput += "Invalid Move! Please enter a valid position: \nInvalid Move! Please enter a valid position: \nChoose position ";
    expectedOutput += "to move piece to: \nInvalid Move! Please enter a valid position: \nInvalid Move! Please enter a valid position: ";
    expectedOutput += "\nInvalid Move! Please enter a valid position: \n";
    ASSERT_EQ(output.str(), expectedOutput);
}

//Test AskUserForMove() function with lowercase input
TEST(GameTest, AskUserForMove_LowercaseInput) {
    // Simulate user input
    std::istringstream input("b6\na5\n");

    // Simulate output
    std::ostringstream output;

    // Set input and output streams for the game
    Game game(input, output);
    
    // Call the function to be tested
    game.askUserForMove();

    // Check if the output is as expected
    std::string expectedOutput = "Enter position of piece you want to move: \nChoose position to move piece to: \n";
    ASSERT_EQ(output.str(), expectedOutput);
}




