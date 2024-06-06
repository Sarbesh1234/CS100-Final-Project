#include "../../header/Pieces/Rook.hpp"
#include "../../header/Square.hpp"

Rook::Rook(PieceColor color) {
    this->symbol = "R";
    this->color = color;
}

Rook::~Rook() {}

void Rook::constructPossibleMoves(pair<int, int> currentPosition, Square* board[8][8]) {
    this->possibleMoves.clear();

    int row = currentPosition.first;
    int col = currentPosition.second;
    
    Square* currentSquare = nullptr;

    while(row < 7) {
      row++;
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

    while(row > 0) {
      row--;
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

    while(col < 7) {
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
    col = currentPosition.second;

    while(col > 0) {
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

}

