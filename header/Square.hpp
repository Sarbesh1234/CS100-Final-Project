#pragma once

#include "Piece.hpp"
#include <utility>

class Square {
    private:
        Piece* piece;
        std::pair<int, int> position;
    public:
        Square();
        Square(Piece* piece, std::pair<int, int> position);
        Piece* getPiece();
        std::pair<int, int> getIndex();
        void setPiece(Piece* piece);
        void setIndex(std::pair<int, int> index);
};