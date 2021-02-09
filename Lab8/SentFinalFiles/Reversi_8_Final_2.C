#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include <stdbool.h>
#include <sys/time.h>
#include <sys/resource.h>

// structure to hold all the possible moves
// of a given color at a given point of time 
struct AvailableMoves
{
	int row;
	int col;
	
} Moves[1000];

// total number of moves
int totalMoves = 0;

// start time of the run
double timeStart;

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
	
	// return true as the game is over
	return true;
}
// printBoard() definition - end

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
// printBoard() definition - end

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

// findAllAvailableMoves() definition - begin
void findAllAvailableMoves(char board[][26], int n, char colour)
{
	// initialize the number of moves to 0
	totalMoves = 0;
	
	// keep counting the feasible moves
	for (int ii = 0; ii < n; ++ii)
	{
		for (int jj = 0; jj < n; ++jj)
		{
			// display the available moves for both of the colours
			if (validateFeasibility(board, n, ii, jj, colour) == true)
			{
				Moves[totalMoves].row = ii;
				Moves[totalMoves].col = jj;
				++totalMoves;
			}
		}
	}
}
// findAllAvailableMoves() definition - end

// getScore() definition - begin
void getScore(char board[][26], int n, int *bScore, int *wScore)
{
	// initialize the counters to 0
	*bScore = *wScore = 0;
	
	// loop through the board and update the counts 
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			if (board[row][col] == 'B')
				++(*bScore);
			else if (board[row][col] == 'W')
				++(*wScore);
		}
	}
}
// getScore() definition - end

// copyBoard() definition - begin
void copyBoard(char newBoard[][26], char board[][26], int n)
{
	int row, col;
	
	// copy the elements of board to newBoard
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
			newBoard[row][col] = board[row][col];
	}
}
// copyBoard() definition - end

// evalHeuristicValue() definition - begin
int evalHeuristicValue(char board[][26], int n, int color)
{
	// variable definition
	// various counters and score computing factors
    double dPieces, dCorners, dPotentialCorners, dEdges;
	double dMobility, dFrontier;
	int ii, jj, iCW, iEW, iFW, iMW, iPW, iPCW;
	int iBlackScore, iWhiteScore;
	int iMyCorners, iOpponentCorners;
	int iMyEdges, iOpponentEdges;
	int iMyFrontiers, iOpponentFrontiers;
	int iMyLegalMoves, iOpponentLegalMoves; 
	char cOpponentColor = (color == 'B') ? 'W' : 'B'; // the opponent color
	
    // initialize the weights of all the heuristic parameters
    iEW  = 50;
	iCW  = 5000;
    iFW  = 200;
	iPCW = 2000;
	
	// find the score from the board
    getScore(board, n, &iBlackScore, &iWhiteScore);
	
	// compute the weightage
	iPW  = (iBlackScore + iWhiteScore) * 2;
	iMW  = (100 - (iBlackScore + iWhiteScore)) * 10;

    // set the piece count
    if (color == 'B')
    	dPieces = (100. * iBlackScore) / (iBlackScore + iWhiteScore);
    else
    	dPieces = (100. * iWhiteScore ) / (iWhiteScore + iBlackScore);
    
	// count the number of corners
    iMyCorners = iOpponentCorners = 0;
    if	(board[0][0] == color)
		++iMyCorners;
    else if (board[0][0] == cOpponentColor)
		++iOpponentCorners;
    
	if (board[0][n-1] == color)
		++iMyCorners;
    else if (board[0][n-1] == cOpponentColor)
		++iOpponentCorners;
    
	if (board[n-1][0] == color)
		++iMyCorners;
    else if (board[n-1][0] == cOpponentColor)
		++iOpponentCorners;
    if (board[n-1][n-1] == color)
		++iMyCorners;
    else if (board[n-1][n-1] == cOpponentColor)
		++iOpponentCorners;
    
	dCorners = (iMyCorners - iOpponentCorners) * 25;

    // count the number of edges and frontier
    iMyEdges = iOpponentEdges = 0;
    iMyFrontiers = iOpponentFrontiers = 0;
    
    for (ii = 0; ii < n; ++ii)
	{
        for (jj = 0; jj < n; ++jj)
		{
			if (board[ii][jj] == 'U')
				continue;
			
			// if the element is on the edge	
        	if (ii == 0 || ii == n-1 || jj == 0 || jj == n-1)
			{
				// unoccupied cells are already skilled at the beginning of the second loop
                if (board[ii][jj] == color)
					++iMyEdges;
                else
					++iOpponentEdges;
            }
            else // count the frontiers
			{
                if (validateFeasibility(board, n, ii, jj, color) == true)
                {
					if (board[ii][jj] == color)
						++iMyFrontiers;
                    else
						iOpponentFrontiers++;
                }
            }
        }
    }
    
    // compute the weightages
    dEdges = (100. * iMyEdges) / (iMyEdges + iOpponentEdges);
    dFrontier = (iMyFrontiers - iOpponentFrontiers) * -100;

    // find all the available moves to the computer
	findAllAvailableMoves(board, n, color);
	iMyLegalMoves = totalMoves;
	findAllAvailableMoves(board, n, cOpponentColor);
	iOpponentLegalMoves = totalMoves;
	// compute the mobility factor
	dMobility = iMyLegalMoves / (iMyLegalMoves + iOpponentLegalMoves) * 100.;
	
	// count the corners of the opponent
	for (ii = 0; ii < iOpponentLegalMoves; ++ii)
	{
        // keep counting the potential corners
		if ((ii == 0 && jj == 0) || ((ii == n-1) && (jj == n-1)) ||
			(ii == 0 && jj == n-1) || ((ii == n-1) && (jj == 0)))
				++iOpponentCorners;
	}
	
	// compute the weightage
    dPotentialCorners = iOpponentCorners * -25.0;

	// return the weightage computed
    return (iPCW * dPotentialCorners) + (iEW * dEdges) + 
		   (iPW * dPieces) + (iCW * dCorners) +
	       (iFW * dFrontier) + (iMW * dMobility);
}
// evalHeuristicValue() definition - end

