#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

main()
{
	FILE *ffirst; 
	char read; 
	char firstfile[80];
	
	printf("Name of first file: ");
	gets(firstfile);
	
	ffirst = fopen(firstfile, "rt");
	if(ffirst==NULL)
	{
		printf("File not available");
		
	}
	fclose(ffirst);
	remove(firstfile);
	
	printf("File deleted");
}