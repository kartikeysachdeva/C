#include<stdio.h>
#include<string.h>
#include <stdbool.h>

// initializeBoard() - begin
void initializeBoard(char board[][26], int n)
{
	int ii, jj;
	
	// set all the cells to 'U'(unused)	
	for (ii = 0; ii < n; ++ii)
		for (jj = 0; jj < n; ++jj)
			board[ii][jj] = 'U';
			
	// update the middle row/columns with the starting configuration	
	board[n/2-1][n/2-1]	= 'W';
	board[n/2-1][n/2]	= 'B';
	board[n/2][n/2-1]	= 'B';
	board[n/2][n/2]	    = 'W';
}
// initializeBoard() - end

// printBoard() definition - begin
void printBoard(char board[][26], int n)
{
	// variable definitions
	int ii, jj;
	
	// accomodate the space for the row heading
	printf("  ");
	
	// display the column headings
	for (ii = 0; ii < n; ++ii)
		printf("%c", 'a'+ii);	
	
	printf("\n");
	
	// keep displaying the elements of the board
	for (ii = 0; ii < n; ++ii)
	{
		// display the row heading
		printf("%c ", 'a'+ii);
		
		// display the status of the current cell
		for (jj = 0; jj < n; ++jj)
			printf("%c", board[ii][jj]);
		
		printf("\n");
	}
}
// printBoard() definition - end

bool isGameOver(char board[][26], int n)
{
	// variable definitions
	int ii, jj;
	
	// keep displaying the elements of the board
	for (ii = 0; ii < n; ++ii)
	{
		// display the status of the current cell
		for (jj = 0; jj < n; ++jj)
		{
			if (board[ii][jj] == 'U')
				return false;
		}
	}
	
	return true;
}

void displayWinner(char board[][26], int n)
{
	// variable definitions
	int ii, jj;
	int bCount = 0, wCount = 0;
	
	// keep displaying the elements of the board
	for (ii = 0; ii < n; ++ii)
	{
		// display the status of the current cell
		for (jj = 0; jj < n; ++jj)
		{
			if (board[ii][jj] == 'B')
				++bCount;
			else
				++wCount;	
		}
	}
	
	if (bCount == wCount)
		printf ("Draw!");
	else if (bCount > wCount)
		printf ("B player wins.");
	else
		printf ("W player wins.");
}

// positionInBounds() definition - begin
bool positionInBounds(int n, int row, int col)
{
	if (row < 0 || row >= n) return false; // row is either -ve or exceeding the limit
	if (col < 0 || col >= n) return false; // col is either -ve or exceeding the limit
	
	// both row and col are within the limits
	return true;
}
// positionInBounds() definition - end

// checkLegalInDirection() definition - begin
bool checkLegalInDirection(char board[][26], int n, int row, int col,
						   char colour, int deltaRow, int deltaCol)
{
	int newRow = row + deltaRow; // find the index of row to be checked
	int newCol = col + deltaCol; // find the index of the col to be checked
	char oponentColour;          // colour of the oponet
	
	// safety check
	if (deltaRow == 0 && deltaCol == 0)
		return false;
	
	// if the cell is already occupied, return false;
	if (board[row][col] != 'U')
		return false;
	
	// identify the colour of the oponent
	if (colour == 'B') 
		oponentColour = 'W';
	else
		oponentColour = 'B';
	
	// to check if atleast one move can be made on the board	
	bool moveOn = false;
	
	// keep tracking the straight line as far as posssible
	while (positionInBounds(n, newRow, newCol) == true)
	{
		// you reached the end, since you found the oponent on the cell
		if (board[newRow][newCol] != oponentColour)
			break;
		
		// update the row and col to keep moveing in the straight line	
		newRow = newRow + deltaRow;
		newCol = newCol + deltaCol;
		
		// you could make atleast one move
		moveOn = true;
	}
    
    // if you couldn't move, move is illegal
	if (moveOn == false)
		return false;
    
    // if you find the oponent at the end of the straight line, move is legal
    if (board[newRow][newCol] == colour)
		return true;
	
	// by now, move is illegal
	return false;
}
// checkLegalInDirection() definition - end

