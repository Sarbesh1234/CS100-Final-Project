#include "../header/Game.hpp"
#include "Player.cpp"
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

void Game::startGame()
{
    string userInput;
    bool invalidInput = true;
    while (invalidInput)
        output << "Do you want to start a game (ENTER START) or continue a previous one? (ENTER CONTINUE):";
    input >> userInput;
    if (userInput == "START")
    { 
        startNewGame();
        invalidInput = false;
    }

    else if (userInput == "CONTINUE")
    {
        loadSavedGame();
        invalidInput = false;
    }

    else
    {
        output << "This is not valid input, please try again." << endl;
    }
}

void Game::startNewGame()
{
    string player1name;
    string player2name;
    string gameInput;
    output << "Please enter your game name:";
    input >> gameName;
    output << "Please enter Player 1's name:";
    input >> player1name;
    player1 = Player(player1name, "White");
    output << "Please enter Player 2's name:";
    input >> player2name;
    player2 = Player(player2name, "Black");

    while (gameInput != "QUIT")
    {
        input >> gameInput;
        //transform(gameInput.begin(), gameInput.end(), gameInput.begin(), 
              //::toupper);
        if (gameInput != "QUIT") {
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

    string inputMove;
    string outputMove;

    int inpOne;
    int inpTwo;

    int outOne;
    int outTwo;

    output << "Enter position of piece you want to move: " << endl;
    while(getline(input,inputMove)) {
        if(inputMove.size() == 2) {
            char inputChar = inputMove[0];
            char inputInt = inputMove[1];

            if (('a' <= inputChar && inputChar <= 'h') || ('A' <= inputChar && inputChar <= 'H')) {
                toupper(inputChar);
                inputChar - 16;

                if(inputInt >= 49 && inputInt <= 56) {
                    inpOne = inputChar;
                    inpTwo = inputInt;
                    break;
                }
            }
        }
        output << "Invalid Move! Please enter a valid position: " << endl;
    }

    output << "Choose position to move piece to: " << endl;
    while(getline(input,outputMove)) {
        if(outputMove.size() == 2) {
            char inputChar = outputMove[0];
            char inputInt = outputMove[1];

            if (('a' <= inputChar && inputChar <= 'h') || ('A' <= inputChar && inputChar <= 'H')) {
                toupper(inputChar);
                inputChar - 16;

                if(inputInt >= 49 && inputInt <= 56) {
                    inpOne = inputChar;
                    inpTwo = inputInt;
                    break;
                }
            }
        }
        output << "Invalid Move! Please enter a valid position: " << endl;
    }

    pair<int,int> inputInt(inpOne,inpTwo);
    pair<int,int> outputInt(outOne,outTwo);

}