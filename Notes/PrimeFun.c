#include <stdio.h>
main()
{
	int n;
	printf("Enter a Number ");
	scanf("%d",&n);
	if (prime(n))
		printf("Prime");
	else
		printf("Not Prime");
}
prime(int n)
{
	int i;
	for(i=2;i<n;i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}
