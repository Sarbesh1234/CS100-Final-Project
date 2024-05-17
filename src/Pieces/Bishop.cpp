#include "../../header/Pieces/Bishop.hpp"

Bishop::Bishop(Color color) {
    this->color = color;
    this->symbol = 'B';
}

void Bishop::constructPossibleMoves(std::pair<int, int> currentPosition) {
    this->possibleMoves.clear();

    int row = currentPosition.first;
    int col = currentPosition.second;

    while(row < 7 && col < 7) {
        row++;
        col++;
        this->possibleMoves.push_back(std::make_pair(row, col));
    }
    row = currentPosition.first;
    col = currentPosition.second;
    while(row > 0 && col > 0) {
        row--;
        col--;
        this->possibleMoves.push_back(std::make_pair(row, col));
    }
    row = currentPosition.first;
    col = currentPosition.second;
    while(row < 7 && col > 0) {
        row++;
        col--;
        this->possibleMoves.push_back(std::make_pair(row, col));
    }
    row = currentPosition.first;
    col = currentPosition.second;
    while(row > 0 && col < 7) {
        row--;
        col++;
        this->possibleMoves.push_back(std::make_pair(row, col));
    }
}