//Sorting - Bubble sort
main()
{
	int n[5],i,j,temp;
	printf("Enter 5 values\n");
	for(i=0;i<5;i++)
		scanf("%d",&n[i]);
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if (n[i] > n[j])
			{
				temp = n[i];
				n[i] = n[j];
				n[j] = temp;
			}
		}
	}
	printf("Sorted Order \n");
	for(i=0;i<5;i++)
		printf("%d ",n[i]);
}
