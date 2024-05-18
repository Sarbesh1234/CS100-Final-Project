#pragma once

#include "../Piece.hpp"

class Rook : public Piece {
    public:
        Rook(PieceColor);
        virtual void constructPossibleMoves(pair<int, int>) override;

};