// evalAlphaBetaScore() definition - begin
int evalAlphaBetaScore(char board[][26], int n, int iDepth, int iAlphaVal, int iBetaVal, char color, bool* bTimeOut, bool bValue)
{
	int ii, row, col, iValue, iRetValue;
	char newColor, newBoard[26][26];
	int blackScore = 0, whiteScore = 0;
	int iAlphaValue = iAlphaVal, iBetaValue = iBetaVal;
	struct rusage usage; // a structure to hold "resource usage" (including time)
	struct timeval end;
	double timeEnd, totalTime;
	
	// compute the total time taken so far
	getrusage(RUSAGE_SELF, &usage);
	end = usage.ru_utime;
	timeEnd = end.tv_sec + end.tv_usec / 1000000.0; // in seconds
	totalTime = timeEnd - timeStart;
	
	*bTimeOut = false;
	// have a buffer time of .02 seconds for executing evalHeuristicValue()
	if (totalTime > 0.98)
	{
		*bTimeOut = true;
        return evalHeuristicValue(board, n, color);
    }
	
	// if we are at depth 0, just comoute and return the heuristic score	
	if(iDepth == 0)
		return evalHeuristicValue(board, n, color);
    else
        --iDepth;
	
	// find all the available moves to the computer
	findAllAvailableMoves(board, n, color);
	
	// find the opponent color
	newColor = (color == 'B') ? 'W' : 'B';
	
	// if no moves is found, check if the game is over
	if (totalMoves == 0)
	{
		// if the game is over, display the winner and quit
		if (isGameOver(board, n) == true)
		{
			// display the board
			printBoard(board, n);
			// display the winner
			displayWinner(board, n);
			exit(0);
		}
		
		// create a new board and compute the score
		copyBoard(newBoard, board, n);
		return evalAlphaBetaScore(newBoard, n, iDepth, iAlphaVal, iBetaVal, newColor, bTimeOut, !bValue);
	}
	
	// if there are valid moves
	if(bValue == true)
	{
		iValue = INT_MIN;
		for (ii = 0; ii < totalMoves; ++ii)
		{
			copyBoard(newBoard, board, n);
			updateBoard(newBoard, n, newColor, Moves[ii].row, Moves[ii].col);
			// if the game is over, display the winner and quit
			if (isGameOver(newBoard, n) == true)
			{
				// display the board
				printBoard(newBoard, n);
				// display the winner
				displayWinner(newBoard, n);
				exit(0);
			}
			
			// find the score of the new board
			iRetValue = evalAlphaBetaScore(newBoard, n, iDepth, iAlphaVal, iBetaVal, newColor, bTimeOut, false);
			
			// adjust the weightages if required
			if (iValue < iRetValue)
				iValue = iRetValue;
				
			if (iValue >= iBetaVal)
				return iValue;
			
			if (iAlphaValue < iValue)
				iAlphaValue = iValue;
		}
		
		return iValue;
	}
	else
	{
		iValue = INT_MAX;
		for (ii = 0; ii < totalMoves; ++ii)
		{
			copyBoard(newBoard, board, n);
			updateBoard(newBoard, n, newColor, Moves[ii].row, Moves[ii].col);
			// if the game is over, display the winner and quit
			if (isGameOver(newBoard, n) == true)
			{
				// display the board
				printBoard(newBoard, n);
				// display the winner
				displayWinner(newBoard, n);
				exit(0);
			}
			
			iRetValue = evalAlphaBetaScore(newBoard, n, iDepth, iAlphaVal, iBetaVal, newColor, bTimeOut, true);
			
			// update the weightages if required
			if (iValue > iRetValue)
				iValue = iRetValue;
		
			if (iValue <= iAlphaValue)
				return iValue;
	
			if (iBetaValue > iValue)
				iBetaValue = iValue;
		}
			
		return iValue;
	}
}
// evalAlphaBetaScore() definition - end
	
