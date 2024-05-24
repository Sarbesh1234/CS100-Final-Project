#include "gtest/gtest.h"

#include "../header/Pieces/Bishop.hpp"
#include "../src/Pieces/Bishop.cpp"




TEST(BishopSuit, BishopInMiddle) {
    Bishop bishop(PieceColor::WHITE);
    // checking all 13 possible moves for the bishop
    bishop.constructPossibleMoves(std::make_pair(4, 4));

    EXPECT_TRUE(bishop.isValidMove(std::make_pair(5, 5)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(6, 6)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(7, 7)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(3, 3)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(2, 2)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(1, 1)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(0, 0)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(5, 3)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(6, 2)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(7, 1)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(3, 5)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(2, 6)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(1, 7)));

    EXPECT_FALSE(bishop.isValidMove(std::make_pair(4, 4)));
    EXPECT_FALSE(bishop.isValidMove(std::make_pair(4, 5)));
}

TEST(BishopSuite, BishopInCorner) {
    Bishop bishop(PieceColor::WHITE);
    // top left corner
    bishop.constructPossibleMoves(std::make_pair(0, 0));

    EXPECT_TRUE(bishop.isValidMove(std::make_pair(1, 1)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(2, 2)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(3, 3)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(4, 4)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(5, 5)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(6, 6)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(7, 7)));

    EXPECT_FALSE(bishop.isValidMove(std::make_pair(0, 0)));
    EXPECT_FALSE(bishop.isValidMove(std::make_pair(0, 1)));
}

TEST(BishopSuite, BishopOnSide) {
    Bishop bishop(PieceColor::WHITE);

    // top side
    bishop.constructPossibleMoves(std::make_pair(0, 4));

    EXPECT_TRUE(bishop.isValidMove(std::make_pair(1, 3)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(2, 2)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(3, 1)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(4, 0)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(1, 5)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(2, 6)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(3, 7)));

    EXPECT_FALSE(bishop.isValidMove(std::make_pair(0, 4)));
    EXPECT_FALSE(bishop.isValidMove(std::make_pair(0, 5)));
}

TEST(BishopSuite, BishopShouldNotBeAbleToMovePastAPieceGoingUpAndLeft) {
    Bishop bishop(PieceColor::WHITE);

    Square* board[8][8];

     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }

    board[3][3] = new Square(new Bishop(PieceColor::WHITE), std::make_pair(3, 3));

    // starting from the bottom
    bishop.constructPossibleMoves(std::make_pair(5, 5), board);

    EXPECT_TRUE(bishop.isValidMove(std::make_pair(4, 4)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(6, 6)));
    
    // should not be able to move past the piece
    EXPECT_FALSE(bishop.isValidMove(std::make_pair(3, 3)));
    EXPECT_FALSE(bishop.isValidMove(std::make_pair(2, 2)));

    // starting from the top
    bishop.constructPossibleMoves(std::make_pair(1, 1), board);

    EXPECT_TRUE(bishop.isValidMove(std::make_pair(2, 2)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(0, 0)));

    // should not be able to move past the piece
    EXPECT_FALSE(bishop.isValidMove(std::make_pair(3, 3)));
    EXPECT_FALSE(bishop.isValidMove(std::make_pair(4, 4)));
}

TEST(BishopSuite, BishopShouldNotBeAbleToMovePastAPieceGoingUpAndRight) {
    Bishop bishop(PieceColor::WHITE);

    Square* board[8][8];

     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }

    board[3][3] = new Square(new Bishop(PieceColor::WHITE), std::make_pair(3, 3));

    // starting from the bottom
    bishop.constructPossibleMoves(std::make_pair(5, 1), board);

    EXPECT_TRUE(bishop.isValidMove(std::make_pair(4, 2)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(6, 0)));
    
    // should not be able to move past the piece
    EXPECT_FALSE(bishop.isValidMove(std::make_pair(3, 3)));
    EXPECT_FALSE(bishop.isValidMove(std::make_pair(2, 4)));

    // starting from the top
    bishop.constructPossibleMoves(std::make_pair(1, 5), board);

    EXPECT_TRUE(bishop.isValidMove(std::make_pair(2, 4)));
    EXPECT_TRUE(bishop.isValidMove(std::make_pair(0, 6)));

    // should not be able to move past the piece
    EXPECT_FALSE(bishop.isValidMove(std::make_pair(3, 3)));
    EXPECT_FALSE(bishop.isValidMove(std::make_pair(4, 2)));
}

TEST(BishopSuite, BishopShouldBeAbleToMoveToTheLocationOfEnemy) {
    Bishop bishop(PieceColor::WHITE);
    Square* board[8][8];

     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }

    board[2][2] = new Square(new Bishop(PieceColor::BLACK), std::make_pair(2, 2));

    bishop.constructPossibleMoves(std::make_pair(0, 0), board);

    EXPECT_TRUE(bishop.isValidMove(std::make_pair(2, 2)));
}

TEST(BishopSuite, BishopShouldNotBeAbleToMovePastFriendlyPiece) {
    Bishop bishop(PieceColor::WHITE);
    Square* board[8][8];

     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }

    board[3][3] = new Square(new Bishop(PieceColor::WHITE), std::make_pair(3, 3));

    // starting from the bottom
    bishop.constructPossibleMoves(std::make_pair(5, 5), board);

    EXPECT_FALSE(bishop.isValidMove(std::make_pair(3, 3)));
}

TEST(BishopSuite, BishopSymbol) {
    Bishop whiteBishop(PieceColor::WHITE);
    Bishop blackBishop(PieceColor::BLACK);

    EXPECT_EQ(whiteBishop.getSymbol(), "Bw");
    EXPECT_EQ(blackBishop.getSymbol(), "Bb");
}