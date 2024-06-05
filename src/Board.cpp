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
}

Square* Board::getSquare(int row, int col) const {
  return board[row][col];
}

std::pair<bool, PieceColor> Board::checkMate() {
  
  int count = 0;
  bool white, black;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (board[i][j]->getPiece()->getSymbol() == "Kw") {
        white = true;
        count++;
      }

      else if (board[i][j]->getPiece()->getSymbol() == "Kb") {
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

bool Board::updateBoard(pair<int, int> startPoint, pair<int, int> endPoint) {
  Piece* movePiece = this->getSquare(startPoint.first, startPoint.second)->getPiece();
  Square* destination = this->getSquare(endPoint.first, endPoint.second);

  if (movePiece == nullptr) {return false;} 
  else if (!movePiece->isValidMove(endPoint))  {
    return false;
  }

  else if (destination->hasPiece()) {
    capturePiece(endPoint);
    return true;
  }

  destination->setPiece(movePiece);
  //delete this->board[sPoint.first][sPoint.second]->getPiece();
  this->board[startPoint.first][startPoint.second]->setPiece(nullptr);
  return true;
}

void Board::capturePiece(pair<int, int> point) {
  return;
}