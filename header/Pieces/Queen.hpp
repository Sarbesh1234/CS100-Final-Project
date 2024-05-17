#pragma once

#include "../Piece.hpp"

class Queen : public Piece {
    public:
        virtual void constructPossibleMoves(std::pair<int, int> currPosition) override;  //constructs possible moves for the piece
        Queen(Color);  //constructor
};