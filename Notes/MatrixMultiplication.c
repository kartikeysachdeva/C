//Matrix Multiplication
main()
{
	int a[2][2],b[2][2],m[2][2],i,j,k,sum;
	printf("Enter first 2x2 matrix\n");
	for(i=0;i<2;i++)
	for(j=0;j<2;j++)
		scanf("%d",&a[i][j]);
	printf("Enter second 2x2 matrix\n");
	for(i=0;i<2;i++)
	for(j=0;j<2;j++)
		scanf("%d",&b[i][j]);
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			sum = 0;
			for(k=0;k<2;k++)
				sum = sum + a[i][k] * b[k][j];
			m[i][j]	 = sum;
		}
	}
	printf("Multiplication of two matrices \n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			printf("%d ",m[i][j]);
		printf("\n");
	}

}
