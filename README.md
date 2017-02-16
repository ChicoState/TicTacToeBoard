#TicTacToeBoard

##Associated Enumerated Types
`Piece` has four possible values: `X`,`O`,`Invalid`, and `Blank`

##Member Variables
`Piece board[BOARDSIZE][BOARDSIZE]` 

**board** represents the 2D playing board, where BOARDSIZE is 3, 
___
`Piece turn` 

**turn** represents whose turn it is to place a piece (defaults to X)

##Private Functions
`void toggleTurn()`  	

*Switches turn member variable to represent whether it's X's or O's turn*
  	
##Public Functions
`TicTacToeBoard()`

*Constructor sets an empty board and specifies it is X's turn first*
___

`void clearBoard()`

*Resets each board location to the Blank Piece value*
___

`Piece placePiece(int row, int column)`

*Places the piece of the current turn on the board, returns what piece is 
placed, and toggles which Piece's turn it is. placePiece does NOT allow to 
place a piece in a location where there is already a piece. In that case, 
placePiece just returns what is already at that location. Out of bounds 
coordinates return the Piece Invalid value.*
___

`Piece getPiece(int row, int column)`

*Returns what piece is at the provided coordinates, or Blank if there
are no pieces there, or Invalid if the coordinates are out of bounds*
___

`Piece getWinner()`

*Returns which Piece has won, if there is a winner, Invalid if the game
is not over, or Blank if the board is filled and no one has won.*