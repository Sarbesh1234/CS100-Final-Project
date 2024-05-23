#include "gtest/gtest.h"

#include "../header/Pieces/Queen.hpp"
#include "../src/Pieces/Queen.cpp"



TEST(QueenSuite, QueenInMiddle) {
    Queen queen(PieceColor::WHITE);
    // checking all 27 possible moves for the queen
    queen.constructPossibleMoves(std::make_pair(4, 4));

    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(1, 1)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(1, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(1, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 1)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 1)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 3)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 5)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 3)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 5)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(5, 3)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(5, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(5, 5)));

    // checking invalid moves for the queen
    EXPECT_FALSE(queen.isValidMove(std::make_pair(4, 4)));
    EXPECT_FALSE(queen.isValidMove(std::make_pair(0, 1)));
    EXPECT_FALSE(queen.isValidMove(std::make_pair(7, 0)));
    EXPECT_FALSE(queen.isValidMove(std::make_pair(0, 7)));

}

TEST(QueenSuite, QueenInCorner) {
    Queen queen(PieceColor::WHITE);

    // top left corner
    queen.constructPossibleMoves(std::make_pair(0, 0));

    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 1)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 2)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 3)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 5)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 6)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(1, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(2, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(5, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(6, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(1, 1)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(2, 2)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 3)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(5, 5)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(6, 6)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 7)));

    // top right corner
    queen.constructPossibleMoves(std::make_pair(0, 7));

    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 6)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 5)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 3)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 2)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 1)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(1, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(2, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(5, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(6, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(1, 6)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(2, 5)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 3)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(5, 2)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(6, 1)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 0)));

    // bottom left corner
    queen.constructPossibleMoves(std::make_pair(7, 0));

    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 1)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 2)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 3)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 5)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 6)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(6, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(5, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(2, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(1, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(6, 1)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(5, 2)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 3)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(2, 5)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(1, 6)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 7)));

    // bottom right corner
    queen.constructPossibleMoves(std::make_pair(7, 7));
    
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 6)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 5)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 3)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 2)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 1)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(6, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(5, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(2, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(1, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(6, 6)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(5, 5)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 3)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(2, 2)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(1, 1)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 0)));

}

TEST(QueenSuite, QueenOnSide) {
    Queen queen(PieceColor::WHITE);

    // top side
    queen.constructPossibleMoves(std::make_pair(0, 4));

    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 3)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 2)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 1)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 5)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 6)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(1, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(2, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(5, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(6, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(1, 3)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(2, 2)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 1)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(1, 5)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(2, 6)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 7)));

    // left side
    queen.constructPossibleMoves(std::make_pair(4, 0));

    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(2, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(1, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(5, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(6, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 1)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 2)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 3)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 5)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 6)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 1)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(2, 2)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(1, 3)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(5, 1)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(6, 2)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 3)));

    // right side
    queen.constructPossibleMoves(std::make_pair(4, 7));

    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(2, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(1, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(5, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(6, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 6)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 5)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 3)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 2)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 1)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 6)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(2, 5)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(1, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 3)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(5, 6)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(6, 5)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 4)));

    // bottom side
    queen.constructPossibleMoves(std::make_pair(7, 4));
    
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 3)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 2)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 1)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 5)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 6)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(7, 7)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(6, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(5, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(2, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(1, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(0, 4)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(6, 3)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(5, 2)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 1)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(3, 0)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(6, 5)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(5, 6)));
    EXPECT_TRUE(queen.isValidMove(std::make_pair(4, 7)));

}

TEST(QueenSuite, QueenSymbol) {
    Queen whiteQueen(PieceColor::WHITE);
    Queen blackQueen(PieceColor::BLACK);
    EXPECT_EQ(whiteQueen.getSymbol(), "Qw");
    EXPECT_EQ(blackQueen.getSymbol(), "Qb");
}