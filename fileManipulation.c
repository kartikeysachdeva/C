#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

main()
{
	FILE *ffirst, *fsecond, *fappend; 
	char read; 
	char firstfile[80], secondfile[80], appendfile[80];
	
	printf("Name of first file: ");
	gets(firstfile);
	
	ffirst = fopen(firstfile, "rt");
	if(ffirst==NULL)
	{
		printf("Not available");
		
	}
	fclose(ffirst);
	remove(firstfile);
	
	printf("File deleted");
}