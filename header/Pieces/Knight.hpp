#pragma once

#include "../Piece.hpp"

class Knight: public Piece {
    public:
        Knight(PieceColor);
        virtual void constructPossibleMoves(pair<int, int> currPosition) override;
};