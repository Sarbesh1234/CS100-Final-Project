#include "../../header/Pieces/King.hpp"

King::King(PieceColor color) {
  this->color = color;
  this->symbol = "K";
}

King::~King() {}

void King::constructPossibleMoves(pair<int, int> currentPosition, Square* board[8][8]) {
  this->possibleMoves.clear();

  std::list<pair<int, int> > mutations;

  mutations.push_back(std::make_pair(0, 1));    // right
  mutations.push_back(std::make_pair(1, 1));    // right down
  mutations.push_back(std::make_pair(1, 0));    // down
  mutations.push_back(std::make_pair(1, -1));   // left down
  mutations.push_back(std::make_pair(0, -1));   // left
  mutations.push_back(std::make_pair(-1, -1));  // left up
  mutations.push_back(std::make_pair(-1, 0));   // up
  mutations.push_back(std::make_pair(-1, 1));   // right up

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
