#pragma once
#include "Board.hpp"
#include <string>

class DisplayBoard {
  private:
    Board* board;
  public:
    DisplayBoard(Board* board);
    string displayBoard(bool flipped);
};