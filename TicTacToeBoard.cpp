#include "TicTacToeBoard.h"
/**
* Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
* to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
	turn = X;
	for (int i = 0; i<BOARDSIZE; i++)
		for (int j = 0; j<BOARDSIZE; j++)
			board[i][j] = Blank;
}

/**
* Switches turn member variable to represent whether it's X's or O's turn
* and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
	if (turn == X) {
		turn = O; return O;
	}
	else {
		turn = X; return X;
	}
}
/**
* Places the piece of the current turn on the board, returns what
* piece is placed, and toggles which Piece's turn it is. placePiece does
* NOT allow to place a piece in a location where there is already a piece.
* In that case, placePiece just returns what is already at that location.
* Out of bounds coordinates return the Piece Invalid value. When the game
* is over, no more pieces can be placed so attempting to place a piece
* should neither change the board nor change whose turn it is.
**/
Piece TicTacToeBoard::placePiece(int row, int column)
{
	if (row < 0 || row > 2 || column < 0 || column > 2) {
		return Invalid;
	}
	else if (board[row][column] == Blank) {
		if (turn == X) {
			board[row][column] = X; turn = O; return O;
		}
		else {
			board[row][column] = O; turn = X; return X;
		}
	}
	else {
		return board[row][column];
	}
}

/**
* Returns what piece is at the provided coordinates, or Blank if there
* are no pieces there, or Invalid if the coordinates are out of bounds
**/

/*There is a bug when passed in a number < 1 or > 3. It should not fail when passed in 0, fail when passed in 3 if working correctly. */
Piece TicTacToeBoard::getPiece(int row, int column)
{
	if (row < 1 || row > 3 || column < 1 || column > 3) {
		return Invalid;
	}
	else if (board[row][column] == Blank) return Blank;
	else if (board[row][column] == X) return X;
	else { return O; }
}

/**
* Returns which Piece has won, if there is a winner, Invalid if the game
* is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == Blank || board[j][i] == Blank) return Blank;
		}
	}

	if ((board[0][0] && board[0][1] == board[0][2]) || (board[0][0] == board[1][0] == board[2][0]) || (board[0][0] == board[1][1] == board[2][2])) {
		return board[0][0];
	}
	else if ((board[0][1] == board[1][1] == board[2][1]) || board[1][0] == board[1][1] == board[1][2]) {
		return board[1][1];
	}
	else if (board[2][0] == board[2][1] == board[2][2] || board[0][2] == board[1][2] == board[2][2]) {
		return board[2][2];
	}
	return Invalid;
}
