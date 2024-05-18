#pragma once

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include "Player.hpp"
#include "Board.hpp"

using namespace std;

class Game {
    private:
    Player player1;
    Player player2;
    string gameName;
    //Board board;
    Player* currentPlayer;
    iostream& input;
    iostream& output;

    public: 
        Game(iostream& input, iostream& output) 
        : input(input), output(output), player1(Player("White", "Player 1")), 
        player2(Player("Black", "Player 2")), currentPlayer(&player1)
        {};
        void startGame();
        void startNewGame();
        void loadSavedGame();
        void endGame();
        void saveGame();
        void askUserForMove();
};
