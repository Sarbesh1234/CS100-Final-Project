#include <gtest/gtest.h>
#include "Game.hpp" 

// Test startGame() function
TEST(GameTest, StartGame) {
    // Simulate user input
    std::istringstream input("start\nname\nplay1\nplayer2\nquit\nY\nN");

    // Simulate output
    std::ostringstream output;

    // Set input and output streams for the game
    Game game(input, output);

    // Call the function to be tested
    game.startGame();

    // Check if the output is as expected
    std::string expectedOutput = "Do you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): Please enter your game name: Please enter Player 1's name: Please enter Player 2's name: Welcome to the game! play1 (White) will start the game.\n   ==========================================\n 8 | Rb | Nb | Bb | Kb | Qb | Bb | Nb | Rb |\n   ==========================================\n 7 | Pb | Pb | Pb | Pb | Pb | Pb | Pb | Pb |\n   ==========================================\n 6 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 5 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 4 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 3 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 2 | Pw | Pw | Pw | Pw | Pw | Pw | Pw | Pw |\n   ==========================================\n 1 | Rw | Nw | Bw | Kw | Qw | Bw | Nw | Rw |\n   ==========================================\n     A    B    C    D    E    F    G    H    \n\nIt is play1's turn.\nEnter \"quit\" to end the game or \"move\" to proceed.\nAre you sure you want to end the game?\nEnter 'Y' to confirm, or 'N' to continue playing: Do you want to save the game before ending? (Y/N): Game ended. Thank you for playing!\n";

    ASSERT_EQ(output.str(), expectedOutput);
}

// Test startNewGame() function
 TEST(GameTest, StartNewGame) {
     // Simulate user input
     std::istringstream input("start\nGame\nRish\nJustin\nquit\nY\nN");

     // Simulate output
     std::ostringstream output;

     // Set input and output streams for the game
     Game game(input, output);

     // Call the function to be tested
     game.startNewGame();

     // Check if the output is as expected
     std::string expectedOutput = "Please enter your game name: Please enter Player 1's name: Please enter Player 2's name: Welcome to the game! Game (White) will start the game.\n   ==========================================\n 8 | Rb | Nb | Bb | Kb | Qb | Bb | Nb | Rb |\n   ==========================================\n 7 | Pb | Pb | Pb | Pb | Pb | Pb | Pb | Pb |\n   ==========================================\n 6 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 5 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 4 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 3 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 2 | Pw | Pw | Pw | Pw | Pw | Pw | Pw | Pw |\n   ==========================================\n 1 | Rw | Nw | Bw | Kw | Qw | Bw | Nw | Rw |\n   ==========================================\n     A    B    C    D    E    F    G    H    \n\nIt is Game's turn.\nEnter \"quit\" to end the game or \"move\" to proceed.\nInvalid input.\n   ==========================================\n 8 | Rb | Nb | Bb | Kb | Qb | Bb | Nb | Rb |\n   ==========================================\n 7 | Pb | Pb | Pb | Pb | Pb | Pb | Pb | Pb |\n   ==========================================\n 6 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 5 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 4 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 3 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 2 | Pw | Pw | Pw | Pw | Pw | Pw | Pw | Pw |\n   ==========================================\n 1 | Rw | Nw | Bw | Kw | Qw | Bw | Nw | Rw |\n   ==========================================\n     A    B    C    D    E    F    G    H    \n\nIt is Game's turn.\nEnter \"quit\" to end the game or \"move\" to proceed.\nAre you sure you want to end the game?\nEnter 'Y' to confirm, or 'N' to continue playing: Do you want to save the game before ending? (Y/N): Game ended. Thank you for playing!\n";

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
    std::string expectedOutput = "Do you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): This is not valid input, please try again.\nDo you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): Please enter your game name: Please enter Player 1's name: Please enter Player 2's name: Welcome to the game! Rish (White) will start the game.\n   ==========================================\n 8 | Rb | Nb | Bb | Kb | Qb | Bb | Nb | Rb |\n   ==========================================\n 7 | Pb | Pb | Pb | Pb | Pb | Pb | Pb | Pb |\n   ==========================================\n 6 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 5 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 4 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 3 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 2 | Pw | Pw | Pw | Pw | Pw | Pw | Pw | Pw |\n   ==========================================\n 1 | Rw | Nw | Bw | Kw | Qw | Bw | Nw | Rw |\n   ==========================================\n     A    B    C    D    E    F    G    H    \n\nIt is Rish's turn.\nEnter \"quit\" to end the game or \"move\" to proceed.\nAre you sure you want to end the game?\nEnter 'Y' to confirm, or 'N' to continue playing: Do you want to save the game before ending? (Y/N): Game ended. Thank you for playing!\n";
     

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
    std::string expectedOutput = "Do you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): Please enter a choice.\nDo you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): Please enter your game name: Please enter Player 1's name: Please enter Player 2's name: Welcome to the game! Rish (White) will start the game.\n   ==========================================\n 8 | Rb | Nb | Bb | Kb | Qb | Bb | Nb | Rb |\n   ==========================================\n 7 | Pb | Pb | Pb | Pb | Pb | Pb | Pb | Pb |\n   ==========================================\n 6 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 5 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 4 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 3 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 2 | Pw | Pw | Pw | Pw | Pw | Pw | Pw | Pw |\n   ==========================================\n 1 | Rw | Nw | Bw | Kw | Qw | Bw | Nw | Rw |\n   ==========================================\n     A    B    C    D    E    F    G    H    \n\nIt is Rish's turn.\nEnter \"quit\" to end the game or \"move\" to proceed.\nAre you sure you want to end the game?\nEnter 'Y' to confirm, or 'N' to continue playing: Do you want to save the game before ending? (Y/N): Game ended. Thank you for playing!\n";
     

     ASSERT_EQ(output.str(), expectedOutput);
 }

 // Test will load test.json from saves folder
 TEST(GameTest, StartGame_ContinueWithTestJSON) {
     // Simulate user input
     std::istringstream input("continue\ntest\nquit\nY\nN");

     // Simulate output
     std::ostringstream output;

     // Set input and output streams for the game
     Game game(input, output);

     // Call the function to be tested
     game.startGame();

     // Check if the output is as expected
     std::string expectedOutput = "Do you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): ";
     expectedOutput += "What saved game would you like to load?\n";
     expectedOutput += "\n";
     expectedOutput += "test\ntwoKings\n"; // list of games in saves
     expectedOutput += "Game: Game Name\n";
     expectedOutput += "Player 1: Rish\n";
     expectedOutput += "Player 2: Justin\n";
     expectedOutput += "Current move belongs to: Rish\n";
     expectedOutput += "   ==========================================\n 8 | Rb | Nb | Bb | Kb | Qb | Bb | Nb | Rb |\n   ==========================================\n 7 | Pb | Pb | Pb | Pb | Pb | Pb | Pb | Pb |\n   ==========================================\n 6 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 5 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 4 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 3 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 2 | Pw | Pw | Pw | Pw | Pw | Pw | Pw | Pw |\n   ==========================================\n 1 | Rw | Nw | Bw | Kw | Qw | Bw | Nw | Rw |\n   ==========================================\n     A    B    C    D    E    F    G    H    \n";
     expectedOutput += "\n";
     expectedOutput += "It is Rish's turn.\n";
     expectedOutput += "Enter \"quit\" to end the game or \"move\" to proceed.\n";
     expectedOutput += "Are you sure you want to end the game?\n";
     expectedOutput += "Enter 'Y' to confirm, or 'N' to continue playing: ";
     expectedOutput += "Do you want to save the game before ending? (Y/N): ";
     expectedOutput += "Game ended. Thank you for playing!\n";


     ASSERT_EQ(output.str(), expectedOutput);
}

