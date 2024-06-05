#pragma once
#include <sstream>
#include <string>

#include "Square.hpp"
#include "Player.hpp"

using std::string;
using std::vector;

class Board {
  Square* board[8][8];
  ostream& output;

 public:
  Board(ostream&);
  ~Board();
  Square* getSquare(int row, int col) const;
  std::pair<bool, PieceColor> checkMate();
  bool updateBoard(pair<int, int> startPoint, pair<int, int> endPoint);
  void capturePiece(pair<int, int> point);
  void reconstructPossibleMoves();
  void initializeBoard();
  void clearBoard();
  void reinitializeBoard(vector<pair<pair<int, int>, string>>& piecesAndLocs);
  Piece* symbolToPiece(const string& symbol);

  private:
  string determinePiece(const string& symbol);

};
