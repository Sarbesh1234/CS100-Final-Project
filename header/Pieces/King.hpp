#pragma once
#include "../Piece.hpp"

class King : public Piece {
    public:
        virtual void constructPossibleMoves(pair<int, int>) override;
        King(PieceColor);
};