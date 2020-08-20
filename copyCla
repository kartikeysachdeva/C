#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc,char *argv[]) 
{
	FILE *fp1, *fp2;
	char readLine[80];
	
	if(argc<=1)
	{
		printf("Not enough commands");
		return 0;
	}
	
	for(int icount=0, i=1; i<argc-1; i++)
	{
		fp1= fopen(argv[i], "rt");
		if (fp1 == NULL)
		{
			printf("Unable to find file... hence quitting");
			exit(1);
		}
		
		fp2= fopen(argv[i+1], "wt");
		
		if(fp2==NULL)
		{
			printf("Unable to create file... hence quitting");
			exit(1);
		}
		
		while((fgets(readLine, 79, fp1))!=NULL)
		{
			fgets(readLine, 79, fp1);
			fputs(readLine, fp2);
		}
		fclose (fp1);
		fclose (fp2);
	}
	printf ("Files copied succesfully");
}
