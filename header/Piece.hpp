enum Color {WHITE, BLACK};

#pragma once
#include <vector>
#include <list>

class Piece {
    protected:
        std::vector<std::pair<int, int> > possibleMoves;    //list of possible moves
        char symbol;    //symbol of the piece
        enum Color color;    //color of the piece
        std::string getSymbol() const;  //returns the symbol of the piece
    public:
        // constructPossibleMoves needs to be public!!!
        virtual void constructPossibleMoves(std::pair<int, int>) = 0;  //abstract function to construct possible moves (unique to each piece)
        bool isValidMove(std::pair<int, int>) const;
};

extern Color ColorEnum;