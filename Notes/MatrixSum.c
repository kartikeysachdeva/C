#include <stdio.h>
main()
{
	int a[3][3],b[3][3],s[3][3],i,j;
	printf("Enter first 3x3 matrix\n");
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	   scanf("%d",&a[i][j]);
	printf("Enter second 3x3 matrix\n");
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
		scanf("%d",&b[i][j]);
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)	
		s[i][j] = a[i][j] + b[i][j];
	printf("Sum of Matrices \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%d ",s[i][j]);
		printf("\n");
	}
}
