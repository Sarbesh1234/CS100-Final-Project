#include "../header/Board.hpp"
#include "../header/Pieces/Rook.hpp"
#include "../header/Pieces/Knight.hpp"
#include "../header/Pieces/Bishop.hpp"
#include "../header/Pieces/King.hpp"
#include "../header/Pieces/Queen.hpp"
#include "../header/Pieces/Pawn.hpp"

using std::endl;

Board::Board() {
  board[0][0] = new Square(new Rook(PieceColor::BLACK), std::make_pair(0, 0));
  board[0][1] = new Square(new Knight(PieceColor::BLACK), std::make_pair(0, 1));
  board[0][2] = new Square(new Bishop(PieceColor::BLACK), std::make_pair(0, 2));
  board[0][3] = new Square(new King(PieceColor::BLACK), std::make_pair(0, 3));
  board[0][4] = new Square(new Queen(PieceColor::BLACK), std::make_pair(0, 4));
  board[0][5] = new Square(new Bishop(PieceColor::BLACK), std::make_pair(0, 5));
  board[0][6] = new Square(new Knight(PieceColor::BLACK), std::make_pair(0, 6));
  board[0][7] = new Square(new Rook(PieceColor::BLACK), std::make_pair(0, 7));

  for (int i = 0; i < 8; i++) {
    board[1][i] = new Square(new Pawn(PieceColor::BLACK), std::make_pair(1, i));
  }

  for (int i = 2; i < 6; i++) {
    for (int j = 0; j < 8; j++) {
      board[i][j] = new Square(nullptr, std::make_pair(i, j));
    }
  }

  for (int i = 0; i < 8; i++) {
    board[6][i] = new Square(new Pawn(PieceColor::WHITE), std::make_pair(6, i));
  }

  board[7][0] = new Square(new Rook(PieceColor::WHITE), std::make_pair(7, 0));
  board[7][1] = new Square(new Knight(PieceColor::WHITE), std::make_pair(7, 1));
  board[7][2] = new Square(new Bishop(PieceColor::WHITE), std::make_pair(7, 2));
  board[7][3] = new Square(new King(PieceColor::WHITE), std::make_pair(7, 3));
  board[7][4] = new Square(new Queen(PieceColor::WHITE), std::make_pair(7, 4));
  board[7][5] = new Square(new Bishop(PieceColor::WHITE), std::make_pair(7, 5));
  board[7][6] = new Square(new Knight(PieceColor::WHITE), std::make_pair(7, 6));
  board[7][7] = new Square(new Rook(PieceColor::WHITE), std::make_pair(7, 7));


}

Board::~Board() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      delete board[i][j];
    }
  }
}

string Board::displayBoard(bool flipped) {
  std::stringstream ss;

  // loop through the board and display the pieces in each new Square and go to the next
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
      if (board[i][j]->getPiece() == nullptr) {
        ss << " -- ";
      } else {
        Piece* currentPiece = board[i][j]->getPiece();
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

std::pair<bool, PieceColor> Board::checkMate() {
  
  int count = 0;
  bool white, black;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (board[i][j]->getPiece()->getSymbol() == "wK") {
        white = true;
        count++;
      }

      else if (board[i][j]->getPiece()->getSymbol() == "bK") {
        black = true;
        count++;
      }  
    }
  }

  PieceColor winnerColor;

  if (white && !black ) {
    winnerColor = PieceColor::WHITE;
    return make_pair(true, winnerColor);
  }

  else if (black && !white) {
    winnerColor = PieceColor::BLACK;
    return make_pair(true, winnerColor);  
  } 


  return make_pair(false, winnerColor);
}