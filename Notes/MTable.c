#include <stdio.h>
main()
{
	int n,i,p;
	printf("Enter a Number ");
	scanf("%d",&n);
	for(i=1;i<=10;i++)
	{
		p = n * i;
		printf("%d * %d = %d\n",n,i,p);
	}
}
/*
Enter a Number 5 (n=5)
5 * 1 = 5
5 * 2 = 10
5 * 3 = 15
...
5 * 10 = 50
*/
