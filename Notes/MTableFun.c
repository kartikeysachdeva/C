#include <stdio.h>
main()
{
	int n;
	printf("Enter a Number ");
	scanf("%d",&n);
	mtable(n);
}
void mtable(int n)//void means no return type - optional in C
{
	int i,p;
	for(i=1;i<=10;i++)
	{
		p = n * i;
		printf("%d * %d = %d\n",n,i,p);
	}
}
