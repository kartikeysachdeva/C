//to write a line of text onto the data file
#include <stdio.h>
main()
{
	FILE *fp;
	char c;
	fp = fopen("xyz.txt","w");
	printf("Enter a line of text\n");
	while ((c = getchar()) != '\n')
		putc(c,fp);
	printf("File Created");
	fclose(fp);
}
