//Dynamic Memory Management
#include <stdio.h>
#include <stdlib.h> //dmm functions
main()
{
	char *p;
	p = (char*)malloc(10*sizeof(char));
	strcpy(p,"hyderabad");
	printf("%s",p);//hyderabad
	p = (char*)realloc(p,15*sizeof(char));
	printf("%s",p);//hyderabad
	strcpy(p,"secunderabad");
	printf("%s",p);//secunderabad
	p = (char*)realloc(p,5*sizeof(char));
	printf("%s",p);
	free(p);
}

