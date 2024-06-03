#include "../header/Board.hpp"
#include "../header/Pieces/Rook.hpp"
#include "../header/Pieces/Knight.hpp"
#include "../header/Pieces/Bishop.hpp"
#include "../header/Pieces/King.hpp"
#include "../header/Pieces/Queen.hpp"
#include "../header/Pieces/Pawn.hpp"

using std::endl;

Board::Board() {
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      board[i][j] = new Square(nullptr, std::make_pair(i, j));
    }
  }
}

Board::~Board() {
}

void Board::initializeBoard() {
  board[0][0]->setPiece(new Rook(PieceColor::BLACK));
  board[0][1]->setPiece(new Knight(PieceColor::BLACK));
  board[0][2]->setPiece(new Bishop(PieceColor::BLACK));
  board[0][3]->setPiece(new King(PieceColor::BLACK));
  board[0][4]->setPiece(new Queen(PieceColor::BLACK));
  board[0][5]->setPiece(new Bishop(PieceColor::BLACK));
  board[0][6]->setPiece(new Knight(PieceColor::BLACK));
  board[0][7]->setPiece(new Rook(PieceColor::BLACK));

  for (int i = 0; i < 8; i++) {
    board[1][i]->setPiece(new Pawn(PieceColor::BLACK));
  }

  for (int i = 0; i < 8; i++) {
    board[6][i]->setPiece(new Pawn(PieceColor::WHITE));
  }

  board[7][0]->setPiece(new Rook(PieceColor::WHITE));
  board[7][1]->setPiece(new Knight(PieceColor::WHITE));
  board[7][2]->setPiece(new Bishop(PieceColor::WHITE));
  board[7][3]->setPiece(new King(PieceColor::WHITE));
  board[7][4]->setPiece(new Queen(PieceColor::WHITE));
  board[7][5]->setPiece(new Bishop(PieceColor::WHITE));
  board[7][6]->setPiece(new Knight(PieceColor::WHITE));
  board[7][7]->setPiece(new Rook(PieceColor::WHITE));

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

void Board::clearBoard() {
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if(board[i][j]->hasPiece()) {
        delete board[i][j]->getPiece();
        board[i][j]->setPiece(nullptr);
      }
    }
  }
}

void Board::reinitializeBoard(vector<pair<pair<int, int>, string>> symbolsAndLocs) {
  clearBoard();

  for(auto& symbolAndLocation: symbolsAndLocs) {
    int row = symbolAndLocation.first.first;
    int col = symbolAndLocation.first.second;

    Piece* newPiece = symbolToPiece(symbolAndLocation.second);

    board[row][col]->setPiece(newPiece);
  }
}

Piece* Board::symbolToPiece(const std::string& symbol) {
  switch(symbol[0]) {
    case 'K':
      if(symbol[1] == 'w') return new King(WHITE);
      return new King(BLACK);
    case 'Q':
      if(symbol[1] == 'w') return new Queen(WHITE);
      return new Queen(BLACK);
    case 'N':
      if(symbol[1] == 'w') return new Knight(WHITE);
      return new Knight(BLACK);
    case 'B':
      if(symbol[1] == 'w') return new Bishop(WHITE);
      return new Bishop(BLACK);
    case 'R':
      if(symbol[1] == 'w') return new Rook(WHITE);
      return new Rook(BLACK);
    case 'P':
      if(symbol[1] == 'w') return new Pawn(WHITE);
      return new Pawn(BLACK);
  }
}