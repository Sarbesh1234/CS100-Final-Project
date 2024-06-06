#pragma once

#include "Piece.hpp"
#include <utility>

using std::pair;

class Square {
    private:
        Piece* piece;
        pair<int, int> position;
    public:
        Square();
        Square(Piece* piece, pair<int, int> position);
        ~Square();
        Piece* getPiece();
        pair<int, int> getIndex();
        void setPiece(Piece* piece);
        void setIndex(pair<int, int> index);
        bool hasPiece() const;
};