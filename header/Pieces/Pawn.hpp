#pragma once

#include "../Piece.hpp"
class Pawn : public Piece {
    private:
        bool hasMoved;  //flag to check if the pawn has moved
    public:
        virtual void constructPossibleMoves(pair<int, int> currPosition, Square* [8][8] = nullptr) override; //constructs possible moves for the piece
        Pawn(PieceColor);  //constructor
};