// updateLegalInDirection() definition - begin
void updateLegalInDirection(char board[][26], int n, int row, int col,
						    char colour, int deltaRow, int deltaCol)
{
	int newRow = row + deltaRow; // find the index of row to be checked
	int newCol = col + deltaCol; // find the index of the col to be checked
	char oponentColour;          // colour of the oponet
	
	// safety check
	if (deltaRow == 0 && deltaCol == 0) return;
	
	// if the cell is already occupied, return false;
	if (board[row][col] != 'U' && board[row][col] != 'X') return;
	
	// identify the colour of the oponent
	if (colour == 'B') 
		oponentColour = 'W';
	else
		oponentColour = 'B';
		
	// to check if atleast one move can be made on the board	
	bool moveOn = false;
	
	// keep tracking the straight line as far as posssible
	while (positionInBounds(n, newRow, newCol) == true)
	{
		// you reached the end, since you found the oponent on the cell
		if (board[newRow][newCol] != oponentColour)
			break;
		
		// update the row and col to keep moveing in the straight line	
		newRow = newRow + deltaRow;
		newCol = newCol + deltaCol;
		
		// you could make atleast one move
		moveOn = true;
	}
    
    // if you couldn't move, move is illegal
	if (moveOn == false)
		return;
    
    // if you don't have the oponent at the end of the straight line, return
    if (board[newRow][newCol] != colour)
    	return;
    
	// go ahead and make the move by inverting the oponet's coins	
    
	// update the row and col to keep moveing in the straight line
	newRow = row + deltaRow;
	newCol = col + deltaCol;
	
	// keep tracking the straight line as far as posssible
	while (positionInBounds(n, newRow, newCol) == true)
	{
		// you reached the end, since you found the oponent on the cell
		if (board[newRow][newCol] != oponentColour)
			break;
			
		// update the cell to X as an indicator	
		board[newRow][newCol] = 'X';
		
		// update the new indices on the straight line
		newRow = newRow + deltaRow;
		newCol = newCol + deltaCol;
	} // end of while
}
// updateLegalInDirection() definition - end

// countLegalInDirection() definition - begin
int countLegalInDirection(char board[][26], int n, int row, int col,
						  char colour, int deltaRow, int deltaCol)
{
	int  newRow = row + deltaRow; // find the index of row to be checked
	int  newCol = col + deltaCol; // find the index of the col to be checked
	char oponentColour;           // colour of the oponet
	int  moveCount;				  // number of valid moves
	
	// safety check
	if (deltaRow == 0 && deltaCol == 0) return 0;
	
	// if the cell is already occupied, return false;
	if (board[row][col] != 'U' && board[row][col] != 'X') return 0;
	
	// identify the colour of the oponent
	if (colour == 'B') 
		oponentColour = 'W';
	else
		oponentColour = 'B';
		
	// to check if atleast one move can be made on the board	
	bool moveOn = false;
	moveCount = 0;
	
	// keep tracking the straight line as far as posssible
	while (positionInBounds(n, newRow, newCol) == true)
	{
		// you reached the end, since you found the oponent on the cell
		if (board[newRow][newCol] != oponentColour)
			break;
		
		// update the row and col to keep moveing in the straight line	
		newRow = newRow + deltaRow;
		newCol = newCol + deltaCol;
		
		// you could make atleast one move
		moveOn = true;
		
		++moveCount;
	}
    
    // if you couldn't move, move is illegal
	if (moveOn == false)
		return 0;
    
    // if you don't have the oponent at the end of the straight line, return
    if (board[newRow][newCol] != colour)
    	return 0;
    
	// return the count
	return moveCount;
}
// countLegalInDirection() definition - end

