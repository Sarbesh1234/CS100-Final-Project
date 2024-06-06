#include "gtest/gtest.h"

#include "../header/Pieces/Pawn.hpp"
#include "../src/Pieces/Pawn.cpp"

TEST(PawnSuite, PawnInMiddleFirstMove) {
    Square* board[8][8];

     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }
    board[3][4] = new Square(new Pawn(PieceColor::BLACK), std::make_pair(3, 4));
    board[3][3] = new Square(new Pawn(PieceColor::BLACK), std::make_pair(3, 3));
    board[3][5] = new Square(new Pawn(PieceColor::WHITE), std::make_pair(3, 5));
    
    Pawn pawn(PieceColor::WHITE);

    // checking all 4 possible moves for the pawn
    pawn.constructPossibleMoves(std::make_pair(4, 4),board);

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(3, 4)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(3, 3)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(3, 5)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(2, 4)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(4, 4)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(5, 4)));

}

TEST(BlackPawnSuite, PawnInMiddleFirstMove) {
    Square* board[8][8];

     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }
    board[5][3] = new Square(new Pawn(PieceColor::WHITE), std::make_pair(5, 3));
    board[5][5] = new Square(new Pawn(PieceColor::BLACK), std::make_pair(5, 5));
    
    Pawn pawn(PieceColor::BLACK);

    pawn.constructPossibleMoves(std::make_pair(4, 4),board);

    EXPECT_TRUE(pawn.isValidMove(std::make_pair(5, 4)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(5, 3)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(5, 5)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(6, 4)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(4, 4)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(3, 4)));
}

TEST(PawnSuite, PawnInMiddleSecondMove) {
    Square* board[8][8];

     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }
    
    Pawn pawn(PieceColor::WHITE);

    // first move to set flag
    pawn.constructPossibleMoves(std::make_pair(4, 4),board);

    // second move
    pawn.constructPossibleMoves(std::make_pair(2, 4),board);


    EXPECT_TRUE(pawn.isValidMove(std::make_pair(1, 4)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(1, 3)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(1, 5)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(2, 4)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(0, 4)));

}

TEST(BlackPawnSuite, PawnInMiddleSecondMove) {
    Square* board[8][8];

     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }
    
    Pawn pawn(PieceColor::BLACK);
    
    // first move to set flag
    pawn.constructPossibleMoves(std::make_pair(4, 4),board);

    // second move
    pawn.constructPossibleMoves(std::make_pair(2, 4),board);

    EXPECT_TRUE(pawn.isValidMove(std::make_pair(3, 4)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(3, 3)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(3, 5)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(2, 4)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(5, 4)));
}

TEST(PawnSuite, PawnInCorner) {
    Square* board[8][8];

     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }
    board[6][0] = new Square(new Pawn(PieceColor::BLACK), std::make_pair(6, 0));
    board[6][1] = new Square(new Pawn(PieceColor::BLACK), std::make_pair(6, 1));
    board[6][6] = new Square(new Pawn(PieceColor::WHITE), std::make_pair(6, 6));
    
    Pawn pawn(PieceColor::WHITE);

    // bottom left corner first move
    pawn.constructPossibleMoves(std::make_pair(7, 0),board);

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(6, 0)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(6, 1)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(5, 0)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(7, 0)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(7, 1)));

    // bottom right corner second move
    pawn.constructPossibleMoves(std::make_pair(7, 7),board);

    EXPECT_TRUE(pawn.isValidMove(std::make_pair(6, 7)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(6, 6)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(7, 7)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(5, 7)));

}

TEST(BlackPawnSuite, PawnInCorner) {
    Square* board[8][8];

     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }
    board[1][7] = new Square(new Pawn(PieceColor::WHITE), std::make_pair(1, 7));
    board[1][6] = new Square(new Pawn(PieceColor::WHITE), std::make_pair(1, 6));
    board[1][1] = new Square(new Pawn(PieceColor::BLACK), std::make_pair(1, 1));
    //top left corner first move
    Pawn pawn(PieceColor::BLACK);

    pawn.constructPossibleMoves(std::make_pair(0, 7),board);

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(1, 7)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(1, 6)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(2, 7)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(0, 7)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(0, 6)));

    // top right corner second move
    pawn.constructPossibleMoves(std::make_pair(0, 0),board);

    EXPECT_TRUE(pawn.isValidMove(std::make_pair(1, 0)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(1, 1)));

    EXPECT_FALSE(pawn.isValidMove(std::make_pair(0, 0)));
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(2, 0)));

}

TEST(PawnSuite, PawnInStartingSpot) {
    Square* board[8][8];

     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }
    board[4][4] = new Square(new Pawn(PieceColor::BLACK), std::make_pair(4, 4));

    Pawn pawn(PieceColor::WHITE);

    pawn.constructPossibleMoves(std::make_pair(6, 2),board);
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(4, 2)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(5, 2)));

    pawn.constructPossibleMoves(std::make_pair(6, 4),board);
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(4, 4)));

}

TEST(BlackPawnSuite,PawnInStartingSpot) {
    Square* board[8][8];

     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(nullptr, std::make_pair(i, j));
        }
    }
    board[3][4] = new Square(new Pawn(PieceColor::WHITE), std::make_pair(3, 4));

    Pawn pawn(PieceColor::BLACK);

    pawn.constructPossibleMoves(std::make_pair(1, 2),board);
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(3, 2)));
    EXPECT_TRUE(pawn.isValidMove(std::make_pair(2, 2)));

    pawn.constructPossibleMoves(std::make_pair(1, 4),board);
    EXPECT_FALSE(pawn.isValidMove(std::make_pair(3, 4)));
}

TEST(PawnSuite, PawnSymbol) {
    Pawn whitePawn(PieceColor::WHITE);
    Pawn blackPawn(PieceColor::BLACK);

    EXPECT_EQ(whitePawn.getSymbol(), "Pw");
    EXPECT_EQ(blackPawn.getSymbol(), "Pb");
}