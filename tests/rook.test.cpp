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

TEST(RookSuite, RookSymbol) {
    Rook whiteRook(PieceColor::WHITE);
    Rook blackRook(PieceColor::BLACK);

    EXPECT_EQ(whiteRook.getSymbol(), "Rw");
    EXPECT_EQ(blackRook.getSymbol(), "Rb");
}