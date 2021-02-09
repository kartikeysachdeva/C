#include <stdio.h>
main()
{
	int n[3][3],i,j;
	printf("Enter 9 values\n");
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	    scanf("%d",&n[i][j]);
	printf("Given 3x3 matrix\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%d ",n[i][j]);
		printf("\n");
	}
}
