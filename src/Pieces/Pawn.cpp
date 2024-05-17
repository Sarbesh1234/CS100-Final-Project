#include "../../header/Pieces/Pawn.hpp"

Pawn::Pawn(Color color) : hasMoved(false) {
    this->color = color;
    this->symbol = 'P';
}

void Pawn::constructPossibleMoves(std::pair<int, int> currentPosition) {
    // check to see if the pawn has moved. If it has, it can only move one square forward
    // if it hasn't, it can move two squares forward

    this->possibleMoves.clear();

    std::list<std::pair<int, int> > mutations;

    mutations.push_back(std::make_pair(-1, 0)); // up
    mutations.push_back(std::make_pair(-1, -1)); // up left
    mutations.push_back(std::make_pair(-1, 1)); // up right

    if(not hasMoved) {
        mutations.push_back(std::make_pair(-2, 0)); // up 2
        hasMoved = true;
    }

    int row = currentPosition.first;
    int col = currentPosition.second;

    for (auto mutation : mutations) {
        int newRow = row + mutation.first;
        int newCol = col + mutation.second;

        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            this->possibleMoves.push_back(std::make_pair(newRow, newCol));
        }
    }

}