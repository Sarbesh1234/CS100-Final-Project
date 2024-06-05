#include "../../header/Pieces/Pawn.hpp"

Pawn::Pawn(PieceColor color) : hasMoved(false) {
  this->color = color;
  this->symbol = "P";
}

Pawn::~Pawn() {}

void Pawn::constructPossibleMoves(pair<int, int> currentPosition, Square* board[8][8]) {
  // check to see if the pawn has moved. If it has, it can only move one square forward
  // if it hasn't, it can move two squares forward

  this->possibleMoves.clear();

  std::list<pair<int, int> > mutations;

  if (this->color == WHITE) {
    mutations.push_back(std::make_pair(-1, 0));   // up
    mutations.push_back(std::make_pair(-1, -1));  // up left
    mutations.push_back(std::make_pair(-1, 1));   // up right

    if (not hasMoved) {
      mutations.push_back(std::make_pair(-2, 0));  // up 2
      hasMoved = true;
    }
  } else {
    mutations.push_back(std::make_pair(1, 0));   // down
    mutations.push_back(std::make_pair(1, -1));  // down left
    mutations.push_back(std::make_pair(1, 1));   // down right

    if (not hasMoved) {
      mutations.push_back(std::make_pair(2, 0));  // down 2
      hasMoved = true;
    }
  }

  int row = currentPosition.first;
  int col = currentPosition.second;

  Square* currentSquare = nullptr;

  for (auto mutation : mutations) {
    int newRow = row + mutation.first;
    int newCol = col + mutation.second;

    currentSquare = this->getNextSquare(newRow, newCol, board);

    if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
      if (currentSquare && currentSquare->hasPiece()) {
        if (!this->isPieceFriendly(currentSquare->getPiece())) {
          this->possibleMoves.push_back(std::make_pair(newRow, newCol));
        }
      } else {
        this->possibleMoves.push_back(std::make_pair(newRow, newCol));
      }
    }
  }
}