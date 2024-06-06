#include "../../header/Pieces/Bishop.hpp"
#include "../../header/Square.hpp"

Bishop::Bishop(PieceColor color) {
  this->color = color;
  this->symbol = "B";
}

Bishop::~Bishop() {}

void Bishop::constructPossibleMoves(pair<int, int> currentPosition, Square* board[8][8]) {
  this->possibleMoves.clear();

  int row = currentPosition.first;
  int col = currentPosition.second;

  Square* currentSquare = nullptr;

  while (row < 7 && col < 7) {
    row++;
    col++;
    currentSquare = this->getNextSquare(row, col, board);
    if (currentSquare && currentSquare->hasPiece()) {
      if (!this->isPieceFriendly(currentSquare->getPiece())) {
        this->possibleMoves.push_back(std::make_pair(row, col));
      }
      break;
    } else {
      this->possibleMoves.push_back(std::make_pair(row, col));
    }
  }

  row = currentPosition.first;
  col = currentPosition.second;
  while (row > 0 && col > 0) {
    row--;
    col--;
    currentSquare = this->getNextSquare(row, col, board);
    if (currentSquare && currentSquare->hasPiece()) {
      if (!this->isPieceFriendly(currentSquare->getPiece())) {
        this->possibleMoves.push_back(std::make_pair(row, col));
      }
      break;
    } else {
      this->possibleMoves.push_back(std::make_pair(row, col));
    }
  }
  row = currentPosition.first;
  col = currentPosition.second;
  while (row < 7 && col > 0) {
    row++;
    col--;

    currentSquare = this->getNextSquare(row, col, board);
    if (currentSquare && currentSquare->hasPiece()) {
      if (!this->isPieceFriendly(currentSquare->getPiece())) {
        this->possibleMoves.push_back(std::make_pair(row, col));
      }
      break;
    } else {
      this->possibleMoves.push_back(std::make_pair(row, col));
    }
  }
  row = currentPosition.first;
  col = currentPosition.second;
  while (row > 0 && col < 7) {
    row--;
    col++;

    currentSquare = this->getNextSquare(row, col, board);
    if (currentSquare && currentSquare->hasPiece()) {
      if (!this->isPieceFriendly(currentSquare->getPiece())) {
        this->possibleMoves.push_back(std::make_pair(row, col));
      }
      break;
    } else {
      this->possibleMoves.push_back(std::make_pair(row, col));
    }
  }
}