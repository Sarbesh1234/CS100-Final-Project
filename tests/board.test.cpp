#include <gtest/gtest.h>
#include <utility>
#include "../header/Board.hpp"
#include "../header/Pieces/Rook.hpp"
#include "../header/Pieces/Knight.hpp"
#include "../header/Pieces/Bishop.hpp"
#include "../header/Pieces/King.hpp"
#include "../header/Pieces/Queen.hpp"
#include "../header/Pieces/Pawn.hpp"

TEST(BoardTest, InvalidMove) {
    Board board;
    board.initializeBoard();
    bool res = board.updateBoard({6, 0}, {7, 2});
    ASSERT_FALSE(res);
    EXPECT_EQ(board.getSquare(6, 0)->getPiece()->getSymbol(), "Pw"); // piece should remain
    EXPECT_EQ(board.getSquare(7, 2)->getPiece()->getSymbol(), "Bw"); // friendly piece
}

TEST(BoardTest, FriendlyPieceAtDestination) {
    Board board;
    Piece* testKnight = new Knight(PieceColor::WHITE);
    board.getSquare(5, 0)->setPiece(testKnight);
    board.initializeBoard();
    bool res = board.updateBoard({6, 0}, {5, 0});
    ASSERT_FALSE(res);
    EXPECT_EQ(board.getSquare(6, 0)->getPiece()->getSymbol(), "Pw"); // piece should remain
    EXPECT_EQ(board.getSquare(5, 0)->getPiece()->getSymbol(), "Nw"); // friendly piece
}


TEST(BoardTest, ValidMoveToEmptySquare) {
    Board board;
    board.initializeBoard();
    bool res = board.updateBoard(std::make_pair(6, 0), std::make_pair(5, 0));
    ASSERT_TRUE(res);
    EXPECT_EQ(board.getSquare(6, 0)->getPiece(), nullptr);
    EXPECT_EQ(board.getSquare(5, 0)->getPiece()->getSymbol(), "Pw");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}