// makeBestComputerMove() definition - begin	
bool makeBestComputerMove(char board[][26], int n, char colour)
{
	bool bTimeOut = false;
	int row, col, ii, jj;
	int iDepth, iEvalScore, iMaxLimit;
	int blackScore = 0, whiteScore = 0;
	char newColor, newBoard[26][26];
	int  iAlphaValue, iBetaValue;
	struct AvailableMoves bestMove;
	struct rusage usage; // a structure to hold "resource usage" (including time)
	struct timeval start, end; // will hold the start and end times
	
	// get the current score from the current state of the board
	getScore(board, n, &blackScore, &whiteScore);
	
	// find the maximum limt of evaluations
	iMaxLimit = (n * n) - (blackScore + whiteScore);
	
	// find all the available moves to the computer
	findAllAvailableMoves(board, n, colour);
	
	// if no moves is found, pass on the turn to the human player
	if (totalMoves == 0)
		return false;
	
	// capture the start time of the evaluation
	getrusage(RUSAGE_SELF, &usage);
	start = usage.ru_utime;
	timeStart = start.tv_sec + start.tv_usec / 1000000.0; // in seconds
	
	// loop through each depth till timeout or all the depths are covered
	for(iDepth = 0; iDepth < iMaxLimit; ++iDepth)
	{
		iAlphaValue = INT_MIN;
		bTimeOut = false;
					
		for(ii = 0; ii < totalMoves; ++ii)
		{
			// create a new board by copying the current state of the board 
			copyBoard(newBoard, board, n);
			updateBoard(newBoard, n, colour, Moves[ii].row, Moves[ii].col);
			// if the game is over, display the winner and quit
			if (isGameOver(newBoard, n) == true)
			{
				// display the board
				printBoard(newBoard, n);
				// display the winner
				displayWinner(newBoard, n);
				exit(0);
			}
			
			newColor = (colour == 'B') ? 'W' : 'B';
			iEvalScore = evalAlphaBetaScore(newBoard, n, iDepth, iAlphaValue, INT_MAX, newColor, &bTimeOut, false);
			
			// check id timeout happened
			if (bTimeOut == true)
				break;
			
			// if we are within time limit, update the score
			if(iEvalScore > iAlphaValue)
			{
    			bestMove = Moves[ii];
    			iAlphaValue = iEvalScore;
			}
		}
	}
		
	// computer found its best move to make
	printf("Computer places %c at %c%c.\n", colour, 'a'+bestMove.row, 'a'+bestMove.col);
	updateBoard(board, n, colour, bestMove.row, bestMove.col);
	
	// return true as the best move is made successfully
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
	findAllAvailableMoves(board, n, 'B');
	findAllAvailableMoves(board, n, 'W');
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
