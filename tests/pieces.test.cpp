#include "gtest/gtest.h"

#include "../header/Piece.hpp"
#include "../header/Pieces/King.hpp"
#include "../src/Pieces/King.cpp"
#include "../header/Pieces/Queen.hpp"
#include "../src/Pieces/Queen.cpp"
#include "../header/Pieces/Pawn.hpp"
#include "../src/Pieces/Pawn.cpp"
#include "../header/Pieces/Bishop.hpp"
#include "../src/Pieces/Bishop.cpp"
#include "../header/Pieces/Knight.hpp"
#include "../src/Pieces/Knight.cpp"
#include "../header/Pieces/Rook.hpp"
#include "../src/Pieces/Rook.cpp"

/*  KingSuite   */


TEST(KingSuite, KingInMiddle) {
    King king(Color::WHITE);
    king.constructPossibleMoves(std::make_pair(4, 4));
    // std::vector<std::pair<int, int>> expected = {
    //     std::make_pair(3, 3),
    //     std::make_pair(3, 4),
    //     std::make_pair(3, 5),
    //     std::make_pair(4, 3),
    //     std::make_pair(4, 5),
    //     std::make_pair(5, 3),
    //     std::make_pair(5, 4),
    //     std::make_pair(5, 5)
    // };
    EXPECT_TRUE(king.isValidMove(std::make_pair(3, 3)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(3, 4)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(3, 5)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(4, 3)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(4, 5)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(5, 3)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(5, 4)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(5, 5)));

    EXPECT_FALSE(king.isValidMove(std::make_pair(4, 4)));
}

TEST(KingSuite, KingInCorner) {
    King king(Color::WHITE);
    king.constructPossibleMoves(std::make_pair(0, 0));
    // std::vector<std::pair<int, int>> expected = {
    //     std::make_pair(0, 1),
    //     std::make_pair(1, 0),
    //     std::make_pair(1, 1)
    // };
    EXPECT_TRUE(king.isValidMove(std::make_pair(0, 1)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(1, 0)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(1, 1)));

    king.constructPossibleMoves(std::make_pair(0, 7));

    // std::vector<std::pair<int, int>> expected = {
    //     std::make_pair(0, 6),
    //     std::make_pair(1, 6),
    //     std::make_pair(1, 7)
    // };
    EXPECT_TRUE(king.isValidMove(std::make_pair(0, 6)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(1, 6)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(1, 7)));

    king.constructPossibleMoves(std::make_pair(7, 0));

    // std::vector<std::pair<int, int>> expected = {
    //     std::make_pair(6, 0),
    //     std::make_pair(6, 1),
    //     std::make_pair(7, 1)
    // };
    EXPECT_TRUE(king.isValidMove(std::make_pair(6, 0)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(6, 1)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(7, 1)));

    king.constructPossibleMoves(std::make_pair(7, 7));

    // std::vector<std::pair<int, int>> expected = {
    //     std::make_pair(6, 6),
    //     std::make_pair(6, 7),
    //     std::make_pair(7, 6)
    // };
    EXPECT_TRUE(king.isValidMove(std::make_pair(6, 6)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(6, 7)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(7, 6)));
}

TEST(KingSuite, KingOnSide) {
    King king(Color::WHITE);
    king.constructPossibleMoves(std::make_pair(0, 4));
    // std::vector<std::pair<int, int>> expected = {
    //     std::make_pair(0, 3),
    //     std::make_pair(1, 3),
    //     std::make_pair(1, 4),
    //     std::make_pair(1, 5),
    //     std::make_pair(0, 5)
    // };
    EXPECT_TRUE(king.isValidMove(std::make_pair(0, 3)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(1, 3)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(1, 4)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(1, 5)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(0, 5)));

    king.constructPossibleMoves(std::make_pair(4, 0));
    // std::vector<std::pair<int, int>> expected = {
    //     std::make_pair(3, 0),
    //     std::make_pair(3, 1),
    //     std::make_pair(4, 1),
    //     std::make_pair(5, 1),
    //     std::make_pair(5, 0)
    // };
    EXPECT_TRUE(king.isValidMove(std::make_pair(3, 0)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(3, 1)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(4, 1)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(5, 1)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(5, 0)));

    king.constructPossibleMoves(std::make_pair(7, 4));
    // std::vector<std::pair<int, int>> expected = {
    //     std::make_pair(7, 3),
    //     std::make_pair(6, 3),
    //     std::make_pair(6, 4),
    //     std::make_pair(6, 5),
    //     std::make_pair(7, 5)
    // };
    EXPECT_TRUE(king.isValidMove(std::make_pair(7, 3)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(6, 3)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(6, 4)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(6, 5)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(7, 5)));
    
    king.constructPossibleMoves(std::make_pair(4, 7));
    // std::vector<std::pair<int, int>> expected = {
    //     std::make_pair(3, 7),
    //     std::make_pair(3, 6),
    //     std::make_pair(4, 6),
    //     std::make_pair(5, 6),
    //     std::make_pair(5, 7)
    // };

    EXPECT_TRUE(king.isValidMove(std::make_pair(3, 7)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(3, 6)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(4, 6)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(5, 6)));
    EXPECT_TRUE(king.isValidMove(std::make_pair(5, 7)));
    
}