// updateBoard() definition - begin
bool updateBoard(char board[][26], int n, char colour, int row, int col)
{
	bool isMoveMade = false;
	
	// check all the 8 directions and invert
	// the coins of the oponent whehever possible
	updateLegalInDirection(board, n, row, col, colour, -1, 0);
	updateLegalInDirection(board, n, row, col, colour, -1, 1);
	updateLegalInDirection(board, n, row, col, colour, 0, 1);
	updateLegalInDirection(board, n, row, col, colour, 1, 1);
	updateLegalInDirection(board, n, row, col, colour, 1, 0);
	updateLegalInDirection(board, n, row, col, colour, 1, -1);
	updateLegalInDirection(board, n, row, col, colour, 0, -1);
	updateLegalInDirection(board, n, row, col, colour, -1, -1);
	
	// mark the current cell with the player colour
	board[row][col] = colour;
	
	// keep updating all the marked cells with colour of the player
	for (int ii = 0; ii < n; ++ii)
	{
		for (int jj = 0; jj < n; ++jj)
		{
			if (board[ii][jj] == 'X')
			{
				board[ii][jj] = colour;
				isMoveMade = true;
			}
		}
	}
	
	return isMoveMade;
}
// updateBoard() definition - end

// validateFeasibility() definition - begin
bool validateFeasibility(char board[][26], int n, int row, int col, char colour)
{
	// check all the 8 directions and return true if the move is valid
	// otherwise return false
	if (checkLegalInDirection(board, n, row, col, colour, -1, 0) == true)
		return true;
	if (checkLegalInDirection(board, n, row, col, colour, -1, 1) == true)
		return true;
	if (checkLegalInDirection(board, n, row, col, colour, 0, 1) == true)
		return true;
	if (checkLegalInDirection(board, n, row, col, colour, 1, 1) == true)
		return true;
	if (checkLegalInDirection(board, n, row, col, colour, 1, 0) == true)
		return true;
	if (checkLegalInDirection(board, n, row, col, colour, 1, -1) == true)
		return true;
	if (checkLegalInDirection(board, n, row, col, colour, 0, -1) == true)
		return true;
	if (checkLegalInDirection(board, n, row, col, colour, -1, -1) == true)
		return true;
	
	// return false
	return false;
}
// validateFeasibility() definition - end

// makeBestComputerMove() definition - begin
bool makeBestComputerMove(char board[][26], int n, char colour)
{
	int bestRow, bestCol, count, maxMoveCount = 0;
	
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			if (board[row][col] != 'U')
				continue;
			
			// display the available moves for both of the colours
			count = countLegalInDirection(board, n, row, col, colour, -1, 0);
			count += countLegalInDirection(board, n, row, col, colour, -1, 1);
			count += countLegalInDirection(board, n, row, col, colour, 0, 1);
			count += countLegalInDirection(board, n, row, col, colour, 1, 1);
			count += countLegalInDirection(board, n, row, col, colour, 1, 0);
			count += countLegalInDirection(board, n, row, col, colour, 1, -1);
			count += countLegalInDirection(board, n, row, col, colour, 0, -1);
			count += countLegalInDirection(board, n, row, col, colour, -1, -1);
			
			if (maxMoveCount < count)
			{
				maxMoveCount = count;
				bestRow = row;
				bestCol = col;
			}
		}
	}
	
	if (maxMoveCount == 0)
		return false;
	
	printf("Computer places %c at %c%c.\n", colour, 'a'+bestRow, 'a'+bestCol);
	updateBoard(board, n, colour, bestRow, bestCol);
	
	return true;
}
// makeBestComputerMove() definition - end

// isMoveAvailable() definition - begin
bool isMoveAvailable(char board[][26], int n, char colour)
{
	for (int ii = 0; ii < n; ++ii)
	{
		for (int jj = 0; jj < n; ++jj)
		{
			// check if move is available for this colour
			if (validateFeasibility(board, n, ii, jj, colour) == true)
				return true;
		}
	}
	
	return false;
}
// isMoveAvailable() definition - end

