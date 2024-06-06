#include "../header/DisplayBoard.hpp"
#include <sstream>

using std::endl;


DisplayBoard::DisplayBoard(Board* board): board(board) {
}

string DisplayBoard::displayBoard(bool flipped) {
  std::stringstream ss;

  // loop through the board and display the pieces in each square and go to the next
  // start each row with the number that is corresponds to
  string lineWidth = "   ==========================================";

  int startingIndex = 0;
  int endingIndex = 8;
  int increment = 1;
  if (flipped) {
    startingIndex = 7;
    endingIndex = -1;
    increment = -1;
  }
  ss << lineWidth << endl;
  for (int i = startingIndex; flipped ? i > endingIndex : i < endingIndex; i += increment) {
    // print the row number
    ss << " " << 8 - i << " ";

    ss << "|";
    for (int j = startingIndex; flipped ? j > endingIndex : j < endingIndex; j += increment) {
      // if piece does not exist, print a dash, otherwise print the piece
      Square* currentSquare = board->getSquare(i, j);
      if (currentSquare->getPiece() == nullptr) {
        ss << " -- ";
      } else {
        Piece* currentPiece = currentSquare->getPiece();
        ss << " " << currentPiece->getSymbol() << " ";
      }
      ss << "|";
    }
    ss << endl
       << lineWidth << endl;
  }

  // print the column letters
  if (flipped) {
    ss << "     H    G    F    E    D    C    B    A" << endl;
  } else {
    ss << "     A    B    C    D    E    F    G    H    " << endl;
  }
  return ss.str();
}