#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int addition(int input)
{
	int sum; 
	
	if(input==1)
	{
		return 1;
	}
	else
	{
		sum = input + addition(input-1);
	}
	
	return sum;
}

int output(int ans,int x)
{
	printf("The sum of the first %d num of natural numbers is %d", x, ans);
}

main()
{
	int x, ans;
	printf("Enter a num ");
	scanf("%d", &x);
	
	ans= addition(x);
	output(ans,x);
}

