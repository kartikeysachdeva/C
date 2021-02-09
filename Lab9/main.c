#include <stdio.h>
#include <stdlib.h>
#include "rawRecipes.h"
#include <string.h>

// IF IT'S EASIER, YOU NEED NOT BE OVERLY GENERAL/FLEXIBLE
// BUT CAN ASSUME THESE LIMITS
#define MAXRECIPES 30 /* max # of recipes */
#define MAXINGREDIENTTYPES 250 /* max # of ingredient types */
#define MAXINGREDIENTS 250 /* max # of ingredients all recipes */

/* node definition to store the name of recipe/ingredient */
typedef struct Recipe
{
	char string[80];	 // name
	struct Recipe *next; // link to the next node	
}Recipe;

Recipe *Recipes[MAXRECIPES];  // array of node pointers
unsigned int  numRecipes = 0; // number of recipes available

// INCLUDE YOUR OWN "HELPER" ROUTINES AS YOU SEE FIT

/* 
 * getNewNode
 * Takes a string as argument
 * allocates memory dynamically for a node 
 * stores the argument string in the data part of the node
 * sets next pointer to null and returns the address of the newly created node
 * returns NULL if memory allocation is unsuccessful
 */ 
Recipe *getNewNode(char item[])
{
	Recipe* newNode;							// pointer to the node
	newNode = (Recipe*)malloc(sizeof(Recipe));	// dynamic memory allocation to the node
	if (newNode == NULL)						// if the memory allocation is unsuccessful
		return NULL;							// return NULL
		
	strcpy(newNode->string, item);				// update the allocated memory with data
	newNode->next = NULL;
	
	return newNode;								// return the pointer to the node
}
 
/* 
 * addIngredient
 * Takes the pointer to the list as first argument
 * Takes the name of the ingredient as second argument
 * add the ingredient to the end of the list
 */  
void addIngredient(Recipe** head, char ingredient[])
{
	Recipe *newNode, *lastNode = *head;

	/* get the new node to store the ingredient */
	newNode = getNewNode(ingredient);
	/* if the memory allocation is unsuccessful, return */
	if (newNode == NULL)
	{
		printf("Unable to add ingredient: %s, memory allocation unsuccessful.\n", ingredient);
		return;
	}
		
	/* traverse to the end of the list */ 
	while (lastNode->next != NULL)
		lastNode = lastNode->next;
		
	// add the new ingredient to the end of the list	
	lastNode->next = newNode;		
} 

/* 
 * deleteList
 * Takes the pointer to the list as argument
 * de-allocates the memory allocated for each of the node
 */ 
void deleteList(Recipe *list)
{
	Recipe *next, *temp = list;
	
	/* keep freeing up each node while traversing in forward direction */
	while (temp != NULL)
	{
		next = temp->next; 	// store the address of the next node
		free (temp);	   	// free up the current node
		temp = next;		// move on to the next node
	}
}

/* 
 * insertInOrderedList
 * Takes the pointer to the list as first argument
 * Takes a string as second argument
 * for using structs with pointers in your solution.
 * You might also want to consider the outputs from the program
 * (see the menu printed in printMenu) since some structures will
 * make this easier than others.
 */ 
void insertInOrderedList(Recipe **orderedList, char string[])
{
	Recipe *current = *orderedList, *prev, *newNode;
	int returnValue;
	
	/* if the list is not yet established, update it to be the first node */
	if (current == NULL)
	{
		*orderedList = getNewNode(string);	// allocate memory for the node
		if (*orderedList != NULL)		    // if memory allocation is successful, return
			return;	

		printf("Memory allocation unseccessful.\n");	
		deleteList(*orderedList);			// otherwise, destroy the list created so far
		exit(0);
	}
	
	// keep traversing through the nodes until you find the right insertion point
	prev = current;
	while (current != NULL) 
    {
    	returnValue = strcmp(current->string, string); // compare the strings
    	if (returnValue == 0)						   // if both the string are same, return 
    		return;
    		
    	if (returnValue > 0)		// if the strign in the node is greater than the argument		
			break;					// string, stop the traversal in the list
			
		prev = current;				// store the pointer to the previous node
		current = current->next;	// move on to the next node
	}
	
	// allocate memory for the new node and store the string in it	
	newNode = getNewNode(string);
	if (newNode == NULL)	// if the memory allocation is unseccessful	
	{						// destroy the list created so far and return
		deleteList(*orderedList);
		return;
	}		
	
	newNode->next = current; // insert the new node at the right position in the list
	if (prev == current)	 // check if the node has to be added to the begin of the list 
		*orderedList = newNode;
	else
		prev->next = newNode;	
}

/* list all recipe titles with recipe number beside
 */ 
void ListAllRecipes(){

    // YOUR CODE HERE
    int ii;
    
    // traverse through all the recipes and display their names
    for (ii = 0; ii < numRecipes; ++ii)
		printf("Recipe #%d: %s\n", ii+1, Recipes[ii]->string);
}

/* 
 * convertInputToDataStructure
 * Takes the information in rawRecipes.h and puts it into a data 
 * structure of your choosing, however: 1 mark of the lab will be
 * for using structs with pointers in your solution.
 * You might also want to consider the outputs from the program
 * (see the menu printed in printMenu) since some structures will
 * make this easier than others.
 */ 
