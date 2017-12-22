/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
using namespace std;
 
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

TEST(TicTacToeBoardTest, toggleTest) {
	TicTacToeBoard TicTac;
	Piece x = TicTac.toggleTurn();
	ASSERT_EQ(O, x);
	x = TicTac.toggleTurn();
	ASSERT_EQ(X, x);
}

TEST(TicTacToeBoardTest, placePieceTest) {
	TicTacToeBoard TicTac;
	TicTac.toggleTurn();
	Piece x = TicTac.placePiece(2, 2);
	ASSERT_EQ(O, x);
}

TEST(TicTacToeBoardTest, placePieceTest2) {
	TicTacToeBoard TicTac;
	Piece x = TicTac.placePiece(4, 4);
	ASSERT_EQ(Invalid, x);
}

TEST(TicTacToeBoardTest, placePieceTest3) {
	TicTacToeBoard TicTac;
	Piece x = TicTac.placePiece(-1, -1);
	ASSERT_EQ(Invalid, x);
}

TEST(TicTacToeBoardTest, getPieceTest) {
	TicTacToeBoard TicTac;
	Piece x = TicTac.getPiece(4, 4);
	ASSERT_EQ(Invalid, x);
}

TEST(TicTacToeBoardTest, getPieceTest2) {
	TicTacToeBoard TicTac;
	Piece x = TicTac.getPiece(-1, -1);
	ASSERT_EQ(Invalid, x);
}

TEST(TicTacToeBoardTest, getPieceTest3) {
	TicTacToeBoard TicTac;
	Piece x = TicTac.getPiece(3, 3);
	ASSERT_EQ(Blank, x);	
}

TEST(TicTacToeBoardTest, getPieceTest4) {
	TicTacToeBoard TicTac;
	Piece x = TicTac.getPiece(0, 0);
	ASSERT_EQ(Blank, x);	
}


/*
BUG: When trying to get a piece that exists, is returning blank. In
getPieceTest5 the outcome should be O. But returns blank.
*/
TEST(TicTacToeBoardTest, getPieceTest5) {
	TicTacToeBoard TicTac;
	TicTac.toggleTurn();
	TicTac.placePiece(2, 1);
	Piece x = TicTac.getPiece(2, 1);
	ASSERT_EQ(O, x);	
}

TEST(TicTacToeBoardTest, getWinnerTest) {
	TicTacToeBoard TicTac;
	Piece x = TicTac.getWinner();
	ASSERT_EQ(Invalid, x);
}

TEST(TicTacToeBoardTest, getWinnerTest2) {
	TicTacToeBoard TicTac;
	TicTac.placePiece(0,0);
	TicTac.placePiece(0,1);
	TicTac.placePiece(1,1);
	TicTac.placePiece(0,2);
	TicTac.placePiece(2,2);
	Piece x = TicTac.getWinner();
	ASSERT_EQ(X, x);
}

TEST(TicTacToeBoardTest, getWinnerTest3) {
	TicTacToeBoard TicTac;
	TicTac.placePiece(0,0);
	TicTac.toggleTurn();
	TicTac.placePiece(1,1);
	TicTac.toggleTurn();
	TicTac.placePiece(2,2);
	Piece x = TicTac.getWinner();
	ASSERT_EQ(X, x);
}

TEST(TicTacToeBoardTest, getWinnerTest4) {
	TicTacToeBoard TicTac;
	TicTac.placePiece(2,0);
	TicTac.toggleTurn();
	TicTac.placePiece(1,1);
	TicTac.toggleTurn();
	TicTac.placePiece(0,2);
	Piece x = TicTac.getWinner();
	ASSERT_EQ(X, x);
}

TEST(TicTacToeBoardTest, getWinnerTest5) {
	TicTacToeBoard TicTac;
	TicTac.placePiece(2,0);
	TicTac.toggleTurn();
	TicTac.placePiece(1,0);
	TicTac.toggleTurn();
	TicTac.placePiece(0,0);
	Piece x = TicTac.getWinner();
	ASSERT_EQ(X, x);
}

TEST(TicTacToeBoardTest, getWinnerTest6) {
	TicTacToeBoard TicTac;
	TicTac.placePiece(0,0);
	TicTac.placePiece(0,1);
	Piece x = TicTac.getWinner();
	ASSERT_EQ(Blank, x);
}