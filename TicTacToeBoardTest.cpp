/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, toggleTurn) {
	TicTacToeBoard local_board;	
	ASSERT_EQ(O,local_board.toggleTurn());
}

TEST(TicTacToeBoardTest, toggleTurnTwice) {
	TicTacToeBoard local_board;	
	local_board.toggleTurn();
	ASSERT_EQ(X,local_board.toggleTurn());
}


TEST(TicTacToeBoardTest, getPiece) {
	TicTacToeBoard local_board;	
	ASSERT_EQ(Blank,local_board.getPiece(0,0));
}

TEST(TicTacToeBoardTest, getPieceOOBNegZero) {
	TicTacToeBoard local_board;	
	ASSERT_EQ(Invalid,local_board.getPiece(-1,0));
}

TEST(TicTacToeBoardTest, getPieceOOBZeroNeg) {
	TicTacToeBoard local_board;	
	ASSERT_EQ(Invalid,local_board.getPiece(0,-1));
}

TEST(TicTacToeBoardTest, getPieceOOBNegNeg) {
	TicTacToeBoard local_board;	
	ASSERT_EQ(Invalid,local_board.getPiece(-1,-1));
}


TEST(TicTacToeBoardTest, getPieceOOBPosZero) {
	TicTacToeBoard local_board;	
	ASSERT_EQ(Invalid,local_board.getPiece(3,0));
}

TEST(TicTacToeBoardTest, getPieceOOBZeroPos) {
	TicTacToeBoard local_board;	
	ASSERT_EQ(Invalid,local_board.getPiece(0,3));
}

TEST(TicTacToeBoardTest, getPieceOOBPosPos) {
	TicTacToeBoard local_board;	
	ASSERT_EQ(Invalid,local_board.getPiece(3,3));
}

TEST(TicTacToeBoardTest, placePieceX) {
	TicTacToeBoard local_board;	
	ASSERT_EQ(Blank,local_board.getPiece(0,0));
	local_board.placePiece(0,0);
	ASSERT_EQ(X,local_board.getPiece(0,0));
}

TEST(TicTacToeBoardTest, placePieceO) {
	TicTacToeBoard local_board;	
	local_board.toggleTurn();
	ASSERT_EQ(Blank,local_board.getPiece(0,0));
	local_board.placePiece(0,0);
	ASSERT_EQ(O,local_board.getPiece(0,0));
}

TEST(TicTacToeBoardTest, HorizontalWinX0) {
	TicTacToeBoard local_board;	
	for(int i = 0; i < BOARDSIZE; i++) {
		local_board.placePiece(i,0);
	}
	ASSERT_NE(Invalid,local_board.getWinner());
	ASSERT_EQ(local_board.getPiece(0,0),local_board.getWinner());
}

TEST(TicTacToeBoardTest, HorizontalWinX1) {
	TicTacToeBoard local_board;	
	for(int i = 0; i < BOARDSIZE; i++) {
		local_board.placePiece(i,1);
	}
	ASSERT_NE(Invalid,local_board.getWinner());
	ASSERT_EQ(local_board.getPiece(1,1),local_board.getWinner());
}

TEST(TicTacToeBoardTest, HorizontalWinX2) {
	TicTacToeBoard local_board;	
	for(int i = 0; i < BOARDSIZE; i++) {
		local_board.placePiece(i,2);
	}
	ASSERT_NE(Invalid,local_board.getWinner());
	ASSERT_EQ(local_board.getPiece(2,2),local_board.getWinner());
}

TEST(TicTacToeBoardTest, HorizontalWinO0) {
	TicTacToeBoard local_board;	
	local_board.toggleTurn();
	for(int i = 0; i < BOARDSIZE; i++) {
		local_board.placePiece(i,0);
	}
	ASSERT_NE(Invalid,local_board.getWinner());
	ASSERT_EQ(local_board.getPiece(0,0),local_board.getWinner());
}

TEST(TicTacToeBoardTest, HorizontalWinO1) {
	TicTacToeBoard local_board;	
	local_board.toggleTurn();
	for(int i = 0; i < BOARDSIZE; i++) {
		local_board.placePiece(i,0);
	}
	ASSERT_NE(Invalid,local_board.getWinner());
	ASSERT_EQ(local_board.getPiece(1,1),local_board.getWinner());
}

TEST(TicTacToeBoardTest, HorizontalWinO2) {
	TicTacToeBoard local_board;	
	local_board.toggleTurn();
	for(int i = 0; i < BOARDSIZE; i++) {
		local_board.placePiece(i,0);
	}
	ASSERT_NE(Invalid,local_board.getWinner());
	ASSERT_EQ(local_board.getPiece(2,2),local_board.getWinner());
}

TEST(TicTacToeBoardTest, VerticalWinX) {
	TicTacToeBoard local_board;	
	for(int i = 0; i < BOARDSIZE; i++) {
		local_board.placePiece(0,i);
	}
	ASSERT_NE(Invalid,local_board.getWinner());
	ASSERT_EQ(local_board.getPiece(0,0),local_board.getWinner());
}

TEST(TicTacToeBoardTest, VerticalWinO) {
	TicTacToeBoard local_board;	
	local_board.toggleTurn();
	for(int i = 0; i < BOARDSIZE; i++) {
		local_board.placePiece(0,i);
	}
	ASSERT_NE(Invalid,local_board.getWinner());
	ASSERT_EQ(local_board.getPiece(0,0),local_board.getWinner());
}

TEST(TicTacToeBoardTest, DiagonalWinX1) {
	TicTacToeBoard local_board;	
	for(int i = 0; i < BOARDSIZE; i++) {
		local_board.placePiece(i,i);
	}
	ASSERT_NE(Invalid,local_board.getWinner());
	ASSERT_EQ(local_board.getPiece(1,1),local_board.getWinner());
}

TEST(TicTacToeBoardTest, DiagonalWinX2) {
	TicTacToeBoard local_board;	
	for(int i = 0; i < BOARDSIZE; i++) {
		local_board.placePiece(i,BOARDSIZE-i-1);
	}
	ASSERT_NE(Invalid,local_board.getWinner());
	ASSERT_EQ(local_board.getPiece(1,1),local_board.getWinner());
}

TEST(TicTacToeBoardTest, DiagonalWinO1) {
	TicTacToeBoard local_board;	
	local_board.toggleTurn();
	for(int i = 0; i < BOARDSIZE; i++) {
		local_board.placePiece(i,i);
	}
	ASSERT_NE(Invalid,local_board.getWinner());
	ASSERT_EQ(local_board.getPiece(1,1),local_board.getWinner());
}

TEST(TicTacToeBoardTest, DiagonalWinO2) {
	TicTacToeBoard local_board;	
	local_board.toggleTurn();
	for(int i = 0; i < BOARDSIZE; i++) {
		local_board.placePiece(i,BOARDSIZE-i-1);
	}
	ASSERT_NE(Invalid,local_board.getWinner());
	ASSERT_EQ(local_board.getPiece(1,1),local_board.getWinner());
}