TEST(GameTest, StartGame_ContinueWithInvalidJSON) {
    // Simulate user input
     std::istringstream input("continue\ninvalid\ntwoKings\nquit\nY\nN");

     // Simulate output
     std::ostringstream output;

     // Set input and output streams for the game
     Game game(input, output);

     // Call the function to be tested
     game.startGame();

     // Check if the output is as expected
     std::string expectedOutput = "Do you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): ";
     expectedOutput += "What saved game would you like to load?\n";
     expectedOutput += "\n";
     expectedOutput += "test\ntwoKings\n"; // list of games in saves
     expectedOutput += "Could not find filename. Please try again.\n";
     expectedOutput += "Game: 1v1\n";
     expectedOutput += "Player 1: Andrew\n";
     expectedOutput += "Player 2: Justin\n";
     expectedOutput += "Current move belongs to: Justin\n";
     expectedOutput += "   ==========================================\n 1 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 2 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 3 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 4 | -- | -- | -- | Kb | -- | -- | -- | -- |\n   ==========================================\n 5 | -- | -- | -- | -- | Kw | -- | -- | -- |\n   ==========================================\n 6 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 7 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 8 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n     H    G    F    E    D    C    B    A\n";
     expectedOutput += "\n";
     expectedOutput += "It is Justin's turn.\n";
     expectedOutput += "Enter \"quit\" to end the game or \"move\" to proceed.\n";
     expectedOutput += "Are you sure you want to end the game?\n";
     expectedOutput += "Enter 'Y' to confirm, or 'N' to continue playing: ";
     expectedOutput += "Do you want to save the game before ending? (Y/N): ";
     expectedOutput += "Game ended. Thank you for playing!\n";


     ASSERT_EQ(output.str(), expectedOutput);
}


