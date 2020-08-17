#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

main()
{
	FILE *ffirst,*feven,*fodd; 
	char read; 
	char firstfile[80];
	int i, num;
	
	printf("Name of first file: ");
	gets(firstfile);
	
	ffirst = fopen(firstfile, "rt");
	if(ffirst==NULL)
	{
		printf("Cannot find the file to write hence quitting ");
		exit(1);
	}
	printf ("\nThe integers from the file: \"%s\" are: ", firstfile);
	
	while(fscanf(ffirst, "%d", &num)!= EOF)
	{
		if(num%2==0)
		{
			feven=fopen("Even.txt", "wt");
			fprintf(feven, "%d", num);
		}
		else
		{
			fodd=fopen("Odd.txt", "wt");
			fprintf(fodd, "%d", odd);
		}
	}
	
		
	fclose(ffirst);
	
	printf("Integers have been successfully added to the file.");
}
