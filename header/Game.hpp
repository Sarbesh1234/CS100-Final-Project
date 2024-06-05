#pragma once

#include <ostream>
#include <istream>
#include <string>
#include "Board.hpp"
#include "Piece.hpp"
#include "Player.hpp"
#include "DisplayBoard.hpp"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "dirent.h"

using namespace std;

class Game {
    private:
    Player player1;
    Player player2;
    string gameName;
    Board board;
    Player& currentPlayer;
    istream& input;
    ostream& output;
    pair<int,int> getMoveCoordinateHelper();

    public: 
        Game(istream& input, ostream& output) 
        : input(input), output(output), player1(Player(PieceColor::WHITE, "Player 1")), 
        player2(Player(PieceColor::BLACK, "Player 2")), currentPlayer(player1)
        {};
        
        void startGame();
        void startNewGame();
        void loadSavedGame();
        void endGame(Player*);
        void quitGame();
        bool saveGame();
        string convertGameToJson();
        void setPlayer1(Player player) {this->player1 = player;}
        void setPlayer2(Player player) {this->player2 = player;}
        void askUserForMove();
        Player* getPlayerOne() {return &player1; }
        Player* getPlayerTwo() { return &player2; }
};
