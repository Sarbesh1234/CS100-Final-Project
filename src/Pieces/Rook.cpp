#include "../../header/Pieces/Rook.hpp"

Rook::Rook(PieceColor color) {
    this->symbol = "R";
    this->color = color;
}

void Rook::constructPossibleMoves(pair<int, int> currentPosition, Square* [8][8]) {
    this->possibleMoves.clear();

    int row = currentPosition.first;
    int col = currentPosition.second;

    while(row < 7) {
        row++;
        this->possibleMoves.push_back(std::make_pair(row, col));
    }
    row = currentPosition.first;
    while(row > 0) {
        row--;
        this->possibleMoves.push_back(std::make_pair(row, col));
    }
    row = currentPosition.first;
    while(col < 7) {
        col++;
        this->possibleMoves.push_back(std::make_pair(row, col));
    }
    col = currentPosition.second;
    while(col > 0) {
        col--;
        this->possibleMoves.push_back(std::make_pair(row, col));
    }

}