/*  QueenSuite   */

TEST(QueenSuite, QueenInMiddle) {
    Queen queen(Color::WHITE);
    queen.constructPossibleMoves(std::make_pair(4, 4));

    std::vector<std::pair<int, int>> expected = {
        std::make_pair(3, 3),
        std::make_pair(3, 4),
        std::make_pair(3, 5),
        std::make_pair(4, 3),
        std::make_pair(4, 5),
        std::make_pair(5, 3),
        std::make_pair(5, 4),
        std::make_pair(5, 5),
        std::make_pair(0, 4),
        std::make_pair(1, 4),
        std::make_pair(2, 4),
        std::make_pair(3, 4),
        std::make_pair(5, 4),
        std::make_pair(6, 4),
        std::make_pair(7, 4),
        std::make_pair(4, 0),
        std::make_pair(4, 1),
        std::make_pair(4, 2),
        std::make_pair(4, 3),
        std::make_pair(4, 5),
        std::make_pair(4, 6),
        std::make_pair(4, 7),
        std::make_pair(0, 0),
        std::make_pair(1, 1),
        std::make_pair(2, 2),
        std::make_pair(3, 3),
        std::make_pair(5, 5),
        std::make_pair(6, 6),
        std::make_pair(7, 7),
        std::make_pair(0, 7),
        std::make_pair(1, 6),
        std::make_pair(2, 5),
        std::make_pair(3, 4),
        std::make_pair(5, 3),
        std::make_pair(6, 2),
        std::make_pair(7, 1)
    };

    

}

/*  BishopSuite */

