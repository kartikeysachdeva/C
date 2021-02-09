//Factorial using Recursion
#include <stdio.h>
main()
{
	int n;
	printf("Enter a Number ");
	scanf("%d",&n);
	printf("Factorial = %d",fact(n));
}
int fact(int n)
{
	if (n == 1)
		return 1;
	else
		return n * fact(n-1);
}