void convertInputToDataStructure(){

    // YOUR CODE HERE
    int ii = 0, jj;
    int iLength;
    char  string[80], item[80];
    
    // read all the data from the array of strings
    while(1)
    {
    	strcpy(string, rawRecipes[ii]);	// copy the current string
    	if (strcmp(string,"") == 0)	    // if it is the end, quit the loop
    		break;
    		
    	iLength = strlen(string);		// exclude the first character from the string 
    	for(jj=1; jj<iLength;++jj)
			item[jj-1] = string[jj];
		item[jj-1] = '\0';				// add null terminater to the string
		
		if (string[0] == '0')			// if it is recipe, create a new list
		{
			Recipes[numRecipes] = getNewNode(item);
			numRecipes++;				// update the number of recipes
		}
		else							// if it is ingredient, add it to the corresponding
		{								// recipe list
			addIngredient(&Recipes[numRecipes-1], item);
    	}
		
		++ii;							// move to the next element in the array 
	}
}

/*
 * printMenu - Prints out the user menu
 */
void printMenu() {
    printf("\n\nEnter a command by number\n");
    printf("1. List all Recipes\n");
    printf("2. Print a Recipe\n");
    printf("3. List All Recipes with a given ingredient\n");
    printf("4. List All Ingredients in alphabetical order\n");
    printf("5. Exit the program\n");
    printf("Give input: ");
}


/*
 * printRecipe asks the user for the recipe number then prints out
 * the title and the ingredients of that recipe.
 */
void printRecipe(){

    // YOUR CODE HERE
    Recipe *recipe;
    unsigned recipeNumber;
    
    // prompt for the recipe number
    printf("\n\nGive the number of the recipe (1-%d):", numRecipes);
    scanf("%d", &recipeNumber);
    
    // if the recipe number is invalid, return
    if (recipeNumber > numRecipes)
    {
    	printf("Invalid number of recipe.");
    	return;
	}
	
	// get the header pointer to the recipe
    recipe = Recipes[recipeNumber-1];
	while (recipe != NULL)		// loop through the recipe and display the ingerdients
	{
		puts(recipe->string);
		recipe = recipe->next;	// move on to the next ingredient
	}
}

/*
 * printForIngredients asks for an ingredient and prints out
 * a list of all recipes that have that ingredient. The user must
 * enter the exact name of the ingredient (including capital letters)
 */
void printForIngredient(){
    
// YOUR CODE HERE
	int ii;
	char ingredient[80];
	Recipe* recipe;
	
	// prompt for teh name of the ingredient
	printf("\n\nGive the name of the ingredient:");
	fflush(stdin);
	gets(ingredient);
	
	// loop through all the recipes and list out the ones with matching ingredient
	for(ii = 0; ii < numRecipes; ++ii)
	{
		recipe = Recipes[ii];	// header of the recipe
		while(recipe != NULL)
		{
			if (strcmp(recipe->string, ingredient) == 0) // check for matching ingredient
			{
				puts(Recipes[ii]->string);
				break;									// quit from the current recipe 
			}
			recipe = recipe->next;						// move on to the next recipe
		}
	}
}

/*
 * printAllIngredients prints a list of all the ingredients used by
 * all the recipes. The list should be in alphabetical order, and have
 * no duplicates. (Any ingredient with a variation in entry, such as
 * "white vinegar" and "white wine vinegar" are considered as different
 * ingredients.
 */
void printAllIngredients(){
    
// YOUR CODE HERE
	int ii;
	Recipe *tt, *orderedList = NULL, *temp, *current;
	
	// loop through all the recipes
	for (ii = 0; ii < numRecipes; ++ii)
	{
		current = Recipes[ii]->next; 	// skip the name of the recipe
		while (current != NULL)		 	// loop through all the ingredients
		{
			// insert the ingredient into the ordered list
			insertInOrderedList(&orderedList, current->string);
			current = current->next;	// move on to the next ingredient	
		}
	}
	
	// display the ingredients in sorted order
	printf("ALL INGREDIENTS\n");
	for (ii = 0, current = orderedList; current != NULL; ++ii, current = current->next)
		printf("%d: %s\n", ii, current->string);
		
	// destroy the ordered list of ingredients	
	deleteList(orderedList);	
}

/*
 * destroyLists
 * destroys the memory allocated for all the recipes
 */
void destroyLists(void)
{
	int ii;
	
	// loop through each recipe and destroy each ingredient
	for (ii = 0; ii < numRecipes; ++ii)
	{
		deleteList(Recipes[ii]);
		Recipes[ii] = NULL;
	}
}


int main()
{
    // first move data from rawRecipes.h to a data structure
	convertInputToDataStructure();
    
    char notDone = 1;
    while(notDone){
        printMenu();
        int userChoice;
        scanf("%d",&userChoice); 
        switch (userChoice){
            case 1: ListAllRecipes(); break;
            case 2: printRecipe(); break;
            case 3: printForIngredient(); break;
            case 4: printAllIngredients(); break;
            case 5: notDone = 0; destroyLists(); break;
            default: printf("Bad command\n"); break;
        }
    }
    
    // PUT ANY POST_RUN CODE HERE

    return 0;
}
