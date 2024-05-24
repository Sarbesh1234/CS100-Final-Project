#include <gtest/gtest.h>
#include "Game.hpp" 

// Test startGame() function
TEST(GameTest, StartGame) {
    // Simulate user input
    std::istringstream input("start\nplay1\nplayer2\nquit\nquit");

    // Simulate output
    std::ostringstream output;

    // Set input and output streams for the game
    Game game(input, output);

    // Call the function to be tested
    game.startGame();

    // Check if the output is as expected
    std::string expectedOutput = "Do you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): Please enter your game name: Please enter Player 1's name: Please enter Player 2's name: Enter \"quit\" to end the game.\n";

    ASSERT_EQ(output.str(), expectedOutput);
}

// Test startNewGame() function
 TEST(GameTest, StartNewGame) {
     // Simulate user input
     std::istringstream input("Game\nRish\nJustin\nquit");

     // Simulate output
     std::ostringstream output;

     // Set input and output streams for the game
     Game game(input, output);

     // Call the function to be tested
     game.startNewGame();

     // Check if the output is as expected
     std::string expectedOutput = "Please enter your game name: ";
     expectedOutput += "Please enter Player 1's name: ";
     expectedOutput += "Please enter Player 2's name: " ;
     expectedOutput += "Enter \"quit\" to end the game.\n" ;

     ASSERT_EQ(output.str(), expectedOutput);
 }

 // Test startGame() function with invalid input
TEST(GameTest, StartGame_InvalidInput) {
     // Simulate user input
     std::istringstream input("blahblah\nstart\nGame\nRish\nJustin\nquit");

     // Simulate output
     std::ostringstream output;

     // Set input and output streams for the game
     Game game(input, output);

     // Call the function to be tested
     game.startGame();

     // Check if the output prompts the user to enter valid input
    std::string expectedOutput = "Do you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): ";
    expectedOutput += "This is not valid input, please try again.\n";
    expectedOutput += "Do you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): ";
    expectedOutput += "Please enter your game name: ";
    expectedOutput += "Please enter Player 1's name: ";
    expectedOutput += "Please enter Player 2's name: ";
    expectedOutput += "Enter \"quit\" to end the game.\n" ;
     

     ASSERT_EQ(output.str(), expectedOutput);
 }

 // Test startGame() function with empty input
 TEST(GameTest, StartGame_EmptyInput) {
     // Simulate user input
     std::istringstream input("\nstart\nGame\nRish\nJustin\nquit");

     // Simulate output
     std::ostringstream output;

     // Set input and output streams for the game
     Game game(input, output);

     // Call the function to be tested
     game.startGame();

     // Check if the output prompts the user to enter valid input
    std::string expectedOutput = "Do you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): ";
    expectedOutput += "Please enter a choice.\n";
    expectedOutput += "Do you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): ";
    expectedOutput += "Please enter your game name: ";
    expectedOutput += "Please enter Player 1's name: ";
    expectedOutput += "Please enter Player 2's name: ";
    expectedOutput += "Enter \"quit\" to end the game.\n" ;
     

     ASSERT_EQ(output.str(), expectedOutput);
 }

 // Test startNewGame() function with quit input immediately
 TEST(GameTest, StartGame_Continue) {
     // Simulate user input
     std::istringstream input("continue\n");

     // Simulate output
     std::ostringstream output;

     // Set input and output streams for the game
     Game game(input, output);

     // Call the function to be tested
     game.startGame();

     // Check if the output is as expected
     std::string expectedOutput = "Do you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): ";
     expectedOutput += "What game would you like to load?\n";

     ASSERT_EQ(output.str(), expectedOutput);
 }



 int main(int argc, char **argv) {
     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
 }

