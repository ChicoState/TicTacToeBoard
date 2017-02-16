/**
 * Unit Tests for Rando Test
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

/*  
	FUNCTIONS WE NEED TO TEST:

	bool shouldWorry(bool,bool,bool);
	bool isDivisbleBy(int,int);
	bool isPrime(int);
	int nearestToZero(int,int);
*/
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
