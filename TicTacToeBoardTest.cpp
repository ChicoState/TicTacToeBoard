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
TEST(TicTacToeBoard, willplayerchange){
	//Rando rando;
	//ASSERT_EQ( rando.mostPopularDigit(0), 0);
	//ASSERT_TRUE(true);
	TicTacToeBoard tic;
	ASSERT_EQ(tic.toggleTurn(), X || O );
}