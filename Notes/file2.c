//to read the content from the data file
#include <stdio.h>
main()
{
	FILE *fp;
	char c;
	fp = fopen("xyz.txt","r");
	while ((c = getc(fp)) != EOF) //EOF - End Of File
		putchar(c);
	fclose(fp);
}
