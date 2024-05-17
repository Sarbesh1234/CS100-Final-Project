#pragma once

#include "../Piece.hpp"

class Knight: public Piece {
    public:
        Knight(Color);
        virtual void constructPossibleMoves(std::pair<int, int> currPosition) override;
};