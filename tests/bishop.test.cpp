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

TEST(BishopSuite, BishopSymbol) {
    Bishop whiteBishop(PieceColor::WHITE);
    Bishop blackBishop(PieceColor::BLACK);

    EXPECT_EQ(whiteBishop.getSymbol(), "Bw");
    EXPECT_EQ(blackBishop.getSymbol(), "Bb");
}