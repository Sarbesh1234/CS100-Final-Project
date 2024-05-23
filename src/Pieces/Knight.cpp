#include "../../header/Pieces/Knight.hpp"

Knight::Knight(PieceColor color) {
  this->symbol = "N";
  this->color = color;
}

void Knight::constructPossibleMoves(pair<int, int> currentPosition, Square* board[8][8]) {
  this->possibleMoves.clear();

  std::list<pair<int, int> > mutations;

  mutations.push_back(std::make_pair(2, 1));    // right down
  mutations.push_back(std::make_pair(2, -1));   // right up
  mutations.push_back(std::make_pair(-2, 1));   // left down
  mutations.push_back(std::make_pair(-2, -1));  // left up
  mutations.push_back(std::make_pair(1, 2));    // down right
  mutations.push_back(std::make_pair(1, -2));   // down left
  mutations.push_back(std::make_pair(-1, 2));   // up right
  mutations.push_back(std::make_pair(-1, -2));  // up left

  int row = currentPosition.first;
  int col = currentPosition.second;

  Square* currentSquare = nullptr;

  for (auto mutation : mutations) {
    int newRow = row + mutation.first;
    int newCol = col + mutation.second;

    if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
      currentSquare = this->getNextSquare(newRow, newCol, board);

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