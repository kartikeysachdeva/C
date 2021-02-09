#include <stdio.h>
main()
{
	int n,i=1,big=0;
	while (i <= 10)
	{
		printf("Enter a Number ");
		scanf("%d",&n);
		if (n > big)
			big = n;
		i++;
	}
	printf("Big = %d",big);
}
