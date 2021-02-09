// include header files here 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

// define macros here
#define BLACK 		'B'
#define WHITE 		'W'
#define UNOCCUPIED	'U'
#define MARKED      'X'  

// initializeBoard() - begin
void initializeBoard(char board[][26], int n)
{
	// variable definitions
	int ii, jj;
	
	// set all the cells to UNOCCUPIED	
	for (ii = 0; ii < n; ++ii)
		for (jj = 0; jj < n; ++jj)
			board[ii][jj] = UNOCCUPIED;
			
	// update the middle row/columns with the starting configuration	
	board[n/2-1][n/2-1]	= WHITE;
	board[n/2-1][n/2]	= BLACK;
	board[n/2][n/2-1]	= BLACK;
	board[n/2][n/2]	    = WHITE;
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

// validateConfiguration() definition - begin
void validateConfiguration(char configuration[])
{
	// configuration must have 3 characters
	if(strlen(configuration) != 3)
	{
		printf("Invalid configuration, must have 3 characters representing Color, Row and Column.");
		exit(1);
	}
	
	// first character must represent either of the two colours
	if (configuration[0] != BLACK && configuration[0] != WHITE)
	{
		printf("Invalid configuration, first character must represent Color(B/W).");
		exit(1);
	}
	
	// second character must represent a row(a-z)
	if (configuration[1] < 'a' || configuration[1] > 'z')
	{
		printf("Invalid configuration, second character must represent Row number(a-z).");
		exit(1);
	}
	
	// second character must represent a column(a-z)
	if (configuration[2] < 'a' || configuration[2] > 'z')
	{
		printf("Invalid configuration, third character must represent Column number(a-z).");
		exit(1);
	}
}
// validateConfiguration() definition - end

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
	if (deltaRow == 0 && deltaCol == 0) return false;
	
	// if the cell is already occupied, return false;
	if (board[row][col] != UNOCCUPIED) return false;
	
	// identify the colour of the oponent
	oponentColour = (colour == BLACK) ? WHITE : BLACK;
	
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
	if (moveOn == false) return false;
    
    // if you find the oponent at the end of the straight line, move is legal
    if (board[newRow][newCol] == colour) return true;
	
	// by now, move is illegal
	return false;
}
// checkLegalInDirection() definition - end

//void checkLegalInDirection(char board[][26], int n, int row, int col,
void updateMove(char board[][26], int n,
				int row, int col, char colour,
				int deltaRow, int deltaCol)
{
	// variable definitions
	int newRow = row + deltaRow; // find the index of row to be checked
	int newCol = col + deltaCol; // find the index of the col to be checked
	char opponentColour;          // colour of the oponet
	
	if (!checkLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol))
		return;
		
	// if the cell is already occupied, return false;
	if (board[row][col] != UNOCCUPIED && board[row][col] != MARKED)
		return;
			
	// identify the colour of the opponent
	opponentColour = (colour == BLACK) ? WHITE : BLACK;
    	
	// go ahead and make the move by inverting the oponet's coins	
    
	// update the row and col to keep moveing in the straight line
	newRow = row + deltaRow;
	newCol = col + deltaCol;
	
	// keep tracking the straight line as far as posssible
	while (positionInBounds(n, newRow, newCol) == true)
	{
		// you reached the end, since you found the opponent on the cell
		if (board[newRow][newCol] != opponentColour)
			break;
			
		// update the cell to X as an indicator	
		board[newRow][newCol] = MARKED;
		
		// update the new indices on the straight line
		newRow = newRow + deltaRow;
		newCol = newCol + deltaCol;
	
	} // end of while
}
// checkLegalInDirection() definition - end

// updateBoard() definition - begin
void updateBoard(char board[][26], int n, char colour, int row, int col)
{
	// check all the 8 directions and invert the
	// coins of the opponent whehever possible
	updateMove(board, n, row, col, colour, -1, 0);
	updateMove(board, n, row, col, colour, -1, 1);
	updateMove(board, n, row, col, colour, 0, 1);
	updateMove(board, n, row, col, colour, 1, 1);
	updateMove(board, n, row, col, colour, 1, 0);
	updateMove(board, n, row, col, colour, 1, -1);
	updateMove(board, n, row, col, colour, 0, -1);
	updateMove(board, n, row, col, colour, -1, -1);
	
	// mark the current cell with the player colour
	board[row][col] = colour;
	
	// keep updating all the marked cells with colour of the player
	for (int ii = 0; ii < n; ++ii)
	{
		for (int jj = 0; jj < n; ++jj)
		{
			if (board[ii][jj] == MARKED)
				board[ii][jj] = colour;
		}
	}
}
// updateBoard() definition - end

// validateFeasibility() definition - begin
bool validateFeasibility(char board[][26], int n,
						 int row, int col,
                         char colour)
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

// displayAvailableMoves() definition - begin
void displayAvailableMoves(char board[][26], int n, char colour)
{
	// variable definitions
	int ii, jj;
	
	for (ii = 0; ii < n; ++ii)
	{
		for (jj = 0; jj < n; ++jj)
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
	char board[26][26];		// the 2D board
	char configuration[4];	// the move
	char colour;			// represents the player
	int  n;					// size of the board
	
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
	
	// setup the board
	initializeBoard(board, n);
	
	// display the current state of the board
	printBoard(board, n);
	
	// keep reading the user inputs for the moves
	printf("Enter board configuration:\n");
	do
	{
		// read the move
		scanf("%s", configuration);
		
		// quit reading if it is the termination inout
		if (strcmp(configuration, "!!!") == 0)
			break;
		
		// chech if the configuration is valid
		validateConfiguration(configuration);
		
		// check if the indices are within valid range	
		bool bPositionValid = positionInBounds(n, configuration[1]-'a', configuration[2]-'a');
		// quit the program if the indexes are out of bound
		if (bPositionValid == false)
		{
			printf("Invalid position on board, hence quitting...");
			return 1;
		}
		
		// mark the move on the board
		board[configuration[1]-'a'][configuration[2]-'a'] = configuration[0];
		
	} while(1);
	
	// display the current state of the board
	printBoard(board, n);
	
	// turn1: white, turn2: black
	for (int turn = 1; turn <= 2; ++turn)
	{
		printf("Available moves for ");
		
		// decide the colour of the player
		if (turn == 1)
			colour = WHITE;
		else
			colour = BLACK;
		printf("%c:\n", colour);
		
		// display the available moves for the current player
		displayAvailableMoves(board, n, colour);
	}
	
	// read the move
	printf("Enter a move:\n");
	scanf("%s", configuration);
	
	// chech if the configuration is valid
	validateConfiguration(configuration);
	
	// check if the move is valid 
	if (validateFeasibility(board, n, configuration[1]-'a', configuration[2]-'a', configuration[0]) == true)
	{
		printf("Valid move.\n");
		
		// update the board with the impact of the current move
		updateBoard(board, n, configuration[0], configuration[1]-'a', configuration[2]-'a');
	}
	else // indicates invalid move	
	{
		printf("Invalid move.\n");
	}
	
	// display the current state of the board
	printBoard(board, n);
	
	// we are done!!!
	return 0;
}
// main() definition - end
