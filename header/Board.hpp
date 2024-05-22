#pragma once
#include "Square.hpp"
#include <string>
#include <sstream>

using std::string;

class Board {
  Square* board[8][8];

  public: 
    Board();
    ~Board();
    Board(Square* newBoard[8][8]);
    string displayBoard(bool flipped);
};
