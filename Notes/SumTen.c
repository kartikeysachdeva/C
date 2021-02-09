#include <stdio.h>
main()
{
	int n,i=1,sum=0;
	while (i <= 10)
	{
		printf("Enter a Number ");
		scanf("%d",&n);
		sum = sum + n;
		i++;
	}
	printf("Sum = %d",sum);
}
