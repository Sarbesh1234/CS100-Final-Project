#include "gtest/gtest.h"

#include "../header/Pieces/Knight.hpp"
#include "../src/Pieces/Knight.cpp"

TEST(KnightSuite, KnightInMiddle) {
    Knight knight(PieceColor::WHITE);

    // checking all 8 possible moves for the knight
    knight.constructPossibleMoves(std::make_pair(4, 4));

    EXPECT_TRUE(knight.isValidMove(std::make_pair(2, 3)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(2, 5)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(3, 2)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(3, 6)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(5, 2)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(5, 6)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(6, 3)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(6, 5)));

    // checking invalid moves for the knight
    EXPECT_FALSE(knight.isValidMove(std::make_pair(4, 4)));
    EXPECT_FALSE(knight.isValidMove(std::make_pair(4, 5)));

}

TEST(KnightSuite, KnightInCorner) {
    Knight knight(PieceColor::WHITE);

    // top left corner
    knight.constructPossibleMoves(std::make_pair(0, 0));

    EXPECT_TRUE(knight.isValidMove(std::make_pair(1, 2)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(2, 1)));

    EXPECT_FALSE(knight.isValidMove(std::make_pair(0, 0)));
    EXPECT_FALSE(knight.isValidMove(std::make_pair(0, 1)));

    // top right corner
    knight.constructPossibleMoves(std::make_pair(0, 7));

    EXPECT_TRUE(knight.isValidMove(std::make_pair(1, 5)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(2, 6)));

    // bottom left corner
    knight.constructPossibleMoves(std::make_pair(7, 0));

    EXPECT_TRUE(knight.isValidMove(std::make_pair(5, 1)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(6, 2)));

    // bottom right corner
    knight.constructPossibleMoves(std::make_pair(7, 7));

    EXPECT_TRUE(knight.isValidMove(std::make_pair(5, 6)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(6, 5)));

}

TEST(KnightSuite, KnightOnSide) {
    Knight knight(PieceColor::WHITE);

    // knight on the left side
    knight.constructPossibleMoves(std::make_pair(0, 4));

    EXPECT_TRUE(knight.isValidMove(std::make_pair(1, 2)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(1, 6)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(2, 3)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(2, 5)));

    EXPECT_FALSE(knight.isValidMove(std::make_pair(0, 4)));
    EXPECT_FALSE(knight.isValidMove(std::make_pair(0, 5)));

    // knight on the right side
    knight.constructPossibleMoves(std::make_pair(4, 7));

    EXPECT_TRUE(knight.isValidMove(std::make_pair(2, 6)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(3, 5)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(6, 6)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(5, 5)));

    // knight on the top side
    knight.constructPossibleMoves(std::make_pair(4, 0));

    EXPECT_TRUE(knight.isValidMove(std::make_pair(2, 1)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(3, 2)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(6, 1)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(5, 2)));

    // knight on the bottom side
    knight.constructPossibleMoves(std::make_pair(7, 4));

    EXPECT_TRUE(knight.isValidMove(std::make_pair(5, 3)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(5, 5)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(6, 2)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(6, 6)));

}

TEST(KnightSuite, KnightShouldNotBeAbleToMoveInTheSquareOfFriendlyPiece) {
    Knight knight(PieceColor::WHITE);
    Square* board[8][8];

    // setting up the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }

    // setting up the friendly piece
    board[6][4] = new Square(new Knight(PieceColor::WHITE), std::make_pair(6, 4));

    knight.constructPossibleMoves(std::make_pair(4, 3), board);

    // valid moves
    EXPECT_TRUE(knight.isValidMove(std::make_pair(2, 2)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(2, 4)));

    // checking if the knight can move to the square of the friendly piece
    EXPECT_FALSE(knight.isValidMove(std::make_pair(6, 4)));
}

TEST(KnightSuite, KnightShouldBeAbleToMoveInTheSquareOfEnemyPiece) {
    Knight knight(PieceColor::WHITE);
    Square* board[8][8];

    // setting up the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }

    // setting up the enemy piece
    board[6][4] = new Square(new Knight(PieceColor::BLACK), std::make_pair(6, 4));

    knight.constructPossibleMoves(std::make_pair(4, 3), board);

    // valid moves
    EXPECT_TRUE(knight.isValidMove(std::make_pair(6, 4)));
}

TEST(KnightSuite, KnightSymbol) {
    Knight whiteKnight(PieceColor::WHITE);
    Knight blackKnight(PieceColor::BLACK);

    EXPECT_EQ(whiteKnight.getSymbol(), "Nw");
    EXPECT_EQ(blackKnight.getSymbol(), "Nb");
}