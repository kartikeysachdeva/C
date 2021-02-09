#include <stdio.h>
main()
{
	int n[5],i,sum=0;
	printf("Enter 5 values\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&n[i]);
		sum = sum + n[i];
	}
	printf("Sum = %d",sum);
}
