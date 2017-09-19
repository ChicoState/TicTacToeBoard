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

TEST(TicTacToeBoardTest, getPieceTest5) {
	TicTacToeBoard TicTac;
	TicTac.toggleTurn();
	TicTac.placePiece(2, 1);
	Piece x = TicTac.getPiece(2, 1);
	ASSERT_EQ(O, x);	
}
