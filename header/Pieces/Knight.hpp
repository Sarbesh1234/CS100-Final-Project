#pragma once

#include "../Piece.hpp"
#include "../Square.hpp"

class Knight: public Piece {
    public:
        Knight(PieceColor);
        ~Knight();
        virtual void constructPossibleMoves(pair<int, int> currPosition, Square* [8][8] = nullptr) override;
};