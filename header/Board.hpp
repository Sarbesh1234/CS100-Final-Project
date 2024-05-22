#pragma once
#include "Square.hpp"
#include <string>
#include <sstream>

using std::string;

class Board {
  Square board[8][8];

  public: 
    Board();
    string displayBoard(bool flipped);
};
