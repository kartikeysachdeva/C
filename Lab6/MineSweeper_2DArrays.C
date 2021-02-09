/****** This code is the Intellectual Property of ********
******* VIDYAVANIINSTITUTE OF TECHNOLOGY, HYDERABAD. *****
******* PH: +040 6999 6920 ** Mobile: +91 98484 18700. ***
******* For more details mail to: VVIT4U@gmail.com *******
******* Created on: 22nd Feb 2002 by VVIT developers. ****
******* The purpose of this program is to implement ******
******* MineSweeper Game with the rules described in *****
******* the document: XXXXXXXXX. Refer to the above ******
******* mentioned doc for complete details of the game. **/

/*** include header file for basic I/O ***/
#include<stdio.h>
/*** include header file for rand() ***/
#include <stdlib.h>
/*** include header file for time() ***/
#include <time.h>

/*** main function definition: Begin ***/
int main()
{
    int 		iRows;		  // number of rows
    int 		iColumns;	  // number of columns
	double		dProbability; // probability(must be between 0 and 1)
	int			ii, jj;		  // loop variables
	int			iCount;		  // number of bombs 
	double		dRandomNumber;// store the generated random number
	const char 	cDot= '.';	  // safe cell
    const char 	cStar= '*';   // cell having bomb
	
	// read the dimensions of the game
	printf("Enter the number of rows: ");
    scanf("%d", &iRows);
    
	printf("Enter the number of columns: ");
    scanf("%d", &iColumns);
    
    // read the probability
	printf("Enter the probability: ");
    scanf("%lf", &dProbability);

    /*** variable size arrays ***/
	
	// setup a double grid of size: iRow+2 and iColumns+2
	// the rows of game: 1 to iRows
	// the columns of the game: 1 to iColumns
    double dRandomGrid[iRows+2][iColumns+2];
    
	// setup the minesweeper of size: iRow+2 x iColumns+2
	// the rows of game: 1 to iRows
	// the columns of the game: 1 to iColumns
    int mineSweeper[iRows+2][iColumns+2];
    
    // update the border rows/columns with a
	// max value so that we won't count them
  
  	// update the left-most columns
  	for (int ii = 0; ii < iRows+2; ++ii)
        mineSweeper[ii][0] = 10;
    
    // update the right-most columns
  	for (int ii = 0; ii < iRows+2; ++ii)
        mineSweeper[ii][iColumns+1] = 10;
        
    // update the top-most row
    for(int jj = 0; jj < iColumns+2; ++jj)
        mineSweeper[0][jj] = 10;
    
    //update the bottom-most row
    for(int jj = 0; jj < iColumns+2; ++jj)
	    mineSweeper[iRows+1][jj] = 10;
    
    // diplay line of -
    for (int ii = 1; ii < 2*iColumns; ++ii)
		printf("-");

	// move on to the next line
    printf("\n");
    
    // set the random seed
    srand(time(NULL));
    
    // generate iRows x iColumns random values
	// populate and display charGrid
    for (ii = 1; ii <= iRows; ++ii)			// rows
	{
    	for (jj = 1; jj <= iColumns; ++jj)	// columns
		{
            // generate the random number between 0 to 1
			dRandomNumber = rand() % 1000;
			dRandomNumber = dRandomNumber / 1000;
			
			// update the cell with the generated random value
            dRandomGrid[ii][jj] = dRandomNumber;
            
            // update minesweeper with either zero or one based on the probability
            // display either * or . based on the probability
	        if (dRandomNumber < dProbability)
	        {
                mineSweeper[ii][jj] = 1;
                printf("%c ", cStar);		// represents a bomb
            }
            else
			{  
                mineSweeper[ii][jj] = 0;
                printf("%c ", cDot);		// represents safe call
            }
        
		} // end of inner for-columns
        
        // move to the next line
		printf("\n");
		
    } // end of outer for-rows

    // diplay line of -
    for (int ii = 1; ii < 2*iColumns; ++ii)
		printf("-");

	// move on to the next line
    printf("\n");
		
	// evaluate and display the count of mines for each eligible cell
	for (int ii = 1; ii <= iRows; ++ii)
	{
    	for (int jj = 1; jj <= iColumns; ++jj)
		{
        	// if the value in the cell is less than the probabilty
			// just display the * and move on to next iteration	
           	if (dRandomGrid[ii][jj] < dProbability)
           	{
            	printf("* ");	// represents a bomb
            	continue;		// move on to the next iteration
		   	}
			
			// initialize the count for each iteration
			iCount = 0;
			 
			// the top neighbour
			if(mineSweeper[ii-1][jj] == 1) 	 ++iCount;
			
			// the top right neighbour
			if(mineSweeper[ii-1][jj+1] == 1) ++iCount;
			
			// the right neighbour
			if(mineSweeper[ii][jj+1] == 1) 	 ++iCount;
			
			// lower right neighbour
			if(mineSweeper[ii+1][jj+1] == 1) ++iCount;
			
			// lower neighbour
			if(mineSweeper[ii+1][jj] == 1) 	 ++iCount;
			
			// lower left neighbour
			if(mineSweeper[ii-1][jj-1] == 1) ++iCount;
		    	
			// left neighbour
			if(mineSweeper[ii][jj-1] == 1) 	 ++iCount;
			
			// upper left neighbour
			if(mineSweeper[ii+1][jj-1] == 1) ++iCount;
			
			// display the computed count
            printf("%d ", iCount);
            
        } // end of inner for-columns
    	
		// move on to the next line
	    printf("\n");
    
	} // end of outer for-rows	
            
	// diplay line of -
    for (int ii = 1; ii < 2*iColumns; ++ii)
		printf("-");

	// move on to the next line
    printf("\n");
	
	// we are done!!!
	return 0;
}
/*** main function definition: End ***/
