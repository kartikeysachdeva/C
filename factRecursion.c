#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int multiply(int input)
{
	int fact; 
	
	if(input==1)
	{
		return 1;
	}
	else
	{
		fact = input * multiply(input-1);
	}
	
	return fact;
}

int output(int x, int ans)
{
	printf("The factorial of the %d is %d", x, ans);
}

main()
{
	int x, ans;
	printf("Enter a num ");
	scanf("%d", &x);
	
	ans= multiply(x);
	output(x, ans);
}

