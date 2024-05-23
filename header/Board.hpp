#pragma once
#include "Square.hpp"
#include <string>
#include <sstream>
#include "Player.hpp"
#include "Game.hpp"

using std::string;

class Board {
  Square* board[8][8];

  public: 
    Board();
    ~Board();
    string displayBoard(bool flipped);
    std::pair<bool, PieceColor> checkMate();
};
