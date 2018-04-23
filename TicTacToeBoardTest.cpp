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

TEST(TicTacToeBoardTest, sanityCheck)
{
	TicTacToeBoard board;
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, testPieceX)
{
	TicTacToeBoard board;
	board.toggleTurn();
	ASSERT_TRUE(board.toggleTurn() == 'X');
}

TEST(TicTacToeBoardTest, testPieceO)
{
	TicTacToeBoard board;
	ASSERT_TRUE(board.toggleTurn() == 'O');
}

TEST(TicTacToeBoardTest, invalidLocationRow)
{
	TicTacToeBoard board;
	ASSERT_FALSE(board.placePiece(3,2) == 'X');
}

TEST(TicTacToeBoardTest, invalidLocationColumn)
{
	TicTacToeBoard board;
	ASSERT_FALSE(board.placePiece(2,3) == 'X');
}

TEST(TicTacToeBoardTest, validLocationRow)
{
	TicTacToeBoard board;
	ASSERT_TRUE(board.placePiece(2,2) == 'X');
}

TEST(TicTacToeBoardTest, validLocationColumn)
{
	TicTacToeBoard board;
	ASSERT_TRUE(board.placePiece(0,1) == 'X');
}

TEST(TicTacToeBoardTest, existingPeice)
{
	TicTacToeBoard board;
	board.placePiece(0,1);
	ASSERT_FALSE(board.placePiece(0,1) == 'X');
}

TEST(TicTacToeBoardTest, freshGame)
{
	TicTacToeBoard board;
	ASSERT_TRUE(board.getPiece(0,0) == Blank);
}



