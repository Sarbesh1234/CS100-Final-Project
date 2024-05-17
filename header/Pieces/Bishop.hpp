#pragma once

#include "../Piece.hpp"

class Bishop : public Piece {
    public:
        Bishop(Color);  //constructor
        void constructPossibleMoves(std::pair<int, int>);  //constructs possible moves for the bishop
};