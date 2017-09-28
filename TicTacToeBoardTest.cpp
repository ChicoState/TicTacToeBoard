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

TEST(TicTacToeBoardTest, toggleTurnTest)
{
	TicTacToeBoard board;
	
	EXPECT_EQ(board.toggleTurn(), O);
	EXPECT_EQ(board.toggleTurn(), X);
	EXPECT_EQ(board.toggleTurn(), O);
	
}

TEST(TicTacToeBoardTest, placePieceTest)
{
	TicTacToeBoard board;
	
	EXPECT_EQ(board.placePiece(-1,-1), Invalid);
	
	EXPECT_EQ(board.placePiece(0,0), O);
	//EXPECT_EQ(board.placePiece(0,0), O);
	
	EXPECT_EQ(board.placePiece(1,0), X);

	EXPECT_EQ(board.placePiece(2,0), O);

	EXPECT_EQ(board.placePiece(3,0), Invalid);

	EXPECT_EQ(board.placePiece(0,1), X);
	EXPECT_EQ(board.placePiece(0,2), O);
	EXPECT_EQ(board.placePiece(1,1), X);
	EXPECT_EQ(board.placePiece(1,2), O);
	EXPECT_EQ(board.placePiece(2,2), X);
}
/*BUG: Testing getPieceTest. Expected outcome for all getPiece tests accessing
the board at position 0-2 for either row or column should return the correct expected output,
ie (0,0) should return blank. However, it returns invalid.*/

TEST(TicTacToeBoardTest, getPieceTest)
{
	TicTacToeBoard board;
	EXPECT_EQ(board.getPiece(0,0), Blank); 
	EXPECT_EQ(board.getPiece(1,1), Blank);
	EXPECT_EQ(board.getPiece(1,2), Blank);
	EXPECT_EQ(board.getPiece(0,3), Invalid);
	EXPECT_EQ(board.getPiece(2,0), Blank);
	EXPECT_EQ(board.getPiece(0,1), Blank);
	EXPECT_EQ(board.getPiece(0,2), Blank);
	
	board.placePiece(0,0);
	EXPECT_EQ(board.getPiece(0,0), X); 
	board.placePiece(0,1);
	EXPECT_EQ(board.getPiece(0,1), O); 
	board.placePiece(2,2);
	EXPECT_EQ(board.getPiece(2,2), X);

}

TEST(TicTacToeBoardTest,getWinnerTest)
{
	TicTacToeBoard board;
	EXPECT_EQ(board.getWinner(), Blank);
	board.placePiece(0,0); 
	board.placePiece(2,2);  
	board.placePiece(0,1); 
	board.placePiece(1,1); 
	board.placePiece(0,2); 
	board.placePiece(1,0); 
	board.placePiece(1,2);
	board.placePiece(2,1);
	board.placePiece(2,1);
	EXPECT_EQ(board.getWinner(), Blank);
}

TEST(TicTacToeBoardTest,getWinnerDraw)
{
	TicTacToeBoard board;
	
	board.placePiece(0,2); 
	board.placePiece(0,0);  
	board.placePiece(1,0);  
	board.placePiece(0,1);  
	board.placePiece(1,1);  
	board.placePiece(1,2);  
	board.placePiece(2,2); 
	board.placePiece(2,0); 
	board.placePiece(2,1); 
	EXPECT_EQ(board.getWinner(), Invalid);
}
