#include "../header/Piece.hpp"

bool Piece::isValidMove(pair<int, int> move) const { 
    return std::find(possibleMoves.begin(), possibleMoves.end(), move) != possibleMoves.end(); 
}

std::string Piece::getSymbol() const {
    return color == WHITE ? symbol + "w" : symbol + "b";
}