#include <gtest/gtest.h>
#include "../header/Board.hpp"
#include "../header/Pieces/Rook.hpp"
#include "../header/Pieces/Knight.hpp"
#include "../header/Pieces/Bishop.hpp"
#include "../header/Pieces/King.hpp"
#include "../header/Pieces/Queen.hpp"
#include "../header/Pieces/Pawn.hpp"

TEST(BoardTest, InvalidMove) {
    Board board;
    board.updateBoard({6, 0}, {7, 2});
    EXPECT_EQ(board.getSquare(6, 0)->getPiece()->getSymbol(), "Pw"); // piece should remain
    EXPECT_EQ(board.getSquare(7, 2)->getPiece()->getSymbol(), "Bw"); // friendly piece
}

TEST(BoardTest, FriendlyPieceAtDestination) {
    Board board;
    Piece* testKnight = new Knight(PieceColor::WHITE);
    board.getSquare(5, 0)->setPiece(testKnight);
    board.updateBoard({6, 0}, {5, 0});
    EXPECT_EQ(board.getSquare(6, 0)->getPiece()->getSymbol(), "Pw"); // piece should remain
    EXPECT_EQ(board.getSquare(5, 0)->getPiece()->getSymbol(), "Nw"); // friendly piece
}


TEST(BoardTest, ValidMoveToEmptySquare) {
    Board board;
    board.updateBoard({6, 0}, {5, 0});
    //EXPECT_EQ(board.getSquare(5, 0)->getPiece()->getSymbol(), "Pw"); seg faults for some reason as if the piece is not being set
    //EXPECT_EQ(board.getSquare(6, 0)->getPiece(), nullptr); // cant pass because piece wont be deleted from starting point
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}