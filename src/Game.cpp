#include "../header/Game.hpp"
#include <iostream>
#include <cctype>



void Game::startGame()
{
    
}

void Game::startNewGame()
{
    
}

void Game::loadSavedGame()
{
}

void Game::endGame()
{
    
}

void Game::saveGame()
{
}
void Game::askUserForMove()
{
    output << "Enter position of piece you want to move: " << endl;
    std::pair<int,int> toCoordinate = getMoveCoordinateHelper(input,output);
    output << "Choose position to move piece to: " << endl;
    std::pair<int,int> fromCoordinate = getMoveCoordinateHelper(input,output);

}

std::pair<int,int> Game::getMoveCoordinateHelper(istream& input,ostream& output) {
    string inputMove;
    std::pair<int,int> pair;
    while(input >> inputMove) {
        if(inputMove.size() == 2) {
            char inputChar = inputMove[0];
            char inputInt = inputMove[1];
            inputChar = toupper(inputChar);
            if (('A' <= inputChar && inputChar <= 'H')) {
                inputChar = inputChar - 16;
                if(inputInt >= 49 && inputInt <= 56) {
                    pair.first = inputChar - '0';
                    pair.second = inputInt - '0';
                    break;
                }
            }
        }
        output << "Invalid Move! Please enter a valid position: " << endl;
    }
    return pair;
}