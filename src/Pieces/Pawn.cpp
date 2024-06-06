#include "../../header/Pieces/Pawn.hpp"

Pawn::Pawn(PieceColor color) : hasMoved(false) {
  this->color = color;
  this->symbol = "P";
}

Pawn::~Pawn() {}


void Pawn::constructPossibleMoves(pair<int, int> currentPosition, Square* board[8][8]) {
    // check to see if the pawn has moved. If it has, it can only move one square forward
    // if it hasn't, it can move two squares forward

  this->possibleMoves.clear();

    std::list<pair<int, int> > mutations;

    Square* checkSquare = nullptr;
    int checkSquareRow;
    int checkSquareCol;

    if(this->color == WHITE) {
        checkSquareRow = currentPosition.first-1;
        checkSquareCol = currentPosition.second;

        if (checkSquareRow >= 0 && checkSquareRow < 8 && checkSquareCol >= 0 && checkSquareCol < 8) {
            checkSquare = this->getNextSquare(checkSquareRow, checkSquareCol, board);
            if(!checkSquare->hasPiece()) {
                mutations.push_back(std::make_pair(-1, 0));
            }
        }
        
        //pawn can move diagonal if there is an enemy   
        checkSquareRow = currentPosition.first-1;
        checkSquareCol = currentPosition.second-1;

        if (checkSquareRow >= 0 && checkSquareRow < 8 && checkSquareCol >= 0 && checkSquareCol < 8) {
            checkSquare = this->getNextSquare(checkSquareRow, checkSquareCol, board);
            if(checkSquare && checkSquare->hasPiece() && !this->isPieceFriendly(checkSquare->getPiece())) {
                mutations.push_back(std::make_pair(-1, -1)); // up left
            }
        }

        checkSquareRow = currentPosition.first-1;
        checkSquareCol = currentPosition.second+1;

        if (checkSquareRow >= 0 && checkSquareRow < 8 && checkSquareCol >= 0 && checkSquareCol < 8) {
            checkSquare = this->getNextSquare(checkSquareRow, checkSquareCol, board);
            if(checkSquare && checkSquare->hasPiece() && !this->isPieceFriendly(checkSquare->getPiece())) {
                mutations.push_back(std::make_pair(-1, 1)); // up left
            }
        }

        hasMoved = !(currentPosition.first == 6);  

        if(not hasMoved) {
            checkSquareRow = currentPosition.first-2;
            checkSquareCol = currentPosition.second;

            if (checkSquareRow >= 0 && checkSquareRow < 8 && checkSquareCol >= 0 && checkSquareCol < 8) {
              checkSquare = this->getNextSquare(checkSquareRow, checkSquareCol, board);
                if(!checkSquare->hasPiece()) {
                  mutations.push_back(std::make_pair(-2, 0)); //move two squares 
              }
          }
        }
    }else {
        //black pawn
        checkSquareRow = currentPosition.first+1;
        checkSquareCol = currentPosition.second;

        if (checkSquareRow >= 0 && checkSquareRow < 8 && checkSquareCol >= 0 && checkSquareCol < 8) {
            checkSquare = this->getNextSquare(checkSquareRow, checkSquareCol, board);
            if(!checkSquare->hasPiece()) {
                mutations.push_back(std::make_pair(1, 0)); // down
            }
        }

        //pawn can move diagonal if there is an enemy   
        checkSquareRow = currentPosition.first+1;
        checkSquareCol = currentPosition.second-1;

        if (checkSquareRow >= 0 && checkSquareRow < 8 && checkSquareCol >= 0 && checkSquareCol < 8) {
            checkSquare = this->getNextSquare(checkSquareRow, checkSquareCol, board);
            if(checkSquare && checkSquare->hasPiece() && !this->isPieceFriendly(checkSquare->getPiece())) {
                mutations.push_back(std::make_pair(1, -1)); // down left
            }
        }

        checkSquareRow = currentPosition.first+1;
        checkSquareCol = currentPosition.second+1;

        if (checkSquareRow >= 0 && checkSquareRow < 8 && checkSquareCol >= 0 && checkSquareCol < 8) {
            checkSquare = this->getNextSquare(checkSquareRow, checkSquareCol, board);
            if(checkSquare && checkSquare->hasPiece() && !this->isPieceFriendly(checkSquare->getPiece())) {
                mutations.push_back(std::make_pair(1, 1)); // down right
            }
        }

    hasMoved = !(currentPosition.first == 1);  

    if (not hasMoved) {
      checkSquareRow = currentPosition.first+2;
      checkSquareCol = currentPosition.second;

        if (checkSquareRow >= 0 && checkSquareRow < 8 && checkSquareCol >= 0 && checkSquareCol < 8) {
          checkSquare = this->getNextSquare(checkSquareRow, checkSquareCol, board);
            if(!checkSquare->hasPiece()) {
              mutations.push_back(std::make_pair(2, 0)); //move two squares
            }
        }
    }
  }

  int row = currentPosition.first;
  int col = currentPosition.second;

  Square* currentSquare = nullptr;

  for (auto mutation : mutations) {
    int newRow = row + mutation.first;
    int newCol = col + mutation.second;

    currentSquare = this->getNextSquare(newRow, newCol, board);

    if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
      if (currentSquare && currentSquare->hasPiece()) {
        if (!this->isPieceFriendly(currentSquare->getPiece())) {
          this->possibleMoves.push_back(std::make_pair(newRow, newCol));
        }
      } else {
        this->possibleMoves.push_back(std::make_pair(newRow, newCol));
      }
    }
  }
}