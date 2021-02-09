//to find factorial using functions
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
	int i,f=1;
	for(i=n;i>=1;i--)
		f = f * i;
	return f;
}
