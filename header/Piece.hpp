

enum PieceColor {WHITE, BLACK};
#pragma once
#include <vector>
#include <list>
#include <string>
#include <algorithm>

class Square;

using std::pair;

class Piece {
    protected:
        std::vector<pair<int, int> > possibleMoves;    //list of possible moves
        std::string symbol;    //symbol of the piece
        PieceColor color;    //color of the piece
        Square* getNextSquare(int row, int col, Square* board[8][8]) const;
    public:
        // constructPossibleMoves needs to be public!!!
        virtual void constructPossibleMoves(pair<int, int>, Square* [8][8] = nullptr) = 0;  //abstract function to construct possible moves (unique to each piece)
        bool isPieceFriendly(Piece* piece) const;
        bool isValidMove(pair<int, int>) const;
        std::string getSymbol() const;  //returns the symbol of the piece
};

extern PieceColor ColorEnum;