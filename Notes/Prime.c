#include <stdio.h>
main()
{
	int n,i,isprime = 1;
	printf("Enter a Number ");
	scanf("%d",&n);
	for(i=2;i<n;i++)
	{
		if (n % i == 0)
		{
			isprime = 0;
			break;
		}
	}
	if (isprime)
		printf("Prime");
	else
		printf("Not Prime");
}
