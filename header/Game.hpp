#pragma once

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include "Player.hpp"
#include "Board.hpp"
#include "Piece.hpp"

using namespace std;

class Game {
    private:
    Player player1;
    Player player2;
    string gameName;
    //Board board;
    Player& currentPlayer;
    istream& input;
    ostream& output;

    public: 
        Game(istream& input, ostream& output) 
        : input(input), output(output), player1(Player(PieceColor::WHITE, "Player 1")), 
        player2(Player(PieceColor::BLACK, "Player 2")), currentPlayer(player1)
        {};
        
        void startGame();
        void startNewGame();
        void loadSavedGame();
        void endGame();
        void saveGame();
        void askUserForMove();
};
