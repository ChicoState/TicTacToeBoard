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
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/
//unit tests to see if toggleTurn() works
TEST(TicTacToeBoard, willplayerchange){
	TicTacToeBoard tic;
	ASSERT_EQ(tic.toggleTurn(),O);
}



//unit test to place piece on empty block
TEST(TicTacToeBoard, placePieceOnBlank){
	TicTacToeBoard tic;
	ASSERT_EQ(tic.placePiece(0,0), X);
}
//unit test to place piece on a filled spot
TEST(TicTacToeBoard, placePieceOnFilled){
	TicTacToeBoard tic;
	tic.placePiece(0,0);
	ASSERT_EQ(tic.placePiece(0,0), X);
}
//unit test to place a piece on out of bounds area
TEST(TicTacToeBoard, placePieceOutofBounds){
	TicTacToeBoard tic;
	ASSERT_EQ(tic.placePiece(-1,0), Invalid);
}


//unit test for getPiece
TEST(TicTacToeBoard, getPieceX){
	TicTacToeBoard tic;
	tic.placePiece(0,0);
	ASSERT_EQ(tic.getPiece(0,0), X);
}

//unit tests for get winner
TEST(TicTacToeBoard, winnerO){
	TicTacToeBoard tic;
	tic.placePiece(0,0);
	tic.placePiece(0,1);
	tic.placePiece(1,2);
	tic.placePiece(1,1);
	tic.placePiece(2,0);
	tic.placePiece(2,1);
	ASSERT_EQ(tic.getWinner(), O);
}