TEST(BishopSuit, BishopInMiddle) {
    Bishop bishop(Color::WHITE);

    bishop.constructPossibleMoves(std::make_pair(4, 4));

    // expected
    // (5, 5)
    // (6, 6)
    // (7, 7)
    // (3, 3)
    // (2, 2)
    // (1, 1)
    // (0, 0)
    // (5, 3)
    // (6, 2)
    // (7, 1)
    // (3, 5)
    // (2, 6)
    // (1, 7)

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
    Bishop bishop(Color::WHITE);

    bishop.constructPossibleMoves(std::make_pair(0, 0));

    // expected
    // (1, 1)
    // (2, 2)
    // (3, 3)
    // (4, 4)
    // (5, 5)
    // (6, 6)
    // (7, 7)

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
    Bishop bishop(Color::WHITE);

    bishop.constructPossibleMoves(std::make_pair(0, 4));

    // expected
    // (1, 3)
    // (2, 2)
    // (3, 1)
    // (4, 0)
    // (1, 5)
    // (2, 6)
    // (3, 7)
    
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

/*  KnightSuite */

TEST(KnightSuite, KnightInMiddle) {
    Knight knight(Color::WHITE);

    knight.constructPossibleMoves(std::make_pair(4, 4));

    // expected
    // (2, 3)
    // (2, 5)
    // (3, 2)
    // (3, 6)
    // (5, 2)
    // (5, 6)
    // (6, 3)
    // (6, 5)

    EXPECT_TRUE(knight.isValidMove(std::make_pair(2, 3)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(2, 5)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(3, 2)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(3, 6)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(5, 2)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(5, 6)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(6, 3)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(6, 5)));

    EXPECT_FALSE(knight.isValidMove(std::make_pair(4, 4)));
    EXPECT_FALSE(knight.isValidMove(std::make_pair(4, 5)));

}

TEST(KnightSuite, KnightInCorner) {
    Knight knight(Color::WHITE);

    knight.constructPossibleMoves(std::make_pair(0, 0));

    // expected
    // (1, 2)
    // (2, 1)

    EXPECT_TRUE(knight.isValidMove(std::make_pair(1, 2)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(2, 1)));

    EXPECT_FALSE(knight.isValidMove(std::make_pair(0, 0)));
    EXPECT_FALSE(knight.isValidMove(std::make_pair(0, 1)));
}

TEST(KnightSuite, KnightOnSide) {
    Knight knight(Color::WHITE);

    knight.constructPossibleMoves(std::make_pair(0, 4));

    // expected
    // (1, 2)
    // (1, 6)
    // (2, 3)
    // (2, 5)

    EXPECT_TRUE(knight.isValidMove(std::make_pair(1, 2)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(1, 6)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(2, 3)));
    EXPECT_TRUE(knight.isValidMove(std::make_pair(2, 5)));

    EXPECT_FALSE(knight.isValidMove(std::make_pair(0, 4)));
    EXPECT_FALSE(knight.isValidMove(std::make_pair(0, 5)));
}

/*  RookSuite   */

TEST(RookSuite, RookInMiddle) {
    Rook rook(Color::WHITE);

    rook.constructPossibleMoves(std::make_pair(4, 4));

    // expected
    // (3, 4)
    // (2, 4)
    // (1, 4)
    // (0, 4)
    // (5, 4)
    // (6, 4)
    // (7, 4)
    // (4, 3)
    // (4, 2)
    // (4, 1)
    // (4, 0)
    // (4, 5)
    // (4, 6)
    // (4, 7)

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
    Rook rook(Color::WHITE);

    rook.constructPossibleMoves(std::make_pair(0, 0));

    // expected
    // (1, 0)
    // (2, 0)
    // (3, 0)
    // (4, 0)
    // (5, 0)
    // (6, 0)
    // (7, 0)
    // (0, 1)
    // (0, 2)
    // (0, 3)
    // (0, 4)
    // (0, 5)
    // (0, 6)
    // (0, 7)
    
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
    Rook rook(Color::WHITE);

    rook.constructPossibleMoves(std::make_pair(0, 4));

    // expected
    // (1, 4)
    // (2, 4)
    // (3, 4)
    // (4, 4)
    // (5, 4)
    // (6, 4)
    // (7, 4)
    // (0, 3)
    // (0, 2)
    // (0, 1)
    // (0, 0)
    // (0, 5)
    // (0, 6)
    // (0, 7)

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

/*  PawnSuite   */

TEST(PawnSuite, PawnInMiddleFirstMove) {
    Pawn pawn(Color::WHITE);

    pawn.constructPossibleMoves(std::make_pair(4, 4));

    // expected
    // (3, 4)
    // (3, 3)
    // (3, 5)
    // (2, 4)

    EXPECT_TRUE(pawn.isValidMove(std::make_pair(3, 4)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(3, 3)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(3, 5)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(2, 4)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(4, 4)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(5, 4)));
}

TEST(PawnSuite, PawnInMiddleSecondMove) {
    Pawn pawn(Color::WHITE);

    pawn.constructPossibleMoves(std::make_pair(4, 4));

    pawn.constructPossibleMoves(std::make_pair(2, 4));

    // expected
    // (1, 4)
    // (1, 3)
    // (1, 5)

    EXPECT_TRUE(pawn.isValidMove(std::make_pair(1, 4)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(1, 3)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(1, 5)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(2, 4)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(0, 4)));
}

TEST(PawnSuite, PawnInCorner) {
    Pawn pawn(Color::WHITE);

    pawn.constructPossibleMoves(std::make_pair(7, 0));

    // expected
    // (6, 0)
    // (6, 1)
    // (5, 0)

    EXPECT_TRUE(pawn.isValidMove(std::make_pair(6, 0)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(6, 1)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(5, 0)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(7, 0)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(7, 1)));

    pawn.constructPossibleMoves(std::make_pair(7, 7));

    // expected

    // (6, 7)
    // (6, 6)

    EXPECT_TRUE(pawn.isValidMove(std::make_pair(6, 7)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(6, 6)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(7, 7)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(5, 7)));

}