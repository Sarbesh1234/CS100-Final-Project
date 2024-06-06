

enum PieceColor { WHITE,
                  BLACK };
#pragma once
#include <algorithm>
#include <list>
#include <string>
#include <vector>

class Square;

using std::pair;

inline const char* PieceColorToString(PieceColor color) {
  switch (color) {
    case WHITE:
      return "White";
    case BLACK:
      return "Black";
    default:
      return "";
  }
}

inline const PieceColor StringToPieceColor(const std::string& color) {
  if (color == "White")
    return WHITE;
  else if (color == "Black")
    return BLACK;
  else
    return WHITE;
}

class Piece {
    protected:
        std::vector<pair<int, int> > possibleMoves;    //list of possible moves
        std::string symbol;    //symbol of the piece
        PieceColor color;    //color of the piece
        Square* getNextSquare(int row, int col, Square* board[8][8]) const;
    public:
        // constructPossibleMoves needs to be public!!!
        virtual void constructPossibleMoves(pair<int, int>, Square* [8][8] = nullptr) = 0;  //abstract function to construct possible moves (unique to each piece)
        virtual ~Piece() {}
        bool isPieceFriendly(Piece* piece) const;
        bool isValidMove(pair<int, int>) const;
        std::string getSymbol() const;  //returns the symbol of the piece
        PieceColor getColor() const;    //returns the color of the piece
};

extern PieceColor ColorEnum;