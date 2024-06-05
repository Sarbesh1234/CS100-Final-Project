#include "../header/Piece.hpp"

bool Piece::isValidMove(pair<int, int> move) const {
  return std::find(possibleMoves.begin(), possibleMoves.end(), move) != possibleMoves.end();
}

std::string Piece::getSymbol() const {
  return color == WHITE ? symbol + "w" : symbol + "b";
}

bool Piece::isPieceFriendly(Piece* piece) const {
  if (!piece) {
    return false;
  }
  return piece->color == this->color;
}

PieceColor Piece::getColor() const {
  return color;
}

Square* Piece::getNextSquare(int row, int col, Square* board[8][8]) const {
  if (board && row >= 0 && row < 8 && col >= 0 && col < 8) {
    return board[row][col];
  }
  return nullptr;
}