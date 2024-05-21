#include "Game.hpp"

using namespace std;

void Game::startGame()
{
    string userInput;
    bool invalidInput = true;
    while (invalidInput) {
        output << "Do you want to start a game (ENTER START) or continue a previous one? (ENTER CONTINUE): ";
        input >> userInput;
        if (userInput == "") {   
            break;
        }

        else if (userInput == "START") {   
            startNewGame();
            invalidInput = false;
        }

        else if (userInput == "CONTINUE") {
            loadSavedGame();
            invalidInput = false;
        }

        else {
            output << "This is not valid input, please try again." << endl;
        }
    }
}

void Game::startNewGame()
{
    string player1name;
    string player2name;
    string gameInput;
    output << "Please enter your game name: ";
    input >> gameName;
    output << "Please enter Player 1's name: ";
    input >> player1name;
    player1 = Player(player1name, "White");
    output << "Please enter Player 2's name: " ;
    input >> player2name;
    player2 = Player(player2name, "Black");

    while (gameInput != "QUIT")
    {
        input >> gameInput;
        //transform(gameInput.begin(), gameInput.end(), gameInput.begin(), ::toupper);
        if (gameInput != "QUIT")
        {
            askUserForMove();
        }
    }
}

void Game::loadSavedGame()
{
}

void Game::endGame()
{
    char choice;
    cout << "Are you sure you want to end the game?" << endl;
    cout << "Enter 'Y' to confirm, or 'N' to continue playing: ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        // Ask if the user wants to save the game before ending
        char saveChoice;
        cout << "Do you want to save the game before ending? (Y/N): ";
        cin >> saveChoice;
        if (saveChoice == 'Y' || saveChoice == 'y')
        {
            saveGame();
        }
        cout << "Game ended. Thank you for playing!" << endl;
    }
    else if (choice == 'N' || choice == 'n')
    {
        askUserForMove();
    }
    else
    {
        cout << "Invalid choice. Please enter 'Y' or 'N'." << endl;
        endGame();
    }
}

void Game::saveGame()
{
}
void Game::askUserForMove()
{
}
