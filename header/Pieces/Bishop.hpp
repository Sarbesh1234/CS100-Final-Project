#pragma once

#include "../Piece.hpp"

class Bishop : public Piece {
    public:
        Bishop(PieceColor);  //constructor
        void constructPossibleMoves(pair<int, int>);  //constructs possible moves for the bishop
};