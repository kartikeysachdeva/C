//to check whether the given number is Even or Odd
#include <stdio.h>
main()
{
	int n;
	printf("Enter a Number ");
	scanf("%d",&n);
	if (n % 2 == 0)
		printf("Even");
	else
		printf("Odd");
}
