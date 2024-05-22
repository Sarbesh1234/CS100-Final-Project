#pragma once

#include "../Piece.hpp"

class Bishop : public Piece {
    public:
        Bishop(PieceColor);  //constructor
        virtual void constructPossibleMoves(pair<int, int>, Square* [8][8] = nullptr);  //constructs possible moves for the bishop
};