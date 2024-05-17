#include "../header/Piece.hpp"

bool Piece::isValidMove(std::pair<int, int> move) const { 
    return std::find(possibleMoves.begin(), possibleMoves.end(), move) != possibleMoves.end(); 
}

std::string Piece::getSymbol() const { 
    return WHITE ? &"W" [ symbol] : &"B" [ symbol];
}