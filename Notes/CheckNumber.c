#include <stdio.h>
main()
{
	int n;
	printf("Enter a Number ");
	scanf("%d",&n);
	if (n > 0)	
		printf("Positive");
	else
		if (n < 0)
			printf("Negative");
		else
			printf("Zero");
}
