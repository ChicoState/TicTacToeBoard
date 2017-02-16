#ifndef _TICTACTOEBOARD_H_
#define _TICTACTOEBOARD_H_

const static int BOARDSIZE = 3;

enum Piece
{
  	X = 'X',
  	O = 'O',
  	Invalid = '?',
  	Blank = ' '
};

/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/
class TicTacToeBoard
{
  private:
  	Piece board[BOARDSIZE][BOARDSIZE];
  	Piece turn;

  	//Switches turn member variable to represent whether it's X's or O's turn
  	void toggleTurn();

  public:
  	//Constructor sets an empty board and specifies it is X's turn first
  	TicTacToeBoard();

  	//Resets each board location to the Blank Piece value
  	void clearBoard();

  	/**
  	 * Places the piece of the current turn on the board, returns what
  	 * piece is placed, and toggles which Piece's turn it is. placePiece does 
  	 * NOT allow to place a piece in a location where there is already a piece.
  	 * In that case, placePiece just returns what is already at that location. 
  	 * Out of bounds coordinates return the Piece Invalid value
  	**/ 
  	Piece placePiece(int row, int column);

  	/**
  	 * Returns what piece is at the provided coordinates, or Blank if there
  	 * are no pieces there, or Invalid if the coordinates are out of bounds
  	**/
  	Piece getPiece(int row, int column);

  	/**
  	 * Returns which Piece has won, if there is a winner, Invalid if the game
  	 * is not over, or Blank if the board is filled and no one has won.
  	**/
  	Piece getWinner();
};

#endif