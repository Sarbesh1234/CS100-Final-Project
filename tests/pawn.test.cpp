#include "gtest/gtest.h"

#include "../header/Pieces/Pawn.hpp"
#include "../src/Pieces/Pawn.cpp"

TEST(PawnSuite, PawnInMiddleFirstMove) {
    Pawn pawn(PieceColor::WHITE);

    // checking all 4 possible moves for the pawn
    pawn.constructPossibleMoves(std::make_pair(4, 4));

    EXPECT_TRUE(pawn.isValidMove(std::make_pair(3, 4)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(3, 3)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(3, 5)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(2, 4)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(4, 4)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(5, 4)));

}

TEST(BlackPawnSuite, PawnInMiddleFirstMove) {
    Pawn pawn(PieceColor::BLACK);

    pawn.constructPossibleMoves(std::make_pair(4, 4));

    EXPECT_TRUE(pawn.isValidMove(std::make_pair(5, 4)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(5, 3)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(5, 5)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(6, 4)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(4, 4)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(3, 4)));
}

TEST(PawnSuite, PawnInMiddleSecondMove) {
    Pawn pawn(PieceColor::WHITE);

    // first move to set flag
    pawn.constructPossibleMoves(std::make_pair(4, 4));

    // second move
    pawn.constructPossibleMoves(std::make_pair(2, 4));


    EXPECT_TRUE(pawn.isValidMove(std::make_pair(1, 4)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(1, 3)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(1, 5)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(2, 4)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(0, 4)));

}

TEST(BlackPawnSuite, PawnInMiddleSecondMove) {
    Pawn pawn(PieceColor::BLACK);
    
    // first move to set flag
    pawn.constructPossibleMoves(std::make_pair(4, 4));

    // second move
    pawn.constructPossibleMoves(std::make_pair(2, 4));

    EXPECT_TRUE(pawn.isValidMove(std::make_pair(3, 4)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(3, 3)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(3, 5)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(2, 4)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(5, 4)));
}

TEST(PawnSuite, PawnInCorner) {
    Pawn pawn(PieceColor::WHITE);

    // bottom left corner first move
    pawn.constructPossibleMoves(std::make_pair(7, 0));

    EXPECT_TRUE(pawn.isValidMove(std::make_pair(6, 0)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(6, 1)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(5, 0)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(7, 0)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(7, 1)));

    // bottom right corner second move
    pawn.constructPossibleMoves(std::make_pair(7, 7));

    EXPECT_TRUE(pawn.isValidMove(std::make_pair(6, 7)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(6, 6)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(7, 7)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(5, 7)));

}

TEST(BlackPawnSuite, PawnInCorner) {

    //top left corner first move
    Pawn pawn(PieceColor::BLACK);

    pawn.constructPossibleMoves(std::make_pair(0, 7));

    EXPECT_TRUE(pawn.isValidMove(std::make_pair(1, 7)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(1, 6)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(2, 7)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(0, 7)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(0, 6)));

    // top right corner second move
    pawn.constructPossibleMoves(std::make_pair(0, 0));

    EXPECT_TRUE(pawn.isValidMove(std::make_pair(1, 0)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(1, 1)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(0, 0)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(2, 0)));

}

TEST(PawnSuite, PawnSymbol) {
    Pawn whitePawn(PieceColor::WHITE);
    Pawn blackPawn(PieceColor::BLACK);

    EXPECT_EQ(whitePawn.getSymbol(), "Pw");
    EXPECT_EQ(blackPawn.getSymbol(), "Pb");
}