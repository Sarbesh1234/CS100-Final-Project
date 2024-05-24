#include "gtest/gtest.h"

#include "../header/Pieces/Rook.hpp"
#include "../src/Pieces/Rook.cpp"

TEST(RookSuite, RookInMiddle) {
    Rook rook(PieceColor::WHITE);

    // checking all 14 possible moves for the rook
    rook.constructPossibleMoves(std::make_pair(4, 4));

    EXPECT_TRUE(rook.isValidMove(std::make_pair(3, 4)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(2, 4)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(1, 4)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(0, 4)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(5, 4)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(6, 4)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(7, 4)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(4, 3)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(4, 2)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(4, 1)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(4, 0)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(4, 5)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(4, 6)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(4, 7)));

    EXPECT_FALSE(rook.isValidMove(std::make_pair(4, 4)));
    EXPECT_FALSE(rook.isValidMove(std::make_pair(5, 5)));
}

TEST(RookSuite, RookInCorner) {
    Rook rook(PieceColor::WHITE);

    // top left corner
    rook.constructPossibleMoves(std::make_pair(0, 0));
    
    EXPECT_TRUE(rook.isValidMove(std::make_pair(1, 0)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(2, 0)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(3, 0)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(4, 0)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(5, 0)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(6, 0)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(7, 0)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(0, 1)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(0, 2)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(0, 3)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(0, 4)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(0, 5)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(0, 6)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(0, 7)));

    EXPECT_FALSE(rook.isValidMove(std::make_pair(0, 0)));
    EXPECT_FALSE(rook.isValidMove(std::make_pair(1, 1)));

}

TEST(RookSuite, RookOnSide) {
    Rook rook(PieceColor::WHITE);

    // top side
    rook.constructPossibleMoves(std::make_pair(0, 4));

    EXPECT_TRUE(rook.isValidMove(std::make_pair(1, 4)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(2, 4)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(3, 4)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(4, 4)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(5, 4)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(6, 4)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(7, 4)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(0, 3)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(0, 2)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(0, 1)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(0, 0)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(0, 5)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(0, 6)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(0, 7)));

    EXPECT_FALSE(rook.isValidMove(std::make_pair(0, 4)));
    EXPECT_FALSE(rook.isValidMove(std::make_pair(1, 3)));
}

TEST(RookSuite, RookNotAbleToMovePastEnemyPieceVertically) {
    Rook rook(PieceColor::WHITE);
    Square* board[8][8];

     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }

    board[2][4] = new Square(new Rook(PieceColor::WHITE), std::make_pair(2, 4));

    // other piece is below current
    rook.constructPossibleMoves(std::make_pair(0, 4), board);

    EXPECT_TRUE(rook.isValidMove(std::make_pair(1, 4)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(0, 5)));

    // impossible moves
    EXPECT_FALSE(rook.isValidMove(std::make_pair(2, 4)));
    EXPECT_FALSE(rook.isValidMove(std::make_pair(3, 4)));

    // other piece is above current
    rook.constructPossibleMoves(std::make_pair(4, 4), board);

    EXPECT_TRUE(rook.isValidMove(std::make_pair(3, 4)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(4, 5)));

    // impossible moves
    EXPECT_FALSE(rook.isValidMove(std::make_pair(2, 4)));
    EXPECT_FALSE(rook.isValidMove(std::make_pair(1, 4)));
}

TEST(RookSuite, RookNotAbleToMovePastEnemyPieceHorizontally) {
    Rook rook(PieceColor::WHITE);
    Square* board[8][8];

     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }

    board[4][2] = new Square(new Rook(PieceColor::WHITE), std::make_pair(4, 2));

    // other piece is to the left of current
    rook.constructPossibleMoves(std::make_pair(4, 0), board);

    EXPECT_TRUE(rook.isValidMove(std::make_pair(4, 1)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(5, 0)));

    // impossible moves
    EXPECT_FALSE(rook.isValidMove(std::make_pair(4, 2)));
    EXPECT_FALSE(rook.isValidMove(std::make_pair(4, 3)));

    // other piece is to the right of current
    rook.constructPossibleMoves(std::make_pair(4, 4), board);

    EXPECT_TRUE(rook.isValidMove(std::make_pair(4, 3)));
    EXPECT_TRUE(rook.isValidMove(std::make_pair(5, 4)));

    // impossible moves
    EXPECT_FALSE(rook.isValidMove(std::make_pair(4, 2)));
    EXPECT_FALSE(rook.isValidMove(std::make_pair(4, 1)));
}

TEST(RookSuite, RookShouldBeAbleToMoveToTheLocationOfAnEnemy) {
    Rook rook(PieceColor::WHITE);
    Square* board[8][8];

     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }

    board[2][4] = new Square(new Rook(PieceColor::BLACK), std::make_pair(2, 4));

    // other piece is below current
    rook.constructPossibleMoves(std::make_pair(0, 4), board);

    EXPECT_TRUE(rook.isValidMove(std::make_pair(2, 4)));
}

TEST(RookSuite, RookShouldNotBeAbleToMoveToTheLocationOfAFriendlyPiece) {
    Rook rook(PieceColor::WHITE);
    Square* board[8][8];

     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }

    board[2][4] = new Square(new Rook(PieceColor::WHITE), std::make_pair(2, 4));

    // other piece is below current
    rook.constructPossibleMoves(std::make_pair(0, 4), board);

    EXPECT_FALSE(rook.isValidMove(std::make_pair(2, 4)));
}

TEST(RookSuite, RookSymbol) {
    Rook whiteRook(PieceColor::WHITE);
    Rook blackRook(PieceColor::BLACK);

    EXPECT_EQ(whiteRook.getSymbol(), "Rw");
    EXPECT_EQ(blackRook.getSymbol(), "Rb");
}