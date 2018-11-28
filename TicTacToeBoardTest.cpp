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


TEST(TicTacToeBoardTest, testFirstToggle)
{
	TicTacToeBoard object;
	Piece outcome = object.toggleTurn();
	ASSERT_EQ(outcome, O);
	
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, testPlacePiece)
{
	TicTacToeBoard object;
	Piece outcome = object.placePiece(0,0);
	ASSERT_EQ(outcome, X);
	
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, testPlacePiece2)
{
	TicTacToeBoard object;
	object.placePiece(0,0);
	Piece outcome = object.placePiece(0,0);
	ASSERT_EQ(outcome, X);
	
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, testPlacePieceOutOfBounds)
{
	TicTacToeBoard object;
	object.placePiece(0,0);
	Piece outcome = object.placePiece(0,3);
	ASSERT_EQ(outcome, Invalid);
	
	ASSERT_TRUE(true);
}