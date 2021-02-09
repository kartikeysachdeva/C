//WAP to find smallest of given 10 numbers
#include <stdio.h>
main()
{
	int n,i=1,small=0;
	while (i <= 10)
	{
		printf("Enter a Number ");
		scanf("%d",&n);
		if (n < small)
			small = n;
		i++;
	}
	printf("Small = %d",small);
}
