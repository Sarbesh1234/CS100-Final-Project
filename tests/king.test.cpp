#include "gtest/gtest.h"

#include "../header/Pieces/King.hpp"
#include "../src/Pieces/King.cpp"

/*  KingSuite   */


TEST(KingSuite, KingInMiddle) {
    King king(PieceColor::WHITE);
    king.constructPossibleMoves(std::make_pair(4, 4));
    
    // checking all 8 possible moves for the king
    EXPECT_TRUE(king.isValidMove(std::make_pair(3, 3)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(3, 4)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(3, 5)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(4, 3)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(4, 5)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(5, 3)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(5, 4)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(5, 5)));

    // checking invalid moves for the king
    EXPECT_FALSE(king.isValidMove(std::make_pair(4, 4)));
    EXPECT_FALSE(king.isValidMove(std::make_pair(0, 0)));
}

TEST(KingSuite, KingInCorner) {
    King king(PieceColor::WHITE);
    // top left corner
    king.constructPossibleMoves(std::make_pair(0, 0));
   
    EXPECT_TRUE(king.isValidMove(std::make_pair(0, 1)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(1, 0)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(1, 1)));

    // top right corner
    king.constructPossibleMoves(std::make_pair(0, 7));

    EXPECT_TRUE(king.isValidMove(std::make_pair(0, 6)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(1, 6)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(1, 7)));

    // bottom left corner
    king.constructPossibleMoves(std::make_pair(7, 0));

    EXPECT_TRUE(king.isValidMove(std::make_pair(6, 0)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(6, 1)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(7, 1)));

    // bottom right corner
    king.constructPossibleMoves(std::make_pair(7, 7));

    
    EXPECT_TRUE(king.isValidMove(std::make_pair(6, 6)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(6, 7)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(7, 6)));
}

TEST(KingSuite, KingOnSide) {
    King king(PieceColor::WHITE);
    // top side
    king.constructPossibleMoves(std::make_pair(0, 4));
    
    EXPECT_TRUE(king.isValidMove(std::make_pair(0, 3)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(1, 3)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(1, 4)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(1, 5)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(0, 5)));

    // bottom side
    king.constructPossibleMoves(std::make_pair(4, 0));
    
    EXPECT_TRUE(king.isValidMove(std::make_pair(3, 0)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(3, 1)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(4, 1)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(5, 1)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(5, 0)));

    // left side
    king.constructPossibleMoves(std::make_pair(7, 4));
    
    EXPECT_TRUE(king.isValidMove(std::make_pair(7, 3)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(6, 3)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(6, 4)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(6, 5)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(7, 5)));
    
    // right side
    king.constructPossibleMoves(std::make_pair(4, 7));

    EXPECT_TRUE(king.isValidMove(std::make_pair(3, 7)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(3, 6)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(4, 6)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(5, 6)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(5, 7)));
}

TEST(KingSuite, KingShouldNotBeAbleToMoveInTheSquareOfFriendlyPiece) {
    King king(PieceColor::WHITE);
    Square* board[8][8];

    // setting up the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }

    // setting up the friendly piece
    board[3][3] = new Square(new King(PieceColor::WHITE), std::make_pair(3, 3));

    king.constructPossibleMoves(std::make_pair(4, 3), board);

    // valid moves
    EXPECT_TRUE(king.isValidMove(std::make_pair(3, 2)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(3, 4)));

    // checking if the king can move to the square of the friendly piece
    EXPECT_FALSE(king.isValidMove(std::make_pair(3, 3)));
}

TEST(KingSuite, KingShouldBeAbleToMoveInTheSquareOfEnemyPiece) {
    King king(PieceColor::WHITE);
    Square* board[8][8];

    // setting up the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }

    // setting up the friendly piece
    board[3][3] = new Square(new King(PieceColor::BLACK), std::make_pair(3, 3));

    king.constructPossibleMoves(std::make_pair(4, 3), board);

    // valid moves
    EXPECT_TRUE(king.isValidMove(std::make_pair(3, 2)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(3, 4)));

    // checking if the king can move to the square of the friendly piece
    EXPECT_TRUE(king.isValidMove(std::make_pair(3, 3)));


    EXPECT_FALSE(king.isValidMove(std::make_pair(5, 7)));
}

TEST(KingSuite, KingSymbol) {
    King whiteKing(PieceColor::WHITE);
    King blackKing(PieceColor::BLACK);

    EXPECT_EQ(whiteKing.getSymbol(), "Kw");
    EXPECT_EQ(blackKing.getSymbol(), "Kb");
}