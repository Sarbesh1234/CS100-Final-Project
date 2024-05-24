#pragma once
#include <sstream>
#include <string>

#include "Square.hpp"
#include "Player.hpp"

using std::string;

class Board {
  Square* board[8][8];

 public:
  Board();
  ~Board();
  Square* getSquare(int row, int col) const;
  std::pair<bool, PieceColor> checkMate();
};
