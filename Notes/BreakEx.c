#include <stdio.h>
main()
{
	int n,sum=0;
	while (1) //infinite loop
	{
		printf("Enter a Number to stop enter zero ");
		scanf("%d",&n);
		if (n == 0)
			break;
		sum = sum + n;
	}
	printf("Sum = %d",sum);
}
