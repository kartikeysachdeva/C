//Linear Search or Sequential Search
#include <stdio.h>
main()
{
	int n[5],i,key,isfound=0;
	printf("Enter 5 values\n");
	for(i=0;i<5;i++)
		scanf("%d",&n[i]);
	printf("Enter value to search ");
	scanf("%d",&key);
	for(i=0;i<5;i++)
	{
		if (key == n[i])
		{
			isfound = 1;
			break;
		}
	}
	if (isfound)
		printf("Found");
	else
		printf("Not Found");
}
