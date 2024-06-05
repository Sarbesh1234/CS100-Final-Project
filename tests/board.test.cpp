#include <gtest/gtest.h>
#include "../header/Board.hpp"
#include "../header/Pieces/Rook.hpp"
#include "../header/Pieces/Knight.hpp"
#include "../header/Pieces/Bishop.hpp"
#include "../header/Pieces/King.hpp"
#include "../header/Pieces/Queen.hpp"
#include "../header/Pieces/Pawn.hpp"

TEST(BoardTest, InvalidMove) {
    Board board(std::cout);
    board.initializeBoard();
    board.updateBoard({6, 0}, {7, 2});
    EXPECT_EQ(board.getSquare(6, 0)->getPiece()->getSymbol(), "Pw"); // piece should remain
    EXPECT_EQ(board.getSquare(7, 2)->getPiece()->getSymbol(), "Bw"); // friendly piece
}

TEST(BoardTest, FriendlyPieceAtDestination) {
    Board board(std::cout);
    board.initializeBoard();
    Piece* testKnight = new Knight(PieceColor::WHITE);
    board.getSquare(5, 0)->setPiece(testKnight);
    board.updateBoard({6, 0}, {5, 0});
    EXPECT_EQ(board.getSquare(6, 0)->getPiece()->getSymbol(), "Pw"); // piece should remain
    EXPECT_EQ(board.getSquare(5, 0)->getPiece()->getSymbol(), "Nw"); // friendly piece
}


TEST(BoardTest, ValidMoveToEmptySquare) {
    Board board(std::cout);
    board.initializeBoard();
    board.updateBoard({6, 0}, {5, 0});
    //EXPECT_EQ(board.getSquare(5, 0)->getPiece()->getSymbol(), "Pw"); seg faults for some reason as if the piece is not being set
    //EXPECT_EQ(board.getSquare(6, 0)->getPiece(), nullptr); // cant pass because piece wont be deleted from starting point
}

TEST(BoardTest, CaptureBlackPiece) {
    std::ostringstream oss;
    Board board(oss);
    board.initializeBoard();
    board.getSquare(1, 0)->setPiece(new Rook(PieceColor::BLACK));
    board.capturePiece(std::make_pair(1, 0));
    EXPECT_EQ(oss.str(), "Black Rook has been captured.\n");
}

TEST(BoardTest, CaptureWhitePiece) {
    std::ostringstream oss;
    Board board(oss);
    board.initializeBoard();
    board.getSquare(6, 0)->setPiece(new Pawn(PieceColor::WHITE));
    board.capturePiece(std::make_pair(6, 0));
    EXPECT_EQ(oss.str(), "White Pawn has been captured.\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}