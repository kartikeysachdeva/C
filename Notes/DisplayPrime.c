#include <stdio.h>
main()
{
	int n,i,isprime;
	for(n=2;n<=100;n++)
	{
		isprime = 1;
		for(i=2;i<n;i++)	
		{
			if (n % i == 0)
			{
				isprime = 0;
				break;
			}
		}
		if (isprime)
			printf("%d ",n);
	}
}
/*
2 3 5 7 11 13 .... 97
*/