// displayAvailableMoves() definition - begin
void displayAvailableMoves(char board[][26], int n, char colour)
{
	for (int ii = 0; ii < n; ++ii)
	{
		for (int jj = 0; jj < n; ++jj)
		{
			// display the available moves for both of the colours
			if (validateFeasibility(board, n, ii, jj, colour) == true)
				printf("%c%c\n", 'a'+ii, 'a'+jj);
		}
	}
}
// displayAvailableMoves() definition - end

// main() definition - begin
int main()
{
	// variable definitions
	char board[26][26];			// the 2D board
	char move[3];				// the move
	char cComputerPlayColour;	// represents the computer playing colour
	char cHumanPlayColour;		// represents the human playing colour
	char cCurrentPlayer;		// represents the current player
	int  ii, jj, kk = 0, n;
	
	// read the dimensions of the board
	printf("Enter the board dimension: ");
	scanf("%d", &n);
	
	// this is a safety check to avoid invalid input
	// if the dimensions are invalid, quit the program
	if (n <= 1 || n > 26 || n%2 == 1)
	{
		printf("Invalid input, n must be an even number between 2 and 26.");
		return 1;
	}
	
	printf("Computer plays (B/W): ");
	fflush(stdin);
	scanf("%c", &cComputerPlayColour);
	if (cComputerPlayColour != 'B' && cComputerPlayColour != 'W')
	{
		printf("Invalid colour.");
		return 1;
	}
	
	// set the play color of the human
	if (cComputerPlayColour == 'B')
	{
		cHumanPlayColour = 'W';
		// set the first colour to black
		cCurrentPlayer = 'C';
	}
	else
	{
		cHumanPlayColour = 'B';
		// set the first colour to black
		cCurrentPlayer = 'H';
	}
	
	// setup the board
	initializeBoard(board, n);
	
	// display the current state of the board
	printBoard(board, n);
	
	do
	{
		if (cCurrentPlayer == 'H')
		{
			if (isMoveAvailable(board, n, cHumanPlayColour) == false)
			{
				printf("%c player has no valid move.\n", cHumanPlayColour);
				cCurrentPlayer = 'C';
				continue;		
			}
			
			// read the move of the human
			printf("Enter move for colour %c (RowCol): ", cHumanPlayColour);
			// read the move
			scanf("%s", move);
			// check if the move has exactly 2 characters
			if (strlen(move) != 2)
			{
				printf("Invalid move.\n");
		   		printf("%c player wins.", cComputerPlayColour);
		   		break;
			}
			
			// check if the cell is already occupied
			// check if the indices are out of range	
			if ( (board[move[0]-'a'][move[1]-'a'] != 'U') ||
			     positionInBounds(n, move[0]-'a', move[1]-'a') == false)
			{
				printf("Invalid move.\n");
		   		printf("%c player wins.", cComputerPlayColour);
		   		break;
			}
			
			// update board with human move
			// if no update happened, move is invalid
			if (updateBoard(board, n, cHumanPlayColour, move[0]-'a', move[1]-'a') == false)
			{
				printf("Invalid move.\n");
		   		printf("%c player wins.", cComputerPlayColour);
				break;
			}
	
			// update the player for the next round
			cCurrentPlayer = 'C'; 
		}
		else
		{
			// find and make the best move of the computer
			if (makeBestComputerMove(board, n, cComputerPlayColour) == false)
			{
				// if computer has no possible move, pass on the turn
				printf("%c player has no valid move.\n", cComputerPlayColour);
				cCurrentPlayer = 'H';
				continue;	
			}
			
			// update the player for the next round
			cCurrentPlayer = 'H';
		}
		
		// display the board
		printBoard(board, n);
		
		// if the game is over, display the winner and quit
		if (isGameOver(board, n) == true)
		{
			// display the winner
			displayWinner(board, n);
			break;
		}
				
	} while(1);
	
	// we are done!!!
	return 0;
}
// main() definition - end
