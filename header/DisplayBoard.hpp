#pragma once
#include "Board.hpp"
#include <string>

class Board;

using std::string;

class DisplayBoard {
  private:
    Board board;
  public:
    DisplayBoard(Board& board);
    string displayBoard(bool flipped);
};