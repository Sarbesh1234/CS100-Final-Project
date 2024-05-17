#include "../../header/Pieces/Queen.hpp"

Queen::Queen(Color color) {
    this->color = color;
    this->symbol = 'Q';
}

void Queen::constructPossibleMoves(std::pair<int, int> currentPosition) {
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
    while(col < 7) {
        col++;
        this->possibleMoves.push_back(std::make_pair(row, col));
    }
    col = currentPosition.second;
    while(col > 0) {
        col--;
        this->possibleMoves.push_back(std::make_pair(row, col));
    }

    row = currentPosition.first;
    col = currentPosition.second;

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