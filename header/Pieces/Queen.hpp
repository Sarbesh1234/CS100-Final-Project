#pragma once

#include "../Piece.hpp"

class Queen : public Piece {
    public:
        virtual void constructPossibleMoves(pair<int, int> currPosition) override;  //constructs possible moves for the piece
        Queen(PieceColor);  //constructor
};