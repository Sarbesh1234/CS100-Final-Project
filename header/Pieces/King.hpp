#pragma once
#include "../Piece.hpp"
#include "../Square.hpp"
class King : public Piece {
    public:
        virtual void constructPossibleMoves(pair<int, int>, Square* [8][8] = nullptr) override;
        King(PieceColor);
};