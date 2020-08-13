#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

main()
{
	FILE *ffirst; 
	char read; 
	char firstfile[80];
	int i, num;
	
	printf("Name of first file: ");
	gets(firstfile);
	
	ffirst = fopen(firstfile, "wt");
	if(ffirst==NULL)
	{
		printf("Cannot create the file to write hence quitting ");
		exit(1);
	}
	
	for(i=0;i<10;i++)
	{
		printf("Enter #%d", i+1);
		scanf("%d", &num);
		fprintf(ffirst, "%d", num);
	}
		
	fclose(ffirst);
	
	printf("Integers have been successfully added to the file.");
}