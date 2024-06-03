#include <gtest/gtest.h>
#include "Game.hpp" 

// Test startGame() function
TEST(GameTest, StartGame) {
    // Simulate user input
    std::istringstream input("start\nplay1\nplayer2\nquit\nY\nN");

    // Simulate output
    std::ostringstream output;

    // Set input and output streams for the game
    Game game(input, output);

    // Call the function to be tested
    game.startGame();

    // Check if the output is as expected
    std::string expectedOutput = "Do you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): Please enter your game name: Please enter Player 1's name: Please enter Player 2's name: Enter \"quit\" to end the game.\nEnter position of piece you want to move: \nInvalid Move! Please enter a valid position: \nChoose position to move piece to: \n";

    ASSERT_EQ(output.str(), expectedOutput);
}

// Test startNewGame() function
 TEST(GameTest, StartNewGame) {
     // Simulate user input
     std::istringstream input("Game\nRish\nJustin\nquit\nY\nN");

     // Simulate output
     std::ostringstream output;

     // Set input and output streams for the game
     Game game(input, output);

     // Call the function to be tested
     game.startNewGame();

     // Check if the output is as expected
     std::string expectedOutput = "Please enter your game name: Please enter Player 1's name: Please enter Player 2's name: Enter \"quit\" to end the game.\nAre you sure you want to end the game?\nEnter 'Y' to confirm, or 'N' to continue playing: Do you want to save the game before ending? (Y/N): Game ended. Thank you for playing!\n";

     ASSERT_EQ(output.str(), expectedOutput);
 }

 // Test startGame() function with invalid input
TEST(GameTest, StartGame_InvalidInput) {
     // Simulate user input
     std::istringstream input("blahblah\nstart\nGame\nRish\nJustin\nquit\nY\nN");

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
    expectedOutput += "Are you sure you want to end the game?\n";
    expectedOutput += "Enter 'Y' to confirm, or 'N' to continue playing: ";
    expectedOutput += "Do you want to save the game before ending? (Y/N): ";
    expectedOutput += "Game ended. Thank you for playing!\n";
     

     ASSERT_EQ(output.str(), expectedOutput);
 }

 // Test startGame() function with empty input
 TEST(GameTest, StartGame_EmptyInput) {
     // Simulate user input
     std::istringstream input("\nstart\nGame\nRish\nJustin\nquit\nY\nN");

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
    expectedOutput += "Are you sure you want to end the game?\n";
    expectedOutput += "Enter 'Y' to confirm, or 'N' to continue playing: ";
    expectedOutput += "Do you want to save the game before ending? (Y/N): ";
    expectedOutput += "Game ended. Thank you for playing!\n";
     

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

//Test AskUserForMove() function with empty input
TEST(GameTest, AskUserForMove_InvalidInputAgain) {
    // Simulate user input
    std::istringstream input("90\nE3\n78\nG5\n");

    // Simulate output
    std::ostringstream output;

    // Set input and output streams for the game
    Game game(input, output);

    // Call the function to be tested
    game.askUserForMove();

    // Check if the output is as expected
    std::string expectedOutput = "Enter position of piece you want to move: \nInvalid Move! Please enter a valid position: \nChoose position to move piece to: \nInvalid Move! Please enter a valid position: \n";
    ASSERT_EQ(output.str(), expectedOutput);
}


TEST(GameTest, SaveGame_RegularDefaultGameBoard) {
    // Simulate user input
    std::istringstream input("Game Name\nRish\nJustin\nquit\nY\nN");

    // Simulate output
    std::ostringstream output;

    // Set input and output streams for the game
    Game game(input, output);

    game.startNewGame();

    // Call the function to be tested
    string jsonGame = game.convertGameToJson();
    string expectedJson = "{\"gameName\":\"Game Name\",\"player1\":{\"name\":\"Rish\",\"color\":\"White\",\"currentPlayer\":true},\"player2\":{\"name\":\"Justin\",\"color\":\"Black\",\"currentPlayer\":false},\"board\":[{\"location\":[0,0],\"piece\":\"Rb\"},{\"location\":[0,1],\"piece\":\"Nb\"},{\"location\":[0,2],\"piece\":\"Bb\"},{\"location\":[0,3],\"piece\":\"Kb\"},{\"location\":[0,4],\"piece\":\"Qb\"},{\"location\":[0,5],\"piece\":\"Bb\"},{\"location\":[0,6],\"piece\":\"Nb\"},{\"location\":[0,7],\"piece\":\"Rb\"},{\"location\":[1,0],\"piece\":\"Pb\"},{\"location\":[1,1],\"piece\":\"Pb\"},{\"location\":[1,2],\"piece\":\"Pb\"},{\"location\":[1,3],\"piece\":\"Pb\"},{\"location\":[1,4],\"piece\":\"Pb\"},{\"location\":[1,5],\"piece\":\"Pb\"},{\"location\":[1,6],\"piece\":\"Pb\"},{\"location\":[1,7],\"piece\":\"Pb\"},{\"location\":[6,0],\"piece\":\"Pw\"},{\"location\":[6,1],\"piece\":\"Pw\"},{\"location\":[6,2],\"piece\":\"Pw\"},{\"location\":[6,3],\"piece\":\"Pw\"},{\"location\":[6,4],\"piece\":\"Pw\"},{\"location\":[6,5],\"piece\":\"Pw\"},{\"location\":[6,6],\"piece\":\"Pw\"},{\"location\":[6,7],\"piece\":\"Pw\"},{\"location\":[7,0],\"piece\":\"Rw\"},{\"location\":[7,1],\"piece\":\"Nw\"},{\"location\":[7,2],\"piece\":\"Bw\"},{\"location\":[7,3],\"piece\":\"Kw\"},{\"location\":[7,4],\"piece\":\"Qw\"},{\"location\":[7,5],\"piece\":\"Bw\"},{\"location\":[7,6],\"piece\":\"Nw\"},{\"location\":[7,7],\"piece\":\"Rw\"}]}";

    EXPECT_EQ(jsonGame, expectedJson);
}

