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
    Board board(std::cout);
    board.initializeBoard();
    bool res = board.updateBoard({6, 0}, {7, 2});
    ASSERT_FALSE(res);
    EXPECT_EQ(board.getSquare(6, 0)->getPiece()->getSymbol(), "Pw"); // piece should remain
    EXPECT_EQ(board.getSquare(7, 2)->getPiece()->getSymbol(), "Bw"); // friendly piece
}

TEST(BoardTest, FriendlyPieceAtDestination) {
    Board board(std::cout);
    Piece* testKnight = new Knight(PieceColor::WHITE);
    board.getSquare(5, 0)->setPiece(testKnight);
    board.initializeBoard();
    bool res = board.updateBoard({6, 0}, {5, 0});
    ASSERT_FALSE(res);
    EXPECT_EQ(board.getSquare(6, 0)->getPiece()->getSymbol(), "Pw"); // piece should remain
    EXPECT_EQ(board.getSquare(5, 0)->getPiece()->getSymbol(), "Nw"); // friendly piece
}


TEST(BoardTest, ValidMoveToEmptySquare) {
    Board board(std::cout);
    board.initializeBoard();
    bool res = board.updateBoard(std::make_pair(6, 0), std::make_pair(5, 0));
    ASSERT_TRUE(res);
    EXPECT_EQ(board.getSquare(6, 0)->getPiece(), nullptr);
    EXPECT_EQ(board.getSquare(5, 0)->getPiece()->getSymbol(), "Pw");
}

TEST(BoardTest, CaptureBlackPiece) {
    std::ostringstream oss;
    Board board(oss);

    board.getSquare(3, 3)->setPiece(new Rook(PieceColor::BLACK));
    board.getSquare(4, 2)->setPiece(new Pawn(PieceColor::WHITE));

    board.reconstructPossibleMoves();

    board.updateBoard(pair<int, int>(4, 2), pair<int, int>(3,3));
    EXPECT_EQ(oss.str(), "Black Rook has been captured.\n");
}

TEST(BoardTest, CaptureWhitePiece) {
    std::ostringstream oss;
    Board board(oss);

    board.getSquare(3, 3)->setPiece(new Pawn(PieceColor::BLACK));
    board.getSquare(4, 2)->setPiece(new Rook(PieceColor::WHITE));

    board.reconstructPossibleMoves();

    board.updateBoard(pair<int, int>(3, 3), pair<int, int>(4,2));
    EXPECT_EQ(oss.str(), "White Rook has been captured.\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}