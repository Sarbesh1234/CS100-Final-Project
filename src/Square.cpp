#include "../header/Square.hpp"
#include <cstddef>

Square::Square(Piece* piece, pair<int, int> position) : piece(piece), position(position) {}

Piece* Square::getPiece() { return piece;}

pair<int, int> Square::getIndex() { return position;}

void Square::setPiece(Piece* piece) { this->piece = piece; }
