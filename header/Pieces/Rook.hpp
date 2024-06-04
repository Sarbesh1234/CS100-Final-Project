#pragma once

#include "../Piece.hpp"
#include "../Square.hpp"
class Rook : public Piece {
 public:
  Rook(PieceColor);
  ~Rook();
  virtual void constructPossibleMoves(pair<int, int>, Square* [8][8] = nullptr) override;
};