//Test AskUserForMove() function
TEST(GameTest, AskUserForMove) {
    // Simulate user input
    std::istringstream input("start\ngame\njustin\nrish\nmove\nA2\nA3\nquit\nY\nN");

    // Simulate output
    std::ostringstream output;

    // Set input and output streams for the game
    Game game(input, output);
    
    // Call the function to be tested

    game.startGame();

    // Check if the output is as expected
    std::string expectedOutput = "Do you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): Please enter your game name: Please enter Player 1's name: Please enter Player 2's name: Welcome to the game! justin (White) will start the game.\n   ==========================================\n 8 | Rb | Nb | Bb | Kb | Qb | Bb | Nb | Rb |\n   ==========================================\n 7 | Pb | Pb | Pb | Pb | Pb | Pb | Pb | Pb |\n   ==========================================\n 6 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 5 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 4 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 3 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 2 | Pw | Pw | Pw | Pw | Pw | Pw | Pw | Pw |\n   ==========================================\n 1 | Rw | Nw | Bw | Kw | Qw | Bw | Nw | Rw |\n   ==========================================\n     A    B    C    D    E    F    G    H    \n\nIt is justin's turn.\nEnter \"quit\" to end the game or \"move\" to proceed.\nEnter position of piece you want to move (ex e5): \nChoose position to move the piece to: \n   ==========================================\n 1 | Rw | Nw | Bw | Qw | Kw | Bw | Nw | Rw |\n   ==========================================\n 2 | Pw | Pw | Pw | Pw | Pw | Pw | Pw | -- |\n   ==========================================\n 3 | -- | -- | -- | -- | -- | -- | -- | Pw |\n   ==========================================\n 4 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 5 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 6 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 7 | Pb | Pb | Pb | Pb | Pb | Pb | Pb | Pb |\n   ==========================================\n 8 | Rb | Nb | Bb | Qb | Kb | Bb | Nb | Rb |\n   ==========================================\n     H    G    F    E    D    C    B    A\n\nIt is rish's turn.\nEnter \"quit\" to end the game or \"move\" to proceed.\nAre you sure you want to end the game?\nEnter 'Y' to confirm, or 'N' to continue playing: Do you want to save the game before ending? (Y/N): Game ended. Thank you for playing!\n";
    ASSERT_EQ(output.str(), expectedOutput);
}

//Test AskUserForMove() function with invalid input
TEST(GameTest, AskUserForMove_InvalidInput) {
    // Simulate user input
    std::istringstream input("start\ngame\njustin\nrish\nmove\nbad\nA2\n\nD8\nA2\nA3\nquit\nY\nN");

    // Simulate output
    std::ostringstream output;

    // Set input and output streams for the game
    Game game(input, output);
    
    // Call the function to be tested
    game.startGame();

    // Check if the output is as expected
    std::string expectedOutput = "Do you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): Please enter your game name: Please enter Player 1's name: Please enter Player 2's name: Welcome to the game! justin (White) will start the game.\n   ==========================================\n 8 | Rb | Nb | Bb | Kb | Qb | Bb | Nb | Rb |\n   ==========================================\n 7 | Pb | Pb | Pb | Pb | Pb | Pb | Pb | Pb |\n   ==========================================\n 6 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 5 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 4 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 3 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 2 | Pw | Pw | Pw | Pw | Pw | Pw | Pw | Pw |\n   ==========================================\n 1 | Rw | Nw | Bw | Kw | Qw | Bw | Nw | Rw |\n   ==========================================\n     A    B    C    D    E    F    G    H    \n\nIt is justin's turn.\nEnter \"quit\" to end the game or \"move\" to proceed.\nEnter position of piece you want to move (ex e5): \nInvalid Move! Please enter a valid position: \nChoose position to move the piece to: \nInvalid move. Please try again.\nEnter position of piece you want to move (ex e5): \nChoose position to move the piece to: \n   ==========================================\n 1 | Rw | Nw | Bw | Qw | Kw | Bw | Nw | Rw |\n   ==========================================\n 2 | Pw | Pw | Pw | Pw | Pw | Pw | Pw | -- |\n   ==========================================\n 3 | -- | -- | -- | -- | -- | -- | -- | Pw |\n   ==========================================\n 4 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 5 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 6 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 7 | Pb | Pb | Pb | Pb | Pb | Pb | Pb | Pb |\n   ==========================================\n 8 | Rb | Nb | Bb | Qb | Kb | Bb | Nb | Rb |\n   ==========================================\n     H    G    F    E    D    C    B    A\n\nIt is rish's turn.\nEnter \"quit\" to end the game or \"move\" to proceed.\nAre you sure you want to end the game?\nEnter 'Y' to confirm, or 'N' to continue playing: Do you want to save the game before ending? (Y/N): Game ended. Thank you for playing!\n";
    ASSERT_EQ(output.str(), expectedOutput);
}

