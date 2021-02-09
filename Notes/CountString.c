#include <stdio.h>
main()
{
	int vowels=0,consonants=0,words=1;
	char c;
	printf("Enter a line of text\n");
	while ((c=getchar()) != '\n')
	{
		switch(c)
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':vowels++;break;
			case ' ':words++;break;	
			default: consonants++;
		}	
	}
	printf("Number of vowels = %d\n",vowels);
	printf("Number of consonants = %d\n",consonants);
	printf("Number of words = %d\n",words);
}
