#pragma once
#include "../Piece.hpp"

class King : public Piece {
    public:
        virtual void constructPossibleMoves(std::pair<int, int>) override;
        King(Color);
};