//Test AskUserForMove() function with lowercase input
TEST(GameTest, AskUserForMove_LowercaseInput) {
     // Simulate user input
    std::istringstream input("start\ngame\njustin\nrish\nmove\n\na2\na3\nquit\nY\nN");

    // Simulate output
    std::ostringstream output;

    // Set input and output streams for the game
    Game game(input, output);
    
    // Call the function to be tested
    game.startGame();

    // Check if the output is as expected
    std::string expectedOutput = "Do you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): Please enter your game name: Please enter Player 1's name: Please enter Player 2's name: Welcome to the game! justin (White) will start the game.\n   ==========================================\n 8 | Rb | Nb | Bb | Kb | Qb | Bb | Nb | Rb |\n   ==========================================\n 7 | Pb | Pb | Pb | Pb | Pb | Pb | Pb | Pb |\n   ==========================================\n 6 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 5 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 4 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 3 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 2 | Pw | Pw | Pw | Pw | Pw | Pw | Pw | Pw |\n   ==========================================\n 1 | Rw | Nw | Bw | Kw | Qw | Bw | Nw | Rw |\n   ==========================================\n     A    B    C    D    E    F    G    H    \n\nIt is justin's turn.\nEnter \"quit\" to end the game or \"move\" to proceed.\nEnter position of piece you want to move (ex e5): \nChoose position to move the piece to: \n   ==========================================\n 1 | Rw | Nw | Bw | Qw | Kw | Bw | Nw | Rw |\n   ==========================================\n 2 | Pw | Pw | Pw | Pw | Pw | Pw | Pw | -- |\n   ==========================================\n 3 | -- | -- | -- | -- | -- | -- | -- | Pw |\n   ==========================================\n 4 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 5 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 6 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 7 | Pb | Pb | Pb | Pb | Pb | Pb | Pb | Pb |\n   ==========================================\n 8 | Rb | Nb | Bb | Qb | Kb | Bb | Nb | Rb |\n   ==========================================\n     H    G    F    E    D    C    B    A\n\nIt is rish's turn.\nEnter \"quit\" to end the game or \"move\" to proceed.\nAre you sure you want to end the game?\nEnter 'Y' to confirm, or 'N' to continue playing: Do you want to save the game before ending? (Y/N): Game ended. Thank you for playing!\n";
    ASSERT_EQ(output.str(), expectedOutput);
}

//Test AskUserForMove() function with empty input
TEST(GameTest, AskUserForMove_InvalidInputAgain) {
    // Simulate user input
    std::istringstream input("start\ngame\njustin\nrish\nmove\n\n\nA2\nA3\nquit\nY\nN");

    // Simulate output
    std::ostringstream output;

    // Set input and output streams for the game
    Game game(input, output);

    // Call the function to be tested
    game.startGame();

    // Check if the output is as expected
    std::string expectedOutput = "Do you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): Please enter your game name: Please enter Player 1's name: Please enter Player 2's name: Welcome to the game! justin (White) will start the game.\n   ==========================================\n 8 | Rb | Nb | Bb | Kb | Qb | Bb | Nb | Rb |\n   ==========================================\n 7 | Pb | Pb | Pb | Pb | Pb | Pb | Pb | Pb |\n   ==========================================\n 6 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 5 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 4 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 3 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 2 | Pw | Pw | Pw | Pw | Pw | Pw | Pw | Pw |\n   ==========================================\n 1 | Rw | Nw | Bw | Kw | Qw | Bw | Nw | Rw |\n   ==========================================\n     A    B    C    D    E    F    G    H    \n\nIt is justin's turn.\nEnter \"quit\" to end the game or \"move\" to proceed.\nEnter position of piece you want to move (ex e5): \nChoose position to move the piece to: \n   ==========================================\n 1 | Rw | Nw | Bw | Qw | Kw | Bw | Nw | Rw |\n   ==========================================\n 2 | Pw | Pw | Pw | Pw | Pw | Pw | Pw | -- |\n   ==========================================\n 3 | -- | -- | -- | -- | -- | -- | -- | Pw |\n   ==========================================\n 4 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 5 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 6 | -- | -- | -- | -- | -- | -- | -- | -- |\n   ==========================================\n 7 | Pb | Pb | Pb | Pb | Pb | Pb | Pb | Pb |\n   ==========================================\n 8 | Rb | Nb | Bb | Qb | Kb | Bb | Nb | Rb |\n   ==========================================\n     H    G    F    E    D    C    B    A\n\nIt is rish's turn.\nEnter \"quit\" to end the game or \"move\" to proceed.\nAre you sure you want to end the game?\nEnter 'Y' to confirm, or 'N' to continue playing: Do you want to save the game before ending? (Y/N): Game ended. Thank you for playing!\n";
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

