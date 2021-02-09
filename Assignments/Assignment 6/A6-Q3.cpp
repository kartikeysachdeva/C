// WAP to display multiplication tables from 1 to 1
#include <stdio.h>
main()
{
	int n,i,j,p;
	printf("Enter a Number ");
	scanf("%d",&n);
	for(i=1;i<=10;i++)
	{
		for(j=1;j<10;j++){
			p = i * j;
		printf("\n%d * %d = %d\n",i,j,p);
		
		
		}
		printf("\n-----------------------------\n");
		
	}
}

