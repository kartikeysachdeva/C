#include <stdio.h>
main()
{
	int n[3][3],i,j,sum=0;
	printf("Enter 9 values\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&n[i][j]);
			if (i == j)
				sum = sum + n[i][j];
		}
	}
	printf("Sum of prinicipal Diagonal elements = %d",sum);
}
