#pragma once

#include "../Piece.hpp"

class Rook : public Piece {
    public:
        Rook(Color);
        virtual void constructPossibleMoves(std::pair<int, int>) override;

};