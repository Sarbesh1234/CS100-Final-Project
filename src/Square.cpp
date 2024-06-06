#include "../header/Square.hpp"

#include <cstddef>

Square::Square() : piece(nullptr), position(std::make_pair(-1, -1)) {}
Square::Square(Piece* piece, pair<int, int> position) : piece(piece), position(position) {}

Square::~Square() {
}

Piece* Square::getPiece() { return piece; }

pair<int, int> Square::getIndex() { return position; }

void Square::setPiece(Piece* piece) { this->piece = piece; }

bool Square::hasPiece() const {
  return piece != nullptr;
}