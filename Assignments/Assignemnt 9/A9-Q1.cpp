#include<stdio.h>
int sum(int a, int b, int c);
main()
{

	int x,y,z; 
	printf("Enter 3 numbers");
	scanf("%d%d%d", &x,&y,&z);
	sum(x,y,z);
	
	
}

int sum(int a, int b, int c)
{
	int sum; 
	sum= a+b+c;
	printf("%d", sum);
}

