#include "../header/Square.hpp"
#include <cstddef>


Square::Square() : piece(nullptr), position(std::make_pair(0, 0)) {}

Square::Square(Piece* piece, std::pair<int, int> position) : piece(piece), position(position) {}

Piece* Square::getPiece() { return piece;}

std::pair<int, int> Square::getIndex() { return position;}

void Square::setPiece(Piece* piece) { this->piece = piece; }
